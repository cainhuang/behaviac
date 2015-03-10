// ---------------------------------------------------------------------
/* This file is auto-generated, so please don't modify it by yourself!
Usage: include it in a certain cpp accordingly(RELATIVE_PATH is the path where it is generated):

      #include "RELATIVE_PATH/generated_behaviors.cpp"
*/

// Export file: ../../../../test/btperformance/generated_behaviors.cpp
// ---------------------------------------------------------------------

// You should set the include path of the behaviac lib in your project
// for using the following header files :
#include "behaviac/behaviortree/behaviortree.h"

#include "behaviac/behaviortree/nodes/actions/action.h"
#include "behaviac/behaviortree/nodes/actions/assignment.h"
#include "behaviac/behaviortree/nodes/actions/compute.h"
#include "behaviac/behaviortree/nodes/actions/noop.h"
#include "behaviac/behaviortree/nodes/actions/wait.h"
#include "behaviac/behaviortree/nodes/actions/waitforsignal.h"
#include "behaviac/behaviortree/nodes/actions/waitframes.h"
#include "behaviac/behaviortree/nodes/composites/compositestochastic.h"
#include "behaviac/behaviortree/nodes/composites/ifelse.h"
#include "behaviac/behaviortree/nodes/composites/parallel.h"
#include "behaviac/behaviortree/nodes/composites/query.h"
#include "behaviac/behaviortree/nodes/composites/referencebehavior.h"
#include "behaviac/behaviortree/nodes/composites/selector.h"
#include "behaviac/behaviortree/nodes/composites/selectorloop.h"
#include "behaviac/behaviortree/nodes/composites/selectorprobability.h"
#include "behaviac/behaviortree/nodes/composites/selectorstochastic.h"
#include "behaviac/behaviortree/nodes/composites/sequence.h"
#include "behaviac/behaviortree/nodes/composites/sequencestochastic.h"
#include "behaviac/behaviortree/nodes/composites/withprecondition.h"
#include "behaviac/behaviortree/nodes/conditions/and.h"
#include "behaviac/behaviortree/nodes/conditions/conditionbase.h"
#include "behaviac/behaviortree/nodes/conditions/condition.h"
#include "behaviac/behaviortree/nodes/conditions/false.h"
#include "behaviac/behaviortree/nodes/conditions/or.h"
#include "behaviac/behaviortree/nodes/conditions/true.h"
#include "behaviac/behaviortree/nodes/decorators/decoratoralwaysfailure.h"
#include "behaviac/behaviortree/nodes/decorators/decoratoralwaysrunning.h"
#include "behaviac/behaviortree/nodes/decorators/decoratoralwayssuccess.h"
#include "behaviac/behaviortree/nodes/decorators/decoratorcount.h"
#include "behaviac/behaviortree/nodes/decorators/decoratorcountlimit.h"
#include "behaviac/behaviortree/nodes/decorators/decoratorfailureuntil.h"
#include "behaviac/behaviortree/nodes/decorators/decoratorframes.h"
#include "behaviac/behaviortree/nodes/decorators/decoratorlog.h"
#include "behaviac/behaviortree/nodes/decorators/decoratorloop.h"
#include "behaviac/behaviortree/nodes/decorators/decoratorloopuntil.h"
#include "behaviac/behaviortree/nodes/decorators/decoratornot.h"
#include "behaviac/behaviortree/nodes/decorators/decoratorsuccessuntil.h"
#include "behaviac/behaviortree/nodes/decorators/decoratortime.h"
#include "behaviac/behaviortree/nodes/decorators/decoratorweight.h"
#include "behaviac/behaviortree/attachments/event.h"
#include "behaviac/behaviortree/attachments/predicate.h"

// You should set the agent header files of your game
// when exporting cpp files in the behaviac editor:

using namespace behaviac;

// Agent property and method handlers

struct PROPERTY_TYPE_CPerformanceAgent_DistanceToEnemy { };
template<> BEHAVIAC_FORCEINLINE float& CPerformanceAgent::_Get_Property_<PROPERTY_TYPE_CPerformanceAgent_DistanceToEnemy>()
{
	unsigned char* pc = (unsigned char*)this;
	pc += (int)offsetof(CPerformanceAgent, CPerformanceAgent::DistanceToEnemy);
	return *(reinterpret_cast<float*>(pc));
}

struct PROPERTY_TYPE_CPerformanceAgent_Food { };
template<> BEHAVIAC_FORCEINLINE float& CPerformanceAgent::_Get_Property_<PROPERTY_TYPE_CPerformanceAgent_Food>()
{
	unsigned char* pc = (unsigned char*)this;
	pc += (int)offsetof(CPerformanceAgent, CPerformanceAgent::Food);
	return *(reinterpret_cast<float*>(pc));
}

struct PROPERTY_TYPE_CPerformanceAgent_HP { };
template<> BEHAVIAC_FORCEINLINE float& CPerformanceAgent::_Get_Property_<PROPERTY_TYPE_CPerformanceAgent_HP>()
{
	unsigned char* pc = (unsigned char*)this;
	pc += (int)offsetof(CPerformanceAgent, CPerformanceAgent::HP);
	return *(reinterpret_cast<float*>(pc));
}

struct PROPERTY_TYPE_CPerformanceAgent_Hungry { };
template<> BEHAVIAC_FORCEINLINE float& CPerformanceAgent::_Get_Property_<PROPERTY_TYPE_CPerformanceAgent_Hungry>()
{
	unsigned char* pc = (unsigned char*)this;
	pc += (int)offsetof(CPerformanceAgent, CPerformanceAgent::Hungry);
	return *(reinterpret_cast<float*>(pc));
}

struct METHOD_TYPE_CPerformanceAgent_Eat { };
template<> BEHAVIAC_FORCEINLINE behaviac::EBTStatus CPerformanceAgent::_Execute_Method_<METHOD_TYPE_CPerformanceAgent_Eat>()
{
	return this->CPerformanceAgent::Eat();
}

struct METHOD_TYPE_CPerformanceAgent_Fidget { };
template<> BEHAVIAC_FORCEINLINE behaviac::EBTStatus CPerformanceAgent::_Execute_Method_<METHOD_TYPE_CPerformanceAgent_Fidget>()
{
	return this->CPerformanceAgent::Fidget();
}

struct METHOD_TYPE_CPerformanceAgent_Fire { };
template<> BEHAVIAC_FORCEINLINE void CPerformanceAgent::_Execute_Method_<METHOD_TYPE_CPerformanceAgent_Fire>()
{
	this->CPerformanceAgent::Fire();
}

struct METHOD_TYPE_CPerformanceAgent_RunAway { };
template<> BEHAVIAC_FORCEINLINE behaviac::EBTStatus CPerformanceAgent::_Execute_Method_<METHOD_TYPE_CPerformanceAgent_RunAway>()
{
	return this->CPerformanceAgent::RunAway();
}

struct METHOD_TYPE_CPerformanceAgent_SearchForFood { };
template<> BEHAVIAC_FORCEINLINE behaviac::EBTStatus CPerformanceAgent::_Execute_Method_<METHOD_TYPE_CPerformanceAgent_SearchForFood>()
{
	return this->CPerformanceAgent::SearchForFood();
}

struct METHOD_TYPE_CPerformanceAgent_Wander { };
template<> BEHAVIAC_FORCEINLINE behaviac::EBTStatus CPerformanceAgent::_Execute_Method_<METHOD_TYPE_CPerformanceAgent_Wander>()
{
	return this->CPerformanceAgent::Wander();
}

namespace behaviac
{
	// Source file: performance/Performance

	class BEHAVIAC_API DecoratorLoop_bt_performance_Performance_node1 : public DecoratorLoop
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorLoop_bt_performance_Performance_node1, DecoratorLoop);
		DecoratorLoop_bt_performance_Performance_node1()
		{
			m_bDecorateWhenChildEnds = true;
		}
	protected:
		virtual int GetCount(Agent* pAgent) const
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			return 10;
		}
	};

	class BEHAVIAC_API Condition_bt_performance_Performance_node5 : public Condition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Condition_bt_performance_Performance_node5, Condition);
		Condition_bt_performance_Performance_node5()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			float& opl = ((CPerformanceAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_CPerformanceAgent_DistanceToEnemy, float >();
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par_SmallDisance") == 4142645218u);
			float& opr = (float&)pAgent->GetVariable<float >(4142645218u);
			bool op = Details::LessEqual(opl, opr);
			return op ? BT_SUCCESS : BT_FAILURE;
		}
	};

	class BEHAVIAC_API Condition_bt_performance_Performance_node6 : public Condition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Condition_bt_performance_Performance_node6, Condition);
		Condition_bt_performance_Performance_node6()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			float& opl = ((CPerformanceAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_CPerformanceAgent_HP, float >();
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par_HealthThreshold") == 1146605254u);
			float& opr = (float&)pAgent->GetVariable<float >(1146605254u);
			bool op = Details::LessEqual(opl, opr);
			return op ? BT_SUCCESS : BT_FAILURE;
		}
	};

	class BEHAVIAC_API Action_bt_performance_Performance_node7 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_performance_Performance_node7, Action);
		Action_bt_performance_Performance_node7()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			behaviac::EBTStatus result = ((CPerformanceAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_CPerformanceAgent_RunAway, behaviac::EBTStatus >();
			return result;
		}
	};

	class BEHAVIAC_API Predicate_bt_performance_Performance_attach8 : public Predicate
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Predicate_bt_performance_Performance_attach8, Predicate);
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_FAILURE;
			this->m_bAnd = true;
			float& opl = ((CPerformanceAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_CPerformanceAgent_DistanceToEnemy, float >();
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par_BigDistance") == 1778440178u);
			float& opr = (float&)pAgent->GetVariable<float >(1778440178u);
			bool op = Details::Greater(opl, opr);
			if (op)
				result = BT_SUCCESS;
			return result;
		}
	};

	class BEHAVIAC_API Action_bt_performance_Performance_node19 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_performance_Performance_node19, Action);
		Action_bt_performance_Performance_node19()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((CPerformanceAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_CPerformanceAgent_Fire, void >();
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Parallel_bt_performance_Performance_node22 : public Parallel
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Parallel_bt_performance_Performance_node22, Parallel);
		Parallel_bt_performance_Performance_node22()
		{
			m_failPolicy = FAIL_ON_ONE;
			m_succeedPolicy = SUCCEED_ON_ALL;
			m_exitPolicy = EXIT_ABORT_RUNNINGSIBLINGS;
			m_childFinishPolicy = CHILDFINISH_LOOP;
		}
	protected:
	};

	class BEHAVIAC_API Condition_bt_performance_Performance_node16 : public Condition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Condition_bt_performance_Performance_node16, Condition);
		Condition_bt_performance_Performance_node16()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			float& opl = ((CPerformanceAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_CPerformanceAgent_DistanceToEnemy, float >();
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par_SmallDisance") == 4142645218u);
			float& opr = (float&)pAgent->GetVariable<float >(4142645218u);
			bool op = Details::Greater(opl, opr);
			return op ? BT_SUCCESS : BT_FAILURE;
		}
	};

	class BEHAVIAC_API Condition_bt_performance_Performance_node9 : public Condition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Condition_bt_performance_Performance_node9, Condition);
		Condition_bt_performance_Performance_node9()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			float& opl = ((CPerformanceAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_CPerformanceAgent_Hungry, float >();
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par_HungryThreshold") == 825091127u);
			float& opr = (float&)pAgent->GetVariable<float >(825091127u);
			bool op = Details::GreaterEqual(opl, opr);
			return op ? BT_SUCCESS : BT_FAILURE;
		}
	};

	class BEHAVIAC_API Condition_bt_performance_Performance_node13 : public Condition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Condition_bt_performance_Performance_node13, Condition);
		Condition_bt_performance_Performance_node13()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			float& opl = ((CPerformanceAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_CPerformanceAgent_Food, float >();
			float opr = 0;
			bool op = Details::Equal(opl, opr);
			return op ? BT_SUCCESS : BT_FAILURE;
		}
	};

	class BEHAVIAC_API Action_bt_performance_Performance_node14 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_performance_Performance_node14, Action);
		Action_bt_performance_Performance_node14()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			behaviac::EBTStatus result = ((CPerformanceAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_CPerformanceAgent_SearchForFood, behaviac::EBTStatus >();
			return result;
		}
	};

	class BEHAVIAC_API Action_bt_performance_Performance_node15 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_performance_Performance_node15, Action);
		Action_bt_performance_Performance_node15()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			behaviac::EBTStatus result = ((CPerformanceAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_CPerformanceAgent_Eat, behaviac::EBTStatus >();
			return result;
		}
	};

	class BEHAVIAC_API Parallel_bt_performance_Performance_node20 : public Parallel
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Parallel_bt_performance_Performance_node20, Parallel);
		Parallel_bt_performance_Performance_node20()
		{
			m_failPolicy = FAIL_ON_ONE;
			m_succeedPolicy = SUCCEED_ON_ALL;
			m_exitPolicy = EXIT_ABORT_RUNNINGSIBLINGS;
			m_childFinishPolicy = CHILDFINISH_LOOP;
		}
	protected:
	};

	class BEHAVIAC_API Condition_bt_performance_Performance_node3 : public Condition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Condition_bt_performance_Performance_node3, Condition);
		Condition_bt_performance_Performance_node3()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			float& opl = ((CPerformanceAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_CPerformanceAgent_DistanceToEnemy, float >();
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par_SmallDisance") == 4142645218u);
			float& opr = (float&)pAgent->GetVariable<float >(4142645218u);
			bool op = Details::Greater(opl, opr);
			return op ? BT_SUCCESS : BT_FAILURE;
		}
	};

	class BEHAVIAC_API Action_bt_performance_Performance_node18 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_performance_Performance_node18, Action);
		Action_bt_performance_Performance_node18()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			behaviac::EBTStatus result = ((CPerformanceAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_CPerformanceAgent_Wander, behaviac::EBTStatus >();
			return result;
		}
	};

	class BEHAVIAC_API Action_bt_performance_Performance_node4 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_performance_Performance_node4, Action);
		Action_bt_performance_Performance_node4()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			behaviac::EBTStatus result = ((CPerformanceAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_CPerformanceAgent_Fidget, behaviac::EBTStatus >();
			return result;
		}
	};

	BEHAVIAC_API bool Create_bt_performance_Performance(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("performance/Performance");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("CPerformanceAgent");
#endif
		// pars
		pBT->AddPar("float", "par_HungryThreshold", "60", "");
		pBT->AddPar("float", "par_BigDistance", "30", "");
		pBT->AddPar("float", "par_SmallDisance", "10", "");
		pBT->AddPar("float", "par_HealthThreshold", "20", "");
		// children
		{
			DecoratorLoop_bt_performance_Performance_node1* node1 = BEHAVIAC_NEW DecoratorLoop_bt_performance_Performance_node1;
			node1->SetClassNameString("DecoratorLoop");
			node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
			node1->SetAgentType("CPerformanceAgent");
#endif
			pBT->AddChild(node1);
			{
				Selector* node21 = BEHAVIAC_NEW Selector;
				node21->SetClassNameString("Selector");
				node21->SetId(21);
#if !defined(BEHAVIAC_RELEASE)
				node21->SetAgentType("CPerformanceAgent");
#endif
				node1->AddChild(node21);
				{
					Sequence* node0 = BEHAVIAC_NEW Sequence;
					node0->SetClassNameString("Sequence");
					node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
					node0->SetAgentType("CPerformanceAgent");
#endif
					node21->AddChild(node0);
					{
						Condition_bt_performance_Performance_node5* node5 = BEHAVIAC_NEW Condition_bt_performance_Performance_node5;
						node5->SetClassNameString("Condition");
						node5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
						node5->SetAgentType("CPerformanceAgent");
#endif
						node0->AddChild(node5);
						node0->SetHasEvents(node0->HasEvents() | node5->HasEvents());
					}
					{
						Selector* node11 = BEHAVIAC_NEW Selector;
						node11->SetClassNameString("Selector");
						node11->SetId(11);
#if !defined(BEHAVIAC_RELEASE)
						node11->SetAgentType("CPerformanceAgent");
#endif
						node0->AddChild(node11);
						{
							Sequence* node2 = BEHAVIAC_NEW Sequence;
							node2->SetClassNameString("Sequence");
							node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
							node2->SetAgentType("CPerformanceAgent");
#endif
							node11->AddChild(node2);
							{
								Condition_bt_performance_Performance_node6* node6 = BEHAVIAC_NEW Condition_bt_performance_Performance_node6;
								node6->SetClassNameString("Condition");
								node6->SetId(6);
#if !defined(BEHAVIAC_RELEASE)
								node6->SetAgentType("CPerformanceAgent");
#endif
								node2->AddChild(node6);
								node2->SetHasEvents(node2->HasEvents() | node6->HasEvents());
							}
							{
								Action_bt_performance_Performance_node7* node7 = BEHAVIAC_NEW Action_bt_performance_Performance_node7;
								node7->SetClassNameString("Action");
								node7->SetId(7);
#if !defined(BEHAVIAC_RELEASE)
								node7->SetAgentType("CPerformanceAgent");
#endif
								// attachments
								{
									Predicate_bt_performance_Performance_attach8* attach8 = BEHAVIAC_NEW Predicate_bt_performance_Performance_attach8;
									attach8->SetClassNameString("Predicate");
									attach8->SetId(8);
#if !defined(BEHAVIAC_RELEASE)
									attach8->SetAgentType("CPerformanceAgent");
#endif
									node7->Attach(attach8);
									node7->SetHasEvents(node7->HasEvents() | (Event::DynamicCast(attach8) != 0));
								}
								node2->AddChild(node7);
								node2->SetHasEvents(node2->HasEvents() | node7->HasEvents());
							}
							node11->SetHasEvents(node11->HasEvents() | node2->HasEvents());
						}
						{
							Action_bt_performance_Performance_node19* node19 = BEHAVIAC_NEW Action_bt_performance_Performance_node19;
							node19->SetClassNameString("Action");
							node19->SetId(19);
#if !defined(BEHAVIAC_RELEASE)
							node19->SetAgentType("CPerformanceAgent");
#endif
							node11->AddChild(node19);
							node11->SetHasEvents(node11->HasEvents() | node19->HasEvents());
						}
						node0->SetHasEvents(node0->HasEvents() | node11->HasEvents());
					}
					node21->SetHasEvents(node21->HasEvents() | node0->HasEvents());
				}
				{
					Parallel_bt_performance_Performance_node22* node22 = BEHAVIAC_NEW Parallel_bt_performance_Performance_node22;
					node22->SetClassNameString("Parallel");
					node22->SetId(22);
#if !defined(BEHAVIAC_RELEASE)
					node22->SetAgentType("CPerformanceAgent");
#endif
					node21->AddChild(node22);
					{
						Condition_bt_performance_Performance_node16* node16 = BEHAVIAC_NEW Condition_bt_performance_Performance_node16;
						node16->SetClassNameString("Condition");
						node16->SetId(16);
#if !defined(BEHAVIAC_RELEASE)
						node16->SetAgentType("CPerformanceAgent");
#endif
						node22->AddChild(node16);
						node22->SetHasEvents(node22->HasEvents() | node16->HasEvents());
					}
					{
						Sequence* node23 = BEHAVIAC_NEW Sequence;
						node23->SetClassNameString("Sequence");
						node23->SetId(23);
#if !defined(BEHAVIAC_RELEASE)
						node23->SetAgentType("CPerformanceAgent");
#endif
						node22->AddChild(node23);
						{
							Condition_bt_performance_Performance_node9* node9 = BEHAVIAC_NEW Condition_bt_performance_Performance_node9;
							node9->SetClassNameString("Condition");
							node9->SetId(9);
#if !defined(BEHAVIAC_RELEASE)
							node9->SetAgentType("CPerformanceAgent");
#endif
							node23->AddChild(node9);
							node23->SetHasEvents(node23->HasEvents() | node9->HasEvents());
						}
						{
							Selector* node10 = BEHAVIAC_NEW Selector;
							node10->SetClassNameString("Selector");
							node10->SetId(10);
#if !defined(BEHAVIAC_RELEASE)
							node10->SetAgentType("CPerformanceAgent");
#endif
							node23->AddChild(node10);
							{
								Sequence* node12 = BEHAVIAC_NEW Sequence;
								node12->SetClassNameString("Sequence");
								node12->SetId(12);
#if !defined(BEHAVIAC_RELEASE)
								node12->SetAgentType("CPerformanceAgent");
#endif
								node10->AddChild(node12);
								{
									Condition_bt_performance_Performance_node13* node13 = BEHAVIAC_NEW Condition_bt_performance_Performance_node13;
									node13->SetClassNameString("Condition");
									node13->SetId(13);
#if !defined(BEHAVIAC_RELEASE)
									node13->SetAgentType("CPerformanceAgent");
#endif
									node12->AddChild(node13);
									node12->SetHasEvents(node12->HasEvents() | node13->HasEvents());
								}
								{
									Action_bt_performance_Performance_node14* node14 = BEHAVIAC_NEW Action_bt_performance_Performance_node14;
									node14->SetClassNameString("Action");
									node14->SetId(14);
#if !defined(BEHAVIAC_RELEASE)
									node14->SetAgentType("CPerformanceAgent");
#endif
									node12->AddChild(node14);
									node12->SetHasEvents(node12->HasEvents() | node14->HasEvents());
								}
								node10->SetHasEvents(node10->HasEvents() | node12->HasEvents());
							}
							{
								Action_bt_performance_Performance_node15* node15 = BEHAVIAC_NEW Action_bt_performance_Performance_node15;
								node15->SetClassNameString("Action");
								node15->SetId(15);
#if !defined(BEHAVIAC_RELEASE)
								node15->SetAgentType("CPerformanceAgent");
#endif
								node10->AddChild(node15);
								node10->SetHasEvents(node10->HasEvents() | node15->HasEvents());
							}
							node23->SetHasEvents(node23->HasEvents() | node10->HasEvents());
						}
						node22->SetHasEvents(node22->HasEvents() | node23->HasEvents());
					}
					node21->SetHasEvents(node21->HasEvents() | node22->HasEvents());
				}
				{
					Parallel_bt_performance_Performance_node20* node20 = BEHAVIAC_NEW Parallel_bt_performance_Performance_node20;
					node20->SetClassNameString("Parallel");
					node20->SetId(20);
#if !defined(BEHAVIAC_RELEASE)
					node20->SetAgentType("CPerformanceAgent");
#endif
					node21->AddChild(node20);
					{
						Condition_bt_performance_Performance_node3* node3 = BEHAVIAC_NEW Condition_bt_performance_Performance_node3;
						node3->SetClassNameString("Condition");
						node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
						node3->SetAgentType("CPerformanceAgent");
#endif
						node20->AddChild(node3);
						node20->SetHasEvents(node20->HasEvents() | node3->HasEvents());
					}
					{
						Sequence* node17 = BEHAVIAC_NEW Sequence;
						node17->SetClassNameString("Sequence");
						node17->SetId(17);
#if !defined(BEHAVIAC_RELEASE)
						node17->SetAgentType("CPerformanceAgent");
#endif
						node20->AddChild(node17);
						{
							Action_bt_performance_Performance_node18* node18 = BEHAVIAC_NEW Action_bt_performance_Performance_node18;
							node18->SetClassNameString("Action");
							node18->SetId(18);
#if !defined(BEHAVIAC_RELEASE)
							node18->SetAgentType("CPerformanceAgent");
#endif
							node17->AddChild(node18);
							node17->SetHasEvents(node17->HasEvents() | node18->HasEvents());
						}
						{
							Action_bt_performance_Performance_node4* node4 = BEHAVIAC_NEW Action_bt_performance_Performance_node4;
							node4->SetClassNameString("Action");
							node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
							node4->SetAgentType("CPerformanceAgent");
#endif
							node17->AddChild(node4);
							node17->SetHasEvents(node17->HasEvents() | node4->HasEvents());
						}
						node20->SetHasEvents(node20->HasEvents() | node17->HasEvents());
					}
					node21->SetHasEvents(node21->HasEvents() | node20->HasEvents());
				}
				node1->SetHasEvents(node1->HasEvents() | node21->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node1->HasEvents());
		}
		return true;
	}

	struct Register_bt_performance_Performance
	{
		Register_bt_performance_Performance()
		{
			Workspace::RegisterBehaviorTreeCreator("performance/Performance", Create_bt_performance_Performance);
		}
	};

	static Register_bt_performance_Performance register_bt_performance_Performance;

}
