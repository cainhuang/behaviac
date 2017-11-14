#include "generated_behaviors_9.h"

namespace behaviac
{
	// Source file: node_test/wait_ut_0

	class Action_bt_node_test_wait_ut_0_node1 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_wait_ut_0_node1, Action);
		Action_bt_node_test_wait_ut_0_node1()
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

	class Action_bt_node_test_wait_ut_0_node3 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_wait_ut_0_node3, Action);
		Action_bt_node_test_wait_ut_0_node3()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_initChildAgentTest, void >();
			return BT_SUCCESS;
		}
	};

	class Wait_bt_node_test_wait_ut_0_node2 : public Wait
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Wait_bt_node_test_wait_ut_0_node2, Wait);
		Wait_bt_node_test_wait_ut_0_node2()
		{
		}
	protected:
		virtual double GetTime(Agent* pAgent) const
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			Agent* pAgent_Time = Agent::GetInstance(pAgent, "par_child_agent_1");
			BEHAVIAC_ASSERT(pAgent_Time);
			return ((ChildNodeTest*)pAgent_Time)->_Execute_Method_<METHOD_TYPE_ChildNodeTest_GetConstDoubleValue, double >();
		}
	};

	class Action_bt_node_test_wait_ut_0_node4 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_wait_ut_0_node4, Action);
		Action_bt_node_test_wait_ut_0_node4()
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

		bool bt_node_test_wait_ut_0::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("node_test/wait_ut_0");
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
					Action_bt_node_test_wait_ut_0_node1* node1 = BEHAVIAC_NEW Action_bt_node_test_wait_ut_0_node1;
					node1->SetClassNameString("Action");
					node1->SetId(1);
#if !BEHAVIAC_RELEASE
					node1->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node1);
					node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
				}
				{
					Action_bt_node_test_wait_ut_0_node3* node3 = BEHAVIAC_NEW Action_bt_node_test_wait_ut_0_node3;
					node3->SetClassNameString("Action");
					node3->SetId(3);
#if !BEHAVIAC_RELEASE
					node3->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node3);
					node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
				}
				{
					Wait_bt_node_test_wait_ut_0_node2* node2 = BEHAVIAC_NEW Wait_bt_node_test_wait_ut_0_node2;
					node2->SetClassNameString("Wait");
					node2->SetId(2);
#if !BEHAVIAC_RELEASE
					node2->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node2);
					node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
				}
				{
					Action_bt_node_test_wait_ut_0_node4* node4 = BEHAVIAC_NEW Action_bt_node_test_wait_ut_0_node4;
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

	// Source file: node_test/wait_ut_1

	class Action_bt_node_test_wait_ut_1_node1 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_wait_ut_1_node1, Action);
		Action_bt_node_test_wait_ut_1_node1()
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

	class Wait_bt_node_test_wait_ut_1_node2 : public Wait
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Wait_bt_node_test_wait_ut_1_node2, Wait);
		Wait_bt_node_test_wait_ut_1_node2()
		{
		}
	protected:
		virtual double GetTime(Agent* pAgent) const
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			return 1000;
		}
	};

	class Action_bt_node_test_wait_ut_1_node3 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_wait_ut_1_node3, Action);
		Action_bt_node_test_wait_ut_1_node3()
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

		bool bt_node_test_wait_ut_1::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("node_test/wait_ut_1");
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
					Action_bt_node_test_wait_ut_1_node1* node1 = BEHAVIAC_NEW Action_bt_node_test_wait_ut_1_node1;
					node1->SetClassNameString("Action");
					node1->SetId(1);
#if !BEHAVIAC_RELEASE
					node1->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node1);
					node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
				}
				{
					Wait_bt_node_test_wait_ut_1_node2* node2 = BEHAVIAC_NEW Wait_bt_node_test_wait_ut_1_node2;
					node2->SetClassNameString("Wait");
					node2->SetId(2);
#if !BEHAVIAC_RELEASE
					node2->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node2);
					node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
				}
				{
					Action_bt_node_test_wait_ut_1_node3* node3 = BEHAVIAC_NEW Action_bt_node_test_wait_ut_1_node3;
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

	// Source file: node_test/wait_ut_2

	class Assignment_bt_node_test_wait_ut_2_node5 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_node_test_wait_ut_2_node5, Assignment);
		Assignment_bt_node_test_wait_ut_2_node5()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			int opr = 1;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("l_IntVar") == 1949893163u);
			pAgent->SetVariable("l_IntVar", opr, 1949893163u);
			return result;
		}
	};

	class Precondition_bt_node_test_wait_ut_2_attach6 : public Precondition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Precondition_bt_node_test_wait_ut_2_attach6, Precondition);
		Precondition_bt_node_test_wait_ut_2_attach6()
		{
			this->SetPhase(Precondition::E_BOTH);
			this->SetIsAnd(true);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("l_IntVar") == 1949893163u);
			int& opl = (int&)pAgent->GetVariable<int >(1949893163u);
			int opr2 = 1;
			bool op = Details::Equal(opl, opr2);
			if (!op)
				result = BT_FAILURE;
			return result;
		}
	};

	class Action_bt_node_test_wait_ut_2_node1 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_wait_ut_2_node1, Action);
		Action_bt_node_test_wait_ut_2_node1()
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

	class Wait_bt_node_test_wait_ut_2_node2 : public Wait
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Wait_bt_node_test_wait_ut_2_node2, Wait);
		Wait_bt_node_test_wait_ut_2_node2()
		{
		}
	protected:
		virtual double GetTime(Agent* pAgent) const
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			return 1000;
		}
	};

	class Assignment_bt_node_test_wait_ut_2_node8 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_node_test_wait_ut_2_node8, Assignment);
		Assignment_bt_node_test_wait_ut_2_node8()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			int opr = 2;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("l_IntVar") == 1949893163u);
			pAgent->SetVariable("l_IntVar", opr, 1949893163u);
			return result;
		}
	};

	class Wait_bt_node_test_wait_ut_2_node7 : public Wait
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Wait_bt_node_test_wait_ut_2_node7, Wait);
		Wait_bt_node_test_wait_ut_2_node7()
		{
		}
	protected:
		virtual double GetTime(Agent* pAgent) const
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			return 1000;
		}
	};

	class Action_bt_node_test_wait_ut_2_node3 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_wait_ut_2_node3, Action);
		Action_bt_node_test_wait_ut_2_node3()
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

		bool bt_node_test_wait_ut_2::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("node_test/wait_ut_2");
			pBT->SetIsFSM(false);
#if !BEHAVIAC_RELEASE
			pBT->SetAgentType("AgentNodeTest");
#endif
			// pars
			pBT->AddPar("AgentNodeTest", "int", "l_IntVar", "0");
			// children
			{
				Sequence* node4 = BEHAVIAC_NEW Sequence;
				node4->SetClassNameString("Sequence");
				node4->SetId(4);
#if !BEHAVIAC_RELEASE
				node4->SetAgentType("AgentNodeTest");
#endif
				pBT->AddChild(node4);
				{
					Assignment_bt_node_test_wait_ut_2_node5* node5 = BEHAVIAC_NEW Assignment_bt_node_test_wait_ut_2_node5;
					node5->SetClassNameString("Assignment");
					node5->SetId(5);
#if !BEHAVIAC_RELEASE
					node5->SetAgentType("AgentNodeTest");
#endif
					node4->AddChild(node5);
					node4->SetHasEvents(node4->HasEvents() | node5->HasEvents());
				}
				{
					Sequence* node0 = BEHAVIAC_NEW Sequence;
					node0->SetClassNameString("Sequence");
					node0->SetId(0);
#if !BEHAVIAC_RELEASE
					node0->SetAgentType("AgentNodeTest");
#endif
					// attachments
					{
						Precondition_bt_node_test_wait_ut_2_attach6* attach6 = BEHAVIAC_NEW Precondition_bt_node_test_wait_ut_2_attach6;
						attach6->SetClassNameString("Precondition");
						attach6->SetId(6);
#if !BEHAVIAC_RELEASE
						attach6->SetAgentType("AgentNodeTest");
#endif
						node0->Attach(attach6, true, false, false);
						node0->SetHasEvents(node0->HasEvents() | (Event::DynamicCast(attach6) != 0));
					}
					node4->AddChild(node0);
					{
						Action_bt_node_test_wait_ut_2_node1* node1 = BEHAVIAC_NEW Action_bt_node_test_wait_ut_2_node1;
						node1->SetClassNameString("Action");
						node1->SetId(1);
#if !BEHAVIAC_RELEASE
						node1->SetAgentType("AgentNodeTest");
#endif
						node0->AddChild(node1);
						node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
					}
					{
						Wait_bt_node_test_wait_ut_2_node2* node2 = BEHAVIAC_NEW Wait_bt_node_test_wait_ut_2_node2;
						node2->SetClassNameString("Wait");
						node2->SetId(2);
#if !BEHAVIAC_RELEASE
						node2->SetAgentType("AgentNodeTest");
#endif
						node0->AddChild(node2);
						node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
					}
					{
						Assignment_bt_node_test_wait_ut_2_node8* node8 = BEHAVIAC_NEW Assignment_bt_node_test_wait_ut_2_node8;
						node8->SetClassNameString("Assignment");
						node8->SetId(8);
#if !BEHAVIAC_RELEASE
						node8->SetAgentType("AgentNodeTest");
#endif
						node0->AddChild(node8);
						node0->SetHasEvents(node0->HasEvents() | node8->HasEvents());
					}
					{
						Wait_bt_node_test_wait_ut_2_node7* node7 = BEHAVIAC_NEW Wait_bt_node_test_wait_ut_2_node7;
						node7->SetClassNameString("Wait");
						node7->SetId(7);
#if !BEHAVIAC_RELEASE
						node7->SetAgentType("AgentNodeTest");
#endif
						node0->AddChild(node7);
						node0->SetHasEvents(node0->HasEvents() | node7->HasEvents());
					}
					{
						Action_bt_node_test_wait_ut_2_node3* node3 = BEHAVIAC_NEW Action_bt_node_test_wait_ut_2_node3;
						node3->SetClassNameString("Action");
						node3->SetId(3);
#if !BEHAVIAC_RELEASE
						node3->SetAgentType("AgentNodeTest");
#endif
						node0->AddChild(node3);
						node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
					}
					node4->SetHasEvents(node4->HasEvents() | node0->HasEvents());
				}
				pBT->SetHasEvents(pBT->HasEvents() | node4->HasEvents());
			}
			return true;
		}

	// Source file: par_test/cast_param

	class Assignment_bt_par_test_cast_param_node1 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_cast_param_node1, Assignment);
		Assignment_bt_par_test_cast_param_node1()
		{
			opr_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			float opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_SingleIR, float, float >(opr_p0);
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_BYTE_0, unsigned char >() = (unsigned char)opr;
			return result;
		}
		float opr_p0;
	};

	class Assignment_bt_par_test_cast_param_node0 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_cast_param_node0, Assignment);
		Assignment_bt_par_test_cast_param_node0()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			unsigned int opr = ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_UINT_0, unsigned int >();
			((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_SHORT_0, short >() = (short)opr;
			return result;
		}
	};

	class Assignment_bt_par_test_cast_param_node2 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_cast_param_node2, Assignment);
		Assignment_bt_par_test_cast_param_node2()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("C_Agent") == 2630010392u);
			ParTestAgent*& opr = (ParTestAgent*&)pAgent->GetVariable<ParTestAgent* >(2630010392u);
			((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_AGENT_0, behaviac::Agent* >() = (behaviac::Agent*)opr;
			return result;
		}
	};

		bool bt_par_test_cast_param::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("par_test/cast_param");
			pBT->SetIsFSM(false);
#if !BEHAVIAC_RELEASE
			pBT->SetAgentType("EmployeeParTestAgent");
#endif
			// children
			{
				Sequence* node22 = BEHAVIAC_NEW Sequence;
				node22->SetClassNameString("Sequence");
				node22->SetId(22);
#if !BEHAVIAC_RELEASE
				node22->SetAgentType("EmployeeParTestAgent");
#endif
				pBT->AddChild(node22);
				{
					Assignment_bt_par_test_cast_param_node1* node1 = BEHAVIAC_NEW Assignment_bt_par_test_cast_param_node1;
					node1->SetClassNameString("Assignment");
					node1->SetId(1);
#if !BEHAVIAC_RELEASE
					node1->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node1);
					node22->SetHasEvents(node22->HasEvents() | node1->HasEvents());
				}
				{
					Assignment_bt_par_test_cast_param_node0* node0 = BEHAVIAC_NEW Assignment_bt_par_test_cast_param_node0;
					node0->SetClassNameString("Assignment");
					node0->SetId(0);
#if !BEHAVIAC_RELEASE
					node0->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node0);
					node22->SetHasEvents(node22->HasEvents() | node0->HasEvents());
				}
				{
					Assignment_bt_par_test_cast_param_node2* node2 = BEHAVIAC_NEW Assignment_bt_par_test_cast_param_node2;
					node2->SetClassNameString("Assignment");
					node2->SetId(2);
#if !BEHAVIAC_RELEASE
					node2->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node2);
					node22->SetHasEvents(node22->HasEvents() | node2->HasEvents());
				}
				pBT->SetHasEvents(pBT->HasEvents() | node22->HasEvents());
			}
			return true;
		}

	// Source file: par_test/const_param

	class Assignment_bt_par_test_const_param_node0 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_const_param_node0, Assignment);
		Assignment_bt_par_test_const_param_node0()
		{
			opr_p0 = true;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			bool opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_BooleanIR, bool, bool >(opr_p0);
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_BOOL_0, bool >() = opr;
			return result;
		}
		bool opr_p0;
	};

	class Assignment_bt_par_test_const_param_node1 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_const_param_node1, Assignment);
		Assignment_bt_par_test_const_param_node1()
		{
			opr_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			unsigned char opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_ByteIR, unsigned char, unsigned char >(opr_p0);
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_BYTE_0, unsigned char >() = opr;
			return result;
		}
		unsigned char opr_p0;
	};

	class Assignment_bt_par_test_const_param_node2 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_const_param_node2, Assignment);
		Assignment_bt_par_test_const_param_node2()
		{
			opr_p0.reserve(2);
			bool opr_p0_item0 = true;
			opr_p0.push_back(opr_p0_item0);
			bool opr_p0_item1 = true;
			opr_p0.push_back(opr_p0_item1);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			behaviac::vector<bool> opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_BooleanListIR, behaviac::vector<bool>, behaviac::vector<bool> >(opr_p0);
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_BOOL_0, behaviac::vector<bool> >() = opr;
			return result;
		}
		behaviac::vector<bool> opr_p0;
	};

		bool bt_par_test_const_param::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("par_test/const_param");
			pBT->SetIsFSM(false);
#if !BEHAVIAC_RELEASE
			pBT->SetAgentType("EmployeeParTestAgent");
#endif
			// children
			{
				Sequence* node22 = BEHAVIAC_NEW Sequence;
				node22->SetClassNameString("Sequence");
				node22->SetId(22);
#if !BEHAVIAC_RELEASE
				node22->SetAgentType("EmployeeParTestAgent");
#endif
				pBT->AddChild(node22);
				{
					Assignment_bt_par_test_const_param_node0* node0 = BEHAVIAC_NEW Assignment_bt_par_test_const_param_node0;
					node0->SetClassNameString("Assignment");
					node0->SetId(0);
#if !BEHAVIAC_RELEASE
					node0->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node0);
					node22->SetHasEvents(node22->HasEvents() | node0->HasEvents());
				}
				{
					Assignment_bt_par_test_const_param_node1* node1 = BEHAVIAC_NEW Assignment_bt_par_test_const_param_node1;
					node1->SetClassNameString("Assignment");
					node1->SetId(1);
#if !BEHAVIAC_RELEASE
					node1->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node1);
					node22->SetHasEvents(node22->HasEvents() | node1->HasEvents());
				}
				{
					Assignment_bt_par_test_const_param_node2* node2 = BEHAVIAC_NEW Assignment_bt_par_test_const_param_node2;
					node2->SetClassNameString("Assignment");
					node2->SetId(2);
#if !BEHAVIAC_RELEASE
					node2->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node2);
					node22->SetHasEvents(node22->HasEvents() | node2->HasEvents());
				}
				pBT->SetHasEvents(pBT->HasEvents() | node22->HasEvents());
			}
			return true;
		}

	// Source file: par_test/custom_property_as_left_value_and_param

	class Assignment_bt_par_test_custom_property_as_left_value_and_param_node0 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_custom_property_as_left_value_and_param_node0, Assignment);
		Assignment_bt_par_test_custom_property_as_left_value_and_param_node0()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			bool opr = true;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("c_Bool") == 130231588u);
			pAgent->SetVariable("c_Bool", opr, 130231588u);
			return result;
		}
	};

	class Assignment_bt_par_test_custom_property_as_left_value_and_param_node1 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_custom_property_as_left_value_and_param_node1, Assignment);
		Assignment_bt_par_test_custom_property_as_left_value_and_param_node1()
		{
			opr.reserve(2);
			int opr_item0 = 1;
			opr.push_back(opr_item0);
			int opr_item1 = 2;
			opr.push_back(opr_item1);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("c_IntArray") == 1799035077u);
			pAgent->SetVariable("c_IntArray", opr, 1799035077u);
			return result;
		}
		behaviac::vector<int> opr;
	};

	class Assignment_bt_par_test_custom_property_as_left_value_and_param_node2 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_custom_property_as_left_value_and_param_node2, Assignment);
		Assignment_bt_par_test_custom_property_as_left_value_and_param_node2()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			behaviac::string opr = (char*)("test string");
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("c_StaticString") == 2438934774u);
			pAgent->SetVariable("c_StaticString", opr, 2438934774u);
			return result;
		}
	};

	class Assignment_bt_par_test_custom_property_as_left_value_and_param_node3 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_custom_property_as_left_value_and_param_node3, Assignment);
		Assignment_bt_par_test_custom_property_as_left_value_and_param_node3()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			TNS::NE::NAT::eColor opr = TNS::NE::NAT::GREEN;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("c_Enum") == 99975606u);
			pAgent->SetVariable("c_Enum", opr, 99975606u);
			return result;
		}
	};

	class Assignment_bt_par_test_custom_property_as_left_value_and_param_node4 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_custom_property_as_left_value_and_param_node4, Assignment);
		Assignment_bt_par_test_custom_property_as_left_value_and_param_node4()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			int opr = 2;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("l_Int") == 337932423u);
			pAgent->SetVariable("l_Int", opr, 337932423u);
			return result;
		}
	};

	class Assignment_bt_par_test_custom_property_as_left_value_and_param_node11 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_custom_property_as_left_value_and_param_node11, Assignment);
		Assignment_bt_par_test_custom_property_as_left_value_and_param_node11()
		{
			opr.x = 1;
			opr.y = 1;
			opr.z = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			((CustomPropertyAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_CustomPropertyAgent_Location, UnityEngine::Vector3 >() = opr;
			return result;
		}
		UnityEngine::Vector3 opr;
	};

	class Assignment_bt_par_test_custom_property_as_left_value_and_param_node8 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_custom_property_as_left_value_and_param_node8, Assignment);
		Assignment_bt_par_test_custom_property_as_left_value_and_param_node8()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			UnityEngine::Vector3 opr = ((CustomPropertyAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_CustomPropertyAgent_Location, UnityEngine::Vector3 >();
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("c_Location") == 1335260864u);
			pAgent->SetVariable("c_Location", opr, 1335260864u);
			return result;
		}
	};

	class Assignment_bt_par_test_custom_property_as_left_value_and_param_node9 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_custom_property_as_left_value_and_param_node9, Assignment);
		Assignment_bt_par_test_custom_property_as_left_value_and_param_node9()
		{
			opr.x = 2;
			opr.y = 2;
			opr.z = 2;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("l_Location") == 3698229766u);
			pAgent->SetVariable("l_Location", opr, 3698229766u);
			return result;
		}
		UnityEngine::Vector3 opr;
	};

	class Assignment_bt_par_test_custom_property_as_left_value_and_param_node10 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_custom_property_as_left_value_and_param_node10, Assignment);
		Assignment_bt_par_test_custom_property_as_left_value_and_param_node10()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("l_Location") == 3698229766u);
			UnityEngine::Vector3& opr = (UnityEngine::Vector3&)pAgent->GetVariable<UnityEngine::Vector3 >(3698229766u);
			((CustomPropertyAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_CustomPropertyAgent_Location, UnityEngine::Vector3 >() = opr;
			return result;
		}
	};

	class DecoratorLoop_bt_par_test_custom_property_as_left_value_and_param_node6 : public DecoratorLoop
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorLoop_bt_par_test_custom_property_as_left_value_and_param_node6, DecoratorLoop);
		DecoratorLoop_bt_par_test_custom_property_as_left_value_and_param_node6()
		{
			m_bDecorateWhenChildEnds = true;
			m_bDoneWithinFrame = false;
		}
	protected:
		virtual int GetCount(Agent* pAgent) const
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			return -1;
		}
	};

		bool bt_par_test_custom_property_as_left_value_and_param::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("par_test/custom_property_as_left_value_and_param");
			pBT->SetIsFSM(false);
#if !BEHAVIAC_RELEASE
			pBT->SetAgentType("CustomPropertyAgent");
#endif
			// pars
			pBT->AddPar("CustomPropertyAgent", "int", "l_Int", "1");
			pBT->AddPar("CustomPropertyAgent", "UnityEngine::Vector3", "l_Location", "{x=0;y=0;z=0;}");
			// children
			{
				Sequence* node5 = BEHAVIAC_NEW Sequence;
				node5->SetClassNameString("Sequence");
				node5->SetId(5);
#if !BEHAVIAC_RELEASE
				node5->SetAgentType("CustomPropertyAgent");
#endif
				pBT->AddChild(node5);
				{
					Sequence* node13 = BEHAVIAC_NEW Sequence;
					node13->SetClassNameString("Sequence");
					node13->SetId(13);
#if !BEHAVIAC_RELEASE
					node13->SetAgentType("CustomPropertyAgent");
#endif
					node5->AddChild(node13);
					{
						Assignment_bt_par_test_custom_property_as_left_value_and_param_node0* node0 = BEHAVIAC_NEW Assignment_bt_par_test_custom_property_as_left_value_and_param_node0;
						node0->SetClassNameString("Assignment");
						node0->SetId(0);
#if !BEHAVIAC_RELEASE
						node0->SetAgentType("CustomPropertyAgent");
#endif
						node13->AddChild(node0);
						node13->SetHasEvents(node13->HasEvents() | node0->HasEvents());
					}
					{
						Assignment_bt_par_test_custom_property_as_left_value_and_param_node1* node1 = BEHAVIAC_NEW Assignment_bt_par_test_custom_property_as_left_value_and_param_node1;
						node1->SetClassNameString("Assignment");
						node1->SetId(1);
#if !BEHAVIAC_RELEASE
						node1->SetAgentType("CustomPropertyAgent");
#endif
						node13->AddChild(node1);
						node13->SetHasEvents(node13->HasEvents() | node1->HasEvents());
					}
					{
						Assignment_bt_par_test_custom_property_as_left_value_and_param_node2* node2 = BEHAVIAC_NEW Assignment_bt_par_test_custom_property_as_left_value_and_param_node2;
						node2->SetClassNameString("Assignment");
						node2->SetId(2);
#if !BEHAVIAC_RELEASE
						node2->SetAgentType("CustomPropertyAgent");
#endif
						node13->AddChild(node2);
						node13->SetHasEvents(node13->HasEvents() | node2->HasEvents());
					}
					{
						Assignment_bt_par_test_custom_property_as_left_value_and_param_node3* node3 = BEHAVIAC_NEW Assignment_bt_par_test_custom_property_as_left_value_and_param_node3;
						node3->SetClassNameString("Assignment");
						node3->SetId(3);
#if !BEHAVIAC_RELEASE
						node3->SetAgentType("CustomPropertyAgent");
#endif
						node13->AddChild(node3);
						node13->SetHasEvents(node13->HasEvents() | node3->HasEvents());
					}
					{
						Assignment_bt_par_test_custom_property_as_left_value_and_param_node4* node4 = BEHAVIAC_NEW Assignment_bt_par_test_custom_property_as_left_value_and_param_node4;
						node4->SetClassNameString("Assignment");
						node4->SetId(4);
#if !BEHAVIAC_RELEASE
						node4->SetAgentType("CustomPropertyAgent");
#endif
						node13->AddChild(node4);
						node13->SetHasEvents(node13->HasEvents() | node4->HasEvents());
					}
					{
						Assignment_bt_par_test_custom_property_as_left_value_and_param_node11* node11 = BEHAVIAC_NEW Assignment_bt_par_test_custom_property_as_left_value_and_param_node11;
						node11->SetClassNameString("Assignment");
						node11->SetId(11);
#if !BEHAVIAC_RELEASE
						node11->SetAgentType("CustomPropertyAgent");
#endif
						node13->AddChild(node11);
						node13->SetHasEvents(node13->HasEvents() | node11->HasEvents());
					}
					{
						Assignment_bt_par_test_custom_property_as_left_value_and_param_node8* node8 = BEHAVIAC_NEW Assignment_bt_par_test_custom_property_as_left_value_and_param_node8;
						node8->SetClassNameString("Assignment");
						node8->SetId(8);
#if !BEHAVIAC_RELEASE
						node8->SetAgentType("CustomPropertyAgent");
#endif
						node13->AddChild(node8);
						node13->SetHasEvents(node13->HasEvents() | node8->HasEvents());
					}
					{
						Assignment_bt_par_test_custom_property_as_left_value_and_param_node9* node9 = BEHAVIAC_NEW Assignment_bt_par_test_custom_property_as_left_value_and_param_node9;
						node9->SetClassNameString("Assignment");
						node9->SetId(9);
#if !BEHAVIAC_RELEASE
						node9->SetAgentType("CustomPropertyAgent");
#endif
						node13->AddChild(node9);
						node13->SetHasEvents(node13->HasEvents() | node9->HasEvents());
					}
					{
						Assignment_bt_par_test_custom_property_as_left_value_and_param_node10* node10 = BEHAVIAC_NEW Assignment_bt_par_test_custom_property_as_left_value_and_param_node10;
						node10->SetClassNameString("Assignment");
						node10->SetId(10);
#if !BEHAVIAC_RELEASE
						node10->SetAgentType("CustomPropertyAgent");
#endif
						node13->AddChild(node10);
						node13->SetHasEvents(node13->HasEvents() | node10->HasEvents());
					}
					node5->SetHasEvents(node5->HasEvents() | node13->HasEvents());
				}
				{
					DecoratorLoop_bt_par_test_custom_property_as_left_value_and_param_node6* node6 = BEHAVIAC_NEW DecoratorLoop_bt_par_test_custom_property_as_left_value_and_param_node6;
					node6->SetClassNameString("DecoratorLoop");
					node6->SetId(6);
#if !BEHAVIAC_RELEASE
					node6->SetAgentType("CustomPropertyAgent");
#endif
					node5->AddChild(node6);
					{
						Noop* node7 = BEHAVIAC_NEW Noop;
						node7->SetClassNameString("Noop");
						node7->SetId(7);
#if !BEHAVIAC_RELEASE
						node7->SetAgentType("CustomPropertyAgent");
#endif
						node6->AddChild(node7);
						node6->SetHasEvents(node6->HasEvents() | node7->HasEvents());
					}
					node5->SetHasEvents(node5->HasEvents() | node6->HasEvents());
				}
				pBT->SetHasEvents(pBT->HasEvents() | node5->HasEvents());
			}
			return true;
		}

	// Source file: par_test/custom_property_reset

	class Action_bt_par_test_custom_property_reset_node1 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_custom_property_reset_node1, Action);
		Action_bt_par_test_custom_property_reset_node1()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("testInt") == 2614050066u);
			int& method_p0 = (int&)pAgent->GetVariable<int >(2614050066u);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_1, void, int >(method_p0);
			return BT_SUCCESS;
		}
	};

	class Assignment_bt_par_test_custom_property_reset_node0 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_custom_property_reset_node0, Assignment);
		Assignment_bt_par_test_custom_property_reset_node0()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			int opr = 20;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("testInt") == 2614050066u);
			pAgent->SetVariable("testInt", opr, 2614050066u);
			return result;
		}
	};

		bool bt_par_test_custom_property_reset::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("par_test/custom_property_reset");
			pBT->SetIsFSM(false);
#if !BEHAVIAC_RELEASE
			pBT->SetAgentType("AgentNodeTest");
#endif
			// pars
			pBT->AddPar("AgentNodeTest", "int", "l_Int", "1");
			pBT->AddPar("AgentNodeTest", "UnityEngine::Vector3", "l_Location", "{x=0;y=0;z=0;}");
			// children
			{
				Sequence* node5 = BEHAVIAC_NEW Sequence;
				node5->SetClassNameString("Sequence");
				node5->SetId(5);
#if !BEHAVIAC_RELEASE
				node5->SetAgentType("AgentNodeTest");
#endif
				pBT->AddChild(node5);
				{
					Action_bt_par_test_custom_property_reset_node1* node1 = BEHAVIAC_NEW Action_bt_par_test_custom_property_reset_node1;
					node1->SetClassNameString("Action");
					node1->SetId(1);
#if !BEHAVIAC_RELEASE
					node1->SetAgentType("AgentNodeTest");
#endif
					node5->AddChild(node1);
					node5->SetHasEvents(node5->HasEvents() | node1->HasEvents());
				}
				{
					Assignment_bt_par_test_custom_property_reset_node0* node0 = BEHAVIAC_NEW Assignment_bt_par_test_custom_property_reset_node0;
					node0->SetClassNameString("Assignment");
					node0->SetId(0);
#if !BEHAVIAC_RELEASE
					node0->SetAgentType("AgentNodeTest");
#endif
					node5->AddChild(node0);
					node5->SetHasEvents(node5->HasEvents() | node0->HasEvents());
				}
				pBT->SetHasEvents(pBT->HasEvents() | node5->HasEvents());
			}
			return true;
		}

	// Source file: par_test/local_out_scope

	class Assignment_bt_par_test_local_out_scope_node0 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_local_out_scope_node0, Assignment);
		Assignment_bt_par_test_local_out_scope_node0()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			bool opr = true;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("c_Bool") == 130231588u);
			pAgent->SetVariable("c_Bool", opr, 130231588u);
			return result;
		}
	};

	class Assignment_bt_par_test_local_out_scope_node1 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_local_out_scope_node1, Assignment);
		Assignment_bt_par_test_local_out_scope_node1()
		{
			opr.reserve(2);
			int opr_item0 = 1;
			opr.push_back(opr_item0);
			int opr_item1 = 2;
			opr.push_back(opr_item1);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("c_IntArray") == 1799035077u);
			pAgent->SetVariable("c_IntArray", opr, 1799035077u);
			return result;
		}
		behaviac::vector<int> opr;
	};

	class Assignment_bt_par_test_local_out_scope_node2 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_local_out_scope_node2, Assignment);
		Assignment_bt_par_test_local_out_scope_node2()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			behaviac::string opr = (char*)("test string");
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("c_StaticString") == 2438934774u);
			pAgent->SetVariable("c_StaticString", opr, 2438934774u);
			return result;
		}
	};

	class Assignment_bt_par_test_local_out_scope_node3 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_local_out_scope_node3, Assignment);
		Assignment_bt_par_test_local_out_scope_node3()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			TNS::NE::NAT::eColor opr = TNS::NE::NAT::GREEN;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("c_Enum") == 99975606u);
			pAgent->SetVariable("c_Enum", opr, 99975606u);
			return result;
		}
	};

	class DecoratorLoop_bt_par_test_local_out_scope_node6 : public DecoratorLoop
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorLoop_bt_par_test_local_out_scope_node6, DecoratorLoop);
		DecoratorLoop_bt_par_test_local_out_scope_node6()
		{
			m_bDecorateWhenChildEnds = true;
			m_bDoneWithinFrame = false;
		}
	protected:
		virtual int GetCount(Agent* pAgent) const
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			return 2;
		}
	};

		bool bt_par_test_local_out_scope::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("par_test/local_out_scope");
			pBT->SetIsFSM(false);
#if !BEHAVIAC_RELEASE
			pBT->SetAgentType("CustomPropertyAgent");
#endif
			// pars
			pBT->AddPar("CustomPropertyAgent", "vector<int>", "l_IntArray", "2:2|3");
			// children
			{
				Sequence* node5 = BEHAVIAC_NEW Sequence;
				node5->SetClassNameString("Sequence");
				node5->SetId(5);
#if !BEHAVIAC_RELEASE
				node5->SetAgentType("CustomPropertyAgent");
#endif
				pBT->AddChild(node5);
				{
					Sequence* node13 = BEHAVIAC_NEW Sequence;
					node13->SetClassNameString("Sequence");
					node13->SetId(13);
#if !BEHAVIAC_RELEASE
					node13->SetAgentType("CustomPropertyAgent");
#endif
					node5->AddChild(node13);
					{
						Assignment_bt_par_test_local_out_scope_node0* node0 = BEHAVIAC_NEW Assignment_bt_par_test_local_out_scope_node0;
						node0->SetClassNameString("Assignment");
						node0->SetId(0);
#if !BEHAVIAC_RELEASE
						node0->SetAgentType("CustomPropertyAgent");
#endif
						node13->AddChild(node0);
						node13->SetHasEvents(node13->HasEvents() | node0->HasEvents());
					}
					{
						Assignment_bt_par_test_local_out_scope_node1* node1 = BEHAVIAC_NEW Assignment_bt_par_test_local_out_scope_node1;
						node1->SetClassNameString("Assignment");
						node1->SetId(1);
#if !BEHAVIAC_RELEASE
						node1->SetAgentType("CustomPropertyAgent");
#endif
						node13->AddChild(node1);
						node13->SetHasEvents(node13->HasEvents() | node1->HasEvents());
					}
					{
						Assignment_bt_par_test_local_out_scope_node2* node2 = BEHAVIAC_NEW Assignment_bt_par_test_local_out_scope_node2;
						node2->SetClassNameString("Assignment");
						node2->SetId(2);
#if !BEHAVIAC_RELEASE
						node2->SetAgentType("CustomPropertyAgent");
#endif
						node13->AddChild(node2);
						node13->SetHasEvents(node13->HasEvents() | node2->HasEvents());
					}
					{
						Assignment_bt_par_test_local_out_scope_node3* node3 = BEHAVIAC_NEW Assignment_bt_par_test_local_out_scope_node3;
						node3->SetClassNameString("Assignment");
						node3->SetId(3);
#if !BEHAVIAC_RELEASE
						node3->SetAgentType("CustomPropertyAgent");
#endif
						node13->AddChild(node3);
						node13->SetHasEvents(node13->HasEvents() | node3->HasEvents());
					}
					node5->SetHasEvents(node5->HasEvents() | node13->HasEvents());
				}
				{
					DecoratorLoop_bt_par_test_local_out_scope_node6* node6 = BEHAVIAC_NEW DecoratorLoop_bt_par_test_local_out_scope_node6;
					node6->SetClassNameString("DecoratorLoop");
					node6->SetId(6);
#if !BEHAVIAC_RELEASE
					node6->SetAgentType("CustomPropertyAgent");
#endif
					node5->AddChild(node6);
					{
						Noop* node7 = BEHAVIAC_NEW Noop;
						node7->SetClassNameString("Noop");
						node7->SetId(7);
#if !BEHAVIAC_RELEASE
						node7->SetAgentType("CustomPropertyAgent");
#endif
						node6->AddChild(node7);
						node6->SetHasEvents(node6->HasEvents() | node7->HasEvents());
					}
					node5->SetHasEvents(node5->HasEvents() | node6->HasEvents());
				}
				pBT->SetHasEvents(pBT->HasEvents() | node5->HasEvents());
			}
			return true;
		}

	// Source file: par_test/par_as_left_value_and_param

	class Assignment_bt_par_test_par_as_left_value_and_param_node0 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node0, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node0()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_agent_0") == 3876418331u);
			behaviac::Agent*& opr_p0 = (behaviac::Agent*&)pAgent->GetVariable<behaviac::Agent* >(3876418331u);
			behaviac::Agent* opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_AgentIR, behaviac::Agent*, behaviac::Agent* >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_agent_0") == 3876418331u);
			pAgent->SetVariable("par2_agent_0", opr, 3876418331u);
			return result;
		}
	};

	class Assignment_bt_par_test_par_as_left_value_and_param_node30 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node30, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node30()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_ParTestAgentBase_0") == 2489994139u);
			ParTestAgentBase*& opr_p0 = (ParTestAgentBase*&)pAgent->GetVariable<ParTestAgentBase* >(2489994139u);
			ParTestAgentBase* opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_ParTestAgentBaseIR, ParTestAgentBase*, ParTestAgentBase* >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_ParTestAgentBase_0") == 2489994139u);
			pAgent->SetVariable("par2_ParTestAgentBase_0", opr, 2489994139u);
			return result;
		}
	};

	class Assignment_bt_par_test_par_as_left_value_and_param_node15 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node15, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node15()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_agent_list_0") == 1126732011u);
			behaviac::vector<behaviac::Agent*>& opr_p0 = (behaviac::vector<behaviac::Agent*>&)pAgent->GetVariable<behaviac::vector<behaviac::Agent*> >(1126732011u);
			behaviac::vector<behaviac::Agent*> opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_AgentListIR, behaviac::vector<behaviac::Agent*>, behaviac::vector<behaviac::Agent*> >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_agent_list_0") == 1126732011u);
			pAgent->SetVariable("par2_agent_list_0", opr, 1126732011u);
			return result;
		}
	};

	class Assignment_bt_par_test_par_as_left_value_and_param_node31 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node31, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node31()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_ParTestAgentBaseList_0") == 3110436684u);
			behaviac::vector<ParTestAgentBase*>& opr_p0 = (behaviac::vector<ParTestAgentBase*>&)pAgent->GetVariable<behaviac::vector<ParTestAgentBase*> >(3110436684u);
			behaviac::vector<ParTestAgentBase*> opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_ParTestAgentBaseListIR, behaviac::vector<ParTestAgentBase*>, behaviac::vector<ParTestAgentBase*> >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_ParTestAgentBaseList_0") == 3110436684u);
			pAgent->SetVariable("par2_ParTestAgentBaseList_0", opr, 3110436684u);
			return result;
		}
	};

	class Assignment_bt_par_test_par_as_left_value_and_param_node2 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node2, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node2()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_double_0") == 2183367433u);
			double& opr_p0 = (double&)pAgent->GetVariable<double >(2183367433u);
			double opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_DoubleIR, double, double >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_double_0") == 2183367433u);
			pAgent->SetVariable("par2_double_0", opr, 2183367433u);
			return result;
		}
	};

	class Assignment_bt_par_test_par_as_left_value_and_param_node3 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node3, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node3()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_single_0") == 3120166065u);
			float& opr_p0 = (float&)pAgent->GetVariable<float >(3120166065u);
			float opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_SingleIR, float, float >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_single_0") == 3120166065u);
			pAgent->SetVariable("par2_single_0", opr, 3120166065u);
			return result;
		}
	};

	class Assignment_bt_par_test_par_as_left_value_and_param_node4 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node4, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node4()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_single_list_0") == 3448877207u);
			behaviac::vector<float>& opr_p0 = (behaviac::vector<float>&)pAgent->GetVariable<behaviac::vector<float> >(3448877207u);
			behaviac::vector<float> opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_SingleListIR, behaviac::vector<float>, behaviac::vector<float> >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_single_list_0") == 3448877207u);
			pAgent->SetVariable("par2_single_list_0", opr, 3448877207u);
			return result;
		}
	};

	class Assignment_bt_par_test_par_as_left_value_and_param_node5 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node5, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node5()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_string_0") == 351984746u);
			behaviac::string& opr_p0 = (behaviac::string&)pAgent->GetVariable<behaviac::string >(351984746u);
			behaviac::string opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_StringIR, behaviac::string, behaviac::string& >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_string_0") == 351984746u);
			pAgent->SetVariable("par2_string_0", opr, 351984746u);
			return result;
		}
	};

	class Assignment_bt_par_test_par_as_left_value_and_param_node6 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node6, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node6()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_string_list_0") == 1339885043u);
			behaviac::vector<behaviac::string>& opr_p0 = (behaviac::vector<behaviac::string>&)pAgent->GetVariable<behaviac::vector<behaviac::string> >(1339885043u);
			behaviac::vector<behaviac::string> opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_StringListIR, behaviac::vector<behaviac::string>, behaviac::vector<behaviac::string> >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_string_list_0") == 1339885043u);
			pAgent->SetVariable("par2_string_list_0", opr, 1339885043u);
			return result;
		}
	};

	class Assignment_bt_par_test_par_as_left_value_and_param_node7 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node7, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node7()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_uint_0") == 868709384u);
			unsigned int& opr_p0 = (unsigned int&)pAgent->GetVariable<unsigned int >(868709384u);
			unsigned int opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_UIntIR, unsigned int, unsigned int >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_uint_0") == 868709384u);
			pAgent->SetVariable("par2_uint_0", opr, 868709384u);
			return result;
		}
	};

	class Assignment_bt_par_test_par_as_left_value_and_param_node8 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node8, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node8()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_ulong_0") == 4274832167u);
			unsigned long& opr_p0 = (unsigned long&)pAgent->GetVariable<unsigned long >(4274832167u);
			unsigned long opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_ULongIR, unsigned long, unsigned long >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_ulong_0") == 4274832167u);
			pAgent->SetVariable("par2_ulong_0", opr, 4274832167u);
			return result;
		}
	};

	class Assignment_bt_par_test_par_as_left_value_and_param_node35 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node35, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node35()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_longlong_0") == 1021248696u);
			long long& opr_p0 = (long long&)pAgent->GetVariable<long long >(1021248696u);
			long long opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_LongLongIR, long long, long long >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_longlong_0") == 1021248696u);
			pAgent->SetVariable("par2_longlong_0", opr, 1021248696u);
			return result;
		}
	};

	class Assignment_bt_par_test_par_as_left_value_and_param_node36 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node36, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node36()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_ulonglong_0") == 386357671u);
			unsigned long long& opr_p0 = (unsigned long long&)pAgent->GetVariable<unsigned long long >(386357671u);
			unsigned long long opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_ULongLongIR, unsigned long long, unsigned long long >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_ulonglong_0") == 386357671u);
			pAgent->SetVariable("par2_ulonglong_0", opr, 386357671u);
			return result;
		}
	};

	class Assignment_bt_par_test_par_as_left_value_and_param_node37 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node37, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node37()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_SzString_0") == 2318984205u);
			behaviac::string& opr_p0 = (behaviac::string&)pAgent->GetVariable<behaviac::string >(2318984205u);
			behaviac::string opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_StringIR, behaviac::string, behaviac::string& >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_SzString_0") == 2318984205u);
			pAgent->SetVariable("par2_SzString_0", opr, 2318984205u);
			return result;
		}
	};

	class Assignment_bt_par_test_par_as_left_value_and_param_node9 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node9, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node9()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_short_0") == 3228030786u);
			short& opr_p0 = (short&)pAgent->GetVariable<short >(3228030786u);
			short opr = ((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_ShortIR, short, short >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_short_0") == 3228030786u);
			pAgent->SetVariable("par1_short_0", opr, 3228030786u);
			return result;
		}
	};

	class Assignment_bt_par_test_par_as_left_value_and_param_node10 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node10, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node10()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_int_0") == 2735162453u);
			int& opr_p0 = (int&)pAgent->GetVariable<int >(2735162453u);
			int opr = ((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_IntIR, int, int >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_int_0") == 2735162453u);
			pAgent->SetVariable("par1_int_0", opr, 2735162453u);
			return result;
		}
	};

	class Assignment_bt_par_test_par_as_left_value_and_param_node11 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node11, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node11()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_int_list_0") == 2093180786u);
			behaviac::vector<int>& opr_p0 = (behaviac::vector<int>&)pAgent->GetVariable<behaviac::vector<int> >(2093180786u);
			behaviac::vector<int> opr = ((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_IntListIR, behaviac::vector<int>, behaviac::vector<int> >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_int_list_0") == 2093180786u);
			pAgent->SetVariable("par1_int_list_0", opr, 2093180786u);
			return result;
		}
	};

	class Assignment_bt_par_test_par_as_left_value_and_param_node12 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node12, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node12()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_long_0") == 1828293308u);
			long& opr_p0 = (long&)pAgent->GetVariable<long >(1828293308u);
			long opr = ((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_LongIR, long, long >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_long_0") == 1828293308u);
			pAgent->SetVariable("par1_long_0", opr, 1828293308u);
			return result;
		}
	};

	class Assignment_bt_par_test_par_as_left_value_and_param_node17 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node17, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node17()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_kemployee_0") == 4045482770u);
			TNS::ST::PER::WRK::kEmployee& opr_p0 = (TNS::ST::PER::WRK::kEmployee&)pAgent->GetVariable<TNS::ST::PER::WRK::kEmployee >(4045482770u);
			TNS::ST::PER::WRK::kEmployee opr = ((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_kEmployeeIR, TNS::ST::PER::WRK::kEmployee, TNS::ST::PER::WRK::kEmployee >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_kemployee_0") == 4045482770u);
			pAgent->SetVariable("par1_kemployee_0", opr, 4045482770u);
			return result;
		}
	};

	class Assignment_bt_par_test_par_as_left_value_and_param_node19 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node19, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node19()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_kemployee_list_0") == 506976637u);
			behaviac::vector<TNS::ST::PER::WRK::kEmployee>& opr_p0 = (behaviac::vector<TNS::ST::PER::WRK::kEmployee>&)pAgent->GetVariable<behaviac::vector<TNS::ST::PER::WRK::kEmployee> >(506976637u);
			behaviac::vector<TNS::ST::PER::WRK::kEmployee> opr = ((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_kEmployeeListIR, behaviac::vector<TNS::ST::PER::WRK::kEmployee>, behaviac::vector<TNS::ST::PER::WRK::kEmployee> >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_kemployee_list_0") == 506976637u);
			pAgent->SetVariable("par1_kemployee_list_0", opr, 506976637u);
			return result;
		}
	};

	class Assignment_bt_par_test_par_as_left_value_and_param_node18 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node18, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node18()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_ushort_0") == 109865111u);
			unsigned short& opr_p0 = (unsigned short&)pAgent->GetVariable<unsigned short >(109865111u);
			unsigned short opr = ((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_UShortIR, unsigned short, unsigned short >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_ushort_0") == 109865111u);
			pAgent->SetVariable("par1_ushort_0", opr, 109865111u);
			return result;
		}
	};

	class Assignment_bt_par_test_par_as_left_value_and_param_node16 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node16, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node16()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_boolean_0") == 1912381985u);
			bool& opr_p0 = (bool&)pAgent->GetVariable<bool >(1912381985u);
			bool opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_BooleanIR, bool, bool >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_boolean_0") == 1912381985u);
			pAgent->SetVariable("par0_boolean_0", opr, 1912381985u);
			return result;
		}
	};

	class Assignment_bt_par_test_par_as_left_value_and_param_node20 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node20, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node20()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_boolean_list_0") == 109714028u);
			behaviac::vector<bool>& opr_p0 = (behaviac::vector<bool>&)pAgent->GetVariable<behaviac::vector<bool> >(109714028u);
			behaviac::vector<bool> opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_BooleanListIR, behaviac::vector<bool>, behaviac::vector<bool> >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_boolean_list_0") == 109714028u);
			pAgent->SetVariable("par0_boolean_list_0", opr, 109714028u);
			return result;
		}
	};

	class Assignment_bt_par_test_par_as_left_value_and_param_node24 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node24, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node24()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_byte_0") == 2120958860u);
			unsigned char& opr_p0 = (unsigned char&)pAgent->GetVariable<unsigned char >(2120958860u);
			unsigned char opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_ByteIR, unsigned char, unsigned char >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_byte_0") == 2120958860u);
			pAgent->SetVariable("par0_byte_0", opr, 2120958860u);
			return result;
		}
	};

	class Assignment_bt_par_test_par_as_left_value_and_param_node25 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node25, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node25()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_byte_list_0") == 1459492261u);
			behaviac::vector<unsigned char>& opr_p0 = (behaviac::vector<unsigned char>&)pAgent->GetVariable<behaviac::vector<unsigned char> >(1459492261u);
			behaviac::vector<unsigned char> opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_ByteListIR, behaviac::vector<unsigned char>, behaviac::vector<unsigned char> >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_byte_list_0") == 1459492261u);
			pAgent->SetVariable("par0_byte_list_0", opr, 1459492261u);
			return result;
		}
	};

	class Assignment_bt_par_test_par_as_left_value_and_param_node26 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node26, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node26()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_char_0") == 1968762578u);
			char& opr_p0 = (char&)pAgent->GetVariable<char >(1968762578u);
			char opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_CharIR, char, char >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_char_0") == 1968762578u);
			pAgent->SetVariable("par0_char_0", opr, 1968762578u);
			return result;
		}
	};

	class Assignment_bt_par_test_par_as_left_value_and_param_node27 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node27, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node27()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_char_list_0") == 2869241813u);
			behaviac::vector<char>& opr_p0 = (behaviac::vector<char>&)pAgent->GetVariable<behaviac::vector<char> >(2869241813u);
			behaviac::vector<char> opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_CharListIR, behaviac::vector<char>, behaviac::vector<char> >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_char_list_0") == 2869241813u);
			pAgent->SetVariable("par0_char_list_0", opr, 2869241813u);
			return result;
		}
	};

	class Assignment_bt_par_test_par_as_left_value_and_param_node21 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node21, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node21()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_ecolor_0") == 3914433730u);
			TNS::NE::NAT::eColor& opr_p0 = (TNS::NE::NAT::eColor&)pAgent->GetVariable<TNS::NE::NAT::eColor >(3914433730u);
			TNS::NE::NAT::eColor opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_eColorIR, TNS::NE::NAT::eColor, TNS::NE::NAT::eColor >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_ecolor_0") == 3914433730u);
			pAgent->SetVariable("par0_ecolor_0", opr, 3914433730u);
			return result;
		}
	};

	class Assignment_bt_par_test_par_as_left_value_and_param_node23 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node23, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node23()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_ecolor_list_0") == 1963776920u);
			behaviac::vector<TNS::NE::NAT::eColor>& opr_p0 = (behaviac::vector<TNS::NE::NAT::eColor>&)pAgent->GetVariable<behaviac::vector<TNS::NE::NAT::eColor> >(1963776920u);
			behaviac::vector<TNS::NE::NAT::eColor> opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_eColorListIR, behaviac::vector<TNS::NE::NAT::eColor>, behaviac::vector<TNS::NE::NAT::eColor> >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_ecolor_list_0") == 1963776920u);
			pAgent->SetVariable("par0_ecolor_list_0", opr, 1963776920u);
			return result;
		}
	};

	class Assignment_bt_par_test_par_as_left_value_and_param_node28 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node28, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node28()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_sbyte_0") == 968869870u);
			signed char& opr_p0 = (signed char&)pAgent->GetVariable<signed char >(968869870u);
			signed char opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_SByteIR, signed char, signed char >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_sbyte_0") == 968869870u);
			pAgent->SetVariable("par0_sbyte_0", opr, 968869870u);
			return result;
		}
	};

	class Assignment_bt_par_test_par_as_left_value_and_param_node29 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node29, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node29()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_sbyte_list_0") == 2290963684u);
			behaviac::vector<signed char>& opr_p0 = (behaviac::vector<signed char>&)pAgent->GetVariable<behaviac::vector<signed char> >(2290963684u);
			behaviac::vector<signed char> opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_SByteListIR, behaviac::vector<signed char>, behaviac::vector<signed char> >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_sbyte_list_0") == 2290963684u);
			pAgent->SetVariable("par0_sbyte_list_0", opr, 2290963684u);
			return result;
		}
	};

	class DecoratorLoop_bt_par_test_par_as_left_value_and_param_node33 : public DecoratorLoop
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorLoop_bt_par_test_par_as_left_value_and_param_node33, DecoratorLoop);
		DecoratorLoop_bt_par_test_par_as_left_value_and_param_node33()
		{
			m_bDecorateWhenChildEnds = true;
			m_bDoneWithinFrame = false;
		}
	protected:
		virtual int GetCount(Agent* pAgent) const
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			return -1;
		}
	};

		bool bt_par_test_par_as_left_value_and_param::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("par_test/par_as_left_value_and_param");
			pBT->SetIsFSM(false);
#if !BEHAVIAC_RELEASE
			pBT->SetAgentType("EmployeeParTestAgent");
#endif
			// pars
			pBT->AddPar("EmployeeParTestAgent", "double", "par2_double_0", "5.7");
			pBT->AddPar("EmployeeParTestAgent", "float", "par2_single_0", "98.2");
			pBT->AddPar("EmployeeParTestAgent", "vector<float>", "par2_single_list_0", "2:5.1|6.2");
			pBT->AddPar("EmployeeParTestAgent", "string", "par2_string_0", "origin");
			pBT->AddPar("EmployeeParTestAgent", "vector<string>", "par2_string_list_0", "4:\"string0\"|\"string1\"|\"string2\"|\"string3\"");
			pBT->AddPar("EmployeeParTestAgent", "uint", "par2_uint_0", "9");
			pBT->AddPar("EmployeeParTestAgent", "ulong", "par2_ulong_0", "300");
			pBT->AddPar("EmployeeParTestAgent", "short", "par1_short_0", "78");
			pBT->AddPar("EmployeeParTestAgent", "int", "par1_int_0", "-3");
			pBT->AddPar("EmployeeParTestAgent", "vector<int>", "par1_int_list_0", "3:9999|12345|0");
			pBT->AddPar("EmployeeParTestAgent", "long", "par1_long_0", "1500");
			pBT->AddPar("EmployeeParTestAgent", "vector<TNS::ST::PER::WRK::kEmployee>", "par1_kemployee_list_0", "1:{boss=null;car={brand=\"Lexus\";color=BLUE;price=93840;};code=q;id=9;isMale=true;name=\"John\";skinColor=GREEN;weight=110;}");
			pBT->AddPar("EmployeeParTestAgent", "ushort", "par1_ushort_0", "2001");
			pBT->AddPar("EmployeeParTestAgent", "bool", "par0_boolean_0", "true");
			pBT->AddPar("EmployeeParTestAgent", "vector<bool>", "par0_boolean_list_0", "2:false|true");
			pBT->AddPar("EmployeeParTestAgent", "TNS::NE::NAT::eColor", "par0_ecolor_0", "YELLOW");
			pBT->AddPar("EmployeeParTestAgent", "vector<TNS::NE::NAT::eColor>", "par0_ecolor_list_0", "2:RED|GREEN");
			pBT->AddPar("EmployeeParTestAgent", "behaviac::Agent", "par2_agent_0", "null");
			pBT->AddPar("EmployeeParTestAgent", "vector<behaviac::Agent>", "par2_agent_list_0", "2:null|null");
			pBT->AddPar("EmployeeParTestAgent", "char", "par0_char_0", "A");
			pBT->AddPar("EmployeeParTestAgent", "TNS::ST::PER::WRK::kEmployee", "par1_kemployee_0", "{boss=null;car={brand=\"Alpha\";color=WHITE;price=5700;};code=A;id=83;isMale=false;name=\"Tom\";skinColor=RED;weight=97.3;}");
			pBT->AddPar("EmployeeParTestAgent", "ubyte", "par0_byte_0", "197");
			pBT->AddPar("EmployeeParTestAgent", "sbyte", "par0_sbyte_0", "-60");
			pBT->AddPar("EmployeeParTestAgent", "vector<char>", "par0_char_list_0", "4:d|j|F|A");
			pBT->AddPar("EmployeeParTestAgent", "vector<sbyte>", "par0_sbyte_list_0", "3:127|-128|0");
			pBT->AddPar("EmployeeParTestAgent", "vector<ubyte>", "par0_byte_list_0", "3:167|23|152");
			pBT->AddPar("EmployeeParTestAgent", "ParTestAgentBase", "par2_ParTestAgentBase_0", "null");
			pBT->AddPar("EmployeeParTestAgent", "vector<ParTestAgentBase>", "par2_ParTestAgentBaseList_0", "2:null|null");
			pBT->AddPar("EmployeeParTestAgent", "llong", "par2_longlong_0", "-666");
			pBT->AddPar("EmployeeParTestAgent", "ullong", "par2_ulonglong_0", "666");
			pBT->AddPar("EmployeeParTestAgent", "string", "par2_SzString_0", "this is char* test");
			pBT->AddPar("EmployeeParTestAgent", "string", "par2_CSzString_0", "this is const char* test");
			// children
			{
				Sequence* node32 = BEHAVIAC_NEW Sequence;
				node32->SetClassNameString("Sequence");
				node32->SetId(32);
#if !BEHAVIAC_RELEASE
				node32->SetAgentType("EmployeeParTestAgent");
#endif
				pBT->AddChild(node32);
				{
					Sequence* node13 = BEHAVIAC_NEW Sequence;
					node13->SetClassNameString("Sequence");
					node13->SetId(13);
#if !BEHAVIAC_RELEASE
					node13->SetAgentType("EmployeeParTestAgent");
#endif
					node32->AddChild(node13);
					{
						Sequence* node1 = BEHAVIAC_NEW Sequence;
						node1->SetClassNameString("Sequence");
						node1->SetId(1);
#if !BEHAVIAC_RELEASE
						node1->SetAgentType("EmployeeParTestAgent");
#endif
						node13->AddChild(node1);
						{
							Assignment_bt_par_test_par_as_left_value_and_param_node0* node0 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node0;
							node0->SetClassNameString("Assignment");
							node0->SetId(0);
#if !BEHAVIAC_RELEASE
							node0->SetAgentType("EmployeeParTestAgent");
#endif
							node1->AddChild(node0);
							node1->SetHasEvents(node1->HasEvents() | node0->HasEvents());
						}
						{
							Assignment_bt_par_test_par_as_left_value_and_param_node30* node30 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node30;
							node30->SetClassNameString("Assignment");
							node30->SetId(30);
#if !BEHAVIAC_RELEASE
							node30->SetAgentType("EmployeeParTestAgent");
#endif
							node1->AddChild(node30);
							node1->SetHasEvents(node1->HasEvents() | node30->HasEvents());
						}
						{
							Assignment_bt_par_test_par_as_left_value_and_param_node15* node15 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node15;
							node15->SetClassNameString("Assignment");
							node15->SetId(15);
#if !BEHAVIAC_RELEASE
							node15->SetAgentType("EmployeeParTestAgent");
#endif
							node1->AddChild(node15);
							node1->SetHasEvents(node1->HasEvents() | node15->HasEvents());
						}
						{
							Assignment_bt_par_test_par_as_left_value_and_param_node31* node31 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node31;
							node31->SetClassNameString("Assignment");
							node31->SetId(31);
#if !BEHAVIAC_RELEASE
							node31->SetAgentType("EmployeeParTestAgent");
#endif
							node1->AddChild(node31);
							node1->SetHasEvents(node1->HasEvents() | node31->HasEvents());
						}
						{
							Assignment_bt_par_test_par_as_left_value_and_param_node2* node2 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node2;
							node2->SetClassNameString("Assignment");
							node2->SetId(2);
#if !BEHAVIAC_RELEASE
							node2->SetAgentType("EmployeeParTestAgent");
#endif
							node1->AddChild(node2);
							node1->SetHasEvents(node1->HasEvents() | node2->HasEvents());
						}
						{
							Assignment_bt_par_test_par_as_left_value_and_param_node3* node3 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node3;
							node3->SetClassNameString("Assignment");
							node3->SetId(3);
#if !BEHAVIAC_RELEASE
							node3->SetAgentType("EmployeeParTestAgent");
#endif
							node1->AddChild(node3);
							node1->SetHasEvents(node1->HasEvents() | node3->HasEvents());
						}
						{
							Assignment_bt_par_test_par_as_left_value_and_param_node4* node4 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node4;
							node4->SetClassNameString("Assignment");
							node4->SetId(4);
#if !BEHAVIAC_RELEASE
							node4->SetAgentType("EmployeeParTestAgent");
#endif
							node1->AddChild(node4);
							node1->SetHasEvents(node1->HasEvents() | node4->HasEvents());
						}
						{
							Assignment_bt_par_test_par_as_left_value_and_param_node5* node5 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node5;
							node5->SetClassNameString("Assignment");
							node5->SetId(5);
#if !BEHAVIAC_RELEASE
							node5->SetAgentType("EmployeeParTestAgent");
#endif
							node1->AddChild(node5);
							node1->SetHasEvents(node1->HasEvents() | node5->HasEvents());
						}
						{
							Assignment_bt_par_test_par_as_left_value_and_param_node6* node6 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node6;
							node6->SetClassNameString("Assignment");
							node6->SetId(6);
#if !BEHAVIAC_RELEASE
							node6->SetAgentType("EmployeeParTestAgent");
#endif
							node1->AddChild(node6);
							node1->SetHasEvents(node1->HasEvents() | node6->HasEvents());
						}
						{
							Assignment_bt_par_test_par_as_left_value_and_param_node7* node7 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node7;
							node7->SetClassNameString("Assignment");
							node7->SetId(7);
#if !BEHAVIAC_RELEASE
							node7->SetAgentType("EmployeeParTestAgent");
#endif
							node1->AddChild(node7);
							node1->SetHasEvents(node1->HasEvents() | node7->HasEvents());
						}
						{
							Assignment_bt_par_test_par_as_left_value_and_param_node8* node8 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node8;
							node8->SetClassNameString("Assignment");
							node8->SetId(8);
#if !BEHAVIAC_RELEASE
							node8->SetAgentType("EmployeeParTestAgent");
#endif
							node1->AddChild(node8);
							node1->SetHasEvents(node1->HasEvents() | node8->HasEvents());
						}
						{
							Assignment_bt_par_test_par_as_left_value_and_param_node35* node35 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node35;
							node35->SetClassNameString("Assignment");
							node35->SetId(35);
#if !BEHAVIAC_RELEASE
							node35->SetAgentType("EmployeeParTestAgent");
#endif
							node1->AddChild(node35);
							node1->SetHasEvents(node1->HasEvents() | node35->HasEvents());
						}
						{
							Assignment_bt_par_test_par_as_left_value_and_param_node36* node36 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node36;
							node36->SetClassNameString("Assignment");
							node36->SetId(36);
#if !BEHAVIAC_RELEASE
							node36->SetAgentType("EmployeeParTestAgent");
#endif
							node1->AddChild(node36);
							node1->SetHasEvents(node1->HasEvents() | node36->HasEvents());
						}
						{
							Assignment_bt_par_test_par_as_left_value_and_param_node37* node37 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node37;
							node37->SetClassNameString("Assignment");
							node37->SetId(37);
#if !BEHAVIAC_RELEASE
							node37->SetAgentType("EmployeeParTestAgent");
#endif
							node1->AddChild(node37);
							node1->SetHasEvents(node1->HasEvents() | node37->HasEvents());
						}
						node13->SetHasEvents(node13->HasEvents() | node1->HasEvents());
					}
					{
						Sequence* node14 = BEHAVIAC_NEW Sequence;
						node14->SetClassNameString("Sequence");
						node14->SetId(14);
#if !BEHAVIAC_RELEASE
						node14->SetAgentType("EmployeeParTestAgent");
#endif
						node13->AddChild(node14);
						{
							Assignment_bt_par_test_par_as_left_value_and_param_node9* node9 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node9;
							node9->SetClassNameString("Assignment");
							node9->SetId(9);
#if !BEHAVIAC_RELEASE
							node9->SetAgentType("EmployeeParTestAgent");
#endif
							node14->AddChild(node9);
							node14->SetHasEvents(node14->HasEvents() | node9->HasEvents());
						}
						{
							Assignment_bt_par_test_par_as_left_value_and_param_node10* node10 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node10;
							node10->SetClassNameString("Assignment");
							node10->SetId(10);
#if !BEHAVIAC_RELEASE
							node10->SetAgentType("EmployeeParTestAgent");
#endif
							node14->AddChild(node10);
							node14->SetHasEvents(node14->HasEvents() | node10->HasEvents());
						}
						{
							Assignment_bt_par_test_par_as_left_value_and_param_node11* node11 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node11;
							node11->SetClassNameString("Assignment");
							node11->SetId(11);
#if !BEHAVIAC_RELEASE
							node11->SetAgentType("EmployeeParTestAgent");
#endif
							node14->AddChild(node11);
							node14->SetHasEvents(node14->HasEvents() | node11->HasEvents());
						}
						{
							Assignment_bt_par_test_par_as_left_value_and_param_node12* node12 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node12;
							node12->SetClassNameString("Assignment");
							node12->SetId(12);
#if !BEHAVIAC_RELEASE
							node12->SetAgentType("EmployeeParTestAgent");
#endif
							node14->AddChild(node12);
							node14->SetHasEvents(node14->HasEvents() | node12->HasEvents());
						}
						{
							Assignment_bt_par_test_par_as_left_value_and_param_node17* node17 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node17;
							node17->SetClassNameString("Assignment");
							node17->SetId(17);
#if !BEHAVIAC_RELEASE
							node17->SetAgentType("EmployeeParTestAgent");
#endif
							node14->AddChild(node17);
							node14->SetHasEvents(node14->HasEvents() | node17->HasEvents());
						}
						{
							Assignment_bt_par_test_par_as_left_value_and_param_node19* node19 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node19;
							node19->SetClassNameString("Assignment");
							node19->SetId(19);
#if !BEHAVIAC_RELEASE
							node19->SetAgentType("EmployeeParTestAgent");
#endif
							node14->AddChild(node19);
							node14->SetHasEvents(node14->HasEvents() | node19->HasEvents());
						}
						{
							Assignment_bt_par_test_par_as_left_value_and_param_node18* node18 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node18;
							node18->SetClassNameString("Assignment");
							node18->SetId(18);
#if !BEHAVIAC_RELEASE
							node18->SetAgentType("EmployeeParTestAgent");
#endif
							node14->AddChild(node18);
							node14->SetHasEvents(node14->HasEvents() | node18->HasEvents());
						}
						node13->SetHasEvents(node13->HasEvents() | node14->HasEvents());
					}
					{
						Sequence* node22 = BEHAVIAC_NEW Sequence;
						node22->SetClassNameString("Sequence");
						node22->SetId(22);
#if !BEHAVIAC_RELEASE
						node22->SetAgentType("EmployeeParTestAgent");
#endif
						node13->AddChild(node22);
						{
							Assignment_bt_par_test_par_as_left_value_and_param_node16* node16 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node16;
							node16->SetClassNameString("Assignment");
							node16->SetId(16);
#if !BEHAVIAC_RELEASE
							node16->SetAgentType("EmployeeParTestAgent");
#endif
							node22->AddChild(node16);
							node22->SetHasEvents(node22->HasEvents() | node16->HasEvents());
						}
						{
							Assignment_bt_par_test_par_as_left_value_and_param_node20* node20 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node20;
							node20->SetClassNameString("Assignment");
							node20->SetId(20);
#if !BEHAVIAC_RELEASE
							node20->SetAgentType("EmployeeParTestAgent");
#endif
							node22->AddChild(node20);
							node22->SetHasEvents(node22->HasEvents() | node20->HasEvents());
						}
						{
							Assignment_bt_par_test_par_as_left_value_and_param_node24* node24 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node24;
							node24->SetClassNameString("Assignment");
							node24->SetId(24);
#if !BEHAVIAC_RELEASE
							node24->SetAgentType("EmployeeParTestAgent");
#endif
							node22->AddChild(node24);
							node22->SetHasEvents(node22->HasEvents() | node24->HasEvents());
						}
						{
							Assignment_bt_par_test_par_as_left_value_and_param_node25* node25 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node25;
							node25->SetClassNameString("Assignment");
							node25->SetId(25);
#if !BEHAVIAC_RELEASE
							node25->SetAgentType("EmployeeParTestAgent");
#endif
							node22->AddChild(node25);
							node22->SetHasEvents(node22->HasEvents() | node25->HasEvents());
						}
						{
							Assignment_bt_par_test_par_as_left_value_and_param_node26* node26 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node26;
							node26->SetClassNameString("Assignment");
							node26->SetId(26);
#if !BEHAVIAC_RELEASE
							node26->SetAgentType("EmployeeParTestAgent");
#endif
							node22->AddChild(node26);
							node22->SetHasEvents(node22->HasEvents() | node26->HasEvents());
						}
						{
							Assignment_bt_par_test_par_as_left_value_and_param_node27* node27 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node27;
							node27->SetClassNameString("Assignment");
							node27->SetId(27);
#if !BEHAVIAC_RELEASE
							node27->SetAgentType("EmployeeParTestAgent");
#endif
							node22->AddChild(node27);
							node22->SetHasEvents(node22->HasEvents() | node27->HasEvents());
						}
						{
							Assignment_bt_par_test_par_as_left_value_and_param_node21* node21 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node21;
							node21->SetClassNameString("Assignment");
							node21->SetId(21);
#if !BEHAVIAC_RELEASE
							node21->SetAgentType("EmployeeParTestAgent");
#endif
							node22->AddChild(node21);
							node22->SetHasEvents(node22->HasEvents() | node21->HasEvents());
						}
						{
							Assignment_bt_par_test_par_as_left_value_and_param_node23* node23 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node23;
							node23->SetClassNameString("Assignment");
							node23->SetId(23);
#if !BEHAVIAC_RELEASE
							node23->SetAgentType("EmployeeParTestAgent");
#endif
							node22->AddChild(node23);
							node22->SetHasEvents(node22->HasEvents() | node23->HasEvents());
						}
						{
							Assignment_bt_par_test_par_as_left_value_and_param_node28* node28 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node28;
							node28->SetClassNameString("Assignment");
							node28->SetId(28);
#if !BEHAVIAC_RELEASE
							node28->SetAgentType("EmployeeParTestAgent");
#endif
							node22->AddChild(node28);
							node22->SetHasEvents(node22->HasEvents() | node28->HasEvents());
						}
						{
							Assignment_bt_par_test_par_as_left_value_and_param_node29* node29 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node29;
							node29->SetClassNameString("Assignment");
							node29->SetId(29);
#if !BEHAVIAC_RELEASE
							node29->SetAgentType("EmployeeParTestAgent");
#endif
							node22->AddChild(node29);
							node22->SetHasEvents(node22->HasEvents() | node29->HasEvents());
						}
						node13->SetHasEvents(node13->HasEvents() | node22->HasEvents());
					}
					node32->SetHasEvents(node32->HasEvents() | node13->HasEvents());
				}
				{
					DecoratorLoop_bt_par_test_par_as_left_value_and_param_node33* node33 = BEHAVIAC_NEW DecoratorLoop_bt_par_test_par_as_left_value_and_param_node33;
					node33->SetClassNameString("DecoratorLoop");
					node33->SetId(33);
#if !BEHAVIAC_RELEASE
					node33->SetAgentType("EmployeeParTestAgent");
#endif
					node32->AddChild(node33);
					{
						Noop* node34 = BEHAVIAC_NEW Noop;
						node34->SetClassNameString("Noop");
						node34->SetId(34);
#if !BEHAVIAC_RELEASE
						node34->SetAgentType("EmployeeParTestAgent");
#endif
						node33->AddChild(node34);
						node33->SetHasEvents(node33->HasEvents() | node34->HasEvents());
					}
					node32->SetHasEvents(node32->HasEvents() | node33->HasEvents());
				}
				pBT->SetHasEvents(pBT->HasEvents() | node32->HasEvents());
			}
			return true;
		}

	// Source file: par_test/par_as_ref_param

	class Action_bt_par_test_par_as_ref_param_node0 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node0, Action);
		Action_bt_par_test_par_as_ref_param_node0()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_agent_0") == 3876418331u);
			behaviac::Agent*& method_p0 = (behaviac::Agent*&)pAgent->GetVariable<behaviac::Agent* >(3876418331u);
			((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_AgentRef, void, behaviac::Agent*& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_agent_0") == 3876418331u);
			pAgent->SetVariable("par2_agent_0", method_p0, 3876418331u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_par_as_ref_param_node17 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node17, Action);
		Action_bt_par_test_par_as_ref_param_node17()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_agent_list_0") == 1126732011u);
			behaviac::vector<behaviac::Agent*>& method_p0 = (behaviac::vector<behaviac::Agent*>&)pAgent->GetVariable<behaviac::vector<behaviac::Agent*> >(1126732011u);
			((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_AgentListRef, void, behaviac::vector<behaviac::Agent*>& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_agent_list_0") == 1126732011u);
			pAgent->SetVariable("par2_agent_list_0", method_p0, 1126732011u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_par_as_ref_param_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node2, Action);
		Action_bt_par_test_par_as_ref_param_node2()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_double_0") == 2183367433u);
			double& method_p0 = (double&)pAgent->GetVariable<double >(2183367433u);
			((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_DoubleRef, void, double& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_double_0") == 2183367433u);
			pAgent->SetVariable("par2_double_0", method_p0, 2183367433u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_par_as_ref_param_node3 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node3, Action);
		Action_bt_par_test_par_as_ref_param_node3()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_single_0") == 3120166065u);
			float& method_p0 = (float&)pAgent->GetVariable<float >(3120166065u);
			((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_SingleRef, void, float& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_single_0") == 3120166065u);
			pAgent->SetVariable("par2_single_0", method_p0, 3120166065u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_par_as_ref_param_node4 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node4, Action);
		Action_bt_par_test_par_as_ref_param_node4()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_single_list_0") == 3448877207u);
			behaviac::vector<float>& method_p0 = (behaviac::vector<float>&)pAgent->GetVariable<behaviac::vector<float> >(3448877207u);
			((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_SingleListRef, void, behaviac::vector<float>& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_single_list_0") == 3448877207u);
			pAgent->SetVariable("par2_single_list_0", method_p0, 3448877207u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_par_as_ref_param_node5 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node5, Action);
		Action_bt_par_test_par_as_ref_param_node5()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_string_0") == 351984746u);
			behaviac::string& method_p0 = (behaviac::string&)pAgent->GetVariable<behaviac::string >(351984746u);
			((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_StringRef, void, behaviac::string& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_string_0") == 351984746u);
			pAgent->SetVariable("par2_string_0", method_p0, 351984746u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_par_as_ref_param_node6 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node6, Action);
		Action_bt_par_test_par_as_ref_param_node6()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_string_list_0") == 1339885043u);
			behaviac::vector<behaviac::string>& method_p0 = (behaviac::vector<behaviac::string>&)pAgent->GetVariable<behaviac::vector<behaviac::string> >(1339885043u);
			((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_StringListRef, void, behaviac::vector<behaviac::string>& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_string_list_0") == 1339885043u);
			pAgent->SetVariable("par2_string_list_0", method_p0, 1339885043u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_par_as_ref_param_node7 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node7, Action);
		Action_bt_par_test_par_as_ref_param_node7()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_uint_0") == 868709384u);
			unsigned int& method_p0 = (unsigned int&)pAgent->GetVariable<unsigned int >(868709384u);
			((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_UIntRef, void, unsigned int& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_uint_0") == 868709384u);
			pAgent->SetVariable("par2_uint_0", method_p0, 868709384u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_par_as_ref_param_node8 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node8, Action);
		Action_bt_par_test_par_as_ref_param_node8()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_ulong_0") == 4274832167u);
			unsigned long& method_p0 = (unsigned long&)pAgent->GetVariable<unsigned long >(4274832167u);
			((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_ULongRef, void, unsigned long& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_ulong_0") == 4274832167u);
			pAgent->SetVariable("par2_ulong_0", method_p0, 4274832167u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_par_as_ref_param_node35 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node35, Action);
		Action_bt_par_test_par_as_ref_param_node35()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_longlong_0") == 1021248696u);
			long long& method_p0 = (long long&)pAgent->GetVariable<long long >(1021248696u);
			((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_LongLongRef, void, long long& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_longlong_0") == 1021248696u);
			pAgent->SetVariable("par2_longlong_0", method_p0, 1021248696u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_par_as_ref_param_node36 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node36, Action);
		Action_bt_par_test_par_as_ref_param_node36()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_ulonglong_0") == 386357671u);
			unsigned long long& method_p0 = (unsigned long long&)pAgent->GetVariable<unsigned long long >(386357671u);
			((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_ULongLongRef, void, unsigned long long& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_ulonglong_0") == 386357671u);
			pAgent->SetVariable("par2_ulonglong_0", method_p0, 386357671u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_par_as_ref_param_node31 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node31, Action);
		Action_bt_par_test_par_as_ref_param_node31()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_SzString_0") == 2318984205u);
			char* method_p0 = (char*)((behaviac::string&)pAgent->GetVariable<behaviac::string>(2318984205u)).c_str();
			((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_SzStringRef, void, char*& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_SzString_0") == 2318984205u);
			pAgent->SetVariable("par2_SzString_0", behaviac::string(method_p0), 2318984205u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_par_as_ref_param_node32 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node32, Action);
		Action_bt_par_test_par_as_ref_param_node32()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_CSzStrng_0") == 1084657673u);
			char* method_p0 = (char*)((behaviac::string&)pAgent->GetVariable<behaviac::string>(1084657673u)).c_str();
			((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_CSzStringRef, void, char* >(method_p0);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_par_as_ref_param_node9 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node9, Action);
		Action_bt_par_test_par_as_ref_param_node9()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_short_0") == 3228030786u);
			short& method_p0 = (short&)pAgent->GetVariable<short >(3228030786u);
			((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_ShortRef, void, short& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_short_0") == 3228030786u);
			pAgent->SetVariable("par1_short_0", method_p0, 3228030786u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_par_as_ref_param_node10 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node10, Action);
		Action_bt_par_test_par_as_ref_param_node10()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_int_0") == 2735162453u);
			int& method_p0 = (int&)pAgent->GetVariable<int >(2735162453u);
			((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_IntRef, void, int& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_int_0") == 2735162453u);
			pAgent->SetVariable("par1_int_0", method_p0, 2735162453u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_par_as_ref_param_node11 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node11, Action);
		Action_bt_par_test_par_as_ref_param_node11()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_int_list_0") == 2093180786u);
			behaviac::vector<int>& method_p0 = (behaviac::vector<int>&)pAgent->GetVariable<behaviac::vector<int> >(2093180786u);
			((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_IntListRef, void, behaviac::vector<int>& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_int_list_0") == 2093180786u);
			pAgent->SetVariable("par1_int_list_0", method_p0, 2093180786u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_par_as_ref_param_node12 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node12, Action);
		Action_bt_par_test_par_as_ref_param_node12()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_long_0") == 1828293308u);
			long& method_p0 = (long&)pAgent->GetVariable<long >(1828293308u);
			((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_LongRef, void, long& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_long_0") == 1828293308u);
			pAgent->SetVariable("par1_long_0", method_p0, 1828293308u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_par_as_ref_param_node18 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node18, Action);
		Action_bt_par_test_par_as_ref_param_node18()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_kemployee_0") == 4045482770u);
			TNS::ST::PER::WRK::kEmployee& method_p0 = (TNS::ST::PER::WRK::kEmployee&)pAgent->GetVariable<TNS::ST::PER::WRK::kEmployee >(4045482770u);
			((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_kEmployeeRef, void, TNS::ST::PER::WRK::kEmployee& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_kemployee_0") == 4045482770u);
			pAgent->SetVariable("par1_kemployee_0", method_p0, 4045482770u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_par_as_ref_param_node19 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node19, Action);
		Action_bt_par_test_par_as_ref_param_node19()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_kemployee_list_0") == 506976637u);
			behaviac::vector<TNS::ST::PER::WRK::kEmployee>& method_p0 = (behaviac::vector<TNS::ST::PER::WRK::kEmployee>&)pAgent->GetVariable<behaviac::vector<TNS::ST::PER::WRK::kEmployee> >(506976637u);
			((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_kEmployeeListRef, void, behaviac::vector<TNS::ST::PER::WRK::kEmployee>& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_kemployee_list_0") == 506976637u);
			pAgent->SetVariable("par1_kemployee_list_0", method_p0, 506976637u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_par_as_ref_param_node20 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node20, Action);
		Action_bt_par_test_par_as_ref_param_node20()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_ushort_0") == 109865111u);
			unsigned short& method_p0 = (unsigned short&)pAgent->GetVariable<unsigned short >(109865111u);
			((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_UShortRef, void, unsigned short& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_ushort_0") == 109865111u);
			pAgent->SetVariable("par1_ushort_0", method_p0, 109865111u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_par_as_ref_param_node16 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node16, Action);
		Action_bt_par_test_par_as_ref_param_node16()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_boolean_0") == 1912381985u);
			bool& method_p0 = (bool&)pAgent->GetVariable<bool >(1912381985u);
			((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_BooleanRef, void, bool& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_boolean_0") == 1912381985u);
			pAgent->SetVariable("par0_boolean_0", method_p0, 1912381985u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_par_as_ref_param_node21 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node21, Action);
		Action_bt_par_test_par_as_ref_param_node21()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_boolean_list_0") == 109714028u);
			behaviac::vector<bool>& method_p0 = (behaviac::vector<bool>&)pAgent->GetVariable<behaviac::vector<bool> >(109714028u);
			((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_BooleanListRef, void, behaviac::vector<bool>& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_boolean_list_0") == 109714028u);
			pAgent->SetVariable("par0_boolean_list_0", method_p0, 109714028u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_par_as_ref_param_node15 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node15, Action);
		Action_bt_par_test_par_as_ref_param_node15()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_byte_0") == 2120958860u);
			unsigned char& method_p0 = (unsigned char&)pAgent->GetVariable<unsigned char >(2120958860u);
			((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_ByteRef, void, unsigned char& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_byte_0") == 2120958860u);
			pAgent->SetVariable("par0_byte_0", method_p0, 2120958860u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_par_as_ref_param_node29 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node29, Action);
		Action_bt_par_test_par_as_ref_param_node29()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_byte_list_0") == 1459492261u);
			behaviac::vector<unsigned char>& method_p0 = (behaviac::vector<unsigned char>&)pAgent->GetVariable<behaviac::vector<unsigned char> >(1459492261u);
			((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_ByteListRef, void, behaviac::vector<unsigned char>& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_byte_list_0") == 1459492261u);
			pAgent->SetVariable("par0_byte_list_0", method_p0, 1459492261u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_par_as_ref_param_node26 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node26, Action);
		Action_bt_par_test_par_as_ref_param_node26()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_char_0") == 1968762578u);
			char& method_p0 = (char&)pAgent->GetVariable<char >(1968762578u);
			((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_CharRef, void, char& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_char_0") == 1968762578u);
			pAgent->SetVariable("par0_char_0", method_p0, 1968762578u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_par_as_ref_param_node27 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node27, Action);
		Action_bt_par_test_par_as_ref_param_node27()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_char_list_0") == 2869241813u);
			behaviac::vector<char>& method_p0 = (behaviac::vector<char>&)pAgent->GetVariable<behaviac::vector<char> >(2869241813u);
			((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_CharListRef, void, behaviac::vector<char>& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_char_list_0") == 2869241813u);
			pAgent->SetVariable("par0_char_list_0", method_p0, 2869241813u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_par_as_ref_param_node24 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node24, Action);
		Action_bt_par_test_par_as_ref_param_node24()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_ecolor_0") == 3914433730u);
			TNS::NE::NAT::eColor& method_p0 = (TNS::NE::NAT::eColor&)pAgent->GetVariable<TNS::NE::NAT::eColor >(3914433730u);
			((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_eColorRef, void, TNS::NE::NAT::eColor& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_ecolor_0") == 3914433730u);
			pAgent->SetVariable("par0_ecolor_0", method_p0, 3914433730u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_par_as_ref_param_node25 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node25, Action);
		Action_bt_par_test_par_as_ref_param_node25()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_ecolor_list_0") == 1963776920u);
			behaviac::vector<TNS::NE::NAT::eColor>& method_p0 = (behaviac::vector<TNS::NE::NAT::eColor>&)pAgent->GetVariable<behaviac::vector<TNS::NE::NAT::eColor> >(1963776920u);
			((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_eColorListRef, void, behaviac::vector<TNS::NE::NAT::eColor>& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_ecolor_list_0") == 1963776920u);
			pAgent->SetVariable("par0_ecolor_list_0", method_p0, 1963776920u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_par_as_ref_param_node23 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node23, Action);
		Action_bt_par_test_par_as_ref_param_node23()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_sbyte_0") == 968869870u);
			signed char& method_p0 = (signed char&)pAgent->GetVariable<signed char >(968869870u);
			((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_SByteRef, void, signed char& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_sbyte_0") == 968869870u);
			pAgent->SetVariable("par0_sbyte_0", method_p0, 968869870u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_par_as_ref_param_node28 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node28, Action);
		Action_bt_par_test_par_as_ref_param_node28()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_sbyte_list_0") == 2290963684u);
			behaviac::vector<signed char>& method_p0 = (behaviac::vector<signed char>&)pAgent->GetVariable<behaviac::vector<signed char> >(2290963684u);
			((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_SByteListRef, void, behaviac::vector<signed char>& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_sbyte_list_0") == 2290963684u);
			pAgent->SetVariable("par0_sbyte_list_0", method_p0, 2290963684u);
			return BT_SUCCESS;
		}
	};

	class DecoratorLoop_bt_par_test_par_as_ref_param_node33 : public DecoratorLoop
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorLoop_bt_par_test_par_as_ref_param_node33, DecoratorLoop);
		DecoratorLoop_bt_par_test_par_as_ref_param_node33()
		{
			m_bDecorateWhenChildEnds = true;
			m_bDoneWithinFrame = false;
		}
	protected:
		virtual int GetCount(Agent* pAgent) const
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			return -1;
		}
	};

		bool bt_par_test_par_as_ref_param::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("par_test/par_as_ref_param");
			pBT->SetIsFSM(false);
#if !BEHAVIAC_RELEASE
			pBT->SetAgentType("EmployeeParTestAgent");
#endif
			// pars
			pBT->AddPar("EmployeeParTestAgent", "bool", "par0_boolean_0", "false");
			pBT->AddPar("EmployeeParTestAgent", "vector<bool>", "par0_boolean_list_0", "0:");
			pBT->AddPar("EmployeeParTestAgent", "ubyte", "par0_byte_0", "0");
			pBT->AddPar("EmployeeParTestAgent", "vector<ubyte>", "par0_byte_list_0", "0:");
			pBT->AddPar("EmployeeParTestAgent", "char", "par0_char_0", "A");
			pBT->AddPar("EmployeeParTestAgent", "vector<char>", "par0_char_list_0", "0:");
			pBT->AddPar("EmployeeParTestAgent", "TNS::NE::NAT::eColor", "par0_ecolor_0", "WHITE");
			pBT->AddPar("EmployeeParTestAgent", "vector<TNS::NE::NAT::eColor>", "par0_ecolor_list_0", "0:");
			pBT->AddPar("EmployeeParTestAgent", "sbyte", "par0_sbyte_0", "0");
			pBT->AddPar("EmployeeParTestAgent", "vector<sbyte>", "par0_sbyte_list_0", "0:");
			pBT->AddPar("EmployeeParTestAgent", "short", "par1_short_0", "0");
			pBT->AddPar("EmployeeParTestAgent", "int", "par1_int_0", "0");
			pBT->AddPar("EmployeeParTestAgent", "vector<int>", "par1_int_list_0", "0:");
			pBT->AddPar("EmployeeParTestAgent", "long", "par1_long_0", "0");
			pBT->AddPar("EmployeeParTestAgent", "TNS::ST::PER::WRK::kEmployee", "par1_kemployee_0", "{boss=null;car={brand=\"\";color=RED;price=0;};code=c;id=0;isMale=false;name=\"tomlp\";skinColor=RED;weight=0;}");
			pBT->AddPar("EmployeeParTestAgent", "vector<TNS::ST::PER::WRK::kEmployee>", "par1_kemployee_list_0", "0:");
			pBT->AddPar("EmployeeParTestAgent", "ushort", "par1_ushort_0", "0");
			pBT->AddPar("EmployeeParTestAgent", "behaviac::Agent", "par2_agent_0", "null");
			pBT->AddPar("EmployeeParTestAgent", "vector<behaviac::Agent>", "par2_agent_list_0", "0:");
			pBT->AddPar("EmployeeParTestAgent", "double", "par2_double_0", "0");
			pBT->AddPar("EmployeeParTestAgent", "float", "par2_single_0", "0");
			pBT->AddPar("EmployeeParTestAgent", "vector<float>", "par2_single_list_0", "0:");
			pBT->AddPar("EmployeeParTestAgent", "string", "par2_string_0", "");
			pBT->AddPar("EmployeeParTestAgent", "vector<string>", "par2_string_list_0", "0:");
			pBT->AddPar("EmployeeParTestAgent", "uint", "par2_uint_0", "0");
			pBT->AddPar("EmployeeParTestAgent", "ulong", "par2_ulong_0", "0");
			pBT->AddPar("EmployeeParTestAgent", "string", "par2_SzString_0", "this is char* test");
			pBT->AddPar("EmployeeParTestAgent", "string", "par2_CSzStrng_0", "this is const char* test");
			pBT->AddPar("EmployeeParTestAgent", "llong", "par2_longlong_0", "-666");
			pBT->AddPar("EmployeeParTestAgent", "ullong", "par2_ulonglong_0", "666");
			// children
			{
				Sequence* node13 = BEHAVIAC_NEW Sequence;
				node13->SetClassNameString("Sequence");
				node13->SetId(13);
#if !BEHAVIAC_RELEASE
				node13->SetAgentType("EmployeeParTestAgent");
#endif
				pBT->AddChild(node13);
				{
					Sequence* node30 = BEHAVIAC_NEW Sequence;
					node30->SetClassNameString("Sequence");
					node30->SetId(30);
#if !BEHAVIAC_RELEASE
					node30->SetAgentType("EmployeeParTestAgent");
#endif
					node13->AddChild(node30);
					{
						Sequence* node1 = BEHAVIAC_NEW Sequence;
						node1->SetClassNameString("Sequence");
						node1->SetId(1);
#if !BEHAVIAC_RELEASE
						node1->SetAgentType("EmployeeParTestAgent");
#endif
						node30->AddChild(node1);
						{
							Action_bt_par_test_par_as_ref_param_node0* node0 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node0;
							node0->SetClassNameString("Action");
							node0->SetId(0);
#if !BEHAVIAC_RELEASE
							node0->SetAgentType("EmployeeParTestAgent");
#endif
							node1->AddChild(node0);
							node1->SetHasEvents(node1->HasEvents() | node0->HasEvents());
						}
						{
							Action_bt_par_test_par_as_ref_param_node17* node17 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node17;
							node17->SetClassNameString("Action");
							node17->SetId(17);
#if !BEHAVIAC_RELEASE
							node17->SetAgentType("EmployeeParTestAgent");
#endif
							node1->AddChild(node17);
							node1->SetHasEvents(node1->HasEvents() | node17->HasEvents());
						}
						{
							Action_bt_par_test_par_as_ref_param_node2* node2 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node2;
							node2->SetClassNameString("Action");
							node2->SetId(2);
#if !BEHAVIAC_RELEASE
							node2->SetAgentType("EmployeeParTestAgent");
#endif
							node1->AddChild(node2);
							node1->SetHasEvents(node1->HasEvents() | node2->HasEvents());
						}
						{
							Action_bt_par_test_par_as_ref_param_node3* node3 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node3;
							node3->SetClassNameString("Action");
							node3->SetId(3);
#if !BEHAVIAC_RELEASE
							node3->SetAgentType("EmployeeParTestAgent");
#endif
							node1->AddChild(node3);
							node1->SetHasEvents(node1->HasEvents() | node3->HasEvents());
						}
						{
							Action_bt_par_test_par_as_ref_param_node4* node4 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node4;
							node4->SetClassNameString("Action");
							node4->SetId(4);
#if !BEHAVIAC_RELEASE
							node4->SetAgentType("EmployeeParTestAgent");
#endif
							node1->AddChild(node4);
							node1->SetHasEvents(node1->HasEvents() | node4->HasEvents());
						}
						{
							Action_bt_par_test_par_as_ref_param_node5* node5 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node5;
							node5->SetClassNameString("Action");
							node5->SetId(5);
#if !BEHAVIAC_RELEASE
							node5->SetAgentType("EmployeeParTestAgent");
#endif
							node1->AddChild(node5);
							node1->SetHasEvents(node1->HasEvents() | node5->HasEvents());
						}
						{
							Action_bt_par_test_par_as_ref_param_node6* node6 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node6;
							node6->SetClassNameString("Action");
							node6->SetId(6);
#if !BEHAVIAC_RELEASE
							node6->SetAgentType("EmployeeParTestAgent");
#endif
							node1->AddChild(node6);
							node1->SetHasEvents(node1->HasEvents() | node6->HasEvents());
						}
						{
							Action_bt_par_test_par_as_ref_param_node7* node7 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node7;
							node7->SetClassNameString("Action");
							node7->SetId(7);
#if !BEHAVIAC_RELEASE
							node7->SetAgentType("EmployeeParTestAgent");
#endif
							node1->AddChild(node7);
							node1->SetHasEvents(node1->HasEvents() | node7->HasEvents());
						}
						{
							Action_bt_par_test_par_as_ref_param_node8* node8 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node8;
							node8->SetClassNameString("Action");
							node8->SetId(8);
#if !BEHAVIAC_RELEASE
							node8->SetAgentType("EmployeeParTestAgent");
#endif
							node1->AddChild(node8);
							node1->SetHasEvents(node1->HasEvents() | node8->HasEvents());
						}
						{
							Action_bt_par_test_par_as_ref_param_node35* node35 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node35;
							node35->SetClassNameString("Action");
							node35->SetId(35);
#if !BEHAVIAC_RELEASE
							node35->SetAgentType("EmployeeParTestAgent");
#endif
							node1->AddChild(node35);
							node1->SetHasEvents(node1->HasEvents() | node35->HasEvents());
						}
						{
							Action_bt_par_test_par_as_ref_param_node36* node36 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node36;
							node36->SetClassNameString("Action");
							node36->SetId(36);
#if !BEHAVIAC_RELEASE
							node36->SetAgentType("EmployeeParTestAgent");
#endif
							node1->AddChild(node36);
							node1->SetHasEvents(node1->HasEvents() | node36->HasEvents());
						}
						{
							Action_bt_par_test_par_as_ref_param_node31* node31 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node31;
							node31->SetClassNameString("Action");
							node31->SetId(31);
#if !BEHAVIAC_RELEASE
							node31->SetAgentType("EmployeeParTestAgent");
#endif
							node1->AddChild(node31);
							node1->SetHasEvents(node1->HasEvents() | node31->HasEvents());
						}
						{
							Action_bt_par_test_par_as_ref_param_node32* node32 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node32;
							node32->SetClassNameString("Action");
							node32->SetId(32);
#if !BEHAVIAC_RELEASE
							node32->SetAgentType("EmployeeParTestAgent");
#endif
							node1->AddChild(node32);
							node1->SetHasEvents(node1->HasEvents() | node32->HasEvents());
						}
						node30->SetHasEvents(node30->HasEvents() | node1->HasEvents());
					}
					{
						Sequence* node14 = BEHAVIAC_NEW Sequence;
						node14->SetClassNameString("Sequence");
						node14->SetId(14);
#if !BEHAVIAC_RELEASE
						node14->SetAgentType("EmployeeParTestAgent");
#endif
						node30->AddChild(node14);
						{
							Action_bt_par_test_par_as_ref_param_node9* node9 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node9;
							node9->SetClassNameString("Action");
							node9->SetId(9);
#if !BEHAVIAC_RELEASE
							node9->SetAgentType("EmployeeParTestAgent");
#endif
							node14->AddChild(node9);
							node14->SetHasEvents(node14->HasEvents() | node9->HasEvents());
						}
						{
							Action_bt_par_test_par_as_ref_param_node10* node10 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node10;
							node10->SetClassNameString("Action");
							node10->SetId(10);
#if !BEHAVIAC_RELEASE
							node10->SetAgentType("EmployeeParTestAgent");
#endif
							node14->AddChild(node10);
							node14->SetHasEvents(node14->HasEvents() | node10->HasEvents());
						}
						{
							Action_bt_par_test_par_as_ref_param_node11* node11 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node11;
							node11->SetClassNameString("Action");
							node11->SetId(11);
#if !BEHAVIAC_RELEASE
							node11->SetAgentType("EmployeeParTestAgent");
#endif
							node14->AddChild(node11);
							node14->SetHasEvents(node14->HasEvents() | node11->HasEvents());
						}
						{
							Action_bt_par_test_par_as_ref_param_node12* node12 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node12;
							node12->SetClassNameString("Action");
							node12->SetId(12);
#if !BEHAVIAC_RELEASE
							node12->SetAgentType("EmployeeParTestAgent");
#endif
							node14->AddChild(node12);
							node14->SetHasEvents(node14->HasEvents() | node12->HasEvents());
						}
						{
							Action_bt_par_test_par_as_ref_param_node18* node18 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node18;
							node18->SetClassNameString("Action");
							node18->SetId(18);
#if !BEHAVIAC_RELEASE
							node18->SetAgentType("EmployeeParTestAgent");
#endif
							node14->AddChild(node18);
							node14->SetHasEvents(node14->HasEvents() | node18->HasEvents());
						}
						{
							Action_bt_par_test_par_as_ref_param_node19* node19 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node19;
							node19->SetClassNameString("Action");
							node19->SetId(19);
#if !BEHAVIAC_RELEASE
							node19->SetAgentType("EmployeeParTestAgent");
#endif
							node14->AddChild(node19);
							node14->SetHasEvents(node14->HasEvents() | node19->HasEvents());
						}
						{
							Action_bt_par_test_par_as_ref_param_node20* node20 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node20;
							node20->SetClassNameString("Action");
							node20->SetId(20);
#if !BEHAVIAC_RELEASE
							node20->SetAgentType("EmployeeParTestAgent");
#endif
							node14->AddChild(node20);
							node14->SetHasEvents(node14->HasEvents() | node20->HasEvents());
						}
						node30->SetHasEvents(node30->HasEvents() | node14->HasEvents());
					}
					{
						Sequence* node22 = BEHAVIAC_NEW Sequence;
						node22->SetClassNameString("Sequence");
						node22->SetId(22);
#if !BEHAVIAC_RELEASE
						node22->SetAgentType("EmployeeParTestAgent");
#endif
						node30->AddChild(node22);
						{
							Action_bt_par_test_par_as_ref_param_node16* node16 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node16;
							node16->SetClassNameString("Action");
							node16->SetId(16);
#if !BEHAVIAC_RELEASE
							node16->SetAgentType("EmployeeParTestAgent");
#endif
							node22->AddChild(node16);
							node22->SetHasEvents(node22->HasEvents() | node16->HasEvents());
						}
						{
							Action_bt_par_test_par_as_ref_param_node21* node21 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node21;
							node21->SetClassNameString("Action");
							node21->SetId(21);
#if !BEHAVIAC_RELEASE
							node21->SetAgentType("EmployeeParTestAgent");
#endif
							node22->AddChild(node21);
							node22->SetHasEvents(node22->HasEvents() | node21->HasEvents());
						}
						{
							Action_bt_par_test_par_as_ref_param_node15* node15 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node15;
							node15->SetClassNameString("Action");
							node15->SetId(15);
#if !BEHAVIAC_RELEASE
							node15->SetAgentType("EmployeeParTestAgent");
#endif
							node22->AddChild(node15);
							node22->SetHasEvents(node22->HasEvents() | node15->HasEvents());
						}
						{
							Action_bt_par_test_par_as_ref_param_node29* node29 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node29;
							node29->SetClassNameString("Action");
							node29->SetId(29);
#if !BEHAVIAC_RELEASE
							node29->SetAgentType("EmployeeParTestAgent");
#endif
							node22->AddChild(node29);
							node22->SetHasEvents(node22->HasEvents() | node29->HasEvents());
						}
						{
							Action_bt_par_test_par_as_ref_param_node26* node26 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node26;
							node26->SetClassNameString("Action");
							node26->SetId(26);
#if !BEHAVIAC_RELEASE
							node26->SetAgentType("EmployeeParTestAgent");
#endif
							node22->AddChild(node26);
							node22->SetHasEvents(node22->HasEvents() | node26->HasEvents());
						}
						{
							Action_bt_par_test_par_as_ref_param_node27* node27 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node27;
							node27->SetClassNameString("Action");
							node27->SetId(27);
#if !BEHAVIAC_RELEASE
							node27->SetAgentType("EmployeeParTestAgent");
#endif
							node22->AddChild(node27);
							node22->SetHasEvents(node22->HasEvents() | node27->HasEvents());
						}
						{
							Action_bt_par_test_par_as_ref_param_node24* node24 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node24;
							node24->SetClassNameString("Action");
							node24->SetId(24);
#if !BEHAVIAC_RELEASE
							node24->SetAgentType("EmployeeParTestAgent");
#endif
							node22->AddChild(node24);
							node22->SetHasEvents(node22->HasEvents() | node24->HasEvents());
						}
						{
							Action_bt_par_test_par_as_ref_param_node25* node25 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node25;
							node25->SetClassNameString("Action");
							node25->SetId(25);
#if !BEHAVIAC_RELEASE
							node25->SetAgentType("EmployeeParTestAgent");
#endif
							node22->AddChild(node25);
							node22->SetHasEvents(node22->HasEvents() | node25->HasEvents());
						}
						{
							Action_bt_par_test_par_as_ref_param_node23* node23 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node23;
							node23->SetClassNameString("Action");
							node23->SetId(23);
#if !BEHAVIAC_RELEASE
							node23->SetAgentType("EmployeeParTestAgent");
#endif
							node22->AddChild(node23);
							node22->SetHasEvents(node22->HasEvents() | node23->HasEvents());
						}
						{
							Action_bt_par_test_par_as_ref_param_node28* node28 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node28;
							node28->SetClassNameString("Action");
							node28->SetId(28);
#if !BEHAVIAC_RELEASE
							node28->SetAgentType("EmployeeParTestAgent");
#endif
							node22->AddChild(node28);
							node22->SetHasEvents(node22->HasEvents() | node28->HasEvents());
						}
						node30->SetHasEvents(node30->HasEvents() | node22->HasEvents());
					}
					node13->SetHasEvents(node13->HasEvents() | node30->HasEvents());
				}
				{
					DecoratorLoop_bt_par_test_par_as_ref_param_node33* node33 = BEHAVIAC_NEW DecoratorLoop_bt_par_test_par_as_ref_param_node33;
					node33->SetClassNameString("DecoratorLoop");
					node33->SetId(33);
#if !BEHAVIAC_RELEASE
					node33->SetAgentType("EmployeeParTestAgent");
#endif
					node13->AddChild(node33);
					{
						Noop* node34 = BEHAVIAC_NEW Noop;
						node34->SetClassNameString("Noop");
						node34->SetId(34);
#if !BEHAVIAC_RELEASE
						node34->SetAgentType("EmployeeParTestAgent");
#endif
						node33->AddChild(node34);
						node33->SetHasEvents(node33->HasEvents() | node34->HasEvents());
					}
					node13->SetHasEvents(node13->HasEvents() | node33->HasEvents());
				}
				pBT->SetHasEvents(pBT->HasEvents() | node13->HasEvents());
			}
			return true;
		}

	// Source file: par_test/property_as_left_value

	class Assignment_bt_par_test_property_as_left_value_node0 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_node0, Assignment);
		Assignment_bt_par_test_property_as_left_value_node0()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_agent_0") == 3876418331u);
			behaviac::Agent*& opr_p0 = (behaviac::Agent*&)pAgent->GetVariable<behaviac::Agent* >(3876418331u);
			behaviac::Agent* opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_AgentIR, behaviac::Agent*, behaviac::Agent* >(opr_p0);
			((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_AGENT_0, behaviac::Agent* >() = opr;
			return result;
		}
	};

	class Assignment_bt_par_test_property_as_left_value_node15 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_node15, Assignment);
		Assignment_bt_par_test_property_as_left_value_node15()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_agent_list_0") == 1126732011u);
			behaviac::vector<behaviac::Agent*>& opr_p0 = (behaviac::vector<behaviac::Agent*>&)pAgent->GetVariable<behaviac::vector<behaviac::Agent*> >(1126732011u);
			behaviac::vector<behaviac::Agent*> opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_AgentListIR, behaviac::vector<behaviac::Agent*>, behaviac::vector<behaviac::Agent*> >(opr_p0);
			((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_LIST_AGENT_0, behaviac::vector<behaviac::Agent*> >() = opr;
			return result;
		}
	};

	class Assignment_bt_par_test_property_as_left_value_node2 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_node2, Assignment);
		Assignment_bt_par_test_property_as_left_value_node2()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_double_0") == 2183367433u);
			double& opr_p0 = (double&)pAgent->GetVariable<double >(2183367433u);
			double opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_DoubleIR, double, double >(opr_p0);
			((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_D_0, double >() = opr;
			return result;
		}
	};

	class Assignment_bt_par_test_property_as_left_value_node3 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_node3, Assignment);
		Assignment_bt_par_test_property_as_left_value_node3()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_single_0") == 3120166065u);
			float& opr_p0 = (float&)pAgent->GetVariable<float >(3120166065u);
			float opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_SingleIR, float, float >(opr_p0);
			((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_F_0, float >() = opr;
			return result;
		}
	};

	class Assignment_bt_par_test_property_as_left_value_node4 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_node4, Assignment);
		Assignment_bt_par_test_property_as_left_value_node4()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_single_list_0") == 3448877207u);
			behaviac::vector<float>& opr_p0 = (behaviac::vector<float>&)pAgent->GetVariable<behaviac::vector<float> >(3448877207u);
			behaviac::vector<float> opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_SingleListIR, behaviac::vector<float>, behaviac::vector<float> >(opr_p0);
			((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_LIST_F_0, behaviac::vector<float> >() = opr;
			return result;
		}
	};

	class Assignment_bt_par_test_property_as_left_value_node5 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_node5, Assignment);
		Assignment_bt_par_test_property_as_left_value_node5()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_string_0") == 351984746u);
			behaviac::string& opr_p0 = (behaviac::string&)pAgent->GetVariable<behaviac::string >(351984746u);
			behaviac::string opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_StringIR, behaviac::string, behaviac::string& >(opr_p0);
			((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_STR_0, behaviac::string >() = opr;
			return result;
		}
	};

	class Assignment_bt_par_test_property_as_left_value_node6 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_node6, Assignment);
		Assignment_bt_par_test_property_as_left_value_node6()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_string_list_0") == 1339885043u);
			behaviac::vector<behaviac::string>& opr_p0 = (behaviac::vector<behaviac::string>&)pAgent->GetVariable<behaviac::vector<behaviac::string> >(1339885043u);
			behaviac::vector<behaviac::string> opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_StringListIR, behaviac::vector<behaviac::string>, behaviac::vector<behaviac::string> >(opr_p0);
			((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_LIST_STR_0, behaviac::vector<behaviac::string> >() = opr;
			return result;
		}
	};

	class Assignment_bt_par_test_property_as_left_value_node7 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_node7, Assignment);
		Assignment_bt_par_test_property_as_left_value_node7()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_uint_0") == 868709384u);
			unsigned int& opr_p0 = (unsigned int&)pAgent->GetVariable<unsigned int >(868709384u);
			unsigned int opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_UIntIR, unsigned int, unsigned int >(opr_p0);
			((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_UINT_0, unsigned int >() = opr;
			return result;
		}
	};

	class Assignment_bt_par_test_property_as_left_value_node8 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_node8, Assignment);
		Assignment_bt_par_test_property_as_left_value_node8()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_ulong_0") == 4274832167u);
			unsigned long& opr_p0 = (unsigned long&)pAgent->GetVariable<unsigned long >(4274832167u);
			unsigned long opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_ULongIR, unsigned long, unsigned long >(opr_p0);
			((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_ULONG_0, unsigned long >() = opr;
			return result;
		}
	};

	class Assignment_bt_par_test_property_as_left_value_node30 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_node30, Assignment);
		Assignment_bt_par_test_property_as_left_value_node30()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			long long opr = -666;
			((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_LL_0, long long >() = opr;
			return result;
		}
	};

	class Assignment_bt_par_test_property_as_left_value_node31 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_node31, Assignment);
		Assignment_bt_par_test_property_as_left_value_node31()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			unsigned long long opr = 666;
			((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_ULL_0, unsigned long long >() = opr;
			return result;
		}
	};

	class Assignment_bt_par_test_property_as_left_value_node9 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_node9, Assignment);
		Assignment_bt_par_test_property_as_left_value_node9()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_short_0") == 3228030786u);
			short& opr_p0 = (short&)pAgent->GetVariable<short >(3228030786u);
			short opr = ((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_ShortIR, short, short >(opr_p0);
			((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_SHORT_0, short >() = opr;
			return result;
		}
	};

	class Assignment_bt_par_test_property_as_left_value_node10 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_node10, Assignment);
		Assignment_bt_par_test_property_as_left_value_node10()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_int_0") == 2735162453u);
			int& opr_p0 = (int&)pAgent->GetVariable<int >(2735162453u);
			int opr = ((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_IntIR, int, int >(opr_p0);
			((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_INT_0, int >() = opr;
			return result;
		}
	};

	class Assignment_bt_par_test_property_as_left_value_node11 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_node11, Assignment);
		Assignment_bt_par_test_property_as_left_value_node11()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_int_list_0") == 2093180786u);
			behaviac::vector<int>& opr_p0 = (behaviac::vector<int>&)pAgent->GetVariable<behaviac::vector<int> >(2093180786u);
			behaviac::vector<int> opr = ((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_IntListIR, behaviac::vector<int>, behaviac::vector<int> >(opr_p0);
			((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_LIST_INT_0, behaviac::vector<int> >() = opr;
			return result;
		}
	};

	class Assignment_bt_par_test_property_as_left_value_node12 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_node12, Assignment);
		Assignment_bt_par_test_property_as_left_value_node12()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_long_0") == 1828293308u);
			long& opr_p0 = (long&)pAgent->GetVariable<long >(1828293308u);
			long opr = ((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_LongIR, long, long >(opr_p0);
			((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_LONG_0, long >() = opr;
			return result;
		}
	};

	class Assignment_bt_par_test_property_as_left_value_node17 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_node17, Assignment);
		Assignment_bt_par_test_property_as_left_value_node17()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_kemployee_0") == 4045482770u);
			TNS::ST::PER::WRK::kEmployee& opr_p0 = (TNS::ST::PER::WRK::kEmployee&)pAgent->GetVariable<TNS::ST::PER::WRK::kEmployee >(4045482770u);
			TNS::ST::PER::WRK::kEmployee opr = ((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_kEmployeeIR, TNS::ST::PER::WRK::kEmployee, TNS::ST::PER::WRK::kEmployee >(opr_p0);
			((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_KEMPLOYEE_0, TNS::ST::PER::WRK::kEmployee >() = opr;
			return result;
		}
	};

	class Assignment_bt_par_test_property_as_left_value_node19 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_node19, Assignment);
		Assignment_bt_par_test_property_as_left_value_node19()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_kemployee_list_0") == 506976637u);
			behaviac::vector<TNS::ST::PER::WRK::kEmployee>& opr_p0 = (behaviac::vector<TNS::ST::PER::WRK::kEmployee>&)pAgent->GetVariable<behaviac::vector<TNS::ST::PER::WRK::kEmployee> >(506976637u);
			behaviac::vector<TNS::ST::PER::WRK::kEmployee> opr = ((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_kEmployeeListIR, behaviac::vector<TNS::ST::PER::WRK::kEmployee>, behaviac::vector<TNS::ST::PER::WRK::kEmployee> >(opr_p0);
			((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_LIST_KEMPLOYEE_0, behaviac::vector<TNS::ST::PER::WRK::kEmployee> >() = opr;
			return result;
		}
	};

	class Assignment_bt_par_test_property_as_left_value_node18 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_node18, Assignment);
		Assignment_bt_par_test_property_as_left_value_node18()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_ushort_0") == 109865111u);
			unsigned short& opr_p0 = (unsigned short&)pAgent->GetVariable<unsigned short >(109865111u);
			unsigned short opr = ((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_UShortIR, unsigned short, unsigned short >(opr_p0);
			((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_USHORT_0, unsigned short >() = opr;
			return result;
		}
	};

	class Assignment_bt_par_test_property_as_left_value_node16 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_node16, Assignment);
		Assignment_bt_par_test_property_as_left_value_node16()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_boolean_0") == 1912381985u);
			bool& opr_p0 = (bool&)pAgent->GetVariable<bool >(1912381985u);
			bool opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_BooleanIR, bool, bool >(opr_p0);
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_BOOL_0, bool >() = opr;
			return result;
		}
	};

	class Assignment_bt_par_test_property_as_left_value_node20 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_node20, Assignment);
		Assignment_bt_par_test_property_as_left_value_node20()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_boolean_list_0") == 109714028u);
			behaviac::vector<bool>& opr_p0 = (behaviac::vector<bool>&)pAgent->GetVariable<behaviac::vector<bool> >(109714028u);
			behaviac::vector<bool> opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_BooleanListIR, behaviac::vector<bool>, behaviac::vector<bool> >(opr_p0);
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_BOOL_0, behaviac::vector<bool> >() = opr;
			return result;
		}
	};

	class Assignment_bt_par_test_property_as_left_value_node24 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_node24, Assignment);
		Assignment_bt_par_test_property_as_left_value_node24()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_byte_0") == 2120958860u);
			unsigned char& opr_p0 = (unsigned char&)pAgent->GetVariable<unsigned char >(2120958860u);
			unsigned char opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_ByteIR, unsigned char, unsigned char >(opr_p0);
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_BYTE_0, unsigned char >() = opr;
			return result;
		}
	};

	class Assignment_bt_par_test_property_as_left_value_node25 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_node25, Assignment);
		Assignment_bt_par_test_property_as_left_value_node25()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_byte_list_0") == 1459492261u);
			behaviac::vector<unsigned char>& opr_p0 = (behaviac::vector<unsigned char>&)pAgent->GetVariable<behaviac::vector<unsigned char> >(1459492261u);
			behaviac::vector<unsigned char> opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_ByteListIR, behaviac::vector<unsigned char>, behaviac::vector<unsigned char> >(opr_p0);
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_BYTE_0, behaviac::vector<unsigned char> >() = opr;
			return result;
		}
	};

	class Assignment_bt_par_test_property_as_left_value_node26 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_node26, Assignment);
		Assignment_bt_par_test_property_as_left_value_node26()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_char_0") == 1968762578u);
			char& opr_p0 = (char&)pAgent->GetVariable<char >(1968762578u);
			char opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_CharIR, char, char >(opr_p0);
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_CHAR_0, char >() = opr;
			return result;
		}
	};

	class Assignment_bt_par_test_property_as_left_value_node27 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_node27, Assignment);
		Assignment_bt_par_test_property_as_left_value_node27()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_char_list_0") == 2869241813u);
			behaviac::vector<char>& opr_p0 = (behaviac::vector<char>&)pAgent->GetVariable<behaviac::vector<char> >(2869241813u);
			behaviac::vector<char> opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_CharListIR, behaviac::vector<char>, behaviac::vector<char> >(opr_p0);
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_CHAR_0, behaviac::vector<char> >() = opr;
			return result;
		}
	};

	class Assignment_bt_par_test_property_as_left_value_node21 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_node21, Assignment);
		Assignment_bt_par_test_property_as_left_value_node21()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_ecolor_0") == 3914433730u);
			TNS::NE::NAT::eColor& opr_p0 = (TNS::NE::NAT::eColor&)pAgent->GetVariable<TNS::NE::NAT::eColor >(3914433730u);
			TNS::NE::NAT::eColor opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_eColorIR, TNS::NE::NAT::eColor, TNS::NE::NAT::eColor >(opr_p0);
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_ECOLOR_0, TNS::NE::NAT::eColor >() = opr;
			return result;
		}
	};

	class Assignment_bt_par_test_property_as_left_value_node23 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_node23, Assignment);
		Assignment_bt_par_test_property_as_left_value_node23()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_ecolor_list_0") == 1963776920u);
			behaviac::vector<TNS::NE::NAT::eColor>& opr_p0 = (behaviac::vector<TNS::NE::NAT::eColor>&)pAgent->GetVariable<behaviac::vector<TNS::NE::NAT::eColor> >(1963776920u);
			behaviac::vector<TNS::NE::NAT::eColor> opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_eColorListIR, behaviac::vector<TNS::NE::NAT::eColor>, behaviac::vector<TNS::NE::NAT::eColor> >(opr_p0);
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_ECOLOR_0, behaviac::vector<TNS::NE::NAT::eColor> >() = opr;
			return result;
		}
	};

	class Assignment_bt_par_test_property_as_left_value_node28 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_node28, Assignment);
		Assignment_bt_par_test_property_as_left_value_node28()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_sbyte_0") == 968869870u);
			signed char& opr_p0 = (signed char&)pAgent->GetVariable<signed char >(968869870u);
			signed char opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_SByteIR, signed char, signed char >(opr_p0);
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_SBYTE_0, signed char >() = opr;
			return result;
		}
	};

	class Assignment_bt_par_test_property_as_left_value_node29 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_node29, Assignment);
		Assignment_bt_par_test_property_as_left_value_node29()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_sbyte_list_0") == 2290963684u);
			behaviac::vector<signed char>& opr_p0 = (behaviac::vector<signed char>&)pAgent->GetVariable<behaviac::vector<signed char> >(2290963684u);
			behaviac::vector<signed char> opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_SByteListIR, behaviac::vector<signed char>, behaviac::vector<signed char> >(opr_p0);
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_SBYTE_0, behaviac::vector<signed char> >() = opr;
			return result;
		}
	};

		bool bt_par_test_property_as_left_value::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("par_test/property_as_left_value");
			pBT->SetIsFSM(false);
#if !BEHAVIAC_RELEASE
			pBT->SetAgentType("EmployeeParTestAgent");
#endif
			// pars
			pBT->AddPar("EmployeeParTestAgent", "double", "par2_double_0", "5.7");
			pBT->AddPar("EmployeeParTestAgent", "float", "par2_single_0", "98.2");
			pBT->AddPar("EmployeeParTestAgent", "vector<float>", "par2_single_list_0", "2:5.1|6.2");
			pBT->AddPar("EmployeeParTestAgent", "string", "par2_string_0", "origin");
			pBT->AddPar("EmployeeParTestAgent", "vector<string>", "par2_string_list_0", "4:\"string0\"|\"string1\"|\"string2\"|\"string3\"");
			pBT->AddPar("EmployeeParTestAgent", "uint", "par2_uint_0", "9");
			pBT->AddPar("EmployeeParTestAgent", "ulong", "par2_ulong_0", "300");
			pBT->AddPar("EmployeeParTestAgent", "short", "par1_short_0", "78");
			pBT->AddPar("EmployeeParTestAgent", "int", "par1_int_0", "-3");
			pBT->AddPar("EmployeeParTestAgent", "vector<int>", "par1_int_list_0", "3:9999|12345|0");
			pBT->AddPar("EmployeeParTestAgent", "long", "par1_long_0", "1500");
			pBT->AddPar("EmployeeParTestAgent", "vector<TNS::ST::PER::WRK::kEmployee>", "par1_kemployee_list_0", "1:{boss=null;car={brand=\"Lexus\";color=BLUE;price=93840;};code=q;id=9;isMale=true;name=\"John\";skinColor=GREEN;weight=110;}");
			pBT->AddPar("EmployeeParTestAgent", "ushort", "par1_ushort_0", "2001");
			pBT->AddPar("EmployeeParTestAgent", "bool", "par0_boolean_0", "true");
			pBT->AddPar("EmployeeParTestAgent", "vector<bool>", "par0_boolean_list_0", "2:false|true");
			pBT->AddPar("EmployeeParTestAgent", "TNS::NE::NAT::eColor", "par0_ecolor_0", "YELLOW");
			pBT->AddPar("EmployeeParTestAgent", "vector<TNS::NE::NAT::eColor>", "par0_ecolor_list_0", "2:RED|GREEN");
			pBT->AddPar("EmployeeParTestAgent", "behaviac::Agent", "par2_agent_0", "null");
			pBT->AddPar("EmployeeParTestAgent", "vector<behaviac::Agent>", "par2_agent_list_0", "2:null|null");
			pBT->AddPar("EmployeeParTestAgent", "char", "par0_char_0", "A");
			pBT->AddPar("EmployeeParTestAgent", "TNS::ST::PER::WRK::kEmployee", "par1_kemployee_0", "{boss=null;car={brand=\"Alpha\";color=WHITE;price=5700;};code=A;id=83;isMale=false;name=\"Tom\";skinColor=RED;weight=97.3;}");
			pBT->AddPar("EmployeeParTestAgent", "ubyte", "par0_byte_0", "197");
			pBT->AddPar("EmployeeParTestAgent", "sbyte", "par0_sbyte_0", "-60");
			pBT->AddPar("EmployeeParTestAgent", "vector<char>", "par0_char_list_0", "4:d|j|F|A");
			pBT->AddPar("EmployeeParTestAgent", "vector<sbyte>", "par0_sbyte_list_0", "3:127|-128|0");
			pBT->AddPar("EmployeeParTestAgent", "vector<ubyte>", "par0_byte_list_0", "3:167|23|152");
			// children
			{
				Sequence* node13 = BEHAVIAC_NEW Sequence;
				node13->SetClassNameString("Sequence");
				node13->SetId(13);
#if !BEHAVIAC_RELEASE
				node13->SetAgentType("EmployeeParTestAgent");
#endif
				pBT->AddChild(node13);
				{
					Sequence* node1 = BEHAVIAC_NEW Sequence;
					node1->SetClassNameString("Sequence");
					node1->SetId(1);
#if !BEHAVIAC_RELEASE
					node1->SetAgentType("EmployeeParTestAgent");
#endif
					node13->AddChild(node1);
					{
						Assignment_bt_par_test_property_as_left_value_node0* node0 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_node0;
						node0->SetClassNameString("Assignment");
						node0->SetId(0);
#if !BEHAVIAC_RELEASE
						node0->SetAgentType("EmployeeParTestAgent");
#endif
						node1->AddChild(node0);
						node1->SetHasEvents(node1->HasEvents() | node0->HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_node15* node15 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_node15;
						node15->SetClassNameString("Assignment");
						node15->SetId(15);
#if !BEHAVIAC_RELEASE
						node15->SetAgentType("EmployeeParTestAgent");
#endif
						node1->AddChild(node15);
						node1->SetHasEvents(node1->HasEvents() | node15->HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_node2* node2 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_node2;
						node2->SetClassNameString("Assignment");
						node2->SetId(2);
#if !BEHAVIAC_RELEASE
						node2->SetAgentType("EmployeeParTestAgent");
#endif
						node1->AddChild(node2);
						node1->SetHasEvents(node1->HasEvents() | node2->HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_node3* node3 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_node3;
						node3->SetClassNameString("Assignment");
						node3->SetId(3);
#if !BEHAVIAC_RELEASE
						node3->SetAgentType("EmployeeParTestAgent");
#endif
						node1->AddChild(node3);
						node1->SetHasEvents(node1->HasEvents() | node3->HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_node4* node4 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_node4;
						node4->SetClassNameString("Assignment");
						node4->SetId(4);
#if !BEHAVIAC_RELEASE
						node4->SetAgentType("EmployeeParTestAgent");
#endif
						node1->AddChild(node4);
						node1->SetHasEvents(node1->HasEvents() | node4->HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_node5* node5 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_node5;
						node5->SetClassNameString("Assignment");
						node5->SetId(5);
#if !BEHAVIAC_RELEASE
						node5->SetAgentType("EmployeeParTestAgent");
#endif
						node1->AddChild(node5);
						node1->SetHasEvents(node1->HasEvents() | node5->HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_node6* node6 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_node6;
						node6->SetClassNameString("Assignment");
						node6->SetId(6);
#if !BEHAVIAC_RELEASE
						node6->SetAgentType("EmployeeParTestAgent");
#endif
						node1->AddChild(node6);
						node1->SetHasEvents(node1->HasEvents() | node6->HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_node7* node7 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_node7;
						node7->SetClassNameString("Assignment");
						node7->SetId(7);
#if !BEHAVIAC_RELEASE
						node7->SetAgentType("EmployeeParTestAgent");
#endif
						node1->AddChild(node7);
						node1->SetHasEvents(node1->HasEvents() | node7->HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_node8* node8 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_node8;
						node8->SetClassNameString("Assignment");
						node8->SetId(8);
#if !BEHAVIAC_RELEASE
						node8->SetAgentType("EmployeeParTestAgent");
#endif
						node1->AddChild(node8);
						node1->SetHasEvents(node1->HasEvents() | node8->HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_node30* node30 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_node30;
						node30->SetClassNameString("Assignment");
						node30->SetId(30);
#if !BEHAVIAC_RELEASE
						node30->SetAgentType("EmployeeParTestAgent");
#endif
						node1->AddChild(node30);
						node1->SetHasEvents(node1->HasEvents() | node30->HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_node31* node31 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_node31;
						node31->SetClassNameString("Assignment");
						node31->SetId(31);
#if !BEHAVIAC_RELEASE
						node31->SetAgentType("EmployeeParTestAgent");
#endif
						node1->AddChild(node31);
						node1->SetHasEvents(node1->HasEvents() | node31->HasEvents());
					}
					node13->SetHasEvents(node13->HasEvents() | node1->HasEvents());
				}
				{
					Sequence* node14 = BEHAVIAC_NEW Sequence;
					node14->SetClassNameString("Sequence");
					node14->SetId(14);
#if !BEHAVIAC_RELEASE
					node14->SetAgentType("EmployeeParTestAgent");
#endif
					node13->AddChild(node14);
					{
						Assignment_bt_par_test_property_as_left_value_node9* node9 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_node9;
						node9->SetClassNameString("Assignment");
						node9->SetId(9);
#if !BEHAVIAC_RELEASE
						node9->SetAgentType("EmployeeParTestAgent");
#endif
						node14->AddChild(node9);
						node14->SetHasEvents(node14->HasEvents() | node9->HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_node10* node10 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_node10;
						node10->SetClassNameString("Assignment");
						node10->SetId(10);
#if !BEHAVIAC_RELEASE
						node10->SetAgentType("EmployeeParTestAgent");
#endif
						node14->AddChild(node10);
						node14->SetHasEvents(node14->HasEvents() | node10->HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_node11* node11 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_node11;
						node11->SetClassNameString("Assignment");
						node11->SetId(11);
#if !BEHAVIAC_RELEASE
						node11->SetAgentType("EmployeeParTestAgent");
#endif
						node14->AddChild(node11);
						node14->SetHasEvents(node14->HasEvents() | node11->HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_node12* node12 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_node12;
						node12->SetClassNameString("Assignment");
						node12->SetId(12);
#if !BEHAVIAC_RELEASE
						node12->SetAgentType("EmployeeParTestAgent");
#endif
						node14->AddChild(node12);
						node14->SetHasEvents(node14->HasEvents() | node12->HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_node17* node17 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_node17;
						node17->SetClassNameString("Assignment");
						node17->SetId(17);
#if !BEHAVIAC_RELEASE
						node17->SetAgentType("EmployeeParTestAgent");
#endif
						node14->AddChild(node17);
						node14->SetHasEvents(node14->HasEvents() | node17->HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_node19* node19 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_node19;
						node19->SetClassNameString("Assignment");
						node19->SetId(19);
#if !BEHAVIAC_RELEASE
						node19->SetAgentType("EmployeeParTestAgent");
#endif
						node14->AddChild(node19);
						node14->SetHasEvents(node14->HasEvents() | node19->HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_node18* node18 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_node18;
						node18->SetClassNameString("Assignment");
						node18->SetId(18);
#if !BEHAVIAC_RELEASE
						node18->SetAgentType("EmployeeParTestAgent");
#endif
						node14->AddChild(node18);
						node14->SetHasEvents(node14->HasEvents() | node18->HasEvents());
					}
					node13->SetHasEvents(node13->HasEvents() | node14->HasEvents());
				}
				{
					Sequence* node22 = BEHAVIAC_NEW Sequence;
					node22->SetClassNameString("Sequence");
					node22->SetId(22);
#if !BEHAVIAC_RELEASE
					node22->SetAgentType("EmployeeParTestAgent");
#endif
					node13->AddChild(node22);
					{
						Assignment_bt_par_test_property_as_left_value_node16* node16 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_node16;
						node16->SetClassNameString("Assignment");
						node16->SetId(16);
#if !BEHAVIAC_RELEASE
						node16->SetAgentType("EmployeeParTestAgent");
#endif
						node22->AddChild(node16);
						node22->SetHasEvents(node22->HasEvents() | node16->HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_node20* node20 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_node20;
						node20->SetClassNameString("Assignment");
						node20->SetId(20);
#if !BEHAVIAC_RELEASE
						node20->SetAgentType("EmployeeParTestAgent");
#endif
						node22->AddChild(node20);
						node22->SetHasEvents(node22->HasEvents() | node20->HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_node24* node24 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_node24;
						node24->SetClassNameString("Assignment");
						node24->SetId(24);
#if !BEHAVIAC_RELEASE
						node24->SetAgentType("EmployeeParTestAgent");
#endif
						node22->AddChild(node24);
						node22->SetHasEvents(node22->HasEvents() | node24->HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_node25* node25 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_node25;
						node25->SetClassNameString("Assignment");
						node25->SetId(25);
#if !BEHAVIAC_RELEASE
						node25->SetAgentType("EmployeeParTestAgent");
#endif
						node22->AddChild(node25);
						node22->SetHasEvents(node22->HasEvents() | node25->HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_node26* node26 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_node26;
						node26->SetClassNameString("Assignment");
						node26->SetId(26);
#if !BEHAVIAC_RELEASE
						node26->SetAgentType("EmployeeParTestAgent");
#endif
						node22->AddChild(node26);
						node22->SetHasEvents(node22->HasEvents() | node26->HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_node27* node27 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_node27;
						node27->SetClassNameString("Assignment");
						node27->SetId(27);
#if !BEHAVIAC_RELEASE
						node27->SetAgentType("EmployeeParTestAgent");
#endif
						node22->AddChild(node27);
						node22->SetHasEvents(node22->HasEvents() | node27->HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_node21* node21 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_node21;
						node21->SetClassNameString("Assignment");
						node21->SetId(21);
#if !BEHAVIAC_RELEASE
						node21->SetAgentType("EmployeeParTestAgent");
#endif
						node22->AddChild(node21);
						node22->SetHasEvents(node22->HasEvents() | node21->HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_node23* node23 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_node23;
						node23->SetClassNameString("Assignment");
						node23->SetId(23);
#if !BEHAVIAC_RELEASE
						node23->SetAgentType("EmployeeParTestAgent");
#endif
						node22->AddChild(node23);
						node22->SetHasEvents(node22->HasEvents() | node23->HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_node28* node28 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_node28;
						node28->SetClassNameString("Assignment");
						node28->SetId(28);
#if !BEHAVIAC_RELEASE
						node28->SetAgentType("EmployeeParTestAgent");
#endif
						node22->AddChild(node28);
						node22->SetHasEvents(node22->HasEvents() | node28->HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_node29* node29 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_node29;
						node29->SetClassNameString("Assignment");
						node29->SetId(29);
#if !BEHAVIAC_RELEASE
						node29->SetAgentType("EmployeeParTestAgent");
#endif
						node22->AddChild(node29);
						node22->SetHasEvents(node22->HasEvents() | node29->HasEvents());
					}
					node13->SetHasEvents(node13->HasEvents() | node22->HasEvents());
				}
				pBT->SetHasEvents(pBT->HasEvents() | node13->HasEvents());
			}
			return true;
		}

	// Source file: par_test/property_as_left_value_and_param

	class Assignment_bt_par_test_property_as_left_value_and_param_node0 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_and_param_node0, Assignment);
		Assignment_bt_par_test_property_as_left_value_and_param_node0()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			behaviac::Agent* opr_p0 = ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_AGENT_0, behaviac::Agent* >();
			behaviac::Agent* opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_AgentIR, behaviac::Agent*, behaviac::Agent* >(opr_p0);
			((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_AGENT_0, behaviac::Agent* >() = opr;
			return result;
		}
	};

	class Assignment_bt_par_test_property_as_left_value_and_param_node15 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_and_param_node15, Assignment);
		Assignment_bt_par_test_property_as_left_value_and_param_node15()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			behaviac::vector<behaviac::Agent*> opr_p0 = ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_LIST_AGENT_0, behaviac::vector<behaviac::Agent*> >();
			behaviac::vector<behaviac::Agent*> opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_AgentListIR, behaviac::vector<behaviac::Agent*>, behaviac::vector<behaviac::Agent*> >(opr_p0);
			((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_LIST_AGENT_0, behaviac::vector<behaviac::Agent*> >() = opr;
			return result;
		}
	};

	class Assignment_bt_par_test_property_as_left_value_and_param_node2 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_and_param_node2, Assignment);
		Assignment_bt_par_test_property_as_left_value_and_param_node2()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			double opr_p0 = ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_D_0, double >();
			double opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_DoubleIR, double, double >(opr_p0);
			((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_D_0, double >() = opr;
			return result;
		}
	};

	class Assignment_bt_par_test_property_as_left_value_and_param_node3 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_and_param_node3, Assignment);
		Assignment_bt_par_test_property_as_left_value_and_param_node3()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			float opr_p0 = ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_F_0, float >();
			float opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_SingleIR, float, float >(opr_p0);
			((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_F_0, float >() = opr;
			return result;
		}
	};

	class Assignment_bt_par_test_property_as_left_value_and_param_node4 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_and_param_node4, Assignment);
		Assignment_bt_par_test_property_as_left_value_and_param_node4()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			behaviac::vector<float> opr_p0 = ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_LIST_F_0, behaviac::vector<float> >();
			behaviac::vector<float> opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_SingleListIR, behaviac::vector<float>, behaviac::vector<float> >(opr_p0);
			((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_LIST_F_0, behaviac::vector<float> >() = opr;
			return result;
		}
	};

	class Assignment_bt_par_test_property_as_left_value_and_param_node5 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_and_param_node5, Assignment);
		Assignment_bt_par_test_property_as_left_value_and_param_node5()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			behaviac::string opr_p0 = ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_STR_0, behaviac::string >();
			behaviac::string opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_StringIR, behaviac::string, behaviac::string& >(opr_p0);
			((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_STR_0, behaviac::string >() = opr;
			return result;
		}
	};

	class Assignment_bt_par_test_property_as_left_value_and_param_node6 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_and_param_node6, Assignment);
		Assignment_bt_par_test_property_as_left_value_and_param_node6()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			behaviac::vector<behaviac::string> opr_p0 = ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_LIST_STR_0, behaviac::vector<behaviac::string> >();
			behaviac::vector<behaviac::string> opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_StringListIR, behaviac::vector<behaviac::string>, behaviac::vector<behaviac::string> >(opr_p0);
			((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_LIST_STR_0, behaviac::vector<behaviac::string> >() = opr;
			return result;
		}
	};

	class Assignment_bt_par_test_property_as_left_value_and_param_node7 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_and_param_node7, Assignment);
		Assignment_bt_par_test_property_as_left_value_and_param_node7()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			unsigned int opr_p0 = ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_UINT_0, unsigned int >();
			unsigned int opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_UIntIR, unsigned int, unsigned int >(opr_p0);
			((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_UINT_0, unsigned int >() = opr;
			return result;
		}
	};

	class Assignment_bt_par_test_property_as_left_value_and_param_node8 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_and_param_node8, Assignment);
		Assignment_bt_par_test_property_as_left_value_and_param_node8()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			unsigned long opr_p0 = ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_ULONG_0, unsigned long >();
			unsigned long opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_ULongIR, unsigned long, unsigned long >(opr_p0);
			((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_ULONG_0, unsigned long >() = opr;
			return result;
		}
	};

	class Assignment_bt_par_test_property_as_left_value_and_param_node30 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_and_param_node30, Assignment);
		Assignment_bt_par_test_property_as_left_value_and_param_node30()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			long long opr_p0 = ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_LL_0, long long >();
			long long opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_LongLongIR, long long, long long >(opr_p0);
			((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_LL_0, long long >() = opr;
			return result;
		}
	};

	class Assignment_bt_par_test_property_as_left_value_and_param_node31 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_and_param_node31, Assignment);
		Assignment_bt_par_test_property_as_left_value_and_param_node31()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			unsigned long long opr_p0 = ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_ULL_0, unsigned long long >();
			unsigned long long opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_ULongLongIR, unsigned long long, unsigned long long >(opr_p0);
			((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_ULL_0, unsigned long long >() = opr;
			return result;
		}
	};

	class Assignment_bt_par_test_property_as_left_value_and_param_node9 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_and_param_node9, Assignment);
		Assignment_bt_par_test_property_as_left_value_and_param_node9()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			short opr_p0 = ((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_SHORT_0, short >();
			short opr = ((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_ShortIR, short, short >(opr_p0);
			((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_SHORT_0, short >() = opr;
			return result;
		}
	};

	class Assignment_bt_par_test_property_as_left_value_and_param_node10 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_and_param_node10, Assignment);
		Assignment_bt_par_test_property_as_left_value_and_param_node10()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			int opr_p0 = ((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_INT_0, int >();
			int opr = ((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_IntIR, int, int >(opr_p0);
			((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_INT_0, int >() = opr;
			return result;
		}
	};

	class Assignment_bt_par_test_property_as_left_value_and_param_node11 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_and_param_node11, Assignment);
		Assignment_bt_par_test_property_as_left_value_and_param_node11()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			behaviac::vector<int> opr_p0 = ((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_LIST_INT_0, behaviac::vector<int> >();
			behaviac::vector<int> opr = ((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_IntListIR, behaviac::vector<int>, behaviac::vector<int> >(opr_p0);
			((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_LIST_INT_0, behaviac::vector<int> >() = opr;
			return result;
		}
	};

	class Assignment_bt_par_test_property_as_left_value_and_param_node12 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_and_param_node12, Assignment);
		Assignment_bt_par_test_property_as_left_value_and_param_node12()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			long opr_p0 = ((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_LONG_0, long >();
			long opr = ((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_LongIR, long, long >(opr_p0);
			((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_LONG_0, long >() = opr;
			return result;
		}
	};

	class Assignment_bt_par_test_property_as_left_value_and_param_node17 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_and_param_node17, Assignment);
		Assignment_bt_par_test_property_as_left_value_and_param_node17()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			TNS::ST::PER::WRK::kEmployee opr_p0 = ((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_KEMPLOYEE_0, TNS::ST::PER::WRK::kEmployee >();
			TNS::ST::PER::WRK::kEmployee opr = ((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_kEmployeeIR, TNS::ST::PER::WRK::kEmployee, TNS::ST::PER::WRK::kEmployee >(opr_p0);
			((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_KEMPLOYEE_0, TNS::ST::PER::WRK::kEmployee >() = opr;
			return result;
		}
	};

	class Assignment_bt_par_test_property_as_left_value_and_param_node19 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_and_param_node19, Assignment);
		Assignment_bt_par_test_property_as_left_value_and_param_node19()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			behaviac::vector<TNS::ST::PER::WRK::kEmployee> opr_p0 = ((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_LIST_KEMPLOYEE_0, behaviac::vector<TNS::ST::PER::WRK::kEmployee> >();
			behaviac::vector<TNS::ST::PER::WRK::kEmployee> opr = ((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_kEmployeeListIR, behaviac::vector<TNS::ST::PER::WRK::kEmployee>, behaviac::vector<TNS::ST::PER::WRK::kEmployee> >(opr_p0);
			((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_LIST_KEMPLOYEE_0, behaviac::vector<TNS::ST::PER::WRK::kEmployee> >() = opr;
			return result;
		}
	};

	class Assignment_bt_par_test_property_as_left_value_and_param_node18 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_and_param_node18, Assignment);
		Assignment_bt_par_test_property_as_left_value_and_param_node18()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			unsigned short opr_p0 = ((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_USHORT_0, unsigned short >();
			unsigned short opr = ((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_UShortIR, unsigned short, unsigned short >(opr_p0);
			((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_USHORT_0, unsigned short >() = opr;
			return result;
		}
	};

	class Assignment_bt_par_test_property_as_left_value_and_param_node16 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_and_param_node16, Assignment);
		Assignment_bt_par_test_property_as_left_value_and_param_node16()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			bool opr_p0 = ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_BOOL_0, bool >();
			bool opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_BooleanIR, bool, bool >(opr_p0);
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_BOOL_0, bool >() = opr;
			return result;
		}
	};

	class Assignment_bt_par_test_property_as_left_value_and_param_node20 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_and_param_node20, Assignment);
		Assignment_bt_par_test_property_as_left_value_and_param_node20()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			behaviac::vector<bool> opr_p0 = ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_BOOL_0, behaviac::vector<bool> >();
			behaviac::vector<bool> opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_BooleanListIR, behaviac::vector<bool>, behaviac::vector<bool> >(opr_p0);
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_BOOL_0, behaviac::vector<bool> >() = opr;
			return result;
		}
	};

	class Assignment_bt_par_test_property_as_left_value_and_param_node24 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_and_param_node24, Assignment);
		Assignment_bt_par_test_property_as_left_value_and_param_node24()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			unsigned char opr_p0 = ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_BYTE_0, unsigned char >();
			unsigned char opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_ByteIR, unsigned char, unsigned char >(opr_p0);
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_BYTE_0, unsigned char >() = opr;
			return result;
		}
	};

	class Assignment_bt_par_test_property_as_left_value_and_param_node25 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_and_param_node25, Assignment);
		Assignment_bt_par_test_property_as_left_value_and_param_node25()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			behaviac::vector<unsigned char> opr_p0 = ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_BYTE_0, behaviac::vector<unsigned char> >();
			behaviac::vector<unsigned char> opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_ByteListIR, behaviac::vector<unsigned char>, behaviac::vector<unsigned char> >(opr_p0);
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_BYTE_0, behaviac::vector<unsigned char> >() = opr;
			return result;
		}
	};

	class Assignment_bt_par_test_property_as_left_value_and_param_node26 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_and_param_node26, Assignment);
		Assignment_bt_par_test_property_as_left_value_and_param_node26()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			char opr_p0 = ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_CHAR_0, char >();
			char opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_CharIR, char, char >(opr_p0);
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_CHAR_0, char >() = opr;
			return result;
		}
	};

	class Assignment_bt_par_test_property_as_left_value_and_param_node27 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_and_param_node27, Assignment);
		Assignment_bt_par_test_property_as_left_value_and_param_node27()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			behaviac::vector<char> opr_p0 = ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_CHAR_0, behaviac::vector<char> >();
			behaviac::vector<char> opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_CharListIR, behaviac::vector<char>, behaviac::vector<char> >(opr_p0);
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_CHAR_0, behaviac::vector<char> >() = opr;
			return result;
		}
	};

	class Assignment_bt_par_test_property_as_left_value_and_param_node21 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_and_param_node21, Assignment);
		Assignment_bt_par_test_property_as_left_value_and_param_node21()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			TNS::NE::NAT::eColor opr_p0 = ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_ECOLOR_0, TNS::NE::NAT::eColor >();
			TNS::NE::NAT::eColor opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_eColorIR, TNS::NE::NAT::eColor, TNS::NE::NAT::eColor >(opr_p0);
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_ECOLOR_0, TNS::NE::NAT::eColor >() = opr;
			return result;
		}
	};

	class Assignment_bt_par_test_property_as_left_value_and_param_node23 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_and_param_node23, Assignment);
		Assignment_bt_par_test_property_as_left_value_and_param_node23()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			behaviac::vector<TNS::NE::NAT::eColor> opr_p0 = ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_ECOLOR_0, behaviac::vector<TNS::NE::NAT::eColor> >();
			behaviac::vector<TNS::NE::NAT::eColor> opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_eColorListIR, behaviac::vector<TNS::NE::NAT::eColor>, behaviac::vector<TNS::NE::NAT::eColor> >(opr_p0);
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_ECOLOR_0, behaviac::vector<TNS::NE::NAT::eColor> >() = opr;
			return result;
		}
	};

	class Assignment_bt_par_test_property_as_left_value_and_param_node28 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_and_param_node28, Assignment);
		Assignment_bt_par_test_property_as_left_value_and_param_node28()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			signed char opr_p0 = ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_SBYTE_0, signed char >();
			signed char opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_SByteIR, signed char, signed char >(opr_p0);
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_SBYTE_0, signed char >() = opr;
			return result;
		}
	};

	class Assignment_bt_par_test_property_as_left_value_and_param_node29 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_and_param_node29, Assignment);
		Assignment_bt_par_test_property_as_left_value_and_param_node29()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			behaviac::vector<signed char> opr_p0 = ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_SBYTE_0, behaviac::vector<signed char> >();
			behaviac::vector<signed char> opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_SByteListIR, behaviac::vector<signed char>, behaviac::vector<signed char> >(opr_p0);
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_SBYTE_0, behaviac::vector<signed char> >() = opr;
			return result;
		}
	};

		bool bt_par_test_property_as_left_value_and_param::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("par_test/property_as_left_value_and_param");
			pBT->SetIsFSM(false);
#if !BEHAVIAC_RELEASE
			pBT->SetAgentType("EmployeeParTestAgent");
#endif
			// children
			{
				Sequence* node13 = BEHAVIAC_NEW Sequence;
				node13->SetClassNameString("Sequence");
				node13->SetId(13);
#if !BEHAVIAC_RELEASE
				node13->SetAgentType("EmployeeParTestAgent");
#endif
				pBT->AddChild(node13);
				{
					Sequence* node1 = BEHAVIAC_NEW Sequence;
					node1->SetClassNameString("Sequence");
					node1->SetId(1);
#if !BEHAVIAC_RELEASE
					node1->SetAgentType("EmployeeParTestAgent");
#endif
					node13->AddChild(node1);
					{
						Assignment_bt_par_test_property_as_left_value_and_param_node0* node0 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_and_param_node0;
						node0->SetClassNameString("Assignment");
						node0->SetId(0);
#if !BEHAVIAC_RELEASE
						node0->SetAgentType("EmployeeParTestAgent");
#endif
						node1->AddChild(node0);
						node1->SetHasEvents(node1->HasEvents() | node0->HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_and_param_node15* node15 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_and_param_node15;
						node15->SetClassNameString("Assignment");
						node15->SetId(15);
#if !BEHAVIAC_RELEASE
						node15->SetAgentType("EmployeeParTestAgent");
#endif
						node1->AddChild(node15);
						node1->SetHasEvents(node1->HasEvents() | node15->HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_and_param_node2* node2 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_and_param_node2;
						node2->SetClassNameString("Assignment");
						node2->SetId(2);
#if !BEHAVIAC_RELEASE
						node2->SetAgentType("EmployeeParTestAgent");
#endif
						node1->AddChild(node2);
						node1->SetHasEvents(node1->HasEvents() | node2->HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_and_param_node3* node3 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_and_param_node3;
						node3->SetClassNameString("Assignment");
						node3->SetId(3);
#if !BEHAVIAC_RELEASE
						node3->SetAgentType("EmployeeParTestAgent");
#endif
						node1->AddChild(node3);
						node1->SetHasEvents(node1->HasEvents() | node3->HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_and_param_node4* node4 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_and_param_node4;
						node4->SetClassNameString("Assignment");
						node4->SetId(4);
#if !BEHAVIAC_RELEASE
						node4->SetAgentType("EmployeeParTestAgent");
#endif
						node1->AddChild(node4);
						node1->SetHasEvents(node1->HasEvents() | node4->HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_and_param_node5* node5 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_and_param_node5;
						node5->SetClassNameString("Assignment");
						node5->SetId(5);
#if !BEHAVIAC_RELEASE
						node5->SetAgentType("EmployeeParTestAgent");
#endif
						node1->AddChild(node5);
						node1->SetHasEvents(node1->HasEvents() | node5->HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_and_param_node6* node6 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_and_param_node6;
						node6->SetClassNameString("Assignment");
						node6->SetId(6);
#if !BEHAVIAC_RELEASE
						node6->SetAgentType("EmployeeParTestAgent");
#endif
						node1->AddChild(node6);
						node1->SetHasEvents(node1->HasEvents() | node6->HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_and_param_node7* node7 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_and_param_node7;
						node7->SetClassNameString("Assignment");
						node7->SetId(7);
#if !BEHAVIAC_RELEASE
						node7->SetAgentType("EmployeeParTestAgent");
#endif
						node1->AddChild(node7);
						node1->SetHasEvents(node1->HasEvents() | node7->HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_and_param_node8* node8 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_and_param_node8;
						node8->SetClassNameString("Assignment");
						node8->SetId(8);
#if !BEHAVIAC_RELEASE
						node8->SetAgentType("EmployeeParTestAgent");
#endif
						node1->AddChild(node8);
						node1->SetHasEvents(node1->HasEvents() | node8->HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_and_param_node30* node30 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_and_param_node30;
						node30->SetClassNameString("Assignment");
						node30->SetId(30);
#if !BEHAVIAC_RELEASE
						node30->SetAgentType("EmployeeParTestAgent");
#endif
						node1->AddChild(node30);
						node1->SetHasEvents(node1->HasEvents() | node30->HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_and_param_node31* node31 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_and_param_node31;
						node31->SetClassNameString("Assignment");
						node31->SetId(31);
#if !BEHAVIAC_RELEASE
						node31->SetAgentType("EmployeeParTestAgent");
#endif
						node1->AddChild(node31);
						node1->SetHasEvents(node1->HasEvents() | node31->HasEvents());
					}
					node13->SetHasEvents(node13->HasEvents() | node1->HasEvents());
				}
				{
					Sequence* node14 = BEHAVIAC_NEW Sequence;
					node14->SetClassNameString("Sequence");
					node14->SetId(14);
#if !BEHAVIAC_RELEASE
					node14->SetAgentType("EmployeeParTestAgent");
#endif
					node13->AddChild(node14);
					{
						Assignment_bt_par_test_property_as_left_value_and_param_node9* node9 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_and_param_node9;
						node9->SetClassNameString("Assignment");
						node9->SetId(9);
#if !BEHAVIAC_RELEASE
						node9->SetAgentType("EmployeeParTestAgent");
#endif
						node14->AddChild(node9);
						node14->SetHasEvents(node14->HasEvents() | node9->HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_and_param_node10* node10 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_and_param_node10;
						node10->SetClassNameString("Assignment");
						node10->SetId(10);
#if !BEHAVIAC_RELEASE
						node10->SetAgentType("EmployeeParTestAgent");
#endif
						node14->AddChild(node10);
						node14->SetHasEvents(node14->HasEvents() | node10->HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_and_param_node11* node11 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_and_param_node11;
						node11->SetClassNameString("Assignment");
						node11->SetId(11);
#if !BEHAVIAC_RELEASE
						node11->SetAgentType("EmployeeParTestAgent");
#endif
						node14->AddChild(node11);
						node14->SetHasEvents(node14->HasEvents() | node11->HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_and_param_node12* node12 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_and_param_node12;
						node12->SetClassNameString("Assignment");
						node12->SetId(12);
#if !BEHAVIAC_RELEASE
						node12->SetAgentType("EmployeeParTestAgent");
#endif
						node14->AddChild(node12);
						node14->SetHasEvents(node14->HasEvents() | node12->HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_and_param_node17* node17 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_and_param_node17;
						node17->SetClassNameString("Assignment");
						node17->SetId(17);
#if !BEHAVIAC_RELEASE
						node17->SetAgentType("EmployeeParTestAgent");
#endif
						node14->AddChild(node17);
						node14->SetHasEvents(node14->HasEvents() | node17->HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_and_param_node19* node19 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_and_param_node19;
						node19->SetClassNameString("Assignment");
						node19->SetId(19);
#if !BEHAVIAC_RELEASE
						node19->SetAgentType("EmployeeParTestAgent");
#endif
						node14->AddChild(node19);
						node14->SetHasEvents(node14->HasEvents() | node19->HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_and_param_node18* node18 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_and_param_node18;
						node18->SetClassNameString("Assignment");
						node18->SetId(18);
#if !BEHAVIAC_RELEASE
						node18->SetAgentType("EmployeeParTestAgent");
#endif
						node14->AddChild(node18);
						node14->SetHasEvents(node14->HasEvents() | node18->HasEvents());
					}
					node13->SetHasEvents(node13->HasEvents() | node14->HasEvents());
				}
				{
					Sequence* node22 = BEHAVIAC_NEW Sequence;
					node22->SetClassNameString("Sequence");
					node22->SetId(22);
#if !BEHAVIAC_RELEASE
					node22->SetAgentType("EmployeeParTestAgent");
#endif
					node13->AddChild(node22);
					{
						Assignment_bt_par_test_property_as_left_value_and_param_node16* node16 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_and_param_node16;
						node16->SetClassNameString("Assignment");
						node16->SetId(16);
#if !BEHAVIAC_RELEASE
						node16->SetAgentType("EmployeeParTestAgent");
#endif
						node22->AddChild(node16);
						node22->SetHasEvents(node22->HasEvents() | node16->HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_and_param_node20* node20 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_and_param_node20;
						node20->SetClassNameString("Assignment");
						node20->SetId(20);
#if !BEHAVIAC_RELEASE
						node20->SetAgentType("EmployeeParTestAgent");
#endif
						node22->AddChild(node20);
						node22->SetHasEvents(node22->HasEvents() | node20->HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_and_param_node24* node24 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_and_param_node24;
						node24->SetClassNameString("Assignment");
						node24->SetId(24);
#if !BEHAVIAC_RELEASE
						node24->SetAgentType("EmployeeParTestAgent");
#endif
						node22->AddChild(node24);
						node22->SetHasEvents(node22->HasEvents() | node24->HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_and_param_node25* node25 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_and_param_node25;
						node25->SetClassNameString("Assignment");
						node25->SetId(25);
#if !BEHAVIAC_RELEASE
						node25->SetAgentType("EmployeeParTestAgent");
#endif
						node22->AddChild(node25);
						node22->SetHasEvents(node22->HasEvents() | node25->HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_and_param_node26* node26 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_and_param_node26;
						node26->SetClassNameString("Assignment");
						node26->SetId(26);
#if !BEHAVIAC_RELEASE
						node26->SetAgentType("EmployeeParTestAgent");
#endif
						node22->AddChild(node26);
						node22->SetHasEvents(node22->HasEvents() | node26->HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_and_param_node27* node27 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_and_param_node27;
						node27->SetClassNameString("Assignment");
						node27->SetId(27);
#if !BEHAVIAC_RELEASE
						node27->SetAgentType("EmployeeParTestAgent");
#endif
						node22->AddChild(node27);
						node22->SetHasEvents(node22->HasEvents() | node27->HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_and_param_node21* node21 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_and_param_node21;
						node21->SetClassNameString("Assignment");
						node21->SetId(21);
#if !BEHAVIAC_RELEASE
						node21->SetAgentType("EmployeeParTestAgent");
#endif
						node22->AddChild(node21);
						node22->SetHasEvents(node22->HasEvents() | node21->HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_and_param_node23* node23 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_and_param_node23;
						node23->SetClassNameString("Assignment");
						node23->SetId(23);
#if !BEHAVIAC_RELEASE
						node23->SetAgentType("EmployeeParTestAgent");
#endif
						node22->AddChild(node23);
						node22->SetHasEvents(node22->HasEvents() | node23->HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_and_param_node28* node28 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_and_param_node28;
						node28->SetClassNameString("Assignment");
						node28->SetId(28);
#if !BEHAVIAC_RELEASE
						node28->SetAgentType("EmployeeParTestAgent");
#endif
						node22->AddChild(node28);
						node22->SetHasEvents(node22->HasEvents() | node28->HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_and_param_node29* node29 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_and_param_node29;
						node29->SetClassNameString("Assignment");
						node29->SetId(29);
#if !BEHAVIAC_RELEASE
						node29->SetAgentType("EmployeeParTestAgent");
#endif
						node22->AddChild(node29);
						node22->SetHasEvents(node22->HasEvents() | node29->HasEvents());
					}
					node13->SetHasEvents(node13->HasEvents() | node22->HasEvents());
				}
				pBT->SetHasEvents(pBT->HasEvents() | node13->HasEvents());
			}
			return true;
		}

	// Source file: par_test/property_as_ref_param

	class Action_bt_par_test_property_as_ref_param_node0 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_property_as_ref_param_node0, Action);
		Action_bt_par_test_property_as_ref_param_node0()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			behaviac::Agent* method_p0 = ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_AGENT_0, behaviac::Agent* >();
			((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_AgentRef, void, behaviac::Agent*& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_AGENT_0") == 2234467067u);
			pAgent->SetVariable("TV_AGENT_0", method_p0, 2234467067u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_property_as_ref_param_node17 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_property_as_ref_param_node17, Action);
		Action_bt_par_test_property_as_ref_param_node17()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			behaviac::vector<behaviac::Agent*> method_p0 = ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_LIST_AGENT_0, behaviac::vector<behaviac::Agent*> >();
			((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_AgentListRef, void, behaviac::vector<behaviac::Agent*>& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_LIST_AGENT_0") == 350152458u);
			pAgent->SetVariable("TV_LIST_AGENT_0", method_p0, 350152458u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_property_as_ref_param_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_property_as_ref_param_node2, Action);
		Action_bt_par_test_property_as_ref_param_node2()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			double method_p0 = ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_D_0, double >();
			((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_DoubleRef, void, double& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_D_0") == 2418961396u);
			pAgent->SetVariable("TV_D_0", method_p0, 2418961396u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_property_as_ref_param_node3 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_property_as_ref_param_node3, Action);
		Action_bt_par_test_property_as_ref_param_node3()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			float method_p0 = ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_F_0, float >();
			((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_SingleRef, void, float& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_F_0") == 975676287u);
			pAgent->SetVariable("TV_F_0", method_p0, 975676287u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_property_as_ref_param_node4 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_property_as_ref_param_node4, Action);
		Action_bt_par_test_property_as_ref_param_node4()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			behaviac::vector<float> method_p0 = ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_LIST_F_0, behaviac::vector<float> >();
			((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_SingleListRef, void, behaviac::vector<float>& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_LIST_F_0") == 3277708114u);
			pAgent->SetVariable("TV_LIST_F_0", method_p0, 3277708114u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_property_as_ref_param_node5 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_property_as_ref_param_node5, Action);
		Action_bt_par_test_property_as_ref_param_node5()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			behaviac::string method_p0 = ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_STR_0, behaviac::string >();
			((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_StringRef, void, behaviac::string& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_STR_0") == 3765213955u);
			pAgent->SetVariable("TV_STR_0", method_p0, 3765213955u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_property_as_ref_param_node32 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_property_as_ref_param_node32, Action);
		Action_bt_par_test_property_as_ref_param_node32()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			Agent* pAgent_method_p0 = Agent::GetInstance(pAgent, "ParTestRegNameAgent");
			BEHAVIAC_ASSERT(pAgent_method_p0);
			behaviac::string method_p0 = ((ParTestRegNameAgent*)pAgent_method_p0)->_Get_Property_<PROPERTY_TYPE_ParTestRegNameAgent_TV_STR_0, behaviac::string >();
			((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_StringRef, void, behaviac::string& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_STR_0") == 3765213955u);
			pAgent_method_p0->SetVariable("TV_STR_0", method_p0, 3765213955u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_property_as_ref_param_node6 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_property_as_ref_param_node6, Action);
		Action_bt_par_test_property_as_ref_param_node6()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			behaviac::vector<behaviac::string> method_p0 = ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_LIST_STR_0, behaviac::vector<behaviac::string> >();
			((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_StringListRef, void, behaviac::vector<behaviac::string>& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_LIST_STR_0") == 3861554756u);
			pAgent->SetVariable("TV_LIST_STR_0", method_p0, 3861554756u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_property_as_ref_param_node7 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_property_as_ref_param_node7, Action);
		Action_bt_par_test_property_as_ref_param_node7()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			unsigned int method_p0 = ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_UINT_0, unsigned int >();
			((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_UIntRef, void, unsigned int& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_UINT_0") == 447245470u);
			pAgent->SetVariable("TV_UINT_0", method_p0, 447245470u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_property_as_ref_param_node8 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_property_as_ref_param_node8, Action);
		Action_bt_par_test_property_as_ref_param_node8()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			unsigned long method_p0 = ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_ULONG_0, unsigned long >();
			((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_ULongRef, void, unsigned long& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_ULONG_0") == 2632905415u);
			pAgent->SetVariable("TV_ULONG_0", method_p0, 2632905415u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_property_as_ref_param_node30 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_property_as_ref_param_node30, Action);
		Action_bt_par_test_property_as_ref_param_node30()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			long long method_p0 = ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_LL_0, long long >();
			((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_LongLongRef, void, long long& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_LL_0") == 2624529173u);
			pAgent->SetVariable("TV_LL_0", method_p0, 2624529173u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_property_as_ref_param_node31 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_property_as_ref_param_node31, Action);
		Action_bt_par_test_property_as_ref_param_node31()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			unsigned long long method_p0 = ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_ULL_0, unsigned long long >();
			((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_ULongLongRef, void, unsigned long long& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_ULL_0") == 3596846321u);
			pAgent->SetVariable("TV_ULL_0", method_p0, 3596846321u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_property_as_ref_param_node9 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_property_as_ref_param_node9, Action);
		Action_bt_par_test_property_as_ref_param_node9()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			short method_p0 = ((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_SHORT_0, short >();
			((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_ShortRef, void, short& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_SHORT_0") == 1232231841u);
			pAgent->SetVariable("TV_SHORT_0", method_p0, 1232231841u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_property_as_ref_param_node10 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_property_as_ref_param_node10, Action);
		Action_bt_par_test_property_as_ref_param_node10()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			int method_p0 = ((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_INT_0, int >();
			((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_IntRef, void, int& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_INT_0") == 1293576705u);
			pAgent->SetVariable("TV_INT_0", method_p0, 1293576705u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_property_as_ref_param_node11 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_property_as_ref_param_node11, Action);
		Action_bt_par_test_property_as_ref_param_node11()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			behaviac::vector<int> method_p0 = ((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_LIST_INT_0, behaviac::vector<int> >();
			((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_IntListRef, void, behaviac::vector<int>& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_LIST_INT_0") == 1264342854u);
			pAgent->SetVariable("TV_LIST_INT_0", method_p0, 1264342854u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_property_as_ref_param_node12 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_property_as_ref_param_node12, Action);
		Action_bt_par_test_property_as_ref_param_node12()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			long method_p0 = ((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_LONG_0, long >();
			((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_LongRef, void, long& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_LONG_0") == 2082189039u);
			pAgent->SetVariable("TV_LONG_0", method_p0, 2082189039u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_property_as_ref_param_node18 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_property_as_ref_param_node18, Action);
		Action_bt_par_test_property_as_ref_param_node18()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			TNS::ST::PER::WRK::kEmployee method_p0 = ((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_KEMPLOYEE_0, TNS::ST::PER::WRK::kEmployee >();
			((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_kEmployeeRef, void, TNS::ST::PER::WRK::kEmployee& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_KEMPLOYEE_0") == 2788553297u);
			pAgent->SetVariable("TV_KEMPLOYEE_0", method_p0, 2788553297u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_property_as_ref_param_node19 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_property_as_ref_param_node19, Action);
		Action_bt_par_test_property_as_ref_param_node19()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			behaviac::vector<TNS::ST::PER::WRK::kEmployee> method_p0 = ((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_LIST_KEMPLOYEE_0, behaviac::vector<TNS::ST::PER::WRK::kEmployee> >();
			((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_kEmployeeListRef, void, behaviac::vector<TNS::ST::PER::WRK::kEmployee>& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_LIST_KEMPLOYEE_0") == 1712688287u);
			pAgent->SetVariable("TV_LIST_KEMPLOYEE_0", method_p0, 1712688287u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_property_as_ref_param_node20 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_property_as_ref_param_node20, Action);
		Action_bt_par_test_property_as_ref_param_node20()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			unsigned short method_p0 = ((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_USHORT_0, unsigned short >();
			((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_UShortRef, void, unsigned short& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_USHORT_0") == 537748306u);
			pAgent->SetVariable("TV_USHORT_0", method_p0, 537748306u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_property_as_ref_param_node16 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_property_as_ref_param_node16, Action);
		Action_bt_par_test_property_as_ref_param_node16()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			bool method_p0 = ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_BOOL_0, bool >();
			((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_BooleanRef, void, bool& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_BOOL_0") == 3326442243u);
			pAgent->SetVariable("TV_BOOL_0", method_p0, 3326442243u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_property_as_ref_param_node21 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_property_as_ref_param_node21, Action);
		Action_bt_par_test_property_as_ref_param_node21()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			behaviac::vector<bool> method_p0 = ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_BOOL_0, behaviac::vector<bool> >();
			((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_BooleanListRef, void, behaviac::vector<bool>& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_LIST_BOOL_0") == 3454568683u);
			pAgent->SetVariable("TV_LIST_BOOL_0", method_p0, 3454568683u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_property_as_ref_param_node15 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_property_as_ref_param_node15, Action);
		Action_bt_par_test_property_as_ref_param_node15()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			unsigned char method_p0 = ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_BYTE_0, unsigned char >();
			((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_ByteRef, void, unsigned char& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_BYTE_0") == 2045932444u);
			pAgent->SetVariable("TV_BYTE_0", method_p0, 2045932444u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_property_as_ref_param_node29 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_property_as_ref_param_node29, Action);
		Action_bt_par_test_property_as_ref_param_node29()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			behaviac::vector<unsigned char> method_p0 = ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_BYTE_0, behaviac::vector<unsigned char> >();
			((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_ByteListRef, void, behaviac::vector<unsigned char>& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_LIST_BYTE_0") == 1918861428u);
			pAgent->SetVariable("TV_LIST_BYTE_0", method_p0, 1918861428u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_property_as_ref_param_node26 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_property_as_ref_param_node26, Action);
		Action_bt_par_test_property_as_ref_param_node26()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			char method_p0 = ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_CHAR_0, char >();
			((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_CharRef, void, char& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_CHAR_0") == 1925308098u);
			pAgent->SetVariable("TV_CHAR_0", method_p0, 1925308098u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_property_as_ref_param_node27 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_property_as_ref_param_node27, Action);
		Action_bt_par_test_property_as_ref_param_node27()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			behaviac::vector<char> method_p0 = ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_CHAR_0, behaviac::vector<char> >();
			((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_CharListRef, void, behaviac::vector<char>& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_LIST_CHAR_0") == 2037132586u);
			pAgent->SetVariable("TV_LIST_CHAR_0", method_p0, 2037132586u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_property_as_ref_param_node24 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_property_as_ref_param_node24, Action);
		Action_bt_par_test_property_as_ref_param_node24()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			TNS::NE::NAT::eColor method_p0 = ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_ECOLOR_0, TNS::NE::NAT::eColor >();
			((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_eColorRef, void, TNS::NE::NAT::eColor& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_ECOLOR_0") == 241062087u);
			pAgent->SetVariable("TV_ECOLOR_0", method_p0, 241062087u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_property_as_ref_param_node25 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_property_as_ref_param_node25, Action);
		Action_bt_par_test_property_as_ref_param_node25()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			behaviac::vector<TNS::NE::NAT::eColor> method_p0 = ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_ECOLOR_0, behaviac::vector<TNS::NE::NAT::eColor> >();
			((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_eColorListRef, void, behaviac::vector<TNS::NE::NAT::eColor>& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_LIST_ECOLOR_0") == 862412353u);
			pAgent->SetVariable("TV_LIST_ECOLOR_0", method_p0, 862412353u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_property_as_ref_param_node23 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_property_as_ref_param_node23, Action);
		Action_bt_par_test_property_as_ref_param_node23()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			signed char method_p0 = ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_SBYTE_0, signed char >();
			((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_SByteRef, void, signed char& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_SBYTE_0") == 1600661043u);
			pAgent->SetVariable("TV_SBYTE_0", method_p0, 1600661043u);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_property_as_ref_param_node28 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_property_as_ref_param_node28, Action);
		Action_bt_par_test_property_as_ref_param_node28()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			behaviac::vector<signed char> method_p0 = ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_SBYTE_0, behaviac::vector<signed char> >();
			((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_SByteListRef, void, behaviac::vector<signed char>& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_LIST_SBYTE_0") == 3466167234u);
			pAgent->SetVariable("TV_LIST_SBYTE_0", method_p0, 3466167234u);
			return BT_SUCCESS;
		}
	};

		bool bt_par_test_property_as_ref_param::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("par_test/property_as_ref_param");
			pBT->SetIsFSM(false);
#if !BEHAVIAC_RELEASE
			pBT->SetAgentType("EmployeeParTestAgent");
#endif
			// pars
			pBT->AddPar("EmployeeParTestAgent", "ulong", "par2_ulong_0", "0");
			pBT->AddPar("EmployeeParTestAgent", "uint", "par2_uint_0", "0");
			pBT->AddPar("EmployeeParTestAgent", "vector<string>", "par2_string_list_0", "0:");
			pBT->AddPar("EmployeeParTestAgent", "string", "par2_string_0", "");
			pBT->AddPar("EmployeeParTestAgent", "vector<float>", "par2_single_list_0", "0:");
			pBT->AddPar("EmployeeParTestAgent", "float", "par2_single_0", "0");
			pBT->AddPar("EmployeeParTestAgent", "double", "par2_double_0", "0");
			pBT->AddPar("EmployeeParTestAgent", "vector<behaviac::Agent>", "par2_agent_list_0", "0:");
			pBT->AddPar("EmployeeParTestAgent", "behaviac::Agent", "par2_agent_0", "null");
			pBT->AddPar("EmployeeParTestAgent", "ushort", "par1_ushort_0", "65535");
			pBT->AddPar("EmployeeParTestAgent", "vector<TNS::ST::PER::WRK::kEmployee>", "par1_kemployee_list_0", "0:");
			pBT->AddPar("EmployeeParTestAgent", "TNS::ST::PER::WRK::kEmployee", "par1_kemployee_0", "{boss=null;car={brand=\"\";color=RED;price=0;};code=c;id=0;isMale=false;name=\"tomlp\";skinColor=RED;weight=0;}");
			pBT->AddPar("EmployeeParTestAgent", "long", "par1_long_0", "0");
			pBT->AddPar("EmployeeParTestAgent", "vector<int>", "par1_int_list_0", "0:");
			pBT->AddPar("EmployeeParTestAgent", "int", "par1_int_0", "0");
			pBT->AddPar("EmployeeParTestAgent", "short", "par1_short_0", "0");
			pBT->AddPar("EmployeeParTestAgent", "vector<sbyte>", "par0_sbyte_list_0", "0:");
			pBT->AddPar("EmployeeParTestAgent", "sbyte", "par0_sbyte_0", "0");
			pBT->AddPar("EmployeeParTestAgent", "vector<TNS::NE::NAT::eColor>", "par0_ecolor_list_0", "0:");
			pBT->AddPar("EmployeeParTestAgent", "TNS::NE::NAT::eColor", "par0_ecolor_0", "WHITE");
			pBT->AddPar("EmployeeParTestAgent", "vector<char>", "par0_char_list_0", "0:");
			pBT->AddPar("EmployeeParTestAgent", "char", "par0_char_0", "A");
			pBT->AddPar("EmployeeParTestAgent", "vector<ubyte>", "par0_byte_list_0", "0:");
			pBT->AddPar("EmployeeParTestAgent", "ubyte", "par0_byte_0", "0");
			pBT->AddPar("EmployeeParTestAgent", "vector<bool>", "par0_boolean_list_0", "0:");
			pBT->AddPar("EmployeeParTestAgent", "bool", "par0_boolean_0", "false");
			// children
			{
				Sequence* node13 = BEHAVIAC_NEW Sequence;
				node13->SetClassNameString("Sequence");
				node13->SetId(13);
#if !BEHAVIAC_RELEASE
				node13->SetAgentType("EmployeeParTestAgent");
#endif
				pBT->AddChild(node13);
				{
					Sequence* node1 = BEHAVIAC_NEW Sequence;
					node1->SetClassNameString("Sequence");
					node1->SetId(1);
#if !BEHAVIAC_RELEASE
					node1->SetAgentType("EmployeeParTestAgent");
#endif
					node13->AddChild(node1);
					{
						Action_bt_par_test_property_as_ref_param_node0* node0 = BEHAVIAC_NEW Action_bt_par_test_property_as_ref_param_node0;
						node0->SetClassNameString("Action");
						node0->SetId(0);
#if !BEHAVIAC_RELEASE
						node0->SetAgentType("EmployeeParTestAgent");
#endif
						node1->AddChild(node0);
						node1->SetHasEvents(node1->HasEvents() | node0->HasEvents());
					}
					{
						Action_bt_par_test_property_as_ref_param_node17* node17 = BEHAVIAC_NEW Action_bt_par_test_property_as_ref_param_node17;
						node17->SetClassNameString("Action");
						node17->SetId(17);
#if !BEHAVIAC_RELEASE
						node17->SetAgentType("EmployeeParTestAgent");
#endif
						node1->AddChild(node17);
						node1->SetHasEvents(node1->HasEvents() | node17->HasEvents());
					}
					{
						Action_bt_par_test_property_as_ref_param_node2* node2 = BEHAVIAC_NEW Action_bt_par_test_property_as_ref_param_node2;
						node2->SetClassNameString("Action");
						node2->SetId(2);
#if !BEHAVIAC_RELEASE
						node2->SetAgentType("EmployeeParTestAgent");
#endif
						node1->AddChild(node2);
						node1->SetHasEvents(node1->HasEvents() | node2->HasEvents());
					}
					{
						Action_bt_par_test_property_as_ref_param_node3* node3 = BEHAVIAC_NEW Action_bt_par_test_property_as_ref_param_node3;
						node3->SetClassNameString("Action");
						node3->SetId(3);
#if !BEHAVIAC_RELEASE
						node3->SetAgentType("EmployeeParTestAgent");
#endif
						node1->AddChild(node3);
						node1->SetHasEvents(node1->HasEvents() | node3->HasEvents());
					}
					{
						Action_bt_par_test_property_as_ref_param_node4* node4 = BEHAVIAC_NEW Action_bt_par_test_property_as_ref_param_node4;
						node4->SetClassNameString("Action");
						node4->SetId(4);
#if !BEHAVIAC_RELEASE
						node4->SetAgentType("EmployeeParTestAgent");
#endif
						node1->AddChild(node4);
						node1->SetHasEvents(node1->HasEvents() | node4->HasEvents());
					}
					{
						Action_bt_par_test_property_as_ref_param_node5* node5 = BEHAVIAC_NEW Action_bt_par_test_property_as_ref_param_node5;
						node5->SetClassNameString("Action");
						node5->SetId(5);
#if !BEHAVIAC_RELEASE
						node5->SetAgentType("EmployeeParTestAgent");
#endif
						node1->AddChild(node5);
						node1->SetHasEvents(node1->HasEvents() | node5->HasEvents());
					}
					{
						Action_bt_par_test_property_as_ref_param_node32* node32 = BEHAVIAC_NEW Action_bt_par_test_property_as_ref_param_node32;
						node32->SetClassNameString("Action");
						node32->SetId(32);
#if !BEHAVIAC_RELEASE
						node32->SetAgentType("EmployeeParTestAgent");
#endif
						node1->AddChild(node32);
						node1->SetHasEvents(node1->HasEvents() | node32->HasEvents());
					}
					{
						Action_bt_par_test_property_as_ref_param_node6* node6 = BEHAVIAC_NEW Action_bt_par_test_property_as_ref_param_node6;
						node6->SetClassNameString("Action");
						node6->SetId(6);
#if !BEHAVIAC_RELEASE
						node6->SetAgentType("EmployeeParTestAgent");
#endif
						node1->AddChild(node6);
						node1->SetHasEvents(node1->HasEvents() | node6->HasEvents());
					}
					{
						Action_bt_par_test_property_as_ref_param_node7* node7 = BEHAVIAC_NEW Action_bt_par_test_property_as_ref_param_node7;
						node7->SetClassNameString("Action");
						node7->SetId(7);
#if !BEHAVIAC_RELEASE
						node7->SetAgentType("EmployeeParTestAgent");
#endif
						node1->AddChild(node7);
						node1->SetHasEvents(node1->HasEvents() | node7->HasEvents());
					}
					{
						Action_bt_par_test_property_as_ref_param_node8* node8 = BEHAVIAC_NEW Action_bt_par_test_property_as_ref_param_node8;
						node8->SetClassNameString("Action");
						node8->SetId(8);
#if !BEHAVIAC_RELEASE
						node8->SetAgentType("EmployeeParTestAgent");
#endif
						node1->AddChild(node8);
						node1->SetHasEvents(node1->HasEvents() | node8->HasEvents());
					}
					{
						Action_bt_par_test_property_as_ref_param_node30* node30 = BEHAVIAC_NEW Action_bt_par_test_property_as_ref_param_node30;
						node30->SetClassNameString("Action");
						node30->SetId(30);
#if !BEHAVIAC_RELEASE
						node30->SetAgentType("EmployeeParTestAgent");
#endif
						node1->AddChild(node30);
						node1->SetHasEvents(node1->HasEvents() | node30->HasEvents());
					}
					{
						Action_bt_par_test_property_as_ref_param_node31* node31 = BEHAVIAC_NEW Action_bt_par_test_property_as_ref_param_node31;
						node31->SetClassNameString("Action");
						node31->SetId(31);
#if !BEHAVIAC_RELEASE
						node31->SetAgentType("EmployeeParTestAgent");
#endif
						node1->AddChild(node31);
						node1->SetHasEvents(node1->HasEvents() | node31->HasEvents());
					}
					node13->SetHasEvents(node13->HasEvents() | node1->HasEvents());
				}
				{
					Sequence* node14 = BEHAVIAC_NEW Sequence;
					node14->SetClassNameString("Sequence");
					node14->SetId(14);
#if !BEHAVIAC_RELEASE
					node14->SetAgentType("EmployeeParTestAgent");
#endif
					node13->AddChild(node14);
					{
						Action_bt_par_test_property_as_ref_param_node9* node9 = BEHAVIAC_NEW Action_bt_par_test_property_as_ref_param_node9;
						node9->SetClassNameString("Action");
						node9->SetId(9);
#if !BEHAVIAC_RELEASE
						node9->SetAgentType("EmployeeParTestAgent");
#endif
						node14->AddChild(node9);
						node14->SetHasEvents(node14->HasEvents() | node9->HasEvents());
					}
					{
						Action_bt_par_test_property_as_ref_param_node10* node10 = BEHAVIAC_NEW Action_bt_par_test_property_as_ref_param_node10;
						node10->SetClassNameString("Action");
						node10->SetId(10);
#if !BEHAVIAC_RELEASE
						node10->SetAgentType("EmployeeParTestAgent");
#endif
						node14->AddChild(node10);
						node14->SetHasEvents(node14->HasEvents() | node10->HasEvents());
					}
					{
						Action_bt_par_test_property_as_ref_param_node11* node11 = BEHAVIAC_NEW Action_bt_par_test_property_as_ref_param_node11;
						node11->SetClassNameString("Action");
						node11->SetId(11);
#if !BEHAVIAC_RELEASE
						node11->SetAgentType("EmployeeParTestAgent");
#endif
						node14->AddChild(node11);
						node14->SetHasEvents(node14->HasEvents() | node11->HasEvents());
					}
					{
						Action_bt_par_test_property_as_ref_param_node12* node12 = BEHAVIAC_NEW Action_bt_par_test_property_as_ref_param_node12;
						node12->SetClassNameString("Action");
						node12->SetId(12);
#if !BEHAVIAC_RELEASE
						node12->SetAgentType("EmployeeParTestAgent");
#endif
						node14->AddChild(node12);
						node14->SetHasEvents(node14->HasEvents() | node12->HasEvents());
					}
					{
						Action_bt_par_test_property_as_ref_param_node18* node18 = BEHAVIAC_NEW Action_bt_par_test_property_as_ref_param_node18;
						node18->SetClassNameString("Action");
						node18->SetId(18);
#if !BEHAVIAC_RELEASE
						node18->SetAgentType("EmployeeParTestAgent");
#endif
						node14->AddChild(node18);
						node14->SetHasEvents(node14->HasEvents() | node18->HasEvents());
					}
					{
						Action_bt_par_test_property_as_ref_param_node19* node19 = BEHAVIAC_NEW Action_bt_par_test_property_as_ref_param_node19;
						node19->SetClassNameString("Action");
						node19->SetId(19);
#if !BEHAVIAC_RELEASE
						node19->SetAgentType("EmployeeParTestAgent");
#endif
						node14->AddChild(node19);
						node14->SetHasEvents(node14->HasEvents() | node19->HasEvents());
					}
					{
						Action_bt_par_test_property_as_ref_param_node20* node20 = BEHAVIAC_NEW Action_bt_par_test_property_as_ref_param_node20;
						node20->SetClassNameString("Action");
						node20->SetId(20);
#if !BEHAVIAC_RELEASE
						node20->SetAgentType("EmployeeParTestAgent");
#endif
						node14->AddChild(node20);
						node14->SetHasEvents(node14->HasEvents() | node20->HasEvents());
					}
					node13->SetHasEvents(node13->HasEvents() | node14->HasEvents());
				}
				{
					Sequence* node22 = BEHAVIAC_NEW Sequence;
					node22->SetClassNameString("Sequence");
					node22->SetId(22);
#if !BEHAVIAC_RELEASE
					node22->SetAgentType("EmployeeParTestAgent");
#endif
					node13->AddChild(node22);
					{
						Action_bt_par_test_property_as_ref_param_node16* node16 = BEHAVIAC_NEW Action_bt_par_test_property_as_ref_param_node16;
						node16->SetClassNameString("Action");
						node16->SetId(16);
#if !BEHAVIAC_RELEASE
						node16->SetAgentType("EmployeeParTestAgent");
#endif
						node22->AddChild(node16);
						node22->SetHasEvents(node22->HasEvents() | node16->HasEvents());
					}
					{
						Action_bt_par_test_property_as_ref_param_node21* node21 = BEHAVIAC_NEW Action_bt_par_test_property_as_ref_param_node21;
						node21->SetClassNameString("Action");
						node21->SetId(21);
#if !BEHAVIAC_RELEASE
						node21->SetAgentType("EmployeeParTestAgent");
#endif
						node22->AddChild(node21);
						node22->SetHasEvents(node22->HasEvents() | node21->HasEvents());
					}
					{
						Action_bt_par_test_property_as_ref_param_node15* node15 = BEHAVIAC_NEW Action_bt_par_test_property_as_ref_param_node15;
						node15->SetClassNameString("Action");
						node15->SetId(15);
#if !BEHAVIAC_RELEASE
						node15->SetAgentType("EmployeeParTestAgent");
#endif
						node22->AddChild(node15);
						node22->SetHasEvents(node22->HasEvents() | node15->HasEvents());
					}
					{
						Action_bt_par_test_property_as_ref_param_node29* node29 = BEHAVIAC_NEW Action_bt_par_test_property_as_ref_param_node29;
						node29->SetClassNameString("Action");
						node29->SetId(29);
#if !BEHAVIAC_RELEASE
						node29->SetAgentType("EmployeeParTestAgent");
#endif
						node22->AddChild(node29);
						node22->SetHasEvents(node22->HasEvents() | node29->HasEvents());
					}
					{
						Action_bt_par_test_property_as_ref_param_node26* node26 = BEHAVIAC_NEW Action_bt_par_test_property_as_ref_param_node26;
						node26->SetClassNameString("Action");
						node26->SetId(26);
#if !BEHAVIAC_RELEASE
						node26->SetAgentType("EmployeeParTestAgent");
#endif
						node22->AddChild(node26);
						node22->SetHasEvents(node22->HasEvents() | node26->HasEvents());
					}
					{
						Action_bt_par_test_property_as_ref_param_node27* node27 = BEHAVIAC_NEW Action_bt_par_test_property_as_ref_param_node27;
						node27->SetClassNameString("Action");
						node27->SetId(27);
#if !BEHAVIAC_RELEASE
						node27->SetAgentType("EmployeeParTestAgent");
#endif
						node22->AddChild(node27);
						node22->SetHasEvents(node22->HasEvents() | node27->HasEvents());
					}
					{
						Action_bt_par_test_property_as_ref_param_node24* node24 = BEHAVIAC_NEW Action_bt_par_test_property_as_ref_param_node24;
						node24->SetClassNameString("Action");
						node24->SetId(24);
#if !BEHAVIAC_RELEASE
						node24->SetAgentType("EmployeeParTestAgent");
#endif
						node22->AddChild(node24);
						node22->SetHasEvents(node22->HasEvents() | node24->HasEvents());
					}
					{
						Action_bt_par_test_property_as_ref_param_node25* node25 = BEHAVIAC_NEW Action_bt_par_test_property_as_ref_param_node25;
						node25->SetClassNameString("Action");
						node25->SetId(25);
#if !BEHAVIAC_RELEASE
						node25->SetAgentType("EmployeeParTestAgent");
#endif
						node22->AddChild(node25);
						node22->SetHasEvents(node22->HasEvents() | node25->HasEvents());
					}
					{
						Action_bt_par_test_property_as_ref_param_node23* node23 = BEHAVIAC_NEW Action_bt_par_test_property_as_ref_param_node23;
						node23->SetClassNameString("Action");
						node23->SetId(23);
#if !BEHAVIAC_RELEASE
						node23->SetAgentType("EmployeeParTestAgent");
#endif
						node22->AddChild(node23);
						node22->SetHasEvents(node22->HasEvents() | node23->HasEvents());
					}
					{
						Action_bt_par_test_property_as_ref_param_node28* node28 = BEHAVIAC_NEW Action_bt_par_test_property_as_ref_param_node28;
						node28->SetClassNameString("Action");
						node28->SetId(28);
#if !BEHAVIAC_RELEASE
						node28->SetAgentType("EmployeeParTestAgent");
#endif
						node22->AddChild(node28);
						node22->SetHasEvents(node22->HasEvents() | node28->HasEvents());
					}
					node13->SetHasEvents(node13->HasEvents() | node22->HasEvents());
				}
				pBT->SetHasEvents(pBT->HasEvents() | node13->HasEvents());
			}
			return true;
		}

	// Source file: par_test/readonly_default

	class Assignment_bt_par_test_readonly_default_node3 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_readonly_default_node3, Assignment);
		Assignment_bt_par_test_readonly_default_node3()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			int opr = ((PropertyReadonlyAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_PropertyReadonlyAgent_MemberReadonly, int >();
			((PropertyReadonlyAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_PropertyReadonlyAgent_PropertyGetterSetter, int >() = opr;
			return result;
		}
	};

	class Action_bt_par_test_readonly_default_node1 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_readonly_default_node1, Action);
		Action_bt_par_test_readonly_default_node1()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			int method_p0 = ((PropertyReadonlyAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_PropertyReadonlyAgent_PropertyGetterOnly, int >();
			((PropertyReadonlyAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_PropertyReadonlyAgent_PassInProperty, void, int >(method_p0);
			return BT_SUCCESS;
		}
	};

	class Action_bt_par_test_readonly_default_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_readonly_default_node2, Action);
		Action_bt_par_test_readonly_default_node2()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("c_Int") == 3849503314u);
			int& method_p0 = (int&)pAgent->GetVariable<int >(3849503314u);
			((PropertyReadonlyAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_PropertyReadonlyAgent_FnWithOutParam, void, int& >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("c_Int") == 3849503314u);
			pAgent->SetVariable("c_Int", method_p0, 3849503314u);
			return BT_SUCCESS;
		}
	};

	class Compute_bt_par_test_readonly_default_node4 : public Compute
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Compute_bt_par_test_readonly_default_node4, Compute);
		Compute_bt_par_test_readonly_default_node4()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			int opr1 = ((PropertyReadonlyAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_PropertyReadonlyAgent_MemberReadonly, int >();
			int opr2 = ((PropertyReadonlyAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_PropertyReadonlyAgent_PropertyGetterOnly, int >();
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("c_ResultStatic") == 450204216u);
			pAgent->SetVariable("c_ResultStatic", (int)(opr1 + opr2), 450204216u);
			return result;
		}
	};

		bool bt_par_test_readonly_default::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("par_test/readonly_default");
			pBT->SetIsFSM(false);
#if !BEHAVIAC_RELEASE
			pBT->SetAgentType("PropertyReadonlyAgent");
#endif
			// children
			{
				Sequence* node0 = BEHAVIAC_NEW Sequence;
				node0->SetClassNameString("Sequence");
				node0->SetId(0);
#if !BEHAVIAC_RELEASE
				node0->SetAgentType("PropertyReadonlyAgent");
#endif
				pBT->AddChild(node0);
				{
					Assignment_bt_par_test_readonly_default_node3* node3 = BEHAVIAC_NEW Assignment_bt_par_test_readonly_default_node3;
					node3->SetClassNameString("Assignment");
					node3->SetId(3);
#if !BEHAVIAC_RELEASE
					node3->SetAgentType("PropertyReadonlyAgent");
#endif
					node0->AddChild(node3);
					node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
				}
				{
					Action_bt_par_test_readonly_default_node1* node1 = BEHAVIAC_NEW Action_bt_par_test_readonly_default_node1;
					node1->SetClassNameString("Action");
					node1->SetId(1);
#if !BEHAVIAC_RELEASE
					node1->SetAgentType("PropertyReadonlyAgent");
#endif
					node0->AddChild(node1);
					node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
				}
				{
					Action_bt_par_test_readonly_default_node2* node2 = BEHAVIAC_NEW Action_bt_par_test_readonly_default_node2;
					node2->SetClassNameString("Action");
					node2->SetId(2);
#if !BEHAVIAC_RELEASE
					node2->SetAgentType("PropertyReadonlyAgent");
#endif
					node0->AddChild(node2);
					node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
				}
				{
					Compute_bt_par_test_readonly_default_node4* node4 = BEHAVIAC_NEW Compute_bt_par_test_readonly_default_node4;
					node4->SetClassNameString("Compute");
					node4->SetId(4);
#if !BEHAVIAC_RELEASE
					node4->SetAgentType("PropertyReadonlyAgent");
#endif
					node0->AddChild(node4);
					node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
				}
				pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
			}
			return true;
		}

}
