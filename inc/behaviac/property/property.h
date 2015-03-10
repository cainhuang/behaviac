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

#ifndef BEHAVIAC_PROPERTY_H_
#define BEHAVIAC_PROPERTY_H_

#include "behaviac/base/dynamictype.h"
#include "behaviac/base/core/factory.h"
#include "behaviac/base/core/thread/asyncvalue.h"

#include "behaviac/base/base.h"
#include "behaviac/base/object/tagobject.h"

#include "behaviac/base/string/valuefromstring.h"
#include "behaviac/base/object/typehandler.h"

#include <map>

#define  K_TYPE_CREATOR_	1

class CMemberBase;

namespace behaviac
{
    //------------------------------------------------------------------------
    BEHAVIAC_API uint32_t MakeVariableId(const char* idString);
	BEHAVIAC_API const char* GetNameWithoutClassName(const char* variableName);

	enum EComputeOperator
	{
		E_INVALID,
		E_ADD,
		E_SUB,
		E_MUL,
		E_DIV
	};

	class Agent;
    class BEHAVIAC_API Property
    {
    public:
        BEHAVIAC_DECLARE_MEMORY_OPERATORS(Property);

		Property(const CMemberBase* pMemberBase);
		virtual ~Property();

		void SetVariableName(const char* variableName);

		const char* GetVariableName() const
		{
			return this->m_varaibleName.c_str();
		}

		uint32_t GetVariableId() const
		{
			return m_variableId;
		}

		const char* GetVariableFullName() const
		{
			return this->m_varaibleFullName.c_str();
		}

		const char* GetClassNameString() const;

		const char* GetInstanceNameString() const;
		void SetInstanceNameString(const char* name);

		virtual Property* clone() = 0;

		virtual int GetTypeId() const	= 0;

		virtual void SetFrom(Agent* pAgentfrom, behaviac::IAsyncValue* from, Agent* pAgentTo) = 0;
		virtual void SetFrom(Agent* pAgentfrom, const Property* from, Agent* pAgentTo) = 0;
		virtual void SetFrom(Agent* pAgentfrom, const CMemberBase* from, Agent* pAgentTo) = 0;

		virtual void ComputeFrom(Agent* pAgentfrom, behaviac::IAsyncValue* from, Agent* pAgentTo, EComputeOperator opr) = 0;
		virtual void ComputeFrom(Agent* pAgentFrom, const Property* from, Agent* pAgentTo, EComputeOperator opr) = 0;

		
		virtual void SetDefaultValueString(const char* valString) = 0;
		virtual void SetDefaultValue(const Property* r) = 0;
		virtual void SetDefaultInteger(int count) = 0;
		virtual uint64_t GetDefaultInteger() const = 0;
		virtual void Instantiate(Agent* pAgent) = 0;
		virtual void UnInstantiate(Agent* pAgent) = 0;
		virtual void UnLoad(Agent* pAgent) = 0;

		ParentType GetParentType() const;

		virtual float DifferencePercentage(const Property* other) const = 0;

		void SetRefName(const char* refParName);
		const behaviac::string& GetRefName() const;
		uint32_t GetRefNameId() const;
#if K_TYPE_CREATOR_
		template<typename T>
        static bool Register(const char* typeName)
        {
            PropertyCreators()[typeName] = &Creator<T>;

			return true;
        }
        template<typename T>
        static void UnRegister(const char* typeName)
        {
            PropertyCreators().erase(typeName);
        }

        static void RegisterBasicTypes();
        static void UnRegisterBasicTypes();
#endif//#if K_TYPE_CREATOR_

		///create instance property, 
		///create class scope static property
		static Property* Create(const char* typeName, const char* variableName, const char* value, bool bStatic, bool bConst);
		static void DeleteFromCache(Property* property_);

        template<typename T>
        static Property* Creator(const char* value, const CMemberBase* pMemberBase, bool bConst);

        template<typename T>
        static Property* Creator(const CMemberBase* pMemberBase, bool bConst);

		static void Cleanup();
    protected:
		Property(const Property& copy);

	private:
#if K_TYPE_CREATOR_
        typedef Property* PropertyCreator(const char* value, const CMemberBase* pMemberBase, bool bConst);
        typedef behaviac::map<behaviac::string, PropertyCreator*> PropertyCreators_t;
        typedef PropertyCreators_t::iterator PropertyCreatorIterator;
        static PropertyCreators_t* ms_propertyCreators;
		static PropertyCreators_t& PropertyCreators();
#endif//#if K_TYPE_CREATOR_
		static Property* create(bool bParVar, bool bConst, const char* typeName, const char* variableName, const char* instanceName, const char* value);

		typedef behaviac::map<behaviac::string, Property*> ClassStaticProperties_t;
		static ClassStaticProperties_t* ms_properties;
		static ClassStaticProperties_t& Properties();
	protected:
		behaviac::string		m_varaibleName;

		//used for Delete
		behaviac::string		m_varaibleFullName;
		uint32_t				m_variableId;

		behaviac::string		m_refParName;
		uint32_t				m_refParNameId;

		const CMemberBase*		m_memberBase;
		ParentType				m_pt;
		behaviac::string		m_instanceName;
    };

	template<typename VariableType>
	inline uint64_t ConvertToInteger(const VariableType& v)
	{
		BEHAVIAC_UNUSED_VAR(v); 
		return 0;
	}

	template<>
	inline uint64_t ConvertToInteger(const long& v)
	{
		return (uint64_t)v;
	}

	template<>
	inline uint64_t ConvertToInteger(const int& v)
	{
		return (uint64_t)v;
	}

	template<>
	inline uint64_t ConvertToInteger(const short& v)
	{
		return (uint64_t)v;
	}

	//template<>
	//inline uint64_t ConvertToInteger(const __int8& v)
	//{
	//	return (uint64_t)v;
	//}

	template<>
	inline uint64_t ConvertToInteger(const char& v)
	{
		return (uint64_t)v;
	}

	template<>
	inline uint64_t ConvertToInteger(const unsigned long& v)
	{
		return (uint64_t)v;
	}

	template<>
	inline uint64_t ConvertToInteger(const unsigned int& v)
	{
		return (uint64_t)v;
	}

	template<>
	inline uint64_t ConvertToInteger(const unsigned short& v)
	{
		return (uint64_t)v;
	}

	//template<>
	//inline uint64_t ConvertToInteger(const unsigned __int8& v)
	//{
	//	return (uint64_t)v;
	//}

	template<>
	inline uint64_t ConvertToInteger(const unsigned char& v)
	{
		return (uint64_t)v;
	}
	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////
	template<typename VariableType>
	inline void ConvertFromInteger(int v, VariableType& ret)
	{
        BEHAVIAC_UNUSED_VAR(v);
		ret = VariableType();
	}

	template<>
	inline void ConvertFromInteger(int v, long& ret)
	{
		ret = (long)v;
	}

	template<>
	inline void ConvertFromInteger(int v, int& ret)
	{
		ret = (int)v;
	}

	template<>
	inline void ConvertFromInteger(int v, short& ret)
	{
		ret = (short)v;
	}

	//template<>
	//inline void ConvertFromInteger(int v, __int8& ret)
	//{
	//	ret = (__int8)v;
	//}

	template<>
	inline void ConvertFromInteger(int v, char& ret)
	{
		ret = (char)v;
	}

	template<>
	inline void ConvertFromInteger(int v, unsigned long& ret)
	{
		ret = (unsigned long)v;
	}

	template<>
	inline void ConvertFromInteger(int v, unsigned int& ret)
	{
		ret = (unsigned int)v;
	}

	template<>
	inline void ConvertFromInteger(int v, unsigned short& ret)
	{
		ret = (unsigned short)v;
	}

	//template<>
	//inline unsigned __int8 ConvertFromInteger(int v)
	//{
	//	ret = (unsigned __int8)v;
	//}

	template<>
	inline void ConvertFromInteger(int v, unsigned char& ret)
	{
		ret = (unsigned char)v;
	}
	////////////////////////////////////////////////////////////////////////
}


#endif//BEHAVIAC_PROPERTY_H_
