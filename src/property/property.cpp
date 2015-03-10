/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Tencent is pleased to support the open source community by making behaviac available.
//
// Copyright (C) 2015 THL A29 Limited, a Tencent company. All rights reserved.
//
// Licensed under the BSD 3-Clause License (the "License"); you may not use this file except in compliance with
// the License. You may obtain a copy of the License at http://opensource.org/licenses/BSD-3-Clause
//
// Unless required by applicable law or agreed to in writing, software distributed under the License is
// distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and limitations under the License.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "behaviac/base/core/assert_t.h"
#include "behaviac/base/core/crc.h"
#include "behaviac/property/property.h"
#include "behaviac/agent/agent.h"
#include "behaviac/base/object/method.h"
#include "behaviac/property/property_t.h"

#include "behaviac/base/core/logging/log.h"

namespace behaviac
{
    uint32_t MakeVariableId(const char* idString)
    {
		return CRC32::CalcCRC(idString);
    }

	bool IsParVar(const char* variableName);

#if K_TYPE_CREATOR_
	Property::PropertyCreators_t* Property::ms_propertyCreators;
	Property::PropertyCreators_t& Property::PropertyCreators()
	{
		if (!ms_propertyCreators)
		{
			ms_propertyCreators = BEHAVIAC_NEW PropertyCreators_t;
		}

		BEHAVIAC_ASSERT(ms_propertyCreators);

		return *ms_propertyCreators;
	}
#endif//#if K_TYPE_CREATOR_

	Property::ClassStaticProperties_t* Property::ms_properties;

	Property::ClassStaticProperties_t& Property::Properties()
	{
		if (!ms_properties)
		{
			ms_properties = BEHAVIAC_NEW ClassStaticProperties_t;
		}

		BEHAVIAC_ASSERT(ms_properties);

		return *ms_properties;
	}


	void Property::Cleanup()
	{
		if (ms_propertyCreators)
		{
			//for (PropertyCreators_t::iterator it = ms_propertyCreators->begin(); it != ms_propertyCreators->end(); ++it)
			//{

			//}

			ms_propertyCreators->clear();
			BEHAVIAC_DELETE(ms_propertyCreators);
			ms_propertyCreators = 0;
		}

		if (ms_properties)
		{
			for (ClassStaticProperties_t::iterator it = ms_properties->begin(); it != ms_properties->end(); ++it)
			{
				Property* p = it->second;
				BEHAVIAC_DELETE(p);
			}

			ms_properties->clear();
			BEHAVIAC_DELETE(ms_properties);
			ms_properties = 0;
		}
	}

	Property::Property(const CMemberBase* pMemberBase) : m_variableId(0), m_memberBase(pMemberBase)
	{
		if (this->m_memberBase)
		{
			this->m_pt = this->m_memberBase->GetParentType();

			BEHAVIAC_ASSERT(this->m_pt == PT_INVALID);
		}
		else
		{
			this->m_pt = PT_PAR;
		}
	}

	Property::Property(const Property& copy) : m_varaibleName(copy.m_varaibleName), m_varaibleFullName(copy.m_varaibleFullName),
		m_variableId(copy.m_variableId), m_refParName(copy.m_refParName), m_refParNameId(copy.m_refParNameId), 
		m_memberBase(copy.m_memberBase), m_pt(copy.m_pt), m_instanceName(copy.m_instanceName)
	{
	}

	Property::~Property()
	{
//it might be wrong due to multithreading, DeleteFromCache
//#if !defined(BEHAVIAC_RELEASE)
//		if (!this->m_varaibleFullName.empty())
//		{
//			ClassStaticProperties_t::iterator it = Properties().find(this->m_varaibleFullName);
//			if (it != Properties().end())
//			{
//				Properties().erase(it);
//			}
//		}
//#endif//#if !defined(BEHAVIAC_RELEASE)
	}

	void Property::SetRefName(const char* refParName)
	{
		m_refParName = refParName;
		m_refParNameId = MakeVariableId(refParName);
	}

	const behaviac::string& Property::GetRefName() const
	{
		return this->m_refParName;
	}

	uint32_t Property::GetRefNameId() const
	{
		return this->m_refParNameId;
	}

	void Property::SetVariableName(const char* variableName)
	{
		this->m_varaibleFullName = variableName;
		const char* nameOnly = GetNameWithoutClassName(variableName);

		this->m_variableId = MakeVariableId(nameOnly);
		this->m_varaibleName = nameOnly;
		//this->m_variableId = MakeVariableId(variableName);
		//this->m_varaibleName = variableName;
	}

	const char* Property::GetClassNameString() const
	{
		return m_memberBase ? m_memberBase->GetClassNameString() : 0;
	}

	const char* Property::GetInstanceNameString() const
	{
		if (!m_instanceName.empty())
		{
			return m_instanceName.c_str();
		}

		return m_memberBase ? m_memberBase->GetInstanceNameString() : 0;
	}

	void Property::SetInstanceNameString(const char* agentIntanceName)
	{
		bool bValidName = agentIntanceName && agentIntanceName[0] != '\0';

		if (bValidName)
		{
			BEHAVIAC_ASSERT(this->m_pt == PT_INVALID || this->m_pt == PT_AGENT);

			if (Agent::IsNameRegistered(agentIntanceName))
			{
				this->m_pt = PT_INSTANCE;
				this->m_instanceName = agentIntanceName;
			}
			else
			{
				//BEHAVIAC_ASSERT(strcmp(agentIntanceName, "Self") == 0);
				this->m_pt = PT_AGENT;
			}
		}
		else
		{
			BEHAVIAC_ASSERT(this->m_pt == PT_PAR);
		}
	}

	ParentType Property::GetParentType() const
	{
		return m_pt;
	}

	const int kInstanceLength = 256;
	static const char* ParseInstanceNameProperty(const char* fullName, char* agentIntanceName)
	{
		//Self->AgentActionTest::Action2(0)
		const char* pClassBegin = strchr(fullName, '.');
		if (pClassBegin)
		{
			int posClass = pClassBegin - fullName;
			BEHAVIAC_ASSERT(posClass < kInstanceLength);
			strncpy(agentIntanceName, fullName, posClass);
			agentIntanceName[posClass] = '\0';

			const char* propertyName = pClassBegin + 1;
			return propertyName;
		}

		return fullName;
	}


	Property* Property::create(bool bParVar, bool bConst, const char* typeName, const char* variableName, const char* instanceName, const char* value)
	{
		bool bValidName = variableName && variableName[0] != '\0';
		if (bValidName)
		{
			if (!bParVar)
			{
				Property* pProperty = Agent::CreateProperty(typeName, variableName, value);

				if (bValidName && pProperty && !bConst)
				{
					pProperty->SetVariableName(variableName);
					pProperty->SetInstanceNameString(instanceName);
				}

				if (pProperty)
				{
					return pProperty;
				}
			}
		}

#if K_TYPE_CREATOR_
		{
			bool bAgentPtr = false;
			//it might be par or the right value of condition/assignment
			if (value && string_icmp(value, "null") == 0)
			{
				BEHAVIAC_ASSERT(Agent::IsAgentClassName(typeName));
				bAgentPtr = true;
				typeName = "void*";
				value = "0";
			}

			BEHAVIAC_UNUSED_VAR(bAgentPtr);

			PropertyCreator* pCreator = PropertyCreators()[typeName];
			BEHAVIAC_ASSERT(pCreator, "%s is not registerd, please add Property::Register<%s>(\"%s\")", typeName, typeName, typeName);

			if (pCreator)
			{
				Property* pProperty = (*pCreator)(value, 0, bConst);

				if (bValidName && pProperty && !bConst)
				{
					pProperty->SetVariableName(variableName);
				}

				return pProperty;
			}
		}
#endif//#if K_TYPE_CREATOR_

		return 0;
	}

    Property* Property::Create(const char* typeName, const char* variableName, const char* value, bool bStatic, bool bConst)
	{
		BEHAVIAC_UNUSED_VAR(bStatic);

		if (!bConst)
		{
			char agentIntanceName[kInstanceLength] = "";
			const char* pPropertyName = 0;

			bool bParVar = IsParVar(variableName);
			char buffer[256];
			if (bParVar)
			{
				//if (string_icmp(variableName, "par1_kemployee_list_0") == 0)
				//{
				//	BEHAVIAC_ASSERT(true);
				//}

				string_sprintf(buffer, "%s::%s", typeName, variableName);
				pPropertyName = buffer;
			}
			else
			{
				pPropertyName = ParseInstanceNameProperty(variableName, agentIntanceName);
			}

			ClassStaticProperties_t::iterator it;
			if (pPropertyName)
			{
				it = Properties().find(pPropertyName);
			}
			else
			{
				it = Properties().end();
			}

			if (it == Properties().end())
			{
				Property* pProperty = Property::create(bParVar, bConst, typeName, pPropertyName, agentIntanceName, value);
				if (pPropertyName)
				{
					ClassStaticProperties_t::iterator itFound = Properties().find(pPropertyName);
					if (itFound != Properties().end())
					{
						BEHAVIAC_ASSERT(false);
					}

					Properties().insert(ClassStaticProperties_t::value_type(pPropertyName, pProperty));
				}

				Property* pO = pProperty->clone();
				return pO;
			}

			Property* p = it->second;

			Property* pO = p->clone();
			if (value)
			{
				pO->SetDefaultValueString(value);
			}

			return pO;
		}
		else
		{
			//const
			const CMemberBase* pMember = 0;
			bool bValidName = variableName && variableName[0] != '\0';
			char agentIntanceName[kInstanceLength] = "";
			
			const char* pPropertyName = variableName;
			if (bValidName)
			{
				pPropertyName = ParseInstanceNameProperty(variableName, agentIntanceName);
				pMember = Agent::FindMemberBase(pPropertyName);
			}

			if (pMember)
			{
				Property* pProperty = pMember->CreateProperty(value, true);

				return pProperty;
			}
			else
			{
				//const CMethodBase* pMethod = 0;
				//if (bValidName)
				//{
				//	pMethod = Agent::FindMethod(pPropertyName);
				//}

				//if (pMethod)
				//{
				//	Property* pProperty =  pMethod->CreateProperty(value, true);

				//	return pProperty;
				//}

				bool bParVar = bValidName && IsParVar(variableName);
				Property* pProperty = Property::create(bParVar, bConst, typeName, pPropertyName, agentIntanceName, value);

				return pProperty;
			}
		}

		//return 0;
	}

	void Property::DeleteFromCache(Property* property_)	{
		const char* pPropertyName = property_->GetVariableFullName();

		ClassStaticProperties_t::iterator it;
		if (pPropertyName) {
			it = Properties().find(pPropertyName);

			if (it != Properties().end())
			{
				Property* pProperty = it->second;
				BEHAVIAC_DELETE pProperty;

				Properties().erase(it);
			}
		}
	}

#define M_REGISTER_PRIMITIVES() \
        M_REGISTER(long long, "long");			\
		M_REGISTER(unsigned long long, "ulong");\
        M_REGISTER(int, "int");					\
		M_REGISTER(unsigned int, "uint");		\
        M_REGISTER(short, "short");				\
		M_REGISTER(unsigned short, "ushort");	\
        M_REGISTER(char, "char");				\
		M_REGISTER(signed char, "sbyte");		\
		M_REGISTER(unsigned char, "ubyte");		\
		M_REGISTER(bool, "bool");				\
		M_REGISTER(float, "float");				\
		M_REGISTER(double, "double");			\
		M_REGISTER(void*, "void*");				\
		M_REGISTER(behaviac::string, "string"); \

#if K_TYPE_CREATOR_
    void Property::RegisterBasicTypes()
    {
		//for primitives
#undef M_REGISTER
#define M_REGISTER(type, name)	Property::Register<type>(name)
		M_REGISTER_PRIMITIVES();

		//for vector
#undef M_REGISTER
#define M_REGISTER(type, name)	Property::Register<behaviac::vector<type> >(FormatString("vector<%s>", name));
		M_REGISTER_PRIMITIVES();

		Property::Register<behaviac::vector<behaviac::Agent*> >("vector<behaviac::Agent>");
    }


    void Property::UnRegisterBasicTypes()
    {
		//for primitives
#undef M_REGISTER
#define M_REGISTER(type, name)	Property::UnRegister<type>(name)
		M_REGISTER_PRIMITIVES();

		//for vector
#undef M_REGISTER
#define M_REGISTER(type, name)	Property::UnRegister<behaviac::vector<type> >(FormatString("vector<%s>", name));
		M_REGISTER_PRIMITIVES();

		Property::UnRegister<behaviac::vector<behaviac::Agent*> >("vector<behaviac::Agent>");
    }
#endif//#if K_TYPE_CREATOR_
}//namespace behaviac