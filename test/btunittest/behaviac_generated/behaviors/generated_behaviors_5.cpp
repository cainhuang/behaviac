#include "generated_behaviors_5.h"

namespace behaviac
{
	// Source file: node_test/parallel_ut_1

	class Parallel_bt_node_test_parallel_ut_1_node0 : public Parallel
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Parallel_bt_node_test_parallel_ut_1_node0, Parallel);
		Parallel_bt_node_test_parallel_ut_1_node0()
		{
			m_failPolicy = FAIL_ON_ONE;
			m_succeedPolicy = SUCCEED_ON_ALL;
			m_exitPolicy = EXIT_ABORT_RUNNINGSIBLINGS;
			m_childFinishPolicy = CHILDFINISH_LOOP;
		}
	protected:
	};

	class Action_bt_node_test_parallel_ut_1_node3 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_parallel_ut_1_node3, Action);
		Action_bt_node_test_parallel_ut_1_node3()
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

	class Action_bt_node_test_parallel_ut_1_node4 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_parallel_ut_1_node4, Action);
		Action_bt_node_test_parallel_ut_1_node4()
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

	class Action_bt_node_test_parallel_ut_1_node5 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_parallel_ut_1_node5, Action);
		Action_bt_node_test_parallel_ut_1_node5()
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

	class Action_bt_node_test_parallel_ut_1_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_parallel_ut_1_node2, Action);
		Action_bt_node_test_parallel_ut_1_node2()
		{
			method_p0 = 3;
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

		bool bt_node_test_parallel_ut_1::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("node_test/parallel_ut_1");
			pBT->SetIsFSM(false);
#if !BEHAVIAC_RELEASE
			pBT->SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Sequence* node1 = BEHAVIAC_NEW Sequence;
				node1->SetClassNameString("Sequence");
				node1->SetId(1);
#if !BEHAVIAC_RELEASE
				node1->SetAgentType("AgentNodeTest");
#endif
				pBT->AddChild(node1);
				{
					Parallel_bt_node_test_parallel_ut_1_node0* node0 = BEHAVIAC_NEW Parallel_bt_node_test_parallel_ut_1_node0;
					node0->SetClassNameString("Parallel");
					node0->SetId(0);
#if !BEHAVIAC_RELEASE
					node0->SetAgentType("AgentNodeTest");
#endif
					node1->AddChild(node0);
					{
						Action_bt_node_test_parallel_ut_1_node3* node3 = BEHAVIAC_NEW Action_bt_node_test_parallel_ut_1_node3;
						node3->SetClassNameString("Action");
						node3->SetId(3);
#if !BEHAVIAC_RELEASE
						node3->SetAgentType("AgentNodeTest");
#endif
						node0->AddChild(node3);
						node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
					}
					{
						Action_bt_node_test_parallel_ut_1_node4* node4 = BEHAVIAC_NEW Action_bt_node_test_parallel_ut_1_node4;
						node4->SetClassNameString("Action");
						node4->SetId(4);
#if !BEHAVIAC_RELEASE
						node4->SetAgentType("AgentNodeTest");
#endif
						node0->AddChild(node4);
						node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
					}
					{
						Action_bt_node_test_parallel_ut_1_node5* node5 = BEHAVIAC_NEW Action_bt_node_test_parallel_ut_1_node5;
						node5->SetClassNameString("Action");
						node5->SetId(5);
#if !BEHAVIAC_RELEASE
						node5->SetAgentType("AgentNodeTest");
#endif
						node0->AddChild(node5);
						node0->SetHasEvents(node0->HasEvents() | node5->HasEvents());
					}
					node1->SetHasEvents(node1->HasEvents() | node0->HasEvents());
				}
				{
					Action_bt_node_test_parallel_ut_1_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_parallel_ut_1_node2;
					node2->SetClassNameString("Action");
					node2->SetId(2);
#if !BEHAVIAC_RELEASE
					node2->SetAgentType("AgentNodeTest");
#endif
					node1->AddChild(node2);
					node1->SetHasEvents(node1->HasEvents() | node2->HasEvents());
				}
				pBT->SetHasEvents(pBT->HasEvents() | node1->HasEvents());
			}
			return true;
		}

	// Source file: node_test/parallel_ut_2

	class Parallel_bt_node_test_parallel_ut_2_node0 : public Parallel
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Parallel_bt_node_test_parallel_ut_2_node0, Parallel);
		Parallel_bt_node_test_parallel_ut_2_node0()
		{
			m_failPolicy = FAIL_ON_ALL;
			m_succeedPolicy = SUCCEED_ON_ALL;
			m_exitPolicy = EXIT_ABORT_RUNNINGSIBLINGS;
			m_childFinishPolicy = CHILDFINISH_LOOP;
		}
	protected:
	};

	class Action_bt_node_test_parallel_ut_2_node3 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_parallel_ut_2_node3, Action);
		Action_bt_node_test_parallel_ut_2_node3()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, int >(method_p0);
			return BT_FAILURE;
		}
		int method_p0;
	};

	class Action_bt_node_test_parallel_ut_2_node4 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_parallel_ut_2_node4, Action);
		Action_bt_node_test_parallel_ut_2_node4()
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

	class Action_bt_node_test_parallel_ut_2_node5 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_parallel_ut_2_node5, Action);
		Action_bt_node_test_parallel_ut_2_node5()
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

	class Action_bt_node_test_parallel_ut_2_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_parallel_ut_2_node2, Action);
		Action_bt_node_test_parallel_ut_2_node2()
		{
			method_p0 = 3;
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

		bool bt_node_test_parallel_ut_2::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("node_test/parallel_ut_2");
			pBT->SetIsFSM(false);
#if !BEHAVIAC_RELEASE
			pBT->SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Sequence* node1 = BEHAVIAC_NEW Sequence;
				node1->SetClassNameString("Sequence");
				node1->SetId(1);
#if !BEHAVIAC_RELEASE
				node1->SetAgentType("AgentNodeTest");
#endif
				pBT->AddChild(node1);
				{
					Parallel_bt_node_test_parallel_ut_2_node0* node0 = BEHAVIAC_NEW Parallel_bt_node_test_parallel_ut_2_node0;
					node0->SetClassNameString("Parallel");
					node0->SetId(0);
#if !BEHAVIAC_RELEASE
					node0->SetAgentType("AgentNodeTest");
#endif
					node1->AddChild(node0);
					{
						Action_bt_node_test_parallel_ut_2_node3* node3 = BEHAVIAC_NEW Action_bt_node_test_parallel_ut_2_node3;
						node3->SetClassNameString("Action");
						node3->SetId(3);
#if !BEHAVIAC_RELEASE
						node3->SetAgentType("AgentNodeTest");
#endif
						node0->AddChild(node3);
						node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
					}
					{
						Action_bt_node_test_parallel_ut_2_node4* node4 = BEHAVIAC_NEW Action_bt_node_test_parallel_ut_2_node4;
						node4->SetClassNameString("Action");
						node4->SetId(4);
#if !BEHAVIAC_RELEASE
						node4->SetAgentType("AgentNodeTest");
#endif
						node0->AddChild(node4);
						node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
					}
					{
						Action_bt_node_test_parallel_ut_2_node5* node5 = BEHAVIAC_NEW Action_bt_node_test_parallel_ut_2_node5;
						node5->SetClassNameString("Action");
						node5->SetId(5);
#if !BEHAVIAC_RELEASE
						node5->SetAgentType("AgentNodeTest");
#endif
						node0->AddChild(node5);
						node0->SetHasEvents(node0->HasEvents() | node5->HasEvents());
					}
					node1->SetHasEvents(node1->HasEvents() | node0->HasEvents());
				}
				{
					Action_bt_node_test_parallel_ut_2_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_parallel_ut_2_node2;
					node2->SetClassNameString("Action");
					node2->SetId(2);
#if !BEHAVIAC_RELEASE
					node2->SetAgentType("AgentNodeTest");
#endif
					node1->AddChild(node2);
					node1->SetHasEvents(node1->HasEvents() | node2->HasEvents());
				}
				pBT->SetHasEvents(pBT->HasEvents() | node1->HasEvents());
			}
			return true;
		}

	// Source file: node_test/parallel_ut_3

	class Parallel_bt_node_test_parallel_ut_3_node0 : public Parallel
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Parallel_bt_node_test_parallel_ut_3_node0, Parallel);
		Parallel_bt_node_test_parallel_ut_3_node0()
		{
			m_failPolicy = FAIL_ON_ONE;
			m_succeedPolicy = SUCCEED_ON_ALL;
			m_exitPolicy = EXIT_ABORT_RUNNINGSIBLINGS;
			m_childFinishPolicy = CHILDFINISH_ONCE;
		}
	protected:
	};

	class Action_bt_node_test_parallel_ut_3_node3 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_parallel_ut_3_node3, Action);
		Action_bt_node_test_parallel_ut_3_node3()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, int >(method_p0);
			return BT_RUNNING;
		}
		int method_p0;
	};

	class Action_bt_node_test_parallel_ut_3_node4 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_parallel_ut_3_node4, Action);
		Action_bt_node_test_parallel_ut_3_node4()
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

	class Action_bt_node_test_parallel_ut_3_node5 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_parallel_ut_3_node5, Action);
		Action_bt_node_test_parallel_ut_3_node5()
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

	class Action_bt_node_test_parallel_ut_3_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_parallel_ut_3_node2, Action);
		Action_bt_node_test_parallel_ut_3_node2()
		{
			method_p0 = 3;
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

		bool bt_node_test_parallel_ut_3::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("node_test/parallel_ut_3");
			pBT->SetIsFSM(false);
#if !BEHAVIAC_RELEASE
			pBT->SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Sequence* node1 = BEHAVIAC_NEW Sequence;
				node1->SetClassNameString("Sequence");
				node1->SetId(1);
#if !BEHAVIAC_RELEASE
				node1->SetAgentType("AgentNodeTest");
#endif
				pBT->AddChild(node1);
				{
					Parallel_bt_node_test_parallel_ut_3_node0* node0 = BEHAVIAC_NEW Parallel_bt_node_test_parallel_ut_3_node0;
					node0->SetClassNameString("Parallel");
					node0->SetId(0);
#if !BEHAVIAC_RELEASE
					node0->SetAgentType("AgentNodeTest");
#endif
					node1->AddChild(node0);
					{
						Action_bt_node_test_parallel_ut_3_node3* node3 = BEHAVIAC_NEW Action_bt_node_test_parallel_ut_3_node3;
						node3->SetClassNameString("Action");
						node3->SetId(3);
#if !BEHAVIAC_RELEASE
						node3->SetAgentType("AgentNodeTest");
#endif
						node0->AddChild(node3);
						node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
					}
					{
						Action_bt_node_test_parallel_ut_3_node4* node4 = BEHAVIAC_NEW Action_bt_node_test_parallel_ut_3_node4;
						node4->SetClassNameString("Action");
						node4->SetId(4);
#if !BEHAVIAC_RELEASE
						node4->SetAgentType("AgentNodeTest");
#endif
						node0->AddChild(node4);
						node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
					}
					{
						Action_bt_node_test_parallel_ut_3_node5* node5 = BEHAVIAC_NEW Action_bt_node_test_parallel_ut_3_node5;
						node5->SetClassNameString("Action");
						node5->SetId(5);
#if !BEHAVIAC_RELEASE
						node5->SetAgentType("AgentNodeTest");
#endif
						node0->AddChild(node5);
						node0->SetHasEvents(node0->HasEvents() | node5->HasEvents());
					}
					node1->SetHasEvents(node1->HasEvents() | node0->HasEvents());
				}
				{
					Action_bt_node_test_parallel_ut_3_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_parallel_ut_3_node2;
					node2->SetClassNameString("Action");
					node2->SetId(2);
#if !BEHAVIAC_RELEASE
					node2->SetAgentType("AgentNodeTest");
#endif
					node1->AddChild(node2);
					node1->SetHasEvents(node1->HasEvents() | node2->HasEvents());
				}
				pBT->SetHasEvents(pBT->HasEvents() | node1->HasEvents());
			}
			return true;
		}

	// Source file: node_test/parallel_ut_4

	class Parallel_bt_node_test_parallel_ut_4_node0 : public Parallel
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Parallel_bt_node_test_parallel_ut_4_node0, Parallel);
		Parallel_bt_node_test_parallel_ut_4_node0()
		{
			m_failPolicy = FAIL_ON_ONE;
			m_succeedPolicy = SUCCEED_ON_ALL;
			m_exitPolicy = EXIT_ABORT_RUNNINGSIBLINGS;
			m_childFinishPolicy = CHILDFINISH_LOOP;
		}
	protected:
	};

	class Action_bt_node_test_parallel_ut_4_node3 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_parallel_ut_4_node3, Action);
		Action_bt_node_test_parallel_ut_4_node3()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, int >(method_p0);
			return BT_RUNNING;
		}
		int method_p0;
	};

	class Action_bt_node_test_parallel_ut_4_node4 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_parallel_ut_4_node4, Action);
		Action_bt_node_test_parallel_ut_4_node4()
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

	class Action_bt_node_test_parallel_ut_4_node5 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_parallel_ut_4_node5, Action);
		Action_bt_node_test_parallel_ut_4_node5()
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

	class Action_bt_node_test_parallel_ut_4_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_parallel_ut_4_node2, Action);
		Action_bt_node_test_parallel_ut_4_node2()
		{
			method_p0 = 3;
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

		bool bt_node_test_parallel_ut_4::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("node_test/parallel_ut_4");
			pBT->SetIsFSM(false);
#if !BEHAVIAC_RELEASE
			pBT->SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Sequence* node1 = BEHAVIAC_NEW Sequence;
				node1->SetClassNameString("Sequence");
				node1->SetId(1);
#if !BEHAVIAC_RELEASE
				node1->SetAgentType("AgentNodeTest");
#endif
				pBT->AddChild(node1);
				{
					Parallel_bt_node_test_parallel_ut_4_node0* node0 = BEHAVIAC_NEW Parallel_bt_node_test_parallel_ut_4_node0;
					node0->SetClassNameString("Parallel");
					node0->SetId(0);
#if !BEHAVIAC_RELEASE
					node0->SetAgentType("AgentNodeTest");
#endif
					node1->AddChild(node0);
					{
						Action_bt_node_test_parallel_ut_4_node3* node3 = BEHAVIAC_NEW Action_bt_node_test_parallel_ut_4_node3;
						node3->SetClassNameString("Action");
						node3->SetId(3);
#if !BEHAVIAC_RELEASE
						node3->SetAgentType("AgentNodeTest");
#endif
						node0->AddChild(node3);
						node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
					}
					{
						Action_bt_node_test_parallel_ut_4_node4* node4 = BEHAVIAC_NEW Action_bt_node_test_parallel_ut_4_node4;
						node4->SetClassNameString("Action");
						node4->SetId(4);
#if !BEHAVIAC_RELEASE
						node4->SetAgentType("AgentNodeTest");
#endif
						node0->AddChild(node4);
						node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
					}
					{
						Action_bt_node_test_parallel_ut_4_node5* node5 = BEHAVIAC_NEW Action_bt_node_test_parallel_ut_4_node5;
						node5->SetClassNameString("Action");
						node5->SetId(5);
#if !BEHAVIAC_RELEASE
						node5->SetAgentType("AgentNodeTest");
#endif
						node0->AddChild(node5);
						node0->SetHasEvents(node0->HasEvents() | node5->HasEvents());
					}
					node1->SetHasEvents(node1->HasEvents() | node0->HasEvents());
				}
				{
					Action_bt_node_test_parallel_ut_4_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_parallel_ut_4_node2;
					node2->SetClassNameString("Action");
					node2->SetId(2);
#if !BEHAVIAC_RELEASE
					node2->SetAgentType("AgentNodeTest");
#endif
					node1->AddChild(node2);
					node1->SetHasEvents(node1->HasEvents() | node2->HasEvents());
				}
				pBT->SetHasEvents(pBT->HasEvents() | node1->HasEvents());
			}
			return true;
		}

	// Source file: node_test/predicate_action_ut_0

	class Action_bt_node_test_predicate_action_ut_0_node1 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_action_ut_0_node1, Action);
		Action_bt_node_test_predicate_action_ut_0_node1()
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

	class Precondition_bt_node_test_predicate_action_ut_0_attach2 : public Precondition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Precondition_bt_node_test_predicate_action_ut_0_attach2, Precondition);
		Precondition_bt_node_test_predicate_action_ut_0_attach2()
		{
			this->SetPhase(Precondition::E_ENTER);
			this->SetIsAnd(true);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, int >();
			int opr2 = -1;
			bool op = Details::Equal(opl, opr2);
			if (!op)
				result = BT_FAILURE;
			return result;
		}
	};

	class Action_bt_node_test_predicate_action_ut_0_node4 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_action_ut_0_node4, Action);
		Action_bt_node_test_predicate_action_ut_0_node4()
		{
			method_p0 = 0;
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

	class Precondition_bt_node_test_predicate_action_ut_0_attach3 : public Precondition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Precondition_bt_node_test_predicate_action_ut_0_attach3, Precondition);
		Precondition_bt_node_test_predicate_action_ut_0_attach3()
		{
			this->SetPhase(Precondition::E_ENTER);
			this->SetIsAnd(true);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, int >();
			int opr2 = -1;
			bool op = Details::Equal(opl, opr2);
			if (!op)
				result = BT_FAILURE;
			return result;
		}
	};

		bool bt_node_test_predicate_action_ut_0::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("node_test/predicate_action_ut_0");
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
					Action_bt_node_test_predicate_action_ut_0_node1* node1 = BEHAVIAC_NEW Action_bt_node_test_predicate_action_ut_0_node1;
					node1->SetClassNameString("Action");
					node1->SetId(1);
#if !BEHAVIAC_RELEASE
					node1->SetAgentType("AgentNodeTest");
#endif
					// attachments
					{
						Precondition_bt_node_test_predicate_action_ut_0_attach2* attach2 = BEHAVIAC_NEW Precondition_bt_node_test_predicate_action_ut_0_attach2;
						attach2->SetClassNameString("Precondition");
						attach2->SetId(2);
#if !BEHAVIAC_RELEASE
						attach2->SetAgentType("AgentNodeTest");
#endif
						node1->Attach(attach2, true, false, false);
						node1->SetHasEvents(node1->HasEvents() | (Event::DynamicCast(attach2) != 0));
					}
					node0->AddChild(node1);
					node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
				}
				{
					Action_bt_node_test_predicate_action_ut_0_node4* node4 = BEHAVIAC_NEW Action_bt_node_test_predicate_action_ut_0_node4;
					node4->SetClassNameString("Action");
					node4->SetId(4);
#if !BEHAVIAC_RELEASE
					node4->SetAgentType("AgentNodeTest");
#endif
					// attachments
					{
						Precondition_bt_node_test_predicate_action_ut_0_attach3* attach3 = BEHAVIAC_NEW Precondition_bt_node_test_predicate_action_ut_0_attach3;
						attach3->SetClassNameString("Precondition");
						attach3->SetId(3);
#if !BEHAVIAC_RELEASE
						attach3->SetAgentType("AgentNodeTest");
#endif
						node4->Attach(attach3, true, false, false);
						node4->SetHasEvents(node4->HasEvents() | (Event::DynamicCast(attach3) != 0));
					}
					node0->AddChild(node4);
					node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
				}
				pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
			}
			return true;
		}

	// Source file: node_test/predicate_action_ut_1

	class Action_bt_node_test_predicate_action_ut_1_node1 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_action_ut_1_node1, Action);
		Action_bt_node_test_predicate_action_ut_1_node1()
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

	class Precondition_bt_node_test_predicate_action_ut_1_attach2 : public Precondition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Precondition_bt_node_test_predicate_action_ut_1_attach2, Precondition);
		Precondition_bt_node_test_predicate_action_ut_1_attach2()
		{
			this->SetPhase(Precondition::E_ENTER);
			this->SetIsAnd(true);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, int >();
			int opr2 = -1;
			bool op = Details::Equal(opl, opr2);
			if (!op)
				result = BT_FAILURE;
			return result;
		}
	};

	class Precondition_bt_node_test_predicate_action_ut_1_attach3 : public Precondition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Precondition_bt_node_test_predicate_action_ut_1_attach3, Precondition);
		Precondition_bt_node_test_predicate_action_ut_1_attach3()
		{
			this->SetPhase(Precondition::E_ENTER);
			this->SetIsAnd(false);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_1, int >();
			int opr2 = 0;
			bool op = Details::Equal(opl, opr2);
			if (!op)
				result = BT_FAILURE;
			return result;
		}
	};

	class Action_bt_node_test_predicate_action_ut_1_node6 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_action_ut_1_node6, Action);
		Action_bt_node_test_predicate_action_ut_1_node6()
		{
			method_p0 = 0;
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

	class Precondition_bt_node_test_predicate_action_ut_1_attach4 : public Precondition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Precondition_bt_node_test_predicate_action_ut_1_attach4, Precondition);
		Precondition_bt_node_test_predicate_action_ut_1_attach4()
		{
			this->SetPhase(Precondition::E_ENTER);
			this->SetIsAnd(true);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, int >();
			int opr2 = 0;
			bool op = Details::Equal(opl, opr2);
			if (!op)
				result = BT_FAILURE;
			return result;
		}
	};

	class Precondition_bt_node_test_predicate_action_ut_1_attach5 : public Precondition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Precondition_bt_node_test_predicate_action_ut_1_attach5, Precondition);
		Precondition_bt_node_test_predicate_action_ut_1_attach5()
		{
			this->SetPhase(Precondition::E_ENTER);
			this->SetIsAnd(true);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_1, int >();
			int opr2 = -1;
			bool op = Details::Equal(opl, opr2);
			if (!op)
				result = BT_FAILURE;
			return result;
		}
	};

		bool bt_node_test_predicate_action_ut_1::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("node_test/predicate_action_ut_1");
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
					Action_bt_node_test_predicate_action_ut_1_node1* node1 = BEHAVIAC_NEW Action_bt_node_test_predicate_action_ut_1_node1;
					node1->SetClassNameString("Action");
					node1->SetId(1);
#if !BEHAVIAC_RELEASE
					node1->SetAgentType("AgentNodeTest");
#endif
					// attachments
					{
						Precondition_bt_node_test_predicate_action_ut_1_attach2* attach2 = BEHAVIAC_NEW Precondition_bt_node_test_predicate_action_ut_1_attach2;
						attach2->SetClassNameString("Precondition");
						attach2->SetId(2);
#if !BEHAVIAC_RELEASE
						attach2->SetAgentType("AgentNodeTest");
#endif
						node1->Attach(attach2, true, false, false);
						node1->SetHasEvents(node1->HasEvents() | (Event::DynamicCast(attach2) != 0));
					}
					{
						Precondition_bt_node_test_predicate_action_ut_1_attach3* attach3 = BEHAVIAC_NEW Precondition_bt_node_test_predicate_action_ut_1_attach3;
						attach3->SetClassNameString("Precondition");
						attach3->SetId(3);
#if !BEHAVIAC_RELEASE
						attach3->SetAgentType("AgentNodeTest");
#endif
						node1->Attach(attach3, true, false, false);
						node1->SetHasEvents(node1->HasEvents() | (Event::DynamicCast(attach3) != 0));
					}
					node0->AddChild(node1);
					node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
				}
				{
					Action_bt_node_test_predicate_action_ut_1_node6* node6 = BEHAVIAC_NEW Action_bt_node_test_predicate_action_ut_1_node6;
					node6->SetClassNameString("Action");
					node6->SetId(6);
#if !BEHAVIAC_RELEASE
					node6->SetAgentType("AgentNodeTest");
#endif
					// attachments
					{
						Precondition_bt_node_test_predicate_action_ut_1_attach4* attach4 = BEHAVIAC_NEW Precondition_bt_node_test_predicate_action_ut_1_attach4;
						attach4->SetClassNameString("Precondition");
						attach4->SetId(4);
#if !BEHAVIAC_RELEASE
						attach4->SetAgentType("AgentNodeTest");
#endif
						node6->Attach(attach4, true, false, false);
						node6->SetHasEvents(node6->HasEvents() | (Event::DynamicCast(attach4) != 0));
					}
					{
						Precondition_bt_node_test_predicate_action_ut_1_attach5* attach5 = BEHAVIAC_NEW Precondition_bt_node_test_predicate_action_ut_1_attach5;
						attach5->SetClassNameString("Precondition");
						attach5->SetId(5);
#if !BEHAVIAC_RELEASE
						attach5->SetAgentType("AgentNodeTest");
#endif
						node6->Attach(attach5, true, false, false);
						node6->SetHasEvents(node6->HasEvents() | (Event::DynamicCast(attach5) != 0));
					}
					node0->AddChild(node6);
					node0->SetHasEvents(node0->HasEvents() | node6->HasEvents());
				}
				pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
			}
			return true;
		}

	// Source file: node_test/predicate_action_ut_2

	class Action_bt_node_test_predicate_action_ut_2_node1 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_action_ut_2_node1, Action);
		Action_bt_node_test_predicate_action_ut_2_node1()
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

	class Precondition_bt_node_test_predicate_action_ut_2_attach2 : public Precondition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Precondition_bt_node_test_predicate_action_ut_2_attach2, Precondition);
		Precondition_bt_node_test_predicate_action_ut_2_attach2()
		{
			this->SetPhase(Precondition::E_ENTER);
			this->SetIsAnd(true);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, int >();
			int opr2 = -1;
			bool op = Details::Equal(opl, opr2);
			if (!op)
				result = BT_FAILURE;
			return result;
		}
	};

	class Precondition_bt_node_test_predicate_action_ut_2_attach3 : public Precondition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Precondition_bt_node_test_predicate_action_ut_2_attach3, Precondition);
		Precondition_bt_node_test_predicate_action_ut_2_attach3()
		{
			this->SetPhase(Precondition::E_ENTER);
			this->SetIsAnd(false);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_1, int >();
			int opr2 = 0;
			bool op = Details::Equal(opl, opr2);
			if (!op)
				result = BT_FAILURE;
			return result;
		}
	};

	class Precondition_bt_node_test_predicate_action_ut_2_attach4 : public Precondition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Precondition_bt_node_test_predicate_action_ut_2_attach4, Precondition);
		Precondition_bt_node_test_predicate_action_ut_2_attach4()
		{
			this->SetPhase(Precondition::E_ENTER);
			this->SetIsAnd(true);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			float& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_2, float >();
			float opr2 = -1;
			bool op = Details::Equal(opl, opr2);
			if (!op)
				result = BT_FAILURE;
			return result;
		}
	};

	class Action_bt_node_test_predicate_action_ut_2_node8 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_action_ut_2_node8, Action);
		Action_bt_node_test_predicate_action_ut_2_node8()
		{
			method_p0 = 0;
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

	class Precondition_bt_node_test_predicate_action_ut_2_attach5 : public Precondition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Precondition_bt_node_test_predicate_action_ut_2_attach5, Precondition);
		Precondition_bt_node_test_predicate_action_ut_2_attach5()
		{
			this->SetPhase(Precondition::E_ENTER);
			this->SetIsAnd(true);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, int >();
			int opr2 = 0;
			bool op = Details::Equal(opl, opr2);
			if (!op)
				result = BT_FAILURE;
			return result;
		}
	};

	class Precondition_bt_node_test_predicate_action_ut_2_attach6 : public Precondition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Precondition_bt_node_test_predicate_action_ut_2_attach6, Precondition);
		Precondition_bt_node_test_predicate_action_ut_2_attach6()
		{
			this->SetPhase(Precondition::E_ENTER);
			this->SetIsAnd(true);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_1, int >();
			int opr2 = -1;
			bool op = Details::Equal(opl, opr2);
			if (!op)
				result = BT_FAILURE;
			return result;
		}
	};

	class Precondition_bt_node_test_predicate_action_ut_2_attach7 : public Precondition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Precondition_bt_node_test_predicate_action_ut_2_attach7, Precondition);
		Precondition_bt_node_test_predicate_action_ut_2_attach7()
		{
			this->SetPhase(Precondition::E_ENTER);
			this->SetIsAnd(true);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			float& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_2, float >();
			float opr2 = -1;
			bool op = Details::Equal(opl, opr2);
			if (!op)
				result = BT_FAILURE;
			return result;
		}
	};

		bool bt_node_test_predicate_action_ut_2::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("node_test/predicate_action_ut_2");
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
					Action_bt_node_test_predicate_action_ut_2_node1* node1 = BEHAVIAC_NEW Action_bt_node_test_predicate_action_ut_2_node1;
					node1->SetClassNameString("Action");
					node1->SetId(1);
#if !BEHAVIAC_RELEASE
					node1->SetAgentType("AgentNodeTest");
#endif
					// attachments
					{
						Precondition_bt_node_test_predicate_action_ut_2_attach2* attach2 = BEHAVIAC_NEW Precondition_bt_node_test_predicate_action_ut_2_attach2;
						attach2->SetClassNameString("Precondition");
						attach2->SetId(2);
#if !BEHAVIAC_RELEASE
						attach2->SetAgentType("AgentNodeTest");
#endif
						node1->Attach(attach2, true, false, false);
						node1->SetHasEvents(node1->HasEvents() | (Event::DynamicCast(attach2) != 0));
					}
					{
						Precondition_bt_node_test_predicate_action_ut_2_attach3* attach3 = BEHAVIAC_NEW Precondition_bt_node_test_predicate_action_ut_2_attach3;
						attach3->SetClassNameString("Precondition");
						attach3->SetId(3);
#if !BEHAVIAC_RELEASE
						attach3->SetAgentType("AgentNodeTest");
#endif
						node1->Attach(attach3, true, false, false);
						node1->SetHasEvents(node1->HasEvents() | (Event::DynamicCast(attach3) != 0));
					}
					{
						Precondition_bt_node_test_predicate_action_ut_2_attach4* attach4 = BEHAVIAC_NEW Precondition_bt_node_test_predicate_action_ut_2_attach4;
						attach4->SetClassNameString("Precondition");
						attach4->SetId(4);
#if !BEHAVIAC_RELEASE
						attach4->SetAgentType("AgentNodeTest");
#endif
						node1->Attach(attach4, true, false, false);
						node1->SetHasEvents(node1->HasEvents() | (Event::DynamicCast(attach4) != 0));
					}
					node0->AddChild(node1);
					node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
				}
				{
					Action_bt_node_test_predicate_action_ut_2_node8* node8 = BEHAVIAC_NEW Action_bt_node_test_predicate_action_ut_2_node8;
					node8->SetClassNameString("Action");
					node8->SetId(8);
#if !BEHAVIAC_RELEASE
					node8->SetAgentType("AgentNodeTest");
#endif
					// attachments
					{
						Precondition_bt_node_test_predicate_action_ut_2_attach5* attach5 = BEHAVIAC_NEW Precondition_bt_node_test_predicate_action_ut_2_attach5;
						attach5->SetClassNameString("Precondition");
						attach5->SetId(5);
#if !BEHAVIAC_RELEASE
						attach5->SetAgentType("AgentNodeTest");
#endif
						node8->Attach(attach5, true, false, false);
						node8->SetHasEvents(node8->HasEvents() | (Event::DynamicCast(attach5) != 0));
					}
					{
						Precondition_bt_node_test_predicate_action_ut_2_attach6* attach6 = BEHAVIAC_NEW Precondition_bt_node_test_predicate_action_ut_2_attach6;
						attach6->SetClassNameString("Precondition");
						attach6->SetId(6);
#if !BEHAVIAC_RELEASE
						attach6->SetAgentType("AgentNodeTest");
#endif
						node8->Attach(attach6, true, false, false);
						node8->SetHasEvents(node8->HasEvents() | (Event::DynamicCast(attach6) != 0));
					}
					{
						Precondition_bt_node_test_predicate_action_ut_2_attach7* attach7 = BEHAVIAC_NEW Precondition_bt_node_test_predicate_action_ut_2_attach7;
						attach7->SetClassNameString("Precondition");
						attach7->SetId(7);
#if !BEHAVIAC_RELEASE
						attach7->SetAgentType("AgentNodeTest");
#endif
						node8->Attach(attach7, true, false, false);
						node8->SetHasEvents(node8->HasEvents() | (Event::DynamicCast(attach7) != 0));
					}
					node0->AddChild(node8);
					node0->SetHasEvents(node0->HasEvents() | node8->HasEvents());
				}
				pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
			}
			return true;
		}

	// Source file: node_test/predicate_action_ut_3

	class Action_bt_node_test_predicate_action_ut_3_node0 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_action_ut_3_node0, Action);
		Action_bt_node_test_predicate_action_ut_3_node0()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, int >(method_p0);
			return BT_RUNNING;
		}
		int method_p0;
	};

	class Precondition_bt_node_test_predicate_action_ut_3_attach1 : public Precondition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Precondition_bt_node_test_predicate_action_ut_3_attach1, Precondition);
		Precondition_bt_node_test_predicate_action_ut_3_attach1()
		{
			this->SetPhase(Precondition::E_BOTH);
			this->SetIsAnd(true);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, int >();
			int opr2 = -1;
			bool op = Details::Equal(opl, opr2);
			if (!op)
				result = BT_FAILURE;
			return result;
		}
	};

		bool bt_node_test_predicate_action_ut_3::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("node_test/predicate_action_ut_3");
			pBT->SetIsFSM(false);
#if !BEHAVIAC_RELEASE
			pBT->SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Action_bt_node_test_predicate_action_ut_3_node0* node0 = BEHAVIAC_NEW Action_bt_node_test_predicate_action_ut_3_node0;
				node0->SetClassNameString("Action");
				node0->SetId(0);
#if !BEHAVIAC_RELEASE
				node0->SetAgentType("AgentNodeTest");
#endif
				// attachments
				{
					Precondition_bt_node_test_predicate_action_ut_3_attach1* attach1 = BEHAVIAC_NEW Precondition_bt_node_test_predicate_action_ut_3_attach1;
					attach1->SetClassNameString("Precondition");
					attach1->SetId(1);
#if !BEHAVIAC_RELEASE
					attach1->SetAgentType("AgentNodeTest");
#endif
					node0->Attach(attach1, true, false, false);
					node0->SetHasEvents(node0->HasEvents() | (Event::DynamicCast(attach1) != 0));
				}
				pBT->AddChild(node0);
				pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
			}
			return true;
		}

	// Source file: node_test/predicate_selector_ut_0

	class DecoratorNot_bt_node_test_predicate_selector_ut_0_node1 : public DecoratorNot
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorNot_bt_node_test_predicate_selector_ut_0_node1, DecoratorNot);
		DecoratorNot_bt_node_test_predicate_selector_ut_0_node1()
		{
			m_bDecorateWhenChildEnds = false;
		}
	protected:
	};

	class Condition_bt_node_test_predicate_selector_ut_0_node3 : public Condition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Condition_bt_node_test_predicate_selector_ut_0_node3, Condition);
		Condition_bt_node_test_predicate_selector_ut_0_node3()
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

	class Action_bt_node_test_predicate_selector_ut_0_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_selector_ut_0_node2, Action);
		Action_bt_node_test_predicate_selector_ut_0_node2()
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

	class Action_bt_node_test_predicate_selector_ut_0_node4 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_selector_ut_0_node4, Action);
		Action_bt_node_test_predicate_selector_ut_0_node4()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, int >(method_p0);
			return BT_FAILURE;
		}
		int method_p0;
	};

	class Action_bt_node_test_predicate_selector_ut_0_node5 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_selector_ut_0_node5, Action);
		Action_bt_node_test_predicate_selector_ut_0_node5()
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

		bool bt_node_test_predicate_selector_ut_0::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("node_test/predicate_selector_ut_0");
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
					DecoratorNot_bt_node_test_predicate_selector_ut_0_node1* node1 = BEHAVIAC_NEW DecoratorNot_bt_node_test_predicate_selector_ut_0_node1;
					node1->SetClassNameString("DecoratorNot");
					node1->SetId(1);
#if !BEHAVIAC_RELEASE
					node1->SetAgentType("AgentNodeTest");
#endif
					node0->SetCustomCondition(node1);
					{
						Condition_bt_node_test_predicate_selector_ut_0_node3* node3 = BEHAVIAC_NEW Condition_bt_node_test_predicate_selector_ut_0_node3;
						node3->SetClassNameString("Condition");
						node3->SetId(3);
#if !BEHAVIAC_RELEASE
						node3->SetAgentType("AgentNodeTest");
#endif
						node1->AddChild(node3);
						node1->SetHasEvents(node1->HasEvents() | node3->HasEvents());
					}
					node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
				}
				{
					Action_bt_node_test_predicate_selector_ut_0_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_predicate_selector_ut_0_node2;
					node2->SetClassNameString("Action");
					node2->SetId(2);
#if !BEHAVIAC_RELEASE
					node2->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node2);
					node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
				}
				{
					Action_bt_node_test_predicate_selector_ut_0_node4* node4 = BEHAVIAC_NEW Action_bt_node_test_predicate_selector_ut_0_node4;
					node4->SetClassNameString("Action");
					node4->SetId(4);
#if !BEHAVIAC_RELEASE
					node4->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node4);
					node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
				}
				{
					Action_bt_node_test_predicate_selector_ut_0_node5* node5 = BEHAVIAC_NEW Action_bt_node_test_predicate_selector_ut_0_node5;
					node5->SetClassNameString("Action");
					node5->SetId(5);
#if !BEHAVIAC_RELEASE
					node5->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node5);
					node0->SetHasEvents(node0->HasEvents() | node5->HasEvents());
				}
				pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
			}
			return true;
		}

	// Source file: node_test/predicate_selector_ut_1

	class DecoratorNot_bt_node_test_predicate_selector_ut_1_node1 : public DecoratorNot
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorNot_bt_node_test_predicate_selector_ut_1_node1, DecoratorNot);
		DecoratorNot_bt_node_test_predicate_selector_ut_1_node1()
		{
			m_bDecorateWhenChildEnds = false;
		}
	protected:
	};

	class Condition_bt_node_test_predicate_selector_ut_1_node3 : public Condition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Condition_bt_node_test_predicate_selector_ut_1_node3, Condition);
		Condition_bt_node_test_predicate_selector_ut_1_node3()
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

	class Action_bt_node_test_predicate_selector_ut_1_node4 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_selector_ut_1_node4, Action);
		Action_bt_node_test_predicate_selector_ut_1_node4()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, int >(method_p0);
			return BT_FAILURE;
		}
		int method_p0;
	};

	class Action_bt_node_test_predicate_selector_ut_1_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_selector_ut_1_node2, Action);
		Action_bt_node_test_predicate_selector_ut_1_node2()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, int >(method_p0);
			return BT_FAILURE;
		}
		int method_p0;
	};

	class Action_bt_node_test_predicate_selector_ut_1_node5 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_selector_ut_1_node5, Action);
		Action_bt_node_test_predicate_selector_ut_1_node5()
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

		bool bt_node_test_predicate_selector_ut_1::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("node_test/predicate_selector_ut_1");
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
					DecoratorNot_bt_node_test_predicate_selector_ut_1_node1* node1 = BEHAVIAC_NEW DecoratorNot_bt_node_test_predicate_selector_ut_1_node1;
					node1->SetClassNameString("DecoratorNot");
					node1->SetId(1);
#if !BEHAVIAC_RELEASE
					node1->SetAgentType("AgentNodeTest");
#endif
					node0->SetCustomCondition(node1);
					{
						Condition_bt_node_test_predicate_selector_ut_1_node3* node3 = BEHAVIAC_NEW Condition_bt_node_test_predicate_selector_ut_1_node3;
						node3->SetClassNameString("Condition");
						node3->SetId(3);
#if !BEHAVIAC_RELEASE
						node3->SetAgentType("AgentNodeTest");
#endif
						node1->AddChild(node3);
						node1->SetHasEvents(node1->HasEvents() | node3->HasEvents());
					}
					node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
				}
				{
					Action_bt_node_test_predicate_selector_ut_1_node4* node4 = BEHAVIAC_NEW Action_bt_node_test_predicate_selector_ut_1_node4;
					node4->SetClassNameString("Action");
					node4->SetId(4);
#if !BEHAVIAC_RELEASE
					node4->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node4);
					node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
				}
				{
					Action_bt_node_test_predicate_selector_ut_1_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_predicate_selector_ut_1_node2;
					node2->SetClassNameString("Action");
					node2->SetId(2);
#if !BEHAVIAC_RELEASE
					node2->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node2);
					node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
				}
				{
					Action_bt_node_test_predicate_selector_ut_1_node5* node5 = BEHAVIAC_NEW Action_bt_node_test_predicate_selector_ut_1_node5;
					node5->SetClassNameString("Action");
					node5->SetId(5);
#if !BEHAVIAC_RELEASE
					node5->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node5);
					node0->SetHasEvents(node0->HasEvents() | node5->HasEvents());
				}
				pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
			}
			return true;
		}

	// Source file: node_test/predicate_selector_ut_2

	class DecoratorNot_bt_node_test_predicate_selector_ut_2_node1 : public DecoratorNot
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorNot_bt_node_test_predicate_selector_ut_2_node1, DecoratorNot);
		DecoratorNot_bt_node_test_predicate_selector_ut_2_node1()
		{
			m_bDecorateWhenChildEnds = false;
		}
	protected:
	};

	class Condition_bt_node_test_predicate_selector_ut_2_node3 : public Condition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Condition_bt_node_test_predicate_selector_ut_2_node3, Condition);
		Condition_bt_node_test_predicate_selector_ut_2_node3()
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

	class Action_bt_node_test_predicate_selector_ut_2_node4 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_selector_ut_2_node4, Action);
		Action_bt_node_test_predicate_selector_ut_2_node4()
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

	class Action_bt_node_test_predicate_selector_ut_2_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_selector_ut_2_node2, Action);
		Action_bt_node_test_predicate_selector_ut_2_node2()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_2, void, float >(method_p0);
			return BT_FAILURE;
		}
		float method_p0;
	};

	class Action_bt_node_test_predicate_selector_ut_2_node5 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_selector_ut_2_node5, Action);
		Action_bt_node_test_predicate_selector_ut_2_node5()
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

		bool bt_node_test_predicate_selector_ut_2::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("node_test/predicate_selector_ut_2");
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
					DecoratorNot_bt_node_test_predicate_selector_ut_2_node1* node1 = BEHAVIAC_NEW DecoratorNot_bt_node_test_predicate_selector_ut_2_node1;
					node1->SetClassNameString("DecoratorNot");
					node1->SetId(1);
#if !BEHAVIAC_RELEASE
					node1->SetAgentType("AgentNodeTest");
#endif
					node0->SetCustomCondition(node1);
					{
						Condition_bt_node_test_predicate_selector_ut_2_node3* node3 = BEHAVIAC_NEW Condition_bt_node_test_predicate_selector_ut_2_node3;
						node3->SetClassNameString("Condition");
						node3->SetId(3);
#if !BEHAVIAC_RELEASE
						node3->SetAgentType("AgentNodeTest");
#endif
						node1->AddChild(node3);
						node1->SetHasEvents(node1->HasEvents() | node3->HasEvents());
					}
					node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
				}
				{
					Action_bt_node_test_predicate_selector_ut_2_node4* node4 = BEHAVIAC_NEW Action_bt_node_test_predicate_selector_ut_2_node4;
					node4->SetClassNameString("Action");
					node4->SetId(4);
#if !BEHAVIAC_RELEASE
					node4->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node4);
					node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
				}
				{
					Action_bt_node_test_predicate_selector_ut_2_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_predicate_selector_ut_2_node2;
					node2->SetClassNameString("Action");
					node2->SetId(2);
#if !BEHAVIAC_RELEASE
					node2->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node2);
					node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
				}
				{
					Action_bt_node_test_predicate_selector_ut_2_node5* node5 = BEHAVIAC_NEW Action_bt_node_test_predicate_selector_ut_2_node5;
					node5->SetClassNameString("Action");
					node5->SetId(5);
#if !BEHAVIAC_RELEASE
					node5->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node5);
					node0->SetHasEvents(node0->HasEvents() | node5->HasEvents());
				}
				pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
			}
			return true;
		}

	// Source file: node_test/predicate_selector_ut_3

	class DecoratorNot_bt_node_test_predicate_selector_ut_3_node1 : public DecoratorNot
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorNot_bt_node_test_predicate_selector_ut_3_node1, DecoratorNot);
		DecoratorNot_bt_node_test_predicate_selector_ut_3_node1()
		{
			m_bDecorateWhenChildEnds = false;
		}
	protected:
	};

	class Condition_bt_node_test_predicate_selector_ut_3_node6 : public Condition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Condition_bt_node_test_predicate_selector_ut_3_node6, Condition);
		Condition_bt_node_test_predicate_selector_ut_3_node6()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_1, int >();
			int opr = -1;
			bool op = Details::Equal(opl, opr);
			return op ? BT_SUCCESS : BT_FAILURE;
		}
	};

	class Condition_bt_node_test_predicate_selector_ut_3_node7 : public Condition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Condition_bt_node_test_predicate_selector_ut_3_node7, Condition);
		Condition_bt_node_test_predicate_selector_ut_3_node7()
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

	class Action_bt_node_test_predicate_selector_ut_3_node5 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_selector_ut_3_node5, Action);
		Action_bt_node_test_predicate_selector_ut_3_node5()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, int >(method_p0);
			return BT_FAILURE;
		}
		int method_p0;
	};

	class Action_bt_node_test_predicate_selector_ut_3_node4 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_selector_ut_3_node4, Action);
		Action_bt_node_test_predicate_selector_ut_3_node4()
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

	class Action_bt_node_test_predicate_selector_ut_3_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_selector_ut_3_node2, Action);
		Action_bt_node_test_predicate_selector_ut_3_node2()
		{
			method_p0 = 0;
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

		bool bt_node_test_predicate_selector_ut_3::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("node_test/predicate_selector_ut_3");
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
					DecoratorNot_bt_node_test_predicate_selector_ut_3_node1* node1 = BEHAVIAC_NEW DecoratorNot_bt_node_test_predicate_selector_ut_3_node1;
					node1->SetClassNameString("DecoratorNot");
					node1->SetId(1);
#if !BEHAVIAC_RELEASE
					node1->SetAgentType("AgentNodeTest");
#endif
					node0->SetCustomCondition(node1);
					{
						Sequence* node3 = BEHAVIAC_NEW Sequence;
						node3->SetClassNameString("Sequence");
						node3->SetId(3);
#if !BEHAVIAC_RELEASE
						node3->SetAgentType("AgentNodeTest");
#endif
						node1->AddChild(node3);
						{
							Condition_bt_node_test_predicate_selector_ut_3_node6* node6 = BEHAVIAC_NEW Condition_bt_node_test_predicate_selector_ut_3_node6;
							node6->SetClassNameString("Condition");
							node6->SetId(6);
#if !BEHAVIAC_RELEASE
							node6->SetAgentType("AgentNodeTest");
#endif
							node3->AddChild(node6);
							node3->SetHasEvents(node3->HasEvents() | node6->HasEvents());
						}
						{
							Condition_bt_node_test_predicate_selector_ut_3_node7* node7 = BEHAVIAC_NEW Condition_bt_node_test_predicate_selector_ut_3_node7;
							node7->SetClassNameString("Condition");
							node7->SetId(7);
#if !BEHAVIAC_RELEASE
							node7->SetAgentType("AgentNodeTest");
#endif
							node3->AddChild(node7);
							node3->SetHasEvents(node3->HasEvents() | node7->HasEvents());
						}
						node1->SetHasEvents(node1->HasEvents() | node3->HasEvents());
					}
					node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
				}
				{
					Action_bt_node_test_predicate_selector_ut_3_node5* node5 = BEHAVIAC_NEW Action_bt_node_test_predicate_selector_ut_3_node5;
					node5->SetClassNameString("Action");
					node5->SetId(5);
#if !BEHAVIAC_RELEASE
					node5->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node5);
					node0->SetHasEvents(node0->HasEvents() | node5->HasEvents());
				}
				{
					Action_bt_node_test_predicate_selector_ut_3_node4* node4 = BEHAVIAC_NEW Action_bt_node_test_predicate_selector_ut_3_node4;
					node4->SetClassNameString("Action");
					node4->SetId(4);
#if !BEHAVIAC_RELEASE
					node4->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node4);
					node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
				}
				{
					Action_bt_node_test_predicate_selector_ut_3_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_predicate_selector_ut_3_node2;
					node2->SetClassNameString("Action");
					node2->SetId(2);
#if !BEHAVIAC_RELEASE
					node2->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node2);
					node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
				}
				pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
			}
			return true;
		}

	// Source file: node_test/predicate_selector_ut_4

	class DecoratorNot_bt_node_test_predicate_selector_ut_4_node1 : public DecoratorNot
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorNot_bt_node_test_predicate_selector_ut_4_node1, DecoratorNot);
		DecoratorNot_bt_node_test_predicate_selector_ut_4_node1()
		{
			m_bDecorateWhenChildEnds = false;
		}
	protected:
	};

	class Condition_bt_node_test_predicate_selector_ut_4_node6 : public Condition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Condition_bt_node_test_predicate_selector_ut_4_node6, Condition);
		Condition_bt_node_test_predicate_selector_ut_4_node6()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_1, int >();
			int opr = -1;
			bool op = Details::Equal(opl, opr);
			return op ? BT_SUCCESS : BT_FAILURE;
		}
	};

	class Condition_bt_node_test_predicate_selector_ut_4_node7 : public Condition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Condition_bt_node_test_predicate_selector_ut_4_node7, Condition);
		Condition_bt_node_test_predicate_selector_ut_4_node7()
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

	class Action_bt_node_test_predicate_selector_ut_4_node5 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_selector_ut_4_node5, Action);
		Action_bt_node_test_predicate_selector_ut_4_node5()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, int >(method_p0);
			return BT_FAILURE;
		}
		int method_p0;
	};

	class Action_bt_node_test_predicate_selector_ut_4_node4 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_selector_ut_4_node4, Action);
		Action_bt_node_test_predicate_selector_ut_4_node4()
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

	class Action_bt_node_test_predicate_selector_ut_4_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_selector_ut_4_node2, Action);
		Action_bt_node_test_predicate_selector_ut_4_node2()
		{
			method_p0 = 0;
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

		bool bt_node_test_predicate_selector_ut_4::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("node_test/predicate_selector_ut_4");
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
					DecoratorNot_bt_node_test_predicate_selector_ut_4_node1* node1 = BEHAVIAC_NEW DecoratorNot_bt_node_test_predicate_selector_ut_4_node1;
					node1->SetClassNameString("DecoratorNot");
					node1->SetId(1);
#if !BEHAVIAC_RELEASE
					node1->SetAgentType("AgentNodeTest");
#endif
					node0->SetCustomCondition(node1);
					{
						Selector* node3 = BEHAVIAC_NEW Selector;
						node3->SetClassNameString("Selector");
						node3->SetId(3);
#if !BEHAVIAC_RELEASE
						node3->SetAgentType("AgentNodeTest");
#endif
						node1->AddChild(node3);
						{
							Condition_bt_node_test_predicate_selector_ut_4_node6* node6 = BEHAVIAC_NEW Condition_bt_node_test_predicate_selector_ut_4_node6;
							node6->SetClassNameString("Condition");
							node6->SetId(6);
#if !BEHAVIAC_RELEASE
							node6->SetAgentType("AgentNodeTest");
#endif
							node3->AddChild(node6);
							node3->SetHasEvents(node3->HasEvents() | node6->HasEvents());
						}
						{
							Condition_bt_node_test_predicate_selector_ut_4_node7* node7 = BEHAVIAC_NEW Condition_bt_node_test_predicate_selector_ut_4_node7;
							node7->SetClassNameString("Condition");
							node7->SetId(7);
#if !BEHAVIAC_RELEASE
							node7->SetAgentType("AgentNodeTest");
#endif
							node3->AddChild(node7);
							node3->SetHasEvents(node3->HasEvents() | node7->HasEvents());
						}
						node1->SetHasEvents(node1->HasEvents() | node3->HasEvents());
					}
					node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
				}
				{
					Action_bt_node_test_predicate_selector_ut_4_node5* node5 = BEHAVIAC_NEW Action_bt_node_test_predicate_selector_ut_4_node5;
					node5->SetClassNameString("Action");
					node5->SetId(5);
#if !BEHAVIAC_RELEASE
					node5->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node5);
					node0->SetHasEvents(node0->HasEvents() | node5->HasEvents());
				}
				{
					Action_bt_node_test_predicate_selector_ut_4_node4* node4 = BEHAVIAC_NEW Action_bt_node_test_predicate_selector_ut_4_node4;
					node4->SetClassNameString("Action");
					node4->SetId(4);
#if !BEHAVIAC_RELEASE
					node4->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node4);
					node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
				}
				{
					Action_bt_node_test_predicate_selector_ut_4_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_predicate_selector_ut_4_node2;
					node2->SetClassNameString("Action");
					node2->SetId(2);
#if !BEHAVIAC_RELEASE
					node2->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node2);
					node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
				}
				pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
			}
			return true;
		}

	// Source file: node_test/predicate_selector_ut_5

	class DecoratorNot_bt_node_test_predicate_selector_ut_5_node1 : public DecoratorNot
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorNot_bt_node_test_predicate_selector_ut_5_node1, DecoratorNot);
		DecoratorNot_bt_node_test_predicate_selector_ut_5_node1()
		{
			m_bDecorateWhenChildEnds = false;
		}
	protected:
	};

	class Condition_bt_node_test_predicate_selector_ut_5_node8 : public Condition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Condition_bt_node_test_predicate_selector_ut_5_node8, Condition);
		Condition_bt_node_test_predicate_selector_ut_5_node8()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_1, int >();
			int opr = -1;
			bool op = Details::Equal(opl, opr);
			return op ? BT_SUCCESS : BT_FAILURE;
		}
	};

	class Condition_bt_node_test_predicate_selector_ut_5_node9 : public Condition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Condition_bt_node_test_predicate_selector_ut_5_node9, Condition);
		Condition_bt_node_test_predicate_selector_ut_5_node9()
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

	class Condition_bt_node_test_predicate_selector_ut_5_node10 : public Condition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Condition_bt_node_test_predicate_selector_ut_5_node10, Condition);
		Condition_bt_node_test_predicate_selector_ut_5_node10()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			float& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_2, float >();
			float opr = -1;
			bool op = Details::Equal(opl, opr);
			return op ? BT_SUCCESS : BT_FAILURE;
		}
	};

	class Action_bt_node_test_predicate_selector_ut_5_node5 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_selector_ut_5_node5, Action);
		Action_bt_node_test_predicate_selector_ut_5_node5()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, int >(method_p0);
			return BT_FAILURE;
		}
		int method_p0;
	};

	class Action_bt_node_test_predicate_selector_ut_5_node4 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_selector_ut_5_node4, Action);
		Action_bt_node_test_predicate_selector_ut_5_node4()
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

	class Action_bt_node_test_predicate_selector_ut_5_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_selector_ut_5_node2, Action);
		Action_bt_node_test_predicate_selector_ut_5_node2()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_2, void, float >(method_p0);
			return BT_FAILURE;
		}
		float method_p0;
	};

	class Action_bt_node_test_predicate_selector_ut_5_node7 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_selector_ut_5_node7, Action);
		Action_bt_node_test_predicate_selector_ut_5_node7()
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

		bool bt_node_test_predicate_selector_ut_5::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("node_test/predicate_selector_ut_5");
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
					DecoratorNot_bt_node_test_predicate_selector_ut_5_node1* node1 = BEHAVIAC_NEW DecoratorNot_bt_node_test_predicate_selector_ut_5_node1;
					node1->SetClassNameString("DecoratorNot");
					node1->SetId(1);
#if !BEHAVIAC_RELEASE
					node1->SetAgentType("AgentNodeTest");
#endif
					node0->SetCustomCondition(node1);
					{
						Selector* node3 = BEHAVIAC_NEW Selector;
						node3->SetClassNameString("Selector");
						node3->SetId(3);
#if !BEHAVIAC_RELEASE
						node3->SetAgentType("AgentNodeTest");
#endif
						node1->AddChild(node3);
						{
							Sequence* node6 = BEHAVIAC_NEW Sequence;
							node6->SetClassNameString("Sequence");
							node6->SetId(6);
#if !BEHAVIAC_RELEASE
							node6->SetAgentType("AgentNodeTest");
#endif
							node3->AddChild(node6);
							{
								Condition_bt_node_test_predicate_selector_ut_5_node8* node8 = BEHAVIAC_NEW Condition_bt_node_test_predicate_selector_ut_5_node8;
								node8->SetClassNameString("Condition");
								node8->SetId(8);
#if !BEHAVIAC_RELEASE
								node8->SetAgentType("AgentNodeTest");
#endif
								node6->AddChild(node8);
								node6->SetHasEvents(node6->HasEvents() | node8->HasEvents());
							}
							{
								Condition_bt_node_test_predicate_selector_ut_5_node9* node9 = BEHAVIAC_NEW Condition_bt_node_test_predicate_selector_ut_5_node9;
								node9->SetClassNameString("Condition");
								node9->SetId(9);
#if !BEHAVIAC_RELEASE
								node9->SetAgentType("AgentNodeTest");
#endif
								node6->AddChild(node9);
								node6->SetHasEvents(node6->HasEvents() | node9->HasEvents());
							}
							node3->SetHasEvents(node3->HasEvents() | node6->HasEvents());
						}
						{
							Condition_bt_node_test_predicate_selector_ut_5_node10* node10 = BEHAVIAC_NEW Condition_bt_node_test_predicate_selector_ut_5_node10;
							node10->SetClassNameString("Condition");
							node10->SetId(10);
#if !BEHAVIAC_RELEASE
							node10->SetAgentType("AgentNodeTest");
#endif
							node3->AddChild(node10);
							node3->SetHasEvents(node3->HasEvents() | node10->HasEvents());
						}
						node1->SetHasEvents(node1->HasEvents() | node3->HasEvents());
					}
					node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
				}
				{
					Action_bt_node_test_predicate_selector_ut_5_node5* node5 = BEHAVIAC_NEW Action_bt_node_test_predicate_selector_ut_5_node5;
					node5->SetClassNameString("Action");
					node5->SetId(5);
#if !BEHAVIAC_RELEASE
					node5->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node5);
					node0->SetHasEvents(node0->HasEvents() | node5->HasEvents());
				}
				{
					Action_bt_node_test_predicate_selector_ut_5_node4* node4 = BEHAVIAC_NEW Action_bt_node_test_predicate_selector_ut_5_node4;
					node4->SetClassNameString("Action");
					node4->SetId(4);
#if !BEHAVIAC_RELEASE
					node4->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node4);
					node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
				}
				{
					Action_bt_node_test_predicate_selector_ut_5_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_predicate_selector_ut_5_node2;
					node2->SetClassNameString("Action");
					node2->SetId(2);
#if !BEHAVIAC_RELEASE
					node2->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node2);
					node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
				}
				{
					Action_bt_node_test_predicate_selector_ut_5_node7* node7 = BEHAVIAC_NEW Action_bt_node_test_predicate_selector_ut_5_node7;
					node7->SetClassNameString("Action");
					node7->SetId(7);
#if !BEHAVIAC_RELEASE
					node7->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node7);
					node0->SetHasEvents(node0->HasEvents() | node7->HasEvents());
				}
				pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
			}
			return true;
		}

}
