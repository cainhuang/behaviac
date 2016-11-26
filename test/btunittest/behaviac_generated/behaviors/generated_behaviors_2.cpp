#include "generated_behaviors_2.h"

namespace behaviac
{
	// Source file: node_test/circular_ut_0

	class Condition_bt_node_test_circular_ut_0_node5 : public Condition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Condition_bt_node_test_circular_ut_0_node5, Condition);
		Condition_bt_node_test_circular_ut_0_node5()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, int >();
			int opr = 0;
			bool op = Details::Equal(opl, opr);
			return op ? BT_SUCCESS : BT_FAILURE;
		}
	};

	class Assignment_bt_node_test_circular_ut_0_node3 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_node_test_circular_ut_0_node3, Assignment);
		Assignment_bt_node_test_circular_ut_0_node3()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			int opr = 1;
			((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, int >() = opr;
			return result;
		}
	};

	class ReferencedBehavior_bt_node_test_circular_ut_0_node6 : public ReferencedBehavior
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(ReferencedBehavior_bt_node_test_circular_ut_0_node6, ReferencedBehavior);
		ReferencedBehavior_bt_node_test_circular_ut_0_node6()
		{
			const char* szTreePath = this->GetReferencedTree(0);
			if (szTreePath) {
			BehaviorTree* behaviorTree = Workspace::GetInstance()->LoadBehaviorTree(szTreePath);
			BEHAVIAC_ASSERT(behaviorTree);
			if (behaviorTree)
			{
				this->m_bHasEvents |= behaviorTree->HasEvents();
			}
			}
		}
	protected:
		virtual const char* GetReferencedTree(const Agent* pAgent) const
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			return (char*)("node_test/circular_ut_0");
		}
	};

	class Compute_bt_node_test_circular_ut_0_node1 : public Compute
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Compute_bt_node_test_circular_ut_0_node1, Compute);
		Compute_bt_node_test_circular_ut_0_node1()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			int opr1 = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_1, int >();
			int opr2 = 1;
			((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_1, int >() = (int)(opr1 + opr2);
			return result;
		}
	};

		bool bt_node_test_circular_ut_0::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("node_test/circular_ut_0");
			pBT->SetIsFSM(false);
#if !BEHAVIAC_RELEASE
			pBT->SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Selector* node0 = BEHAVIAC_NEW Selector;
				node0->SetClassNameString("Selector");
				node0->SetId(0);
#if !BEHAVIAC_RELEASE
				node0->SetAgentType("AgentNodeTest");
#endif
				pBT->AddChild(node0);
				{
					Sequence* node2 = BEHAVIAC_NEW Sequence;
					node2->SetClassNameString("Sequence");
					node2->SetId(2);
#if !BEHAVIAC_RELEASE
					node2->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node2);
					{
						Condition_bt_node_test_circular_ut_0_node5* node5 = BEHAVIAC_NEW Condition_bt_node_test_circular_ut_0_node5;
						node5->SetClassNameString("Condition");
						node5->SetId(5);
#if !BEHAVIAC_RELEASE
						node5->SetAgentType("AgentNodeTest");
#endif
						node2->AddChild(node5);
						node2->SetHasEvents(node2->HasEvents() | node5->HasEvents());
					}
					{
						Sequence* node4 = BEHAVIAC_NEW Sequence;
						node4->SetClassNameString("Sequence");
						node4->SetId(4);
#if !BEHAVIAC_RELEASE
						node4->SetAgentType("AgentNodeTest");
#endif
						node2->AddChild(node4);
						{
							Assignment_bt_node_test_circular_ut_0_node3* node3 = BEHAVIAC_NEW Assignment_bt_node_test_circular_ut_0_node3;
							node3->SetClassNameString("Assignment");
							node3->SetId(3);
#if !BEHAVIAC_RELEASE
							node3->SetAgentType("AgentNodeTest");
#endif
							node4->AddChild(node3);
							node4->SetHasEvents(node4->HasEvents() | node3->HasEvents());
						}
						{
							ReferencedBehavior_bt_node_test_circular_ut_0_node6* node6 = BEHAVIAC_NEW ReferencedBehavior_bt_node_test_circular_ut_0_node6;
							node6->SetClassNameString("ReferencedBehavior");
							node6->SetId(6);
#if !BEHAVIAC_RELEASE
							node6->SetAgentType("AgentNodeTest");
#endif
							node4->AddChild(node6);
							node4->SetHasEvents(node4->HasEvents() | node6->HasEvents());
						}
						node2->SetHasEvents(node2->HasEvents() | node4->HasEvents());
					}
					node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
				}
				{
					Compute_bt_node_test_circular_ut_0_node1* node1 = BEHAVIAC_NEW Compute_bt_node_test_circular_ut_0_node1;
					node1->SetClassNameString("Compute");
					node1->SetId(1);
#if !BEHAVIAC_RELEASE
					node1->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node1);
					node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
				}
				pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
			}
			return true;
		}

	// Source file: node_test/condition_ut_0

	class Condition_bt_node_test_condition_ut_0_node1 : public Condition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Condition_bt_node_test_condition_ut_0_node1, Condition);
		Condition_bt_node_test_condition_ut_0_node1()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, int >();
			int opr = -1;
			bool op = Details::Equal(opl, opr);
			return op ? BT_SUCCESS : BT_FAILURE;
		}
	};

	class Action_bt_node_test_condition_ut_0_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_condition_ut_0_node2, Action);
		Action_bt_node_test_condition_ut_0_node2()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, int >(method_p0);
			return BT_SUCCESS;
		}
		int method_p0;
	};

	class Condition_bt_node_test_condition_ut_0_node3 : public Condition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Condition_bt_node_test_condition_ut_0_node3, Condition);
		Condition_bt_node_test_condition_ut_0_node3()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, int >();
			int opr = ((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_getConstOne, int >();
			bool op = Details::Equal(opl, opr);
			return op ? BT_SUCCESS : BT_FAILURE;
		}
	};

	class Action_bt_node_test_condition_ut_0_node4 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_condition_ut_0_node4, Action);
		Action_bt_node_test_condition_ut_0_node4()
		{
			method_p0 = 2;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, int >(method_p0);
			return BT_SUCCESS;
		}
		int method_p0;
	};

		bool bt_node_test_condition_ut_0::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("node_test/condition_ut_0");
			pBT->SetIsFSM(false);
#if !BEHAVIAC_RELEASE
			pBT->SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Sequence* node0 = BEHAVIAC_NEW Sequence;
				node0->SetClassNameString("Sequence");
				node0->SetId(0);
#if !BEHAVIAC_RELEASE
				node0->SetAgentType("AgentNodeTest");
#endif
				pBT->AddChild(node0);
				{
					Condition_bt_node_test_condition_ut_0_node1* node1 = BEHAVIAC_NEW Condition_bt_node_test_condition_ut_0_node1;
					node1->SetClassNameString("Condition");
					node1->SetId(1);
#if !BEHAVIAC_RELEASE
					node1->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node1);
					node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
				}
				{
					Action_bt_node_test_condition_ut_0_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_condition_ut_0_node2;
					node2->SetClassNameString("Action");
					node2->SetId(2);
#if !BEHAVIAC_RELEASE
					node2->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node2);
					node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
				}
				{
					Condition_bt_node_test_condition_ut_0_node3* node3 = BEHAVIAC_NEW Condition_bt_node_test_condition_ut_0_node3;
					node3->SetClassNameString("Condition");
					node3->SetId(3);
#if !BEHAVIAC_RELEASE
					node3->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node3);
					node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
				}
				{
					Action_bt_node_test_condition_ut_0_node4* node4 = BEHAVIAC_NEW Action_bt_node_test_condition_ut_0_node4;
					node4->SetClassNameString("Action");
					node4->SetId(4);
#if !BEHAVIAC_RELEASE
					node4->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node4);
					node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
				}
				pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
			}
			return true;
		}

	// Source file: node_test/condition_ut_1

	class Condition_bt_node_test_condition_ut_1_node10 : public Condition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Condition_bt_node_test_condition_ut_1_node10, Condition);
		Condition_bt_node_test_condition_ut_1_node10()
		{
			opr = NULL;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par_agent") == 239606442u);
			ParTestAgent*& opl = (ParTestAgent*&)pAgent->GetVariable<ParTestAgent* >(239606442u);
			bool op = Details::Equal(opl, opr);
			return op ? BT_SUCCESS : BT_FAILURE;
		}
		ParTestAgent* opr;
	};

	class Action_bt_node_test_condition_ut_1_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_condition_ut_1_node2, Action);
		Action_bt_node_test_condition_ut_1_node2()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, int >(method_p0);
			return BT_SUCCESS;
		}
		int method_p0;
	};

	class Action_bt_node_test_condition_ut_1_node8 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_condition_ut_1_node8, Action);
		Action_bt_node_test_condition_ut_1_node8()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, int >(method_p0);
			return BT_SUCCESS;
		}
		int method_p0;
	};

		bool bt_node_test_condition_ut_1::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("node_test/condition_ut_1");
			pBT->SetIsFSM(false);
#if !BEHAVIAC_RELEASE
			pBT->SetAgentType("AgentNodeTest");
#endif
			// pars
			pBT->AddPar("AgentNodeTest", "ParTestAgent", "par_agent", "null");
			// children
			{
				Sequence* node0 = BEHAVIAC_NEW Sequence;
				node0->SetClassNameString("Sequence");
				node0->SetId(0);
#if !BEHAVIAC_RELEASE
				node0->SetAgentType("AgentNodeTest");
#endif
				pBT->AddChild(node0);
				{
					Or* node9 = BEHAVIAC_NEW Or;
					node9->SetClassNameString("Or");
					node9->SetId(9);
#if !BEHAVIAC_RELEASE
					node9->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node9);
					{
						Condition_bt_node_test_condition_ut_1_node10* node10 = BEHAVIAC_NEW Condition_bt_node_test_condition_ut_1_node10;
						node10->SetClassNameString("Condition");
						node10->SetId(10);
#if !BEHAVIAC_RELEASE
						node10->SetAgentType("AgentNodeTest");
#endif
						node9->AddChild(node10);
						node9->SetHasEvents(node9->HasEvents() | node10->HasEvents());
					}
					{
						True* node11 = BEHAVIAC_NEW True;
						node11->SetClassNameString("True");
						node11->SetId(11);
#if !BEHAVIAC_RELEASE
						node11->SetAgentType("AgentNodeTest");
#endif
						node9->AddChild(node11);
						node9->SetHasEvents(node9->HasEvents() | node11->HasEvents());
					}
					node0->SetHasEvents(node0->HasEvents() | node9->HasEvents());
				}
				{
					Or* node1 = BEHAVIAC_NEW Or;
					node1->SetClassNameString("Or");
					node1->SetId(1);
#if !BEHAVIAC_RELEASE
					node1->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node1);
					{
						True* node3 = BEHAVIAC_NEW True;
						node3->SetClassNameString("True");
						node3->SetId(3);
#if !BEHAVIAC_RELEASE
						node3->SetAgentType("AgentNodeTest");
#endif
						node1->AddChild(node3);
						node1->SetHasEvents(node1->HasEvents() | node3->HasEvents());
					}
					{
						False* node5 = BEHAVIAC_NEW False;
						node5->SetClassNameString("False");
						node5->SetId(5);
#if !BEHAVIAC_RELEASE
						node5->SetAgentType("AgentNodeTest");
#endif
						node1->AddChild(node5);
						node1->SetHasEvents(node1->HasEvents() | node5->HasEvents());
					}
					node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
				}
				{
					Action_bt_node_test_condition_ut_1_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_condition_ut_1_node2;
					node2->SetClassNameString("Action");
					node2->SetId(2);
#if !BEHAVIAC_RELEASE
					node2->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node2);
					node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
				}
				{
					Or* node4 = BEHAVIAC_NEW Or;
					node4->SetClassNameString("Or");
					node4->SetId(4);
#if !BEHAVIAC_RELEASE
					node4->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node4);
					{
						False* node6 = BEHAVIAC_NEW False;
						node6->SetClassNameString("False");
						node6->SetId(6);
#if !BEHAVIAC_RELEASE
						node6->SetAgentType("AgentNodeTest");
#endif
						node4->AddChild(node6);
						node4->SetHasEvents(node4->HasEvents() | node6->HasEvents());
					}
					{
						False* node7 = BEHAVIAC_NEW False;
						node7->SetClassNameString("False");
						node7->SetId(7);
#if !BEHAVIAC_RELEASE
						node7->SetAgentType("AgentNodeTest");
#endif
						node4->AddChild(node7);
						node4->SetHasEvents(node4->HasEvents() | node7->HasEvents());
					}
					node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
				}
				{
					Action_bt_node_test_condition_ut_1_node8* node8 = BEHAVIAC_NEW Action_bt_node_test_condition_ut_1_node8;
					node8->SetClassNameString("Action");
					node8->SetId(8);
#if !BEHAVIAC_RELEASE
					node8->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node8);
					node0->SetHasEvents(node0->HasEvents() | node8->HasEvents());
				}
				pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
			}
			return true;
		}

	// Source file: node_test/condition_ut_2

	class Action_bt_node_test_condition_ut_2_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_condition_ut_2_node2, Action);
		Action_bt_node_test_condition_ut_2_node2()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, int >(method_p0);
			return BT_SUCCESS;
		}
		int method_p0;
	};

	class Action_bt_node_test_condition_ut_2_node8 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_condition_ut_2_node8, Action);
		Action_bt_node_test_condition_ut_2_node8()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, int >(method_p0);
			return BT_SUCCESS;
		}
		int method_p0;
	};

	class Action_bt_node_test_condition_ut_2_node12 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_condition_ut_2_node12, Action);
		Action_bt_node_test_condition_ut_2_node12()
		{
			method_p0 = 2;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, int >(method_p0);
			return BT_SUCCESS;
		}
		int method_p0;
	};

		bool bt_node_test_condition_ut_2::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("node_test/condition_ut_2");
			pBT->SetIsFSM(false);
#if !BEHAVIAC_RELEASE
			pBT->SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Sequence* node0 = BEHAVIAC_NEW Sequence;
				node0->SetClassNameString("Sequence");
				node0->SetId(0);
#if !BEHAVIAC_RELEASE
				node0->SetAgentType("AgentNodeTest");
#endif
				pBT->AddChild(node0);
				{
					And* node9 = BEHAVIAC_NEW And;
					node9->SetClassNameString("And");
					node9->SetId(9);
#if !BEHAVIAC_RELEASE
					node9->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node9);
					{
						True* node10 = BEHAVIAC_NEW True;
						node10->SetClassNameString("True");
						node10->SetId(10);
#if !BEHAVIAC_RELEASE
						node10->SetAgentType("AgentNodeTest");
#endif
						node9->AddChild(node10);
						node9->SetHasEvents(node9->HasEvents() | node10->HasEvents());
					}
					{
						True* node11 = BEHAVIAC_NEW True;
						node11->SetClassNameString("True");
						node11->SetId(11);
#if !BEHAVIAC_RELEASE
						node11->SetAgentType("AgentNodeTest");
#endif
						node9->AddChild(node11);
						node9->SetHasEvents(node9->HasEvents() | node11->HasEvents());
					}
					node0->SetHasEvents(node0->HasEvents() | node9->HasEvents());
				}
				{
					Action_bt_node_test_condition_ut_2_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_condition_ut_2_node2;
					node2->SetClassNameString("Action");
					node2->SetId(2);
#if !BEHAVIAC_RELEASE
					node2->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node2);
					node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
				}
				{
					And* node1 = BEHAVIAC_NEW And;
					node1->SetClassNameString("And");
					node1->SetId(1);
#if !BEHAVIAC_RELEASE
					node1->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node1);
					{
						True* node3 = BEHAVIAC_NEW True;
						node3->SetClassNameString("True");
						node3->SetId(3);
#if !BEHAVIAC_RELEASE
						node3->SetAgentType("AgentNodeTest");
#endif
						node1->AddChild(node3);
						node1->SetHasEvents(node1->HasEvents() | node3->HasEvents());
					}
					{
						False* node5 = BEHAVIAC_NEW False;
						node5->SetClassNameString("False");
						node5->SetId(5);
#if !BEHAVIAC_RELEASE
						node5->SetAgentType("AgentNodeTest");
#endif
						node1->AddChild(node5);
						node1->SetHasEvents(node1->HasEvents() | node5->HasEvents());
					}
					node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
				}
				{
					Action_bt_node_test_condition_ut_2_node8* node8 = BEHAVIAC_NEW Action_bt_node_test_condition_ut_2_node8;
					node8->SetClassNameString("Action");
					node8->SetId(8);
#if !BEHAVIAC_RELEASE
					node8->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node8);
					node0->SetHasEvents(node0->HasEvents() | node8->HasEvents());
				}
				{
					And* node4 = BEHAVIAC_NEW And;
					node4->SetClassNameString("And");
					node4->SetId(4);
#if !BEHAVIAC_RELEASE
					node4->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node4);
					{
						False* node6 = BEHAVIAC_NEW False;
						node6->SetClassNameString("False");
						node6->SetId(6);
#if !BEHAVIAC_RELEASE
						node6->SetAgentType("AgentNodeTest");
#endif
						node4->AddChild(node6);
						node4->SetHasEvents(node4->HasEvents() | node6->HasEvents());
					}
					{
						False* node7 = BEHAVIAC_NEW False;
						node7->SetClassNameString("False");
						node7->SetId(7);
#if !BEHAVIAC_RELEASE
						node7->SetAgentType("AgentNodeTest");
#endif
						node4->AddChild(node7);
						node4->SetHasEvents(node4->HasEvents() | node7->HasEvents());
					}
					node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
				}
				{
					Action_bt_node_test_condition_ut_2_node12* node12 = BEHAVIAC_NEW Action_bt_node_test_condition_ut_2_node12;
					node12->SetClassNameString("Action");
					node12->SetId(12);
#if !BEHAVIAC_RELEASE
					node12->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node12);
					node0->SetHasEvents(node0->HasEvents() | node12->HasEvents());
				}
				pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
			}
			return true;
		}

	// Source file: node_test/condition_ut_3

	class Action_bt_node_test_condition_ut_3_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_condition_ut_3_node2, Action);
		Action_bt_node_test_condition_ut_3_node2()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, int >(method_p0);
			return BT_SUCCESS;
		}
		int method_p0;
	};

	class Action_bt_node_test_condition_ut_3_node8 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_condition_ut_3_node8, Action);
		Action_bt_node_test_condition_ut_3_node8()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, int >(method_p0);
			return BT_SUCCESS;
		}
		int method_p0;
	};

	class Action_bt_node_test_condition_ut_3_node12 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_condition_ut_3_node12, Action);
		Action_bt_node_test_condition_ut_3_node12()
		{
			method_p0 = 2;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, int >(method_p0);
			return BT_SUCCESS;
		}
		int method_p0;
	};

		bool bt_node_test_condition_ut_3::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("node_test/condition_ut_3");
			pBT->SetIsFSM(false);
#if !BEHAVIAC_RELEASE
			pBT->SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Sequence* node0 = BEHAVIAC_NEW Sequence;
				node0->SetClassNameString("Sequence");
				node0->SetId(0);
#if !BEHAVIAC_RELEASE
				node0->SetAgentType("AgentNodeTest");
#endif
				pBT->AddChild(node0);
				{
					And* node9 = BEHAVIAC_NEW And;
					node9->SetClassNameString("And");
					node9->SetId(9);
#if !BEHAVIAC_RELEASE
					node9->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node9);
					{
						Or* node13 = BEHAVIAC_NEW Or;
						node13->SetClassNameString("Or");
						node13->SetId(13);
#if !BEHAVIAC_RELEASE
						node13->SetAgentType("AgentNodeTest");
#endif
						node9->AddChild(node13);
						{
							True* node10 = BEHAVIAC_NEW True;
							node10->SetClassNameString("True");
							node10->SetId(10);
#if !BEHAVIAC_RELEASE
							node10->SetAgentType("AgentNodeTest");
#endif
							node13->AddChild(node10);
							node13->SetHasEvents(node13->HasEvents() | node10->HasEvents());
						}
						{
							False* node14 = BEHAVIAC_NEW False;
							node14->SetClassNameString("False");
							node14->SetId(14);
#if !BEHAVIAC_RELEASE
							node14->SetAgentType("AgentNodeTest");
#endif
							node13->AddChild(node14);
							node13->SetHasEvents(node13->HasEvents() | node14->HasEvents());
						}
						node9->SetHasEvents(node9->HasEvents() | node13->HasEvents());
					}
					{
						True* node11 = BEHAVIAC_NEW True;
						node11->SetClassNameString("True");
						node11->SetId(11);
#if !BEHAVIAC_RELEASE
						node11->SetAgentType("AgentNodeTest");
#endif
						node9->AddChild(node11);
						node9->SetHasEvents(node9->HasEvents() | node11->HasEvents());
					}
					node0->SetHasEvents(node0->HasEvents() | node9->HasEvents());
				}
				{
					Action_bt_node_test_condition_ut_3_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_condition_ut_3_node2;
					node2->SetClassNameString("Action");
					node2->SetId(2);
#if !BEHAVIAC_RELEASE
					node2->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node2);
					node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
				}
				{
					Or* node1 = BEHAVIAC_NEW Or;
					node1->SetClassNameString("Or");
					node1->SetId(1);
#if !BEHAVIAC_RELEASE
					node1->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node1);
					{
						And* node15 = BEHAVIAC_NEW And;
						node15->SetClassNameString("And");
						node15->SetId(15);
#if !BEHAVIAC_RELEASE
						node15->SetAgentType("AgentNodeTest");
#endif
						node1->AddChild(node15);
						{
							True* node3 = BEHAVIAC_NEW True;
							node3->SetClassNameString("True");
							node3->SetId(3);
#if !BEHAVIAC_RELEASE
							node3->SetAgentType("AgentNodeTest");
#endif
							node15->AddChild(node3);
							node15->SetHasEvents(node15->HasEvents() | node3->HasEvents());
						}
						{
							True* node16 = BEHAVIAC_NEW True;
							node16->SetClassNameString("True");
							node16->SetId(16);
#if !BEHAVIAC_RELEASE
							node16->SetAgentType("AgentNodeTest");
#endif
							node15->AddChild(node16);
							node15->SetHasEvents(node15->HasEvents() | node16->HasEvents());
						}
						node1->SetHasEvents(node1->HasEvents() | node15->HasEvents());
					}
					{
						False* node5 = BEHAVIAC_NEW False;
						node5->SetClassNameString("False");
						node5->SetId(5);
#if !BEHAVIAC_RELEASE
						node5->SetAgentType("AgentNodeTest");
#endif
						node1->AddChild(node5);
						node1->SetHasEvents(node1->HasEvents() | node5->HasEvents());
					}
					node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
				}
				{
					Action_bt_node_test_condition_ut_3_node8* node8 = BEHAVIAC_NEW Action_bt_node_test_condition_ut_3_node8;
					node8->SetClassNameString("Action");
					node8->SetId(8);
#if !BEHAVIAC_RELEASE
					node8->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node8);
					node0->SetHasEvents(node0->HasEvents() | node8->HasEvents());
				}
				{
					And* node4 = BEHAVIAC_NEW And;
					node4->SetClassNameString("And");
					node4->SetId(4);
#if !BEHAVIAC_RELEASE
					node4->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node4);
					{
						Or* node18 = BEHAVIAC_NEW Or;
						node18->SetClassNameString("Or");
						node18->SetId(18);
#if !BEHAVIAC_RELEASE
						node18->SetAgentType("AgentNodeTest");
#endif
						node4->AddChild(node18);
						{
							Or* node19 = BEHAVIAC_NEW Or;
							node19->SetClassNameString("Or");
							node19->SetId(19);
#if !BEHAVIAC_RELEASE
							node19->SetAgentType("AgentNodeTest");
#endif
							node18->AddChild(node19);
							{
								False* node6 = BEHAVIAC_NEW False;
								node6->SetClassNameString("False");
								node6->SetId(6);
#if !BEHAVIAC_RELEASE
								node6->SetAgentType("AgentNodeTest");
#endif
								node19->AddChild(node6);
								node19->SetHasEvents(node19->HasEvents() | node6->HasEvents());
							}
							{
								True* node21 = BEHAVIAC_NEW True;
								node21->SetClassNameString("True");
								node21->SetId(21);
#if !BEHAVIAC_RELEASE
								node21->SetAgentType("AgentNodeTest");
#endif
								node19->AddChild(node21);
								node19->SetHasEvents(node19->HasEvents() | node21->HasEvents());
							}
							node18->SetHasEvents(node18->HasEvents() | node19->HasEvents());
						}
						{
							False* node22 = BEHAVIAC_NEW False;
							node22->SetClassNameString("False");
							node22->SetId(22);
#if !BEHAVIAC_RELEASE
							node22->SetAgentType("AgentNodeTest");
#endif
							node18->AddChild(node22);
							node18->SetHasEvents(node18->HasEvents() | node22->HasEvents());
						}
						node4->SetHasEvents(node4->HasEvents() | node18->HasEvents());
					}
					{
						And* node17 = BEHAVIAC_NEW And;
						node17->SetClassNameString("And");
						node17->SetId(17);
#if !BEHAVIAC_RELEASE
						node17->SetAgentType("AgentNodeTest");
#endif
						node4->AddChild(node17);
						{
							True* node7 = BEHAVIAC_NEW True;
							node7->SetClassNameString("True");
							node7->SetId(7);
#if !BEHAVIAC_RELEASE
							node7->SetAgentType("AgentNodeTest");
#endif
							node17->AddChild(node7);
							node17->SetHasEvents(node17->HasEvents() | node7->HasEvents());
						}
						{
							And* node20 = BEHAVIAC_NEW And;
							node20->SetClassNameString("And");
							node20->SetId(20);
#if !BEHAVIAC_RELEASE
							node20->SetAgentType("AgentNodeTest");
#endif
							node17->AddChild(node20);
							{
								True* node23 = BEHAVIAC_NEW True;
								node23->SetClassNameString("True");
								node23->SetId(23);
#if !BEHAVIAC_RELEASE
								node23->SetAgentType("AgentNodeTest");
#endif
								node20->AddChild(node23);
								node20->SetHasEvents(node20->HasEvents() | node23->HasEvents());
							}
							{
								True* node24 = BEHAVIAC_NEW True;
								node24->SetClassNameString("True");
								node24->SetId(24);
#if !BEHAVIAC_RELEASE
								node24->SetAgentType("AgentNodeTest");
#endif
								node20->AddChild(node24);
								node20->SetHasEvents(node20->HasEvents() | node24->HasEvents());
							}
							node17->SetHasEvents(node17->HasEvents() | node20->HasEvents());
						}
						node4->SetHasEvents(node4->HasEvents() | node17->HasEvents());
					}
					node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
				}
				{
					Action_bt_node_test_condition_ut_3_node12* node12 = BEHAVIAC_NEW Action_bt_node_test_condition_ut_3_node12;
					node12->SetClassNameString("Action");
					node12->SetId(12);
#if !BEHAVIAC_RELEASE
					node12->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node12);
					node0->SetHasEvents(node0->HasEvents() | node12->HasEvents());
				}
				pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
			}
			return true;
		}

	// Source file: node_test/decoration_alwaysfailure_ut_0

	class DecoratorAlwaysFailure_bt_node_test_decoration_alwaysfailure_ut_0_node1 : public DecoratorAlwaysFailure
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorAlwaysFailure_bt_node_test_decoration_alwaysfailure_ut_0_node1, DecoratorAlwaysFailure);
		DecoratorAlwaysFailure_bt_node_test_decoration_alwaysfailure_ut_0_node1()
		{
			m_bDecorateWhenChildEnds = false;
		}
	protected:
	};

	class Action_bt_node_test_decoration_alwaysfailure_ut_0_node5 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_alwaysfailure_ut_0_node5, Action);
		Action_bt_node_test_decoration_alwaysfailure_ut_0_node5()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, int >(method_p0);
			return BT_SUCCESS;
		}
		int method_p0;
	};

	class Action_bt_node_test_decoration_alwaysfailure_ut_0_node6 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_alwaysfailure_ut_0_node6, Action);
		Action_bt_node_test_decoration_alwaysfailure_ut_0_node6()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, int >(method_p0);
			return BT_SUCCESS;
		}
		int method_p0;
	};

	class DecoratorAlwaysFailure_bt_node_test_decoration_alwaysfailure_ut_0_node3 : public DecoratorAlwaysFailure
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorAlwaysFailure_bt_node_test_decoration_alwaysfailure_ut_0_node3, DecoratorAlwaysFailure);
		DecoratorAlwaysFailure_bt_node_test_decoration_alwaysfailure_ut_0_node3()
		{
			m_bDecorateWhenChildEnds = false;
		}
	protected:
	};

	class Action_bt_node_test_decoration_alwaysfailure_ut_0_node7 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_alwaysfailure_ut_0_node7, Action);
		Action_bt_node_test_decoration_alwaysfailure_ut_0_node7()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_1, void, int >(method_p0);
			return BT_FAILURE;
		}
		int method_p0;
	};

	class Action_bt_node_test_decoration_alwaysfailure_ut_0_node8 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_alwaysfailure_ut_0_node8, Action);
		Action_bt_node_test_decoration_alwaysfailure_ut_0_node8()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_1, void, int >(method_p0);
			return BT_SUCCESS;
		}
		int method_p0;
	};

	class DecoratorAlwaysFailure_bt_node_test_decoration_alwaysfailure_ut_0_node10 : public DecoratorAlwaysFailure
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorAlwaysFailure_bt_node_test_decoration_alwaysfailure_ut_0_node10, DecoratorAlwaysFailure);
		DecoratorAlwaysFailure_bt_node_test_decoration_alwaysfailure_ut_0_node10()
		{
			m_bDecorateWhenChildEnds = false;
		}
	protected:
	};

	class Action_bt_node_test_decoration_alwaysfailure_ut_0_node11 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_alwaysfailure_ut_0_node11, Action);
		Action_bt_node_test_decoration_alwaysfailure_ut_0_node11()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_2, void, float >(method_p0);
			return BT_RUNNING;
		}
		float method_p0;
	};

	class Action_bt_node_test_decoration_alwaysfailure_ut_0_node12 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_alwaysfailure_ut_0_node12, Action);
		Action_bt_node_test_decoration_alwaysfailure_ut_0_node12()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_2, void, float >(method_p0);
			return BT_SUCCESS;
		}
		float method_p0;
	};

		bool bt_node_test_decoration_alwaysfailure_ut_0::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("node_test/decoration_alwaysfailure_ut_0");
			pBT->SetIsFSM(false);
#if !BEHAVIAC_RELEASE
			pBT->SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Sequence* node0 = BEHAVIAC_NEW Sequence;
				node0->SetClassNameString("Sequence");
				node0->SetId(0);
#if !BEHAVIAC_RELEASE
				node0->SetAgentType("AgentNodeTest");
#endif
				pBT->AddChild(node0);
				{
					Selector* node4 = BEHAVIAC_NEW Selector;
					node4->SetClassNameString("Selector");
					node4->SetId(4);
#if !BEHAVIAC_RELEASE
					node4->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node4);
					{
						DecoratorAlwaysFailure_bt_node_test_decoration_alwaysfailure_ut_0_node1* node1 = BEHAVIAC_NEW DecoratorAlwaysFailure_bt_node_test_decoration_alwaysfailure_ut_0_node1;
						node1->SetClassNameString("DecoratorAlwaysFailure");
						node1->SetId(1);
#if !BEHAVIAC_RELEASE
						node1->SetAgentType("AgentNodeTest");
#endif
						node4->AddChild(node1);
						{
							Action_bt_node_test_decoration_alwaysfailure_ut_0_node5* node5 = BEHAVIAC_NEW Action_bt_node_test_decoration_alwaysfailure_ut_0_node5;
							node5->SetClassNameString("Action");
							node5->SetId(5);
#if !BEHAVIAC_RELEASE
							node5->SetAgentType("AgentNodeTest");
#endif
							node1->AddChild(node5);
							node1->SetHasEvents(node1->HasEvents() | node5->HasEvents());
						}
						node4->SetHasEvents(node4->HasEvents() | node1->HasEvents());
					}
					{
						Action_bt_node_test_decoration_alwaysfailure_ut_0_node6* node6 = BEHAVIAC_NEW Action_bt_node_test_decoration_alwaysfailure_ut_0_node6;
						node6->SetClassNameString("Action");
						node6->SetId(6);
#if !BEHAVIAC_RELEASE
						node6->SetAgentType("AgentNodeTest");
#endif
						node4->AddChild(node6);
						node4->SetHasEvents(node4->HasEvents() | node6->HasEvents());
					}
					node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
				}
				{
					Selector* node2 = BEHAVIAC_NEW Selector;
					node2->SetClassNameString("Selector");
					node2->SetId(2);
#if !BEHAVIAC_RELEASE
					node2->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node2);
					{
						DecoratorAlwaysFailure_bt_node_test_decoration_alwaysfailure_ut_0_node3* node3 = BEHAVIAC_NEW DecoratorAlwaysFailure_bt_node_test_decoration_alwaysfailure_ut_0_node3;
						node3->SetClassNameString("DecoratorAlwaysFailure");
						node3->SetId(3);
#if !BEHAVIAC_RELEASE
						node3->SetAgentType("AgentNodeTest");
#endif
						node2->AddChild(node3);
						{
							Action_bt_node_test_decoration_alwaysfailure_ut_0_node7* node7 = BEHAVIAC_NEW Action_bt_node_test_decoration_alwaysfailure_ut_0_node7;
							node7->SetClassNameString("Action");
							node7->SetId(7);
#if !BEHAVIAC_RELEASE
							node7->SetAgentType("AgentNodeTest");
#endif
							node3->AddChild(node7);
							node3->SetHasEvents(node3->HasEvents() | node7->HasEvents());
						}
						node2->SetHasEvents(node2->HasEvents() | node3->HasEvents());
					}
					{
						Action_bt_node_test_decoration_alwaysfailure_ut_0_node8* node8 = BEHAVIAC_NEW Action_bt_node_test_decoration_alwaysfailure_ut_0_node8;
						node8->SetClassNameString("Action");
						node8->SetId(8);
#if !BEHAVIAC_RELEASE
						node8->SetAgentType("AgentNodeTest");
#endif
						node2->AddChild(node8);
						node2->SetHasEvents(node2->HasEvents() | node8->HasEvents());
					}
					node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
				}
				{
					Selector* node9 = BEHAVIAC_NEW Selector;
					node9->SetClassNameString("Selector");
					node9->SetId(9);
#if !BEHAVIAC_RELEASE
					node9->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node9);
					{
						DecoratorAlwaysFailure_bt_node_test_decoration_alwaysfailure_ut_0_node10* node10 = BEHAVIAC_NEW DecoratorAlwaysFailure_bt_node_test_decoration_alwaysfailure_ut_0_node10;
						node10->SetClassNameString("DecoratorAlwaysFailure");
						node10->SetId(10);
#if !BEHAVIAC_RELEASE
						node10->SetAgentType("AgentNodeTest");
#endif
						node9->AddChild(node10);
						{
							Action_bt_node_test_decoration_alwaysfailure_ut_0_node11* node11 = BEHAVIAC_NEW Action_bt_node_test_decoration_alwaysfailure_ut_0_node11;
							node11->SetClassNameString("Action");
							node11->SetId(11);
#if !BEHAVIAC_RELEASE
							node11->SetAgentType("AgentNodeTest");
#endif
							node10->AddChild(node11);
							node10->SetHasEvents(node10->HasEvents() | node11->HasEvents());
						}
						node9->SetHasEvents(node9->HasEvents() | node10->HasEvents());
					}
					{
						Action_bt_node_test_decoration_alwaysfailure_ut_0_node12* node12 = BEHAVIAC_NEW Action_bt_node_test_decoration_alwaysfailure_ut_0_node12;
						node12->SetClassNameString("Action");
						node12->SetId(12);
#if !BEHAVIAC_RELEASE
						node12->SetAgentType("AgentNodeTest");
#endif
						node9->AddChild(node12);
						node9->SetHasEvents(node9->HasEvents() | node12->HasEvents());
					}
					node0->SetHasEvents(node0->HasEvents() | node9->HasEvents());
				}
				pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
			}
			return true;
		}

	// Source file: node_test/decoration_alwaysrunning_ut_0

	class Parallel_bt_node_test_decoration_alwaysrunning_ut_0_node0 : public Parallel
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Parallel_bt_node_test_decoration_alwaysrunning_ut_0_node0, Parallel);
		Parallel_bt_node_test_decoration_alwaysrunning_ut_0_node0()
		{
			m_failPolicy = FAIL_ON_ONE;
			m_succeedPolicy = SUCCEED_ON_ALL;
			m_exitPolicy = EXIT_ABORT_RUNNINGSIBLINGS;
			m_childFinishPolicy = CHILDFINISH_LOOP;
		}
	protected:
	};

	class DecoratorAlwaysRunning_bt_node_test_decoration_alwaysrunning_ut_0_node1 : public DecoratorAlwaysRunning
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorAlwaysRunning_bt_node_test_decoration_alwaysrunning_ut_0_node1, DecoratorAlwaysRunning);
		DecoratorAlwaysRunning_bt_node_test_decoration_alwaysrunning_ut_0_node1()
		{
			m_bDecorateWhenChildEnds = false;
		}
	protected:
	};

	class Action_bt_node_test_decoration_alwaysrunning_ut_0_node5 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_alwaysrunning_ut_0_node5, Action);
		Action_bt_node_test_decoration_alwaysrunning_ut_0_node5()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, int >(method_p0);
			return BT_SUCCESS;
		}
		int method_p0;
	};

	class Action_bt_node_test_decoration_alwaysrunning_ut_0_node6 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_alwaysrunning_ut_0_node6, Action);
		Action_bt_node_test_decoration_alwaysrunning_ut_0_node6()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, int >(method_p0);
			return BT_SUCCESS;
		}
		int method_p0;
	};

	class DecoratorAlwaysRunning_bt_node_test_decoration_alwaysrunning_ut_0_node3 : public DecoratorAlwaysRunning
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorAlwaysRunning_bt_node_test_decoration_alwaysrunning_ut_0_node3, DecoratorAlwaysRunning);
		DecoratorAlwaysRunning_bt_node_test_decoration_alwaysrunning_ut_0_node3()
		{
			m_bDecorateWhenChildEnds = false;
		}
	protected:
	};

	class Action_bt_node_test_decoration_alwaysrunning_ut_0_node7 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_alwaysrunning_ut_0_node7, Action);
		Action_bt_node_test_decoration_alwaysrunning_ut_0_node7()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_1, void, int >(method_p0);
			return BT_FAILURE;
		}
		int method_p0;
	};

	class Action_bt_node_test_decoration_alwaysrunning_ut_0_node8 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_alwaysrunning_ut_0_node8, Action);
		Action_bt_node_test_decoration_alwaysrunning_ut_0_node8()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_1, void, int >(method_p0);
			return BT_SUCCESS;
		}
		int method_p0;
	};

	class DecoratorAlwaysRunning_bt_node_test_decoration_alwaysrunning_ut_0_node10 : public DecoratorAlwaysRunning
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorAlwaysRunning_bt_node_test_decoration_alwaysrunning_ut_0_node10, DecoratorAlwaysRunning);
		DecoratorAlwaysRunning_bt_node_test_decoration_alwaysrunning_ut_0_node10()
		{
			m_bDecorateWhenChildEnds = false;
		}
	protected:
	};

	class Action_bt_node_test_decoration_alwaysrunning_ut_0_node11 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_alwaysrunning_ut_0_node11, Action);
		Action_bt_node_test_decoration_alwaysrunning_ut_0_node11()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_2, void, float >(method_p0);
			return BT_RUNNING;
		}
		float method_p0;
	};

	class Action_bt_node_test_decoration_alwaysrunning_ut_0_node12 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_alwaysrunning_ut_0_node12, Action);
		Action_bt_node_test_decoration_alwaysrunning_ut_0_node12()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_2, void, float >(method_p0);
			return BT_SUCCESS;
		}
		float method_p0;
	};

		bool bt_node_test_decoration_alwaysrunning_ut_0::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("node_test/decoration_alwaysrunning_ut_0");
			pBT->SetIsFSM(false);
#if !BEHAVIAC_RELEASE
			pBT->SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Parallel_bt_node_test_decoration_alwaysrunning_ut_0_node0* node0 = BEHAVIAC_NEW Parallel_bt_node_test_decoration_alwaysrunning_ut_0_node0;
				node0->SetClassNameString("Parallel");
				node0->SetId(0);
#if !BEHAVIAC_RELEASE
				node0->SetAgentType("AgentNodeTest");
#endif
				pBT->AddChild(node0);
				{
					Selector* node4 = BEHAVIAC_NEW Selector;
					node4->SetClassNameString("Selector");
					node4->SetId(4);
#if !BEHAVIAC_RELEASE
					node4->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node4);
					{
						DecoratorAlwaysRunning_bt_node_test_decoration_alwaysrunning_ut_0_node1* node1 = BEHAVIAC_NEW DecoratorAlwaysRunning_bt_node_test_decoration_alwaysrunning_ut_0_node1;
						node1->SetClassNameString("DecoratorAlwaysRunning");
						node1->SetId(1);
#if !BEHAVIAC_RELEASE
						node1->SetAgentType("AgentNodeTest");
#endif
						node4->AddChild(node1);
						{
							Action_bt_node_test_decoration_alwaysrunning_ut_0_node5* node5 = BEHAVIAC_NEW Action_bt_node_test_decoration_alwaysrunning_ut_0_node5;
							node5->SetClassNameString("Action");
							node5->SetId(5);
#if !BEHAVIAC_RELEASE
							node5->SetAgentType("AgentNodeTest");
#endif
							node1->AddChild(node5);
							node1->SetHasEvents(node1->HasEvents() | node5->HasEvents());
						}
						node4->SetHasEvents(node4->HasEvents() | node1->HasEvents());
					}
					{
						Action_bt_node_test_decoration_alwaysrunning_ut_0_node6* node6 = BEHAVIAC_NEW Action_bt_node_test_decoration_alwaysrunning_ut_0_node6;
						node6->SetClassNameString("Action");
						node6->SetId(6);
#if !BEHAVIAC_RELEASE
						node6->SetAgentType("AgentNodeTest");
#endif
						node4->AddChild(node6);
						node4->SetHasEvents(node4->HasEvents() | node6->HasEvents());
					}
					node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
				}
				{
					Selector* node2 = BEHAVIAC_NEW Selector;
					node2->SetClassNameString("Selector");
					node2->SetId(2);
#if !BEHAVIAC_RELEASE
					node2->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node2);
					{
						DecoratorAlwaysRunning_bt_node_test_decoration_alwaysrunning_ut_0_node3* node3 = BEHAVIAC_NEW DecoratorAlwaysRunning_bt_node_test_decoration_alwaysrunning_ut_0_node3;
						node3->SetClassNameString("DecoratorAlwaysRunning");
						node3->SetId(3);
#if !BEHAVIAC_RELEASE
						node3->SetAgentType("AgentNodeTest");
#endif
						node2->AddChild(node3);
						{
							Action_bt_node_test_decoration_alwaysrunning_ut_0_node7* node7 = BEHAVIAC_NEW Action_bt_node_test_decoration_alwaysrunning_ut_0_node7;
							node7->SetClassNameString("Action");
							node7->SetId(7);
#if !BEHAVIAC_RELEASE
							node7->SetAgentType("AgentNodeTest");
#endif
							node3->AddChild(node7);
							node3->SetHasEvents(node3->HasEvents() | node7->HasEvents());
						}
						node2->SetHasEvents(node2->HasEvents() | node3->HasEvents());
					}
					{
						Action_bt_node_test_decoration_alwaysrunning_ut_0_node8* node8 = BEHAVIAC_NEW Action_bt_node_test_decoration_alwaysrunning_ut_0_node8;
						node8->SetClassNameString("Action");
						node8->SetId(8);
#if !BEHAVIAC_RELEASE
						node8->SetAgentType("AgentNodeTest");
#endif
						node2->AddChild(node8);
						node2->SetHasEvents(node2->HasEvents() | node8->HasEvents());
					}
					node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
				}
				{
					Selector* node9 = BEHAVIAC_NEW Selector;
					node9->SetClassNameString("Selector");
					node9->SetId(9);
#if !BEHAVIAC_RELEASE
					node9->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node9);
					{
						DecoratorAlwaysRunning_bt_node_test_decoration_alwaysrunning_ut_0_node10* node10 = BEHAVIAC_NEW DecoratorAlwaysRunning_bt_node_test_decoration_alwaysrunning_ut_0_node10;
						node10->SetClassNameString("DecoratorAlwaysRunning");
						node10->SetId(10);
#if !BEHAVIAC_RELEASE
						node10->SetAgentType("AgentNodeTest");
#endif
						node9->AddChild(node10);
						{
							Action_bt_node_test_decoration_alwaysrunning_ut_0_node11* node11 = BEHAVIAC_NEW Action_bt_node_test_decoration_alwaysrunning_ut_0_node11;
							node11->SetClassNameString("Action");
							node11->SetId(11);
#if !BEHAVIAC_RELEASE
							node11->SetAgentType("AgentNodeTest");
#endif
							node10->AddChild(node11);
							node10->SetHasEvents(node10->HasEvents() | node11->HasEvents());
						}
						node9->SetHasEvents(node9->HasEvents() | node10->HasEvents());
					}
					{
						Action_bt_node_test_decoration_alwaysrunning_ut_0_node12* node12 = BEHAVIAC_NEW Action_bt_node_test_decoration_alwaysrunning_ut_0_node12;
						node12->SetClassNameString("Action");
						node12->SetId(12);
#if !BEHAVIAC_RELEASE
						node12->SetAgentType("AgentNodeTest");
#endif
						node9->AddChild(node12);
						node9->SetHasEvents(node9->HasEvents() | node12->HasEvents());
					}
					node0->SetHasEvents(node0->HasEvents() | node9->HasEvents());
				}
				pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
			}
			return true;
		}

	// Source file: node_test/decoration_alwayssuccess_ut_0

	class DecoratorAlwaysSuccess_bt_node_test_decoration_alwayssuccess_ut_0_node1 : public DecoratorAlwaysSuccess
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorAlwaysSuccess_bt_node_test_decoration_alwayssuccess_ut_0_node1, DecoratorAlwaysSuccess);
		DecoratorAlwaysSuccess_bt_node_test_decoration_alwayssuccess_ut_0_node1()
		{
			m_bDecorateWhenChildEnds = false;
		}
	protected:
	};

	class Action_bt_node_test_decoration_alwayssuccess_ut_0_node5 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_alwayssuccess_ut_0_node5, Action);
		Action_bt_node_test_decoration_alwayssuccess_ut_0_node5()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, int >(method_p0);
			return BT_SUCCESS;
		}
		int method_p0;
	};

	class Action_bt_node_test_decoration_alwayssuccess_ut_0_node6 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_alwayssuccess_ut_0_node6, Action);
		Action_bt_node_test_decoration_alwayssuccess_ut_0_node6()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, int >(method_p0);
			return BT_SUCCESS;
		}
		int method_p0;
	};

	class DecoratorAlwaysSuccess_bt_node_test_decoration_alwayssuccess_ut_0_node3 : public DecoratorAlwaysSuccess
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorAlwaysSuccess_bt_node_test_decoration_alwayssuccess_ut_0_node3, DecoratorAlwaysSuccess);
		DecoratorAlwaysSuccess_bt_node_test_decoration_alwayssuccess_ut_0_node3()
		{
			m_bDecorateWhenChildEnds = false;
		}
	protected:
	};

	class Action_bt_node_test_decoration_alwayssuccess_ut_0_node7 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_alwayssuccess_ut_0_node7, Action);
		Action_bt_node_test_decoration_alwayssuccess_ut_0_node7()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_1, void, int >(method_p0);
			return BT_FAILURE;
		}
		int method_p0;
	};

	class Action_bt_node_test_decoration_alwayssuccess_ut_0_node8 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_alwayssuccess_ut_0_node8, Action);
		Action_bt_node_test_decoration_alwayssuccess_ut_0_node8()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_1, void, int >(method_p0);
			return BT_SUCCESS;
		}
		int method_p0;
	};

	class DecoratorAlwaysSuccess_bt_node_test_decoration_alwayssuccess_ut_0_node10 : public DecoratorAlwaysSuccess
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorAlwaysSuccess_bt_node_test_decoration_alwayssuccess_ut_0_node10, DecoratorAlwaysSuccess);
		DecoratorAlwaysSuccess_bt_node_test_decoration_alwayssuccess_ut_0_node10()
		{
			m_bDecorateWhenChildEnds = false;
		}
	protected:
	};

	class Action_bt_node_test_decoration_alwayssuccess_ut_0_node11 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_alwayssuccess_ut_0_node11, Action);
		Action_bt_node_test_decoration_alwayssuccess_ut_0_node11()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_2, void, float >(method_p0);
			return BT_RUNNING;
		}
		float method_p0;
	};

	class Action_bt_node_test_decoration_alwayssuccess_ut_0_node12 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_alwayssuccess_ut_0_node12, Action);
		Action_bt_node_test_decoration_alwayssuccess_ut_0_node12()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_2, void, float >(method_p0);
			return BT_SUCCESS;
		}
		float method_p0;
	};

		bool bt_node_test_decoration_alwayssuccess_ut_0::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("node_test/decoration_alwayssuccess_ut_0");
			pBT->SetIsFSM(false);
#if !BEHAVIAC_RELEASE
			pBT->SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Sequence* node0 = BEHAVIAC_NEW Sequence;
				node0->SetClassNameString("Sequence");
				node0->SetId(0);
#if !BEHAVIAC_RELEASE
				node0->SetAgentType("AgentNodeTest");
#endif
				pBT->AddChild(node0);
				{
					Selector* node4 = BEHAVIAC_NEW Selector;
					node4->SetClassNameString("Selector");
					node4->SetId(4);
#if !BEHAVIAC_RELEASE
					node4->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node4);
					{
						DecoratorAlwaysSuccess_bt_node_test_decoration_alwayssuccess_ut_0_node1* node1 = BEHAVIAC_NEW DecoratorAlwaysSuccess_bt_node_test_decoration_alwayssuccess_ut_0_node1;
						node1->SetClassNameString("DecoratorAlwaysSuccess");
						node1->SetId(1);
#if !BEHAVIAC_RELEASE
						node1->SetAgentType("AgentNodeTest");
#endif
						node4->AddChild(node1);
						{
							Action_bt_node_test_decoration_alwayssuccess_ut_0_node5* node5 = BEHAVIAC_NEW Action_bt_node_test_decoration_alwayssuccess_ut_0_node5;
							node5->SetClassNameString("Action");
							node5->SetId(5);
#if !BEHAVIAC_RELEASE
							node5->SetAgentType("AgentNodeTest");
#endif
							node1->AddChild(node5);
							node1->SetHasEvents(node1->HasEvents() | node5->HasEvents());
						}
						node4->SetHasEvents(node4->HasEvents() | node1->HasEvents());
					}
					{
						Action_bt_node_test_decoration_alwayssuccess_ut_0_node6* node6 = BEHAVIAC_NEW Action_bt_node_test_decoration_alwayssuccess_ut_0_node6;
						node6->SetClassNameString("Action");
						node6->SetId(6);
#if !BEHAVIAC_RELEASE
						node6->SetAgentType("AgentNodeTest");
#endif
						node4->AddChild(node6);
						node4->SetHasEvents(node4->HasEvents() | node6->HasEvents());
					}
					node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
				}
				{
					Selector* node2 = BEHAVIAC_NEW Selector;
					node2->SetClassNameString("Selector");
					node2->SetId(2);
#if !BEHAVIAC_RELEASE
					node2->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node2);
					{
						DecoratorAlwaysSuccess_bt_node_test_decoration_alwayssuccess_ut_0_node3* node3 = BEHAVIAC_NEW DecoratorAlwaysSuccess_bt_node_test_decoration_alwayssuccess_ut_0_node3;
						node3->SetClassNameString("DecoratorAlwaysSuccess");
						node3->SetId(3);
#if !BEHAVIAC_RELEASE
						node3->SetAgentType("AgentNodeTest");
#endif
						node2->AddChild(node3);
						{
							Action_bt_node_test_decoration_alwayssuccess_ut_0_node7* node7 = BEHAVIAC_NEW Action_bt_node_test_decoration_alwayssuccess_ut_0_node7;
							node7->SetClassNameString("Action");
							node7->SetId(7);
#if !BEHAVIAC_RELEASE
							node7->SetAgentType("AgentNodeTest");
#endif
							node3->AddChild(node7);
							node3->SetHasEvents(node3->HasEvents() | node7->HasEvents());
						}
						node2->SetHasEvents(node2->HasEvents() | node3->HasEvents());
					}
					{
						Action_bt_node_test_decoration_alwayssuccess_ut_0_node8* node8 = BEHAVIAC_NEW Action_bt_node_test_decoration_alwayssuccess_ut_0_node8;
						node8->SetClassNameString("Action");
						node8->SetId(8);
#if !BEHAVIAC_RELEASE
						node8->SetAgentType("AgentNodeTest");
#endif
						node2->AddChild(node8);
						node2->SetHasEvents(node2->HasEvents() | node8->HasEvents());
					}
					node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
				}
				{
					Selector* node9 = BEHAVIAC_NEW Selector;
					node9->SetClassNameString("Selector");
					node9->SetId(9);
#if !BEHAVIAC_RELEASE
					node9->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node9);
					{
						DecoratorAlwaysSuccess_bt_node_test_decoration_alwayssuccess_ut_0_node10* node10 = BEHAVIAC_NEW DecoratorAlwaysSuccess_bt_node_test_decoration_alwayssuccess_ut_0_node10;
						node10->SetClassNameString("DecoratorAlwaysSuccess");
						node10->SetId(10);
#if !BEHAVIAC_RELEASE
						node10->SetAgentType("AgentNodeTest");
#endif
						node9->AddChild(node10);
						{
							Action_bt_node_test_decoration_alwayssuccess_ut_0_node11* node11 = BEHAVIAC_NEW Action_bt_node_test_decoration_alwayssuccess_ut_0_node11;
							node11->SetClassNameString("Action");
							node11->SetId(11);
#if !BEHAVIAC_RELEASE
							node11->SetAgentType("AgentNodeTest");
#endif
							node10->AddChild(node11);
							node10->SetHasEvents(node10->HasEvents() | node11->HasEvents());
						}
						node9->SetHasEvents(node9->HasEvents() | node10->HasEvents());
					}
					{
						Action_bt_node_test_decoration_alwayssuccess_ut_0_node12* node12 = BEHAVIAC_NEW Action_bt_node_test_decoration_alwayssuccess_ut_0_node12;
						node12->SetClassNameString("Action");
						node12->SetId(12);
#if !BEHAVIAC_RELEASE
						node12->SetAgentType("AgentNodeTest");
#endif
						node9->AddChild(node12);
						node9->SetHasEvents(node9->HasEvents() | node12->HasEvents());
					}
					node0->SetHasEvents(node0->HasEvents() | node9->HasEvents());
				}
				pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
			}
			return true;
		}

	// Source file: node_test/decoration_countlimit_ut_0

	class DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_0_node1 : public DecoratorCountLimit
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_0_node1, DecoratorCountLimit);
		DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_0_node1()
		{
			m_bDecorateWhenChildEnds = true;
		}
	protected:
		virtual int GetCount(Agent* pAgent) const
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			return 5;
		}
	};

	class Action_bt_node_test_decoration_countlimit_ut_0_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_countlimit_ut_0_node2, Action);
		Action_bt_node_test_decoration_countlimit_ut_0_node2()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, int >(method_p0);
			return BT_SUCCESS;
		}
		int method_p0;
	};

	class Action_bt_node_test_decoration_countlimit_ut_0_node3 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_countlimit_ut_0_node3, Action);
		Action_bt_node_test_decoration_countlimit_ut_0_node3()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, int >(method_p0);
			return BT_SUCCESS;
		}
		int method_p0;
	};

		bool bt_node_test_decoration_countlimit_ut_0::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("node_test/decoration_countlimit_ut_0");
			pBT->SetIsFSM(false);
#if !BEHAVIAC_RELEASE
			pBT->SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Selector* node0 = BEHAVIAC_NEW Selector;
				node0->SetClassNameString("Selector");
				node0->SetId(0);
#if !BEHAVIAC_RELEASE
				node0->SetAgentType("AgentNodeTest");
#endif
				pBT->AddChild(node0);
				{
					DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_0_node1* node1 = BEHAVIAC_NEW DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_0_node1;
					node1->SetClassNameString("DecoratorCountLimit");
					node1->SetId(1);
#if !BEHAVIAC_RELEASE
					node1->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node1);
					{
						Action_bt_node_test_decoration_countlimit_ut_0_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_decoration_countlimit_ut_0_node2;
						node2->SetClassNameString("Action");
						node2->SetId(2);
#if !BEHAVIAC_RELEASE
						node2->SetAgentType("AgentNodeTest");
#endif
						node1->AddChild(node2);
						node1->SetHasEvents(node1->HasEvents() | node2->HasEvents());
					}
					node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
				}
				{
					Action_bt_node_test_decoration_countlimit_ut_0_node3* node3 = BEHAVIAC_NEW Action_bt_node_test_decoration_countlimit_ut_0_node3;
					node3->SetClassNameString("Action");
					node3->SetId(3);
#if !BEHAVIAC_RELEASE
					node3->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node3);
					node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
				}
				pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
			}
			return true;
		}

	// Source file: node_test/decoration_countlimit_ut_1

	class DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_1_node1 : public DecoratorCountLimit
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_1_node1, DecoratorCountLimit);
		DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_1_node1()
		{
			m_bDecorateWhenChildEnds = true;
		}
	protected:
		virtual int GetCount(Agent* pAgent) const
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			return 5;
		}
	};

	class Condition_bt_node_test_decoration_countlimit_ut_1_node4 : public Condition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Condition_bt_node_test_decoration_countlimit_ut_1_node4, Condition);
		Condition_bt_node_test_decoration_countlimit_ut_1_node4()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_1, int >();
			int opr = 0;
			bool op = Details::Equal(opl, opr);
			return op ? BT_SUCCESS : BT_FAILURE;
		}
	};

	class Action_bt_node_test_decoration_countlimit_ut_1_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_countlimit_ut_1_node2, Action);
		Action_bt_node_test_decoration_countlimit_ut_1_node2()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, int >(method_p0);
			return BT_SUCCESS;
		}
		int method_p0;
	};

	class Action_bt_node_test_decoration_countlimit_ut_1_node3 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_countlimit_ut_1_node3, Action);
		Action_bt_node_test_decoration_countlimit_ut_1_node3()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, int >(method_p0);
			return BT_SUCCESS;
		}
		int method_p0;
	};

		bool bt_node_test_decoration_countlimit_ut_1::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("node_test/decoration_countlimit_ut_1");
			pBT->SetIsFSM(false);
#if !BEHAVIAC_RELEASE
			pBT->SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Selector* node0 = BEHAVIAC_NEW Selector;
				node0->SetClassNameString("Selector");
				node0->SetId(0);
#if !BEHAVIAC_RELEASE
				node0->SetAgentType("AgentNodeTest");
#endif
				pBT->AddChild(node0);
				{
					DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_1_node1* node1 = BEHAVIAC_NEW DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_1_node1;
					node1->SetClassNameString("DecoratorCountLimit");
					node1->SetId(1);
#if !BEHAVIAC_RELEASE
					node1->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node1);
					{
						Condition_bt_node_test_decoration_countlimit_ut_1_node4* node4 = BEHAVIAC_NEW Condition_bt_node_test_decoration_countlimit_ut_1_node4;
						node4->SetClassNameString("Condition");
						node4->SetId(4);
#if !BEHAVIAC_RELEASE
						node4->SetAgentType("AgentNodeTest");
#endif
						node1->SetCustomCondition(node4);
						node1->SetHasEvents(node1->HasEvents() | node4->HasEvents());
					}
					{
						Action_bt_node_test_decoration_countlimit_ut_1_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_decoration_countlimit_ut_1_node2;
						node2->SetClassNameString("Action");
						node2->SetId(2);
#if !BEHAVIAC_RELEASE
						node2->SetAgentType("AgentNodeTest");
#endif
						node1->AddChild(node2);
						node1->SetHasEvents(node1->HasEvents() | node2->HasEvents());
					}
					node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
				}
				{
					Action_bt_node_test_decoration_countlimit_ut_1_node3* node3 = BEHAVIAC_NEW Action_bt_node_test_decoration_countlimit_ut_1_node3;
					node3->SetClassNameString("Action");
					node3->SetId(3);
#if !BEHAVIAC_RELEASE
					node3->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node3);
					node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
				}
				pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
			}
			return true;
		}

	// Source file: node_test/decoration_countlimit_ut_2

	class DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_2_node1 : public DecoratorCountLimit
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_2_node1, DecoratorCountLimit);
		DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_2_node1()
		{
			m_bDecorateWhenChildEnds = true;
		}
	protected:
		virtual int GetCount(Agent* pAgent) const
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			return 5;
		}
	};

	class Condition_bt_node_test_decoration_countlimit_ut_2_node5 : public Condition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Condition_bt_node_test_decoration_countlimit_ut_2_node5, Condition);
		Condition_bt_node_test_decoration_countlimit_ut_2_node5()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			float& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_2, float >();
			float opr = 0;
			bool op = Details::Equal(opl, opr);
			return op ? BT_SUCCESS : BT_FAILURE;
		}
	};

	class Condition_bt_node_test_decoration_countlimit_ut_2_node6 : public Condition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Condition_bt_node_test_decoration_countlimit_ut_2_node6, Condition);
		Condition_bt_node_test_decoration_countlimit_ut_2_node6()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_1, int >();
			int opr = 0;
			bool op = Details::Equal(opl, opr);
			return op ? BT_SUCCESS : BT_FAILURE;
		}
	};

	class Action_bt_node_test_decoration_countlimit_ut_2_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_countlimit_ut_2_node2, Action);
		Action_bt_node_test_decoration_countlimit_ut_2_node2()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, int >(method_p0);
			return BT_SUCCESS;
		}
		int method_p0;
	};

	class Action_bt_node_test_decoration_countlimit_ut_2_node3 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_countlimit_ut_2_node3, Action);
		Action_bt_node_test_decoration_countlimit_ut_2_node3()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, int >(method_p0);
			return BT_SUCCESS;
		}
		int method_p0;
	};

		bool bt_node_test_decoration_countlimit_ut_2::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("node_test/decoration_countlimit_ut_2");
			pBT->SetIsFSM(false);
#if !BEHAVIAC_RELEASE
			pBT->SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Selector* node0 = BEHAVIAC_NEW Selector;
				node0->SetClassNameString("Selector");
				node0->SetId(0);
#if !BEHAVIAC_RELEASE
				node0->SetAgentType("AgentNodeTest");
#endif
				pBT->AddChild(node0);
				{
					DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_2_node1* node1 = BEHAVIAC_NEW DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_2_node1;
					node1->SetClassNameString("DecoratorCountLimit");
					node1->SetId(1);
#if !BEHAVIAC_RELEASE
					node1->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node1);
					{
						And* node4 = BEHAVIAC_NEW And;
						node4->SetClassNameString("And");
						node4->SetId(4);
#if !BEHAVIAC_RELEASE
						node4->SetAgentType("AgentNodeTest");
#endif
						node1->SetCustomCondition(node4);
						{
							Condition_bt_node_test_decoration_countlimit_ut_2_node5* node5 = BEHAVIAC_NEW Condition_bt_node_test_decoration_countlimit_ut_2_node5;
							node5->SetClassNameString("Condition");
							node5->SetId(5);
#if !BEHAVIAC_RELEASE
							node5->SetAgentType("AgentNodeTest");
#endif
							node4->AddChild(node5);
							node4->SetHasEvents(node4->HasEvents() | node5->HasEvents());
						}
						{
							Condition_bt_node_test_decoration_countlimit_ut_2_node6* node6 = BEHAVIAC_NEW Condition_bt_node_test_decoration_countlimit_ut_2_node6;
							node6->SetClassNameString("Condition");
							node6->SetId(6);
#if !BEHAVIAC_RELEASE
							node6->SetAgentType("AgentNodeTest");
#endif
							node4->AddChild(node6);
							node4->SetHasEvents(node4->HasEvents() | node6->HasEvents());
						}
						node1->SetHasEvents(node1->HasEvents() | node4->HasEvents());
					}
					{
						Action_bt_node_test_decoration_countlimit_ut_2_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_decoration_countlimit_ut_2_node2;
						node2->SetClassNameString("Action");
						node2->SetId(2);
#if !BEHAVIAC_RELEASE
						node2->SetAgentType("AgentNodeTest");
#endif
						node1->AddChild(node2);
						node1->SetHasEvents(node1->HasEvents() | node2->HasEvents());
					}
					node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
				}
				{
					Action_bt_node_test_decoration_countlimit_ut_2_node3* node3 = BEHAVIAC_NEW Action_bt_node_test_decoration_countlimit_ut_2_node3;
					node3->SetClassNameString("Action");
					node3->SetId(3);
#if !BEHAVIAC_RELEASE
					node3->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node3);
					node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
				}
				pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
			}
			return true;
		}

	// Source file: node_test/decoration_countlimit_ut_3

	class DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_3_node1 : public DecoratorCountLimit
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_3_node1, DecoratorCountLimit);
		DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_3_node1()
		{
			m_bDecorateWhenChildEnds = true;
		}
	protected:
		virtual int GetCount(Agent* pAgent) const
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			return 5;
		}
	};

	class Condition_bt_node_test_decoration_countlimit_ut_3_node6 : public Condition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Condition_bt_node_test_decoration_countlimit_ut_3_node6, Condition);
		Condition_bt_node_test_decoration_countlimit_ut_3_node6()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_1, int >();
			int opr = 0;
			bool op = Details::Equal(opl, opr);
			return op ? BT_SUCCESS : BT_FAILURE;
		}
	};

	class Condition_bt_node_test_decoration_countlimit_ut_3_node7 : public Condition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Condition_bt_node_test_decoration_countlimit_ut_3_node7, Condition);
		Condition_bt_node_test_decoration_countlimit_ut_3_node7()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, int >();
			int opr = 0;
			bool op = Details::Equal(opl, opr);
			return op ? BT_SUCCESS : BT_FAILURE;
		}
	};

	class Condition_bt_node_test_decoration_countlimit_ut_3_node8 : public Condition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Condition_bt_node_test_decoration_countlimit_ut_3_node8, Condition);
		Condition_bt_node_test_decoration_countlimit_ut_3_node8()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			float& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_3, float >();
			float opr = 0;
			bool op = Details::Equal(opl, opr);
			return op ? BT_SUCCESS : BT_FAILURE;
		}
	};

	class Action_bt_node_test_decoration_countlimit_ut_3_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_countlimit_ut_3_node2, Action);
		Action_bt_node_test_decoration_countlimit_ut_3_node2()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, int >(method_p0);
			return BT_SUCCESS;
		}
		int method_p0;
	};

	class Action_bt_node_test_decoration_countlimit_ut_3_node3 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_countlimit_ut_3_node3, Action);
		Action_bt_node_test_decoration_countlimit_ut_3_node3()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, int >(method_p0);
			return BT_SUCCESS;
		}
		int method_p0;
	};

		bool bt_node_test_decoration_countlimit_ut_3::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("node_test/decoration_countlimit_ut_3");
			pBT->SetIsFSM(false);
#if !BEHAVIAC_RELEASE
			pBT->SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Selector* node0 = BEHAVIAC_NEW Selector;
				node0->SetClassNameString("Selector");
				node0->SetId(0);
#if !BEHAVIAC_RELEASE
				node0->SetAgentType("AgentNodeTest");
#endif
				pBT->AddChild(node0);
				{
					DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_3_node1* node1 = BEHAVIAC_NEW DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_3_node1;
					node1->SetClassNameString("DecoratorCountLimit");
					node1->SetId(1);
#if !BEHAVIAC_RELEASE
					node1->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node1);
					{
						Or* node4 = BEHAVIAC_NEW Or;
						node4->SetClassNameString("Or");
						node4->SetId(4);
#if !BEHAVIAC_RELEASE
						node4->SetAgentType("AgentNodeTest");
#endif
						node1->SetCustomCondition(node4);
						{
							And* node5 = BEHAVIAC_NEW And;
							node5->SetClassNameString("And");
							node5->SetId(5);
#if !BEHAVIAC_RELEASE
							node5->SetAgentType("AgentNodeTest");
#endif
							node4->AddChild(node5);
							{
								Condition_bt_node_test_decoration_countlimit_ut_3_node6* node6 = BEHAVIAC_NEW Condition_bt_node_test_decoration_countlimit_ut_3_node6;
								node6->SetClassNameString("Condition");
								node6->SetId(6);
#if !BEHAVIAC_RELEASE
								node6->SetAgentType("AgentNodeTest");
#endif
								node5->AddChild(node6);
								node5->SetHasEvents(node5->HasEvents() | node6->HasEvents());
							}
							{
								Condition_bt_node_test_decoration_countlimit_ut_3_node7* node7 = BEHAVIAC_NEW Condition_bt_node_test_decoration_countlimit_ut_3_node7;
								node7->SetClassNameString("Condition");
								node7->SetId(7);
#if !BEHAVIAC_RELEASE
								node7->SetAgentType("AgentNodeTest");
#endif
								node5->AddChild(node7);
								node5->SetHasEvents(node5->HasEvents() | node7->HasEvents());
							}
							node4->SetHasEvents(node4->HasEvents() | node5->HasEvents());
						}
						{
							Condition_bt_node_test_decoration_countlimit_ut_3_node8* node8 = BEHAVIAC_NEW Condition_bt_node_test_decoration_countlimit_ut_3_node8;
							node8->SetClassNameString("Condition");
							node8->SetId(8);
#if !BEHAVIAC_RELEASE
							node8->SetAgentType("AgentNodeTest");
#endif
							node4->AddChild(node8);
							node4->SetHasEvents(node4->HasEvents() | node8->HasEvents());
						}
						node1->SetHasEvents(node1->HasEvents() | node4->HasEvents());
					}
					{
						Action_bt_node_test_decoration_countlimit_ut_3_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_decoration_countlimit_ut_3_node2;
						node2->SetClassNameString("Action");
						node2->SetId(2);
#if !BEHAVIAC_RELEASE
						node2->SetAgentType("AgentNodeTest");
#endif
						node1->AddChild(node2);
						node1->SetHasEvents(node1->HasEvents() | node2->HasEvents());
					}
					node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
				}
				{
					Action_bt_node_test_decoration_countlimit_ut_3_node3* node3 = BEHAVIAC_NEW Action_bt_node_test_decoration_countlimit_ut_3_node3;
					node3->SetClassNameString("Action");
					node3->SetId(3);
#if !BEHAVIAC_RELEASE
					node3->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node3);
					node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
				}
				pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
			}
			return true;
		}

	// Source file: node_test/decoration_failureuntil_ut_0

	class DecoratorFailureUntil_bt_node_test_decoration_failureuntil_ut_0_node0 : public DecoratorFailureUntil
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorFailureUntil_bt_node_test_decoration_failureuntil_ut_0_node0, DecoratorFailureUntil);
		DecoratorFailureUntil_bt_node_test_decoration_failureuntil_ut_0_node0()
		{
			m_bDecorateWhenChildEnds = true;
		}
	protected:
		virtual int GetCount(Agent* pAgent) const
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			return -1;
		}
	};

		bool bt_node_test_decoration_failureuntil_ut_0::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("node_test/decoration_failureuntil_ut_0");
			pBT->SetIsFSM(false);
#if !BEHAVIAC_RELEASE
			pBT->SetAgentType("AgentNodeTest");
#endif
			// children
			{
				DecoratorFailureUntil_bt_node_test_decoration_failureuntil_ut_0_node0* node0 = BEHAVIAC_NEW DecoratorFailureUntil_bt_node_test_decoration_failureuntil_ut_0_node0;
				node0->SetClassNameString("DecoratorFailureUntil");
				node0->SetId(0);
#if !BEHAVIAC_RELEASE
				node0->SetAgentType("AgentNodeTest");
#endif
				pBT->AddChild(node0);
				{
					True* node1 = BEHAVIAC_NEW True;
					node1->SetClassNameString("True");
					node1->SetId(1);
#if !BEHAVIAC_RELEASE
					node1->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node1);
					node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
				}
				pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
			}
			return true;
		}

	// Source file: node_test/decoration_failureuntil_ut_1

	class DecoratorFailureUntil_bt_node_test_decoration_failureuntil_ut_1_node0 : public DecoratorFailureUntil
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorFailureUntil_bt_node_test_decoration_failureuntil_ut_1_node0, DecoratorFailureUntil);
		DecoratorFailureUntil_bt_node_test_decoration_failureuntil_ut_1_node0()
		{
			m_bDecorateWhenChildEnds = true;
		}
	protected:
		virtual int GetCount(Agent* pAgent) const
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			return 5;
		}
	};

		bool bt_node_test_decoration_failureuntil_ut_1::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("node_test/decoration_failureuntil_ut_1");
			pBT->SetIsFSM(false);
#if !BEHAVIAC_RELEASE
			pBT->SetAgentType("AgentNodeTest");
#endif
			// children
			{
				DecoratorFailureUntil_bt_node_test_decoration_failureuntil_ut_1_node0* node0 = BEHAVIAC_NEW DecoratorFailureUntil_bt_node_test_decoration_failureuntil_ut_1_node0;
				node0->SetClassNameString("DecoratorFailureUntil");
				node0->SetId(0);
#if !BEHAVIAC_RELEASE
				node0->SetAgentType("AgentNodeTest");
#endif
				pBT->AddChild(node0);
				{
					True* node1 = BEHAVIAC_NEW True;
					node1->SetClassNameString("True");
					node1->SetId(1);
#if !BEHAVIAC_RELEASE
					node1->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node1);
					node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
				}
				pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
			}
			return true;
		}

}
