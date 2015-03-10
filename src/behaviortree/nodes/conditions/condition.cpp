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

#include "behaviac/base/base.h"
#include "behaviac/world/world.h"
#include "behaviac/behaviortree/nodes/conditions/condition.h"

#include "behaviac/base/core/profiler/profiler.h"

namespace behaviac
{
	Condition::Condition() : m_opl(0), m_opr(0), m_opl_m(0), m_comparator(0)
	{
	}

	Condition::~Condition()
	{
		BEHAVIAC_DELETE(m_opl);
		BEHAVIAC_DELETE(m_opr);
		BEHAVIAC_DELETE(m_opl_m);
		BEHAVIAC_DELETE(m_comparator);
	}

	const char* kStatic = "static";
	Property* LoadLeft(const char* value, behaviac::string& propertyName, const char* constValue)
	{
		Property* opl = 0;

		if (value[0] != '\0')
		{
			behaviac::vector<behaviac::string> tokens;
			behaviac::StringUtils::SplitIntoArray(value, " ", tokens);

			if (tokens.size() == 2)
			{
				//int AgentTest::Property1
				propertyName = tokens[1];
				opl = Property::Create(tokens[0].c_str(), tokens[1].c_str(), constValue, false, false);
			}
			else
			{
				//static int AgentTest::Property6
				BEHAVIAC_ASSERT(tokens[0] == kStatic);
				propertyName = tokens[2];
				opl = Property::Create(tokens[1].c_str(), tokens[2].c_str(), constValue, true, false);
			}
		}

		return opl;
	}

	Property* LoadRight(const char* value, const behaviac::string& propertyName, behaviac::string& typeName)
	{
		Property* opr = 0;
		if (value[0] != '\0')
		{
			const char* kConst = "const";
			const int kConstLength = 5;

			if (behaviac::StringUtils::StartsWith(value, kConst))
			{
				//const Int32 0
				const char* p = behaviac::StringUtils::FirstToken(value + kConstLength + 1, ' ', typeName);
				BEHAVIAC_ASSERT(*p == ' ');

				opr = Property::Create(typeName.c_str(), propertyName.c_str(), p + 1, false, true);
			}
			else 
			{
				behaviac::vector<behaviac::string> tokens;
				behaviac::StringUtils::SplitIntoArray(value, " ", tokens);

				if (tokens[0] == kStatic)
				{
					//static int Property1
					BEHAVIAC_ASSERT(tokens.size() == 3);
					typeName = tokens[1];
					opr = Property::Create(tokens[1].c_str(), tokens[2].c_str(), 0, true, false);
				}
				else
				{
					//int Property1
					BEHAVIAC_ASSERT(tokens.size() == 2);
					typeName = tokens[0];
					opr = Property::Create(tokens[0].c_str(), tokens[1].c_str(), 0, false, false);
				}
			}
		}

		return opr;
	}

	CMethodBase* LoadMethod(const char* value);

    void Condition::load(int version, const char* agentType, const properties_t& properties)
    {
		super::load(version, agentType, properties);

		behaviac::string typeName;
		behaviac::string propertyName;
        behaviac::string comparatorName;

        for (propertie_const_iterator_t it = properties.begin(); it != properties.end(); ++it)
        {
            const property_t& p = (*it);

            if (strcmp(p.name, "Operator") == 0)
            {
                comparatorName = p.value;
            }
			else if (strcmp(p.name, "Opl") == 0)
            {
				const char* pParenthesis = strchr(p.value, '(');
				if (pParenthesis == 0)
				{
					this->m_opl = LoadLeft(p.value, propertyName, 0);
				}
				else
				{
					//method
					this->m_opl_m = LoadMethod(p.value);
				}
            }
            else if (strcmp(p.name, "Opr") == 0)
            {
				this->m_opr = LoadRight(p.value, propertyName, typeName);
            }
            else
            {
                //BEHAVIAC_ASSERT(0, "unrecognised property %s", p.name);
            }
        }

		if (!comparatorName.empty() && (this->m_opl || this->m_opl_m) && this->m_opr)
		{
			this->m_comparator = Condition::Create(typeName.c_str(), comparatorName.c_str(), this->m_opl, this->m_opr);
		}
    }

	bool Condition::IsValid(Agent* pAgent, BehaviorTask* pTask) const
	{
		if (!Condition::DynamicCast(pTask->GetNode()))
		{
			return false;
		}

		return super::IsValid(pAgent, pTask);
	}

	BehaviorTask* Condition::createTask() const
	{
		ConditionTask* pTask = BEHAVIAC_NEW ConditionTask();
		
		return pTask;
	}

    Condition::VariableComparators* Condition::ms_comparatorCreators;

	Condition::VariableComparators& Condition::ComparatorCreators()
	{
		if (!ms_comparatorCreators)
		{
			ms_comparatorCreators = BEHAVIAC_NEW Condition::VariableComparators;
		}
		return *ms_comparatorCreators;
	}

	void Condition::Cleanup()
	{
		if (ms_comparatorCreators)
		{
			ms_comparatorCreators->clear();
			BEHAVIAC_DELETE(ms_comparatorCreators);
			ms_comparatorCreators = 0;
		}
	}

    VariableComparator* Condition::Create(const char* typeName, const char* comparionOperator,
                                          const Property* lhs, const Property* rhs)
    {
        E_VariableComparisonType comparisonType = ParseComparisonType(comparionOperator);

		bool bAgentPtr = false;
		//it might be par or the right value of condition/assignment
		if (Agent::IsAgentClassName(typeName))
		{
			bAgentPtr = true;
			typeName = "void*";
		}

		BEHAVIAC_UNUSED_VAR(bAgentPtr);

        VariableComparatorCreator* pCreator = ComparatorCreators()[typeName];

        if (pCreator)
        {
            VariableComparator* pComparator = (*pCreator)(comparisonType, lhs, rhs);
            return pComparator;
        }
		else
		{
			BEHAVIAC_LOGWARNING("please add Condition::Register<%s>(\"%s\") in your code\n", typeName, typeName, typeName);
			BEHAVIAC_ASSERT(0);
		}

        return 0;
    }

#define M_REGISTER_PRIMITIVES() \
        M_REGISTER(long, "long");				\
		M_REGISTER(unsigned long, "ulong");		\
        M_REGISTER(int, "int");					\
		M_REGISTER(unsigned int, "uint");		\
        M_REGISTER(short, "short");				\
		M_REGISTER(unsigned short, "ushort");	\
        M_REGISTER(char, "char");				\
		M_REGISTER(unsigned char, "uchar");		\
		M_REGISTER(bool, "bool");				\
		M_REGISTER(float, "float");				\
		M_REGISTER(double, "double");			\
		M_REGISTER(void*, "void*");				\
		M_REGISTER(behaviac::string, "string");

    void Condition::RegisterBasicTypes()
    {
		//for primitives
#undef M_REGISTER
#define M_REGISTER(type, name)	Condition::Register<type>(name)
		M_REGISTER_PRIMITIVES();

		//for vector
#undef M_REGISTER
#define M_REGISTER(type, name)	Condition::Register<behaviac::vector<type> >(FormatString("vector<%s>", name));
		M_REGISTER_PRIMITIVES();

		Condition::Register<behaviac::vector<behaviac::Agent*> >("vector<behaviac::Agent>");

		Condition::Register<EBTStatus>("EBTStatus"); 
    }

    void Condition::UnRegisterBasicTypes()
    {
		//for primitives
#undef M_REGISTER
#define M_REGISTER(type, name)	Condition::UnRegister<type>(name)
		M_REGISTER_PRIMITIVES();

		//for vector
#undef M_REGISTER
#define M_REGISTER(type, name)	Condition::UnRegister<behaviac::vector<type> >(FormatString("vector<%s>", name));
		M_REGISTER_PRIMITIVES();

		Condition::UnRegister<behaviac::vector<behaviac::Agent*> >("vector<behaviac::Agent>");

		Condition::UnRegister<EBTStatus>("EBTStatus"); 
    }

	void ConditionTask::copyto(BehaviorTask* target) const
	{
		super::copyto(target);
	}

	void ConditionTask::save(ISerializableNode* node) const
	{
		super::save(node);
	}

	void ConditionTask::load(ISerializableNode* node)
	{
		super::load(node);
	}

    bool ConditionTask::onenter(Agent* pAgent)
    {
    	BEHAVIAC_UNUSED_VAR(pAgent);
        return true;
    }

    void ConditionTask::onexit(Agent* pAgent, EBTStatus s)
    {
        BEHAVIAC_UNUSED_VAR(pAgent);
        BEHAVIAC_UNUSED_VAR(s);
    }

	bool DoCompare(Agent* pAgent, VariableComparator* comparator, Property* opl, CMethodBase* opl_m, Property* opr)
	{
		bool bResult = false;
		if (opl)
		{
			Agent* agent_left = pAgent;
			ParentType pt = opl->GetParentType();
			if (pt == PT_INSTANCE)
			{
				agent_left = Agent::GetInstance(opl->GetInstanceNameString(), agent_left->GetContextId());
				BEHAVIAC_ASSERT(agent_left);
			}

			Agent* agent_right = pAgent;
			pt = opr->GetParentType();
			if (pt == PT_INSTANCE)
			{
				agent_right = Agent::GetInstance(opr->GetInstanceNameString(), agent_left->GetContextId());
				BEHAVIAC_ASSERT(agent_right);
			}

			bResult = comparator->Execute(agent_left, agent_right);
		}
		else if (opl_m)
		{
			ParentType pt = opl_m->GetParentType();
			Agent* agent_left = pAgent;
			if (pt == PT_INSTANCE)
			{
				agent_left = Agent::GetInstance(opl_m->GetInstanceNameString(), agent_left->GetContextId());
				BEHAVIAC_ASSERT(agent_left);
			}

			opl_m->run(agent_left, pAgent);

			Agent* agent_right = pAgent;
			pt = opr->GetParentType();
			if (pt == PT_INSTANCE)
			{
				agent_right = Agent::GetInstance(opr->GetInstanceNameString(), agent_right->GetContextId());
				BEHAVIAC_ASSERT(agent_right);
			}

			bResult = comparator->Execute(opl_m, agent_left, agent_right);
		}

		return bResult;
	}

    EBTStatus ConditionTask::update(Agent* pAgent, EBTStatus childStatus)
    {
    	BEHAVIAC_UNUSED_VAR(pAgent);
    	BEHAVIAC_UNUSED_VAR(childStatus);

		EBTStatus result = BT_FAILURE;

		BEHAVIAC_ASSERT(Condition::DynamicCast(this->GetNode()));
		Condition* pConditionNode = (Condition*)(this->GetNode());

		if (pConditionNode->m_comparator)
		{
//#if BEHAVIAC_ENABLE_PROFILING
//			BEHAVIAC_PROFILE("Node");
//#endif
			if (DoCompare(pAgent, pConditionNode->m_comparator, pConditionNode->m_opl, pConditionNode->m_opl_m, pConditionNode->m_opr))
			{
				result = BT_SUCCESS;
			}
		}
		else
		{
//#if BEHAVIAC_ENABLE_PROFILING
//			BEHAVIAC_PROFILE("ConditionGenerated");
//#endif
			result = pConditionNode->update_impl(pAgent, childStatus);
		}

        return result;
    }

}
