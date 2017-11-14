#include "generated_behaviors_0.h"

namespace behaviac
{
	// Source file: node_test/fsm/action_ut_1_2

	class DecoratorLoop_bt_node_test_fsm_action_ut_1_2_node8 : public DecoratorLoop
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorLoop_bt_node_test_fsm_action_ut_1_2_node8, DecoratorLoop);
		DecoratorLoop_bt_node_test_fsm_action_ut_1_2_node8()
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

	class Compute_bt_node_test_fsm_action_ut_1_2_node3 : public Compute
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Compute_bt_node_test_fsm_action_ut_1_2_node3, Compute);
		Compute_bt_node_test_fsm_action_ut_1_2_node3()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			float opr1 = 0.5f;
			float opr2 = 1.3f;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par_float_type_0") == 569873069u);
			pAgent->SetVariable("par_float_type_0", (float)(opr1 + opr2), 569873069u);
			return result;
		}
	};

	class Action_bt_node_test_fsm_action_ut_1_2_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_fsm_action_ut_1_2_node2, Action);
		Action_bt_node_test_fsm_action_ut_1_2_node2()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par_float_type_0") == 569873069u);
			float& method_p0 = (float&)pAgent->GetVariable<float >(569873069u);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_2, void, float >(method_p0);
			return BT_SUCCESS;
		}
	};

	class Assignment_bt_node_test_fsm_action_ut_1_2_node1 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_node_test_fsm_action_ut_1_2_node1, Assignment);
		Assignment_bt_node_test_fsm_action_ut_1_2_node1()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			float opr = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_2, float >();
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par_float_type_1") == 955032556u);
			pAgent->SetVariable("par_float_type_1", opr, 955032556u);
			return result;
		}
	};

	class Compute_bt_node_test_fsm_action_ut_1_2_node4 : public Compute
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Compute_bt_node_test_fsm_action_ut_1_2_node4, Compute);
		Compute_bt_node_test_fsm_action_ut_1_2_node4()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par_float_type_1") == 955032556u);
			float& opr1 = (float&)pAgent->GetVariable<float >(955032556u);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par_float_type_2") == 331477039u);
			float& opr2 = (float&)pAgent->GetVariable<float >(331477039u);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par_float_type_0") == 569873069u);
			pAgent->SetVariable("par_float_type_0", (float)(opr1 + opr2), 569873069u);
			return result;
		}
	};

	class Action_bt_node_test_fsm_action_ut_1_2_node5 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_fsm_action_ut_1_2_node5, Action);
		Action_bt_node_test_fsm_action_ut_1_2_node5()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par_float_type_0") == 569873069u);
			float& method_p0 = (float&)pAgent->GetVariable<float >(569873069u);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_3, void, float >(method_p0);
			return BT_SUCCESS;
		}
	};

	class Assignment_bt_node_test_fsm_action_ut_1_2_node7 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_node_test_fsm_action_ut_1_2_node7, Assignment);
		Assignment_bt_node_test_fsm_action_ut_1_2_node7()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			UnityEngine::GameObject* opr = ((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_createGameObject, UnityEngine::GameObject* >();
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par_go") == 464621558u);
			pAgent->SetVariable("par_go", opr, 464621558u);
			return result;
		}
	};

	class Action_bt_node_test_fsm_action_ut_1_2_node6 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_fsm_action_ut_1_2_node6, Action);
		Action_bt_node_test_fsm_action_ut_1_2_node6()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par_go") == 464621558u);
			UnityEngine::GameObject*& method_p0 = (UnityEngine::GameObject*&)pAgent->GetVariable<UnityEngine::GameObject* >(464621558u);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_testGameObject, void, UnityEngine::GameObject* >(method_p0);
			return BT_SUCCESS;
		}
	};

		bool bt_node_test_fsm_action_ut_1_2::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("node_test/fsm/action_ut_1_2");
			pBT->SetIsFSM(false);
#if !BEHAVIAC_RELEASE
			pBT->SetAgentType("AgentNodeTest");
#endif
			// pars
			pBT->AddPar("AgentNodeTest", "UnityEngine::GameObject", "par_go", "null");
			pBT->AddPar("AgentNodeTest", "float", "par_float_type_0", "0");
			pBT->AddPar("AgentNodeTest", "float", "par_float_type_1", "0");
			pBT->AddPar("AgentNodeTest", "float", "par_float_type_2", "2.7");
			// children
			{
				DecoratorLoop_bt_node_test_fsm_action_ut_1_2_node8* node8 = BEHAVIAC_NEW DecoratorLoop_bt_node_test_fsm_action_ut_1_2_node8;
				node8->SetClassNameString("DecoratorLoop");
				node8->SetId(8);
#if !BEHAVIAC_RELEASE
				node8->SetAgentType("AgentNodeTest");
#endif
				pBT->AddChild(node8);
				{
					Sequence* node0 = BEHAVIAC_NEW Sequence;
					node0->SetClassNameString("Sequence");
					node0->SetId(0);
#if !BEHAVIAC_RELEASE
					node0->SetAgentType("AgentNodeTest");
#endif
					node8->AddChild(node0);
					{
						Compute_bt_node_test_fsm_action_ut_1_2_node3* node3 = BEHAVIAC_NEW Compute_bt_node_test_fsm_action_ut_1_2_node3;
						node3->SetClassNameString("Compute");
						node3->SetId(3);
#if !BEHAVIAC_RELEASE
						node3->SetAgentType("AgentNodeTest");
#endif
						node0->AddChild(node3);
						node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
					}
					{
						Action_bt_node_test_fsm_action_ut_1_2_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_fsm_action_ut_1_2_node2;
						node2->SetClassNameString("Action");
						node2->SetId(2);
#if !BEHAVIAC_RELEASE
						node2->SetAgentType("AgentNodeTest");
#endif
						node0->AddChild(node2);
						node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
					}
					{
						Assignment_bt_node_test_fsm_action_ut_1_2_node1* node1 = BEHAVIAC_NEW Assignment_bt_node_test_fsm_action_ut_1_2_node1;
						node1->SetClassNameString("Assignment");
						node1->SetId(1);
#if !BEHAVIAC_RELEASE
						node1->SetAgentType("AgentNodeTest");
#endif
						node0->AddChild(node1);
						node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
					}
					{
						Compute_bt_node_test_fsm_action_ut_1_2_node4* node4 = BEHAVIAC_NEW Compute_bt_node_test_fsm_action_ut_1_2_node4;
						node4->SetClassNameString("Compute");
						node4->SetId(4);
#if !BEHAVIAC_RELEASE
						node4->SetAgentType("AgentNodeTest");
#endif
						node0->AddChild(node4);
						node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
					}
					{
						Action_bt_node_test_fsm_action_ut_1_2_node5* node5 = BEHAVIAC_NEW Action_bt_node_test_fsm_action_ut_1_2_node5;
						node5->SetClassNameString("Action");
						node5->SetId(5);
#if !BEHAVIAC_RELEASE
						node5->SetAgentType("AgentNodeTest");
#endif
						node0->AddChild(node5);
						node0->SetHasEvents(node0->HasEvents() | node5->HasEvents());
					}
					{
						Assignment_bt_node_test_fsm_action_ut_1_2_node7* node7 = BEHAVIAC_NEW Assignment_bt_node_test_fsm_action_ut_1_2_node7;
						node7->SetClassNameString("Assignment");
						node7->SetId(7);
#if !BEHAVIAC_RELEASE
						node7->SetAgentType("AgentNodeTest");
#endif
						node0->AddChild(node7);
						node0->SetHasEvents(node0->HasEvents() | node7->HasEvents());
					}
					{
						Action_bt_node_test_fsm_action_ut_1_2_node6* node6 = BEHAVIAC_NEW Action_bt_node_test_fsm_action_ut_1_2_node6;
						node6->SetClassNameString("Action");
						node6->SetId(6);
#if !BEHAVIAC_RELEASE
						node6->SetAgentType("AgentNodeTest");
#endif
						node0->AddChild(node6);
						node0->SetHasEvents(node0->HasEvents() | node6->HasEvents());
					}
					node8->SetHasEvents(node8->HasEvents() | node0->HasEvents());
				}
				pBT->SetHasEvents(pBT->HasEvents() | node8->HasEvents());
			}
			return true;
		}

	// Source file: node_test/fsm/bt_ref_fsm

	class Assignment_bt_node_test_fsm_bt_ref_fsm_node2 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_node_test_fsm_bt_ref_fsm_node2, Assignment);
		Assignment_bt_node_test_fsm_bt_ref_fsm_node2()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			int opr = -1;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("FoodCount") == 3299892854u);
			pAgent->SetVariable("FoodCount", opr, 3299892854u);
			return result;
		}
	};

	class ReferencedBehavior_bt_node_test_fsm_bt_ref_fsm_node1 : public ReferencedBehavior
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(ReferencedBehavior_bt_node_test_fsm_bt_ref_fsm_node1, ReferencedBehavior);
		ReferencedBehavior_bt_node_test_fsm_bt_ref_fsm_node1()
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
			return (char*)("node_test/fsm/fsm_ut_0");
		}
	};

		bool bt_node_test_fsm_bt_ref_fsm::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("node_test/fsm/bt_ref_fsm");
			pBT->SetIsFSM(false);
#if !BEHAVIAC_RELEASE
			pBT->SetAgentType("FSMAgentTest");
#endif
			// children
			{
				Sequence* node0 = BEHAVIAC_NEW Sequence;
				node0->SetClassNameString("Sequence");
				node0->SetId(0);
#if !BEHAVIAC_RELEASE
				node0->SetAgentType("FSMAgentTest");
#endif
				pBT->AddChild(node0);
				{
					Assignment_bt_node_test_fsm_bt_ref_fsm_node2* node2 = BEHAVIAC_NEW Assignment_bt_node_test_fsm_bt_ref_fsm_node2;
					node2->SetClassNameString("Assignment");
					node2->SetId(2);
#if !BEHAVIAC_RELEASE
					node2->SetAgentType("FSMAgentTest");
#endif
					node0->AddChild(node2);
					node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
				}
				{
					ReferencedBehavior_bt_node_test_fsm_bt_ref_fsm_node1* node1 = BEHAVIAC_NEW ReferencedBehavior_bt_node_test_fsm_bt_ref_fsm_node1;
					node1->SetClassNameString("ReferencedBehavior");
					node1->SetId(1);
#if !BEHAVIAC_RELEASE
					node1->SetAgentType("FSMAgentTest");
#endif
					node0->AddChild(node1);
					node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
				}
				pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
			}
			return true;
		}

	// Source file: node_test/fsm/fsm_ref_bt_ut

	class State_bt_node_test_fsm_fsm_ref_bt_ut_node1 : public State
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(State_bt_node_test_fsm_fsm_ref_bt_ut_node1, State);
		State_bt_node_test_fsm_fsm_ref_bt_ut_node1()
		{
			this->m_bIsEndState = false;
			method_p0 = 1;
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

	class Transition_bt_node_test_fsm_fsm_ref_bt_ut_attach4 : public Transition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Transition_bt_node_test_fsm_fsm_ref_bt_ut_attach4, Transition);
		Transition_bt_node_test_fsm_fsm_ref_bt_ut_attach4()
		{
			this->SetTargetStateId(6);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			int opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, int >();
			int opr2 = 1;
			bool op = Details::Equal(opl, opr2);
			if (!op)
				result = BT_FAILURE;
			return result;
		}
	};

	class State_bt_node_test_fsm_fsm_ref_bt_ut_node3 : public State
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(State_bt_node_test_fsm_fsm_ref_bt_ut_node3, State);
		State_bt_node_test_fsm_fsm_ref_bt_ut_node3()
		{
			this->m_bIsEndState = false;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			return BT_RUNNING;
		}
	};

	class Precondition_bt_node_test_fsm_fsm_ref_bt_ut_attach2 : public Precondition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Precondition_bt_node_test_fsm_fsm_ref_bt_ut_attach2, Precondition);
		Precondition_bt_node_test_fsm_fsm_ref_bt_ut_attach2()
		{
			this->SetPhase(Precondition::E_ENTER);
			this->SetIsAnd(true);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			int opr2 = 4;
			((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, int >() = opr2;
			return result;
		}
	};

	class ReferencedBehavior_bt_node_test_fsm_fsm_ref_bt_ut_node6 : public ReferencedBehavior
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(ReferencedBehavior_bt_node_test_fsm_fsm_ref_bt_ut_node6, ReferencedBehavior);
		ReferencedBehavior_bt_node_test_fsm_fsm_ref_bt_ut_node6()
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
			return (char*)("node_test/fsm/action_ut_1_2");
		}
	};

	class Precondition_bt_node_test_fsm_fsm_ref_bt_ut_attach5 : public Precondition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Precondition_bt_node_test_fsm_fsm_ref_bt_ut_attach5, Precondition);
		Precondition_bt_node_test_fsm_fsm_ref_bt_ut_attach5()
		{
			this->SetPhase(Precondition::E_UPDATE);
			this->SetIsAnd(true);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			int opr1 = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, int >();
			int opr2 = 1;
			((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, int >() = (int)(opr1 + opr2);
			return result;
		}
	};

	class Transition_bt_node_test_fsm_fsm_ref_bt_ut_attach9 : public Transition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Transition_bt_node_test_fsm_fsm_ref_bt_ut_attach9, Transition);
		Transition_bt_node_test_fsm_fsm_ref_bt_ut_attach9()
		{
			this->SetTargetStateId(3);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			int opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, int >();
			int opr2 = 3;
			bool op = Details::GreaterEqual(opl, opr2);
			if (!op)
				result = BT_FAILURE;
			return result;
		}
	};

		bool bt_node_test_fsm_fsm_ref_bt_ut::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("node_test/fsm/fsm_ref_bt_ut");
			pBT->SetIsFSM(true);
#if !BEHAVIAC_RELEASE
			pBT->SetAgentType("AgentNodeTest");
#endif
			// attachments
			// children
			{
				FSM* fsm = BEHAVIAC_NEW FSM();
				fsm->SetClassNameString("FSM");
				fsm->SetId((uint16_t)-1);
				fsm->SetInitialId(1);
#if !BEHAVIAC_RELEASE
				fsm->SetAgentType("AgentNodeTest");
#endif
				{
					State_bt_node_test_fsm_fsm_ref_bt_ut_node1* node1 = BEHAVIAC_NEW State_bt_node_test_fsm_fsm_ref_bt_ut_node1;
					node1->SetClassNameString("State");
					node1->SetId(1);
#if !BEHAVIAC_RELEASE
					node1->SetAgentType("AgentNodeTest");
#endif
					// attachments
					{
						Transition_bt_node_test_fsm_fsm_ref_bt_ut_attach4* attach4 = BEHAVIAC_NEW Transition_bt_node_test_fsm_fsm_ref_bt_ut_attach4;
						attach4->SetClassNameString("Transition");
						attach4->SetId(4);
#if !BEHAVIAC_RELEASE
						attach4->SetAgentType("AgentNodeTest");
#endif
						node1->Attach(attach4, false, false, true);
						node1->SetHasEvents(node1->HasEvents() | (Event::DynamicCast(attach4) != 0));
					}
					fsm->AddChild(node1);
					fsm->SetHasEvents(fsm->HasEvents() | node1->HasEvents());
				}
				{
					State_bt_node_test_fsm_fsm_ref_bt_ut_node3* node3 = BEHAVIAC_NEW State_bt_node_test_fsm_fsm_ref_bt_ut_node3;
					node3->SetClassNameString("State");
					node3->SetId(3);
#if !BEHAVIAC_RELEASE
					node3->SetAgentType("AgentNodeTest");
#endif
					// attachments
					{
						Precondition_bt_node_test_fsm_fsm_ref_bt_ut_attach2* attach2 = BEHAVIAC_NEW Precondition_bt_node_test_fsm_fsm_ref_bt_ut_attach2;
						attach2->SetClassNameString("Precondition");
						attach2->SetId(2);
#if !BEHAVIAC_RELEASE
						attach2->SetAgentType("AgentNodeTest");
#endif
						node3->Attach(attach2, true, false, false);
						node3->SetHasEvents(node3->HasEvents() | (Event::DynamicCast(attach2) != 0));
					}
					fsm->AddChild(node3);
					fsm->SetHasEvents(fsm->HasEvents() | node3->HasEvents());
				}
				{
					ReferencedBehavior_bt_node_test_fsm_fsm_ref_bt_ut_node6* node6 = BEHAVIAC_NEW ReferencedBehavior_bt_node_test_fsm_fsm_ref_bt_ut_node6;
					node6->SetClassNameString("ReferencedBehavior");
					node6->SetId(6);
#if !BEHAVIAC_RELEASE
					node6->SetAgentType("AgentNodeTest");
#endif
					// attachments
					{
						Precondition_bt_node_test_fsm_fsm_ref_bt_ut_attach5* attach5 = BEHAVIAC_NEW Precondition_bt_node_test_fsm_fsm_ref_bt_ut_attach5;
						attach5->SetClassNameString("Precondition");
						attach5->SetId(5);
#if !BEHAVIAC_RELEASE
						attach5->SetAgentType("AgentNodeTest");
#endif
						node6->Attach(attach5, true, false, false);
						node6->SetHasEvents(node6->HasEvents() | (Event::DynamicCast(attach5) != 0));
					}
					{
						Transition_bt_node_test_fsm_fsm_ref_bt_ut_attach9* attach9 = BEHAVIAC_NEW Transition_bt_node_test_fsm_fsm_ref_bt_ut_attach9;
						attach9->SetClassNameString("Transition");
						attach9->SetId(9);
#if !BEHAVIAC_RELEASE
						attach9->SetAgentType("AgentNodeTest");
#endif
						node6->Attach(attach9, false, false, true);
						node6->SetHasEvents(node6->HasEvents() | (Event::DynamicCast(attach9) != 0));
					}
					fsm->AddChild(node6);
					fsm->SetHasEvents(fsm->HasEvents() | node6->HasEvents());
				}
				pBT->AddChild(fsm);
			}
			return true;
		}

	// Source file: node_test/fsm/fsm_ref_fsm_ut

	class State_bt_node_test_fsm_fsm_ref_fsm_ut_node3 : public State
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(State_bt_node_test_fsm_fsm_ref_fsm_ut_node3, State);
		State_bt_node_test_fsm_fsm_ref_fsm_ut_node3()
		{
			this->m_bIsEndState = false;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((FSMAgentTest*)pAgent)->_Execute_Method_<METHOD_TYPE_FSMAgentTest_inactive_update, void >();
			return BT_RUNNING;
		}
	};

	class Precondition_bt_node_test_fsm_fsm_ref_fsm_ut_attach10 : public Precondition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Precondition_bt_node_test_fsm_fsm_ref_fsm_ut_attach10, Precondition);
		Precondition_bt_node_test_fsm_fsm_ref_fsm_ut_attach10()
		{
			this->SetPhase(Precondition::E_ENTER);
			this->SetIsAnd(true);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			int opr2 = 0;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("InactiveCount") == 1246269412u);
			pAgent->SetVariable("InactiveCount", opr2, 1246269412u);
			return result;
		}
	};

	class Transition_bt_node_test_fsm_fsm_ref_fsm_ut_attach5 : public Transition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Transition_bt_node_test_fsm_fsm_ref_fsm_ut_attach5, Transition);
		Transition_bt_node_test_fsm_fsm_ref_fsm_ut_attach5()
		{
			this->SetTargetStateId(18);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			FSMAgentTest::EMessage opl = ((FSMAgentTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_FSMAgentTest_Message, FSMAgentTest::EMessage >();
			FSMAgentTest::EMessage opr2 = FSMAgentTest::Begin;
			bool op = Details::Equal(opl, opr2);
			if (!op)
				result = BT_FAILURE;
			return result;
		}
	};

	class Effector_bt_node_test_fsm_fsm_ref_fsm_ut_attach14 : public Effector
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Effector_bt_node_test_fsm_fsm_ref_fsm_ut_attach14, Effector);
		Effector_bt_node_test_fsm_fsm_ref_fsm_ut_attach14()
		{
			this->SetPhase(Effector::E_SUCCESS);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("InactiveCount") == 1246269412u);
			int& opr1 = (int&)pAgent->GetVariable<int >(1246269412u);
			int opr2 = 1;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("InactiveCount") == 1246269412u);
			pAgent->SetVariable("InactiveCount", (int)(opr1 + opr2), 1246269412u);
			return result;
		}
	};

	class Transition_bt_node_test_fsm_fsm_ref_fsm_ut_attach6 : public Transition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Transition_bt_node_test_fsm_fsm_ref_fsm_ut_attach6, Transition);
		Transition_bt_node_test_fsm_fsm_ref_fsm_ut_attach6()
		{
			this->SetTargetStateId(2);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			FSMAgentTest::EMessage opl = ((FSMAgentTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_FSMAgentTest_Message, FSMAgentTest::EMessage >();
			FSMAgentTest::EMessage opr2 = FSMAgentTest::Exit;
			bool op = Details::Equal(opl, opr2);
			if (!op)
				result = BT_FAILURE;
			return result;
		}
	};

	class State_bt_node_test_fsm_fsm_ref_fsm_ut_node2 : public State
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(State_bt_node_test_fsm_fsm_ref_fsm_ut_node2, State);
		State_bt_node_test_fsm_fsm_ref_fsm_ut_node2()
		{
			this->m_bIsEndState = true;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			return BT_RUNNING;
		}
	};

	class Precondition_bt_node_test_fsm_fsm_ref_fsm_ut_attach12 : public Precondition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Precondition_bt_node_test_fsm_fsm_ref_fsm_ut_attach12, Precondition);
		Precondition_bt_node_test_fsm_fsm_ref_fsm_ut_attach12()
		{
			this->SetPhase(Precondition::E_ENTER);
			this->SetIsAnd(true);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			long opr2 = 0;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("ExitCount") == 1184325508u);
			pAgent->SetVariable("ExitCount", opr2, 1184325508u);
			return result;
		}
	};

	class Effector_bt_node_test_fsm_fsm_ref_fsm_ut_attach15 : public Effector
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Effector_bt_node_test_fsm_fsm_ref_fsm_ut_attach15, Effector);
		Effector_bt_node_test_fsm_fsm_ref_fsm_ut_attach15()
		{
			this->SetPhase(Effector::E_SUCCESS);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("ExitCount") == 1184325508u);
			long& opr1 = (long&)pAgent->GetVariable<long >(1184325508u);
			long opr2 = 1;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("ExitCount") == 1184325508u);
			pAgent->SetVariable("ExitCount", (long)(opr1 + opr2), 1184325508u);
			return result;
		}
	};

	class State_bt_node_test_fsm_fsm_ref_fsm_ut_node4 : public State
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(State_bt_node_test_fsm_fsm_ref_fsm_ut_node4, State);
		State_bt_node_test_fsm_fsm_ref_fsm_ut_node4()
		{
			this->m_bIsEndState = false;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((FSMAgentTest*)pAgent)->_Execute_Method_<METHOD_TYPE_FSMAgentTest_pause_update, void >();
			return BT_RUNNING;
		}
	};

	class Precondition_bt_node_test_fsm_fsm_ref_fsm_ut_attach13 : public Precondition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Precondition_bt_node_test_fsm_fsm_ref_fsm_ut_attach13, Precondition);
		Precondition_bt_node_test_fsm_fsm_ref_fsm_ut_attach13()
		{
			this->SetPhase(Precondition::E_ENTER);
			this->SetIsAnd(true);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			short opr2 = 0;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("PauseCount") == 3020354788u);
			pAgent->SetVariable("PauseCount", opr2, 3020354788u);
			return result;
		}
	};

	class Transition_bt_node_test_fsm_fsm_ref_fsm_ut_attach8 : public Transition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Transition_bt_node_test_fsm_fsm_ref_fsm_ut_attach8, Transition);
		Transition_bt_node_test_fsm_fsm_ref_fsm_ut_attach8()
		{
			this->SetTargetStateId(3);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			FSMAgentTest::EMessage opl = ((FSMAgentTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_FSMAgentTest_Message, FSMAgentTest::EMessage >();
			FSMAgentTest::EMessage opr2 = FSMAgentTest::End;
			bool op = Details::Equal(opl, opr2);
			if (!op)
				result = BT_FAILURE;
			return result;
		}
	};

	class Transition_bt_node_test_fsm_fsm_ref_fsm_ut_attach9 : public Transition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Transition_bt_node_test_fsm_fsm_ref_fsm_ut_attach9, Transition);
		Transition_bt_node_test_fsm_fsm_ref_fsm_ut_attach9()
		{
			this->SetTargetStateId(1);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			FSMAgentTest::EMessage opl = ((FSMAgentTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_FSMAgentTest_Message, FSMAgentTest::EMessage >();
			FSMAgentTest::EMessage opr2 = FSMAgentTest::Resume;
			bool op = Details::Equal(opl, opr2);
			if (!op)
				result = BT_FAILURE;
			return result;
		}
	};

	class Effector_bt_node_test_fsm_fsm_ref_fsm_ut_attach16 : public Effector
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Effector_bt_node_test_fsm_fsm_ref_fsm_ut_attach16, Effector);
		Effector_bt_node_test_fsm_fsm_ref_fsm_ut_attach16()
		{
			this->SetPhase(Effector::E_SUCCESS);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("PauseCount") == 3020354788u);
			short& opr1 = (short&)pAgent->GetVariable<short >(3020354788u);
			short opr2 = 1;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("PauseCount") == 3020354788u);
			pAgent->SetVariable("PauseCount", (short)(opr1 + opr2), 3020354788u);
			return result;
		}
	};

	class ReferencedBehavior_bt_node_test_fsm_fsm_ref_fsm_ut_node18 : public ReferencedBehavior
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(ReferencedBehavior_bt_node_test_fsm_fsm_ref_fsm_ut_node18, ReferencedBehavior);
		ReferencedBehavior_bt_node_test_fsm_fsm_ref_fsm_ut_node18()
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
			return (char*)("node_test/fsm/fsm_ut_0");
		}
	};

	class Precondition_bt_node_test_fsm_fsm_ref_fsm_ut_attach11 : public Precondition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Precondition_bt_node_test_fsm_fsm_ref_fsm_ut_attach11, Precondition);
		Precondition_bt_node_test_fsm_fsm_ref_fsm_ut_attach11()
		{
			this->SetPhase(Precondition::E_ENTER);
			this->SetIsAnd(true);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			unsigned int opr2 = 0;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("ActiveCount") == 177115358u);
			pAgent->SetVariable("ActiveCount", opr2, 177115358u);
			return result;
		}
	};

	class Transition_bt_node_test_fsm_fsm_ref_fsm_ut_attach7 : public Transition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Transition_bt_node_test_fsm_fsm_ref_fsm_ut_attach7, Transition);
		Transition_bt_node_test_fsm_fsm_ref_fsm_ut_attach7()
		{
			this->SetTargetStateId(4);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			FSMAgentTest::EMessage opl = ((FSMAgentTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_FSMAgentTest_Message, FSMAgentTest::EMessage >();
			FSMAgentTest::EMessage opr2 = FSMAgentTest::Pause;
			bool op = Details::Equal(opl, opr2);
			if (!op)
				result = BT_FAILURE;
			return result;
		}
	};

	class Effector_bt_node_test_fsm_fsm_ref_fsm_ut_attach17 : public Effector
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Effector_bt_node_test_fsm_fsm_ref_fsm_ut_attach17, Effector);
		Effector_bt_node_test_fsm_fsm_ref_fsm_ut_attach17()
		{
			this->SetPhase(Effector::E_SUCCESS);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("ActiveCount") == 177115358u);
			unsigned int& opr1 = (unsigned int&)pAgent->GetVariable<unsigned int >(177115358u);
			unsigned int opr2 = 1;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("ActiveCount") == 177115358u);
			pAgent->SetVariable("ActiveCount", (unsigned int)(opr1 + opr2), 177115358u);
			return result;
		}
	};

		bool bt_node_test_fsm_fsm_ref_fsm_ut::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("node_test/fsm/fsm_ref_fsm_ut");
			pBT->SetIsFSM(true);
#if !BEHAVIAC_RELEASE
			pBT->SetAgentType("FSMAgentTest");
#endif
			// attachments
			// children
			{
				FSM* fsm = BEHAVIAC_NEW FSM();
				fsm->SetClassNameString("FSM");
				fsm->SetId((uint16_t)-1);
				fsm->SetInitialId(3);
#if !BEHAVIAC_RELEASE
				fsm->SetAgentType("FSMAgentTest");
#endif
				{
					State_bt_node_test_fsm_fsm_ref_fsm_ut_node3* node3 = BEHAVIAC_NEW State_bt_node_test_fsm_fsm_ref_fsm_ut_node3;
					node3->SetClassNameString("State");
					node3->SetId(3);
#if !BEHAVIAC_RELEASE
					node3->SetAgentType("FSMAgentTest");
#endif
					// attachments
					{
						Precondition_bt_node_test_fsm_fsm_ref_fsm_ut_attach10* attach10 = BEHAVIAC_NEW Precondition_bt_node_test_fsm_fsm_ref_fsm_ut_attach10;
						attach10->SetClassNameString("Precondition");
						attach10->SetId(10);
#if !BEHAVIAC_RELEASE
						attach10->SetAgentType("FSMAgentTest");
#endif
						node3->Attach(attach10, true, false, false);
						node3->SetHasEvents(node3->HasEvents() | (Event::DynamicCast(attach10) != 0));
					}
					{
						Transition_bt_node_test_fsm_fsm_ref_fsm_ut_attach5* attach5 = BEHAVIAC_NEW Transition_bt_node_test_fsm_fsm_ref_fsm_ut_attach5;
						attach5->SetClassNameString("Transition");
						attach5->SetId(5);
#if !BEHAVIAC_RELEASE
						attach5->SetAgentType("FSMAgentTest");
#endif
						node3->Attach(attach5, false, false, true);
						node3->SetHasEvents(node3->HasEvents() | (Event::DynamicCast(attach5) != 0));
					}
					{
						Effector_bt_node_test_fsm_fsm_ref_fsm_ut_attach14* attach14 = BEHAVIAC_NEW Effector_bt_node_test_fsm_fsm_ref_fsm_ut_attach14;
						attach14->SetClassNameString("Effector");
						attach14->SetId(14);
#if !BEHAVIAC_RELEASE
						attach14->SetAgentType("FSMAgentTest");
#endif
						node3->Attach(attach14, false, true, false);
						node3->SetHasEvents(node3->HasEvents() | (Event::DynamicCast(attach14) != 0));
					}
					{
						Transition_bt_node_test_fsm_fsm_ref_fsm_ut_attach6* attach6 = BEHAVIAC_NEW Transition_bt_node_test_fsm_fsm_ref_fsm_ut_attach6;
						attach6->SetClassNameString("Transition");
						attach6->SetId(6);
#if !BEHAVIAC_RELEASE
						attach6->SetAgentType("FSMAgentTest");
#endif
						node3->Attach(attach6, false, false, true);
						node3->SetHasEvents(node3->HasEvents() | (Event::DynamicCast(attach6) != 0));
					}
					fsm->AddChild(node3);
					fsm->SetHasEvents(fsm->HasEvents() | node3->HasEvents());
				}
				{
					State_bt_node_test_fsm_fsm_ref_fsm_ut_node2* node2 = BEHAVIAC_NEW State_bt_node_test_fsm_fsm_ref_fsm_ut_node2;
					node2->SetClassNameString("State");
					node2->SetId(2);
#if !BEHAVIAC_RELEASE
					node2->SetAgentType("FSMAgentTest");
#endif
					// attachments
					{
						Precondition_bt_node_test_fsm_fsm_ref_fsm_ut_attach12* attach12 = BEHAVIAC_NEW Precondition_bt_node_test_fsm_fsm_ref_fsm_ut_attach12;
						attach12->SetClassNameString("Precondition");
						attach12->SetId(12);
#if !BEHAVIAC_RELEASE
						attach12->SetAgentType("FSMAgentTest");
#endif
						node2->Attach(attach12, true, false, false);
						node2->SetHasEvents(node2->HasEvents() | (Event::DynamicCast(attach12) != 0));
					}
					{
						Effector_bt_node_test_fsm_fsm_ref_fsm_ut_attach15* attach15 = BEHAVIAC_NEW Effector_bt_node_test_fsm_fsm_ref_fsm_ut_attach15;
						attach15->SetClassNameString("Effector");
						attach15->SetId(15);
#if !BEHAVIAC_RELEASE
						attach15->SetAgentType("FSMAgentTest");
#endif
						node2->Attach(attach15, false, true, false);
						node2->SetHasEvents(node2->HasEvents() | (Event::DynamicCast(attach15) != 0));
					}
					fsm->AddChild(node2);
					fsm->SetHasEvents(fsm->HasEvents() | node2->HasEvents());
				}
				{
					State_bt_node_test_fsm_fsm_ref_fsm_ut_node4* node4 = BEHAVIAC_NEW State_bt_node_test_fsm_fsm_ref_fsm_ut_node4;
					node4->SetClassNameString("State");
					node4->SetId(4);
#if !BEHAVIAC_RELEASE
					node4->SetAgentType("FSMAgentTest");
#endif
					// attachments
					{
						Precondition_bt_node_test_fsm_fsm_ref_fsm_ut_attach13* attach13 = BEHAVIAC_NEW Precondition_bt_node_test_fsm_fsm_ref_fsm_ut_attach13;
						attach13->SetClassNameString("Precondition");
						attach13->SetId(13);
#if !BEHAVIAC_RELEASE
						attach13->SetAgentType("FSMAgentTest");
#endif
						node4->Attach(attach13, true, false, false);
						node4->SetHasEvents(node4->HasEvents() | (Event::DynamicCast(attach13) != 0));
					}
					{
						Transition_bt_node_test_fsm_fsm_ref_fsm_ut_attach8* attach8 = BEHAVIAC_NEW Transition_bt_node_test_fsm_fsm_ref_fsm_ut_attach8;
						attach8->SetClassNameString("Transition");
						attach8->SetId(8);
#if !BEHAVIAC_RELEASE
						attach8->SetAgentType("FSMAgentTest");
#endif
						node4->Attach(attach8, false, false, true);
						node4->SetHasEvents(node4->HasEvents() | (Event::DynamicCast(attach8) != 0));
					}
					{
						Transition_bt_node_test_fsm_fsm_ref_fsm_ut_attach9* attach9 = BEHAVIAC_NEW Transition_bt_node_test_fsm_fsm_ref_fsm_ut_attach9;
						attach9->SetClassNameString("Transition");
						attach9->SetId(9);
#if !BEHAVIAC_RELEASE
						attach9->SetAgentType("FSMAgentTest");
#endif
						node4->Attach(attach9, false, false, true);
						node4->SetHasEvents(node4->HasEvents() | (Event::DynamicCast(attach9) != 0));
					}
					{
						Effector_bt_node_test_fsm_fsm_ref_fsm_ut_attach16* attach16 = BEHAVIAC_NEW Effector_bt_node_test_fsm_fsm_ref_fsm_ut_attach16;
						attach16->SetClassNameString("Effector");
						attach16->SetId(16);
#if !BEHAVIAC_RELEASE
						attach16->SetAgentType("FSMAgentTest");
#endif
						node4->Attach(attach16, false, true, false);
						node4->SetHasEvents(node4->HasEvents() | (Event::DynamicCast(attach16) != 0));
					}
					fsm->AddChild(node4);
					fsm->SetHasEvents(fsm->HasEvents() | node4->HasEvents());
				}
				{
					ReferencedBehavior_bt_node_test_fsm_fsm_ref_fsm_ut_node18* node18 = BEHAVIAC_NEW ReferencedBehavior_bt_node_test_fsm_fsm_ref_fsm_ut_node18;
					node18->SetClassNameString("ReferencedBehavior");
					node18->SetId(18);
#if !BEHAVIAC_RELEASE
					node18->SetAgentType("FSMAgentTest");
#endif
					// attachments
					{
						Precondition_bt_node_test_fsm_fsm_ref_fsm_ut_attach11* attach11 = BEHAVIAC_NEW Precondition_bt_node_test_fsm_fsm_ref_fsm_ut_attach11;
						attach11->SetClassNameString("Precondition");
						attach11->SetId(11);
#if !BEHAVIAC_RELEASE
						attach11->SetAgentType("FSMAgentTest");
#endif
						node18->Attach(attach11, true, false, false);
						node18->SetHasEvents(node18->HasEvents() | (Event::DynamicCast(attach11) != 0));
					}
					{
						Transition_bt_node_test_fsm_fsm_ref_fsm_ut_attach7* attach7 = BEHAVIAC_NEW Transition_bt_node_test_fsm_fsm_ref_fsm_ut_attach7;
						attach7->SetClassNameString("Transition");
						attach7->SetId(7);
#if !BEHAVIAC_RELEASE
						attach7->SetAgentType("FSMAgentTest");
#endif
						node18->Attach(attach7, false, false, true);
						node18->SetHasEvents(node18->HasEvents() | (Event::DynamicCast(attach7) != 0));
					}
					{
						Effector_bt_node_test_fsm_fsm_ref_fsm_ut_attach17* attach17 = BEHAVIAC_NEW Effector_bt_node_test_fsm_fsm_ref_fsm_ut_attach17;
						attach17->SetClassNameString("Effector");
						attach17->SetId(17);
#if !BEHAVIAC_RELEASE
						attach17->SetAgentType("FSMAgentTest");
#endif
						node18->Attach(attach17, false, true, false);
						node18->SetHasEvents(node18->HasEvents() | (Event::DynamicCast(attach17) != 0));
					}
					fsm->AddChild(node18);
					fsm->SetHasEvents(fsm->HasEvents() | node18->HasEvents());
				}
				pBT->AddChild(fsm);
			}
			return true;
		}

	// Source file: node_test/fsm/fsm_ut_0

	class State_bt_node_test_fsm_fsm_ut_0_node3 : public State
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(State_bt_node_test_fsm_fsm_ut_0_node3, State);
		State_bt_node_test_fsm_fsm_ut_0_node3()
		{
			this->m_bIsEndState = false;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((FSMAgentTest*)pAgent)->_Execute_Method_<METHOD_TYPE_FSMAgentTest_inactive_update, void >();
			return BT_RUNNING;
		}
	};

	class Precondition_bt_node_test_fsm_fsm_ut_0_attach10 : public Precondition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Precondition_bt_node_test_fsm_fsm_ut_0_attach10, Precondition);
		Precondition_bt_node_test_fsm_fsm_ut_0_attach10()
		{
			this->SetPhase(Precondition::E_ENTER);
			this->SetIsAnd(true);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			int opr2 = 0;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("FoodCount") == 3299892854u);
			pAgent->SetVariable("FoodCount", opr2, 3299892854u);
			return result;
		}
	};

	class Precondition_bt_node_test_fsm_fsm_ut_0_attach2 : public Precondition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Precondition_bt_node_test_fsm_fsm_ut_0_attach2, Precondition);
		Precondition_bt_node_test_fsm_fsm_ut_0_attach2()
		{
			this->SetPhase(Precondition::E_UPDATE);
			this->SetIsAnd(true);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("FoodCount") == 3299892854u);
			int& opr1 = (int&)pAgent->GetVariable<int >(3299892854u);
			int opr2 = 1;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("FoodCount") == 3299892854u);
			pAgent->SetVariable("FoodCount", (int)(opr1 + opr2), 3299892854u);
			return result;
		}
	};

	class Transition_bt_node_test_fsm_fsm_ut_0_attach5 : public Transition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Transition_bt_node_test_fsm_fsm_ut_0_attach5, Transition);
		Transition_bt_node_test_fsm_fsm_ut_0_attach5()
		{
			this->SetTargetStateId(1);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("FoodCount") == 3299892854u);
			int& opl = (int&)pAgent->GetVariable<int >(3299892854u);
			int opr2 = 10;
			bool op = Details::GreaterEqual(opl, opr2);
			if (!op)
				result = BT_FAILURE;
			return result;
		}
	};

	class State_bt_node_test_fsm_fsm_ut_0_node1 : public State
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(State_bt_node_test_fsm_fsm_ut_0_node1, State);
		State_bt_node_test_fsm_fsm_ut_0_node1()
		{
			this->m_bIsEndState = false;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((FSMAgentTest*)pAgent)->_Execute_Method_<METHOD_TYPE_FSMAgentTest_active_update, void >();
			return BT_RUNNING;
		}
	};

	class Precondition_bt_node_test_fsm_fsm_ut_0_attach6 : public Precondition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Precondition_bt_node_test_fsm_fsm_ut_0_attach6, Precondition);
		Precondition_bt_node_test_fsm_fsm_ut_0_attach6()
		{
			this->SetPhase(Precondition::E_UPDATE);
			this->SetIsAnd(true);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("FoodCount") == 3299892854u);
			int& opr1 = (int&)pAgent->GetVariable<int >(3299892854u);
			int opr2 = 2;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("FoodCount") == 3299892854u);
			pAgent->SetVariable("FoodCount", (int)(opr1 - opr2), 3299892854u);
			return result;
		}
	};

	class Precondition_bt_node_test_fsm_fsm_ut_0_attach11 : public Precondition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Precondition_bt_node_test_fsm_fsm_ut_0_attach11, Precondition);
		Precondition_bt_node_test_fsm_fsm_ut_0_attach11()
		{
			this->SetPhase(Precondition::E_UPDATE);
			this->SetIsAnd(true);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("EnergyCount") == 881465299u);
			int& opr1 = (int&)pAgent->GetVariable<int >(881465299u);
			int opr2 = 1;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("EnergyCount") == 881465299u);
			pAgent->SetVariable("EnergyCount", (int)(opr1 + opr2), 881465299u);
			return result;
		}
	};

	class Transition_bt_node_test_fsm_fsm_ut_0_attach7 : public Transition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Transition_bt_node_test_fsm_fsm_ut_0_attach7, Transition);
		Transition_bt_node_test_fsm_fsm_ut_0_attach7()
		{
			this->SetTargetStateId(3);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("FoodCount") == 3299892854u);
			int& opl = (int&)pAgent->GetVariable<int >(3299892854u);
			int opr2 = 0;
			bool op = Details::LessEqual(opl, opr2);
			if (!op)
				result = BT_FAILURE;
			return result;
		}
	};

	class Transition_bt_node_test_fsm_fsm_ut_0_attach12 : public Transition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Transition_bt_node_test_fsm_fsm_ut_0_attach12, Transition);
		Transition_bt_node_test_fsm_fsm_ut_0_attach12()
		{
			this->SetTargetStateId(4);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("EnergyCount") == 881465299u);
			int& opl = (int&)pAgent->GetVariable<int >(881465299u);
			int opr2 = 5;
			bool op = Details::GreaterEqual(opl, opr2);
			if (!op)
				result = BT_FAILURE;
			return result;
		}
	};

	class State_bt_node_test_fsm_fsm_ut_0_node4 : public State
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(State_bt_node_test_fsm_fsm_ut_0_node4, State);
		State_bt_node_test_fsm_fsm_ut_0_node4()
		{
			this->m_bIsEndState = false;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((FSMAgentTest*)pAgent)->_Execute_Method_<METHOD_TYPE_FSMAgentTest_pause_update, void >();
			return BT_RUNNING;
		}
	};

	class Precondition_bt_node_test_fsm_fsm_ut_0_attach9 : public Precondition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Precondition_bt_node_test_fsm_fsm_ut_0_attach9, Precondition);
		Precondition_bt_node_test_fsm_fsm_ut_0_attach9()
		{
			this->SetPhase(Precondition::E_ENTER);
			this->SetIsAnd(true);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("FoodCount") == 3299892854u);
			int& opr1 = (int&)pAgent->GetVariable<int >(3299892854u);
			int opr2 = 1;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("FoodCount") == 3299892854u);
			pAgent->SetVariable("FoodCount", (int)(opr1 - opr2), 3299892854u);
			return result;
		}
	};

	class Transition_bt_node_test_fsm_fsm_ut_0_attach8 : public Transition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Transition_bt_node_test_fsm_fsm_ut_0_attach8, Transition);
		Transition_bt_node_test_fsm_fsm_ut_0_attach8()
		{
			this->SetTargetStateId(3);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("FoodCount") == 3299892854u);
			int& opl = (int&)pAgent->GetVariable<int >(3299892854u);
			int opr2 = 0;
			bool op = Details::LessEqual(opl, opr2);
			if (!op)
				result = BT_FAILURE;
			return result;
		}
	};

		bool bt_node_test_fsm_fsm_ut_0::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("node_test/fsm/fsm_ut_0");
			pBT->SetIsFSM(true);
#if !BEHAVIAC_RELEASE
			pBT->SetAgentType("FSMAgentTest");
#endif
			// attachments
			// children
			{
				FSM* fsm = BEHAVIAC_NEW FSM();
				fsm->SetClassNameString("FSM");
				fsm->SetId((uint16_t)-1);
				fsm->SetInitialId(3);
#if !BEHAVIAC_RELEASE
				fsm->SetAgentType("FSMAgentTest");
#endif
				{
					State_bt_node_test_fsm_fsm_ut_0_node3* node3 = BEHAVIAC_NEW State_bt_node_test_fsm_fsm_ut_0_node3;
					node3->SetClassNameString("State");
					node3->SetId(3);
#if !BEHAVIAC_RELEASE
					node3->SetAgentType("FSMAgentTest");
#endif
					// attachments
					{
						Precondition_bt_node_test_fsm_fsm_ut_0_attach10* attach10 = BEHAVIAC_NEW Precondition_bt_node_test_fsm_fsm_ut_0_attach10;
						attach10->SetClassNameString("Precondition");
						attach10->SetId(10);
#if !BEHAVIAC_RELEASE
						attach10->SetAgentType("FSMAgentTest");
#endif
						node3->Attach(attach10, true, false, false);
						node3->SetHasEvents(node3->HasEvents() | (Event::DynamicCast(attach10) != 0));
					}
					{
						Precondition_bt_node_test_fsm_fsm_ut_0_attach2* attach2 = BEHAVIAC_NEW Precondition_bt_node_test_fsm_fsm_ut_0_attach2;
						attach2->SetClassNameString("Precondition");
						attach2->SetId(2);
#if !BEHAVIAC_RELEASE
						attach2->SetAgentType("FSMAgentTest");
#endif
						node3->Attach(attach2, true, false, false);
						node3->SetHasEvents(node3->HasEvents() | (Event::DynamicCast(attach2) != 0));
					}
					{
						Transition_bt_node_test_fsm_fsm_ut_0_attach5* attach5 = BEHAVIAC_NEW Transition_bt_node_test_fsm_fsm_ut_0_attach5;
						attach5->SetClassNameString("Transition");
						attach5->SetId(5);
#if !BEHAVIAC_RELEASE
						attach5->SetAgentType("FSMAgentTest");
#endif
						node3->Attach(attach5, false, false, true);
						node3->SetHasEvents(node3->HasEvents() | (Event::DynamicCast(attach5) != 0));
					}
					fsm->AddChild(node3);
					fsm->SetHasEvents(fsm->HasEvents() | node3->HasEvents());
				}
				{
					State_bt_node_test_fsm_fsm_ut_0_node1* node1 = BEHAVIAC_NEW State_bt_node_test_fsm_fsm_ut_0_node1;
					node1->SetClassNameString("State");
					node1->SetId(1);
#if !BEHAVIAC_RELEASE
					node1->SetAgentType("FSMAgentTest");
#endif
					// attachments
					{
						Precondition_bt_node_test_fsm_fsm_ut_0_attach6* attach6 = BEHAVIAC_NEW Precondition_bt_node_test_fsm_fsm_ut_0_attach6;
						attach6->SetClassNameString("Precondition");
						attach6->SetId(6);
#if !BEHAVIAC_RELEASE
						attach6->SetAgentType("FSMAgentTest");
#endif
						node1->Attach(attach6, true, false, false);
						node1->SetHasEvents(node1->HasEvents() | (Event::DynamicCast(attach6) != 0));
					}
					{
						Precondition_bt_node_test_fsm_fsm_ut_0_attach11* attach11 = BEHAVIAC_NEW Precondition_bt_node_test_fsm_fsm_ut_0_attach11;
						attach11->SetClassNameString("Precondition");
						attach11->SetId(11);
#if !BEHAVIAC_RELEASE
						attach11->SetAgentType("FSMAgentTest");
#endif
						node1->Attach(attach11, true, false, false);
						node1->SetHasEvents(node1->HasEvents() | (Event::DynamicCast(attach11) != 0));
					}
					{
						Transition_bt_node_test_fsm_fsm_ut_0_attach7* attach7 = BEHAVIAC_NEW Transition_bt_node_test_fsm_fsm_ut_0_attach7;
						attach7->SetClassNameString("Transition");
						attach7->SetId(7);
#if !BEHAVIAC_RELEASE
						attach7->SetAgentType("FSMAgentTest");
#endif
						node1->Attach(attach7, false, false, true);
						node1->SetHasEvents(node1->HasEvents() | (Event::DynamicCast(attach7) != 0));
					}
					{
						Transition_bt_node_test_fsm_fsm_ut_0_attach12* attach12 = BEHAVIAC_NEW Transition_bt_node_test_fsm_fsm_ut_0_attach12;
						attach12->SetClassNameString("Transition");
						attach12->SetId(12);
#if !BEHAVIAC_RELEASE
						attach12->SetAgentType("FSMAgentTest");
#endif
						node1->Attach(attach12, false, false, true);
						node1->SetHasEvents(node1->HasEvents() | (Event::DynamicCast(attach12) != 0));
					}
					fsm->AddChild(node1);
					fsm->SetHasEvents(fsm->HasEvents() | node1->HasEvents());
				}
				{
					State_bt_node_test_fsm_fsm_ut_0_node4* node4 = BEHAVIAC_NEW State_bt_node_test_fsm_fsm_ut_0_node4;
					node4->SetClassNameString("State");
					node4->SetId(4);
#if !BEHAVIAC_RELEASE
					node4->SetAgentType("FSMAgentTest");
#endif
					// attachments
					{
						Precondition_bt_node_test_fsm_fsm_ut_0_attach9* attach9 = BEHAVIAC_NEW Precondition_bt_node_test_fsm_fsm_ut_0_attach9;
						attach9->SetClassNameString("Precondition");
						attach9->SetId(9);
#if !BEHAVIAC_RELEASE
						attach9->SetAgentType("FSMAgentTest");
#endif
						node4->Attach(attach9, true, false, false);
						node4->SetHasEvents(node4->HasEvents() | (Event::DynamicCast(attach9) != 0));
					}
					{
						Transition_bt_node_test_fsm_fsm_ut_0_attach8* attach8 = BEHAVIAC_NEW Transition_bt_node_test_fsm_fsm_ut_0_attach8;
						attach8->SetClassNameString("Transition");
						attach8->SetId(8);
#if !BEHAVIAC_RELEASE
						attach8->SetAgentType("FSMAgentTest");
#endif
						node4->Attach(attach8, false, false, true);
						node4->SetHasEvents(node4->HasEvents() | (Event::DynamicCast(attach8) != 0));
					}
					fsm->AddChild(node4);
					fsm->SetHasEvents(fsm->HasEvents() | node4->HasEvents());
				}
				pBT->AddChild(fsm);
			}
			return true;
		}

	// Source file: node_test/fsm/fsm_ut_1

	class State_bt_node_test_fsm_fsm_ut_1_node3 : public State
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(State_bt_node_test_fsm_fsm_ut_1_node3, State);
		State_bt_node_test_fsm_fsm_ut_1_node3()
		{
			this->m_bIsEndState = false;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((FSMAgentTest*)pAgent)->_Execute_Method_<METHOD_TYPE_FSMAgentTest_inactive_update, void >();
			return BT_RUNNING;
		}
	};

	class Precondition_bt_node_test_fsm_fsm_ut_1_attach10 : public Precondition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Precondition_bt_node_test_fsm_fsm_ut_1_attach10, Precondition);
		Precondition_bt_node_test_fsm_fsm_ut_1_attach10()
		{
			this->SetPhase(Precondition::E_ENTER);
			this->SetIsAnd(true);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			int opr2 = 0;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("InactiveCount") == 1246269412u);
			pAgent->SetVariable("InactiveCount", opr2, 1246269412u);
			return result;
		}
	};

	class Transition_bt_node_test_fsm_fsm_ut_1_attach5 : public Transition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Transition_bt_node_test_fsm_fsm_ut_1_attach5, Transition);
		Transition_bt_node_test_fsm_fsm_ut_1_attach5()
		{
			this->SetTargetStateId(1);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			FSMAgentTest::EMessage opl = ((FSMAgentTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_FSMAgentTest_Message, FSMAgentTest::EMessage >();
			FSMAgentTest::EMessage opr2 = FSMAgentTest::Begin;
			bool op = Details::Equal(opl, opr2);
			if (!op)
				result = BT_FAILURE;
			return result;
		}
	};

	class Transition_bt_node_test_fsm_fsm_ut_1_attach6 : public Transition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Transition_bt_node_test_fsm_fsm_ut_1_attach6, Transition);
		Transition_bt_node_test_fsm_fsm_ut_1_attach6()
		{
			this->SetTargetStateId(18);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			FSMAgentTest::EMessage opl = ((FSMAgentTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_FSMAgentTest_Message, FSMAgentTest::EMessage >();
			FSMAgentTest::EMessage opr2 = FSMAgentTest::Exit;
			bool op = Details::Equal(opl, opr2);
			if (!op)
				result = BT_FAILURE;
			return result;
		}
	};

	class Effector_bt_node_test_fsm_fsm_ut_1_attach14 : public Effector
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Effector_bt_node_test_fsm_fsm_ut_1_attach14, Effector);
		Effector_bt_node_test_fsm_fsm_ut_1_attach14()
		{
			this->SetPhase(Effector::E_SUCCESS);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("InactiveCount") == 1246269412u);
			int& opr1 = (int&)pAgent->GetVariable<int >(1246269412u);
			int opr2 = 1;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("InactiveCount") == 1246269412u);
			pAgent->SetVariable("InactiveCount", (int)(opr1 + opr2), 1246269412u);
			return result;
		}
	};

	class State_bt_node_test_fsm_fsm_ut_1_node1 : public State
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(State_bt_node_test_fsm_fsm_ut_1_node1, State);
		State_bt_node_test_fsm_fsm_ut_1_node1()
		{
			this->m_bIsEndState = false;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((FSMAgentTest*)pAgent)->_Execute_Method_<METHOD_TYPE_FSMAgentTest_active_update, void >();
			return BT_RUNNING;
		}
	};

	class Precondition_bt_node_test_fsm_fsm_ut_1_attach11 : public Precondition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Precondition_bt_node_test_fsm_fsm_ut_1_attach11, Precondition);
		Precondition_bt_node_test_fsm_fsm_ut_1_attach11()
		{
			this->SetPhase(Precondition::E_ENTER);
			this->SetIsAnd(true);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			unsigned int opr2 = 0;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("ActiveCount") == 177115358u);
			pAgent->SetVariable("ActiveCount", opr2, 177115358u);
			return result;
		}
	};

	class Transition_bt_node_test_fsm_fsm_ut_1_attach7 : public Transition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Transition_bt_node_test_fsm_fsm_ut_1_attach7, Transition);
		Transition_bt_node_test_fsm_fsm_ut_1_attach7()
		{
			this->SetTargetStateId(4);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			FSMAgentTest::EMessage opl = ((FSMAgentTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_FSMAgentTest_Message, FSMAgentTest::EMessage >();
			FSMAgentTest::EMessage opr2 = FSMAgentTest::Pause;
			bool op = Details::Equal(opl, opr2);
			if (!op)
				result = BT_FAILURE;
			return result;
		}
	};

	class Effector_bt_node_test_fsm_fsm_ut_1_attach17 : public Effector
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Effector_bt_node_test_fsm_fsm_ut_1_attach17, Effector);
		Effector_bt_node_test_fsm_fsm_ut_1_attach17()
		{
			this->SetPhase(Effector::E_SUCCESS);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("ActiveCount") == 177115358u);
			unsigned int& opr1 = (unsigned int&)pAgent->GetVariable<unsigned int >(177115358u);
			unsigned int opr2 = 1;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("ActiveCount") == 177115358u);
			pAgent->SetVariable("ActiveCount", (unsigned int)(opr1 + opr2), 177115358u);
			return result;
		}
	};

	class State_bt_node_test_fsm_fsm_ut_1_node2 : public State
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(State_bt_node_test_fsm_fsm_ut_1_node2, State);
		State_bt_node_test_fsm_fsm_ut_1_node2()
		{
			this->m_bIsEndState = true;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			return BT_RUNNING;
		}
	};

	class Precondition_bt_node_test_fsm_fsm_ut_1_attach12 : public Precondition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Precondition_bt_node_test_fsm_fsm_ut_1_attach12, Precondition);
		Precondition_bt_node_test_fsm_fsm_ut_1_attach12()
		{
			this->SetPhase(Precondition::E_ENTER);
			this->SetIsAnd(true);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			long opr2 = 0;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("ExitCount") == 1184325508u);
			pAgent->SetVariable("ExitCount", opr2, 1184325508u);
			return result;
		}
	};

	class Effector_bt_node_test_fsm_fsm_ut_1_attach15 : public Effector
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Effector_bt_node_test_fsm_fsm_ut_1_attach15, Effector);
		Effector_bt_node_test_fsm_fsm_ut_1_attach15()
		{
			this->SetPhase(Effector::E_SUCCESS);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("ExitCount") == 1184325508u);
			long& opr1 = (long&)pAgent->GetVariable<long >(1184325508u);
			long opr2 = 1;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("ExitCount") == 1184325508u);
			pAgent->SetVariable("ExitCount", (long)(opr1 + opr2), 1184325508u);
			return result;
		}
	};

	class State_bt_node_test_fsm_fsm_ut_1_node4 : public State
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(State_bt_node_test_fsm_fsm_ut_1_node4, State);
		State_bt_node_test_fsm_fsm_ut_1_node4()
		{
			this->m_bIsEndState = false;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((FSMAgentTest*)pAgent)->_Execute_Method_<METHOD_TYPE_FSMAgentTest_pause_update, void >();
			return BT_RUNNING;
		}
	};

	class Precondition_bt_node_test_fsm_fsm_ut_1_attach13 : public Precondition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Precondition_bt_node_test_fsm_fsm_ut_1_attach13, Precondition);
		Precondition_bt_node_test_fsm_fsm_ut_1_attach13()
		{
			this->SetPhase(Precondition::E_ENTER);
			this->SetIsAnd(true);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			short opr2 = 0;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("PauseCount") == 3020354788u);
			pAgent->SetVariable("PauseCount", opr2, 3020354788u);
			return result;
		}
	};

	class Transition_bt_node_test_fsm_fsm_ut_1_attach8 : public Transition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Transition_bt_node_test_fsm_fsm_ut_1_attach8, Transition);
		Transition_bt_node_test_fsm_fsm_ut_1_attach8()
		{
			this->SetTargetStateId(3);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			FSMAgentTest::EMessage opl = ((FSMAgentTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_FSMAgentTest_Message, FSMAgentTest::EMessage >();
			FSMAgentTest::EMessage opr2 = FSMAgentTest::End;
			bool op = Details::Equal(opl, opr2);
			if (!op)
				result = BT_FAILURE;
			return result;
		}
	};

	class Transition_bt_node_test_fsm_fsm_ut_1_attach9 : public Transition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Transition_bt_node_test_fsm_fsm_ut_1_attach9, Transition);
		Transition_bt_node_test_fsm_fsm_ut_1_attach9()
		{
			this->SetTargetStateId(1);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			FSMAgentTest::EMessage opl = ((FSMAgentTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_FSMAgentTest_Message, FSMAgentTest::EMessage >();
			FSMAgentTest::EMessage opr2 = FSMAgentTest::Resume;
			bool op = Details::Equal(opl, opr2);
			if (!op)
				result = BT_FAILURE;
			return result;
		}
	};

	class Effector_bt_node_test_fsm_fsm_ut_1_attach16 : public Effector
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Effector_bt_node_test_fsm_fsm_ut_1_attach16, Effector);
		Effector_bt_node_test_fsm_fsm_ut_1_attach16()
		{
			this->SetPhase(Effector::E_SUCCESS);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("PauseCount") == 3020354788u);
			short& opr1 = (short&)pAgent->GetVariable<short >(3020354788u);
			short opr2 = 1;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("PauseCount") == 3020354788u);
			pAgent->SetVariable("PauseCount", (short)(opr1 + opr2), 3020354788u);
			return result;
		}
	};

	class WaitFramesState_bt_node_test_fsm_fsm_ut_1_node18 : public WaitFramesState
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(WaitFramesState_bt_node_test_fsm_fsm_ut_1_node18, WaitFramesState);
		WaitFramesState_bt_node_test_fsm_fsm_ut_1_node18()
		{
		}
	protected:
		virtual int GetFrames(Agent* pAgent) const
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			return 3;
		}
	};

	class WaitTransition_bt_node_test_fsm_fsm_ut_1_attach20 : public WaitTransition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(WaitTransition_bt_node_test_fsm_fsm_ut_1_attach20, WaitTransition);
		WaitTransition_bt_node_test_fsm_fsm_ut_1_attach20()
		{
			this->SetTargetStateId(2);
		}
	protected:
	};

		bool bt_node_test_fsm_fsm_ut_1::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("node_test/fsm/fsm_ut_1");
			pBT->SetIsFSM(true);
#if !BEHAVIAC_RELEASE
			pBT->SetAgentType("FSMAgentTest");
#endif
			// attachments
			// children
			{
				FSM* fsm = BEHAVIAC_NEW FSM();
				fsm->SetClassNameString("FSM");
				fsm->SetId((uint16_t)-1);
				fsm->SetInitialId(3);
#if !BEHAVIAC_RELEASE
				fsm->SetAgentType("FSMAgentTest");
#endif
				{
					State_bt_node_test_fsm_fsm_ut_1_node3* node3 = BEHAVIAC_NEW State_bt_node_test_fsm_fsm_ut_1_node3;
					node3->SetClassNameString("State");
					node3->SetId(3);
#if !BEHAVIAC_RELEASE
					node3->SetAgentType("FSMAgentTest");
#endif
					// attachments
					{
						Precondition_bt_node_test_fsm_fsm_ut_1_attach10* attach10 = BEHAVIAC_NEW Precondition_bt_node_test_fsm_fsm_ut_1_attach10;
						attach10->SetClassNameString("Precondition");
						attach10->SetId(10);
#if !BEHAVIAC_RELEASE
						attach10->SetAgentType("FSMAgentTest");
#endif
						node3->Attach(attach10, true, false, false);
						node3->SetHasEvents(node3->HasEvents() | (Event::DynamicCast(attach10) != 0));
					}
					{
						Transition_bt_node_test_fsm_fsm_ut_1_attach5* attach5 = BEHAVIAC_NEW Transition_bt_node_test_fsm_fsm_ut_1_attach5;
						attach5->SetClassNameString("Transition");
						attach5->SetId(5);
#if !BEHAVIAC_RELEASE
						attach5->SetAgentType("FSMAgentTest");
#endif
						node3->Attach(attach5, false, false, true);
						node3->SetHasEvents(node3->HasEvents() | (Event::DynamicCast(attach5) != 0));
					}
					{
						Transition_bt_node_test_fsm_fsm_ut_1_attach6* attach6 = BEHAVIAC_NEW Transition_bt_node_test_fsm_fsm_ut_1_attach6;
						attach6->SetClassNameString("Transition");
						attach6->SetId(6);
#if !BEHAVIAC_RELEASE
						attach6->SetAgentType("FSMAgentTest");
#endif
						node3->Attach(attach6, false, false, true);
						node3->SetHasEvents(node3->HasEvents() | (Event::DynamicCast(attach6) != 0));
					}
					{
						Effector_bt_node_test_fsm_fsm_ut_1_attach14* attach14 = BEHAVIAC_NEW Effector_bt_node_test_fsm_fsm_ut_1_attach14;
						attach14->SetClassNameString("Effector");
						attach14->SetId(14);
#if !BEHAVIAC_RELEASE
						attach14->SetAgentType("FSMAgentTest");
#endif
						node3->Attach(attach14, false, true, false);
						node3->SetHasEvents(node3->HasEvents() | (Event::DynamicCast(attach14) != 0));
					}
					fsm->AddChild(node3);
					fsm->SetHasEvents(fsm->HasEvents() | node3->HasEvents());
				}
				{
					State_bt_node_test_fsm_fsm_ut_1_node1* node1 = BEHAVIAC_NEW State_bt_node_test_fsm_fsm_ut_1_node1;
					node1->SetClassNameString("State");
					node1->SetId(1);
#if !BEHAVIAC_RELEASE
					node1->SetAgentType("FSMAgentTest");
#endif
					// attachments
					{
						Precondition_bt_node_test_fsm_fsm_ut_1_attach11* attach11 = BEHAVIAC_NEW Precondition_bt_node_test_fsm_fsm_ut_1_attach11;
						attach11->SetClassNameString("Precondition");
						attach11->SetId(11);
#if !BEHAVIAC_RELEASE
						attach11->SetAgentType("FSMAgentTest");
#endif
						node1->Attach(attach11, true, false, false);
						node1->SetHasEvents(node1->HasEvents() | (Event::DynamicCast(attach11) != 0));
					}
					{
						Transition_bt_node_test_fsm_fsm_ut_1_attach7* attach7 = BEHAVIAC_NEW Transition_bt_node_test_fsm_fsm_ut_1_attach7;
						attach7->SetClassNameString("Transition");
						attach7->SetId(7);
#if !BEHAVIAC_RELEASE
						attach7->SetAgentType("FSMAgentTest");
#endif
						node1->Attach(attach7, false, false, true);
						node1->SetHasEvents(node1->HasEvents() | (Event::DynamicCast(attach7) != 0));
					}
					{
						Effector_bt_node_test_fsm_fsm_ut_1_attach17* attach17 = BEHAVIAC_NEW Effector_bt_node_test_fsm_fsm_ut_1_attach17;
						attach17->SetClassNameString("Effector");
						attach17->SetId(17);
#if !BEHAVIAC_RELEASE
						attach17->SetAgentType("FSMAgentTest");
#endif
						node1->Attach(attach17, false, true, false);
						node1->SetHasEvents(node1->HasEvents() | (Event::DynamicCast(attach17) != 0));
					}
					fsm->AddChild(node1);
					fsm->SetHasEvents(fsm->HasEvents() | node1->HasEvents());
				}
				{
					State_bt_node_test_fsm_fsm_ut_1_node2* node2 = BEHAVIAC_NEW State_bt_node_test_fsm_fsm_ut_1_node2;
					node2->SetClassNameString("State");
					node2->SetId(2);
#if !BEHAVIAC_RELEASE
					node2->SetAgentType("FSMAgentTest");
#endif
					// attachments
					{
						Precondition_bt_node_test_fsm_fsm_ut_1_attach12* attach12 = BEHAVIAC_NEW Precondition_bt_node_test_fsm_fsm_ut_1_attach12;
						attach12->SetClassNameString("Precondition");
						attach12->SetId(12);
#if !BEHAVIAC_RELEASE
						attach12->SetAgentType("FSMAgentTest");
#endif
						node2->Attach(attach12, true, false, false);
						node2->SetHasEvents(node2->HasEvents() | (Event::DynamicCast(attach12) != 0));
					}
					{
						Effector_bt_node_test_fsm_fsm_ut_1_attach15* attach15 = BEHAVIAC_NEW Effector_bt_node_test_fsm_fsm_ut_1_attach15;
						attach15->SetClassNameString("Effector");
						attach15->SetId(15);
#if !BEHAVIAC_RELEASE
						attach15->SetAgentType("FSMAgentTest");
#endif
						node2->Attach(attach15, false, true, false);
						node2->SetHasEvents(node2->HasEvents() | (Event::DynamicCast(attach15) != 0));
					}
					fsm->AddChild(node2);
					fsm->SetHasEvents(fsm->HasEvents() | node2->HasEvents());
				}
				{
					State_bt_node_test_fsm_fsm_ut_1_node4* node4 = BEHAVIAC_NEW State_bt_node_test_fsm_fsm_ut_1_node4;
					node4->SetClassNameString("State");
					node4->SetId(4);
#if !BEHAVIAC_RELEASE
					node4->SetAgentType("FSMAgentTest");
#endif
					// attachments
					{
						Precondition_bt_node_test_fsm_fsm_ut_1_attach13* attach13 = BEHAVIAC_NEW Precondition_bt_node_test_fsm_fsm_ut_1_attach13;
						attach13->SetClassNameString("Precondition");
						attach13->SetId(13);
#if !BEHAVIAC_RELEASE
						attach13->SetAgentType("FSMAgentTest");
#endif
						node4->Attach(attach13, true, false, false);
						node4->SetHasEvents(node4->HasEvents() | (Event::DynamicCast(attach13) != 0));
					}
					{
						Transition_bt_node_test_fsm_fsm_ut_1_attach8* attach8 = BEHAVIAC_NEW Transition_bt_node_test_fsm_fsm_ut_1_attach8;
						attach8->SetClassNameString("Transition");
						attach8->SetId(8);
#if !BEHAVIAC_RELEASE
						attach8->SetAgentType("FSMAgentTest");
#endif
						node4->Attach(attach8, false, false, true);
						node4->SetHasEvents(node4->HasEvents() | (Event::DynamicCast(attach8) != 0));
					}
					{
						Transition_bt_node_test_fsm_fsm_ut_1_attach9* attach9 = BEHAVIAC_NEW Transition_bt_node_test_fsm_fsm_ut_1_attach9;
						attach9->SetClassNameString("Transition");
						attach9->SetId(9);
#if !BEHAVIAC_RELEASE
						attach9->SetAgentType("FSMAgentTest");
#endif
						node4->Attach(attach9, false, false, true);
						node4->SetHasEvents(node4->HasEvents() | (Event::DynamicCast(attach9) != 0));
					}
					{
						Effector_bt_node_test_fsm_fsm_ut_1_attach16* attach16 = BEHAVIAC_NEW Effector_bt_node_test_fsm_fsm_ut_1_attach16;
						attach16->SetClassNameString("Effector");
						attach16->SetId(16);
#if !BEHAVIAC_RELEASE
						attach16->SetAgentType("FSMAgentTest");
#endif
						node4->Attach(attach16, false, true, false);
						node4->SetHasEvents(node4->HasEvents() | (Event::DynamicCast(attach16) != 0));
					}
					fsm->AddChild(node4);
					fsm->SetHasEvents(fsm->HasEvents() | node4->HasEvents());
				}
				{
					WaitFramesState_bt_node_test_fsm_fsm_ut_1_node18* node18 = BEHAVIAC_NEW WaitFramesState_bt_node_test_fsm_fsm_ut_1_node18;
					node18->SetClassNameString("WaitFramesState");
					node18->SetId(18);
#if !BEHAVIAC_RELEASE
					node18->SetAgentType("FSMAgentTest");
#endif
					// attachments
					{
						WaitTransition_bt_node_test_fsm_fsm_ut_1_attach20* attach20 = BEHAVIAC_NEW WaitTransition_bt_node_test_fsm_fsm_ut_1_attach20;
						attach20->SetClassNameString("WaitTransition");
						attach20->SetId(20);
#if !BEHAVIAC_RELEASE
						attach20->SetAgentType("FSMAgentTest");
#endif
						node18->Attach(attach20, false, false, true);
						node18->SetHasEvents(node18->HasEvents() | (Event::DynamicCast(attach20) != 0));
					}
					fsm->AddChild(node18);
					fsm->SetHasEvents(fsm->HasEvents() | node18->HasEvents());
				}
				pBT->AddChild(fsm);
			}
			return true;
		}

	// Source file: node_test/htn/house/build_house

	class Task_bt_node_test_htn_house_build_house_node7 : public Task
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Task_bt_node_test_htn_house_build_house_node7, Task);
		Task_bt_node_test_htn_house_build_house_node7()
		{
			this->m_task = (CTaskMethod*)Action::LoadMethod("Self.HTNAgentHouse::build_house()");
			BEHAVIAC_ASSERT(this->m_task != NULL);
			this->m_bHTN = true;
		}
	protected:
	};

	class Precondition_bt_node_test_htn_house_build_house_attach0 : public Precondition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Precondition_bt_node_test_htn_house_build_house_attach0, Precondition);
		Precondition_bt_node_test_htn_house_build_house_attach0()
		{
			this->SetPhase(Precondition::E_ENTER);
			this->SetIsAnd(true);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("Land") == 1676779868u);
			bool& opl = (bool&)pAgent->GetVariable<bool >(1676779868u);
			bool opr2 = true;
			bool op = Details::Equal(opl, opr2);
			if (!op)
				result = BT_FAILURE;
			return result;
		}
	};

	class Effector_bt_node_test_htn_house_build_house_attach1 : public Effector
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Effector_bt_node_test_htn_house_build_house_attach1, Effector);
		Effector_bt_node_test_htn_house_build_house_attach1()
		{
			this->SetPhase(Effector::E_SUCCESS);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			bool opr2 = true;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("House") == 3571637003u);
			pAgent->SetVariable("House", opr2, 3571637003u);
			return result;
		}
	};

	class Parallel_bt_node_test_htn_house_build_house_node4 : public Parallel
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Parallel_bt_node_test_htn_house_build_house_node4, Parallel);
		Parallel_bt_node_test_htn_house_build_house_node4()
		{
			m_failPolicy = FAIL_ON_ONE;
			m_succeedPolicy = SUCCEED_ON_ALL;
			m_exitPolicy = EXIT_ABORT_RUNNINGSIBLINGS;
			m_childFinishPolicy = CHILDFINISH_LOOP;
		}
	protected:
	};

	class Action_bt_node_test_htn_house_build_house_node5 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_htn_house_build_house_node5, Action);
		Action_bt_node_test_htn_house_build_house_node5()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((HTNAgentHouseBase*)pAgent)->_Execute_Method_<METHOD_TYPE_HTNAgentHouseBase_ObtainPermit, void >();
			return BT_SUCCESS;
		}
	};

	class Precondition_bt_node_test_htn_house_build_house_attach3 : public Precondition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Precondition_bt_node_test_htn_house_build_house_attach3, Precondition);
		Precondition_bt_node_test_htn_house_build_house_attach3()
		{
			this->SetPhase(Precondition::E_ENTER);
			this->SetIsAnd(true);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("Land") == 1676779868u);
			bool& opl = (bool&)pAgent->GetVariable<bool >(1676779868u);
			bool opr2 = true;
			bool op = Details::Equal(opl, opr2);
			if (!op)
				result = BT_FAILURE;
			return result;
		}
	};

	class Effector_bt_node_test_htn_house_build_house_attach6 : public Effector
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Effector_bt_node_test_htn_house_build_house_attach6, Effector);
		Effector_bt_node_test_htn_house_build_house_attach6()
		{
			this->SetPhase(Effector::E_SUCCESS);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			bool opr2 = true;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("Permit") == 3054969542u);
			pAgent->SetVariable("Permit", opr2, 3054969542u);
			return result;
		}
	};

	class Action_bt_node_test_htn_house_build_house_node18 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_htn_house_build_house_node18, Action);
		Action_bt_node_test_htn_house_build_house_node18()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((HTNAgentHouse*)pAgent)->_Execute_Method_<METHOD_TYPE_HTNAgentHouse_HireBuilder, void >();
			return BT_SUCCESS;
		}
	};

	class Effector_bt_node_test_htn_house_build_house_attach8 : public Effector
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Effector_bt_node_test_htn_house_build_house_attach8, Effector);
		Effector_bt_node_test_htn_house_build_house_attach8()
		{
			this->SetPhase(Effector::E_SUCCESS);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			bool opr2 = true;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("Contract") == 3012131995u);
			pAgent->SetVariable("Contract", opr2, 3012131995u);
			return result;
		}
	};

	class ReferencedBehavior_bt_node_test_htn_house_build_house_node20 : public ReferencedBehavior
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(ReferencedBehavior_bt_node_test_htn_house_build_house_node20, ReferencedBehavior);
		ReferencedBehavior_bt_node_test_htn_house_build_house_node20()
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
			m_taskMethod = (CTaskMethod*)Action::LoadMethod("Self.HTNAgentHouse::construct()");
			BEHAVIAC_ASSERT(m_taskMethod);
		}
	protected:
		virtual const char* GetReferencedTree(const Agent* pAgent) const
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			return (char*)("node_test/htn/house/construct");
		}
	};

	class Action_bt_node_test_htn_house_build_house_node19 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_htn_house_build_house_node19, Action);
		Action_bt_node_test_htn_house_build_house_node19()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((HTNAgentHouse*)pAgent)->_Execute_Method_<METHOD_TYPE_HTNAgentHouse_PayBuilder, void >();
			return BT_SUCCESS;
		}
	};

	class Precondition_bt_node_test_htn_house_build_house_attach27 : public Precondition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Precondition_bt_node_test_htn_house_build_house_attach27, Precondition);
		Precondition_bt_node_test_htn_house_build_house_attach27()
		{
			this->SetPhase(Precondition::E_ENTER);
			this->SetIsAnd(true);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("Money") == 4260042937u);
			int& opl = (int&)pAgent->GetVariable<int >(4260042937u);
			int opr2 = 50;
			bool op = Details::GreaterEqual(opl, opr2);
			if (!op)
				result = BT_FAILURE;
			return result;
		}
	};

	class Precondition_bt_node_test_htn_house_build_house_attach9 : public Precondition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Precondition_bt_node_test_htn_house_build_house_attach9, Precondition);
		Precondition_bt_node_test_htn_house_build_house_attach9()
		{
			this->SetPhase(Precondition::E_ENTER);
			this->SetIsAnd(true);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("HouseBuilt") == 1186824470u);
			bool& opl = (bool&)pAgent->GetVariable<bool >(1186824470u);
			bool opr2 = true;
			bool op = Details::Equal(opl, opr2);
			if (!op)
				result = BT_FAILURE;
			return result;
		}
	};

	class Effector_bt_node_test_htn_house_build_house_attach10 : public Effector
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Effector_bt_node_test_htn_house_build_house_attach10, Effector);
		Effector_bt_node_test_htn_house_build_house_attach10()
		{
			this->SetPhase(Effector::E_SUCCESS);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("Money") == 4260042937u);
			int& opr1 = (int&)pAgent->GetVariable<int >(4260042937u);
			int opr2 = 50;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("Money") == 4260042937u);
			pAgent->SetVariable("Money", (int)(opr1 - opr2), 4260042937u);
			return result;
		}
	};

	class Effector_bt_node_test_htn_house_build_house_attach11 : public Effector
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Effector_bt_node_test_htn_house_build_house_attach11, Effector);
		Effector_bt_node_test_htn_house_build_house_attach11()
		{
			this->SetPhase(Effector::E_SUCCESS);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			bool opr2 = true;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("House") == 3571637003u);
			pAgent->SetVariable("House", opr2, 3571637003u);
			return result;
		}
	};

	class Effector_bt_node_test_htn_house_build_house_attach12 : public Effector
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Effector_bt_node_test_htn_house_build_house_attach12, Effector);
		Effector_bt_node_test_htn_house_build_house_attach12()
		{
			this->SetPhase(Effector::E_SUCCESS);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			bool opr2 = false;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("Contract") == 3012131995u);
			pAgent->SetVariable("Contract", opr2, 3012131995u);
			return result;
		}
	};

	class Parallel_bt_node_test_htn_house_build_house_node23 : public Parallel
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Parallel_bt_node_test_htn_house_build_house_node23, Parallel);
		Parallel_bt_node_test_htn_house_build_house_node23()
		{
			m_failPolicy = FAIL_ON_ONE;
			m_succeedPolicy = SUCCEED_ON_ALL;
			m_exitPolicy = EXIT_ABORT_RUNNINGSIBLINGS;
			m_childFinishPolicy = CHILDFINISH_LOOP;
		}
	protected:
	};

	class Action_bt_node_test_htn_house_build_house_node28 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_htn_house_build_house_node28, Action);
		Action_bt_node_test_htn_house_build_house_node28()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((HTNAgentHouseBase*)pAgent)->_Execute_Method_<METHOD_TYPE_HTNAgentHouseBase_ObtainPermit, void >();
			return BT_SUCCESS;
		}
	};

	class Precondition_bt_node_test_htn_house_build_house_attach15 : public Precondition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Precondition_bt_node_test_htn_house_build_house_attach15, Precondition);
		Precondition_bt_node_test_htn_house_build_house_attach15()
		{
			this->SetPhase(Precondition::E_ENTER);
			this->SetIsAnd(true);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("Land") == 1676779868u);
			bool& opl = (bool&)pAgent->GetVariable<bool >(1676779868u);
			bool opr2 = true;
			bool op = Details::Equal(opl, opr2);
			if (!op)
				result = BT_FAILURE;
			return result;
		}
	};

	class Effector_bt_node_test_htn_house_build_house_attach16 : public Effector
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Effector_bt_node_test_htn_house_build_house_attach16, Effector);
		Effector_bt_node_test_htn_house_build_house_attach16()
		{
			this->SetPhase(Effector::E_SUCCESS);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			bool opr2 = true;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("Permit") == 3054969542u);
			pAgent->SetVariable("Permit", opr2, 3054969542u);
			return result;
		}
	};

	class Action_bt_node_test_htn_house_build_house_node24 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_htn_house_build_house_node24, Action);
		Action_bt_node_test_htn_house_build_house_node24()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((HTNAgentHouse*)pAgent)->_Execute_Method_<METHOD_TYPE_HTNAgentHouse_CutLogs, void >();
			return BT_SUCCESS;
		}
	};

	class Action_bt_node_test_htn_house_build_house_node25 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_htn_house_build_house_node25, Action);
		Action_bt_node_test_htn_house_build_house_node25()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((HTNAgentHouse*)pAgent)->_Execute_Method_<METHOD_TYPE_HTNAgentHouse_GetFriend, void >();
			return BT_SUCCESS;
		}
	};

	class ReferencedBehavior_bt_node_test_htn_house_build_house_node26 : public ReferencedBehavior
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(ReferencedBehavior_bt_node_test_htn_house_build_house_node26, ReferencedBehavior);
		ReferencedBehavior_bt_node_test_htn_house_build_house_node26()
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
			m_taskMethod = (CTaskMethod*)Action::LoadMethod("Self.HTNAgentHouse::construct()");
			BEHAVIAC_ASSERT(m_taskMethod);
		}
	protected:
		virtual const char* GetReferencedTree(const Agent* pAgent) const
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			return (char*)("node_test/htn/house/construct");
		}
	};

		bool bt_node_test_htn_house_build_house::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("node_test/htn/house/build_house");
			pBT->SetIsFSM(false);
#if !BEHAVIAC_RELEASE
			pBT->SetAgentType("HTNAgentHouse");
#endif
			// children
			{
				Task_bt_node_test_htn_house_build_house_node7* node7 = BEHAVIAC_NEW Task_bt_node_test_htn_house_build_house_node7;
				node7->SetClassNameString("Task");
				node7->SetId(7);
#if !BEHAVIAC_RELEASE
				node7->SetAgentType("HTNAgentHouse");
#endif
				// attachments
				{
					Precondition_bt_node_test_htn_house_build_house_attach0* attach0 = BEHAVIAC_NEW Precondition_bt_node_test_htn_house_build_house_attach0;
					attach0->SetClassNameString("Precondition");
					attach0->SetId(0);
#if !BEHAVIAC_RELEASE
					attach0->SetAgentType("HTNAgentHouse");
#endif
					node7->Attach(attach0, true, false, false);
					node7->SetHasEvents(node7->HasEvents() | (Event::DynamicCast(attach0) != 0));
				}
				{
					Effector_bt_node_test_htn_house_build_house_attach1* attach1 = BEHAVIAC_NEW Effector_bt_node_test_htn_house_build_house_attach1;
					attach1->SetClassNameString("Effector");
					attach1->SetId(1);
#if !BEHAVIAC_RELEASE
					attach1->SetAgentType("HTNAgentHouse");
#endif
					node7->Attach(attach1, false, true, false);
					node7->SetHasEvents(node7->HasEvents() | (Event::DynamicCast(attach1) != 0));
				}
				pBT->AddChild(node7);
				{
					Method* node2 = BEHAVIAC_NEW Method;
					node2->SetClassNameString("Method");
					node2->SetId(2);
#if !BEHAVIAC_RELEASE
					node2->SetAgentType("HTNAgentHouse");
#endif
					node7->AddChild(node2);
					{
						Sequence* node17 = BEHAVIAC_NEW Sequence;
						node17->SetClassNameString("Sequence");
						node17->SetId(17);
#if !BEHAVIAC_RELEASE
						node17->SetAgentType("HTNAgentHouse");
#endif
						node2->AddChild(node17);
						{
							Parallel_bt_node_test_htn_house_build_house_node4* node4 = BEHAVIAC_NEW Parallel_bt_node_test_htn_house_build_house_node4;
							node4->SetClassNameString("Parallel");
							node4->SetId(4);
#if !BEHAVIAC_RELEASE
							node4->SetAgentType("HTNAgentHouse");
#endif
							node17->AddChild(node4);
							{
								Action_bt_node_test_htn_house_build_house_node5* node5 = BEHAVIAC_NEW Action_bt_node_test_htn_house_build_house_node5;
								node5->SetClassNameString("Action");
								node5->SetId(5);
#if !BEHAVIAC_RELEASE
								node5->SetAgentType("HTNAgentHouse");
#endif
								// attachments
								{
									Precondition_bt_node_test_htn_house_build_house_attach3* attach3 = BEHAVIAC_NEW Precondition_bt_node_test_htn_house_build_house_attach3;
									attach3->SetClassNameString("Precondition");
									attach3->SetId(3);
#if !BEHAVIAC_RELEASE
									attach3->SetAgentType("HTNAgentHouse");
#endif
									node5->Attach(attach3, true, false, false);
									node5->SetHasEvents(node5->HasEvents() | (Event::DynamicCast(attach3) != 0));
								}
								{
									Effector_bt_node_test_htn_house_build_house_attach6* attach6 = BEHAVIAC_NEW Effector_bt_node_test_htn_house_build_house_attach6;
									attach6->SetClassNameString("Effector");
									attach6->SetId(6);
#if !BEHAVIAC_RELEASE
									attach6->SetAgentType("HTNAgentHouse");
#endif
									node5->Attach(attach6, false, true, false);
									node5->SetHasEvents(node5->HasEvents() | (Event::DynamicCast(attach6) != 0));
								}
								node4->AddChild(node5);
								node4->SetHasEvents(node4->HasEvents() | node5->HasEvents());
							}
							{
								Action_bt_node_test_htn_house_build_house_node18* node18 = BEHAVIAC_NEW Action_bt_node_test_htn_house_build_house_node18;
								node18->SetClassNameString("Action");
								node18->SetId(18);
#if !BEHAVIAC_RELEASE
								node18->SetAgentType("HTNAgentHouse");
#endif
								// attachments
								{
									Effector_bt_node_test_htn_house_build_house_attach8* attach8 = BEHAVIAC_NEW Effector_bt_node_test_htn_house_build_house_attach8;
									attach8->SetClassNameString("Effector");
									attach8->SetId(8);
#if !BEHAVIAC_RELEASE
									attach8->SetAgentType("HTNAgentHouse");
#endif
									node18->Attach(attach8, false, true, false);
									node18->SetHasEvents(node18->HasEvents() | (Event::DynamicCast(attach8) != 0));
								}
								node4->AddChild(node18);
								node4->SetHasEvents(node4->HasEvents() | node18->HasEvents());
							}
							node17->SetHasEvents(node17->HasEvents() | node4->HasEvents());
						}
						{
							ReferencedBehavior_bt_node_test_htn_house_build_house_node20* node20 = BEHAVIAC_NEW ReferencedBehavior_bt_node_test_htn_house_build_house_node20;
							node20->SetClassNameString("ReferencedBehavior");
							node20->SetId(20);
#if !BEHAVIAC_RELEASE
							node20->SetAgentType("HTNAgentHouse");
#endif
							node17->AddChild(node20);
							node17->SetHasEvents(node17->HasEvents() | node20->HasEvents());
						}
						{
							Action_bt_node_test_htn_house_build_house_node19* node19 = BEHAVIAC_NEW Action_bt_node_test_htn_house_build_house_node19;
							node19->SetClassNameString("Action");
							node19->SetId(19);
#if !BEHAVIAC_RELEASE
							node19->SetAgentType("HTNAgentHouse");
#endif
							// attachments
							{
								Precondition_bt_node_test_htn_house_build_house_attach27* attach27 = BEHAVIAC_NEW Precondition_bt_node_test_htn_house_build_house_attach27;
								attach27->SetClassNameString("Precondition");
								attach27->SetId(27);
#if !BEHAVIAC_RELEASE
								attach27->SetAgentType("HTNAgentHouse");
#endif
								node19->Attach(attach27, true, false, false);
								node19->SetHasEvents(node19->HasEvents() | (Event::DynamicCast(attach27) != 0));
							}
							{
								Precondition_bt_node_test_htn_house_build_house_attach9* attach9 = BEHAVIAC_NEW Precondition_bt_node_test_htn_house_build_house_attach9;
								attach9->SetClassNameString("Precondition");
								attach9->SetId(9);
#if !BEHAVIAC_RELEASE
								attach9->SetAgentType("HTNAgentHouse");
#endif
								node19->Attach(attach9, true, false, false);
								node19->SetHasEvents(node19->HasEvents() | (Event::DynamicCast(attach9) != 0));
							}
							{
								Effector_bt_node_test_htn_house_build_house_attach10* attach10 = BEHAVIAC_NEW Effector_bt_node_test_htn_house_build_house_attach10;
								attach10->SetClassNameString("Effector");
								attach10->SetId(10);
#if !BEHAVIAC_RELEASE
								attach10->SetAgentType("HTNAgentHouse");
#endif
								node19->Attach(attach10, false, true, false);
								node19->SetHasEvents(node19->HasEvents() | (Event::DynamicCast(attach10) != 0));
							}
							{
								Effector_bt_node_test_htn_house_build_house_attach11* attach11 = BEHAVIAC_NEW Effector_bt_node_test_htn_house_build_house_attach11;
								attach11->SetClassNameString("Effector");
								attach11->SetId(11);
#if !BEHAVIAC_RELEASE
								attach11->SetAgentType("HTNAgentHouse");
#endif
								node19->Attach(attach11, false, true, false);
								node19->SetHasEvents(node19->HasEvents() | (Event::DynamicCast(attach11) != 0));
							}
							{
								Effector_bt_node_test_htn_house_build_house_attach12* attach12 = BEHAVIAC_NEW Effector_bt_node_test_htn_house_build_house_attach12;
								attach12->SetClassNameString("Effector");
								attach12->SetId(12);
#if !BEHAVIAC_RELEASE
								attach12->SetAgentType("HTNAgentHouse");
#endif
								node19->Attach(attach12, false, true, false);
								node19->SetHasEvents(node19->HasEvents() | (Event::DynamicCast(attach12) != 0));
							}
							node17->AddChild(node19);
							node17->SetHasEvents(node17->HasEvents() | node19->HasEvents());
						}
						node2->SetHasEvents(node2->HasEvents() | node17->HasEvents());
					}
					node7->SetHasEvents(node7->HasEvents() | node2->HasEvents());
				}
				{
					Method* node21 = BEHAVIAC_NEW Method;
					node21->SetClassNameString("Method");
					node21->SetId(21);
#if !BEHAVIAC_RELEASE
					node21->SetAgentType("HTNAgentHouse");
#endif
					node7->AddChild(node21);
					{
						Sequence* node22 = BEHAVIAC_NEW Sequence;
						node22->SetClassNameString("Sequence");
						node22->SetId(22);
#if !BEHAVIAC_RELEASE
						node22->SetAgentType("HTNAgentHouse");
#endif
						node21->AddChild(node22);
						{
							Parallel_bt_node_test_htn_house_build_house_node23* node23 = BEHAVIAC_NEW Parallel_bt_node_test_htn_house_build_house_node23;
							node23->SetClassNameString("Parallel");
							node23->SetId(23);
#if !BEHAVIAC_RELEASE
							node23->SetAgentType("HTNAgentHouse");
#endif
							node22->AddChild(node23);
							{
								Sequence* node14 = BEHAVIAC_NEW Sequence;
								node14->SetClassNameString("Sequence");
								node14->SetId(14);
#if !BEHAVIAC_RELEASE
								node14->SetAgentType("HTNAgentHouse");
#endif
								node23->AddChild(node14);
								{
									Action_bt_node_test_htn_house_build_house_node28* node28 = BEHAVIAC_NEW Action_bt_node_test_htn_house_build_house_node28;
									node28->SetClassNameString("Action");
									node28->SetId(28);
#if !BEHAVIAC_RELEASE
									node28->SetAgentType("HTNAgentHouse");
#endif
									// attachments
									{
										Precondition_bt_node_test_htn_house_build_house_attach15* attach15 = BEHAVIAC_NEW Precondition_bt_node_test_htn_house_build_house_attach15;
										attach15->SetClassNameString("Precondition");
										attach15->SetId(15);
#if !BEHAVIAC_RELEASE
										attach15->SetAgentType("HTNAgentHouse");
#endif
										node28->Attach(attach15, true, false, false);
										node28->SetHasEvents(node28->HasEvents() | (Event::DynamicCast(attach15) != 0));
									}
									{
										Effector_bt_node_test_htn_house_build_house_attach16* attach16 = BEHAVIAC_NEW Effector_bt_node_test_htn_house_build_house_attach16;
										attach16->SetClassNameString("Effector");
										attach16->SetId(16);
#if !BEHAVIAC_RELEASE
										attach16->SetAgentType("HTNAgentHouse");
#endif
										node28->Attach(attach16, false, true, false);
										node28->SetHasEvents(node28->HasEvents() | (Event::DynamicCast(attach16) != 0));
									}
									node14->AddChild(node28);
									node14->SetHasEvents(node14->HasEvents() | node28->HasEvents());
								}
								{
									Action_bt_node_test_htn_house_build_house_node24* node24 = BEHAVIAC_NEW Action_bt_node_test_htn_house_build_house_node24;
									node24->SetClassNameString("Action");
									node24->SetId(24);
#if !BEHAVIAC_RELEASE
									node24->SetAgentType("HTNAgentHouse");
#endif
									node14->AddChild(node24);
									node14->SetHasEvents(node14->HasEvents() | node24->HasEvents());
								}
								node23->SetHasEvents(node23->HasEvents() | node14->HasEvents());
							}
							{
								Action_bt_node_test_htn_house_build_house_node25* node25 = BEHAVIAC_NEW Action_bt_node_test_htn_house_build_house_node25;
								node25->SetClassNameString("Action");
								node25->SetId(25);
#if !BEHAVIAC_RELEASE
								node25->SetAgentType("HTNAgentHouse");
#endif
								node23->AddChild(node25);
								node23->SetHasEvents(node23->HasEvents() | node25->HasEvents());
							}
							node22->SetHasEvents(node22->HasEvents() | node23->HasEvents());
						}
						{
							ReferencedBehavior_bt_node_test_htn_house_build_house_node26* node26 = BEHAVIAC_NEW ReferencedBehavior_bt_node_test_htn_house_build_house_node26;
							node26->SetClassNameString("ReferencedBehavior");
							node26->SetId(26);
#if !BEHAVIAC_RELEASE
							node26->SetAgentType("HTNAgentHouse");
#endif
							node22->AddChild(node26);
							node22->SetHasEvents(node22->HasEvents() | node26->HasEvents());
						}
						node21->SetHasEvents(node21->HasEvents() | node22->HasEvents());
					}
					node7->SetHasEvents(node7->HasEvents() | node21->HasEvents());
				}
				pBT->SetHasEvents(pBT->HasEvents() | node7->HasEvents());
			}
			return true;
		}

	// Source file: node_test/htn/house/construct

	class Task_bt_node_test_htn_house_construct_node0 : public Task
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Task_bt_node_test_htn_house_construct_node0, Task);
		Task_bt_node_test_htn_house_construct_node0()
		{
			this->m_task = (CTaskMethod*)Action::LoadMethod("Self.HTNAgentHouse::construct()");
			BEHAVIAC_ASSERT(this->m_task != NULL);
			this->m_bHTN = true;
		}
	protected:
	};

	class Precondition_bt_node_test_htn_house_construct_attach1 : public Precondition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Precondition_bt_node_test_htn_house_construct_attach1, Precondition);
		Precondition_bt_node_test_htn_house_construct_attach1()
		{
			this->SetPhase(Precondition::E_ENTER);
			this->SetIsAnd(true);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("Permit") == 3054969542u);
			bool& opl = (bool&)pAgent->GetVariable<bool >(3054969542u);
			bool opr2 = true;
			bool op = Details::Equal(opl, opr2);
			if (!op)
				result = BT_FAILURE;
			return result;
		}
	};

	class Effector_bt_node_test_htn_house_construct_attach2 : public Effector
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Effector_bt_node_test_htn_house_construct_attach2, Effector);
		Effector_bt_node_test_htn_house_construct_attach2()
		{
			this->SetPhase(Effector::E_SUCCESS);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			bool opr2 = true;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("HouseBuilt") == 1186824470u);
			pAgent->SetVariable("HouseBuilt", opr2, 1186824470u);
			return result;
		}
	};

	class Action_bt_node_test_htn_house_construct_node3 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_htn_house_construct_node3, Action);
		Action_bt_node_test_htn_house_construct_node3()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((HTNAgentHouse*)pAgent)->_Execute_Method_<METHOD_TYPE_HTNAgentHouse_BuildFoundation, void >();
			return BT_SUCCESS;
		}
	};

	class Action_bt_node_test_htn_house_construct_node4 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_htn_house_construct_node4, Action);
		Action_bt_node_test_htn_house_construct_node4()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((HTNAgentHouse*)pAgent)->_Execute_Method_<METHOD_TYPE_HTNAgentHouse_BuildFrame, void >();
			return BT_SUCCESS;
		}
	};

	class Parallel_bt_node_test_htn_house_construct_node5 : public Parallel
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Parallel_bt_node_test_htn_house_construct_node5, Parallel);
		Parallel_bt_node_test_htn_house_construct_node5()
		{
			m_failPolicy = FAIL_ON_ONE;
			m_succeedPolicy = SUCCEED_ON_ALL;
			m_exitPolicy = EXIT_ABORT_RUNNINGSIBLINGS;
			m_childFinishPolicy = CHILDFINISH_LOOP;
		}
	protected:
	};

	class Action_bt_node_test_htn_house_construct_node6 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_htn_house_construct_node6, Action);
		Action_bt_node_test_htn_house_construct_node6()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((HTNAgentHouse*)pAgent)->_Execute_Method_<METHOD_TYPE_HTNAgentHouse_BuildRoof, void >();
			return BT_SUCCESS;
		}
	};

	class Action_bt_node_test_htn_house_construct_node7 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_htn_house_construct_node7, Action);
		Action_bt_node_test_htn_house_construct_node7()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((HTNAgentHouse*)pAgent)->_Execute_Method_<METHOD_TYPE_HTNAgentHouse_BuildWalls, void >();
			return BT_SUCCESS;
		}
	};

	class Action_bt_node_test_htn_house_construct_node8 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_htn_house_construct_node8, Action);
		Action_bt_node_test_htn_house_construct_node8()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((HTNAgentHouse*)pAgent)->_Execute_Method_<METHOD_TYPE_HTNAgentHouse_BuildInterior, void >();
			return BT_SUCCESS;
		}
	};

		bool bt_node_test_htn_house_construct::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("node_test/htn/house/construct");
			pBT->SetIsFSM(false);
#if !BEHAVIAC_RELEASE
			pBT->SetAgentType("HTNAgentHouse");
#endif
			// children
			{
				Task_bt_node_test_htn_house_construct_node0* node0 = BEHAVIAC_NEW Task_bt_node_test_htn_house_construct_node0;
				node0->SetClassNameString("Task");
				node0->SetId(0);
#if !BEHAVIAC_RELEASE
				node0->SetAgentType("HTNAgentHouse");
#endif
				// attachments
				{
					Precondition_bt_node_test_htn_house_construct_attach1* attach1 = BEHAVIAC_NEW Precondition_bt_node_test_htn_house_construct_attach1;
					attach1->SetClassNameString("Precondition");
					attach1->SetId(1);
#if !BEHAVIAC_RELEASE
					attach1->SetAgentType("HTNAgentHouse");
#endif
					node0->Attach(attach1, true, false, false);
					node0->SetHasEvents(node0->HasEvents() | (Event::DynamicCast(attach1) != 0));
				}
				{
					Effector_bt_node_test_htn_house_construct_attach2* attach2 = BEHAVIAC_NEW Effector_bt_node_test_htn_house_construct_attach2;
					attach2->SetClassNameString("Effector");
					attach2->SetId(2);
#if !BEHAVIAC_RELEASE
					attach2->SetAgentType("HTNAgentHouse");
#endif
					node0->Attach(attach2, false, true, false);
					node0->SetHasEvents(node0->HasEvents() | (Event::DynamicCast(attach2) != 0));
				}
				pBT->AddChild(node0);
				{
					Method* node9 = BEHAVIAC_NEW Method;
					node9->SetClassNameString("Method");
					node9->SetId(9);
#if !BEHAVIAC_RELEASE
					node9->SetAgentType("HTNAgentHouse");
#endif
					node0->AddChild(node9);
					{
						Sequence* node10 = BEHAVIAC_NEW Sequence;
						node10->SetClassNameString("Sequence");
						node10->SetId(10);
#if !BEHAVIAC_RELEASE
						node10->SetAgentType("HTNAgentHouse");
#endif
						node9->AddChild(node10);
						{
							Action_bt_node_test_htn_house_construct_node3* node3 = BEHAVIAC_NEW Action_bt_node_test_htn_house_construct_node3;
							node3->SetClassNameString("Action");
							node3->SetId(3);
#if !BEHAVIAC_RELEASE
							node3->SetAgentType("HTNAgentHouse");
#endif
							node10->AddChild(node3);
							node10->SetHasEvents(node10->HasEvents() | node3->HasEvents());
						}
						{
							Action_bt_node_test_htn_house_construct_node4* node4 = BEHAVIAC_NEW Action_bt_node_test_htn_house_construct_node4;
							node4->SetClassNameString("Action");
							node4->SetId(4);
#if !BEHAVIAC_RELEASE
							node4->SetAgentType("HTNAgentHouse");
#endif
							node10->AddChild(node4);
							node10->SetHasEvents(node10->HasEvents() | node4->HasEvents());
						}
						{
							Parallel_bt_node_test_htn_house_construct_node5* node5 = BEHAVIAC_NEW Parallel_bt_node_test_htn_house_construct_node5;
							node5->SetClassNameString("Parallel");
							node5->SetId(5);
#if !BEHAVIAC_RELEASE
							node5->SetAgentType("HTNAgentHouse");
#endif
							node10->AddChild(node5);
							{
								Action_bt_node_test_htn_house_construct_node6* node6 = BEHAVIAC_NEW Action_bt_node_test_htn_house_construct_node6;
								node6->SetClassNameString("Action");
								node6->SetId(6);
#if !BEHAVIAC_RELEASE
								node6->SetAgentType("HTNAgentHouse");
#endif
								node5->AddChild(node6);
								node5->SetHasEvents(node5->HasEvents() | node6->HasEvents());
							}
							{
								Action_bt_node_test_htn_house_construct_node7* node7 = BEHAVIAC_NEW Action_bt_node_test_htn_house_construct_node7;
								node7->SetClassNameString("Action");
								node7->SetId(7);
#if !BEHAVIAC_RELEASE
								node7->SetAgentType("HTNAgentHouse");
#endif
								node5->AddChild(node7);
								node5->SetHasEvents(node5->HasEvents() | node7->HasEvents());
							}
							node10->SetHasEvents(node10->HasEvents() | node5->HasEvents());
						}
						{
							Action_bt_node_test_htn_house_construct_node8* node8 = BEHAVIAC_NEW Action_bt_node_test_htn_house_construct_node8;
							node8->SetClassNameString("Action");
							node8->SetId(8);
#if !BEHAVIAC_RELEASE
							node8->SetAgentType("HTNAgentHouse");
#endif
							node10->AddChild(node8);
							node10->SetHasEvents(node10->HasEvents() | node8->HasEvents());
						}
						node9->SetHasEvents(node9->HasEvents() | node10->HasEvents());
					}
					node0->SetHasEvents(node0->HasEvents() | node9->HasEvents());
				}
				pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
			}
			return true;
		}

	// Source file: node_test/htn/house/root

	class Task_bt_node_test_htn_house_root_node1 : public Task
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Task_bt_node_test_htn_house_root_node1, Task);
		Task_bt_node_test_htn_house_root_node1()
		{
			this->m_task = (CTaskMethod*)Action::LoadMethod("Self.HTNAgentHouse::root()");
			BEHAVIAC_ASSERT(this->m_task != NULL);
			this->m_bHTN = true;
		}
	protected:
	};

	class Parallel_bt_node_test_htn_house_root_node12 : public Parallel
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Parallel_bt_node_test_htn_house_root_node12, Parallel);
		Parallel_bt_node_test_htn_house_root_node12()
		{
			m_failPolicy = FAIL_ON_ONE;
			m_succeedPolicy = SUCCEED_ON_ALL;
			m_exitPolicy = EXIT_ABORT_RUNNINGSIBLINGS;
			m_childFinishPolicy = CHILDFINISH_LOOP;
		}
	protected:
	};

	class Action_bt_node_test_htn_house_root_node4 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_htn_house_root_node4, Action);
		Action_bt_node_test_htn_house_root_node4()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((HTNAgentHouse*)pAgent)->_Execute_Method_<METHOD_TYPE_HTNAgentHouse_BuyLand, void >();
			return BT_SUCCESS;
		}
	};

	class Precondition_bt_node_test_htn_house_root_attach3 : public Precondition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Precondition_bt_node_test_htn_house_root_attach3, Precondition);
		Precondition_bt_node_test_htn_house_root_attach3()
		{
			this->SetPhase(Precondition::E_ENTER);
			this->SetIsAnd(true);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("Money") == 4260042937u);
			int& opl = (int&)pAgent->GetVariable<int >(4260042937u);
			int opr2 = 100;
			bool op = Details::Greater(opl, opr2);
			if (!op)
				result = BT_FAILURE;
			return result;
		}
	};

	class Effector_bt_node_test_htn_house_root_attach5 : public Effector
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Effector_bt_node_test_htn_house_root_attach5, Effector);
		Effector_bt_node_test_htn_house_root_attach5()
		{
			this->SetPhase(Effector::E_SUCCESS);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("Money") == 4260042937u);
			int& opr1 = (int&)pAgent->GetVariable<int >(4260042937u);
			int opr2 = 100;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("Money") == 4260042937u);
			pAgent->SetVariable("Money", (int)(opr1 - opr2), 4260042937u);
			return result;
		}
	};

	class Effector_bt_node_test_htn_house_root_attach6 : public Effector
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Effector_bt_node_test_htn_house_root_attach6, Effector);
		Effector_bt_node_test_htn_house_root_attach6()
		{
			this->SetPhase(Effector::E_SUCCESS);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			bool opr2 = true;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("Land") == 1676779868u);
			pAgent->SetVariable("Land", opr2, 1676779868u);
			return result;
		}
	};

	class Action_bt_node_test_htn_house_root_node8 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_htn_house_root_node8, Action);
		Action_bt_node_test_htn_house_root_node8()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((HTNAgentHouse*)pAgent)->_Execute_Method_<METHOD_TYPE_HTNAgentHouse_GetLoan, void >();
			return BT_SUCCESS;
		}
	};

	class Precondition_bt_node_test_htn_house_root_attach7 : public Precondition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Precondition_bt_node_test_htn_house_root_attach7, Precondition);
		Precondition_bt_node_test_htn_house_root_attach7()
		{
			this->SetPhase(Precondition::E_ENTER);
			this->SetIsAnd(true);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("GoodCredit") == 2793604018u);
			bool& opl = (bool&)pAgent->GetVariable<bool >(2793604018u);
			bool opr2 = true;
			bool op = Details::Equal(opl, opr2);
			if (!op)
				result = BT_FAILURE;
			return result;
		}
	};

	class Effector_bt_node_test_htn_house_root_attach9 : public Effector
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Effector_bt_node_test_htn_house_root_attach9, Effector);
		Effector_bt_node_test_htn_house_root_attach9()
		{
			this->SetPhase(Effector::E_SUCCESS);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("Money") == 4260042937u);
			int& opr1 = (int&)pAgent->GetVariable<int >(4260042937u);
			int opr2 = 50;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("Money") == 4260042937u);
			pAgent->SetVariable("Money", (int)(opr1 + opr2), 4260042937u);
			return result;
		}
	};

	class Effector_bt_node_test_htn_house_root_attach10 : public Effector
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Effector_bt_node_test_htn_house_root_attach10, Effector);
		Effector_bt_node_test_htn_house_root_attach10()
		{
			this->SetPhase(Effector::E_SUCCESS);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			bool opr2 = true;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("Mortgage") == 669368973u);
			pAgent->SetVariable("Mortgage", opr2, 669368973u);
			return result;
		}
	};

	class ReferencedBehavior_bt_node_test_htn_house_root_node11 : public ReferencedBehavior
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(ReferencedBehavior_bt_node_test_htn_house_root_node11, ReferencedBehavior);
		ReferencedBehavior_bt_node_test_htn_house_root_node11()
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
			m_taskMethod = (CTaskMethod*)Action::LoadMethod("Self.HTNAgentHouse::build_house()");
			BEHAVIAC_ASSERT(m_taskMethod);
		}
	protected:
		virtual const char* GetReferencedTree(const Agent* pAgent) const
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			return (char*)("node_test/htn/house/build_house");
		}
	};

		bool bt_node_test_htn_house_root::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("node_test/htn/house/root");
			pBT->SetIsFSM(false);
#if !BEHAVIAC_RELEASE
			pBT->SetAgentType("HTNAgentHouse");
#endif
			// children
			{
				Task_bt_node_test_htn_house_root_node1* node1 = BEHAVIAC_NEW Task_bt_node_test_htn_house_root_node1;
				node1->SetClassNameString("Task");
				node1->SetId(1);
#if !BEHAVIAC_RELEASE
				node1->SetAgentType("HTNAgentHouse");
#endif
				pBT->AddChild(node1);
				{
					Method* node0 = BEHAVIAC_NEW Method;
					node0->SetClassNameString("Method");
					node0->SetId(0);
#if !BEHAVIAC_RELEASE
					node0->SetAgentType("HTNAgentHouse");
#endif
					node1->AddChild(node0);
					{
						Sequence* node2 = BEHAVIAC_NEW Sequence;
						node2->SetClassNameString("Sequence");
						node2->SetId(2);
#if !BEHAVIAC_RELEASE
						node2->SetAgentType("HTNAgentHouse");
#endif
						node0->AddChild(node2);
						{
							Parallel_bt_node_test_htn_house_root_node12* node12 = BEHAVIAC_NEW Parallel_bt_node_test_htn_house_root_node12;
							node12->SetClassNameString("Parallel");
							node12->SetId(12);
#if !BEHAVIAC_RELEASE
							node12->SetAgentType("HTNAgentHouse");
#endif
							node2->AddChild(node12);
							{
								Action_bt_node_test_htn_house_root_node4* node4 = BEHAVIAC_NEW Action_bt_node_test_htn_house_root_node4;
								node4->SetClassNameString("Action");
								node4->SetId(4);
#if !BEHAVIAC_RELEASE
								node4->SetAgentType("HTNAgentHouse");
#endif
								// attachments
								{
									Precondition_bt_node_test_htn_house_root_attach3* attach3 = BEHAVIAC_NEW Precondition_bt_node_test_htn_house_root_attach3;
									attach3->SetClassNameString("Precondition");
									attach3->SetId(3);
#if !BEHAVIAC_RELEASE
									attach3->SetAgentType("HTNAgentHouse");
#endif
									node4->Attach(attach3, true, false, false);
									node4->SetHasEvents(node4->HasEvents() | (Event::DynamicCast(attach3) != 0));
								}
								{
									Effector_bt_node_test_htn_house_root_attach5* attach5 = BEHAVIAC_NEW Effector_bt_node_test_htn_house_root_attach5;
									attach5->SetClassNameString("Effector");
									attach5->SetId(5);
#if !BEHAVIAC_RELEASE
									attach5->SetAgentType("HTNAgentHouse");
#endif
									node4->Attach(attach5, false, true, false);
									node4->SetHasEvents(node4->HasEvents() | (Event::DynamicCast(attach5) != 0));
								}
								{
									Effector_bt_node_test_htn_house_root_attach6* attach6 = BEHAVIAC_NEW Effector_bt_node_test_htn_house_root_attach6;
									attach6->SetClassNameString("Effector");
									attach6->SetId(6);
#if !BEHAVIAC_RELEASE
									attach6->SetAgentType("HTNAgentHouse");
#endif
									node4->Attach(attach6, false, true, false);
									node4->SetHasEvents(node4->HasEvents() | (Event::DynamicCast(attach6) != 0));
								}
								node12->AddChild(node4);
								node12->SetHasEvents(node12->HasEvents() | node4->HasEvents());
							}
							{
								Action_bt_node_test_htn_house_root_node8* node8 = BEHAVIAC_NEW Action_bt_node_test_htn_house_root_node8;
								node8->SetClassNameString("Action");
								node8->SetId(8);
#if !BEHAVIAC_RELEASE
								node8->SetAgentType("HTNAgentHouse");
#endif
								// attachments
								{
									Precondition_bt_node_test_htn_house_root_attach7* attach7 = BEHAVIAC_NEW Precondition_bt_node_test_htn_house_root_attach7;
									attach7->SetClassNameString("Precondition");
									attach7->SetId(7);
#if !BEHAVIAC_RELEASE
									attach7->SetAgentType("HTNAgentHouse");
#endif
									node8->Attach(attach7, true, false, false);
									node8->SetHasEvents(node8->HasEvents() | (Event::DynamicCast(attach7) != 0));
								}
								{
									Effector_bt_node_test_htn_house_root_attach9* attach9 = BEHAVIAC_NEW Effector_bt_node_test_htn_house_root_attach9;
									attach9->SetClassNameString("Effector");
									attach9->SetId(9);
#if !BEHAVIAC_RELEASE
									attach9->SetAgentType("HTNAgentHouse");
#endif
									node8->Attach(attach9, false, true, false);
									node8->SetHasEvents(node8->HasEvents() | (Event::DynamicCast(attach9) != 0));
								}
								{
									Effector_bt_node_test_htn_house_root_attach10* attach10 = BEHAVIAC_NEW Effector_bt_node_test_htn_house_root_attach10;
									attach10->SetClassNameString("Effector");
									attach10->SetId(10);
#if !BEHAVIAC_RELEASE
									attach10->SetAgentType("HTNAgentHouse");
#endif
									node8->Attach(attach10, false, true, false);
									node8->SetHasEvents(node8->HasEvents() | (Event::DynamicCast(attach10) != 0));
								}
								node12->AddChild(node8);
								node12->SetHasEvents(node12->HasEvents() | node8->HasEvents());
							}
							node2->SetHasEvents(node2->HasEvents() | node12->HasEvents());
						}
						{
							ReferencedBehavior_bt_node_test_htn_house_root_node11* node11 = BEHAVIAC_NEW ReferencedBehavior_bt_node_test_htn_house_root_node11;
							node11->SetClassNameString("ReferencedBehavior");
							node11->SetId(11);
#if !BEHAVIAC_RELEASE
							node11->SetAgentType("HTNAgentHouse");
#endif
							node2->AddChild(node11);
							node2->SetHasEvents(node2->HasEvents() | node11->HasEvents());
						}
						node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
					}
					node1->SetHasEvents(node1->HasEvents() | node0->HasEvents());
				}
				pBT->SetHasEvents(pBT->HasEvents() | node1->HasEvents());
			}
			return true;
		}

	// Source file: node_test/htn/travel/root

	class Task_bt_node_test_htn_travel_root_node1 : public Task
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Task_bt_node_test_htn_travel_root_node1, Task);
		Task_bt_node_test_htn_travel_root_node1()
		{
			this->m_task = (CTaskMethod*)Action::LoadMethod("Self.HTNAgentTravel::root()");
			BEHAVIAC_ASSERT(this->m_task != NULL);
			this->m_bHTN = true;
		}
	protected:
	};

	class Precondition_bt_node_test_htn_travel_root_attach0 : public Precondition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Precondition_bt_node_test_htn_travel_root_attach0, Precondition);
		Precondition_bt_node_test_htn_travel_root_attach0()
		{
			this->SetPhase(Precondition::E_ENTER);
			this->SetIsAnd(true);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("start") == 537854745u);
			int& opl_p0 = (int&)pAgent->GetVariable<int >(537854745u);
			bool opl = ((HTNAgentTravel*)pAgent)->_Execute_Method_<METHOD_TYPE_HTNAgentTravel_exist_start, bool, int& >(opl_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("start") == 537854745u);
			pAgent->SetVariable("start", opl_p0, 537854745u);
			bool opr2 = true;
			bool op = Details::Equal(opl, opr2);
			if (!op)
				result = BT_FAILURE;
			return result;
		}
	};

	class Precondition_bt_node_test_htn_travel_root_attach3 : public Precondition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Precondition_bt_node_test_htn_travel_root_attach3, Precondition);
		Precondition_bt_node_test_htn_travel_root_attach3()
		{
			this->SetPhase(Precondition::E_ENTER);
			this->SetIsAnd(true);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("finish") == 3620922618u);
			int& opl_p0 = (int&)pAgent->GetVariable<int >(3620922618u);
			bool opl = ((HTNAgentTravel*)pAgent)->_Execute_Method_<METHOD_TYPE_HTNAgentTravel_exist_finish, bool, int& >(opl_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("finish") == 3620922618u);
			pAgent->SetVariable("finish", opl_p0, 3620922618u);
			bool opr2 = true;
			bool op = Details::Equal(opl, opr2);
			if (!op)
				result = BT_FAILURE;
			return result;
		}
	};

	class ReferencedBehavior_bt_node_test_htn_travel_root_node4 : public ReferencedBehavior
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(ReferencedBehavior_bt_node_test_htn_travel_root_node4, ReferencedBehavior);
		ReferencedBehavior_bt_node_test_htn_travel_root_node4()
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
			m_taskMethod = (CTaskMethod*)Action::LoadMethod("Self.HTNAgentTravel::travel(int Self.HTNAgentTravel::start,int Self.HTNAgentTravel::finish)");
			BEHAVIAC_ASSERT(m_taskMethod);
		}
	protected:
		virtual const char* GetReferencedTree(const Agent* pAgent) const
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			return (char*)("node_test/htn/travel/travel");
		}
	};

		bool bt_node_test_htn_travel_root::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("node_test/htn/travel/root");
			pBT->SetIsFSM(false);
#if !BEHAVIAC_RELEASE
			pBT->SetAgentType("HTNAgentTravel");
#endif
			// pars
			pBT->AddPar("HTNAgentTravel", "int", "start", "0");
			pBT->AddPar("HTNAgentTravel", "int", "finish", "0");
			// children
			{
				Task_bt_node_test_htn_travel_root_node1* node1 = BEHAVIAC_NEW Task_bt_node_test_htn_travel_root_node1;
				node1->SetClassNameString("Task");
				node1->SetId(1);
#if !BEHAVIAC_RELEASE
				node1->SetAgentType("HTNAgentTravel");
#endif
				pBT->AddChild(node1);
				{
					Method* node2 = BEHAVIAC_NEW Method;
					node2->SetClassNameString("Method");
					node2->SetId(2);
#if !BEHAVIAC_RELEASE
					node2->SetAgentType("HTNAgentTravel");
#endif
					// attachments
					{
						Precondition_bt_node_test_htn_travel_root_attach0* attach0 = BEHAVIAC_NEW Precondition_bt_node_test_htn_travel_root_attach0;
						attach0->SetClassNameString("Precondition");
						attach0->SetId(0);
#if !BEHAVIAC_RELEASE
						attach0->SetAgentType("HTNAgentTravel");
#endif
						node2->Attach(attach0, true, false, false);
						node2->SetHasEvents(node2->HasEvents() | (Event::DynamicCast(attach0) != 0));
					}
					{
						Precondition_bt_node_test_htn_travel_root_attach3* attach3 = BEHAVIAC_NEW Precondition_bt_node_test_htn_travel_root_attach3;
						attach3->SetClassNameString("Precondition");
						attach3->SetId(3);
#if !BEHAVIAC_RELEASE
						attach3->SetAgentType("HTNAgentTravel");
#endif
						node2->Attach(attach3, true, false, false);
						node2->SetHasEvents(node2->HasEvents() | (Event::DynamicCast(attach3) != 0));
					}
					node1->AddChild(node2);
					{
						ReferencedBehavior_bt_node_test_htn_travel_root_node4* node4 = BEHAVIAC_NEW ReferencedBehavior_bt_node_test_htn_travel_root_node4;
						node4->SetClassNameString("ReferencedBehavior");
						node4->SetId(4);
#if !BEHAVIAC_RELEASE
						node4->SetAgentType("HTNAgentTravel");
#endif
						node2->AddChild(node4);
						node2->SetHasEvents(node2->HasEvents() | node4->HasEvents());
					}
					node1->SetHasEvents(node1->HasEvents() | node2->HasEvents());
				}
				pBT->SetHasEvents(pBT->HasEvents() | node1->HasEvents());
			}
			return true;
		}

	// Source file: node_test/htn/travel/travel

	class Task_bt_node_test_htn_travel_travel_node0 : public Task
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Task_bt_node_test_htn_travel_travel_node0, Task);
		Task_bt_node_test_htn_travel_travel_node0()
		{
			this->m_task = (CTaskMethod*)Action::LoadMethod("Self.HTNAgentTravel::travel(0,0)");
			BEHAVIAC_ASSERT(this->m_task != NULL);
			this->m_bHTN = true;
		}
	protected:
	};

	class Precondition_bt_node_test_htn_travel_travel_attach1 : public Precondition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Precondition_bt_node_test_htn_travel_travel_attach1, Precondition);
		Precondition_bt_node_test_htn_travel_travel_attach1()
		{
			this->SetPhase(Precondition::E_ENTER);
			this->SetIsAnd(true);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("_$local_task_param_$_0") == 2009726548u);
			int& opl_p0 = (int&)pAgent->GetVariable<int >(2009726548u);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("_$local_task_param_$_1") == 1859309333u);
			int& opl_p1 = (int&)pAgent->GetVariable<int >(1859309333u);
			bool opl = ((HTNAgentTravel*)pAgent)->_Execute_Method_<METHOD_TYPE_HTNAgentTravel_short_distance, bool, int, int >(opl_p0, opl_p1);
			bool opr2 = true;
			bool op = Details::Equal(opl, opr2);
			if (!op)
				result = BT_FAILURE;
			return result;
		}
	};

	class Action_bt_node_test_htn_travel_travel_node3 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_htn_travel_travel_node3, Action);
		Action_bt_node_test_htn_travel_travel_node3()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("_$local_task_param_$_0") == 2009726548u);
			int& method_p0 = (int&)pAgent->GetVariable<int >(2009726548u);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("_$local_task_param_$_1") == 1859309333u);
			int& method_p1 = (int&)pAgent->GetVariable<int >(1859309333u);
			((HTNAgentTravel*)pAgent)->_Execute_Method_<METHOD_TYPE_HTNAgentTravel_ride_taxi, void, int, int >(method_p0, method_p1);
			return BT_SUCCESS;
		}
	};

	class Precondition_bt_node_test_htn_travel_travel_attach4 : public Precondition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Precondition_bt_node_test_htn_travel_travel_attach4, Precondition);
		Precondition_bt_node_test_htn_travel_travel_attach4()
		{
			this->SetPhase(Precondition::E_ENTER);
			this->SetIsAnd(true);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("_$local_task_param_$_0") == 2009726548u);
			int& opl_p0 = (int&)pAgent->GetVariable<int >(2009726548u);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("_$local_task_param_$_1") == 1859309333u);
			int& opl_p1 = (int&)pAgent->GetVariable<int >(1859309333u);
			bool opl = ((HTNAgentTravel*)pAgent)->_Execute_Method_<METHOD_TYPE_HTNAgentTravel_long_distance, bool, int, int >(opl_p0, opl_p1);
			bool opr2 = true;
			bool op = Details::Equal(opl, opr2);
			if (!op)
				result = BT_FAILURE;
			return result;
		}
	};

	class ReferencedBehavior_bt_node_test_htn_travel_travel_node6 : public ReferencedBehavior
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(ReferencedBehavior_bt_node_test_htn_travel_travel_node6, ReferencedBehavior);
		ReferencedBehavior_bt_node_test_htn_travel_travel_node6()
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
			m_taskMethod = (CTaskMethod*)Action::LoadMethod("Self.HTNAgentTravel::travel_by_air(int Self.HTNAgentTravel::_$local_task_param_$_0,int Self.HTNAgentTravel::_$local_task_param_$_1)");
			BEHAVIAC_ASSERT(m_taskMethod);
		}
	protected:
		virtual const char* GetReferencedTree(const Agent* pAgent) const
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			return (char*)("node_test/htn/travel/travel_by_air");
		}
	};

		bool bt_node_test_htn_travel_travel::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("node_test/htn/travel/travel");
			pBT->SetIsFSM(false);
#if !BEHAVIAC_RELEASE
			pBT->SetAgentType("HTNAgentTravel");
#endif
			// pars
			pBT->AddPar("HTNAgentTravel", "int", "_$local_task_param_$_0", "0");
			pBT->AddPar("HTNAgentTravel", "int", "_$local_task_param_$_1", "0");
			// children
			{
				Task_bt_node_test_htn_travel_travel_node0* node0 = BEHAVIAC_NEW Task_bt_node_test_htn_travel_travel_node0;
				node0->SetClassNameString("Task");
				node0->SetId(0);
#if !BEHAVIAC_RELEASE
				node0->SetAgentType("HTNAgentTravel");
#endif
				pBT->AddChild(node0);
				{
					Method* node2 = BEHAVIAC_NEW Method;
					node2->SetClassNameString("Method");
					node2->SetId(2);
#if !BEHAVIAC_RELEASE
					node2->SetAgentType("HTNAgentTravel");
#endif
					// attachments
					{
						Precondition_bt_node_test_htn_travel_travel_attach1* attach1 = BEHAVIAC_NEW Precondition_bt_node_test_htn_travel_travel_attach1;
						attach1->SetClassNameString("Precondition");
						attach1->SetId(1);
#if !BEHAVIAC_RELEASE
						attach1->SetAgentType("HTNAgentTravel");
#endif
						node2->Attach(attach1, true, false, false);
						node2->SetHasEvents(node2->HasEvents() | (Event::DynamicCast(attach1) != 0));
					}
					node0->AddChild(node2);
					{
						Action_bt_node_test_htn_travel_travel_node3* node3 = BEHAVIAC_NEW Action_bt_node_test_htn_travel_travel_node3;
						node3->SetClassNameString("Action");
						node3->SetId(3);
#if !BEHAVIAC_RELEASE
						node3->SetAgentType("HTNAgentTravel");
#endif
						node2->AddChild(node3);
						node2->SetHasEvents(node2->HasEvents() | node3->HasEvents());
					}
					node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
				}
				{
					Method* node5 = BEHAVIAC_NEW Method;
					node5->SetClassNameString("Method");
					node5->SetId(5);
#if !BEHAVIAC_RELEASE
					node5->SetAgentType("HTNAgentTravel");
#endif
					// attachments
					{
						Precondition_bt_node_test_htn_travel_travel_attach4* attach4 = BEHAVIAC_NEW Precondition_bt_node_test_htn_travel_travel_attach4;
						attach4->SetClassNameString("Precondition");
						attach4->SetId(4);
#if !BEHAVIAC_RELEASE
						attach4->SetAgentType("HTNAgentTravel");
#endif
						node5->Attach(attach4, true, false, false);
						node5->SetHasEvents(node5->HasEvents() | (Event::DynamicCast(attach4) != 0));
					}
					node0->AddChild(node5);
					{
						ReferencedBehavior_bt_node_test_htn_travel_travel_node6* node6 = BEHAVIAC_NEW ReferencedBehavior_bt_node_test_htn_travel_travel_node6;
						node6->SetClassNameString("ReferencedBehavior");
						node6->SetId(6);
#if !BEHAVIAC_RELEASE
						node6->SetAgentType("HTNAgentTravel");
#endif
						node5->AddChild(node6);
						node5->SetHasEvents(node5->HasEvents() | node6->HasEvents());
					}
					node0->SetHasEvents(node0->HasEvents() | node5->HasEvents());
				}
				pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
			}
			return true;
		}

	// Source file: node_test/htn/travel/travel_by_air

	class Task_bt_node_test_htn_travel_travel_by_air_node0 : public Task
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Task_bt_node_test_htn_travel_travel_by_air_node0, Task);
		Task_bt_node_test_htn_travel_travel_by_air_node0()
		{
			this->m_task = (CTaskMethod*)Action::LoadMethod("Self.HTNAgentTravel::travel_by_air(0,0)");
			BEHAVIAC_ASSERT(this->m_task != NULL);
			this->m_bHTN = true;
		}
	protected:
	};

	class Precondition_bt_node_test_htn_travel_travel_by_air_attach2 : public Precondition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Precondition_bt_node_test_htn_travel_travel_by_air_attach2, Precondition);
		Precondition_bt_node_test_htn_travel_travel_by_air_attach2()
		{
			this->SetPhase(Precondition::E_ENTER);
			this->SetIsAnd(true);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("_$local_task_param_$_0") == 2009726548u);
			int& opl_p0 = (int&)pAgent->GetVariable<int >(2009726548u);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("as") == 2746731747u);
			behaviac::vector<int>& opl_p1 = (behaviac::vector<int>&)pAgent->GetVariable<behaviac::vector<int> >(2746731747u);
			bool opl = ((HTNAgentTravel*)pAgent)->_Execute_Method_<METHOD_TYPE_HTNAgentTravel_exist_airports, bool, int, behaviac::vector<int>& >(opl_p0, opl_p1);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("as") == 2746731747u);
			pAgent->SetVariable("as", opl_p1, 2746731747u);
			bool opr2 = true;
			bool op = Details::Equal(opl, opr2);
			if (!op)
				result = BT_FAILURE;
			return result;
		}
	};

	class Precondition_bt_node_test_htn_travel_travel_by_air_attach3 : public Precondition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Precondition_bt_node_test_htn_travel_travel_by_air_attach3, Precondition);
		Precondition_bt_node_test_htn_travel_travel_by_air_attach3()
		{
			this->SetPhase(Precondition::E_ENTER);
			this->SetIsAnd(true);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("_$local_task_param_$_1") == 1859309333u);
			int& opl_p0 = (int&)pAgent->GetVariable<int >(1859309333u);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("ay") == 1498948713u);
			int& opl_p1 = (int&)pAgent->GetVariable<int >(1498948713u);
			bool opl = ((HTNAgentTravel*)pAgent)->_Execute_Method_<METHOD_TYPE_HTNAgentTravel_exist_airport, bool, int, int& >(opl_p0, opl_p1);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("ay") == 1498948713u);
			pAgent->SetVariable("ay", opl_p1, 1498948713u);
			bool opr2 = true;
			bool op = Details::Equal(opl, opr2);
			if (!op)
				result = BT_FAILURE;
			return result;
		}
	};

	class DecoratorIterator_bt_node_test_htn_travel_travel_by_air_node5 : public DecoratorIterator
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorIterator_bt_node_test_htn_travel_travel_by_air_node5, DecoratorIterator);
		DecoratorIterator_bt_node_test_htn_travel_travel_by_air_node5()
		{
			m_bDecorateWhenChildEnds = false;
			behaviac::string typeName;
			this->m_opl = Condition::LoadLeft("int Self.HTNAgentTravel::ax", typeName);
			BEHAVIAC_ASSERT(this->m_opl != NULL);
			this->m_opr = Condition::LoadRight("vector<int> Self.HTNAgentTravel::as", typeName);
			BEHAVIAC_ASSERT(this->m_opr != NULL);
		}
	protected:
	};

	class ReferencedBehavior_bt_node_test_htn_travel_travel_by_air_node8 : public ReferencedBehavior
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(ReferencedBehavior_bt_node_test_htn_travel_travel_by_air_node8, ReferencedBehavior);
		ReferencedBehavior_bt_node_test_htn_travel_travel_by_air_node8()
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
			m_taskMethod = (CTaskMethod*)Action::LoadMethod("Self.HTNAgentTravel::travel(int Self.HTNAgentTravel::_$local_task_param_$_0,int Self.HTNAgentTravel::ax)");
			BEHAVIAC_ASSERT(m_taskMethod);
		}
	protected:
		virtual const char* GetReferencedTree(const Agent* pAgent) const
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			return (char*)("node_test/htn/travel/travel");
		}
	};

	class Action_bt_node_test_htn_travel_travel_by_air_node7 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_htn_travel_travel_by_air_node7, Action);
		Action_bt_node_test_htn_travel_travel_by_air_node7()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("ax") == 1078138152u);
			int& method_p0 = (int&)pAgent->GetVariable<int >(1078138152u);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("ay") == 1498948713u);
			int& method_p1 = (int&)pAgent->GetVariable<int >(1498948713u);
			((HTNAgentTravel*)pAgent)->_Execute_Method_<METHOD_TYPE_HTNAgentTravel_fly, void, int, int >(method_p0, method_p1);
			return BT_SUCCESS;
		}
	};

	class ReferencedBehavior_bt_node_test_htn_travel_travel_by_air_node4 : public ReferencedBehavior
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(ReferencedBehavior_bt_node_test_htn_travel_travel_by_air_node4, ReferencedBehavior);
		ReferencedBehavior_bt_node_test_htn_travel_travel_by_air_node4()
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
			m_taskMethod = (CTaskMethod*)Action::LoadMethod("Self.HTNAgentTravel::travel(int Self.HTNAgentTravel::ay,int Self.HTNAgentTravel::_$local_task_param_$_1)");
			BEHAVIAC_ASSERT(m_taskMethod);
		}
	protected:
		virtual const char* GetReferencedTree(const Agent* pAgent) const
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			return (char*)("node_test/htn/travel/travel");
		}
	};

		bool bt_node_test_htn_travel_travel_by_air::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("node_test/htn/travel/travel_by_air");
			pBT->SetIsFSM(false);
#if !BEHAVIAC_RELEASE
			pBT->SetAgentType("HTNAgentTravel");
#endif
			// pars
			pBT->AddPar("HTNAgentTravel", "int", "ax", "0");
			pBT->AddPar("HTNAgentTravel", "int", "ay", "0");
			pBT->AddPar("HTNAgentTravel", "vector<int>", "as", "0:");
			pBT->AddPar("HTNAgentTravel", "int", "_$local_task_param_$_0", "0");
			pBT->AddPar("HTNAgentTravel", "int", "_$local_task_param_$_1", "0");
			// children
			{
				Task_bt_node_test_htn_travel_travel_by_air_node0* node0 = BEHAVIAC_NEW Task_bt_node_test_htn_travel_travel_by_air_node0;
				node0->SetClassNameString("Task");
				node0->SetId(0);
#if !BEHAVIAC_RELEASE
				node0->SetAgentType("HTNAgentTravel");
#endif
				pBT->AddChild(node0);
				{
					Method* node1 = BEHAVIAC_NEW Method;
					node1->SetClassNameString("Method");
					node1->SetId(1);
#if !BEHAVIAC_RELEASE
					node1->SetAgentType("HTNAgentTravel");
#endif
					// attachments
					{
						Precondition_bt_node_test_htn_travel_travel_by_air_attach2* attach2 = BEHAVIAC_NEW Precondition_bt_node_test_htn_travel_travel_by_air_attach2;
						attach2->SetClassNameString("Precondition");
						attach2->SetId(2);
#if !BEHAVIAC_RELEASE
						attach2->SetAgentType("HTNAgentTravel");
#endif
						node1->Attach(attach2, true, false, false);
						node1->SetHasEvents(node1->HasEvents() | (Event::DynamicCast(attach2) != 0));
					}
					{
						Precondition_bt_node_test_htn_travel_travel_by_air_attach3* attach3 = BEHAVIAC_NEW Precondition_bt_node_test_htn_travel_travel_by_air_attach3;
						attach3->SetClassNameString("Precondition");
						attach3->SetId(3);
#if !BEHAVIAC_RELEASE
						attach3->SetAgentType("HTNAgentTravel");
#endif
						node1->Attach(attach3, true, false, false);
						node1->SetHasEvents(node1->HasEvents() | (Event::DynamicCast(attach3) != 0));
					}
					node0->AddChild(node1);
					{
						DecoratorIterator_bt_node_test_htn_travel_travel_by_air_node5* node5 = BEHAVIAC_NEW DecoratorIterator_bt_node_test_htn_travel_travel_by_air_node5;
						node5->SetClassNameString("DecoratorIterator");
						node5->SetId(5);
#if !BEHAVIAC_RELEASE
						node5->SetAgentType("HTNAgentTravel");
#endif
						node1->AddChild(node5);
						{
							Sequence* node6 = BEHAVIAC_NEW Sequence;
							node6->SetClassNameString("Sequence");
							node6->SetId(6);
#if !BEHAVIAC_RELEASE
							node6->SetAgentType("HTNAgentTravel");
#endif
							node5->AddChild(node6);
							{
								ReferencedBehavior_bt_node_test_htn_travel_travel_by_air_node8* node8 = BEHAVIAC_NEW ReferencedBehavior_bt_node_test_htn_travel_travel_by_air_node8;
								node8->SetClassNameString("ReferencedBehavior");
								node8->SetId(8);
#if !BEHAVIAC_RELEASE
								node8->SetAgentType("HTNAgentTravel");
#endif
								node6->AddChild(node8);
								node6->SetHasEvents(node6->HasEvents() | node8->HasEvents());
							}
							{
								Action_bt_node_test_htn_travel_travel_by_air_node7* node7 = BEHAVIAC_NEW Action_bt_node_test_htn_travel_travel_by_air_node7;
								node7->SetClassNameString("Action");
								node7->SetId(7);
#if !BEHAVIAC_RELEASE
								node7->SetAgentType("HTNAgentTravel");
#endif
								node6->AddChild(node7);
								node6->SetHasEvents(node6->HasEvents() | node7->HasEvents());
							}
							{
								ReferencedBehavior_bt_node_test_htn_travel_travel_by_air_node4* node4 = BEHAVIAC_NEW ReferencedBehavior_bt_node_test_htn_travel_travel_by_air_node4;
								node4->SetClassNameString("ReferencedBehavior");
								node4->SetId(4);
#if !BEHAVIAC_RELEASE
								node4->SetAgentType("HTNAgentTravel");
#endif
								node6->AddChild(node4);
								node6->SetHasEvents(node6->HasEvents() | node4->HasEvents());
							}
							node5->SetHasEvents(node5->HasEvents() | node6->HasEvents());
						}
						node1->SetHasEvents(node1->HasEvents() | node5->HasEvents());
					}
					node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
				}
				pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
			}
			return true;
		}

	// Source file: node_test/PreconditionEffectorTest/PreconditionEffectorTest_0

	class Precondition_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_0_attach0 : public Precondition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Precondition_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_0_attach0, Precondition);
		Precondition_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_0_attach0()
		{
			this->SetPhase(Precondition::E_ENTER);
			this->SetIsAnd(true);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			int& opl = ((PreconEffectorAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_PreconEffectorAgent_count_both, int >();
			int opr2 = 0;
			bool op = Details::Equal(opl, opr2);
			if (!op)
				result = BT_FAILURE;
			return result;
		}
	};

	class Action_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_0_node8 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_0_node8, Action);
		Action_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_0_node8()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((PreconEffectorAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_PreconEffectorAgent_action, void >();
			return BT_FAILURE;
		}
	};

	class Precondition_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_0_attach1 : public Precondition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Precondition_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_0_attach1, Precondition);
		Precondition_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_0_attach1()
		{
			this->SetPhase(Precondition::E_ENTER);
			this->SetIsAnd(true);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			int& opl = ((PreconEffectorAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_PreconEffectorAgent_count_failure, int >();
			int opr2 = 0;
			bool op = Details::Equal(opl, opr2);
			if (!op)
				result = BT_FAILURE;
			return result;
		}
	};

	class Effector_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_0_attach2 : public Effector
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Effector_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_0_attach2, Effector);
		Effector_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_0_attach2()
		{
			this->SetPhase(Effector::E_FAILURE);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			int opr2 = 1;
			((PreconEffectorAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_PreconEffectorAgent_count_failure, int >() = opr2;
			return result;
		}
	};

	class Effector_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_0_attach4 : public Effector
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Effector_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_0_attach4, Effector);
		Effector_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_0_attach4()
		{
			this->SetPhase(Effector::E_BOTH);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			int opr1 = ((PreconEffectorAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_PreconEffectorAgent_count_both, int >();
			int opr2 = 1;
			((PreconEffectorAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_PreconEffectorAgent_count_both, int >() = (int)(opr1 + opr2);
			return result;
		}
	};

	class Action_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_0_node9 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_0_node9, Action);
		Action_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_0_node9()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((PreconEffectorAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_PreconEffectorAgent_action, void >();
			return BT_SUCCESS;
		}
	};

	class Precondition_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_0_attach10 : public Precondition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Precondition_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_0_attach10, Precondition);
		Precondition_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_0_attach10()
		{
			this->SetPhase(Precondition::E_ENTER);
			this->SetIsAnd(true);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			int& opl = ((PreconEffectorAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_PreconEffectorAgent_count_success, int >();
			int opr2 = 0;
			bool op = Details::Equal(opl, opr2);
			if (!op)
				result = BT_FAILURE;
			return result;
		}
	};

	class Effector_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_0_attach5 : public Effector
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Effector_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_0_attach5, Effector);
		Effector_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_0_attach5()
		{
			this->SetPhase(Effector::E_SUCCESS);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			int opr2 = 1;
			((PreconEffectorAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_PreconEffectorAgent_count_success, int >() = opr2;
			return result;
		}
	};

	class Effector_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_0_attach6 : public Effector
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Effector_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_0_attach6, Effector);
		Effector_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_0_attach6()
		{
			this->SetPhase(Effector::E_BOTH);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			int opr1 = ((PreconEffectorAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_PreconEffectorAgent_count_both, int >();
			int opr2 = 1;
			((PreconEffectorAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_PreconEffectorAgent_count_both, int >() = (int)(opr1 + opr2);
			return result;
		}
	};

		bool bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_0::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("node_test/PreconditionEffectorTest/PreconditionEffectorTest_0");
			pBT->SetIsFSM(false);
#if !BEHAVIAC_RELEASE
			pBT->SetAgentType("PreconEffectorAgent");
#endif
			// children
			{
				Selector* node3 = BEHAVIAC_NEW Selector;
				node3->SetClassNameString("Selector");
				node3->SetId(3);
#if !BEHAVIAC_RELEASE
				node3->SetAgentType("PreconEffectorAgent");
#endif
				// attachments
				{
					Precondition_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_0_attach0* attach0 = BEHAVIAC_NEW Precondition_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_0_attach0;
					attach0->SetClassNameString("Precondition");
					attach0->SetId(0);
#if !BEHAVIAC_RELEASE
					attach0->SetAgentType("PreconEffectorAgent");
#endif
					node3->Attach(attach0, true, false, false);
					node3->SetHasEvents(node3->HasEvents() | (Event::DynamicCast(attach0) != 0));
				}
				pBT->AddChild(node3);
				{
					Action_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_0_node8* node8 = BEHAVIAC_NEW Action_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_0_node8;
					node8->SetClassNameString("Action");
					node8->SetId(8);
#if !BEHAVIAC_RELEASE
					node8->SetAgentType("PreconEffectorAgent");
#endif
					// attachments
					{
						Precondition_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_0_attach1* attach1 = BEHAVIAC_NEW Precondition_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_0_attach1;
						attach1->SetClassNameString("Precondition");
						attach1->SetId(1);
#if !BEHAVIAC_RELEASE
						attach1->SetAgentType("PreconEffectorAgent");
#endif
						node8->Attach(attach1, true, false, false);
						node8->SetHasEvents(node8->HasEvents() | (Event::DynamicCast(attach1) != 0));
					}
					{
						Effector_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_0_attach2* attach2 = BEHAVIAC_NEW Effector_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_0_attach2;
						attach2->SetClassNameString("Effector");
						attach2->SetId(2);
#if !BEHAVIAC_RELEASE
						attach2->SetAgentType("PreconEffectorAgent");
#endif
						node8->Attach(attach2, false, true, false);
						node8->SetHasEvents(node8->HasEvents() | (Event::DynamicCast(attach2) != 0));
					}
					{
						Effector_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_0_attach4* attach4 = BEHAVIAC_NEW Effector_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_0_attach4;
						attach4->SetClassNameString("Effector");
						attach4->SetId(4);
#if !BEHAVIAC_RELEASE
						attach4->SetAgentType("PreconEffectorAgent");
#endif
						node8->Attach(attach4, false, true, false);
						node8->SetHasEvents(node8->HasEvents() | (Event::DynamicCast(attach4) != 0));
					}
					node3->AddChild(node8);
					node3->SetHasEvents(node3->HasEvents() | node8->HasEvents());
				}
				{
					Action_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_0_node9* node9 = BEHAVIAC_NEW Action_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_0_node9;
					node9->SetClassNameString("Action");
					node9->SetId(9);
#if !BEHAVIAC_RELEASE
					node9->SetAgentType("PreconEffectorAgent");
#endif
					// attachments
					{
						Precondition_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_0_attach10* attach10 = BEHAVIAC_NEW Precondition_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_0_attach10;
						attach10->SetClassNameString("Precondition");
						attach10->SetId(10);
#if !BEHAVIAC_RELEASE
						attach10->SetAgentType("PreconEffectorAgent");
#endif
						node9->Attach(attach10, true, false, false);
						node9->SetHasEvents(node9->HasEvents() | (Event::DynamicCast(attach10) != 0));
					}
					{
						Effector_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_0_attach5* attach5 = BEHAVIAC_NEW Effector_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_0_attach5;
						attach5->SetClassNameString("Effector");
						attach5->SetId(5);
#if !BEHAVIAC_RELEASE
						attach5->SetAgentType("PreconEffectorAgent");
#endif
						node9->Attach(attach5, false, true, false);
						node9->SetHasEvents(node9->HasEvents() | (Event::DynamicCast(attach5) != 0));
					}
					{
						Effector_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_0_attach6* attach6 = BEHAVIAC_NEW Effector_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_0_attach6;
						attach6->SetClassNameString("Effector");
						attach6->SetId(6);
#if !BEHAVIAC_RELEASE
						attach6->SetAgentType("PreconEffectorAgent");
#endif
						node9->Attach(attach6, false, true, false);
						node9->SetHasEvents(node9->HasEvents() | (Event::DynamicCast(attach6) != 0));
					}
					node3->AddChild(node9);
					node3->SetHasEvents(node3->HasEvents() | node9->HasEvents());
				}
				pBT->SetHasEvents(pBT->HasEvents() | node3->HasEvents());
			}
			return true;
		}

	// Source file: node_test/PreconditionEffectorTest/PreconditionEffectorTest_1

	class Action_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_1_node4 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_1_node4, Action);
		Action_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_1_node4()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((PreconEffectorAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_PreconEffectorAgent_action, void >();
			return BT_RUNNING;
		}
	};

	class Precondition_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_1_attach0 : public Precondition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Precondition_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_1_attach0, Precondition);
		Precondition_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_1_attach0()
		{
			this->SetPhase(Precondition::E_ENTER);
			this->SetIsAnd(true);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			int& opl = ((PreconEffectorAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_PreconEffectorAgent_count_success, int >();
			int opr2 = 0;
			bool op = Details::Equal(opl, opr2);
			if (!op)
				result = BT_FAILURE;
			return result;
		}
	};

	class Precondition_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_1_attach1 : public Precondition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Precondition_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_1_attach1, Precondition);
		Precondition_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_1_attach1()
		{
			this->SetPhase(Precondition::E_ENTER);
			this->SetIsAnd(true);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			int& opl = ((PreconEffectorAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_PreconEffectorAgent_count_failure, int >();
			int opr2 = 0;
			bool op = Details::Equal(opl, opr2);
			if (!op)
				result = BT_FAILURE;
			return result;
		}
	};

	class Precondition_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_1_attach2 : public Precondition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Precondition_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_1_attach2, Precondition);
		Precondition_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_1_attach2()
		{
			this->SetPhase(Precondition::E_UPDATE);
			this->SetIsAnd(true);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			int& opl = ((PreconEffectorAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_PreconEffectorAgent_count_both, int >();
			int opr2 = 0;
			bool op = Details::Equal(opl, opr2);
			if (!op)
				result = BT_FAILURE;
			return result;
		}
	};

	class Precondition_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_1_attach3 : public Precondition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Precondition_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_1_attach3, Precondition);
		Precondition_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_1_attach3()
		{
			this->SetPhase(Precondition::E_ENTER);
			this->SetIsAnd(true);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			int opr2 = ((PreconEffectorAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_PreconEffectorAgent_fn_return, int >();
			((PreconEffectorAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_PreconEffectorAgent_ret, int >() = opr2;
			return result;
		}
	};

	class Effector_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_1_attach5 : public Effector
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Effector_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_1_attach5, Effector);
		Effector_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_1_attach5()
		{
			this->SetPhase(Effector::E_SUCCESS);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			int opr2 = 1;
			((PreconEffectorAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_PreconEffectorAgent_count_success, int >() = opr2;
			return result;
		}
	};

	class Effector_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_1_attach6 : public Effector
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Effector_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_1_attach6, Effector);
		Effector_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_1_attach6()
		{
			this->SetPhase(Effector::E_FAILURE);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			int opr2 = 1;
			((PreconEffectorAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_PreconEffectorAgent_count_failure, int >() = opr2;
			return result;
		}
	};

	class Effector_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_1_attach7 : public Effector
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Effector_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_1_attach7, Effector);
		Effector_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_1_attach7()
		{
			this->SetPhase(Effector::E_BOTH);
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			EBTStatus result = BT_SUCCESS;
			int opr1 = ((PreconEffectorAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_PreconEffectorAgent_count_both, int >();
			int opr2 = 1;
			((PreconEffectorAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_PreconEffectorAgent_count_both, int >() = (int)(opr1 + opr2);
			return result;
		}
	};

		bool bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_1::Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("node_test/PreconditionEffectorTest/PreconditionEffectorTest_1");
			pBT->SetIsFSM(false);
#if !BEHAVIAC_RELEASE
			pBT->SetAgentType("PreconEffectorAgent");
#endif
			// children
			{
				Action_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_1_node4* node4 = BEHAVIAC_NEW Action_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_1_node4;
				node4->SetClassNameString("Action");
				node4->SetId(4);
#if !BEHAVIAC_RELEASE
				node4->SetAgentType("PreconEffectorAgent");
#endif
				// attachments
				{
					Precondition_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_1_attach0* attach0 = BEHAVIAC_NEW Precondition_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_1_attach0;
					attach0->SetClassNameString("Precondition");
					attach0->SetId(0);
#if !BEHAVIAC_RELEASE
					attach0->SetAgentType("PreconEffectorAgent");
#endif
					node4->Attach(attach0, true, false, false);
					node4->SetHasEvents(node4->HasEvents() | (Event::DynamicCast(attach0) != 0));
				}
				{
					Precondition_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_1_attach1* attach1 = BEHAVIAC_NEW Precondition_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_1_attach1;
					attach1->SetClassNameString("Precondition");
					attach1->SetId(1);
#if !BEHAVIAC_RELEASE
					attach1->SetAgentType("PreconEffectorAgent");
#endif
					node4->Attach(attach1, true, false, false);
					node4->SetHasEvents(node4->HasEvents() | (Event::DynamicCast(attach1) != 0));
				}
				{
					Precondition_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_1_attach2* attach2 = BEHAVIAC_NEW Precondition_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_1_attach2;
					attach2->SetClassNameString("Precondition");
					attach2->SetId(2);
#if !BEHAVIAC_RELEASE
					attach2->SetAgentType("PreconEffectorAgent");
#endif
					node4->Attach(attach2, true, false, false);
					node4->SetHasEvents(node4->HasEvents() | (Event::DynamicCast(attach2) != 0));
				}
				{
					Precondition_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_1_attach3* attach3 = BEHAVIAC_NEW Precondition_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_1_attach3;
					attach3->SetClassNameString("Precondition");
					attach3->SetId(3);
#if !BEHAVIAC_RELEASE
					attach3->SetAgentType("PreconEffectorAgent");
#endif
					node4->Attach(attach3, true, false, false);
					node4->SetHasEvents(node4->HasEvents() | (Event::DynamicCast(attach3) != 0));
				}
				{
					Effector_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_1_attach5* attach5 = BEHAVIAC_NEW Effector_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_1_attach5;
					attach5->SetClassNameString("Effector");
					attach5->SetId(5);
#if !BEHAVIAC_RELEASE
					attach5->SetAgentType("PreconEffectorAgent");
#endif
					node4->Attach(attach5, false, true, false);
					node4->SetHasEvents(node4->HasEvents() | (Event::DynamicCast(attach5) != 0));
				}
				{
					Effector_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_1_attach6* attach6 = BEHAVIAC_NEW Effector_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_1_attach6;
					attach6->SetClassNameString("Effector");
					attach6->SetId(6);
#if !BEHAVIAC_RELEASE
					attach6->SetAgentType("PreconEffectorAgent");
#endif
					node4->Attach(attach6, false, true, false);
					node4->SetHasEvents(node4->HasEvents() | (Event::DynamicCast(attach6) != 0));
				}
				{
					Effector_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_1_attach7* attach7 = BEHAVIAC_NEW Effector_bt_node_test_PreconditionEffectorTest_PreconditionEffectorTest_1_attach7;
					attach7->SetClassNameString("Effector");
					attach7->SetId(7);
#if !BEHAVIAC_RELEASE
					attach7->SetAgentType("PreconEffectorAgent");
#endif
					node4->Attach(attach7, false, true, false);
					node4->SetHasEvents(node4->HasEvents() | (Event::DynamicCast(attach7) != 0));
				}
				pBT->AddChild(node4);
				pBT->SetHasEvents(pBT->HasEvents() | node4->HasEvents());
			}
			return true;
		}

}
