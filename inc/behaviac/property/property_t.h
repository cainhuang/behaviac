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

#ifndef BEHAVIAC_PROPERTY_T_H_
#define BEHAVIAC_PROPERTY_T_H_

#include "behaviac/property/property.h"
#include "behaviac/agent/agent.h"
#include "behaviac/base/object/member.h"

#define  K_TYPE_CREATOR_	1

class CMemberBase;

namespace behaviac
{
	template<typename VariableType>
	inline void ComputeTo(VariableType v, Property* pPropertyTo, Agent* pAgentTo, EComputeOperator opr)
	{
		BEHAVIAC_UNUSED_VAR(v);
		BEHAVIAC_UNUSED_VAR(pPropertyTo);
		BEHAVIAC_UNUSED_VAR(pAgentTo);
		BEHAVIAC_UNUSED_VAR(opr);

		BEHAVIAC_ASSERT(0);
	};

	template<typename VariableType>
    class TProperty : public Property
    {
		TProperty& operator=(const TProperty& copy);

	protected:
		TProperty(const TProperty& copy) : Property(copy), m_defaultValue(copy.m_defaultValue), m_bValidDefaultValue(copy.m_bValidDefaultValue), m_bIsConst(copy.m_bIsConst)
		{}
    public:
		BEHAVIAC_DECLARE_MEMORY_OPERATORS(TProperty);
        TProperty(const CMemberBase* pMemberBase, bool bConst) : Property(pMemberBase), m_bValidDefaultValue(false), m_bIsConst(bConst)
        {
        }

        virtual ~TProperty()
        {}

		virtual Property* clone() 
		{
			Property* p = BEHAVIAC_NEW TProperty(*this);

			return p;
		}

		virtual int GetTypeId() const
		{
			return GetClassTypeNumberId<VariableType>();
		}

		virtual void SetFrom(Agent* pAgentFrom, behaviac::IAsyncValue* from, Agent* pAgentTo)
		{
			BEHAVIAC_UNUSED_VAR(pAgentFrom);
			const VariableType& retV = ((behaviac::AsyncValue<VariableType>*)from)->get();
			this->SetValue(pAgentTo, retV);
		}

		virtual void SetFrom(Agent* pAgentFrom, const Property* from, Agent* pAgentTo)
		{
			TProperty<VariableType>* fromT = (TProperty<VariableType>*)from;

			const VariableType& retV = fromT->GetValue(pAgentFrom);

			this->SetValue(pAgentTo, retV);
		}

		virtual void SetFrom(Agent* pAgentfrom, const CMemberBase* from, Agent* pAgentTo) 
		{
			int typeId = this->GetTypeId();
			void* pData = from->Get(pAgentfrom, typeId);
			VariableType* pV = (VariableType*)pData;

			this->SetValue(pAgentTo, *pV);
		}

		virtual void ComputeFrom(Agent* pAgentFrom, const Property* from, Agent* pAgentTo, EComputeOperator opr)
		{
			TProperty<VariableType>* fromT = (TProperty<VariableType>*)from;

			const VariableType& retV = fromT->GetValue(pAgentFrom);

			ComputeTo(retV, this, pAgentTo, opr);
		}

		virtual void ComputeFrom(Agent* pAgentfrom, behaviac::IAsyncValue* from, Agent* pAgentTo, EComputeOperator opr)
		{
			BEHAVIAC_UNUSED_VAR(pAgentfrom);
			const VariableType retV = ((behaviac::AsyncValue<VariableType>*)from)->get();

			ComputeTo(retV, this, pAgentTo, opr);
		}

		virtual void SetDefaultInteger(int count)
		{
			VariableType v;
			
			ConvertFromInteger(count, v);

			this->SetDefaultValue(v);
		}

		virtual uint64_t GetDefaultInteger() const
		{
			const VariableType& retV = this->GetDefaultValue();

			uint64_t result = ConvertToInteger(retV);
			return result;
		}

		virtual float DifferencePercentage(const Property* other) const
		{
			return const_cast<CMemberBase*>(this->m_memberBase)->DifferencePercentage(this, other);
		}

		virtual void Instantiate(Agent* pAgent)
		{
			const VariableType& v = this->GetDefaultValue();
			BEHAVIAC_ASSERT(!this->m_memberBase);

			pAgent->Instantiate(v, this);
		}


		virtual void UnInstantiate(Agent* pAgent)
		{
			BEHAVIAC_ASSERT(!this->m_memberBase);

			pAgent->UnInstantiate<VariableType>(this->m_varaibleName.c_str());
		}

		virtual void UnLoad(Agent* pAgent)
		{
			BEHAVIAC_ASSERT(!this->m_memberBase);

			pAgent->UnLoad<VariableType>(this->m_varaibleName.c_str());
		}


		virtual IVariable* CreateVar()
		{
			IVariable* v = BEHAVIAC_NEW TVariable<VariableType>(0, this, this->m_defaultValue);

			return v;
		}

		virtual void SetDefaultValueString(const char* valString)
		{
			VariableType v;
			if (behaviac::StringUtils::FromString(valString, v))
			{
				this->SetDefaultValue(v);
			}
		}

		virtual void SetDefaultValue(const Property* r)
		{
			TProperty<VariableType>* rT = (TProperty<VariableType>*)r;
			const VariableType& v = rT->GetDefaultValue();
			this->SetDefaultValue(v);
		}

        void SetDefaultValue(const VariableType& v)
        {
			this->m_bValidDefaultValue = true;
			this->m_defaultValue = v;
        }

        const VariableType& GetDefaultValue() const
        {
			BEHAVIAC_ASSERT(this->m_bValidDefaultValue);

			return this->m_defaultValue;
        }

        void SetValue(Agent* parent, const VariableType& v)
        {
			BEHAVIAC_ASSERT(parent);
			BEHAVIAC_ASSERT(!m_bIsConst);

			const char* staticClassName = 0;
			if (this->m_memberBase)
			{
#if !defined(BEHAVIAC_RELEASE)
				ParentType pt = this->m_memberBase->GetParentType();

				if (pt == PT_INSTANCE)
				{
					Agent* pInstance = Agent::GetInstance(this->GetInstanceNameString(), parent->GetContextId());
					BEHAVIAC_ASSERT(pInstance == parent);
				}
#endif//BEHAVIAC_RELEASE
				if (this->m_pt == PT_INSTANCE)
				{
					Agent* pInstance = Agent::GetInstance(this->GetInstanceNameString(), parent->GetContextId());
					parent = pInstance;
				}
				
				//int typeId = GetClassTypeNumberId<VariableType>();
				//VariableType* pVariable = (VariableType*)this->m_memberBase->Get(parent, typeId);

				//*pVariable = v;

				if (this->m_memberBase->ISSTATIC())
				{
					staticClassName = this->m_memberBase->GetClassNameString();
				}
			}

			parent->SetVariableRegistry(this->m_memberBase, this->m_varaibleName.c_str(), v, staticClassName, this->m_variableId);
        }

		const VariableType& GetValue(const Agent* parent) const
		{
			if (!parent || m_bIsConst)
			{
				return this->GetDefaultValue();
			}
			else
			{
				if (this->m_memberBase)
				{
#if !defined(BEHAVIAC_RELEASE)
					ParentType pt = this->m_memberBase->GetParentType();
					if (pt == PT_INSTANCE)
					{
						Agent* pInstance = Agent::GetInstance(this->GetInstanceNameString(), parent->GetContextId());
						BEHAVIAC_ASSERT(pInstance == parent);
					}
#endif//BEHAVIAC_RELEASE
					if (this->m_pt == PT_INSTANCE)
					{
						Agent* pInstance = Agent::GetInstance(this->GetInstanceNameString(), parent->GetContextId());
						parent = pInstance;
					}

					int typeId = GetClassTypeNumberId<VariableType>();
					VariableType* pVariable = (VariableType*)this->m_memberBase->Get(parent, typeId);

					return *pVariable;
				}
				else
				{
					return parent->GetVariable<VariableType>(this->m_varaibleName.c_str());
				}
			}
		}

		const VariableType& GetValue(const Agent* parent, const Agent* parHolder) const
		{
			if (!parent || m_bIsConst)
			{
				return this->GetDefaultValue();
			}
			else
			{
				if (this->m_memberBase)
				{
#if !defined(BEHAVIAC_RELEASE)
					ParentType pt = this->m_memberBase->GetParentType();
					if (pt == PT_INSTANCE)
					{
						Agent* pInstance = Agent::GetInstance(this->GetInstanceNameString(), parHolder->GetContextId());
						BEHAVIAC_ASSERT(pInstance == parHolder);
					}
#endif//BEHAVIAC_RELEASE

					if (this->m_pt == PT_INSTANCE)
					{
						Agent* pInstance = Agent::GetInstance(this->GetInstanceNameString(), parHolder->GetContextId());
						parHolder = pInstance;
					}

					int typeId = GetClassTypeNumberId<VariableType>();
					VariableType* pVariable = (VariableType*)this->m_memberBase->Get(parHolder, typeId);

					return *pVariable;
				}
				else
				{
					return parHolder->GetVariable<VariableType>(this->m_varaibleName.c_str());
				}
			}
		}
	
	private:
		VariableType	m_defaultValue;
		bool			m_bValidDefaultValue;
		const bool		m_bIsConst;
    };

    template<typename T>
	inline Property* Property::Creator(const char* value, const CMemberBase* pMemberBase, bool bConst)
    {
        TProperty<T>* p = (TProperty<T>*)Creator<T>(pMemberBase, bConst);

		//a const must have default value
		BEHAVIAC_ASSERT(!bConst || value);

        if (value)
        {
            T v;
			if (behaviac::StringUtils::FromString(value, v))
			{
				p->SetDefaultValue(v);
			}
			else
			{
				//a const must have a valid default value
				BEHAVIAC_ASSERT(!bConst);
			}
        }

        return p;
    }


	template<typename T>
	inline Property* Property::Creator(const CMemberBase* pMemberBase, bool bConst)
	{
		typedef TProperty<T> PropertyType;
		PropertyType* p = BEHAVIAC_NEW PropertyType(pMemberBase, bConst);

		return p;
	}

#define M_COMPUTE_TO(VariableType)\
	template<>\
	inline void ComputeTo<VariableType>(VariableType v, Property* pPropertyTo, Agent* pAgentTo, EComputeOperator opr)\
	{\
		TProperty<VariableType>* pPropertyToT = (TProperty<VariableType>*)pPropertyTo;\
		const VariableType& thisV = pPropertyToT->GetValue(pAgentTo);\
		\
		VariableType resultV = thisV;\
		\
		switch (opr)\
		{\
		case E_ADD:\
			resultV += v;\
			break;\
			\
		case E_SUB:\
			resultV -= v;\
			break;\
			\
		case E_MUL:\
			resultV *= v;\
			break;\
			\
		case E_DIV:\
			resultV /= v;\
			break;\
			\
		default:\
			BEHAVIAC_ASSERT(0);\
			break;\
		}\
		\
		pPropertyToT->SetValue(pAgentTo, resultV);\
	}

	M_COMPUTE_TO(long)
	M_COMPUTE_TO(int)
	M_COMPUTE_TO(short)
	M_COMPUTE_TO(char)

	M_COMPUTE_TO(unsigned long)
	M_COMPUTE_TO(unsigned int)
	M_COMPUTE_TO(unsigned short)
	M_COMPUTE_TO(unsigned char)

	M_COMPUTE_TO(float)
	M_COMPUTE_TO(double)
}

template <typename T>
float CMemberBase::TDifferencePercentage(const behaviac::Property* l, const behaviac::Property* r)
{
	const behaviac::TProperty<T>* pV = (const behaviac::TProperty<T>*)l;
	const T& v = pV->GetDefaultValue();

	const behaviac::TProperty<T>* pOtherV = (const behaviac::TProperty<T>*)r;
	const T& ov = pOtherV->GetDefaultValue();

	float result = FloatReturnSubtract(v, ov);

	return result / this->m_range;
}


#endif//BEHAVIAC_PROPERTY_T_H_
