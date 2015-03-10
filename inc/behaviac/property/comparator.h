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

#ifndef _BEHAVIAC_COMPARISOR_H_
#define _BEHAVIAC_COMPARISOR_H_

#include "behaviac/property/property.h"
#include "behaviac/agent/agent.h"
#include "behaviac/property/property_t.h"
#include "behaviac/property/operators.inl"

#include <vector>
#include <string>

namespace behaviac
{
    //------------------------------------------------------------------------
    enum E_VariableComparisonType
    {
        VariableComparisonType_Equal,			//( "Equal (==)" )
        VariableComparisonType_NotEqual,		//( "Not Equal (!=)" )
        VariableComparisonType_Greater,			//( "Greater (>)"  )
        VariableComparisonType_GreaterEqual,	//( "Greater Or Equal (>=)" )
        VariableComparisonType_Less,			//( "Lower (<)"  )
        VariableComparisonType_LessEqual,		//( "Lower Or Equal (<=)" )
		VariableComparisonType_And,				//( "Lower Or Equal (&&)" )
		VariableComparisonType_Or				//( "Lower Or Equal (||)" )
    };


    E_VariableComparisonType ParseComparisonType(const char* comparionOperator);

    //------------------------------------------------------------------------
    class BEHAVIAC_API VariableComparator
    {
    public:
		VariableComparator() : m_lhs(0), m_rhs(0)
		{}

		VariableComparator(const VariableComparator& copy) : m_lhs(copy.m_lhs), m_rhs(copy.m_rhs)
		{}

        virtual ~VariableComparator() {}

		virtual VariableComparator* clone() = 0;

        //virtual void Serialize( Serializer& serializer ) = 0;
        virtual bool Execute(Agent* agentL, Agent* agentR) const = 0;

		virtual bool Execute(CMethodBase* method, const Agent* parent, Agent* agentR) const = 0;

		void SetProperty(Property* lhs, Property* rhs)
		{
			m_lhs = lhs;
			m_rhs = rhs;
		}

	protected:
		Property* m_lhs;
		Property* m_rhs;
    };

    //------------------------------------------------------------------------
    //
    template< typename VariableType >
    class VariableComparatorImpl_ : public VariableComparator
    {
	protected:
		VariableComparatorImpl_(const VariableComparatorImpl_& copy) : VariableComparator(copy), m_comparisonType(copy.m_comparisonType)
		{}
    public:
        VariableComparatorImpl_();
        virtual ~VariableComparatorImpl_() {}

		virtual VariableComparator* clone() = 0;

        //void Serialize( Serializer& serializer );
        virtual bool Execute(Agent* agentL, Agent* agentR) const = 0;

		virtual bool Execute(CMethodBase* lhs, const Agent* parent, Agent* agentR) const = 0;

        void SetType(const E_VariableComparisonType type);
        E_VariableComparisonType GetType() const;
    protected:
        //The operator used in the comparison
        E_VariableComparisonType m_comparisonType;
    };


    //------------------------------------------------------------------------
    template< typename VariableType >
	VariableComparatorImpl_< VariableType >::VariableComparatorImpl_() : m_comparisonType(VariableComparisonType_Equal)
    {}

    //------------------------------------------------------------------------
    template< typename VariableType >
    inline void VariableComparatorImpl_< VariableType >::SetType(const E_VariableComparisonType type)
    {
        m_comparisonType = type;
    }

    //------------------------------------------------------------------------
    template< typename VariableType >
    inline E_VariableComparisonType VariableComparatorImpl_< VariableType >::GetType() const
    {
        return m_comparisonType;
    }

    template< typename VariableType >
    class VariableComparatorImpl : public VariableComparatorImpl_<VariableType>
    {
	protected:
		VariableComparatorImpl(const VariableComparatorImpl& copy) : VariableComparatorImpl_<VariableType>(copy)
		{}
    public:
        VariableComparatorImpl()
		{}

		virtual VariableComparator* clone()
		{
			return BEHAVIAC_NEW VariableComparatorImpl(*this);
		}

        //void Serialize( Serializer& serializer );
        virtual bool Execute(Agent* agentL, Agent* agentR) const;
		virtual bool Execute(CMethodBase* pLHS, const Agent* parent, Agent* agentR) const;
	};

    //------------------------------------------------------------------------
    template< typename VariableType >
    inline bool VariableComparatorImpl< VariableType >::Execute(Agent* agentL, Agent* agentR) const
    {
		TProperty<VariableType>* pTP_lhs = (TProperty<VariableType>*)this->m_lhs;
		TProperty<VariableType>* pTP_rhs = (TProperty<VariableType>*)this->m_rhs;

        const VariableType& lhs = pTP_lhs->GetValue(agentL);
        const VariableType& rhs = pTP_rhs->GetValue(agentR);

        switch (this->m_comparisonType)
        {
            case VariableComparisonType_Equal:
                return Details::Equal(lhs, rhs);

            case VariableComparisonType_NotEqual:
                return !Details::Equal(lhs, rhs);

            case VariableComparisonType_Greater:
                return Details::Greater(lhs, rhs);

            case VariableComparisonType_GreaterEqual:
                return Details::GreaterEqual(lhs, rhs);

            case VariableComparisonType_Less:
                return Details::Less(lhs, rhs);

            case VariableComparisonType_LessEqual:
                return Details::LessEqual(lhs, rhs);

            default:
                BEHAVIAC_ASSERT(0, "Unsupported comparison type");
                break;
        }

        return false;
    }

    template< typename VariableType >
    inline bool VariableComparatorImpl< VariableType >::Execute(CMethodBase* pLHS, const Agent* parent, Agent* agentR) const
    {
        VariableType lhs;
		
		bool bOk = pLHS->GetReturnValue(parent, lhs);
		BEHAVIAC_UNUSED_VAR(bOk);
		BEHAVIAC_ASSERT(bOk);

		TProperty<VariableType>* pTP_rhs = (TProperty<VariableType>*)this->m_rhs;
        const VariableType& rhs = pTP_rhs->GetValue(agentR);

        switch (this->m_comparisonType)
        {
            case VariableComparisonType_Equal:
                return Details::Equal(lhs, rhs);

            case VariableComparisonType_NotEqual:
                return !Details::Equal(lhs, rhs);

            case VariableComparisonType_Greater:
                return Details::Greater(lhs, rhs);

            case VariableComparisonType_GreaterEqual:
                return Details::GreaterEqual(lhs, rhs);

            case VariableComparisonType_Less:
                return Details::Less(lhs, rhs);

            case VariableComparisonType_LessEqual:
                return Details::LessEqual(lhs, rhs);

            default:
                BEHAVIAC_ASSERT(0, "Unsupported comparison type");
                break;
        }

        return false;
    }


    template<>
    class VariableComparatorImpl<bool> : public VariableComparatorImpl_<bool>
    {
	protected:
		VariableComparatorImpl(const VariableComparatorImpl& copy) : VariableComparatorImpl_<bool>(copy)
		{}
    public:
        VariableComparatorImpl()
		{}

		virtual VariableComparator* clone()
		{
			return BEHAVIAC_NEW VariableComparatorImpl(*this);
		}

        //void Serialize( Serializer& serializer );
        virtual bool Execute(Agent* agentL, Agent* agentR) const
		{
			TProperty<bool>* pTP_lhs = (TProperty<bool>*)this->m_lhs;
			TProperty<bool>* pTP_rhs = (TProperty<bool>*)this->m_rhs;

			bool lhs = pTP_lhs->GetValue(agentL);
			bool rhs = pTP_rhs->GetValue(agentR);

			switch (this->m_comparisonType)
			{
			case VariableComparisonType_Equal:
				return Details::Equal(lhs, rhs);

			case VariableComparisonType_NotEqual:
				return !Details::Equal(lhs, rhs);

			case VariableComparisonType_Greater:
				return Details::Greater(lhs, rhs);

			case VariableComparisonType_GreaterEqual:
				return Details::GreaterEqual(lhs, rhs);

			case VariableComparisonType_Less:
				return Details::Less(lhs, rhs);

			case VariableComparisonType_LessEqual:
				return Details::LessEqual(lhs, rhs);

			case VariableComparisonType_And:
				return (lhs && rhs);

			case VariableComparisonType_Or:
				return (lhs || rhs);

			default:
				BEHAVIAC_ASSERT(0, "Unsupported comparison type");
				break;
			}

			return false;
		}

		virtual bool Execute(CMethodBase* pLHS, const Agent* parent, Agent* agentR) const
		{
			bool lhs;

			bool bOk = pLHS->GetReturnValue(parent, lhs);
			BEHAVIAC_UNUSED_VAR(bOk);
			BEHAVIAC_ASSERT(bOk);

			TProperty<bool>* pTP_rhs = (TProperty<bool>*)this->m_rhs;
			bool rhs = pTP_rhs->GetValue(agentR);

			switch (this->m_comparisonType)
			{
			case VariableComparisonType_Equal:
				return Details::Equal(lhs, rhs);

			case VariableComparisonType_NotEqual:
				return !Details::Equal(lhs, rhs);

			case VariableComparisonType_Greater:
				return Details::Greater(lhs, rhs);

			case VariableComparisonType_GreaterEqual:
				return Details::GreaterEqual(lhs, rhs);

			case VariableComparisonType_Less:
				return Details::Less(lhs, rhs);

			case VariableComparisonType_LessEqual:
				return Details::LessEqual(lhs, rhs);

			case VariableComparisonType_And:
				return (lhs && rhs);

			case VariableComparisonType_Or:
				return (lhs || rhs);

			default:
				BEHAVIAC_ASSERT(0, "Unsupported comparison type");
				break;
			}

			return false;
		}
	};

}


#endif//_BEHAVIAC_COMPARISOR_H_
