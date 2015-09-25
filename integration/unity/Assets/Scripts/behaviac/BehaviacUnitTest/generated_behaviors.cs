// ---------------------------------------------------------------------
// This file is auto-generated, so please don't modify it by yourself!
// Export file: ../../Scripts/behaviac/BehaviacUnitTest/generated_behaviors.cs
// ---------------------------------------------------------------------

using System;
using System.Collections;
using System.Collections.Generic;
using System.Reflection;

namespace behaviac
{
	class AgentExtra_Generated
	{
		private static Dictionary<string, FieldInfo> _fields = new Dictionary<string, FieldInfo>();
		private static Dictionary<string, PropertyInfo> _properties = new Dictionary<string, PropertyInfo>();
		private static Dictionary<string, MethodInfo> _methods = new Dictionary<string, MethodInfo>();

		public static object GetProperty(behaviac.Agent agent, string property)
		{
			Type type = agent.GetType();
			string propertyName = type.FullName + property;
			if (_fields.ContainsKey(propertyName))
			{
				return _fields[propertyName].GetValue(agent);
			}

			if (_properties.ContainsKey(propertyName))
			{
				return _properties[propertyName].GetValue(agent, null);
			}

			while (type != typeof(object))
			{
				FieldInfo field = type.GetField(property, BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.Static);
				if (field != null)
				{
					_fields[propertyName] = field;
					return field.GetValue(agent);
				}

				PropertyInfo prop = type.GetProperty(property, BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.Static);
				if (prop != null)
				{
					_properties[propertyName] = prop;
					return prop.GetValue(agent, null);
				}

				type = type.BaseType;
			}
			Debug.Check(false, "No property can be found!");
			return null;
		}

		public static void SetProperty(behaviac.Agent agent, string property, object value)
		{
			Type type = agent.GetType();
			string propertyName = type.FullName + property;
			if (_fields.ContainsKey(propertyName))
			{
				_fields[propertyName].SetValue(agent, value);
				return;
			}

			if (_properties.ContainsKey(propertyName))
			{
				_properties[propertyName].SetValue(agent, value, null);
				return;
			}

			while (type != typeof(object))
			{
				FieldInfo field = type.GetField(property, BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.Static);
				if (field != null)
				{
					_fields[propertyName] = field;
					field.SetValue(agent, value);
					return;
				}

				PropertyInfo prop = type.GetProperty(property, BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.Static);
				if (prop != null)
				{
					_properties[propertyName] = prop;
					prop.SetValue(agent, value, null);
					return;
				}

				type = type.BaseType;
			}
			Debug.Check(false, "No property can be found!");
		}

		public static object ExecuteMethod(behaviac.Agent agent, string method, object[] args)
		{
			Type type = agent.GetType();
			string methodName = type.FullName + method;
			if (_methods.ContainsKey(methodName))
			{
				return _methods[methodName].Invoke(agent, args);;
			}

			while (type != typeof(object))
			{
				MethodInfo m = type.GetMethod(method, BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.Static);
				if (m != null)
				{
					_methods[methodName] = m;
					return m.Invoke(agent, args);
				}

				type = type.BaseType;
			}
			Debug.Check(false, "No method can be found!");
			return null;
		}
	}

	// Source file: node_test/action_noop_ut_0

	class Assignment_bt_node_test_action_noop_ut_0_node4 : behaviac.Assignment
	{
		public Assignment_bt_node_test_action_noop_ut_0_node4()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			int opr = 2;
			AgentExtra_Generated.SetProperty(pAgent, "testVar_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("testVar_0") == 2970758673u);
			pAgent.SetVariable<int>("testVar_0", opr, 2970758673u);
			return result;
		}
	}

	public static class bt_node_test_action_noop_ut_0
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/action_noop_ut_0");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Sequence node0 = new Sequence();
				node0.SetClassNameString("Sequence");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					Noop node2 = new Noop();
					node2.SetClassNameString("Noop");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				{
					Noop node1 = new Noop();
					node1.SetClassNameString("Noop");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					Assignment_bt_node_test_action_noop_ut_0_node4 node4 = new Assignment_bt_node_test_action_noop_ut_0_node4();
					node4.SetClassNameString("Assignment");
					node4.SetId(4);
#if !BEHAVIAC_RELEASE
					node4.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node4);
					node0.SetHasEvents(node0.HasEvents() | node4.HasEvents());
				}
				{
					Noop node3 = new Noop();
					node3.SetClassNameString("Noop");
					node3.SetId(3);
#if !BEHAVIAC_RELEASE
					node3.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node3);
					node0.SetHasEvents(node0.HasEvents() | node3.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/action_ut_0

	class Compute_bt_node_test_action_ut_0_node1 : behaviac.Compute
	{
		public Compute_bt_node_test_action_ut_0_node1()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			int opr1 = 1000;
			int opr2 = 500;
			int opr = (int)(opr1 + opr2);
			Debug.Check(behaviac.Utils.MakeVariableId("par_int_type_0") == 4028995106u);
			pAgent.SetVariable<int>("par_int_type_0", opr, 4028995106u);
			return result;
		}
	}

	class Action_bt_node_test_action_ut_0_node2 : behaviac.Action
	{
		public Action_bt_node_test_action_ut_0_node2()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			Debug.Check(behaviac.Utils.MakeVariableId("par_int_type_0") == 4028995106u);
			int method_p0 = pAgent.GetVariable<int>(4028995106u);
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Assignment_bt_node_test_action_ut_0_node3 : behaviac.Assignment
	{
		public Assignment_bt_node_test_action_ut_0_node3()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			int opr = ((AgentNodeTest)pAgent).testVar_0;
			Debug.Check(behaviac.Utils.MakeVariableId("par_int_type_1") == 3913197411u);
			pAgent.SetVariable<int>("par_int_type_1", opr, 3913197411u);
			return result;
		}
	}

	class Compute_bt_node_test_action_ut_0_node4 : behaviac.Compute
	{
		public Compute_bt_node_test_action_ut_0_node4()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par_int_type_1") == 3913197411u);
			int opr1 = pAgent.GetVariable<int>(3913197411u);
			Debug.Check(behaviac.Utils.MakeVariableId("par_int_type_2") == 3256087712u);
			int opr2 = pAgent.GetVariable<int>(3256087712u);
			int opr = (int)(opr1 + opr2);
			Debug.Check(behaviac.Utils.MakeVariableId("par_int_type_0") == 4028995106u);
			pAgent.SetVariable<int>("par_int_type_0", opr, 4028995106u);
			return result;
		}
	}

	class Action_bt_node_test_action_ut_0_node5 : behaviac.Action
	{
		public Action_bt_node_test_action_ut_0_node5()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			Debug.Check(behaviac.Utils.MakeVariableId("par_int_type_0") == 4028995106u);
			int method_p0 = pAgent.GetVariable<int>(4028995106u);
			((AgentNodeTest)pAgent).setTestVar_1(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_node_test_action_ut_0_node6 : behaviac.Action
	{
		public Action_bt_node_test_action_ut_0_node6()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			StaticAgent.sAction();
			return EBTStatus.BT_SUCCESS;
		}
	}

	public static class bt_node_test_action_ut_0
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/action_ut_0");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// pars
			bt.AddPar("int", "par_int_type_0", "0", "");
			bt.AddPar("int", "par_int_type_1", "0", "");
			bt.AddPar("int", "par_int_type_2", "300", "");
			// children
			{
				Sequence node0 = new Sequence();
				node0.SetClassNameString("Sequence");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					Compute_bt_node_test_action_ut_0_node1 node1 = new Compute_bt_node_test_action_ut_0_node1();
					node1.SetClassNameString("Compute");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					Action_bt_node_test_action_ut_0_node2 node2 = new Action_bt_node_test_action_ut_0_node2();
					node2.SetClassNameString("Action");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				{
					Assignment_bt_node_test_action_ut_0_node3 node3 = new Assignment_bt_node_test_action_ut_0_node3();
					node3.SetClassNameString("Assignment");
					node3.SetId(3);
#if !BEHAVIAC_RELEASE
					node3.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node3);
					node0.SetHasEvents(node0.HasEvents() | node3.HasEvents());
				}
				{
					Compute_bt_node_test_action_ut_0_node4 node4 = new Compute_bt_node_test_action_ut_0_node4();
					node4.SetClassNameString("Compute");
					node4.SetId(4);
#if !BEHAVIAC_RELEASE
					node4.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node4);
					node0.SetHasEvents(node0.HasEvents() | node4.HasEvents());
				}
				{
					Action_bt_node_test_action_ut_0_node5 node5 = new Action_bt_node_test_action_ut_0_node5();
					node5.SetClassNameString("Action");
					node5.SetId(5);
#if !BEHAVIAC_RELEASE
					node5.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node5);
					node0.SetHasEvents(node0.HasEvents() | node5.HasEvents());
				}
				{
					Action_bt_node_test_action_ut_0_node6 node6 = new Action_bt_node_test_action_ut_0_node6();
					node6.SetClassNameString("Action");
					node6.SetId(6);
#if !BEHAVIAC_RELEASE
					node6.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node6);
					node0.SetHasEvents(node0.HasEvents() | node6.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/action_ut_1

	class Compute_bt_node_test_action_ut_1_node3 : behaviac.Compute
	{
		public Compute_bt_node_test_action_ut_1_node3()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			float opr1 = 0.5f;
			float opr2 = 1.3f;
			float opr = (float)(opr1 + opr2);
			Debug.Check(behaviac.Utils.MakeVariableId("par_float_type_0") == 569873069u);
			pAgent.SetVariable<float>("par_float_type_0", opr, 569873069u);
			return result;
		}
	}

	class Action_bt_node_test_action_ut_1_node2 : behaviac.Action
	{
		public Action_bt_node_test_action_ut_1_node2()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			Debug.Check(behaviac.Utils.MakeVariableId("par_float_type_0") == 569873069u);
			float method_p0 = pAgent.GetVariable<float>(569873069u);
			((AgentNodeTest)pAgent).setTestVar_2(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Assignment_bt_node_test_action_ut_1_node1 : behaviac.Assignment
	{
		public Assignment_bt_node_test_action_ut_1_node1()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			float opr = ((AgentNodeTest)pAgent).testVar_2;
			Debug.Check(behaviac.Utils.MakeVariableId("par_float_type_1") == 955032556u);
			pAgent.SetVariable<float>("par_float_type_1", opr, 955032556u);
			return result;
		}
	}

	class Compute_bt_node_test_action_ut_1_node4 : behaviac.Compute
	{
		public Compute_bt_node_test_action_ut_1_node4()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par_float_type_1") == 955032556u);
			float opr1 = pAgent.GetVariable<float>(955032556u);
			Debug.Check(behaviac.Utils.MakeVariableId("par_float_type_2") == 331477039u);
			float opr2 = pAgent.GetVariable<float>(331477039u);
			float opr = (float)(opr1 + opr2);
			Debug.Check(behaviac.Utils.MakeVariableId("par_float_type_0") == 569873069u);
			pAgent.SetVariable<float>("par_float_type_0", opr, 569873069u);
			return result;
		}
	}

	class Action_bt_node_test_action_ut_1_node5 : behaviac.Action
	{
		public Action_bt_node_test_action_ut_1_node5()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			Debug.Check(behaviac.Utils.MakeVariableId("par_float_type_0") == 569873069u);
			float method_p0 = pAgent.GetVariable<float>(569873069u);
			((AgentNodeTest)pAgent).setTestVar_3(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Assignment_bt_node_test_action_ut_1_node7 : behaviac.Assignment
	{
		public Assignment_bt_node_test_action_ut_1_node7()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			UnityEngine.GameObject opr = (UnityEngine.GameObject)((AgentNodeTest)pAgent).createGameObject();
			Debug.Check(behaviac.Utils.MakeVariableId("par_go") == 464621558u);
			pAgent.SetVariable<UnityEngine.GameObject>("par_go", opr, 464621558u);
			return result;
		}
	}

	class Action_bt_node_test_action_ut_1_node6 : behaviac.Action
	{
		public Action_bt_node_test_action_ut_1_node6()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			Debug.Check(behaviac.Utils.MakeVariableId("par_go") == 464621558u);
			UnityEngine.GameObject method_p0 = pAgent.GetVariable<UnityEngine.GameObject>(464621558u);
			((AgentNodeTest)pAgent).testGameObject(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
	}

	public static class bt_node_test_action_ut_1
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/action_ut_1");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// pars
			bt.AddPar("float", "par_float_type_0", "0", "");
			bt.AddPar("float", "par_float_type_1", "0", "");
			bt.AddPar("float", "par_float_type_2", "2.7", "");
			bt.AddPar("UnityEngine.GameObject", "par_go", "null", "");
			// children
			{
				Sequence node0 = new Sequence();
				node0.SetClassNameString("Sequence");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					Compute_bt_node_test_action_ut_1_node3 node3 = new Compute_bt_node_test_action_ut_1_node3();
					node3.SetClassNameString("Compute");
					node3.SetId(3);
#if !BEHAVIAC_RELEASE
					node3.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node3);
					node0.SetHasEvents(node0.HasEvents() | node3.HasEvents());
				}
				{
					Action_bt_node_test_action_ut_1_node2 node2 = new Action_bt_node_test_action_ut_1_node2();
					node2.SetClassNameString("Action");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				{
					Assignment_bt_node_test_action_ut_1_node1 node1 = new Assignment_bt_node_test_action_ut_1_node1();
					node1.SetClassNameString("Assignment");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					Compute_bt_node_test_action_ut_1_node4 node4 = new Compute_bt_node_test_action_ut_1_node4();
					node4.SetClassNameString("Compute");
					node4.SetId(4);
#if !BEHAVIAC_RELEASE
					node4.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node4);
					node0.SetHasEvents(node0.HasEvents() | node4.HasEvents());
				}
				{
					Action_bt_node_test_action_ut_1_node5 node5 = new Action_bt_node_test_action_ut_1_node5();
					node5.SetClassNameString("Action");
					node5.SetId(5);
#if !BEHAVIAC_RELEASE
					node5.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node5);
					node0.SetHasEvents(node0.HasEvents() | node5.HasEvents());
				}
				{
					Assignment_bt_node_test_action_ut_1_node7 node7 = new Assignment_bt_node_test_action_ut_1_node7();
					node7.SetClassNameString("Assignment");
					node7.SetId(7);
#if !BEHAVIAC_RELEASE
					node7.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node7);
					node0.SetHasEvents(node0.HasEvents() | node7.HasEvents());
				}
				{
					Action_bt_node_test_action_ut_1_node6 node6 = new Action_bt_node_test_action_ut_1_node6();
					node6.SetClassNameString("Action");
					node6.SetId(6);
#if !BEHAVIAC_RELEASE
					node6.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node6);
					node0.SetHasEvents(node0.HasEvents() | node6.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/action_ut_2

	class Compute_bt_node_test_action_ut_2_node1 : behaviac.Compute
	{
		public Compute_bt_node_test_action_ut_2_node1()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			int opr1 = 1000;
			int opr2 = 500;
			int opr = (int)(opr1 * opr2);
			Debug.Check(behaviac.Utils.MakeVariableId("par_int_type_0") == 4028995106u);
			pAgent.SetVariable<int>("par_int_type_0", opr, 4028995106u);
			return result;
		}
	}

	class Action_bt_node_test_action_ut_2_node2 : behaviac.Action
	{
		public Action_bt_node_test_action_ut_2_node2()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			Debug.Check(behaviac.Utils.MakeVariableId("par_int_type_0") == 4028995106u);
			int method_p0 = pAgent.GetVariable<int>(4028995106u);
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Assignment_bt_node_test_action_ut_2_node3 : behaviac.Assignment
	{
		public Assignment_bt_node_test_action_ut_2_node3()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			int opr = ((AgentNodeTest)pAgent).testVar_0;
			Debug.Check(behaviac.Utils.MakeVariableId("par_int_type_1") == 3913197411u);
			pAgent.SetVariable<int>("par_int_type_1", opr, 3913197411u);
			return result;
		}
	}

	class Compute_bt_node_test_action_ut_2_node4 : behaviac.Compute
	{
		public Compute_bt_node_test_action_ut_2_node4()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par_int_type_1") == 3913197411u);
			int opr1 = pAgent.GetVariable<int>(3913197411u);
			Debug.Check(behaviac.Utils.MakeVariableId("par_int_type_2") == 3256087712u);
			int opr2 = pAgent.GetVariable<int>(3256087712u);
			int opr = (int)(opr1 / opr2);
			Debug.Check(behaviac.Utils.MakeVariableId("par_int_type_0") == 4028995106u);
			pAgent.SetVariable<int>("par_int_type_0", opr, 4028995106u);
			return result;
		}
	}

	class Action_bt_node_test_action_ut_2_node5 : behaviac.Action
	{
		public Action_bt_node_test_action_ut_2_node5()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			Debug.Check(behaviac.Utils.MakeVariableId("par_int_type_0") == 4028995106u);
			int method_p0 = pAgent.GetVariable<int>(4028995106u);
			((AgentNodeTest)pAgent).setTestVar_1(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
	}

	public static class bt_node_test_action_ut_2
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/action_ut_2");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// pars
			bt.AddPar("int", "par_int_type_0", "0", "");
			bt.AddPar("int", "par_int_type_1", "0", "");
			bt.AddPar("int", "par_int_type_2", "300", "");
			// children
			{
				Sequence node0 = new Sequence();
				node0.SetClassNameString("Sequence");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					Compute_bt_node_test_action_ut_2_node1 node1 = new Compute_bt_node_test_action_ut_2_node1();
					node1.SetClassNameString("Compute");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					Action_bt_node_test_action_ut_2_node2 node2 = new Action_bt_node_test_action_ut_2_node2();
					node2.SetClassNameString("Action");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				{
					Assignment_bt_node_test_action_ut_2_node3 node3 = new Assignment_bt_node_test_action_ut_2_node3();
					node3.SetClassNameString("Assignment");
					node3.SetId(3);
#if !BEHAVIAC_RELEASE
					node3.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node3);
					node0.SetHasEvents(node0.HasEvents() | node3.HasEvents());
				}
				{
					Compute_bt_node_test_action_ut_2_node4 node4 = new Compute_bt_node_test_action_ut_2_node4();
					node4.SetClassNameString("Compute");
					node4.SetId(4);
#if !BEHAVIAC_RELEASE
					node4.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node4);
					node0.SetHasEvents(node0.HasEvents() | node4.HasEvents());
				}
				{
					Action_bt_node_test_action_ut_2_node5 node5 = new Action_bt_node_test_action_ut_2_node5();
					node5.SetClassNameString("Action");
					node5.SetId(5);
#if !BEHAVIAC_RELEASE
					node5.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node5);
					node0.SetHasEvents(node0.HasEvents() | node5.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/action_ut_3

	class Compute_bt_node_test_action_ut_3_node3 : behaviac.Compute
	{
		public Compute_bt_node_test_action_ut_3_node3()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			float opr1 = 0.5f;
			float opr2 = 4.8f;
			float opr = (float)(opr1 * opr2);
			Debug.Check(behaviac.Utils.MakeVariableId("par_float_type_0") == 569873069u);
			pAgent.SetVariable<float>("par_float_type_0", opr, 569873069u);
			return result;
		}
	}

	class Action_bt_node_test_action_ut_3_node2 : behaviac.Action
	{
		public Action_bt_node_test_action_ut_3_node2()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			Debug.Check(behaviac.Utils.MakeVariableId("par_float_type_0") == 569873069u);
			float method_p0 = pAgent.GetVariable<float>(569873069u);
			((AgentNodeTest)pAgent).setTestVar_2(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Assignment_bt_node_test_action_ut_3_node1 : behaviac.Assignment
	{
		public Assignment_bt_node_test_action_ut_3_node1()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			float opr = ((AgentNodeTest)pAgent).testVar_2;
			Debug.Check(behaviac.Utils.MakeVariableId("par_float_type_1") == 955032556u);
			pAgent.SetVariable<float>("par_float_type_1", opr, 955032556u);
			return result;
		}
	}

	class Compute_bt_node_test_action_ut_3_node4 : behaviac.Compute
	{
		public Compute_bt_node_test_action_ut_3_node4()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par_float_type_1") == 955032556u);
			float opr1 = pAgent.GetVariable<float>(955032556u);
			Debug.Check(behaviac.Utils.MakeVariableId("par_float_type_2") == 331477039u);
			float opr2 = pAgent.GetVariable<float>(331477039u);
			float opr = (float)(opr1 / opr2);
			Debug.Check(behaviac.Utils.MakeVariableId("par_float_type_0") == 569873069u);
			pAgent.SetVariable<float>("par_float_type_0", opr, 569873069u);
			return result;
		}
	}

	class Action_bt_node_test_action_ut_3_node5 : behaviac.Action
	{
		public Action_bt_node_test_action_ut_3_node5()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			Debug.Check(behaviac.Utils.MakeVariableId("par_float_type_0") == 569873069u);
			float method_p0 = pAgent.GetVariable<float>(569873069u);
			((AgentNodeTest)pAgent).setTestVar_3(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
	}

	public static class bt_node_test_action_ut_3
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/action_ut_3");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// pars
			bt.AddPar("float", "par_float_type_0", "0", "");
			bt.AddPar("float", "par_float_type_1", "0", "");
			bt.AddPar("float", "par_float_type_2", "0.6", "");
			// children
			{
				Sequence node0 = new Sequence();
				node0.SetClassNameString("Sequence");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					Compute_bt_node_test_action_ut_3_node3 node3 = new Compute_bt_node_test_action_ut_3_node3();
					node3.SetClassNameString("Compute");
					node3.SetId(3);
#if !BEHAVIAC_RELEASE
					node3.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node3);
					node0.SetHasEvents(node0.HasEvents() | node3.HasEvents());
				}
				{
					Action_bt_node_test_action_ut_3_node2 node2 = new Action_bt_node_test_action_ut_3_node2();
					node2.SetClassNameString("Action");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				{
					Assignment_bt_node_test_action_ut_3_node1 node1 = new Assignment_bt_node_test_action_ut_3_node1();
					node1.SetClassNameString("Assignment");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					Compute_bt_node_test_action_ut_3_node4 node4 = new Compute_bt_node_test_action_ut_3_node4();
					node4.SetClassNameString("Compute");
					node4.SetId(4);
#if !BEHAVIAC_RELEASE
					node4.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node4);
					node0.SetHasEvents(node0.HasEvents() | node4.HasEvents());
				}
				{
					Action_bt_node_test_action_ut_3_node5 node5 = new Action_bt_node_test_action_ut_3_node5();
					node5.SetClassNameString("Action");
					node5.SetId(5);
#if !BEHAVIAC_RELEASE
					node5.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node5);
					node0.SetHasEvents(node0.HasEvents() | node5.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/action_ut_waitforsignal_0

	class Predicate_bt_node_test_action_ut_waitforsignal_0_attach2 : behaviac.Predicate
	{
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_FAILURE;
			this.m_bAnd = true;
			int opl = ((AgentNodeTest)pAgent).testVar_0;
			int opr = 0;
			bool op = opl == opr;
			if (op)
				result = EBTStatus.BT_SUCCESS;
			return result;
		}
	}

	class Assignment_bt_node_test_action_ut_waitforsignal_0_node3 : behaviac.Assignment
	{
		public Assignment_bt_node_test_action_ut_waitforsignal_0_node3()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			int opr = 1;
			AgentExtra_Generated.SetProperty(pAgent, "testVar_1", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("testVar_1") == 2819170128u);
			pAgent.SetVariable<int>("testVar_1", opr, 2819170128u);
			return result;
		}
	}

	class Assignment_bt_node_test_action_ut_waitforsignal_0_node4 : behaviac.Assignment
	{
		public Assignment_bt_node_test_action_ut_waitforsignal_0_node4()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			float opr = 2.3f;
			AgentExtra_Generated.SetProperty(pAgent, "testVar_2", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("testVar_2") == 2200194195u);
			pAgent.SetVariable<float>("testVar_2", opr, 2200194195u);
			return result;
		}
	}

	public static class bt_node_test_action_ut_waitforsignal_0
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/action_ut_waitforsignal_0");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Sequence node0 = new Sequence();
				node0.SetClassNameString("Sequence");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					WaitforSignal node1 = new WaitforSignal();
					node1.SetClassNameString("WaitforSignal");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					// attachments
					{
						Predicate_bt_node_test_action_ut_waitforsignal_0_attach2 attach2 = new Predicate_bt_node_test_action_ut_waitforsignal_0_attach2();
						attach2.SetClassNameString("Predicate");
						attach2.SetId(2);
#if !BEHAVIAC_RELEASE
						attach2.SetAgentType("AgentNodeTest");
#endif
						node1.Attach(attach2);
					}
					node0.AddChild(node1);
					{
						Assignment_bt_node_test_action_ut_waitforsignal_0_node3 node3 = new Assignment_bt_node_test_action_ut_waitforsignal_0_node3();
						node3.SetClassNameString("Assignment");
						node3.SetId(3);
#if !BEHAVIAC_RELEASE
						node3.SetAgentType("AgentNodeTest");
#endif
						node1.AddChild(node3);
						node1.SetHasEvents(node1.HasEvents() | node3.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					Assignment_bt_node_test_action_ut_waitforsignal_0_node4 node4 = new Assignment_bt_node_test_action_ut_waitforsignal_0_node4();
					node4.SetClassNameString("Assignment");
					node4.SetId(4);
#if !BEHAVIAC_RELEASE
					node4.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node4);
					node0.SetHasEvents(node0.HasEvents() | node4.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/action_ut_waitforsignal_1

	class Predicate_bt_node_test_action_ut_waitforsignal_1_attach2 : behaviac.Predicate
	{
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_FAILURE;
			this.m_bAnd = true;
			int opl = ((AgentNodeTest)pAgent).testVar_0;
			int opr = 0;
			bool op = opl == opr;
			if (op)
				result = EBTStatus.BT_SUCCESS;
			return result;
		}
	}

	class Predicate_bt_node_test_action_ut_waitforsignal_1_attach5 : behaviac.Predicate
	{
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_FAILURE;
			this.m_bAnd = true;
			int opl = ((AgentNodeTest)pAgent).testVar_1;
			int opr = 0;
			bool op = opl == opr;
			if (op)
				result = EBTStatus.BT_SUCCESS;
			return result;
		}
	}

	class Predicate_bt_node_test_action_ut_waitforsignal_1_attach6 : behaviac.Predicate
	{
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_FAILURE;
			this.m_bAnd = false;
			float opl = ((AgentNodeTest)pAgent).testVar_2;
			float opr = 0f;
			bool op = opl == opr;
			if (op)
				result = EBTStatus.BT_SUCCESS;
			return result;
		}
	}

	class Assignment_bt_node_test_action_ut_waitforsignal_1_node3 : behaviac.Assignment
	{
		public Assignment_bt_node_test_action_ut_waitforsignal_1_node3()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			int opr = 1;
			AgentExtra_Generated.SetProperty(pAgent, "testVar_1", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("testVar_1") == 2819170128u);
			pAgent.SetVariable<int>("testVar_1", opr, 2819170128u);
			return result;
		}
	}

	class Assignment_bt_node_test_action_ut_waitforsignal_1_node4 : behaviac.Assignment
	{
		public Assignment_bt_node_test_action_ut_waitforsignal_1_node4()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			float opr = 2.3f;
			AgentExtra_Generated.SetProperty(pAgent, "testVar_2", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("testVar_2") == 2200194195u);
			pAgent.SetVariable<float>("testVar_2", opr, 2200194195u);
			return result;
		}
	}

	public static class bt_node_test_action_ut_waitforsignal_1
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/action_ut_waitforsignal_1");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Sequence node0 = new Sequence();
				node0.SetClassNameString("Sequence");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					WaitforSignal node1 = new WaitforSignal();
					node1.SetClassNameString("WaitforSignal");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					// attachments
					{
						Predicate_bt_node_test_action_ut_waitforsignal_1_attach2 attach2 = new Predicate_bt_node_test_action_ut_waitforsignal_1_attach2();
						attach2.SetClassNameString("Predicate");
						attach2.SetId(2);
#if !BEHAVIAC_RELEASE
						attach2.SetAgentType("AgentNodeTest");
#endif
						node1.Attach(attach2);
					}
					{
						Predicate_bt_node_test_action_ut_waitforsignal_1_attach5 attach5 = new Predicate_bt_node_test_action_ut_waitforsignal_1_attach5();
						attach5.SetClassNameString("Predicate");
						attach5.SetId(5);
#if !BEHAVIAC_RELEASE
						attach5.SetAgentType("AgentNodeTest");
#endif
						node1.Attach(attach5);
					}
					{
						Predicate_bt_node_test_action_ut_waitforsignal_1_attach6 attach6 = new Predicate_bt_node_test_action_ut_waitforsignal_1_attach6();
						attach6.SetClassNameString("Predicate");
						attach6.SetId(6);
#if !BEHAVIAC_RELEASE
						attach6.SetAgentType("AgentNodeTest");
#endif
						node1.Attach(attach6);
					}
					node0.AddChild(node1);
					{
						Assignment_bt_node_test_action_ut_waitforsignal_1_node3 node3 = new Assignment_bt_node_test_action_ut_waitforsignal_1_node3();
						node3.SetClassNameString("Assignment");
						node3.SetId(3);
#if !BEHAVIAC_RELEASE
						node3.SetAgentType("AgentNodeTest");
#endif
						node1.AddChild(node3);
						node1.SetHasEvents(node1.HasEvents() | node3.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					Assignment_bt_node_test_action_ut_waitforsignal_1_node4 node4 = new Assignment_bt_node_test_action_ut_waitforsignal_1_node4();
					node4.SetClassNameString("Assignment");
					node4.SetId(4);
#if !BEHAVIAC_RELEASE
					node4.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node4);
					node0.SetHasEvents(node0.HasEvents() | node4.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/action_ut_waitforsignal_2

	class Predicate_bt_node_test_action_ut_waitforsignal_2_attach2 : behaviac.Predicate
	{
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_FAILURE;
			this.m_bAnd = true;
			int opl = ((AgentNodeTest)pAgent).testVar_0;
			int opr = 0;
			bool op = opl == opr;
			if (op)
				result = EBTStatus.BT_SUCCESS;
			return result;
		}
	}

	class Predicate_bt_node_test_action_ut_waitforsignal_2_attach5 : behaviac.Predicate
	{
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_FAILURE;
			this.m_bAnd = true;
			int opl = ((AgentNodeTest)pAgent).testVar_1;
			int opr = 0;
			bool op = opl == opr;
			if (op)
				result = EBTStatus.BT_SUCCESS;
			return result;
		}
	}

	class Predicate_bt_node_test_action_ut_waitforsignal_2_attach6 : behaviac.Predicate
	{
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_FAILURE;
			this.m_bAnd = false;
			float opl = ((AgentNodeTest)pAgent).testVar_2;
			float opr = 0f;
			bool op = opl == opr;
			if (op)
				result = EBTStatus.BT_SUCCESS;
			return result;
		}
	}

	class Assignment_bt_node_test_action_ut_waitforsignal_2_node4 : behaviac.Assignment
	{
		public Assignment_bt_node_test_action_ut_waitforsignal_2_node4()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			float opr = 2.3f;
			AgentExtra_Generated.SetProperty(pAgent, "testVar_2", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("testVar_2") == 2200194195u);
			pAgent.SetVariable<float>("testVar_2", opr, 2200194195u);
			return result;
		}
	}

	public static class bt_node_test_action_ut_waitforsignal_2
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/action_ut_waitforsignal_2");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Sequence node0 = new Sequence();
				node0.SetClassNameString("Sequence");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					WaitforSignal node1 = new WaitforSignal();
					node1.SetClassNameString("WaitforSignal");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					// attachments
					{
						Predicate_bt_node_test_action_ut_waitforsignal_2_attach2 attach2 = new Predicate_bt_node_test_action_ut_waitforsignal_2_attach2();
						attach2.SetClassNameString("Predicate");
						attach2.SetId(2);
#if !BEHAVIAC_RELEASE
						attach2.SetAgentType("AgentNodeTest");
#endif
						node1.Attach(attach2);
					}
					{
						Predicate_bt_node_test_action_ut_waitforsignal_2_attach5 attach5 = new Predicate_bt_node_test_action_ut_waitforsignal_2_attach5();
						attach5.SetClassNameString("Predicate");
						attach5.SetId(5);
#if !BEHAVIAC_RELEASE
						attach5.SetAgentType("AgentNodeTest");
#endif
						node1.Attach(attach5);
					}
					{
						Predicate_bt_node_test_action_ut_waitforsignal_2_attach6 attach6 = new Predicate_bt_node_test_action_ut_waitforsignal_2_attach6();
						attach6.SetClassNameString("Predicate");
						attach6.SetId(6);
#if !BEHAVIAC_RELEASE
						attach6.SetAgentType("AgentNodeTest");
#endif
						node1.Attach(attach6);
					}
					node0.AddChild(node1);
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					Assignment_bt_node_test_action_ut_waitforsignal_2_node4 node4 = new Assignment_bt_node_test_action_ut_waitforsignal_2_node4();
					node4.SetClassNameString("Assignment");
					node4.SetId(4);
#if !BEHAVIAC_RELEASE
					node4.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node4);
					node0.SetHasEvents(node0.HasEvents() | node4.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/action_waitframes_ut_0

	class Assignment_bt_node_test_action_waitframes_ut_0_node3 : behaviac.Assignment
	{
		public Assignment_bt_node_test_action_waitframes_ut_0_node3()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			int opr = 1;
			AgentExtra_Generated.SetProperty(pAgent, "testVar_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("testVar_0") == 2970758673u);
			pAgent.SetVariable<int>("testVar_0", opr, 2970758673u);
			return result;
		}
	}

	class WaitFrames_bt_node_test_action_waitframes_ut_0_node1 : behaviac.WaitFrames
	{
		public WaitFrames_bt_node_test_action_waitframes_ut_0_node1()
		{
		}
		protected override int GetFrames(Agent pAgent)
		{
			Debug.Check(behaviac.Utils.MakeVariableId("par_frame_count") == 4259617405u);
			return pAgent.GetVariable<int>(4259617405u);
		}
	}

	class Assignment_bt_node_test_action_waitframes_ut_0_node4 : behaviac.Assignment
	{
		public Assignment_bt_node_test_action_waitframes_ut_0_node4()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			int opr = 2;
			AgentExtra_Generated.SetProperty(pAgent, "testVar_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("testVar_0") == 2970758673u);
			pAgent.SetVariable<int>("testVar_0", opr, 2970758673u);
			return result;
		}
	}

	public static class bt_node_test_action_waitframes_ut_0
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/action_waitframes_ut_0");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// pars
			bt.AddPar("int", "par_frame_count", "5", "");
			// children
			{
				Sequence node0 = new Sequence();
				node0.SetClassNameString("Sequence");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					Assignment_bt_node_test_action_waitframes_ut_0_node3 node3 = new Assignment_bt_node_test_action_waitframes_ut_0_node3();
					node3.SetClassNameString("Assignment");
					node3.SetId(3);
#if !BEHAVIAC_RELEASE
					node3.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node3);
					node0.SetHasEvents(node0.HasEvents() | node3.HasEvents());
				}
				{
					WaitFrames_bt_node_test_action_waitframes_ut_0_node1 node1 = new WaitFrames_bt_node_test_action_waitframes_ut_0_node1();
					node1.SetClassNameString("WaitFrames");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					Assignment_bt_node_test_action_waitframes_ut_0_node4 node4 = new Assignment_bt_node_test_action_waitframes_ut_0_node4();
					node4.SetClassNameString("Assignment");
					node4.SetId(4);
#if !BEHAVIAC_RELEASE
					node4.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node4);
					node0.SetHasEvents(node0.HasEvents() | node4.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/circular_ut_0

	class Condition_bt_node_test_circular_ut_0_node5 : behaviac.Condition
	{
		public Condition_bt_node_test_circular_ut_0_node5()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			int opl = ((AgentNodeTest)pAgent).testVar_0;
			int opr = 0;
			bool op = opl == opr;
			return op ? EBTStatus.BT_SUCCESS : EBTStatus.BT_FAILURE;
		}
	}

	class Assignment_bt_node_test_circular_ut_0_node3 : behaviac.Assignment
	{
		public Assignment_bt_node_test_circular_ut_0_node3()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			int opr = 1;
			AgentExtra_Generated.SetProperty(pAgent, "testVar_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("testVar_0") == 2970758673u);
			pAgent.SetVariable<int>("testVar_0", opr, 2970758673u);
			return result;
		}
	}

	class ReferencedBehavior_bt_node_test_circular_ut_0_node6 : behaviac.ReferencedBehavior
	{
		public ReferencedBehavior_bt_node_test_circular_ut_0_node6()
		{
			m_referencedBehaviorPath = "node_test/circular_ut_0";
			bool result = Workspace.Load(this.m_referencedBehaviorPath);
			Debug.Check(result);
		}
	}

	class Action_bt_node_test_circular_ut_0_node1 : behaviac.Action
	{
		public Action_bt_node_test_circular_ut_0_node1()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_1(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	public static class bt_node_test_circular_ut_0
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/circular_ut_0");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Selector node0 = new Selector();
				node0.SetClassNameString("Selector");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					Sequence node2 = new Sequence();
					node2.SetClassNameString("Sequence");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					{
						Condition_bt_node_test_circular_ut_0_node5 node5 = new Condition_bt_node_test_circular_ut_0_node5();
						node5.SetClassNameString("Condition");
						node5.SetId(5);
#if !BEHAVIAC_RELEASE
						node5.SetAgentType("AgentNodeTest");
#endif
						node2.AddChild(node5);
						node2.SetHasEvents(node2.HasEvents() | node5.HasEvents());
					}
					{
						Sequence node4 = new Sequence();
						node4.SetClassNameString("Sequence");
						node4.SetId(4);
#if !BEHAVIAC_RELEASE
						node4.SetAgentType("AgentNodeTest");
#endif
						node2.AddChild(node4);
						{
							Assignment_bt_node_test_circular_ut_0_node3 node3 = new Assignment_bt_node_test_circular_ut_0_node3();
							node3.SetClassNameString("Assignment");
							node3.SetId(3);
#if !BEHAVIAC_RELEASE
							node3.SetAgentType("AgentNodeTest");
#endif
							node4.AddChild(node3);
							node4.SetHasEvents(node4.HasEvents() | node3.HasEvents());
						}
						{
							ReferencedBehavior_bt_node_test_circular_ut_0_node6 node6 = new ReferencedBehavior_bt_node_test_circular_ut_0_node6();
							node6.SetClassNameString("ReferencedBehavior");
							node6.SetId(6);
#if !BEHAVIAC_RELEASE
							node6.SetAgentType("AgentNodeTest");
#endif
							node4.AddChild(node6);
							node4.SetHasEvents(node4.HasEvents() | node6.HasEvents());
						}
						node2.SetHasEvents(node2.HasEvents() | node4.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				{
					Action_bt_node_test_circular_ut_0_node1 node1 = new Action_bt_node_test_circular_ut_0_node1();
					node1.SetClassNameString("Action");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/condition_ut_0

	class Condition_bt_node_test_condition_ut_0_node1 : behaviac.Condition
	{
		public Condition_bt_node_test_condition_ut_0_node1()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			int opl = ((AgentNodeTest)pAgent).testVar_0;
			int opr = -1;
			bool op = opl == opr;
			return op ? EBTStatus.BT_SUCCESS : EBTStatus.BT_FAILURE;
		}
	}

	class Action_bt_node_test_condition_ut_0_node2 : behaviac.Action
	{
		public Action_bt_node_test_condition_ut_0_node2()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Condition_bt_node_test_condition_ut_0_node3 : behaviac.Condition
	{
		public Condition_bt_node_test_condition_ut_0_node3()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			int opl = ((AgentNodeTest)pAgent).testVar_0;
			int opr = 1;
			bool op = opl == opr;
			return op ? EBTStatus.BT_SUCCESS : EBTStatus.BT_FAILURE;
		}
	}

	class Action_bt_node_test_condition_ut_0_node4 : behaviac.Action
	{
		public Action_bt_node_test_condition_ut_0_node4()
		{
			method_p0 = 2;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	public static class bt_node_test_condition_ut_0
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/condition_ut_0");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Sequence node0 = new Sequence();
				node0.SetClassNameString("Sequence");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					Condition_bt_node_test_condition_ut_0_node1 node1 = new Condition_bt_node_test_condition_ut_0_node1();
					node1.SetClassNameString("Condition");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					Action_bt_node_test_condition_ut_0_node2 node2 = new Action_bt_node_test_condition_ut_0_node2();
					node2.SetClassNameString("Action");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				{
					Condition_bt_node_test_condition_ut_0_node3 node3 = new Condition_bt_node_test_condition_ut_0_node3();
					node3.SetClassNameString("Condition");
					node3.SetId(3);
#if !BEHAVIAC_RELEASE
					node3.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node3);
					node0.SetHasEvents(node0.HasEvents() | node3.HasEvents());
				}
				{
					Action_bt_node_test_condition_ut_0_node4 node4 = new Action_bt_node_test_condition_ut_0_node4();
					node4.SetClassNameString("Action");
					node4.SetId(4);
#if !BEHAVIAC_RELEASE
					node4.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node4);
					node0.SetHasEvents(node0.HasEvents() | node4.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/condition_ut_1

	class Action_bt_node_test_condition_ut_1_node2 : behaviac.Action
	{
		public Action_bt_node_test_condition_ut_1_node2()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Action_bt_node_test_condition_ut_1_node8 : behaviac.Action
	{
		public Action_bt_node_test_condition_ut_1_node8()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	public static class bt_node_test_condition_ut_1
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/condition_ut_1");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Sequence node0 = new Sequence();
				node0.SetClassNameString("Sequence");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					Or node9 = new Or();
					node9.SetClassNameString("Or");
					node9.SetId(9);
#if !BEHAVIAC_RELEASE
					node9.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node9);
					{
						True node10 = new True();
						node10.SetClassNameString("True");
						node10.SetId(10);
#if !BEHAVIAC_RELEASE
						node10.SetAgentType("AgentNodeTest");
#endif
						node9.AddChild(node10);
						node9.SetHasEvents(node9.HasEvents() | node10.HasEvents());
					}
					{
						True node11 = new True();
						node11.SetClassNameString("True");
						node11.SetId(11);
#if !BEHAVIAC_RELEASE
						node11.SetAgentType("AgentNodeTest");
#endif
						node9.AddChild(node11);
						node9.SetHasEvents(node9.HasEvents() | node11.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node9.HasEvents());
				}
				{
					Or node1 = new Or();
					node1.SetClassNameString("Or");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					{
						True node3 = new True();
						node3.SetClassNameString("True");
						node3.SetId(3);
#if !BEHAVIAC_RELEASE
						node3.SetAgentType("AgentNodeTest");
#endif
						node1.AddChild(node3);
						node1.SetHasEvents(node1.HasEvents() | node3.HasEvents());
					}
					{
						False node5 = new False();
						node5.SetClassNameString("False");
						node5.SetId(5);
#if !BEHAVIAC_RELEASE
						node5.SetAgentType("AgentNodeTest");
#endif
						node1.AddChild(node5);
						node1.SetHasEvents(node1.HasEvents() | node5.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					Action_bt_node_test_condition_ut_1_node2 node2 = new Action_bt_node_test_condition_ut_1_node2();
					node2.SetClassNameString("Action");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				{
					Or node4 = new Or();
					node4.SetClassNameString("Or");
					node4.SetId(4);
#if !BEHAVIAC_RELEASE
					node4.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node4);
					{
						False node6 = new False();
						node6.SetClassNameString("False");
						node6.SetId(6);
#if !BEHAVIAC_RELEASE
						node6.SetAgentType("AgentNodeTest");
#endif
						node4.AddChild(node6);
						node4.SetHasEvents(node4.HasEvents() | node6.HasEvents());
					}
					{
						False node7 = new False();
						node7.SetClassNameString("False");
						node7.SetId(7);
#if !BEHAVIAC_RELEASE
						node7.SetAgentType("AgentNodeTest");
#endif
						node4.AddChild(node7);
						node4.SetHasEvents(node4.HasEvents() | node7.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node4.HasEvents());
				}
				{
					Action_bt_node_test_condition_ut_1_node8 node8 = new Action_bt_node_test_condition_ut_1_node8();
					node8.SetClassNameString("Action");
					node8.SetId(8);
#if !BEHAVIAC_RELEASE
					node8.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node8);
					node0.SetHasEvents(node0.HasEvents() | node8.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/condition_ut_2

	class Action_bt_node_test_condition_ut_2_node2 : behaviac.Action
	{
		public Action_bt_node_test_condition_ut_2_node2()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Action_bt_node_test_condition_ut_2_node8 : behaviac.Action
	{
		public Action_bt_node_test_condition_ut_2_node8()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Action_bt_node_test_condition_ut_2_node12 : behaviac.Action
	{
		public Action_bt_node_test_condition_ut_2_node12()
		{
			method_p0 = 2;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	public static class bt_node_test_condition_ut_2
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/condition_ut_2");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Sequence node0 = new Sequence();
				node0.SetClassNameString("Sequence");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					And node9 = new And();
					node9.SetClassNameString("And");
					node9.SetId(9);
#if !BEHAVIAC_RELEASE
					node9.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node9);
					{
						True node10 = new True();
						node10.SetClassNameString("True");
						node10.SetId(10);
#if !BEHAVIAC_RELEASE
						node10.SetAgentType("AgentNodeTest");
#endif
						node9.AddChild(node10);
						node9.SetHasEvents(node9.HasEvents() | node10.HasEvents());
					}
					{
						True node11 = new True();
						node11.SetClassNameString("True");
						node11.SetId(11);
#if !BEHAVIAC_RELEASE
						node11.SetAgentType("AgentNodeTest");
#endif
						node9.AddChild(node11);
						node9.SetHasEvents(node9.HasEvents() | node11.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node9.HasEvents());
				}
				{
					Action_bt_node_test_condition_ut_2_node2 node2 = new Action_bt_node_test_condition_ut_2_node2();
					node2.SetClassNameString("Action");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				{
					And node1 = new And();
					node1.SetClassNameString("And");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					{
						True node3 = new True();
						node3.SetClassNameString("True");
						node3.SetId(3);
#if !BEHAVIAC_RELEASE
						node3.SetAgentType("AgentNodeTest");
#endif
						node1.AddChild(node3);
						node1.SetHasEvents(node1.HasEvents() | node3.HasEvents());
					}
					{
						False node5 = new False();
						node5.SetClassNameString("False");
						node5.SetId(5);
#if !BEHAVIAC_RELEASE
						node5.SetAgentType("AgentNodeTest");
#endif
						node1.AddChild(node5);
						node1.SetHasEvents(node1.HasEvents() | node5.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					Action_bt_node_test_condition_ut_2_node8 node8 = new Action_bt_node_test_condition_ut_2_node8();
					node8.SetClassNameString("Action");
					node8.SetId(8);
#if !BEHAVIAC_RELEASE
					node8.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node8);
					node0.SetHasEvents(node0.HasEvents() | node8.HasEvents());
				}
				{
					And node4 = new And();
					node4.SetClassNameString("And");
					node4.SetId(4);
#if !BEHAVIAC_RELEASE
					node4.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node4);
					{
						False node6 = new False();
						node6.SetClassNameString("False");
						node6.SetId(6);
#if !BEHAVIAC_RELEASE
						node6.SetAgentType("AgentNodeTest");
#endif
						node4.AddChild(node6);
						node4.SetHasEvents(node4.HasEvents() | node6.HasEvents());
					}
					{
						False node7 = new False();
						node7.SetClassNameString("False");
						node7.SetId(7);
#if !BEHAVIAC_RELEASE
						node7.SetAgentType("AgentNodeTest");
#endif
						node4.AddChild(node7);
						node4.SetHasEvents(node4.HasEvents() | node7.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node4.HasEvents());
				}
				{
					Action_bt_node_test_condition_ut_2_node12 node12 = new Action_bt_node_test_condition_ut_2_node12();
					node12.SetClassNameString("Action");
					node12.SetId(12);
#if !BEHAVIAC_RELEASE
					node12.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node12);
					node0.SetHasEvents(node0.HasEvents() | node12.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/condition_ut_3

	class Action_bt_node_test_condition_ut_3_node2 : behaviac.Action
	{
		public Action_bt_node_test_condition_ut_3_node2()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Action_bt_node_test_condition_ut_3_node8 : behaviac.Action
	{
		public Action_bt_node_test_condition_ut_3_node8()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Action_bt_node_test_condition_ut_3_node12 : behaviac.Action
	{
		public Action_bt_node_test_condition_ut_3_node12()
		{
			method_p0 = 2;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	public static class bt_node_test_condition_ut_3
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/condition_ut_3");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Sequence node0 = new Sequence();
				node0.SetClassNameString("Sequence");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					And node9 = new And();
					node9.SetClassNameString("And");
					node9.SetId(9);
#if !BEHAVIAC_RELEASE
					node9.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node9);
					{
						Or node13 = new Or();
						node13.SetClassNameString("Or");
						node13.SetId(13);
#if !BEHAVIAC_RELEASE
						node13.SetAgentType("AgentNodeTest");
#endif
						node9.AddChild(node13);
						{
							True node10 = new True();
							node10.SetClassNameString("True");
							node10.SetId(10);
#if !BEHAVIAC_RELEASE
							node10.SetAgentType("AgentNodeTest");
#endif
							node13.AddChild(node10);
							node13.SetHasEvents(node13.HasEvents() | node10.HasEvents());
						}
						{
							False node14 = new False();
							node14.SetClassNameString("False");
							node14.SetId(14);
#if !BEHAVIAC_RELEASE
							node14.SetAgentType("AgentNodeTest");
#endif
							node13.AddChild(node14);
							node13.SetHasEvents(node13.HasEvents() | node14.HasEvents());
						}
						node9.SetHasEvents(node9.HasEvents() | node13.HasEvents());
					}
					{
						True node11 = new True();
						node11.SetClassNameString("True");
						node11.SetId(11);
#if !BEHAVIAC_RELEASE
						node11.SetAgentType("AgentNodeTest");
#endif
						node9.AddChild(node11);
						node9.SetHasEvents(node9.HasEvents() | node11.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node9.HasEvents());
				}
				{
					Action_bt_node_test_condition_ut_3_node2 node2 = new Action_bt_node_test_condition_ut_3_node2();
					node2.SetClassNameString("Action");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				{
					Or node1 = new Or();
					node1.SetClassNameString("Or");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					{
						And node15 = new And();
						node15.SetClassNameString("And");
						node15.SetId(15);
#if !BEHAVIAC_RELEASE
						node15.SetAgentType("AgentNodeTest");
#endif
						node1.AddChild(node15);
						{
							True node3 = new True();
							node3.SetClassNameString("True");
							node3.SetId(3);
#if !BEHAVIAC_RELEASE
							node3.SetAgentType("AgentNodeTest");
#endif
							node15.AddChild(node3);
							node15.SetHasEvents(node15.HasEvents() | node3.HasEvents());
						}
						{
							True node16 = new True();
							node16.SetClassNameString("True");
							node16.SetId(16);
#if !BEHAVIAC_RELEASE
							node16.SetAgentType("AgentNodeTest");
#endif
							node15.AddChild(node16);
							node15.SetHasEvents(node15.HasEvents() | node16.HasEvents());
						}
						node1.SetHasEvents(node1.HasEvents() | node15.HasEvents());
					}
					{
						False node5 = new False();
						node5.SetClassNameString("False");
						node5.SetId(5);
#if !BEHAVIAC_RELEASE
						node5.SetAgentType("AgentNodeTest");
#endif
						node1.AddChild(node5);
						node1.SetHasEvents(node1.HasEvents() | node5.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					Action_bt_node_test_condition_ut_3_node8 node8 = new Action_bt_node_test_condition_ut_3_node8();
					node8.SetClassNameString("Action");
					node8.SetId(8);
#if !BEHAVIAC_RELEASE
					node8.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node8);
					node0.SetHasEvents(node0.HasEvents() | node8.HasEvents());
				}
				{
					And node4 = new And();
					node4.SetClassNameString("And");
					node4.SetId(4);
#if !BEHAVIAC_RELEASE
					node4.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node4);
					{
						Or node18 = new Or();
						node18.SetClassNameString("Or");
						node18.SetId(18);
#if !BEHAVIAC_RELEASE
						node18.SetAgentType("AgentNodeTest");
#endif
						node4.AddChild(node18);
						{
							Or node19 = new Or();
							node19.SetClassNameString("Or");
							node19.SetId(19);
#if !BEHAVIAC_RELEASE
							node19.SetAgentType("AgentNodeTest");
#endif
							node18.AddChild(node19);
							{
								False node6 = new False();
								node6.SetClassNameString("False");
								node6.SetId(6);
#if !BEHAVIAC_RELEASE
								node6.SetAgentType("AgentNodeTest");
#endif
								node19.AddChild(node6);
								node19.SetHasEvents(node19.HasEvents() | node6.HasEvents());
							}
							{
								True node21 = new True();
								node21.SetClassNameString("True");
								node21.SetId(21);
#if !BEHAVIAC_RELEASE
								node21.SetAgentType("AgentNodeTest");
#endif
								node19.AddChild(node21);
								node19.SetHasEvents(node19.HasEvents() | node21.HasEvents());
							}
							node18.SetHasEvents(node18.HasEvents() | node19.HasEvents());
						}
						{
							False node22 = new False();
							node22.SetClassNameString("False");
							node22.SetId(22);
#if !BEHAVIAC_RELEASE
							node22.SetAgentType("AgentNodeTest");
#endif
							node18.AddChild(node22);
							node18.SetHasEvents(node18.HasEvents() | node22.HasEvents());
						}
						node4.SetHasEvents(node4.HasEvents() | node18.HasEvents());
					}
					{
						And node17 = new And();
						node17.SetClassNameString("And");
						node17.SetId(17);
#if !BEHAVIAC_RELEASE
						node17.SetAgentType("AgentNodeTest");
#endif
						node4.AddChild(node17);
						{
							True node7 = new True();
							node7.SetClassNameString("True");
							node7.SetId(7);
#if !BEHAVIAC_RELEASE
							node7.SetAgentType("AgentNodeTest");
#endif
							node17.AddChild(node7);
							node17.SetHasEvents(node17.HasEvents() | node7.HasEvents());
						}
						{
							And node20 = new And();
							node20.SetClassNameString("And");
							node20.SetId(20);
#if !BEHAVIAC_RELEASE
							node20.SetAgentType("AgentNodeTest");
#endif
							node17.AddChild(node20);
							{
								True node23 = new True();
								node23.SetClassNameString("True");
								node23.SetId(23);
#if !BEHAVIAC_RELEASE
								node23.SetAgentType("AgentNodeTest");
#endif
								node20.AddChild(node23);
								node20.SetHasEvents(node20.HasEvents() | node23.HasEvents());
							}
							{
								True node24 = new True();
								node24.SetClassNameString("True");
								node24.SetId(24);
#if !BEHAVIAC_RELEASE
								node24.SetAgentType("AgentNodeTest");
#endif
								node20.AddChild(node24);
								node20.SetHasEvents(node20.HasEvents() | node24.HasEvents());
							}
							node17.SetHasEvents(node17.HasEvents() | node20.HasEvents());
						}
						node4.SetHasEvents(node4.HasEvents() | node17.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node4.HasEvents());
				}
				{
					Action_bt_node_test_condition_ut_3_node12 node12 = new Action_bt_node_test_condition_ut_3_node12();
					node12.SetClassNameString("Action");
					node12.SetId(12);
#if !BEHAVIAC_RELEASE
					node12.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node12);
					node0.SetHasEvents(node0.HasEvents() | node12.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/decoration_alwaysfailure_ut_0

	class DecoratorAlwaysFailure_bt_node_test_decoration_alwaysfailure_ut_0_node1 : behaviac.DecoratorAlwaysFailure
	{
		public DecoratorAlwaysFailure_bt_node_test_decoration_alwaysfailure_ut_0_node1()
		{
			m_bDecorateWhenChildEnds = false;
		}
	}

	class Action_bt_node_test_decoration_alwaysfailure_ut_0_node5 : behaviac.Action
	{
		public Action_bt_node_test_decoration_alwaysfailure_ut_0_node5()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Action_bt_node_test_decoration_alwaysfailure_ut_0_node6 : behaviac.Action
	{
		public Action_bt_node_test_decoration_alwaysfailure_ut_0_node6()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class DecoratorAlwaysFailure_bt_node_test_decoration_alwaysfailure_ut_0_node3 : behaviac.DecoratorAlwaysFailure
	{
		public DecoratorAlwaysFailure_bt_node_test_decoration_alwaysfailure_ut_0_node3()
		{
			m_bDecorateWhenChildEnds = false;
		}
	}

	class Action_bt_node_test_decoration_alwaysfailure_ut_0_node7 : behaviac.Action
	{
		public Action_bt_node_test_decoration_alwaysfailure_ut_0_node7()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_1(method_p0);
			return EBTStatus.BT_FAILURE;
		}
		int method_p0;
	}

	class Action_bt_node_test_decoration_alwaysfailure_ut_0_node8 : behaviac.Action
	{
		public Action_bt_node_test_decoration_alwaysfailure_ut_0_node8()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_1(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class DecoratorAlwaysFailure_bt_node_test_decoration_alwaysfailure_ut_0_node10 : behaviac.DecoratorAlwaysFailure
	{
		public DecoratorAlwaysFailure_bt_node_test_decoration_alwaysfailure_ut_0_node10()
		{
			m_bDecorateWhenChildEnds = false;
		}
	}

	class Action_bt_node_test_decoration_alwaysfailure_ut_0_node11 : behaviac.Action
	{
		public Action_bt_node_test_decoration_alwaysfailure_ut_0_node11()
		{
			method_p0 = 0f;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_2(method_p0);
			return EBTStatus.BT_RUNNING;
		}
		float method_p0;
	}

	class Action_bt_node_test_decoration_alwaysfailure_ut_0_node12 : behaviac.Action
	{
		public Action_bt_node_test_decoration_alwaysfailure_ut_0_node12()
		{
			method_p0 = 1f;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_2(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		float method_p0;
	}

	public static class bt_node_test_decoration_alwaysfailure_ut_0
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/decoration_alwaysfailure_ut_0");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Sequence node0 = new Sequence();
				node0.SetClassNameString("Sequence");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					Selector node4 = new Selector();
					node4.SetClassNameString("Selector");
					node4.SetId(4);
#if !BEHAVIAC_RELEASE
					node4.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node4);
					{
						DecoratorAlwaysFailure_bt_node_test_decoration_alwaysfailure_ut_0_node1 node1 = new DecoratorAlwaysFailure_bt_node_test_decoration_alwaysfailure_ut_0_node1();
						node1.SetClassNameString("DecoratorAlwaysFailure");
						node1.SetId(1);
#if !BEHAVIAC_RELEASE
						node1.SetAgentType("AgentNodeTest");
#endif
						node4.AddChild(node1);
						{
							Action_bt_node_test_decoration_alwaysfailure_ut_0_node5 node5 = new Action_bt_node_test_decoration_alwaysfailure_ut_0_node5();
							node5.SetClassNameString("Action");
							node5.SetId(5);
#if !BEHAVIAC_RELEASE
							node5.SetAgentType("AgentNodeTest");
#endif
							node1.AddChild(node5);
							node1.SetHasEvents(node1.HasEvents() | node5.HasEvents());
						}
						node4.SetHasEvents(node4.HasEvents() | node1.HasEvents());
					}
					{
						Action_bt_node_test_decoration_alwaysfailure_ut_0_node6 node6 = new Action_bt_node_test_decoration_alwaysfailure_ut_0_node6();
						node6.SetClassNameString("Action");
						node6.SetId(6);
#if !BEHAVIAC_RELEASE
						node6.SetAgentType("AgentNodeTest");
#endif
						node4.AddChild(node6);
						node4.SetHasEvents(node4.HasEvents() | node6.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node4.HasEvents());
				}
				{
					Selector node2 = new Selector();
					node2.SetClassNameString("Selector");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					{
						DecoratorAlwaysFailure_bt_node_test_decoration_alwaysfailure_ut_0_node3 node3 = new DecoratorAlwaysFailure_bt_node_test_decoration_alwaysfailure_ut_0_node3();
						node3.SetClassNameString("DecoratorAlwaysFailure");
						node3.SetId(3);
#if !BEHAVIAC_RELEASE
						node3.SetAgentType("AgentNodeTest");
#endif
						node2.AddChild(node3);
						{
							Action_bt_node_test_decoration_alwaysfailure_ut_0_node7 node7 = new Action_bt_node_test_decoration_alwaysfailure_ut_0_node7();
							node7.SetClassNameString("Action");
							node7.SetId(7);
#if !BEHAVIAC_RELEASE
							node7.SetAgentType("AgentNodeTest");
#endif
							node3.AddChild(node7);
							node3.SetHasEvents(node3.HasEvents() | node7.HasEvents());
						}
						node2.SetHasEvents(node2.HasEvents() | node3.HasEvents());
					}
					{
						Action_bt_node_test_decoration_alwaysfailure_ut_0_node8 node8 = new Action_bt_node_test_decoration_alwaysfailure_ut_0_node8();
						node8.SetClassNameString("Action");
						node8.SetId(8);
#if !BEHAVIAC_RELEASE
						node8.SetAgentType("AgentNodeTest");
#endif
						node2.AddChild(node8);
						node2.SetHasEvents(node2.HasEvents() | node8.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				{
					Selector node9 = new Selector();
					node9.SetClassNameString("Selector");
					node9.SetId(9);
#if !BEHAVIAC_RELEASE
					node9.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node9);
					{
						DecoratorAlwaysFailure_bt_node_test_decoration_alwaysfailure_ut_0_node10 node10 = new DecoratorAlwaysFailure_bt_node_test_decoration_alwaysfailure_ut_0_node10();
						node10.SetClassNameString("DecoratorAlwaysFailure");
						node10.SetId(10);
#if !BEHAVIAC_RELEASE
						node10.SetAgentType("AgentNodeTest");
#endif
						node9.AddChild(node10);
						{
							Action_bt_node_test_decoration_alwaysfailure_ut_0_node11 node11 = new Action_bt_node_test_decoration_alwaysfailure_ut_0_node11();
							node11.SetClassNameString("Action");
							node11.SetId(11);
#if !BEHAVIAC_RELEASE
							node11.SetAgentType("AgentNodeTest");
#endif
							node10.AddChild(node11);
							node10.SetHasEvents(node10.HasEvents() | node11.HasEvents());
						}
						node9.SetHasEvents(node9.HasEvents() | node10.HasEvents());
					}
					{
						Action_bt_node_test_decoration_alwaysfailure_ut_0_node12 node12 = new Action_bt_node_test_decoration_alwaysfailure_ut_0_node12();
						node12.SetClassNameString("Action");
						node12.SetId(12);
#if !BEHAVIAC_RELEASE
						node12.SetAgentType("AgentNodeTest");
#endif
						node9.AddChild(node12);
						node9.SetHasEvents(node9.HasEvents() | node12.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node9.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/decoration_alwaysrunning_ut_0

	class Parallel_bt_node_test_decoration_alwaysrunning_ut_0_node0 : behaviac.Parallel
	{
		public Parallel_bt_node_test_decoration_alwaysrunning_ut_0_node0()
		{
			m_failPolicy = behaviac.FAILURE_POLICY.FAIL_ON_ONE;
			m_succeedPolicy = behaviac.SUCCESS_POLICY.SUCCEED_ON_ALL;
			m_exitPolicy = behaviac.EXIT_POLICY.EXIT_ABORT_RUNNINGSIBLINGS;
			m_childFinishPolicy = behaviac.CHILDFINISH_POLICY.CHILDFINISH_LOOP;
		}
	}

	class DecoratorAlwaysRunning_bt_node_test_decoration_alwaysrunning_ut_0_node1 : behaviac.DecoratorAlwaysRunning
	{
		public DecoratorAlwaysRunning_bt_node_test_decoration_alwaysrunning_ut_0_node1()
		{
			m_bDecorateWhenChildEnds = false;
		}
	}

	class Action_bt_node_test_decoration_alwaysrunning_ut_0_node5 : behaviac.Action
	{
		public Action_bt_node_test_decoration_alwaysrunning_ut_0_node5()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Action_bt_node_test_decoration_alwaysrunning_ut_0_node6 : behaviac.Action
	{
		public Action_bt_node_test_decoration_alwaysrunning_ut_0_node6()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class DecoratorAlwaysRunning_bt_node_test_decoration_alwaysrunning_ut_0_node3 : behaviac.DecoratorAlwaysRunning
	{
		public DecoratorAlwaysRunning_bt_node_test_decoration_alwaysrunning_ut_0_node3()
		{
			m_bDecorateWhenChildEnds = false;
		}
	}

	class Action_bt_node_test_decoration_alwaysrunning_ut_0_node7 : behaviac.Action
	{
		public Action_bt_node_test_decoration_alwaysrunning_ut_0_node7()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_1(method_p0);
			return EBTStatus.BT_FAILURE;
		}
		int method_p0;
	}

	class Action_bt_node_test_decoration_alwaysrunning_ut_0_node8 : behaviac.Action
	{
		public Action_bt_node_test_decoration_alwaysrunning_ut_0_node8()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_1(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class DecoratorAlwaysRunning_bt_node_test_decoration_alwaysrunning_ut_0_node10 : behaviac.DecoratorAlwaysRunning
	{
		public DecoratorAlwaysRunning_bt_node_test_decoration_alwaysrunning_ut_0_node10()
		{
			m_bDecorateWhenChildEnds = false;
		}
	}

	class Action_bt_node_test_decoration_alwaysrunning_ut_0_node11 : behaviac.Action
	{
		public Action_bt_node_test_decoration_alwaysrunning_ut_0_node11()
		{
			method_p0 = 0f;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_2(method_p0);
			return EBTStatus.BT_RUNNING;
		}
		float method_p0;
	}

	class Action_bt_node_test_decoration_alwaysrunning_ut_0_node12 : behaviac.Action
	{
		public Action_bt_node_test_decoration_alwaysrunning_ut_0_node12()
		{
			method_p0 = 1f;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_2(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		float method_p0;
	}

	public static class bt_node_test_decoration_alwaysrunning_ut_0
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/decoration_alwaysrunning_ut_0");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Parallel_bt_node_test_decoration_alwaysrunning_ut_0_node0 node0 = new Parallel_bt_node_test_decoration_alwaysrunning_ut_0_node0();
				node0.SetClassNameString("Parallel");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					Selector node4 = new Selector();
					node4.SetClassNameString("Selector");
					node4.SetId(4);
#if !BEHAVIAC_RELEASE
					node4.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node4);
					{
						DecoratorAlwaysRunning_bt_node_test_decoration_alwaysrunning_ut_0_node1 node1 = new DecoratorAlwaysRunning_bt_node_test_decoration_alwaysrunning_ut_0_node1();
						node1.SetClassNameString("DecoratorAlwaysRunning");
						node1.SetId(1);
#if !BEHAVIAC_RELEASE
						node1.SetAgentType("AgentNodeTest");
#endif
						node4.AddChild(node1);
						{
							Action_bt_node_test_decoration_alwaysrunning_ut_0_node5 node5 = new Action_bt_node_test_decoration_alwaysrunning_ut_0_node5();
							node5.SetClassNameString("Action");
							node5.SetId(5);
#if !BEHAVIAC_RELEASE
							node5.SetAgentType("AgentNodeTest");
#endif
							node1.AddChild(node5);
							node1.SetHasEvents(node1.HasEvents() | node5.HasEvents());
						}
						node4.SetHasEvents(node4.HasEvents() | node1.HasEvents());
					}
					{
						Action_bt_node_test_decoration_alwaysrunning_ut_0_node6 node6 = new Action_bt_node_test_decoration_alwaysrunning_ut_0_node6();
						node6.SetClassNameString("Action");
						node6.SetId(6);
#if !BEHAVIAC_RELEASE
						node6.SetAgentType("AgentNodeTest");
#endif
						node4.AddChild(node6);
						node4.SetHasEvents(node4.HasEvents() | node6.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node4.HasEvents());
				}
				{
					Selector node2 = new Selector();
					node2.SetClassNameString("Selector");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					{
						DecoratorAlwaysRunning_bt_node_test_decoration_alwaysrunning_ut_0_node3 node3 = new DecoratorAlwaysRunning_bt_node_test_decoration_alwaysrunning_ut_0_node3();
						node3.SetClassNameString("DecoratorAlwaysRunning");
						node3.SetId(3);
#if !BEHAVIAC_RELEASE
						node3.SetAgentType("AgentNodeTest");
#endif
						node2.AddChild(node3);
						{
							Action_bt_node_test_decoration_alwaysrunning_ut_0_node7 node7 = new Action_bt_node_test_decoration_alwaysrunning_ut_0_node7();
							node7.SetClassNameString("Action");
							node7.SetId(7);
#if !BEHAVIAC_RELEASE
							node7.SetAgentType("AgentNodeTest");
#endif
							node3.AddChild(node7);
							node3.SetHasEvents(node3.HasEvents() | node7.HasEvents());
						}
						node2.SetHasEvents(node2.HasEvents() | node3.HasEvents());
					}
					{
						Action_bt_node_test_decoration_alwaysrunning_ut_0_node8 node8 = new Action_bt_node_test_decoration_alwaysrunning_ut_0_node8();
						node8.SetClassNameString("Action");
						node8.SetId(8);
#if !BEHAVIAC_RELEASE
						node8.SetAgentType("AgentNodeTest");
#endif
						node2.AddChild(node8);
						node2.SetHasEvents(node2.HasEvents() | node8.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				{
					Selector node9 = new Selector();
					node9.SetClassNameString("Selector");
					node9.SetId(9);
#if !BEHAVIAC_RELEASE
					node9.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node9);
					{
						DecoratorAlwaysRunning_bt_node_test_decoration_alwaysrunning_ut_0_node10 node10 = new DecoratorAlwaysRunning_bt_node_test_decoration_alwaysrunning_ut_0_node10();
						node10.SetClassNameString("DecoratorAlwaysRunning");
						node10.SetId(10);
#if !BEHAVIAC_RELEASE
						node10.SetAgentType("AgentNodeTest");
#endif
						node9.AddChild(node10);
						{
							Action_bt_node_test_decoration_alwaysrunning_ut_0_node11 node11 = new Action_bt_node_test_decoration_alwaysrunning_ut_0_node11();
							node11.SetClassNameString("Action");
							node11.SetId(11);
#if !BEHAVIAC_RELEASE
							node11.SetAgentType("AgentNodeTest");
#endif
							node10.AddChild(node11);
							node10.SetHasEvents(node10.HasEvents() | node11.HasEvents());
						}
						node9.SetHasEvents(node9.HasEvents() | node10.HasEvents());
					}
					{
						Action_bt_node_test_decoration_alwaysrunning_ut_0_node12 node12 = new Action_bt_node_test_decoration_alwaysrunning_ut_0_node12();
						node12.SetClassNameString("Action");
						node12.SetId(12);
#if !BEHAVIAC_RELEASE
						node12.SetAgentType("AgentNodeTest");
#endif
						node9.AddChild(node12);
						node9.SetHasEvents(node9.HasEvents() | node12.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node9.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/decoration_alwayssuccess_ut_0

	class DecoratorAlwaysSuccess_bt_node_test_decoration_alwayssuccess_ut_0_node1 : behaviac.DecoratorAlwaysSuccess
	{
		public DecoratorAlwaysSuccess_bt_node_test_decoration_alwayssuccess_ut_0_node1()
		{
			m_bDecorateWhenChildEnds = false;
		}
	}

	class Action_bt_node_test_decoration_alwayssuccess_ut_0_node5 : behaviac.Action
	{
		public Action_bt_node_test_decoration_alwayssuccess_ut_0_node5()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Action_bt_node_test_decoration_alwayssuccess_ut_0_node6 : behaviac.Action
	{
		public Action_bt_node_test_decoration_alwayssuccess_ut_0_node6()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class DecoratorAlwaysSuccess_bt_node_test_decoration_alwayssuccess_ut_0_node3 : behaviac.DecoratorAlwaysSuccess
	{
		public DecoratorAlwaysSuccess_bt_node_test_decoration_alwayssuccess_ut_0_node3()
		{
			m_bDecorateWhenChildEnds = false;
		}
	}

	class Action_bt_node_test_decoration_alwayssuccess_ut_0_node7 : behaviac.Action
	{
		public Action_bt_node_test_decoration_alwayssuccess_ut_0_node7()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_1(method_p0);
			return EBTStatus.BT_FAILURE;
		}
		int method_p0;
	}

	class Action_bt_node_test_decoration_alwayssuccess_ut_0_node8 : behaviac.Action
	{
		public Action_bt_node_test_decoration_alwayssuccess_ut_0_node8()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_1(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class DecoratorAlwaysSuccess_bt_node_test_decoration_alwayssuccess_ut_0_node10 : behaviac.DecoratorAlwaysSuccess
	{
		public DecoratorAlwaysSuccess_bt_node_test_decoration_alwayssuccess_ut_0_node10()
		{
			m_bDecorateWhenChildEnds = false;
		}
	}

	class Action_bt_node_test_decoration_alwayssuccess_ut_0_node11 : behaviac.Action
	{
		public Action_bt_node_test_decoration_alwayssuccess_ut_0_node11()
		{
			method_p0 = 0f;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_2(method_p0);
			return EBTStatus.BT_RUNNING;
		}
		float method_p0;
	}

	class Action_bt_node_test_decoration_alwayssuccess_ut_0_node12 : behaviac.Action
	{
		public Action_bt_node_test_decoration_alwayssuccess_ut_0_node12()
		{
			method_p0 = 1f;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_2(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		float method_p0;
	}

	public static class bt_node_test_decoration_alwayssuccess_ut_0
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/decoration_alwayssuccess_ut_0");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Sequence node0 = new Sequence();
				node0.SetClassNameString("Sequence");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					Selector node4 = new Selector();
					node4.SetClassNameString("Selector");
					node4.SetId(4);
#if !BEHAVIAC_RELEASE
					node4.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node4);
					{
						DecoratorAlwaysSuccess_bt_node_test_decoration_alwayssuccess_ut_0_node1 node1 = new DecoratorAlwaysSuccess_bt_node_test_decoration_alwayssuccess_ut_0_node1();
						node1.SetClassNameString("DecoratorAlwaysSuccess");
						node1.SetId(1);
#if !BEHAVIAC_RELEASE
						node1.SetAgentType("AgentNodeTest");
#endif
						node4.AddChild(node1);
						{
							Action_bt_node_test_decoration_alwayssuccess_ut_0_node5 node5 = new Action_bt_node_test_decoration_alwayssuccess_ut_0_node5();
							node5.SetClassNameString("Action");
							node5.SetId(5);
#if !BEHAVIAC_RELEASE
							node5.SetAgentType("AgentNodeTest");
#endif
							node1.AddChild(node5);
							node1.SetHasEvents(node1.HasEvents() | node5.HasEvents());
						}
						node4.SetHasEvents(node4.HasEvents() | node1.HasEvents());
					}
					{
						Action_bt_node_test_decoration_alwayssuccess_ut_0_node6 node6 = new Action_bt_node_test_decoration_alwayssuccess_ut_0_node6();
						node6.SetClassNameString("Action");
						node6.SetId(6);
#if !BEHAVIAC_RELEASE
						node6.SetAgentType("AgentNodeTest");
#endif
						node4.AddChild(node6);
						node4.SetHasEvents(node4.HasEvents() | node6.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node4.HasEvents());
				}
				{
					Selector node2 = new Selector();
					node2.SetClassNameString("Selector");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					{
						DecoratorAlwaysSuccess_bt_node_test_decoration_alwayssuccess_ut_0_node3 node3 = new DecoratorAlwaysSuccess_bt_node_test_decoration_alwayssuccess_ut_0_node3();
						node3.SetClassNameString("DecoratorAlwaysSuccess");
						node3.SetId(3);
#if !BEHAVIAC_RELEASE
						node3.SetAgentType("AgentNodeTest");
#endif
						node2.AddChild(node3);
						{
							Action_bt_node_test_decoration_alwayssuccess_ut_0_node7 node7 = new Action_bt_node_test_decoration_alwayssuccess_ut_0_node7();
							node7.SetClassNameString("Action");
							node7.SetId(7);
#if !BEHAVIAC_RELEASE
							node7.SetAgentType("AgentNodeTest");
#endif
							node3.AddChild(node7);
							node3.SetHasEvents(node3.HasEvents() | node7.HasEvents());
						}
						node2.SetHasEvents(node2.HasEvents() | node3.HasEvents());
					}
					{
						Action_bt_node_test_decoration_alwayssuccess_ut_0_node8 node8 = new Action_bt_node_test_decoration_alwayssuccess_ut_0_node8();
						node8.SetClassNameString("Action");
						node8.SetId(8);
#if !BEHAVIAC_RELEASE
						node8.SetAgentType("AgentNodeTest");
#endif
						node2.AddChild(node8);
						node2.SetHasEvents(node2.HasEvents() | node8.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				{
					Selector node9 = new Selector();
					node9.SetClassNameString("Selector");
					node9.SetId(9);
#if !BEHAVIAC_RELEASE
					node9.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node9);
					{
						DecoratorAlwaysSuccess_bt_node_test_decoration_alwayssuccess_ut_0_node10 node10 = new DecoratorAlwaysSuccess_bt_node_test_decoration_alwayssuccess_ut_0_node10();
						node10.SetClassNameString("DecoratorAlwaysSuccess");
						node10.SetId(10);
#if !BEHAVIAC_RELEASE
						node10.SetAgentType("AgentNodeTest");
#endif
						node9.AddChild(node10);
						{
							Action_bt_node_test_decoration_alwayssuccess_ut_0_node11 node11 = new Action_bt_node_test_decoration_alwayssuccess_ut_0_node11();
							node11.SetClassNameString("Action");
							node11.SetId(11);
#if !BEHAVIAC_RELEASE
							node11.SetAgentType("AgentNodeTest");
#endif
							node10.AddChild(node11);
							node10.SetHasEvents(node10.HasEvents() | node11.HasEvents());
						}
						node9.SetHasEvents(node9.HasEvents() | node10.HasEvents());
					}
					{
						Action_bt_node_test_decoration_alwayssuccess_ut_0_node12 node12 = new Action_bt_node_test_decoration_alwayssuccess_ut_0_node12();
						node12.SetClassNameString("Action");
						node12.SetId(12);
#if !BEHAVIAC_RELEASE
						node12.SetAgentType("AgentNodeTest");
#endif
						node9.AddChild(node12);
						node9.SetHasEvents(node9.HasEvents() | node12.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node9.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/decoration_countlimit_ut_0

	class DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_0_node1 : behaviac.DecoratorCountLimit
	{
		public DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_0_node1()
		{
			m_bDecorateWhenChildEnds = true;
		}
		protected override int GetCount(Agent pAgent)
		{
			return 5;
		}
	}

	class Action_bt_node_test_decoration_countlimit_ut_0_node2 : behaviac.Action
	{
		public Action_bt_node_test_decoration_countlimit_ut_0_node2()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Action_bt_node_test_decoration_countlimit_ut_0_node3 : behaviac.Action
	{
		public Action_bt_node_test_decoration_countlimit_ut_0_node3()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	public static class bt_node_test_decoration_countlimit_ut_0
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/decoration_countlimit_ut_0");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Selector node0 = new Selector();
				node0.SetClassNameString("Selector");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_0_node1 node1 = new DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_0_node1();
					node1.SetClassNameString("DecoratorCountLimit");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					{
						Action_bt_node_test_decoration_countlimit_ut_0_node2 node2 = new Action_bt_node_test_decoration_countlimit_ut_0_node2();
						node2.SetClassNameString("Action");
						node2.SetId(2);
#if !BEHAVIAC_RELEASE
						node2.SetAgentType("AgentNodeTest");
#endif
						node1.AddChild(node2);
						node1.SetHasEvents(node1.HasEvents() | node2.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					Action_bt_node_test_decoration_countlimit_ut_0_node3 node3 = new Action_bt_node_test_decoration_countlimit_ut_0_node3();
					node3.SetClassNameString("Action");
					node3.SetId(3);
#if !BEHAVIAC_RELEASE
					node3.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node3);
					node0.SetHasEvents(node0.HasEvents() | node3.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/decoration_countlimit_ut_1

	class DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_1_node1 : behaviac.DecoratorCountLimit
	{
		public DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_1_node1()
		{
			m_bDecorateWhenChildEnds = true;
		}
		protected override int GetCount(Agent pAgent)
		{
			return 5;
		}
	}

	class Predicate_bt_node_test_decoration_countlimit_ut_1_attach4 : behaviac.Predicate
	{
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_FAILURE;
			this.m_bAnd = true;
			int opl = ((AgentNodeTest)pAgent).testVar_1;
			int opr = 0;
			bool op = opl == opr;
			if (op)
				result = EBTStatus.BT_SUCCESS;
			return result;
		}
	}

	class Action_bt_node_test_decoration_countlimit_ut_1_node2 : behaviac.Action
	{
		public Action_bt_node_test_decoration_countlimit_ut_1_node2()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Action_bt_node_test_decoration_countlimit_ut_1_node3 : behaviac.Action
	{
		public Action_bt_node_test_decoration_countlimit_ut_1_node3()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	public static class bt_node_test_decoration_countlimit_ut_1
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/decoration_countlimit_ut_1");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Selector node0 = new Selector();
				node0.SetClassNameString("Selector");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_1_node1 node1 = new DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_1_node1();
					node1.SetClassNameString("DecoratorCountLimit");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					// attachments
					{
						Predicate_bt_node_test_decoration_countlimit_ut_1_attach4 attach4 = new Predicate_bt_node_test_decoration_countlimit_ut_1_attach4();
						attach4.SetClassNameString("Predicate");
						attach4.SetId(4);
#if !BEHAVIAC_RELEASE
						attach4.SetAgentType("AgentNodeTest");
#endif
						node1.Attach(attach4);
					}
					node0.AddChild(node1);
					{
						Action_bt_node_test_decoration_countlimit_ut_1_node2 node2 = new Action_bt_node_test_decoration_countlimit_ut_1_node2();
						node2.SetClassNameString("Action");
						node2.SetId(2);
#if !BEHAVIAC_RELEASE
						node2.SetAgentType("AgentNodeTest");
#endif
						node1.AddChild(node2);
						node1.SetHasEvents(node1.HasEvents() | node2.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					Action_bt_node_test_decoration_countlimit_ut_1_node3 node3 = new Action_bt_node_test_decoration_countlimit_ut_1_node3();
					node3.SetClassNameString("Action");
					node3.SetId(3);
#if !BEHAVIAC_RELEASE
					node3.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node3);
					node0.SetHasEvents(node0.HasEvents() | node3.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/decoration_countlimit_ut_2

	class DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_2_node1 : behaviac.DecoratorCountLimit
	{
		public DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_2_node1()
		{
			m_bDecorateWhenChildEnds = true;
		}
		protected override int GetCount(Agent pAgent)
		{
			return 5;
		}
	}

	class Predicate_bt_node_test_decoration_countlimit_ut_2_attach4 : behaviac.Predicate
	{
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_FAILURE;
			this.m_bAnd = true;
			int opl = ((AgentNodeTest)pAgent).testVar_1;
			int opr = 0;
			bool op = opl == opr;
			if (op)
				result = EBTStatus.BT_SUCCESS;
			return result;
		}
	}

	class Predicate_bt_node_test_decoration_countlimit_ut_2_attach5 : behaviac.Predicate
	{
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_FAILURE;
			this.m_bAnd = true;
			float opl = ((AgentNodeTest)pAgent).testVar_2;
			float opr = 0f;
			bool op = opl == opr;
			if (op)
				result = EBTStatus.BT_SUCCESS;
			return result;
		}
	}

	class Action_bt_node_test_decoration_countlimit_ut_2_node2 : behaviac.Action
	{
		public Action_bt_node_test_decoration_countlimit_ut_2_node2()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Action_bt_node_test_decoration_countlimit_ut_2_node3 : behaviac.Action
	{
		public Action_bt_node_test_decoration_countlimit_ut_2_node3()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	public static class bt_node_test_decoration_countlimit_ut_2
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/decoration_countlimit_ut_2");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Selector node0 = new Selector();
				node0.SetClassNameString("Selector");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_2_node1 node1 = new DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_2_node1();
					node1.SetClassNameString("DecoratorCountLimit");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					// attachments
					{
						Predicate_bt_node_test_decoration_countlimit_ut_2_attach4 attach4 = new Predicate_bt_node_test_decoration_countlimit_ut_2_attach4();
						attach4.SetClassNameString("Predicate");
						attach4.SetId(4);
#if !BEHAVIAC_RELEASE
						attach4.SetAgentType("AgentNodeTest");
#endif
						node1.Attach(attach4);
					}
					{
						Predicate_bt_node_test_decoration_countlimit_ut_2_attach5 attach5 = new Predicate_bt_node_test_decoration_countlimit_ut_2_attach5();
						attach5.SetClassNameString("Predicate");
						attach5.SetId(5);
#if !BEHAVIAC_RELEASE
						attach5.SetAgentType("AgentNodeTest");
#endif
						node1.Attach(attach5);
					}
					node0.AddChild(node1);
					{
						Action_bt_node_test_decoration_countlimit_ut_2_node2 node2 = new Action_bt_node_test_decoration_countlimit_ut_2_node2();
						node2.SetClassNameString("Action");
						node2.SetId(2);
#if !BEHAVIAC_RELEASE
						node2.SetAgentType("AgentNodeTest");
#endif
						node1.AddChild(node2);
						node1.SetHasEvents(node1.HasEvents() | node2.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					Action_bt_node_test_decoration_countlimit_ut_2_node3 node3 = new Action_bt_node_test_decoration_countlimit_ut_2_node3();
					node3.SetClassNameString("Action");
					node3.SetId(3);
#if !BEHAVIAC_RELEASE
					node3.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node3);
					node0.SetHasEvents(node0.HasEvents() | node3.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/decoration_countlimit_ut_3

	class DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_3_node1 : behaviac.DecoratorCountLimit
	{
		public DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_3_node1()
		{
			m_bDecorateWhenChildEnds = true;
		}
		protected override int GetCount(Agent pAgent)
		{
			return 5;
		}
	}

	class Predicate_bt_node_test_decoration_countlimit_ut_3_attach4 : behaviac.Predicate
	{
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_FAILURE;
			this.m_bAnd = true;
			int opl = ((AgentNodeTest)pAgent).testVar_0;
			int opr = 0;
			bool op = opl == opr;
			if (op)
				result = EBTStatus.BT_SUCCESS;
			return result;
		}
	}

	class Predicate_bt_node_test_decoration_countlimit_ut_3_attach5 : behaviac.Predicate
	{
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_FAILURE;
			this.m_bAnd = true;
			int opl = ((AgentNodeTest)pAgent).testVar_1;
			int opr = 0;
			bool op = opl == opr;
			if (op)
				result = EBTStatus.BT_SUCCESS;
			return result;
		}
	}

	class Predicate_bt_node_test_decoration_countlimit_ut_3_attach6 : behaviac.Predicate
	{
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_FAILURE;
			this.m_bAnd = false;
			float opl = ((AgentNodeTest)pAgent).testVar_3;
			float opr = 0f;
			bool op = opl == opr;
			if (op)
				result = EBTStatus.BT_SUCCESS;
			return result;
		}
	}

	class Action_bt_node_test_decoration_countlimit_ut_3_node2 : behaviac.Action
	{
		public Action_bt_node_test_decoration_countlimit_ut_3_node2()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Action_bt_node_test_decoration_countlimit_ut_3_node3 : behaviac.Action
	{
		public Action_bt_node_test_decoration_countlimit_ut_3_node3()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	public static class bt_node_test_decoration_countlimit_ut_3
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/decoration_countlimit_ut_3");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Selector node0 = new Selector();
				node0.SetClassNameString("Selector");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_3_node1 node1 = new DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_3_node1();
					node1.SetClassNameString("DecoratorCountLimit");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					// attachments
					{
						Predicate_bt_node_test_decoration_countlimit_ut_3_attach4 attach4 = new Predicate_bt_node_test_decoration_countlimit_ut_3_attach4();
						attach4.SetClassNameString("Predicate");
						attach4.SetId(4);
#if !BEHAVIAC_RELEASE
						attach4.SetAgentType("AgentNodeTest");
#endif
						node1.Attach(attach4);
					}
					{
						Predicate_bt_node_test_decoration_countlimit_ut_3_attach5 attach5 = new Predicate_bt_node_test_decoration_countlimit_ut_3_attach5();
						attach5.SetClassNameString("Predicate");
						attach5.SetId(5);
#if !BEHAVIAC_RELEASE
						attach5.SetAgentType("AgentNodeTest");
#endif
						node1.Attach(attach5);
					}
					{
						Predicate_bt_node_test_decoration_countlimit_ut_3_attach6 attach6 = new Predicate_bt_node_test_decoration_countlimit_ut_3_attach6();
						attach6.SetClassNameString("Predicate");
						attach6.SetId(6);
#if !BEHAVIAC_RELEASE
						attach6.SetAgentType("AgentNodeTest");
#endif
						node1.Attach(attach6);
					}
					node0.AddChild(node1);
					{
						Action_bt_node_test_decoration_countlimit_ut_3_node2 node2 = new Action_bt_node_test_decoration_countlimit_ut_3_node2();
						node2.SetClassNameString("Action");
						node2.SetId(2);
#if !BEHAVIAC_RELEASE
						node2.SetAgentType("AgentNodeTest");
#endif
						node1.AddChild(node2);
						node1.SetHasEvents(node1.HasEvents() | node2.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					Action_bt_node_test_decoration_countlimit_ut_3_node3 node3 = new Action_bt_node_test_decoration_countlimit_ut_3_node3();
					node3.SetClassNameString("Action");
					node3.SetId(3);
#if !BEHAVIAC_RELEASE
					node3.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node3);
					node0.SetHasEvents(node0.HasEvents() | node3.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/decoration_failureuntil_ut_0

	class DecoratorFailureUntil_bt_node_test_decoration_failureuntil_ut_0_node0 : behaviac.DecoratorFailureUntil
	{
		public DecoratorFailureUntil_bt_node_test_decoration_failureuntil_ut_0_node0()
		{
			m_bDecorateWhenChildEnds = true;
		}
		protected override int GetCount(Agent pAgent)
		{
			return -1;
		}
	}

	public static class bt_node_test_decoration_failureuntil_ut_0
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/decoration_failureuntil_ut_0");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				DecoratorFailureUntil_bt_node_test_decoration_failureuntil_ut_0_node0 node0 = new DecoratorFailureUntil_bt_node_test_decoration_failureuntil_ut_0_node0();
				node0.SetClassNameString("DecoratorFailureUntil");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					True node1 = new True();
					node1.SetClassNameString("True");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/decoration_failureuntil_ut_1

	class DecoratorFailureUntil_bt_node_test_decoration_failureuntil_ut_1_node0 : behaviac.DecoratorFailureUntil
	{
		public DecoratorFailureUntil_bt_node_test_decoration_failureuntil_ut_1_node0()
		{
			m_bDecorateWhenChildEnds = true;
		}
		protected override int GetCount(Agent pAgent)
		{
			return 5;
		}
	}

	public static class bt_node_test_decoration_failureuntil_ut_1
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/decoration_failureuntil_ut_1");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				DecoratorFailureUntil_bt_node_test_decoration_failureuntil_ut_1_node0 node0 = new DecoratorFailureUntil_bt_node_test_decoration_failureuntil_ut_1_node0();
				node0.SetClassNameString("DecoratorFailureUntil");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					True node1 = new True();
					node1.SetClassNameString("True");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/decoration_frames_ut_0

	class DecoratorFrames_bt_node_test_decoration_frames_ut_0_node1 : behaviac.DecoratorFrames
	{
		public DecoratorFrames_bt_node_test_decoration_frames_ut_0_node1()
		{
			m_bDecorateWhenChildEnds = false;
		}
		protected override int GetFrames(Agent pAgent)
		{
			return 100;
		}
	}

	class Action_bt_node_test_decoration_frames_ut_0_node2 : behaviac.Action
	{
		public Action_bt_node_test_decoration_frames_ut_0_node2()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Action_bt_node_test_decoration_frames_ut_0_node3 : behaviac.Action
	{
		public Action_bt_node_test_decoration_frames_ut_0_node3()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	public static class bt_node_test_decoration_frames_ut_0
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/decoration_frames_ut_0");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Sequence node0 = new Sequence();
				node0.SetClassNameString("Sequence");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					DecoratorFrames_bt_node_test_decoration_frames_ut_0_node1 node1 = new DecoratorFrames_bt_node_test_decoration_frames_ut_0_node1();
					node1.SetClassNameString("DecoratorFrames");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					{
						Action_bt_node_test_decoration_frames_ut_0_node2 node2 = new Action_bt_node_test_decoration_frames_ut_0_node2();
						node2.SetClassNameString("Action");
						node2.SetId(2);
#if !BEHAVIAC_RELEASE
						node2.SetAgentType("AgentNodeTest");
#endif
						node1.AddChild(node2);
						node1.SetHasEvents(node1.HasEvents() | node2.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					Action_bt_node_test_decoration_frames_ut_0_node3 node3 = new Action_bt_node_test_decoration_frames_ut_0_node3();
					node3.SetClassNameString("Action");
					node3.SetId(3);
#if !BEHAVIAC_RELEASE
					node3.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node3);
					node0.SetHasEvents(node0.HasEvents() | node3.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/decoration_log_ut_0

	class DecoratorLog_bt_node_test_decoration_log_ut_0_node1 : behaviac.DecoratorLog
	{
		public DecoratorLog_bt_node_test_decoration_log_ut_0_node1()
		{
			m_bDecorateWhenChildEnds = false;
			m_message = "This is a log node message 0! Child status is SUCCESS.";
		}
	}

	class Action_bt_node_test_decoration_log_ut_0_node2 : behaviac.Action
	{
		public Action_bt_node_test_decoration_log_ut_0_node2()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Action_bt_node_test_decoration_log_ut_0_node8 : behaviac.Action
	{
		public Action_bt_node_test_decoration_log_ut_0_node8()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class DecoratorLog_bt_node_test_decoration_log_ut_0_node3 : behaviac.DecoratorLog
	{
		public DecoratorLog_bt_node_test_decoration_log_ut_0_node3()
		{
			m_bDecorateWhenChildEnds = false;
			m_message = "This is a log node message 1! Child status is FAILURE.";
		}
	}

	class Action_bt_node_test_decoration_log_ut_0_node4 : behaviac.Action
	{
		public Action_bt_node_test_decoration_log_ut_0_node4()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_1(method_p0);
			return EBTStatus.BT_FAILURE;
		}
		int method_p0;
	}

	class Action_bt_node_test_decoration_log_ut_0_node9 : behaviac.Action
	{
		public Action_bt_node_test_decoration_log_ut_0_node9()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_1(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class DecoratorLog_bt_node_test_decoration_log_ut_0_node10 : behaviac.DecoratorLog
	{
		public DecoratorLog_bt_node_test_decoration_log_ut_0_node10()
		{
			m_bDecorateWhenChildEnds = false;
			m_message = "This is a log node message 1! Child status is RUNNING.";
		}
	}

	class Action_bt_node_test_decoration_log_ut_0_node12 : behaviac.Action
	{
		public Action_bt_node_test_decoration_log_ut_0_node12()
		{
			method_p0 = 0f;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_2(method_p0);
			return EBTStatus.BT_RUNNING;
		}
		float method_p0;
	}

	class Action_bt_node_test_decoration_log_ut_0_node11 : behaviac.Action
	{
		public Action_bt_node_test_decoration_log_ut_0_node11()
		{
			method_p0 = 1f;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_2(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		float method_p0;
	}

	public static class bt_node_test_decoration_log_ut_0
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/decoration_log_ut_0");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Sequence node0 = new Sequence();
				node0.SetClassNameString("Sequence");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					Selector node5 = new Selector();
					node5.SetClassNameString("Selector");
					node5.SetId(5);
#if !BEHAVIAC_RELEASE
					node5.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node5);
					{
						DecoratorLog_bt_node_test_decoration_log_ut_0_node1 node1 = new DecoratorLog_bt_node_test_decoration_log_ut_0_node1();
						node1.SetClassNameString("DecoratorLog");
						node1.SetId(1);
#if !BEHAVIAC_RELEASE
						node1.SetAgentType("AgentNodeTest");
#endif
						node5.AddChild(node1);
						{
							Action_bt_node_test_decoration_log_ut_0_node2 node2 = new Action_bt_node_test_decoration_log_ut_0_node2();
							node2.SetClassNameString("Action");
							node2.SetId(2);
#if !BEHAVIAC_RELEASE
							node2.SetAgentType("AgentNodeTest");
#endif
							node1.AddChild(node2);
							node1.SetHasEvents(node1.HasEvents() | node2.HasEvents());
						}
						node5.SetHasEvents(node5.HasEvents() | node1.HasEvents());
					}
					{
						Action_bt_node_test_decoration_log_ut_0_node8 node8 = new Action_bt_node_test_decoration_log_ut_0_node8();
						node8.SetClassNameString("Action");
						node8.SetId(8);
#if !BEHAVIAC_RELEASE
						node8.SetAgentType("AgentNodeTest");
#endif
						node5.AddChild(node8);
						node5.SetHasEvents(node5.HasEvents() | node8.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node5.HasEvents());
				}
				{
					Selector node6 = new Selector();
					node6.SetClassNameString("Selector");
					node6.SetId(6);
#if !BEHAVIAC_RELEASE
					node6.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node6);
					{
						DecoratorLog_bt_node_test_decoration_log_ut_0_node3 node3 = new DecoratorLog_bt_node_test_decoration_log_ut_0_node3();
						node3.SetClassNameString("DecoratorLog");
						node3.SetId(3);
#if !BEHAVIAC_RELEASE
						node3.SetAgentType("AgentNodeTest");
#endif
						node6.AddChild(node3);
						{
							Action_bt_node_test_decoration_log_ut_0_node4 node4 = new Action_bt_node_test_decoration_log_ut_0_node4();
							node4.SetClassNameString("Action");
							node4.SetId(4);
#if !BEHAVIAC_RELEASE
							node4.SetAgentType("AgentNodeTest");
#endif
							node3.AddChild(node4);
							node3.SetHasEvents(node3.HasEvents() | node4.HasEvents());
						}
						node6.SetHasEvents(node6.HasEvents() | node3.HasEvents());
					}
					{
						Action_bt_node_test_decoration_log_ut_0_node9 node9 = new Action_bt_node_test_decoration_log_ut_0_node9();
						node9.SetClassNameString("Action");
						node9.SetId(9);
#if !BEHAVIAC_RELEASE
						node9.SetAgentType("AgentNodeTest");
#endif
						node6.AddChild(node9);
						node6.SetHasEvents(node6.HasEvents() | node9.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node6.HasEvents());
				}
				{
					Selector node7 = new Selector();
					node7.SetClassNameString("Selector");
					node7.SetId(7);
#if !BEHAVIAC_RELEASE
					node7.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node7);
					{
						DecoratorLog_bt_node_test_decoration_log_ut_0_node10 node10 = new DecoratorLog_bt_node_test_decoration_log_ut_0_node10();
						node10.SetClassNameString("DecoratorLog");
						node10.SetId(10);
#if !BEHAVIAC_RELEASE
						node10.SetAgentType("AgentNodeTest");
#endif
						node7.AddChild(node10);
						{
							Action_bt_node_test_decoration_log_ut_0_node12 node12 = new Action_bt_node_test_decoration_log_ut_0_node12();
							node12.SetClassNameString("Action");
							node12.SetId(12);
#if !BEHAVIAC_RELEASE
							node12.SetAgentType("AgentNodeTest");
#endif
							node10.AddChild(node12);
							node10.SetHasEvents(node10.HasEvents() | node12.HasEvents());
						}
						node7.SetHasEvents(node7.HasEvents() | node10.HasEvents());
					}
					{
						Action_bt_node_test_decoration_log_ut_0_node11 node11 = new Action_bt_node_test_decoration_log_ut_0_node11();
						node11.SetClassNameString("Action");
						node11.SetId(11);
#if !BEHAVIAC_RELEASE
						node11.SetAgentType("AgentNodeTest");
#endif
						node7.AddChild(node11);
						node7.SetHasEvents(node7.HasEvents() | node11.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node7.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/decoration_loopuntil_ut_0

	class Action_bt_node_test_decoration_loopuntil_ut_0_node4 : behaviac.Action
	{
		public Action_bt_node_test_decoration_loopuntil_ut_0_node4()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class DecoratorLoopUntil_bt_node_test_decoration_loopuntil_ut_0_node1 : behaviac.DecoratorLoopUntil
	{
		public DecoratorLoopUntil_bt_node_test_decoration_loopuntil_ut_0_node1()
		{
			m_bDecorateWhenChildEnds = true;
			m_until = true;
		}
		protected override int GetCount(Agent pAgent)
		{
			return -1;
		}
	}

	class DecoratorLoop_bt_node_test_decoration_loopuntil_ut_0_node2 : behaviac.DecoratorLoop
	{
		public DecoratorLoop_bt_node_test_decoration_loopuntil_ut_0_node2()
		{
			m_bDecorateWhenChildEnds = true;
		}
		protected override int GetCount(Agent pAgent)
		{
			return 100;
		}
	}

	class Action_bt_node_test_decoration_loopuntil_ut_0_node3 : behaviac.Action
	{
		public Action_bt_node_test_decoration_loopuntil_ut_0_node3()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	public static class bt_node_test_decoration_loopuntil_ut_0
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/decoration_loopuntil_ut_0");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Sequence node0 = new Sequence();
				node0.SetClassNameString("Sequence");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					Action_bt_node_test_decoration_loopuntil_ut_0_node4 node4 = new Action_bt_node_test_decoration_loopuntil_ut_0_node4();
					node4.SetClassNameString("Action");
					node4.SetId(4);
#if !BEHAVIAC_RELEASE
					node4.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node4);
					node0.SetHasEvents(node0.HasEvents() | node4.HasEvents());
				}
				{
					DecoratorLoopUntil_bt_node_test_decoration_loopuntil_ut_0_node1 node1 = new DecoratorLoopUntil_bt_node_test_decoration_loopuntil_ut_0_node1();
					node1.SetClassNameString("DecoratorLoopUntil");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					{
						DecoratorLoop_bt_node_test_decoration_loopuntil_ut_0_node2 node2 = new DecoratorLoop_bt_node_test_decoration_loopuntil_ut_0_node2();
						node2.SetClassNameString("DecoratorLoop");
						node2.SetId(2);
#if !BEHAVIAC_RELEASE
						node2.SetAgentType("AgentNodeTest");
#endif
						node1.AddChild(node2);
						{
							True node5 = new True();
							node5.SetClassNameString("True");
							node5.SetId(5);
#if !BEHAVIAC_RELEASE
							node5.SetAgentType("AgentNodeTest");
#endif
							node2.AddChild(node5);
							node2.SetHasEvents(node2.HasEvents() | node5.HasEvents());
						}
						node1.SetHasEvents(node1.HasEvents() | node2.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					Action_bt_node_test_decoration_loopuntil_ut_0_node3 node3 = new Action_bt_node_test_decoration_loopuntil_ut_0_node3();
					node3.SetClassNameString("Action");
					node3.SetId(3);
#if !BEHAVIAC_RELEASE
					node3.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node3);
					node0.SetHasEvents(node0.HasEvents() | node3.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/decoration_loopuntil_ut_1

	class Action_bt_node_test_decoration_loopuntil_ut_1_node4 : behaviac.Action
	{
		public Action_bt_node_test_decoration_loopuntil_ut_1_node4()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class DecoratorLoopUntil_bt_node_test_decoration_loopuntil_ut_1_node1 : behaviac.DecoratorLoopUntil
	{
		public DecoratorLoopUntil_bt_node_test_decoration_loopuntil_ut_1_node1()
		{
			m_bDecorateWhenChildEnds = false;
			m_until = true;
		}
		protected override int GetCount(Agent pAgent)
		{
			return 50;
		}
	}

	class DecoratorLoop_bt_node_test_decoration_loopuntil_ut_1_node2 : behaviac.DecoratorLoop
	{
		public DecoratorLoop_bt_node_test_decoration_loopuntil_ut_1_node2()
		{
			m_bDecorateWhenChildEnds = true;
		}
		protected override int GetCount(Agent pAgent)
		{
			return 100;
		}
	}

	class Action_bt_node_test_decoration_loopuntil_ut_1_node3 : behaviac.Action
	{
		public Action_bt_node_test_decoration_loopuntil_ut_1_node3()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	public static class bt_node_test_decoration_loopuntil_ut_1
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/decoration_loopuntil_ut_1");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Sequence node0 = new Sequence();
				node0.SetClassNameString("Sequence");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					Action_bt_node_test_decoration_loopuntil_ut_1_node4 node4 = new Action_bt_node_test_decoration_loopuntil_ut_1_node4();
					node4.SetClassNameString("Action");
					node4.SetId(4);
#if !BEHAVIAC_RELEASE
					node4.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node4);
					node0.SetHasEvents(node0.HasEvents() | node4.HasEvents());
				}
				{
					DecoratorLoopUntil_bt_node_test_decoration_loopuntil_ut_1_node1 node1 = new DecoratorLoopUntil_bt_node_test_decoration_loopuntil_ut_1_node1();
					node1.SetClassNameString("DecoratorLoopUntil");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					{
						DecoratorLoop_bt_node_test_decoration_loopuntil_ut_1_node2 node2 = new DecoratorLoop_bt_node_test_decoration_loopuntil_ut_1_node2();
						node2.SetClassNameString("DecoratorLoop");
						node2.SetId(2);
#if !BEHAVIAC_RELEASE
						node2.SetAgentType("AgentNodeTest");
#endif
						node1.AddChild(node2);
						{
							True node5 = new True();
							node5.SetClassNameString("True");
							node5.SetId(5);
#if !BEHAVIAC_RELEASE
							node5.SetAgentType("AgentNodeTest");
#endif
							node2.AddChild(node5);
							node2.SetHasEvents(node2.HasEvents() | node5.HasEvents());
						}
						node1.SetHasEvents(node1.HasEvents() | node2.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					Action_bt_node_test_decoration_loopuntil_ut_1_node3 node3 = new Action_bt_node_test_decoration_loopuntil_ut_1_node3();
					node3.SetClassNameString("Action");
					node3.SetId(3);
#if !BEHAVIAC_RELEASE
					node3.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node3);
					node0.SetHasEvents(node0.HasEvents() | node3.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/decoration_loopuntil_ut_2

	class Action_bt_node_test_decoration_loopuntil_ut_2_node4 : behaviac.Action
	{
		public Action_bt_node_test_decoration_loopuntil_ut_2_node4()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class DecoratorLoopUntil_bt_node_test_decoration_loopuntil_ut_2_node1 : behaviac.DecoratorLoopUntil
	{
		public DecoratorLoopUntil_bt_node_test_decoration_loopuntil_ut_2_node1()
		{
			m_bDecorateWhenChildEnds = true;
			m_until = true;
		}
		protected override int GetCount(Agent pAgent)
		{
			return 50;
		}
	}

	class DecoratorAlwaysFailure_bt_node_test_decoration_loopuntil_ut_2_node6 : behaviac.DecoratorAlwaysFailure
	{
		public DecoratorAlwaysFailure_bt_node_test_decoration_loopuntil_ut_2_node6()
		{
			m_bDecorateWhenChildEnds = false;
		}
	}

	class DecoratorLoop_bt_node_test_decoration_loopuntil_ut_2_node2 : behaviac.DecoratorLoop
	{
		public DecoratorLoop_bt_node_test_decoration_loopuntil_ut_2_node2()
		{
			m_bDecorateWhenChildEnds = true;
		}
		protected override int GetCount(Agent pAgent)
		{
			return 100;
		}
	}

	class Action_bt_node_test_decoration_loopuntil_ut_2_node3 : behaviac.Action
	{
		public Action_bt_node_test_decoration_loopuntil_ut_2_node3()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	public static class bt_node_test_decoration_loopuntil_ut_2
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/decoration_loopuntil_ut_2");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Sequence node0 = new Sequence();
				node0.SetClassNameString("Sequence");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					Action_bt_node_test_decoration_loopuntil_ut_2_node4 node4 = new Action_bt_node_test_decoration_loopuntil_ut_2_node4();
					node4.SetClassNameString("Action");
					node4.SetId(4);
#if !BEHAVIAC_RELEASE
					node4.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node4);
					node0.SetHasEvents(node0.HasEvents() | node4.HasEvents());
				}
				{
					DecoratorLoopUntil_bt_node_test_decoration_loopuntil_ut_2_node1 node1 = new DecoratorLoopUntil_bt_node_test_decoration_loopuntil_ut_2_node1();
					node1.SetClassNameString("DecoratorLoopUntil");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					{
						DecoratorAlwaysFailure_bt_node_test_decoration_loopuntil_ut_2_node6 node6 = new DecoratorAlwaysFailure_bt_node_test_decoration_loopuntil_ut_2_node6();
						node6.SetClassNameString("DecoratorAlwaysFailure");
						node6.SetId(6);
#if !BEHAVIAC_RELEASE
						node6.SetAgentType("AgentNodeTest");
#endif
						node1.AddChild(node6);
						{
							DecoratorLoop_bt_node_test_decoration_loopuntil_ut_2_node2 node2 = new DecoratorLoop_bt_node_test_decoration_loopuntil_ut_2_node2();
							node2.SetClassNameString("DecoratorLoop");
							node2.SetId(2);
#if !BEHAVIAC_RELEASE
							node2.SetAgentType("AgentNodeTest");
#endif
							node6.AddChild(node2);
							{
								True node5 = new True();
								node5.SetClassNameString("True");
								node5.SetId(5);
#if !BEHAVIAC_RELEASE
								node5.SetAgentType("AgentNodeTest");
#endif
								node2.AddChild(node5);
								node2.SetHasEvents(node2.HasEvents() | node5.HasEvents());
							}
							node6.SetHasEvents(node6.HasEvents() | node2.HasEvents());
						}
						node1.SetHasEvents(node1.HasEvents() | node6.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					Action_bt_node_test_decoration_loopuntil_ut_2_node3 node3 = new Action_bt_node_test_decoration_loopuntil_ut_2_node3();
					node3.SetClassNameString("Action");
					node3.SetId(3);
#if !BEHAVIAC_RELEASE
					node3.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node3);
					node0.SetHasEvents(node0.HasEvents() | node3.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/decoration_loop_ut_0

	class DecoratorLoop_bt_node_test_decoration_loop_ut_0_node0 : behaviac.DecoratorLoop
	{
		public DecoratorLoop_bt_node_test_decoration_loop_ut_0_node0()
		{
			m_bDecorateWhenChildEnds = true;
		}
		protected override int GetCount(Agent pAgent)
		{
			return -1;
		}
	}

	class Action_bt_node_test_decoration_loop_ut_0_node3 : behaviac.Action
	{
		public Action_bt_node_test_decoration_loop_ut_0_node3()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Action_bt_node_test_decoration_loop_ut_0_node2 : behaviac.Action
	{
		public Action_bt_node_test_decoration_loop_ut_0_node2()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	public static class bt_node_test_decoration_loop_ut_0
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/decoration_loop_ut_0");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Sequence node1 = new Sequence();
				node1.SetClassNameString("Sequence");
				node1.SetId(1);
#if !BEHAVIAC_RELEASE
				node1.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node1);
				{
					DecoratorLoop_bt_node_test_decoration_loop_ut_0_node0 node0 = new DecoratorLoop_bt_node_test_decoration_loop_ut_0_node0();
					node0.SetClassNameString("DecoratorLoop");
					node0.SetId(0);
#if !BEHAVIAC_RELEASE
					node0.SetAgentType("AgentNodeTest");
#endif
					node1.AddChild(node0);
					{
						Action_bt_node_test_decoration_loop_ut_0_node3 node3 = new Action_bt_node_test_decoration_loop_ut_0_node3();
						node3.SetClassNameString("Action");
						node3.SetId(3);
#if !BEHAVIAC_RELEASE
						node3.SetAgentType("AgentNodeTest");
#endif
						node0.AddChild(node3);
						node0.SetHasEvents(node0.HasEvents() | node3.HasEvents());
					}
					node1.SetHasEvents(node1.HasEvents() | node0.HasEvents());
				}
				{
					Action_bt_node_test_decoration_loop_ut_0_node2 node2 = new Action_bt_node_test_decoration_loop_ut_0_node2();
					node2.SetClassNameString("Action");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node1.AddChild(node2);
					node1.SetHasEvents(node1.HasEvents() | node2.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node1.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/decoration_loop_ut_1

	class DecoratorLoop_bt_node_test_decoration_loop_ut_1_node0 : behaviac.DecoratorLoop
	{
		public DecoratorLoop_bt_node_test_decoration_loop_ut_1_node0()
		{
			m_bDecorateWhenChildEnds = true;
		}
		protected override int GetCount(Agent pAgent)
		{
			return 500;
		}
	}

	class Action_bt_node_test_decoration_loop_ut_1_node3 : behaviac.Action
	{
		public Action_bt_node_test_decoration_loop_ut_1_node3()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_FAILURE;
		}
		int method_p0;
	}

	class Action_bt_node_test_decoration_loop_ut_1_node2 : behaviac.Action
	{
		public Action_bt_node_test_decoration_loop_ut_1_node2()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	public static class bt_node_test_decoration_loop_ut_1
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/decoration_loop_ut_1");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Sequence node1 = new Sequence();
				node1.SetClassNameString("Sequence");
				node1.SetId(1);
#if !BEHAVIAC_RELEASE
				node1.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node1);
				{
					DecoratorLoop_bt_node_test_decoration_loop_ut_1_node0 node0 = new DecoratorLoop_bt_node_test_decoration_loop_ut_1_node0();
					node0.SetClassNameString("DecoratorLoop");
					node0.SetId(0);
#if !BEHAVIAC_RELEASE
					node0.SetAgentType("AgentNodeTest");
#endif
					node1.AddChild(node0);
					{
						Action_bt_node_test_decoration_loop_ut_1_node3 node3 = new Action_bt_node_test_decoration_loop_ut_1_node3();
						node3.SetClassNameString("Action");
						node3.SetId(3);
#if !BEHAVIAC_RELEASE
						node3.SetAgentType("AgentNodeTest");
#endif
						node0.AddChild(node3);
						node0.SetHasEvents(node0.HasEvents() | node3.HasEvents());
					}
					node1.SetHasEvents(node1.HasEvents() | node0.HasEvents());
				}
				{
					Action_bt_node_test_decoration_loop_ut_1_node2 node2 = new Action_bt_node_test_decoration_loop_ut_1_node2();
					node2.SetClassNameString("Action");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node1.AddChild(node2);
					node1.SetHasEvents(node1.HasEvents() | node2.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node1.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/decoration_not_ut_0

	class DecoratorNot_bt_node_test_decoration_not_ut_0_node1 : behaviac.DecoratorNot
	{
		public DecoratorNot_bt_node_test_decoration_not_ut_0_node1()
		{
			m_bDecorateWhenChildEnds = false;
		}
	}

	class Action_bt_node_test_decoration_not_ut_0_node2 : behaviac.Action
	{
		public Action_bt_node_test_decoration_not_ut_0_node2()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_FAILURE;
		}
		int method_p0;
	}

	class Action_bt_node_test_decoration_not_ut_0_node3 : behaviac.Action
	{
		public Action_bt_node_test_decoration_not_ut_0_node3()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	public static class bt_node_test_decoration_not_ut_0
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/decoration_not_ut_0");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Sequence node0 = new Sequence();
				node0.SetClassNameString("Sequence");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					DecoratorNot_bt_node_test_decoration_not_ut_0_node1 node1 = new DecoratorNot_bt_node_test_decoration_not_ut_0_node1();
					node1.SetClassNameString("DecoratorNot");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					{
						Action_bt_node_test_decoration_not_ut_0_node2 node2 = new Action_bt_node_test_decoration_not_ut_0_node2();
						node2.SetClassNameString("Action");
						node2.SetId(2);
#if !BEHAVIAC_RELEASE
						node2.SetAgentType("AgentNodeTest");
#endif
						node1.AddChild(node2);
						node1.SetHasEvents(node1.HasEvents() | node2.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					Action_bt_node_test_decoration_not_ut_0_node3 node3 = new Action_bt_node_test_decoration_not_ut_0_node3();
					node3.SetClassNameString("Action");
					node3.SetId(3);
#if !BEHAVIAC_RELEASE
					node3.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node3);
					node0.SetHasEvents(node0.HasEvents() | node3.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/decoration_not_ut_1

	class DecoratorNot_bt_node_test_decoration_not_ut_1_node1 : behaviac.DecoratorNot
	{
		public DecoratorNot_bt_node_test_decoration_not_ut_1_node1()
		{
			m_bDecorateWhenChildEnds = false;
		}
	}

	class Action_bt_node_test_decoration_not_ut_1_node2 : behaviac.Action
	{
		public Action_bt_node_test_decoration_not_ut_1_node2()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Action_bt_node_test_decoration_not_ut_1_node3 : behaviac.Action
	{
		public Action_bt_node_test_decoration_not_ut_1_node3()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	public static class bt_node_test_decoration_not_ut_1
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/decoration_not_ut_1");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Sequence node0 = new Sequence();
				node0.SetClassNameString("Sequence");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					DecoratorNot_bt_node_test_decoration_not_ut_1_node1 node1 = new DecoratorNot_bt_node_test_decoration_not_ut_1_node1();
					node1.SetClassNameString("DecoratorNot");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					{
						Action_bt_node_test_decoration_not_ut_1_node2 node2 = new Action_bt_node_test_decoration_not_ut_1_node2();
						node2.SetClassNameString("Action");
						node2.SetId(2);
#if !BEHAVIAC_RELEASE
						node2.SetAgentType("AgentNodeTest");
#endif
						node1.AddChild(node2);
						node1.SetHasEvents(node1.HasEvents() | node2.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					Action_bt_node_test_decoration_not_ut_1_node3 node3 = new Action_bt_node_test_decoration_not_ut_1_node3();
					node3.SetClassNameString("Action");
					node3.SetId(3);
#if !BEHAVIAC_RELEASE
					node3.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node3);
					node0.SetHasEvents(node0.HasEvents() | node3.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/decoration_not_ut_2

	class DecoratorNot_bt_node_test_decoration_not_ut_2_node1 : behaviac.DecoratorNot
	{
		public DecoratorNot_bt_node_test_decoration_not_ut_2_node1()
		{
			m_bDecorateWhenChildEnds = false;
		}
	}

	class Action_bt_node_test_decoration_not_ut_2_node2 : behaviac.Action
	{
		public Action_bt_node_test_decoration_not_ut_2_node2()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_RUNNING;
		}
		int method_p0;
	}

	class Action_bt_node_test_decoration_not_ut_2_node3 : behaviac.Action
	{
		public Action_bt_node_test_decoration_not_ut_2_node3()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	public static class bt_node_test_decoration_not_ut_2
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/decoration_not_ut_2");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Sequence node0 = new Sequence();
				node0.SetClassNameString("Sequence");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					DecoratorNot_bt_node_test_decoration_not_ut_2_node1 node1 = new DecoratorNot_bt_node_test_decoration_not_ut_2_node1();
					node1.SetClassNameString("DecoratorNot");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					{
						Action_bt_node_test_decoration_not_ut_2_node2 node2 = new Action_bt_node_test_decoration_not_ut_2_node2();
						node2.SetClassNameString("Action");
						node2.SetId(2);
#if !BEHAVIAC_RELEASE
						node2.SetAgentType("AgentNodeTest");
#endif
						node1.AddChild(node2);
						node1.SetHasEvents(node1.HasEvents() | node2.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					Action_bt_node_test_decoration_not_ut_2_node3 node3 = new Action_bt_node_test_decoration_not_ut_2_node3();
					node3.SetClassNameString("Action");
					node3.SetId(3);
#if !BEHAVIAC_RELEASE
					node3.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node3);
					node0.SetHasEvents(node0.HasEvents() | node3.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/decoration_successuntil_ut_0

	class DecoratorSuccessUntil_bt_node_test_decoration_successuntil_ut_0_node0 : behaviac.DecoratorSuccessUntil
	{
		public DecoratorSuccessUntil_bt_node_test_decoration_successuntil_ut_0_node0()
		{
			m_bDecorateWhenChildEnds = true;
		}
		protected override int GetCount(Agent pAgent)
		{
			return -1;
		}
	}

	public static class bt_node_test_decoration_successuntil_ut_0
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/decoration_successuntil_ut_0");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				DecoratorSuccessUntil_bt_node_test_decoration_successuntil_ut_0_node0 node0 = new DecoratorSuccessUntil_bt_node_test_decoration_successuntil_ut_0_node0();
				node0.SetClassNameString("DecoratorSuccessUntil");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					False node1 = new False();
					node1.SetClassNameString("False");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/decoration_successuntil_ut_1

	class DecoratorSuccessUntil_bt_node_test_decoration_successuntil_ut_1_node0 : behaviac.DecoratorSuccessUntil
	{
		public DecoratorSuccessUntil_bt_node_test_decoration_successuntil_ut_1_node0()
		{
			m_bDecorateWhenChildEnds = true;
		}
		protected override int GetCount(Agent pAgent)
		{
			return 5;
		}
	}

	public static class bt_node_test_decoration_successuntil_ut_1
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/decoration_successuntil_ut_1");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				DecoratorSuccessUntil_bt_node_test_decoration_successuntil_ut_1_node0 node0 = new DecoratorSuccessUntil_bt_node_test_decoration_successuntil_ut_1_node0();
				node0.SetClassNameString("DecoratorSuccessUntil");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					False node1 = new False();
					node1.SetClassNameString("False");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/enter_exit_action_ut_0

	class Sequence_bt_node_test_enter_exit_action_ut_0_node0 : behaviac.Sequence
	{
		public Sequence_bt_node_test_enter_exit_action_ut_0_node0()
		{
			EnterAction_p0 = 0f;
			ExitAction_p0 = 0f;
		}
		public override bool enteraction_impl(Agent pAgent)
		{
			((AgentNodeTest)pAgent).enter_action_1(EnterAction_p0);
			return true;
		}
		public override bool exitaction_impl(Agent pAgent)
		{
			((AgentNodeTest)pAgent).exit_action_1(ExitAction_p0);
			return true;
		}
		float EnterAction_p0;
		float ExitAction_p0;
	}

	class Selector_bt_node_test_enter_exit_action_ut_0_node1 : behaviac.Selector
	{
		public Selector_bt_node_test_enter_exit_action_ut_0_node1()
		{
			EnterAction_p0 = 0;
			EnterAction_p1 = "";
			ExitAction_p0 = 0;
			ExitAction_p1 = "";
		}
		public override bool enteraction_impl(Agent pAgent)
		{
			((AgentNodeTest)pAgent).enter_action_2(EnterAction_p0, EnterAction_p1);
			return true;
		}
		public override bool exitaction_impl(Agent pAgent)
		{
			((AgentNodeTest)pAgent).exit_action_2(ExitAction_p0, ExitAction_p1);
			return true;
		}
		int EnterAction_p0;
		string EnterAction_p1;
		int ExitAction_p0;
		string ExitAction_p1;
	}

	class Predicate_bt_node_test_enter_exit_action_ut_0_attach5 : behaviac.Predicate
	{
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_FAILURE;
			this.m_bAnd = true;
			int opl = ((AgentNodeTest)pAgent).testVar_0;
			int opr = 0;
			bool op = opl == opr;
			if (op)
				result = EBTStatus.BT_SUCCESS;
			return result;
		}
	}

	public static class bt_node_test_enter_exit_action_ut_0
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/enter_exit_action_ut_0");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Sequence_bt_node_test_enter_exit_action_ut_0_node0 node0 = new Sequence_bt_node_test_enter_exit_action_ut_0_node0();
				node0.SetClassNameString("Sequence");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					Selector_bt_node_test_enter_exit_action_ut_0_node1 node1 = new Selector_bt_node_test_enter_exit_action_ut_0_node1();
					node1.SetClassNameString("Selector");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					{
						WaitforSignal node3 = new WaitforSignal();
						node3.SetClassNameString("WaitforSignal");
						node3.SetId(3);
#if !BEHAVIAC_RELEASE
						node3.SetAgentType("AgentNodeTest");
#endif
						// attachments
						{
							Predicate_bt_node_test_enter_exit_action_ut_0_attach5 attach5 = new Predicate_bt_node_test_enter_exit_action_ut_0_attach5();
							attach5.SetClassNameString("Predicate");
							attach5.SetId(5);
#if !BEHAVIAC_RELEASE
							attach5.SetAgentType("AgentNodeTest");
#endif
							node3.Attach(attach5);
						}
						node1.AddChild(node3);
						node1.SetHasEvents(node1.HasEvents() | node3.HasEvents());
					}
					{
						True node4 = new True();
						node4.SetClassNameString("True");
						node4.SetId(4);
#if !BEHAVIAC_RELEASE
						node4.SetAgentType("AgentNodeTest");
#endif
						node1.AddChild(node4);
						node1.SetHasEvents(node1.HasEvents() | node4.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					True node2 = new True();
					node2.SetClassNameString("True");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/enter_exit_action_ut_1

	class Parallel_bt_node_test_enter_exit_action_ut_1_node0 : behaviac.Parallel
	{
		public Parallel_bt_node_test_enter_exit_action_ut_1_node0()
		{
			EnterAction_p0 = 0f;
			ExitAction_p0 = 0f;
			m_failPolicy = behaviac.FAILURE_POLICY.FAIL_ON_ONE;
			m_succeedPolicy = behaviac.SUCCESS_POLICY.SUCCEED_ON_ALL;
			m_exitPolicy = behaviac.EXIT_POLICY.EXIT_ABORT_RUNNINGSIBLINGS;
			m_childFinishPolicy = behaviac.CHILDFINISH_POLICY.CHILDFINISH_LOOP;
		}
		public override bool enteraction_impl(Agent pAgent)
		{
			((AgentNodeTest)pAgent).enter_action_1(EnterAction_p0);
			return true;
		}
		public override bool exitaction_impl(Agent pAgent)
		{
			((AgentNodeTest)pAgent).exit_action_1(ExitAction_p0);
			return true;
		}
		float EnterAction_p0;
		float ExitAction_p0;
	}

	class WaitforSignal_bt_node_test_enter_exit_action_ut_1_node3 : behaviac.WaitforSignal
	{
		public WaitforSignal_bt_node_test_enter_exit_action_ut_1_node3()
		{
			EnterAction_p0 = 3;
			EnterAction_p1 = "hello";
			ExitAction_p0 = 5;
			ExitAction_p1 = "world";
		}
		public override bool enteraction_impl(Agent pAgent)
		{
			((AgentNodeTest)pAgent).enter_action_2(EnterAction_p0, EnterAction_p1);
			return true;
		}
		public override bool exitaction_impl(Agent pAgent)
		{
			((AgentNodeTest)pAgent).exit_action_2(ExitAction_p0, ExitAction_p1);
			return true;
		}
		int EnterAction_p0;
		string EnterAction_p1;
		int ExitAction_p0;
		string ExitAction_p1;
	}

	class Predicate_bt_node_test_enter_exit_action_ut_1_attach5 : behaviac.Predicate
	{
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_FAILURE;
			this.m_bAnd = true;
			int opl = ((AgentNodeTest)pAgent).testVar_0;
			int opr = 0;
			bool op = opl == opr;
			if (op)
				result = EBTStatus.BT_SUCCESS;
			return result;
		}
	}

	public static class bt_node_test_enter_exit_action_ut_1
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/enter_exit_action_ut_1");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Parallel_bt_node_test_enter_exit_action_ut_1_node0 node0 = new Parallel_bt_node_test_enter_exit_action_ut_1_node0();
				node0.SetClassNameString("Parallel");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					WaitforSignal_bt_node_test_enter_exit_action_ut_1_node3 node3 = new WaitforSignal_bt_node_test_enter_exit_action_ut_1_node3();
					node3.SetClassNameString("WaitforSignal");
					node3.SetId(3);
#if !BEHAVIAC_RELEASE
					node3.SetAgentType("AgentNodeTest");
#endif
					// attachments
					{
						Predicate_bt_node_test_enter_exit_action_ut_1_attach5 attach5 = new Predicate_bt_node_test_enter_exit_action_ut_1_attach5();
						attach5.SetClassNameString("Predicate");
						attach5.SetId(5);
#if !BEHAVIAC_RELEASE
						attach5.SetAgentType("AgentNodeTest");
#endif
						node3.Attach(attach5);
					}
					node0.AddChild(node3);
					node0.SetHasEvents(node0.HasEvents() | node3.HasEvents());
				}
				{
					True node4 = new True();
					node4.SetClassNameString("True");
					node4.SetId(4);
#if !BEHAVIAC_RELEASE
					node4.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node4);
					node0.SetHasEvents(node0.HasEvents() | node4.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/enter_exit_action_ut_2

	class Parallel_bt_node_test_enter_exit_action_ut_2_node0 : behaviac.Parallel
	{
		public Parallel_bt_node_test_enter_exit_action_ut_2_node0()
		{
			EnterAction_p0 = 0f;
			ExitAction_p0 = 0f;
			m_failPolicy = behaviac.FAILURE_POLICY.FAIL_ON_ONE;
			m_succeedPolicy = behaviac.SUCCESS_POLICY.SUCCEED_ON_ALL;
			m_exitPolicy = behaviac.EXIT_POLICY.EXIT_ABORT_RUNNINGSIBLINGS;
			m_childFinishPolicy = behaviac.CHILDFINISH_POLICY.CHILDFINISH_LOOP;
		}
		public override bool enteraction_impl(Agent pAgent)
		{
			((AgentNodeTest)pAgent).enter_action_1(EnterAction_p0);
			return true;
		}
		public override bool exitaction_impl(Agent pAgent)
		{
			((AgentNodeTest)pAgent).exit_action_1(ExitAction_p0);
			return true;
		}
		float EnterAction_p0;
		float ExitAction_p0;
	}

	class WaitforSignal_bt_node_test_enter_exit_action_ut_2_node3 : behaviac.WaitforSignal
	{
		public WaitforSignal_bt_node_test_enter_exit_action_ut_2_node3()
		{
			EnterAction_p0 = 3;
			EnterAction_p1 = "hello";
			ExitAction_p0 = 5;
			ExitAction_p1 = "world";
		}
		public override bool enteraction_impl(Agent pAgent)
		{
			((AgentNodeTest)pAgent).enter_action_2(EnterAction_p0, EnterAction_p1);
			return true;
		}
		public override bool exitaction_impl(Agent pAgent)
		{
			((AgentNodeTest)pAgent).exit_action_2(ExitAction_p0, ExitAction_p1);
			return true;
		}
		int EnterAction_p0;
		string EnterAction_p1;
		int ExitAction_p0;
		string ExitAction_p1;
	}

	class Predicate_bt_node_test_enter_exit_action_ut_2_attach5 : behaviac.Predicate
	{
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_FAILURE;
			this.m_bAnd = true;
			int opl = ((AgentNodeTest)pAgent).testVar_0;
			int opr = 0;
			bool op = opl == opr;
			if (op)
				result = EBTStatus.BT_SUCCESS;
			return result;
		}
	}

	class Action_bt_node_test_enter_exit_action_ut_2_node1 : behaviac.Action
	{
		public Action_bt_node_test_enter_exit_action_ut_2_node1()
		{
			method_p0 = 0f;
		}
		public override bool enteraction_impl(Agent pAgent)
		{
			((AgentNodeTest)pAgent).enter_action_0();
			return true;
		}
		public override bool exitaction_impl(Agent pAgent)
		{
			((AgentNodeTest)pAgent).exit_action_0();
			return true;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_3(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		float method_p0;
	}

	public static class bt_node_test_enter_exit_action_ut_2
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/enter_exit_action_ut_2");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Parallel_bt_node_test_enter_exit_action_ut_2_node0 node0 = new Parallel_bt_node_test_enter_exit_action_ut_2_node0();
				node0.SetClassNameString("Parallel");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					WaitforSignal_bt_node_test_enter_exit_action_ut_2_node3 node3 = new WaitforSignal_bt_node_test_enter_exit_action_ut_2_node3();
					node3.SetClassNameString("WaitforSignal");
					node3.SetId(3);
#if !BEHAVIAC_RELEASE
					node3.SetAgentType("AgentNodeTest");
#endif
					// attachments
					{
						Predicate_bt_node_test_enter_exit_action_ut_2_attach5 attach5 = new Predicate_bt_node_test_enter_exit_action_ut_2_attach5();
						attach5.SetClassNameString("Predicate");
						attach5.SetId(5);
#if !BEHAVIAC_RELEASE
						attach5.SetAgentType("AgentNodeTest");
#endif
						node3.Attach(attach5);
					}
					node0.AddChild(node3);
					node0.SetHasEvents(node0.HasEvents() | node3.HasEvents());
				}
				{
					Action_bt_node_test_enter_exit_action_ut_2_node1 node1 = new Action_bt_node_test_enter_exit_action_ut_2_node1();
					node1.SetClassNameString("Action");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/event_subtree_0

	class Action_bt_node_test_event_subtree_0_node2 : behaviac.Action
	{
		public Action_bt_node_test_event_subtree_0_node2()
		{
			method_p0 = true;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setEventVarBool(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		bool method_p0;
	}

	public static class bt_node_test_event_subtree_0
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/event_subtree_0");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Sequence node0 = new Sequence();
				node0.SetClassNameString("Sequence");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					True node1 = new True();
					node1.SetClassNameString("True");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					Action_bt_node_test_event_subtree_0_node2 node2 = new Action_bt_node_test_event_subtree_0_node2();
					node2.SetClassNameString("Action");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/event_subtree_1

	class Action_bt_node_test_event_subtree_1_node2 : behaviac.Action
	{
		public Action_bt_node_test_event_subtree_1_node2()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			Debug.Check(behaviac.Utils.MakeVariableId("par_event_param_int") == 792119655u);
			int method_p0 = pAgent.GetVariable<int>(792119655u);
			((AgentNodeTest)pAgent).setEventVarInt(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
	}

	public static class bt_node_test_event_subtree_1
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/event_subtree_1");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// pars
			bt.AddPar("int", "par_event_param_int", "0", "");
			// children
			{
				Sequence node0 = new Sequence();
				node0.SetClassNameString("Sequence");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					True node1 = new True();
					node1.SetClassNameString("True");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					Action_bt_node_test_event_subtree_1_node2 node2 = new Action_bt_node_test_event_subtree_1_node2();
					node2.SetClassNameString("Action");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/event_subtree_2

	class Action_bt_node_test_event_subtree_2_node1 : behaviac.Action
	{
		public Action_bt_node_test_event_subtree_2_node1()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			Debug.Check(behaviac.Utils.MakeVariableId("par_event_param_int") == 792119655u);
			int method_p0 = pAgent.GetVariable<int>(792119655u);
			((AgentNodeTest)pAgent).setEventVarInt(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_node_test_event_subtree_2_node2 : behaviac.Action
	{
		public Action_bt_node_test_event_subtree_2_node2()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			Debug.Check(behaviac.Utils.MakeVariableId("par_event_param_int_bool") == 1932497425u);
			bool method_p0 = pAgent.GetVariable<bool>(1932497425u);
			((AgentNodeTest)pAgent).setEventVarBool(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
	}

	public static class bt_node_test_event_subtree_2
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/event_subtree_2");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// pars
			bt.AddPar("int", "par_event_param_int", "0", "AgentNodeTest::event_test_int_bool::param0");
			bt.AddPar("bool", "par_event_param_int_bool", "false", "AgentNodeTest::event_test_int_bool::param1");
			// children
			{
				Sequence node0 = new Sequence();
				node0.SetClassNameString("Sequence");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					Action_bt_node_test_event_subtree_2_node1 node1 = new Action_bt_node_test_event_subtree_2_node1();
					node1.SetClassNameString("Action");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					Action_bt_node_test_event_subtree_2_node2 node2 = new Action_bt_node_test_event_subtree_2_node2();
					node2.SetClassNameString("Action");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/event_subtree_3

	class Action_bt_node_test_event_subtree_3_node1 : behaviac.Action
	{
		public Action_bt_node_test_event_subtree_3_node1()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			Debug.Check(behaviac.Utils.MakeVariableId("par_event_param_int") == 792119655u);
			int method_p0 = pAgent.GetVariable<int>(792119655u);
			((AgentNodeTest)pAgent).setEventVarInt(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_node_test_event_subtree_3_node2 : behaviac.Action
	{
		public Action_bt_node_test_event_subtree_3_node2()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			Debug.Check(behaviac.Utils.MakeVariableId("par_event_param_bool") == 3197856147u);
			bool method_p0 = pAgent.GetVariable<bool>(3197856147u);
			((AgentNodeTest)pAgent).setEventVarBool(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_node_test_event_subtree_3_node3 : behaviac.Action
	{
		public Action_bt_node_test_event_subtree_3_node3()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			Debug.Check(behaviac.Utils.MakeVariableId("par_event_param_float") == 3044113742u);
			float method_p0 = pAgent.GetVariable<float>(3044113742u);
			((AgentNodeTest)pAgent).setEventVarFloat(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
	}

	public static class bt_node_test_event_subtree_3
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/event_subtree_3");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// pars
			bt.AddPar("int", "par_event_param_int", "0", "");
			bt.AddPar("bool", "par_event_param_bool", "false", "");
			bt.AddPar("float", "par_event_param_float", "0", "");
			// children
			{
				Sequence node0 = new Sequence();
				node0.SetClassNameString("Sequence");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					Action_bt_node_test_event_subtree_3_node1 node1 = new Action_bt_node_test_event_subtree_3_node1();
					node1.SetClassNameString("Action");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					Action_bt_node_test_event_subtree_3_node2 node2 = new Action_bt_node_test_event_subtree_3_node2();
					node2.SetClassNameString("Action");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				{
					Action_bt_node_test_event_subtree_3_node3 node3 = new Action_bt_node_test_event_subtree_3_node3();
					node3.SetClassNameString("Action");
					node3.SetId(3);
#if !BEHAVIAC_RELEASE
					node3.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node3);
					node0.SetHasEvents(node0.HasEvents() | node3.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/event_ut_0

	class Event_bt_node_test_event_ut_0_attach1 : behaviac.Event
	{
		public void Initialize(string eventName, string referencedBehavior, TriggerMode mode, bool once)
		{
			this.m_event = Action.LoadMethod(eventName);
			this.m_referencedBehaviorPath = referencedBehavior;
			this.m_triggerMode = mode;
			this.m_bTriggeredOnce = once;
		}
	}

	class Event_bt_node_test_event_ut_0_attach2 : behaviac.Event
	{
		public void Initialize(string eventName, string referencedBehavior, TriggerMode mode, bool once)
		{
			this.m_event = Action.LoadMethod(eventName);
			this.m_referencedBehaviorPath = referencedBehavior;
			this.m_triggerMode = mode;
			this.m_bTriggeredOnce = once;
		}
	}

	class Event_bt_node_test_event_ut_0_attach3 : behaviac.Event
	{
		public void Initialize(string eventName, string referencedBehavior, TriggerMode mode, bool once)
		{
			this.m_event = Action.LoadMethod(eventName);
			this.m_referencedBehaviorPath = referencedBehavior;
			this.m_triggerMode = mode;
			this.m_bTriggeredOnce = once;
		}
	}

	class Event_bt_node_test_event_ut_0_attach4 : behaviac.Event
	{
		public void Initialize(string eventName, string referencedBehavior, TriggerMode mode, bool once)
		{
			this.m_event = Action.LoadMethod(eventName);
			this.m_referencedBehaviorPath = referencedBehavior;
			this.m_triggerMode = mode;
			this.m_bTriggeredOnce = once;
		}
	}

	class Predicate_bt_node_test_event_ut_0_attach6 : behaviac.Predicate
	{
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_FAILURE;
			this.m_bAnd = true;
			int opl = ((AgentNodeTest)pAgent).testVar_0;
			int opr = 0;
			bool op = opl == opr;
			if (op)
				result = EBTStatus.BT_SUCCESS;
			return result;
		}
	}

	class Action_bt_node_test_event_ut_0_node7 : behaviac.Action
	{
		public Action_bt_node_test_event_ut_0_node7()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_1(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	public static class bt_node_test_event_ut_0
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/event_ut_0");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// attachments
			{
				Event_bt_node_test_event_ut_0_attach1 attach1 = new Event_bt_node_test_event_ut_0_attach1();
				attach1.SetClassNameString("Event");
				attach1.SetId(1);
#if !BEHAVIAC_RELEASE
				attach1.SetAgentType("AgentNodeTest");
#endif
				attach1.Initialize("Self.AgentNodeTest::event_test_void()", "node_test/event_subtree_0", TriggerMode.TM_Return, false);
				bt.Attach(attach1);
				bt.SetHasEvents(bt.HasEvents() | (attach1 is Event));
			}
			{
				Event_bt_node_test_event_ut_0_attach2 attach2 = new Event_bt_node_test_event_ut_0_attach2();
				attach2.SetClassNameString("Event");
				attach2.SetId(2);
#if !BEHAVIAC_RELEASE
				attach2.SetAgentType("AgentNodeTest");
#endif
				attach2.Initialize("Self.AgentNodeTest::event_test_int(0)", "node_test/event_subtree_1", TriggerMode.TM_Return, false);
				// pars
				attach2.AddPar("int", "par_event_param_int", "0", "AgentNodeTest::event_test_int::param0");
				bt.Attach(attach2);
				bt.SetHasEvents(bt.HasEvents() | (attach2 is Event));
			}
			{
				Event_bt_node_test_event_ut_0_attach3 attach3 = new Event_bt_node_test_event_ut_0_attach3();
				attach3.SetClassNameString("Event");
				attach3.SetId(3);
#if !BEHAVIAC_RELEASE
				attach3.SetAgentType("AgentNodeTest");
#endif
				attach3.Initialize("Self.AgentNodeTest::event_test_int_bool(0,false)", "node_test/event_subtree_2", TriggerMode.TM_Return, false);
				// pars
				attach3.AddPar("int", "par_event_param_int", "0", "AgentNodeTest::event_test_int_bool::param0");
				attach3.AddPar("bool", "par_event_param_int_bool", "false", "AgentNodeTest::event_test_int_bool::param1");
				bt.Attach(attach3);
				bt.SetHasEvents(bt.HasEvents() | (attach3 is Event));
			}
			{
				Event_bt_node_test_event_ut_0_attach4 attach4 = new Event_bt_node_test_event_ut_0_attach4();
				attach4.SetClassNameString("Event");
				attach4.SetId(4);
#if !BEHAVIAC_RELEASE
				attach4.SetAgentType("AgentNodeTest");
#endif
				attach4.Initialize("Self.AgentNodeTest::event_test_int_bool_float(0,false,0)", "node_test/event_subtree_3", TriggerMode.TM_Return, false);
				// pars
				attach4.AddPar("int", "par_event_param_int", "0", "AgentNodeTest::event_test_int_bool_float::param0");
				attach4.AddPar("bool", "par_event_param_bool", "false", "AgentNodeTest::event_test_int_bool_float::param1");
				attach4.AddPar("float", "par_event_param_float", "0", "AgentNodeTest::event_test_int_bool_float::param2");
				bt.Attach(attach4);
				bt.SetHasEvents(bt.HasEvents() | (attach4 is Event));
			}
			// children
			{
				Sequence node0 = new Sequence();
				node0.SetClassNameString("Sequence");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					WaitforSignal node5 = new WaitforSignal();
					node5.SetClassNameString("WaitforSignal");
					node5.SetId(5);
#if !BEHAVIAC_RELEASE
					node5.SetAgentType("AgentNodeTest");
#endif
					// attachments
					{
						Predicate_bt_node_test_event_ut_0_attach6 attach6 = new Predicate_bt_node_test_event_ut_0_attach6();
						attach6.SetClassNameString("Predicate");
						attach6.SetId(6);
#if !BEHAVIAC_RELEASE
						attach6.SetAgentType("AgentNodeTest");
#endif
						node5.Attach(attach6);
					}
					node0.AddChild(node5);
					node0.SetHasEvents(node0.HasEvents() | node5.HasEvents());
				}
				{
					Action_bt_node_test_event_ut_0_node7 node7 = new Action_bt_node_test_event_ut_0_node7();
					node7.SetClassNameString("Action");
					node7.SetId(7);
#if !BEHAVIAC_RELEASE
					node7.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node7);
					node0.SetHasEvents(node0.HasEvents() | node7.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/if_else_ut_0

	class Action_bt_node_test_if_else_ut_0_node2 : behaviac.Action
	{
		public Action_bt_node_test_if_else_ut_0_node2()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Action_bt_node_test_if_else_ut_0_node3 : behaviac.Action
	{
		public Action_bt_node_test_if_else_ut_0_node3()
		{
			method_p0 = 2;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	public static class bt_node_test_if_else_ut_0
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/if_else_ut_0");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				IfElse node0 = new IfElse();
				node0.SetClassNameString("IfElse");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					True node1 = new True();
					node1.SetClassNameString("True");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					Action_bt_node_test_if_else_ut_0_node2 node2 = new Action_bt_node_test_if_else_ut_0_node2();
					node2.SetClassNameString("Action");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				{
					Action_bt_node_test_if_else_ut_0_node3 node3 = new Action_bt_node_test_if_else_ut_0_node3();
					node3.SetClassNameString("Action");
					node3.SetId(3);
#if !BEHAVIAC_RELEASE
					node3.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node3);
					node0.SetHasEvents(node0.HasEvents() | node3.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/if_else_ut_1

	class Action_bt_node_test_if_else_ut_1_node2 : behaviac.Action
	{
		public Action_bt_node_test_if_else_ut_1_node2()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Action_bt_node_test_if_else_ut_1_node3 : behaviac.Action
	{
		public Action_bt_node_test_if_else_ut_1_node3()
		{
			method_p0 = 2;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	public static class bt_node_test_if_else_ut_1
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/if_else_ut_1");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				IfElse node0 = new IfElse();
				node0.SetClassNameString("IfElse");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					False node1 = new False();
					node1.SetClassNameString("False");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					Action_bt_node_test_if_else_ut_1_node2 node2 = new Action_bt_node_test_if_else_ut_1_node2();
					node2.SetClassNameString("Action");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				{
					Action_bt_node_test_if_else_ut_1_node3 node3 = new Action_bt_node_test_if_else_ut_1_node3();
					node3.SetClassNameString("Action");
					node3.SetId(3);
#if !BEHAVIAC_RELEASE
					node3.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node3);
					node0.SetHasEvents(node0.HasEvents() | node3.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/parallel_ut_0

	class Parallel_bt_node_test_parallel_ut_0_node0 : behaviac.Parallel
	{
		public Parallel_bt_node_test_parallel_ut_0_node0()
		{
			m_failPolicy = behaviac.FAILURE_POLICY.FAIL_ON_ONE;
			m_succeedPolicy = behaviac.SUCCESS_POLICY.SUCCEED_ON_ALL;
			m_exitPolicy = behaviac.EXIT_POLICY.EXIT_ABORT_RUNNINGSIBLINGS;
			m_childFinishPolicy = behaviac.CHILDFINISH_POLICY.CHILDFINISH_LOOP;
		}
	}

	class Action_bt_node_test_parallel_ut_0_node3 : behaviac.Action
	{
		public Action_bt_node_test_parallel_ut_0_node3()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_FAILURE;
		}
		int method_p0;
	}

	class Action_bt_node_test_parallel_ut_0_node4 : behaviac.Action
	{
		public Action_bt_node_test_parallel_ut_0_node4()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Action_bt_node_test_parallel_ut_0_node5 : behaviac.Action
	{
		public Action_bt_node_test_parallel_ut_0_node5()
		{
			method_p0 = 2;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Action_bt_node_test_parallel_ut_0_node2 : behaviac.Action
	{
		public Action_bt_node_test_parallel_ut_0_node2()
		{
			method_p0 = 3;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	public static class bt_node_test_parallel_ut_0
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/parallel_ut_0");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Sequence node1 = new Sequence();
				node1.SetClassNameString("Sequence");
				node1.SetId(1);
#if !BEHAVIAC_RELEASE
				node1.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node1);
				{
					Parallel_bt_node_test_parallel_ut_0_node0 node0 = new Parallel_bt_node_test_parallel_ut_0_node0();
					node0.SetClassNameString("Parallel");
					node0.SetId(0);
#if !BEHAVIAC_RELEASE
					node0.SetAgentType("AgentNodeTest");
#endif
					node1.AddChild(node0);
					{
						Action_bt_node_test_parallel_ut_0_node3 node3 = new Action_bt_node_test_parallel_ut_0_node3();
						node3.SetClassNameString("Action");
						node3.SetId(3);
#if !BEHAVIAC_RELEASE
						node3.SetAgentType("AgentNodeTest");
#endif
						node0.AddChild(node3);
						node0.SetHasEvents(node0.HasEvents() | node3.HasEvents());
					}
					{
						Action_bt_node_test_parallel_ut_0_node4 node4 = new Action_bt_node_test_parallel_ut_0_node4();
						node4.SetClassNameString("Action");
						node4.SetId(4);
#if !BEHAVIAC_RELEASE
						node4.SetAgentType("AgentNodeTest");
#endif
						node0.AddChild(node4);
						node0.SetHasEvents(node0.HasEvents() | node4.HasEvents());
					}
					{
						Action_bt_node_test_parallel_ut_0_node5 node5 = new Action_bt_node_test_parallel_ut_0_node5();
						node5.SetClassNameString("Action");
						node5.SetId(5);
#if !BEHAVIAC_RELEASE
						node5.SetAgentType("AgentNodeTest");
#endif
						node0.AddChild(node5);
						node0.SetHasEvents(node0.HasEvents() | node5.HasEvents());
					}
					node1.SetHasEvents(node1.HasEvents() | node0.HasEvents());
				}
				{
					Action_bt_node_test_parallel_ut_0_node2 node2 = new Action_bt_node_test_parallel_ut_0_node2();
					node2.SetClassNameString("Action");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node1.AddChild(node2);
					node1.SetHasEvents(node1.HasEvents() | node2.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node1.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/parallel_ut_1

	class Parallel_bt_node_test_parallel_ut_1_node0 : behaviac.Parallel
	{
		public Parallel_bt_node_test_parallel_ut_1_node0()
		{
			m_failPolicy = behaviac.FAILURE_POLICY.FAIL_ON_ONE;
			m_succeedPolicy = behaviac.SUCCESS_POLICY.SUCCEED_ON_ALL;
			m_exitPolicy = behaviac.EXIT_POLICY.EXIT_ABORT_RUNNINGSIBLINGS;
			m_childFinishPolicy = behaviac.CHILDFINISH_POLICY.CHILDFINISH_LOOP;
		}
	}

	class Action_bt_node_test_parallel_ut_1_node3 : behaviac.Action
	{
		public Action_bt_node_test_parallel_ut_1_node3()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Action_bt_node_test_parallel_ut_1_node4 : behaviac.Action
	{
		public Action_bt_node_test_parallel_ut_1_node4()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Action_bt_node_test_parallel_ut_1_node5 : behaviac.Action
	{
		public Action_bt_node_test_parallel_ut_1_node5()
		{
			method_p0 = 2;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Action_bt_node_test_parallel_ut_1_node2 : behaviac.Action
	{
		public Action_bt_node_test_parallel_ut_1_node2()
		{
			method_p0 = 3;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	public static class bt_node_test_parallel_ut_1
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/parallel_ut_1");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Sequence node1 = new Sequence();
				node1.SetClassNameString("Sequence");
				node1.SetId(1);
#if !BEHAVIAC_RELEASE
				node1.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node1);
				{
					Parallel_bt_node_test_parallel_ut_1_node0 node0 = new Parallel_bt_node_test_parallel_ut_1_node0();
					node0.SetClassNameString("Parallel");
					node0.SetId(0);
#if !BEHAVIAC_RELEASE
					node0.SetAgentType("AgentNodeTest");
#endif
					node1.AddChild(node0);
					{
						Action_bt_node_test_parallel_ut_1_node3 node3 = new Action_bt_node_test_parallel_ut_1_node3();
						node3.SetClassNameString("Action");
						node3.SetId(3);
#if !BEHAVIAC_RELEASE
						node3.SetAgentType("AgentNodeTest");
#endif
						node0.AddChild(node3);
						node0.SetHasEvents(node0.HasEvents() | node3.HasEvents());
					}
					{
						Action_bt_node_test_parallel_ut_1_node4 node4 = new Action_bt_node_test_parallel_ut_1_node4();
						node4.SetClassNameString("Action");
						node4.SetId(4);
#if !BEHAVIAC_RELEASE
						node4.SetAgentType("AgentNodeTest");
#endif
						node0.AddChild(node4);
						node0.SetHasEvents(node0.HasEvents() | node4.HasEvents());
					}
					{
						Action_bt_node_test_parallel_ut_1_node5 node5 = new Action_bt_node_test_parallel_ut_1_node5();
						node5.SetClassNameString("Action");
						node5.SetId(5);
#if !BEHAVIAC_RELEASE
						node5.SetAgentType("AgentNodeTest");
#endif
						node0.AddChild(node5);
						node0.SetHasEvents(node0.HasEvents() | node5.HasEvents());
					}
					node1.SetHasEvents(node1.HasEvents() | node0.HasEvents());
				}
				{
					Action_bt_node_test_parallel_ut_1_node2 node2 = new Action_bt_node_test_parallel_ut_1_node2();
					node2.SetClassNameString("Action");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node1.AddChild(node2);
					node1.SetHasEvents(node1.HasEvents() | node2.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node1.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/parallel_ut_2

	class Parallel_bt_node_test_parallel_ut_2_node0 : behaviac.Parallel
	{
		public Parallel_bt_node_test_parallel_ut_2_node0()
		{
			m_failPolicy = behaviac.FAILURE_POLICY.FAIL_ON_ALL;
			m_succeedPolicy = behaviac.SUCCESS_POLICY.SUCCEED_ON_ALL;
			m_exitPolicy = behaviac.EXIT_POLICY.EXIT_ABORT_RUNNINGSIBLINGS;
			m_childFinishPolicy = behaviac.CHILDFINISH_POLICY.CHILDFINISH_LOOP;
		}
	}

	class Action_bt_node_test_parallel_ut_2_node3 : behaviac.Action
	{
		public Action_bt_node_test_parallel_ut_2_node3()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_FAILURE;
		}
		int method_p0;
	}

	class Action_bt_node_test_parallel_ut_2_node4 : behaviac.Action
	{
		public Action_bt_node_test_parallel_ut_2_node4()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Action_bt_node_test_parallel_ut_2_node5 : behaviac.Action
	{
		public Action_bt_node_test_parallel_ut_2_node5()
		{
			method_p0 = 2;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Action_bt_node_test_parallel_ut_2_node2 : behaviac.Action
	{
		public Action_bt_node_test_parallel_ut_2_node2()
		{
			method_p0 = 3;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	public static class bt_node_test_parallel_ut_2
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/parallel_ut_2");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Sequence node1 = new Sequence();
				node1.SetClassNameString("Sequence");
				node1.SetId(1);
#if !BEHAVIAC_RELEASE
				node1.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node1);
				{
					Parallel_bt_node_test_parallel_ut_2_node0 node0 = new Parallel_bt_node_test_parallel_ut_2_node0();
					node0.SetClassNameString("Parallel");
					node0.SetId(0);
#if !BEHAVIAC_RELEASE
					node0.SetAgentType("AgentNodeTest");
#endif
					node1.AddChild(node0);
					{
						Action_bt_node_test_parallel_ut_2_node3 node3 = new Action_bt_node_test_parallel_ut_2_node3();
						node3.SetClassNameString("Action");
						node3.SetId(3);
#if !BEHAVIAC_RELEASE
						node3.SetAgentType("AgentNodeTest");
#endif
						node0.AddChild(node3);
						node0.SetHasEvents(node0.HasEvents() | node3.HasEvents());
					}
					{
						Action_bt_node_test_parallel_ut_2_node4 node4 = new Action_bt_node_test_parallel_ut_2_node4();
						node4.SetClassNameString("Action");
						node4.SetId(4);
#if !BEHAVIAC_RELEASE
						node4.SetAgentType("AgentNodeTest");
#endif
						node0.AddChild(node4);
						node0.SetHasEvents(node0.HasEvents() | node4.HasEvents());
					}
					{
						Action_bt_node_test_parallel_ut_2_node5 node5 = new Action_bt_node_test_parallel_ut_2_node5();
						node5.SetClassNameString("Action");
						node5.SetId(5);
#if !BEHAVIAC_RELEASE
						node5.SetAgentType("AgentNodeTest");
#endif
						node0.AddChild(node5);
						node0.SetHasEvents(node0.HasEvents() | node5.HasEvents());
					}
					node1.SetHasEvents(node1.HasEvents() | node0.HasEvents());
				}
				{
					Action_bt_node_test_parallel_ut_2_node2 node2 = new Action_bt_node_test_parallel_ut_2_node2();
					node2.SetClassNameString("Action");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node1.AddChild(node2);
					node1.SetHasEvents(node1.HasEvents() | node2.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node1.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/parallel_ut_3

	class Parallel_bt_node_test_parallel_ut_3_node0 : behaviac.Parallel
	{
		public Parallel_bt_node_test_parallel_ut_3_node0()
		{
			m_failPolicy = behaviac.FAILURE_POLICY.FAIL_ON_ONE;
			m_succeedPolicy = behaviac.SUCCESS_POLICY.SUCCEED_ON_ALL;
			m_exitPolicy = behaviac.EXIT_POLICY.EXIT_ABORT_RUNNINGSIBLINGS;
			m_childFinishPolicy = behaviac.CHILDFINISH_POLICY.CHILDFINISH_ONCE;
		}
	}

	class Action_bt_node_test_parallel_ut_3_node3 : behaviac.Action
	{
		public Action_bt_node_test_parallel_ut_3_node3()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_RUNNING;
		}
		int method_p0;
	}

	class Action_bt_node_test_parallel_ut_3_node4 : behaviac.Action
	{
		public Action_bt_node_test_parallel_ut_3_node4()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Action_bt_node_test_parallel_ut_3_node5 : behaviac.Action
	{
		public Action_bt_node_test_parallel_ut_3_node5()
		{
			method_p0 = 2;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Action_bt_node_test_parallel_ut_3_node2 : behaviac.Action
	{
		public Action_bt_node_test_parallel_ut_3_node2()
		{
			method_p0 = 3;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	public static class bt_node_test_parallel_ut_3
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/parallel_ut_3");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Sequence node1 = new Sequence();
				node1.SetClassNameString("Sequence");
				node1.SetId(1);
#if !BEHAVIAC_RELEASE
				node1.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node1);
				{
					Parallel_bt_node_test_parallel_ut_3_node0 node0 = new Parallel_bt_node_test_parallel_ut_3_node0();
					node0.SetClassNameString("Parallel");
					node0.SetId(0);
#if !BEHAVIAC_RELEASE
					node0.SetAgentType("AgentNodeTest");
#endif
					node1.AddChild(node0);
					{
						Action_bt_node_test_parallel_ut_3_node3 node3 = new Action_bt_node_test_parallel_ut_3_node3();
						node3.SetClassNameString("Action");
						node3.SetId(3);
#if !BEHAVIAC_RELEASE
						node3.SetAgentType("AgentNodeTest");
#endif
						node0.AddChild(node3);
						node0.SetHasEvents(node0.HasEvents() | node3.HasEvents());
					}
					{
						Action_bt_node_test_parallel_ut_3_node4 node4 = new Action_bt_node_test_parallel_ut_3_node4();
						node4.SetClassNameString("Action");
						node4.SetId(4);
#if !BEHAVIAC_RELEASE
						node4.SetAgentType("AgentNodeTest");
#endif
						node0.AddChild(node4);
						node0.SetHasEvents(node0.HasEvents() | node4.HasEvents());
					}
					{
						Action_bt_node_test_parallel_ut_3_node5 node5 = new Action_bt_node_test_parallel_ut_3_node5();
						node5.SetClassNameString("Action");
						node5.SetId(5);
#if !BEHAVIAC_RELEASE
						node5.SetAgentType("AgentNodeTest");
#endif
						node0.AddChild(node5);
						node0.SetHasEvents(node0.HasEvents() | node5.HasEvents());
					}
					node1.SetHasEvents(node1.HasEvents() | node0.HasEvents());
				}
				{
					Action_bt_node_test_parallel_ut_3_node2 node2 = new Action_bt_node_test_parallel_ut_3_node2();
					node2.SetClassNameString("Action");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node1.AddChild(node2);
					node1.SetHasEvents(node1.HasEvents() | node2.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node1.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/parallel_ut_4

	class Parallel_bt_node_test_parallel_ut_4_node0 : behaviac.Parallel
	{
		public Parallel_bt_node_test_parallel_ut_4_node0()
		{
			m_failPolicy = behaviac.FAILURE_POLICY.FAIL_ON_ONE;
			m_succeedPolicy = behaviac.SUCCESS_POLICY.SUCCEED_ON_ALL;
			m_exitPolicy = behaviac.EXIT_POLICY.EXIT_ABORT_RUNNINGSIBLINGS;
			m_childFinishPolicy = behaviac.CHILDFINISH_POLICY.CHILDFINISH_LOOP;
		}
	}

	class Action_bt_node_test_parallel_ut_4_node3 : behaviac.Action
	{
		public Action_bt_node_test_parallel_ut_4_node3()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_RUNNING;
		}
		int method_p0;
	}

	class Action_bt_node_test_parallel_ut_4_node4 : behaviac.Action
	{
		public Action_bt_node_test_parallel_ut_4_node4()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Action_bt_node_test_parallel_ut_4_node5 : behaviac.Action
	{
		public Action_bt_node_test_parallel_ut_4_node5()
		{
			method_p0 = 2;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Action_bt_node_test_parallel_ut_4_node2 : behaviac.Action
	{
		public Action_bt_node_test_parallel_ut_4_node2()
		{
			method_p0 = 3;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	public static class bt_node_test_parallel_ut_4
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/parallel_ut_4");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Sequence node1 = new Sequence();
				node1.SetClassNameString("Sequence");
				node1.SetId(1);
#if !BEHAVIAC_RELEASE
				node1.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node1);
				{
					Parallel_bt_node_test_parallel_ut_4_node0 node0 = new Parallel_bt_node_test_parallel_ut_4_node0();
					node0.SetClassNameString("Parallel");
					node0.SetId(0);
#if !BEHAVIAC_RELEASE
					node0.SetAgentType("AgentNodeTest");
#endif
					node1.AddChild(node0);
					{
						Action_bt_node_test_parallel_ut_4_node3 node3 = new Action_bt_node_test_parallel_ut_4_node3();
						node3.SetClassNameString("Action");
						node3.SetId(3);
#if !BEHAVIAC_RELEASE
						node3.SetAgentType("AgentNodeTest");
#endif
						node0.AddChild(node3);
						node0.SetHasEvents(node0.HasEvents() | node3.HasEvents());
					}
					{
						Action_bt_node_test_parallel_ut_4_node4 node4 = new Action_bt_node_test_parallel_ut_4_node4();
						node4.SetClassNameString("Action");
						node4.SetId(4);
#if !BEHAVIAC_RELEASE
						node4.SetAgentType("AgentNodeTest");
#endif
						node0.AddChild(node4);
						node0.SetHasEvents(node0.HasEvents() | node4.HasEvents());
					}
					{
						Action_bt_node_test_parallel_ut_4_node5 node5 = new Action_bt_node_test_parallel_ut_4_node5();
						node5.SetClassNameString("Action");
						node5.SetId(5);
#if !BEHAVIAC_RELEASE
						node5.SetAgentType("AgentNodeTest");
#endif
						node0.AddChild(node5);
						node0.SetHasEvents(node0.HasEvents() | node5.HasEvents());
					}
					node1.SetHasEvents(node1.HasEvents() | node0.HasEvents());
				}
				{
					Action_bt_node_test_parallel_ut_4_node2 node2 = new Action_bt_node_test_parallel_ut_4_node2();
					node2.SetClassNameString("Action");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node1.AddChild(node2);
					node1.SetHasEvents(node1.HasEvents() | node2.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node1.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/predicate_action_ut_0

	class Action_bt_node_test_predicate_action_ut_0_node1 : behaviac.Action
	{
		public Action_bt_node_test_predicate_action_ut_0_node1()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Predicate_bt_node_test_predicate_action_ut_0_attach3 : behaviac.Predicate
	{
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_FAILURE;
			this.m_bAnd = true;
			int opl = ((AgentNodeTest)pAgent).testVar_0;
			int opr = -1;
			bool op = opl == opr;
			if (op)
				result = EBTStatus.BT_SUCCESS;
			return result;
		}
	}

	class Action_bt_node_test_predicate_action_ut_0_node2 : behaviac.Action
	{
		public Action_bt_node_test_predicate_action_ut_0_node2()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_1(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Predicate_bt_node_test_predicate_action_ut_0_attach4 : behaviac.Predicate
	{
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_FAILURE;
			this.m_bAnd = true;
			int opl = ((AgentNodeTest)pAgent).testVar_0;
			int opr = -1;
			bool op = opl == opr;
			if (op)
				result = EBTStatus.BT_SUCCESS;
			return result;
		}
	}

	public static class bt_node_test_predicate_action_ut_0
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/predicate_action_ut_0");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Sequence node0 = new Sequence();
				node0.SetClassNameString("Sequence");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					Action_bt_node_test_predicate_action_ut_0_node1 node1 = new Action_bt_node_test_predicate_action_ut_0_node1();
					node1.SetClassNameString("Action");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					// attachments
					{
						Predicate_bt_node_test_predicate_action_ut_0_attach3 attach3 = new Predicate_bt_node_test_predicate_action_ut_0_attach3();
						attach3.SetClassNameString("Predicate");
						attach3.SetId(3);
#if !BEHAVIAC_RELEASE
						attach3.SetAgentType("AgentNodeTest");
#endif
						node1.Attach(attach3);
					}
					node0.AddChild(node1);
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					Action_bt_node_test_predicate_action_ut_0_node2 node2 = new Action_bt_node_test_predicate_action_ut_0_node2();
					node2.SetClassNameString("Action");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					// attachments
					{
						Predicate_bt_node_test_predicate_action_ut_0_attach4 attach4 = new Predicate_bt_node_test_predicate_action_ut_0_attach4();
						attach4.SetClassNameString("Predicate");
						attach4.SetId(4);
#if !BEHAVIAC_RELEASE
						attach4.SetAgentType("AgentNodeTest");
#endif
						node2.Attach(attach4);
					}
					node0.AddChild(node2);
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/predicate_action_ut_1

	class Action_bt_node_test_predicate_action_ut_1_node1 : behaviac.Action
	{
		public Action_bt_node_test_predicate_action_ut_1_node1()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Predicate_bt_node_test_predicate_action_ut_1_attach3 : behaviac.Predicate
	{
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_FAILURE;
			this.m_bAnd = true;
			int opl = ((AgentNodeTest)pAgent).testVar_0;
			int opr = -1;
			bool op = opl == opr;
			if (op)
				result = EBTStatus.BT_SUCCESS;
			return result;
		}
	}

	class Predicate_bt_node_test_predicate_action_ut_1_attach5 : behaviac.Predicate
	{
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_FAILURE;
			this.m_bAnd = false;
			int opl = ((AgentNodeTest)pAgent).testVar_1;
			int opr = 0;
			bool op = opl == opr;
			if (op)
				result = EBTStatus.BT_SUCCESS;
			return result;
		}
	}

	class Action_bt_node_test_predicate_action_ut_1_node2 : behaviac.Action
	{
		public Action_bt_node_test_predicate_action_ut_1_node2()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_1(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Predicate_bt_node_test_predicate_action_ut_1_attach4 : behaviac.Predicate
	{
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_FAILURE;
			this.m_bAnd = true;
			int opl = ((AgentNodeTest)pAgent).testVar_0;
			int opr = 0;
			bool op = opl == opr;
			if (op)
				result = EBTStatus.BT_SUCCESS;
			return result;
		}
	}

	class Predicate_bt_node_test_predicate_action_ut_1_attach6 : behaviac.Predicate
	{
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_FAILURE;
			this.m_bAnd = true;
			int opl = ((AgentNodeTest)pAgent).testVar_1;
			int opr = -1;
			bool op = opl == opr;
			if (op)
				result = EBTStatus.BT_SUCCESS;
			return result;
		}
	}

	public static class bt_node_test_predicate_action_ut_1
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/predicate_action_ut_1");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Sequence node0 = new Sequence();
				node0.SetClassNameString("Sequence");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					Action_bt_node_test_predicate_action_ut_1_node1 node1 = new Action_bt_node_test_predicate_action_ut_1_node1();
					node1.SetClassNameString("Action");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					// attachments
					{
						Predicate_bt_node_test_predicate_action_ut_1_attach3 attach3 = new Predicate_bt_node_test_predicate_action_ut_1_attach3();
						attach3.SetClassNameString("Predicate");
						attach3.SetId(3);
#if !BEHAVIAC_RELEASE
						attach3.SetAgentType("AgentNodeTest");
#endif
						node1.Attach(attach3);
					}
					{
						Predicate_bt_node_test_predicate_action_ut_1_attach5 attach5 = new Predicate_bt_node_test_predicate_action_ut_1_attach5();
						attach5.SetClassNameString("Predicate");
						attach5.SetId(5);
#if !BEHAVIAC_RELEASE
						attach5.SetAgentType("AgentNodeTest");
#endif
						node1.Attach(attach5);
					}
					node0.AddChild(node1);
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					Action_bt_node_test_predicate_action_ut_1_node2 node2 = new Action_bt_node_test_predicate_action_ut_1_node2();
					node2.SetClassNameString("Action");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					// attachments
					{
						Predicate_bt_node_test_predicate_action_ut_1_attach4 attach4 = new Predicate_bt_node_test_predicate_action_ut_1_attach4();
						attach4.SetClassNameString("Predicate");
						attach4.SetId(4);
#if !BEHAVIAC_RELEASE
						attach4.SetAgentType("AgentNodeTest");
#endif
						node2.Attach(attach4);
					}
					{
						Predicate_bt_node_test_predicate_action_ut_1_attach6 attach6 = new Predicate_bt_node_test_predicate_action_ut_1_attach6();
						attach6.SetClassNameString("Predicate");
						attach6.SetId(6);
#if !BEHAVIAC_RELEASE
						attach6.SetAgentType("AgentNodeTest");
#endif
						node2.Attach(attach6);
					}
					node0.AddChild(node2);
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/predicate_action_ut_2

	class Action_bt_node_test_predicate_action_ut_2_node1 : behaviac.Action
	{
		public Action_bt_node_test_predicate_action_ut_2_node1()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Predicate_bt_node_test_predicate_action_ut_2_attach3 : behaviac.Predicate
	{
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_FAILURE;
			this.m_bAnd = true;
			int opl = ((AgentNodeTest)pAgent).testVar_0;
			int opr = -1;
			bool op = opl == opr;
			if (op)
				result = EBTStatus.BT_SUCCESS;
			return result;
		}
	}

	class Predicate_bt_node_test_predicate_action_ut_2_attach5 : behaviac.Predicate
	{
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_FAILURE;
			this.m_bAnd = false;
			int opl = ((AgentNodeTest)pAgent).testVar_1;
			int opr = 0;
			bool op = opl == opr;
			if (op)
				result = EBTStatus.BT_SUCCESS;
			return result;
		}
	}

	class Predicate_bt_node_test_predicate_action_ut_2_attach7 : behaviac.Predicate
	{
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_FAILURE;
			this.m_bAnd = true;
			float opl = ((AgentNodeTest)pAgent).testVar_2;
			float opr = -1f;
			bool op = opl == opr;
			if (op)
				result = EBTStatus.BT_SUCCESS;
			return result;
		}
	}

	class Action_bt_node_test_predicate_action_ut_2_node2 : behaviac.Action
	{
		public Action_bt_node_test_predicate_action_ut_2_node2()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_1(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Predicate_bt_node_test_predicate_action_ut_2_attach4 : behaviac.Predicate
	{
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_FAILURE;
			this.m_bAnd = true;
			int opl = ((AgentNodeTest)pAgent).testVar_0;
			int opr = 0;
			bool op = opl == opr;
			if (op)
				result = EBTStatus.BT_SUCCESS;
			return result;
		}
	}

	class Predicate_bt_node_test_predicate_action_ut_2_attach6 : behaviac.Predicate
	{
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_FAILURE;
			this.m_bAnd = true;
			int opl = ((AgentNodeTest)pAgent).testVar_1;
			int opr = -1;
			bool op = opl == opr;
			if (op)
				result = EBTStatus.BT_SUCCESS;
			return result;
		}
	}

	class Predicate_bt_node_test_predicate_action_ut_2_attach8 : behaviac.Predicate
	{
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_FAILURE;
			this.m_bAnd = true;
			float opl = ((AgentNodeTest)pAgent).testVar_2;
			float opr = -1f;
			bool op = opl == opr;
			if (op)
				result = EBTStatus.BT_SUCCESS;
			return result;
		}
	}

	public static class bt_node_test_predicate_action_ut_2
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/predicate_action_ut_2");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Sequence node0 = new Sequence();
				node0.SetClassNameString("Sequence");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					Action_bt_node_test_predicate_action_ut_2_node1 node1 = new Action_bt_node_test_predicate_action_ut_2_node1();
					node1.SetClassNameString("Action");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					// attachments
					{
						Predicate_bt_node_test_predicate_action_ut_2_attach3 attach3 = new Predicate_bt_node_test_predicate_action_ut_2_attach3();
						attach3.SetClassNameString("Predicate");
						attach3.SetId(3);
#if !BEHAVIAC_RELEASE
						attach3.SetAgentType("AgentNodeTest");
#endif
						node1.Attach(attach3);
					}
					{
						Predicate_bt_node_test_predicate_action_ut_2_attach5 attach5 = new Predicate_bt_node_test_predicate_action_ut_2_attach5();
						attach5.SetClassNameString("Predicate");
						attach5.SetId(5);
#if !BEHAVIAC_RELEASE
						attach5.SetAgentType("AgentNodeTest");
#endif
						node1.Attach(attach5);
					}
					{
						Predicate_bt_node_test_predicate_action_ut_2_attach7 attach7 = new Predicate_bt_node_test_predicate_action_ut_2_attach7();
						attach7.SetClassNameString("Predicate");
						attach7.SetId(7);
#if !BEHAVIAC_RELEASE
						attach7.SetAgentType("AgentNodeTest");
#endif
						node1.Attach(attach7);
					}
					node0.AddChild(node1);
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					Action_bt_node_test_predicate_action_ut_2_node2 node2 = new Action_bt_node_test_predicate_action_ut_2_node2();
					node2.SetClassNameString("Action");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					// attachments
					{
						Predicate_bt_node_test_predicate_action_ut_2_attach4 attach4 = new Predicate_bt_node_test_predicate_action_ut_2_attach4();
						attach4.SetClassNameString("Predicate");
						attach4.SetId(4);
#if !BEHAVIAC_RELEASE
						attach4.SetAgentType("AgentNodeTest");
#endif
						node2.Attach(attach4);
					}
					{
						Predicate_bt_node_test_predicate_action_ut_2_attach6 attach6 = new Predicate_bt_node_test_predicate_action_ut_2_attach6();
						attach6.SetClassNameString("Predicate");
						attach6.SetId(6);
#if !BEHAVIAC_RELEASE
						attach6.SetAgentType("AgentNodeTest");
#endif
						node2.Attach(attach6);
					}
					{
						Predicate_bt_node_test_predicate_action_ut_2_attach8 attach8 = new Predicate_bt_node_test_predicate_action_ut_2_attach8();
						attach8.SetClassNameString("Predicate");
						attach8.SetId(8);
#if !BEHAVIAC_RELEASE
						attach8.SetAgentType("AgentNodeTest");
#endif
						node2.Attach(attach8);
					}
					node0.AddChild(node2);
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/predicate_action_ut_3

	class Action_bt_node_test_predicate_action_ut_3_node0 : behaviac.Action
	{
		public Action_bt_node_test_predicate_action_ut_3_node0()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_RUNNING;
		}
		int method_p0;
	}

	class Predicate_bt_node_test_predicate_action_ut_3_attach1 : behaviac.Predicate
	{
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_FAILURE;
			this.m_bAnd = true;
			int opl = ((AgentNodeTest)pAgent).testVar_0;
			int opr = -1;
			bool op = opl == opr;
			if (op)
				result = EBTStatus.BT_SUCCESS;
			return result;
		}
	}

	public static class bt_node_test_predicate_action_ut_3
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/predicate_action_ut_3");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Action_bt_node_test_predicate_action_ut_3_node0 node0 = new Action_bt_node_test_predicate_action_ut_3_node0();
				node0.SetClassNameString("Action");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				// attachments
				{
					Predicate_bt_node_test_predicate_action_ut_3_attach1 attach1 = new Predicate_bt_node_test_predicate_action_ut_3_attach1();
					attach1.SetClassNameString("Predicate");
					attach1.SetId(1);
#if !BEHAVIAC_RELEASE
					attach1.SetAgentType("AgentNodeTest");
#endif
					node0.Attach(attach1);
				}
				bt.AddChild(node0);
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/predicate_selector_ut_0

	class Predicate_bt_node_test_predicate_selector_ut_0_attach1 : behaviac.Predicate
	{
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_FAILURE;
			this.m_bAnd = true;
			int opl = ((AgentNodeTest)pAgent).testVar_0;
			int opr = -1;
			bool op = opl == opr;
			if (op)
				result = EBTStatus.BT_SUCCESS;
			return result;
		}
	}

	class Action_bt_node_test_predicate_selector_ut_0_node2 : behaviac.Action
	{
		public Action_bt_node_test_predicate_selector_ut_0_node2()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_1(method_p0);
			return EBTStatus.BT_FAILURE;
		}
		int method_p0;
	}

	class Action_bt_node_test_predicate_selector_ut_0_node4 : behaviac.Action
	{
		public Action_bt_node_test_predicate_selector_ut_0_node4()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_FAILURE;
		}
		int method_p0;
	}

	class Action_bt_node_test_predicate_selector_ut_0_node5 : behaviac.Action
	{
		public Action_bt_node_test_predicate_selector_ut_0_node5()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	public static class bt_node_test_predicate_selector_ut_0
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/predicate_selector_ut_0");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Selector node0 = new Selector();
				node0.SetClassNameString("Selector");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				// attachments
				{
					Predicate_bt_node_test_predicate_selector_ut_0_attach1 attach1 = new Predicate_bt_node_test_predicate_selector_ut_0_attach1();
					attach1.SetClassNameString("Predicate");
					attach1.SetId(1);
#if !BEHAVIAC_RELEASE
					attach1.SetAgentType("AgentNodeTest");
#endif
					node0.Attach(attach1);
				}
				bt.AddChild(node0);
				{
					Action_bt_node_test_predicate_selector_ut_0_node2 node2 = new Action_bt_node_test_predicate_selector_ut_0_node2();
					node2.SetClassNameString("Action");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				{
					Action_bt_node_test_predicate_selector_ut_0_node4 node4 = new Action_bt_node_test_predicate_selector_ut_0_node4();
					node4.SetClassNameString("Action");
					node4.SetId(4);
#if !BEHAVIAC_RELEASE
					node4.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node4);
					node0.SetHasEvents(node0.HasEvents() | node4.HasEvents());
				}
				{
					Action_bt_node_test_predicate_selector_ut_0_node5 node5 = new Action_bt_node_test_predicate_selector_ut_0_node5();
					node5.SetClassNameString("Action");
					node5.SetId(5);
#if !BEHAVIAC_RELEASE
					node5.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node5);
					node0.SetHasEvents(node0.HasEvents() | node5.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/predicate_selector_ut_1

	class Predicate_bt_node_test_predicate_selector_ut_1_attach1 : behaviac.Predicate
	{
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_FAILURE;
			this.m_bAnd = true;
			int opl = ((AgentNodeTest)pAgent).testVar_0;
			int opr = -1;
			bool op = opl == opr;
			if (op)
				result = EBTStatus.BT_SUCCESS;
			return result;
		}
	}

	class Action_bt_node_test_predicate_selector_ut_1_node4 : behaviac.Action
	{
		public Action_bt_node_test_predicate_selector_ut_1_node4()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_FAILURE;
		}
		int method_p0;
	}

	class Action_bt_node_test_predicate_selector_ut_1_node2 : behaviac.Action
	{
		public Action_bt_node_test_predicate_selector_ut_1_node2()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_FAILURE;
		}
		int method_p0;
	}

	class Action_bt_node_test_predicate_selector_ut_1_node5 : behaviac.Action
	{
		public Action_bt_node_test_predicate_selector_ut_1_node5()
		{
			method_p0 = 2;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	public static class bt_node_test_predicate_selector_ut_1
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/predicate_selector_ut_1");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Selector node0 = new Selector();
				node0.SetClassNameString("Selector");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				// attachments
				{
					Predicate_bt_node_test_predicate_selector_ut_1_attach1 attach1 = new Predicate_bt_node_test_predicate_selector_ut_1_attach1();
					attach1.SetClassNameString("Predicate");
					attach1.SetId(1);
#if !BEHAVIAC_RELEASE
					attach1.SetAgentType("AgentNodeTest");
#endif
					node0.Attach(attach1);
				}
				bt.AddChild(node0);
				{
					Action_bt_node_test_predicate_selector_ut_1_node4 node4 = new Action_bt_node_test_predicate_selector_ut_1_node4();
					node4.SetClassNameString("Action");
					node4.SetId(4);
#if !BEHAVIAC_RELEASE
					node4.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node4);
					node0.SetHasEvents(node0.HasEvents() | node4.HasEvents());
				}
				{
					Action_bt_node_test_predicate_selector_ut_1_node2 node2 = new Action_bt_node_test_predicate_selector_ut_1_node2();
					node2.SetClassNameString("Action");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				{
					Action_bt_node_test_predicate_selector_ut_1_node5 node5 = new Action_bt_node_test_predicate_selector_ut_1_node5();
					node5.SetClassNameString("Action");
					node5.SetId(5);
#if !BEHAVIAC_RELEASE
					node5.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node5);
					node0.SetHasEvents(node0.HasEvents() | node5.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/predicate_selector_ut_2

	class Predicate_bt_node_test_predicate_selector_ut_2_attach1 : behaviac.Predicate
	{
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_FAILURE;
			this.m_bAnd = true;
			int opl = ((AgentNodeTest)pAgent).testVar_0;
			int opr = -1;
			bool op = opl == opr;
			if (op)
				result = EBTStatus.BT_SUCCESS;
			return result;
		}
	}

	class Action_bt_node_test_predicate_selector_ut_2_node4 : behaviac.Action
	{
		public Action_bt_node_test_predicate_selector_ut_2_node4()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_1(method_p0);
			return EBTStatus.BT_FAILURE;
		}
		int method_p0;
	}

	class Action_bt_node_test_predicate_selector_ut_2_node2 : behaviac.Action
	{
		public Action_bt_node_test_predicate_selector_ut_2_node2()
		{
			method_p0 = 0f;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_2(method_p0);
			return EBTStatus.BT_FAILURE;
		}
		float method_p0;
	}

	class Action_bt_node_test_predicate_selector_ut_2_node5 : behaviac.Action
	{
		public Action_bt_node_test_predicate_selector_ut_2_node5()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	public static class bt_node_test_predicate_selector_ut_2
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/predicate_selector_ut_2");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Selector node0 = new Selector();
				node0.SetClassNameString("Selector");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				// attachments
				{
					Predicate_bt_node_test_predicate_selector_ut_2_attach1 attach1 = new Predicate_bt_node_test_predicate_selector_ut_2_attach1();
					attach1.SetClassNameString("Predicate");
					attach1.SetId(1);
#if !BEHAVIAC_RELEASE
					attach1.SetAgentType("AgentNodeTest");
#endif
					node0.Attach(attach1);
				}
				bt.AddChild(node0);
				{
					Action_bt_node_test_predicate_selector_ut_2_node4 node4 = new Action_bt_node_test_predicate_selector_ut_2_node4();
					node4.SetClassNameString("Action");
					node4.SetId(4);
#if !BEHAVIAC_RELEASE
					node4.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node4);
					node0.SetHasEvents(node0.HasEvents() | node4.HasEvents());
				}
				{
					Action_bt_node_test_predicate_selector_ut_2_node2 node2 = new Action_bt_node_test_predicate_selector_ut_2_node2();
					node2.SetClassNameString("Action");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				{
					Action_bt_node_test_predicate_selector_ut_2_node5 node5 = new Action_bt_node_test_predicate_selector_ut_2_node5();
					node5.SetClassNameString("Action");
					node5.SetId(5);
#if !BEHAVIAC_RELEASE
					node5.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node5);
					node0.SetHasEvents(node0.HasEvents() | node5.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/predicate_selector_ut_3

	class Predicate_bt_node_test_predicate_selector_ut_3_attach1 : behaviac.Predicate
	{
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_FAILURE;
			this.m_bAnd = true;
			int opl = ((AgentNodeTest)pAgent).testVar_0;
			int opr = -1;
			bool op = opl == opr;
			if (op)
				result = EBTStatus.BT_SUCCESS;
			return result;
		}
	}

	class Predicate_bt_node_test_predicate_selector_ut_3_attach3 : behaviac.Predicate
	{
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_FAILURE;
			this.m_bAnd = true;
			int opl = ((AgentNodeTest)pAgent).testVar_1;
			int opr = -1;
			bool op = opl == opr;
			if (op)
				result = EBTStatus.BT_SUCCESS;
			return result;
		}
	}

	class Action_bt_node_test_predicate_selector_ut_3_node5 : behaviac.Action
	{
		public Action_bt_node_test_predicate_selector_ut_3_node5()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_FAILURE;
		}
		int method_p0;
	}

	class Action_bt_node_test_predicate_selector_ut_3_node4 : behaviac.Action
	{
		public Action_bt_node_test_predicate_selector_ut_3_node4()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_1(method_p0);
			return EBTStatus.BT_FAILURE;
		}
		int method_p0;
	}

	class Action_bt_node_test_predicate_selector_ut_3_node2 : behaviac.Action
	{
		public Action_bt_node_test_predicate_selector_ut_3_node2()
		{
			method_p0 = 0f;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_2(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		float method_p0;
	}

	public static class bt_node_test_predicate_selector_ut_3
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/predicate_selector_ut_3");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Selector node0 = new Selector();
				node0.SetClassNameString("Selector");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				// attachments
				{
					Predicate_bt_node_test_predicate_selector_ut_3_attach1 attach1 = new Predicate_bt_node_test_predicate_selector_ut_3_attach1();
					attach1.SetClassNameString("Predicate");
					attach1.SetId(1);
#if !BEHAVIAC_RELEASE
					attach1.SetAgentType("AgentNodeTest");
#endif
					node0.Attach(attach1);
				}
				{
					Predicate_bt_node_test_predicate_selector_ut_3_attach3 attach3 = new Predicate_bt_node_test_predicate_selector_ut_3_attach3();
					attach3.SetClassNameString("Predicate");
					attach3.SetId(3);
#if !BEHAVIAC_RELEASE
					attach3.SetAgentType("AgentNodeTest");
#endif
					node0.Attach(attach3);
				}
				bt.AddChild(node0);
				{
					Action_bt_node_test_predicate_selector_ut_3_node5 node5 = new Action_bt_node_test_predicate_selector_ut_3_node5();
					node5.SetClassNameString("Action");
					node5.SetId(5);
#if !BEHAVIAC_RELEASE
					node5.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node5);
					node0.SetHasEvents(node0.HasEvents() | node5.HasEvents());
				}
				{
					Action_bt_node_test_predicate_selector_ut_3_node4 node4 = new Action_bt_node_test_predicate_selector_ut_3_node4();
					node4.SetClassNameString("Action");
					node4.SetId(4);
#if !BEHAVIAC_RELEASE
					node4.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node4);
					node0.SetHasEvents(node0.HasEvents() | node4.HasEvents());
				}
				{
					Action_bt_node_test_predicate_selector_ut_3_node2 node2 = new Action_bt_node_test_predicate_selector_ut_3_node2();
					node2.SetClassNameString("Action");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/predicate_selector_ut_4

	class Predicate_bt_node_test_predicate_selector_ut_4_attach1 : behaviac.Predicate
	{
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_FAILURE;
			this.m_bAnd = true;
			int opl = ((AgentNodeTest)pAgent).testVar_0;
			int opr = -1;
			bool op = opl == opr;
			if (op)
				result = EBTStatus.BT_SUCCESS;
			return result;
		}
	}

	class Predicate_bt_node_test_predicate_selector_ut_4_attach3 : behaviac.Predicate
	{
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_FAILURE;
			this.m_bAnd = false;
			int opl = ((AgentNodeTest)pAgent).testVar_1;
			int opr = -1;
			bool op = opl == opr;
			if (op)
				result = EBTStatus.BT_SUCCESS;
			return result;
		}
	}

	class Action_bt_node_test_predicate_selector_ut_4_node5 : behaviac.Action
	{
		public Action_bt_node_test_predicate_selector_ut_4_node5()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_FAILURE;
		}
		int method_p0;
	}

	class Action_bt_node_test_predicate_selector_ut_4_node4 : behaviac.Action
	{
		public Action_bt_node_test_predicate_selector_ut_4_node4()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_1(method_p0);
			return EBTStatus.BT_FAILURE;
		}
		int method_p0;
	}

	class Action_bt_node_test_predicate_selector_ut_4_node2 : behaviac.Action
	{
		public Action_bt_node_test_predicate_selector_ut_4_node2()
		{
			method_p0 = 0f;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_2(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		float method_p0;
	}

	public static class bt_node_test_predicate_selector_ut_4
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/predicate_selector_ut_4");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Selector node0 = new Selector();
				node0.SetClassNameString("Selector");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				// attachments
				{
					Predicate_bt_node_test_predicate_selector_ut_4_attach1 attach1 = new Predicate_bt_node_test_predicate_selector_ut_4_attach1();
					attach1.SetClassNameString("Predicate");
					attach1.SetId(1);
#if !BEHAVIAC_RELEASE
					attach1.SetAgentType("AgentNodeTest");
#endif
					node0.Attach(attach1);
				}
				{
					Predicate_bt_node_test_predicate_selector_ut_4_attach3 attach3 = new Predicate_bt_node_test_predicate_selector_ut_4_attach3();
					attach3.SetClassNameString("Predicate");
					attach3.SetId(3);
#if !BEHAVIAC_RELEASE
					attach3.SetAgentType("AgentNodeTest");
#endif
					node0.Attach(attach3);
				}
				bt.AddChild(node0);
				{
					Action_bt_node_test_predicate_selector_ut_4_node5 node5 = new Action_bt_node_test_predicate_selector_ut_4_node5();
					node5.SetClassNameString("Action");
					node5.SetId(5);
#if !BEHAVIAC_RELEASE
					node5.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node5);
					node0.SetHasEvents(node0.HasEvents() | node5.HasEvents());
				}
				{
					Action_bt_node_test_predicate_selector_ut_4_node4 node4 = new Action_bt_node_test_predicate_selector_ut_4_node4();
					node4.SetClassNameString("Action");
					node4.SetId(4);
#if !BEHAVIAC_RELEASE
					node4.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node4);
					node0.SetHasEvents(node0.HasEvents() | node4.HasEvents());
				}
				{
					Action_bt_node_test_predicate_selector_ut_4_node2 node2 = new Action_bt_node_test_predicate_selector_ut_4_node2();
					node2.SetClassNameString("Action");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/predicate_selector_ut_5

	class Predicate_bt_node_test_predicate_selector_ut_5_attach1 : behaviac.Predicate
	{
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_FAILURE;
			this.m_bAnd = true;
			int opl = ((AgentNodeTest)pAgent).testVar_0;
			int opr = -1;
			bool op = opl == opr;
			if (op)
				result = EBTStatus.BT_SUCCESS;
			return result;
		}
	}

	class Predicate_bt_node_test_predicate_selector_ut_5_attach3 : behaviac.Predicate
	{
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_FAILURE;
			this.m_bAnd = true;
			int opl = ((AgentNodeTest)pAgent).testVar_1;
			int opr = -1;
			bool op = opl == opr;
			if (op)
				result = EBTStatus.BT_SUCCESS;
			return result;
		}
	}

	class Predicate_bt_node_test_predicate_selector_ut_5_attach6 : behaviac.Predicate
	{
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_FAILURE;
			this.m_bAnd = false;
			float opl = ((AgentNodeTest)pAgent).testVar_2;
			float opr = -1f;
			bool op = opl == opr;
			if (op)
				result = EBTStatus.BT_SUCCESS;
			return result;
		}
	}

	class Action_bt_node_test_predicate_selector_ut_5_node5 : behaviac.Action
	{
		public Action_bt_node_test_predicate_selector_ut_5_node5()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_FAILURE;
		}
		int method_p0;
	}

	class Action_bt_node_test_predicate_selector_ut_5_node4 : behaviac.Action
	{
		public Action_bt_node_test_predicate_selector_ut_5_node4()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_1(method_p0);
			return EBTStatus.BT_FAILURE;
		}
		int method_p0;
	}

	class Action_bt_node_test_predicate_selector_ut_5_node2 : behaviac.Action
	{
		public Action_bt_node_test_predicate_selector_ut_5_node2()
		{
			method_p0 = 0f;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_2(method_p0);
			return EBTStatus.BT_FAILURE;
		}
		float method_p0;
	}

	class Action_bt_node_test_predicate_selector_ut_5_node7 : behaviac.Action
	{
		public Action_bt_node_test_predicate_selector_ut_5_node7()
		{
			method_p0 = 1f;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_2(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		float method_p0;
	}

	public static class bt_node_test_predicate_selector_ut_5
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/predicate_selector_ut_5");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Selector node0 = new Selector();
				node0.SetClassNameString("Selector");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				// attachments
				{
					Predicate_bt_node_test_predicate_selector_ut_5_attach1 attach1 = new Predicate_bt_node_test_predicate_selector_ut_5_attach1();
					attach1.SetClassNameString("Predicate");
					attach1.SetId(1);
#if !BEHAVIAC_RELEASE
					attach1.SetAgentType("AgentNodeTest");
#endif
					node0.Attach(attach1);
				}
				{
					Predicate_bt_node_test_predicate_selector_ut_5_attach3 attach3 = new Predicate_bt_node_test_predicate_selector_ut_5_attach3();
					attach3.SetClassNameString("Predicate");
					attach3.SetId(3);
#if !BEHAVIAC_RELEASE
					attach3.SetAgentType("AgentNodeTest");
#endif
					node0.Attach(attach3);
				}
				{
					Predicate_bt_node_test_predicate_selector_ut_5_attach6 attach6 = new Predicate_bt_node_test_predicate_selector_ut_5_attach6();
					attach6.SetClassNameString("Predicate");
					attach6.SetId(6);
#if !BEHAVIAC_RELEASE
					attach6.SetAgentType("AgentNodeTest");
#endif
					node0.Attach(attach6);
				}
				bt.AddChild(node0);
				{
					Action_bt_node_test_predicate_selector_ut_5_node5 node5 = new Action_bt_node_test_predicate_selector_ut_5_node5();
					node5.SetClassNameString("Action");
					node5.SetId(5);
#if !BEHAVIAC_RELEASE
					node5.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node5);
					node0.SetHasEvents(node0.HasEvents() | node5.HasEvents());
				}
				{
					Action_bt_node_test_predicate_selector_ut_5_node4 node4 = new Action_bt_node_test_predicate_selector_ut_5_node4();
					node4.SetClassNameString("Action");
					node4.SetId(4);
#if !BEHAVIAC_RELEASE
					node4.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node4);
					node0.SetHasEvents(node0.HasEvents() | node4.HasEvents());
				}
				{
					Action_bt_node_test_predicate_selector_ut_5_node2 node2 = new Action_bt_node_test_predicate_selector_ut_5_node2();
					node2.SetClassNameString("Action");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				{
					Action_bt_node_test_predicate_selector_ut_5_node7 node7 = new Action_bt_node_test_predicate_selector_ut_5_node7();
					node7.SetClassNameString("Action");
					node7.SetId(7);
#if !BEHAVIAC_RELEASE
					node7.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node7);
					node0.SetHasEvents(node0.HasEvents() | node7.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/predicate_sequence_ut_0

	class Predicate_bt_node_test_predicate_sequence_ut_0_attach1 : behaviac.Predicate
	{
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_FAILURE;
			this.m_bAnd = true;
			int opl = ((AgentNodeTest)pAgent).testVar_0;
			int opr = -1;
			bool op = opl == opr;
			if (op)
				result = EBTStatus.BT_SUCCESS;
			return result;
		}
	}

	class Action_bt_node_test_predicate_sequence_ut_0_node2 : behaviac.Action
	{
		public Action_bt_node_test_predicate_sequence_ut_0_node2()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_1(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Action_bt_node_test_predicate_sequence_ut_0_node4 : behaviac.Action
	{
		public Action_bt_node_test_predicate_sequence_ut_0_node4()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Action_bt_node_test_predicate_sequence_ut_0_node5 : behaviac.Action
	{
		public Action_bt_node_test_predicate_sequence_ut_0_node5()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	public static class bt_node_test_predicate_sequence_ut_0
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/predicate_sequence_ut_0");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Sequence node0 = new Sequence();
				node0.SetClassNameString("Sequence");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				// attachments
				{
					Predicate_bt_node_test_predicate_sequence_ut_0_attach1 attach1 = new Predicate_bt_node_test_predicate_sequence_ut_0_attach1();
					attach1.SetClassNameString("Predicate");
					attach1.SetId(1);
#if !BEHAVIAC_RELEASE
					attach1.SetAgentType("AgentNodeTest");
#endif
					node0.Attach(attach1);
				}
				bt.AddChild(node0);
				{
					Action_bt_node_test_predicate_sequence_ut_0_node2 node2 = new Action_bt_node_test_predicate_sequence_ut_0_node2();
					node2.SetClassNameString("Action");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				{
					Action_bt_node_test_predicate_sequence_ut_0_node4 node4 = new Action_bt_node_test_predicate_sequence_ut_0_node4();
					node4.SetClassNameString("Action");
					node4.SetId(4);
#if !BEHAVIAC_RELEASE
					node4.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node4);
					node0.SetHasEvents(node0.HasEvents() | node4.HasEvents());
				}
				{
					Action_bt_node_test_predicate_sequence_ut_0_node5 node5 = new Action_bt_node_test_predicate_sequence_ut_0_node5();
					node5.SetClassNameString("Action");
					node5.SetId(5);
#if !BEHAVIAC_RELEASE
					node5.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node5);
					node0.SetHasEvents(node0.HasEvents() | node5.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/predicate_sequence_ut_1

	class Predicate_bt_node_test_predicate_sequence_ut_1_attach1 : behaviac.Predicate
	{
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_FAILURE;
			this.m_bAnd = true;
			int opl = ((AgentNodeTest)pAgent).testVar_0;
			int opr = -1;
			bool op = opl == opr;
			if (op)
				result = EBTStatus.BT_SUCCESS;
			return result;
		}
	}

	class Action_bt_node_test_predicate_sequence_ut_1_node4 : behaviac.Action
	{
		public Action_bt_node_test_predicate_sequence_ut_1_node4()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Action_bt_node_test_predicate_sequence_ut_1_node2 : behaviac.Action
	{
		public Action_bt_node_test_predicate_sequence_ut_1_node2()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Action_bt_node_test_predicate_sequence_ut_1_node5 : behaviac.Action
	{
		public Action_bt_node_test_predicate_sequence_ut_1_node5()
		{
			method_p0 = 2;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	public static class bt_node_test_predicate_sequence_ut_1
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/predicate_sequence_ut_1");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Sequence node0 = new Sequence();
				node0.SetClassNameString("Sequence");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				// attachments
				{
					Predicate_bt_node_test_predicate_sequence_ut_1_attach1 attach1 = new Predicate_bt_node_test_predicate_sequence_ut_1_attach1();
					attach1.SetClassNameString("Predicate");
					attach1.SetId(1);
#if !BEHAVIAC_RELEASE
					attach1.SetAgentType("AgentNodeTest");
#endif
					node0.Attach(attach1);
				}
				bt.AddChild(node0);
				{
					Action_bt_node_test_predicate_sequence_ut_1_node4 node4 = new Action_bt_node_test_predicate_sequence_ut_1_node4();
					node4.SetClassNameString("Action");
					node4.SetId(4);
#if !BEHAVIAC_RELEASE
					node4.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node4);
					node0.SetHasEvents(node0.HasEvents() | node4.HasEvents());
				}
				{
					Action_bt_node_test_predicate_sequence_ut_1_node2 node2 = new Action_bt_node_test_predicate_sequence_ut_1_node2();
					node2.SetClassNameString("Action");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				{
					Action_bt_node_test_predicate_sequence_ut_1_node5 node5 = new Action_bt_node_test_predicate_sequence_ut_1_node5();
					node5.SetClassNameString("Action");
					node5.SetId(5);
#if !BEHAVIAC_RELEASE
					node5.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node5);
					node0.SetHasEvents(node0.HasEvents() | node5.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/predicate_sequence_ut_2

	class Predicate_bt_node_test_predicate_sequence_ut_2_attach1 : behaviac.Predicate
	{
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_FAILURE;
			this.m_bAnd = true;
			int opl = ((AgentNodeTest)pAgent).testVar_0;
			int opr = -1;
			bool op = opl == opr;
			if (op)
				result = EBTStatus.BT_SUCCESS;
			return result;
		}
	}

	class Action_bt_node_test_predicate_sequence_ut_2_node4 : behaviac.Action
	{
		public Action_bt_node_test_predicate_sequence_ut_2_node4()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_1(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Action_bt_node_test_predicate_sequence_ut_2_node2 : behaviac.Action
	{
		public Action_bt_node_test_predicate_sequence_ut_2_node2()
		{
			method_p0 = 0f;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_2(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		float method_p0;
	}

	class Action_bt_node_test_predicate_sequence_ut_2_node5 : behaviac.Action
	{
		public Action_bt_node_test_predicate_sequence_ut_2_node5()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	public static class bt_node_test_predicate_sequence_ut_2
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/predicate_sequence_ut_2");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Sequence node0 = new Sequence();
				node0.SetClassNameString("Sequence");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				// attachments
				{
					Predicate_bt_node_test_predicate_sequence_ut_2_attach1 attach1 = new Predicate_bt_node_test_predicate_sequence_ut_2_attach1();
					attach1.SetClassNameString("Predicate");
					attach1.SetId(1);
#if !BEHAVIAC_RELEASE
					attach1.SetAgentType("AgentNodeTest");
#endif
					node0.Attach(attach1);
				}
				bt.AddChild(node0);
				{
					Action_bt_node_test_predicate_sequence_ut_2_node4 node4 = new Action_bt_node_test_predicate_sequence_ut_2_node4();
					node4.SetClassNameString("Action");
					node4.SetId(4);
#if !BEHAVIAC_RELEASE
					node4.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node4);
					node0.SetHasEvents(node0.HasEvents() | node4.HasEvents());
				}
				{
					Action_bt_node_test_predicate_sequence_ut_2_node2 node2 = new Action_bt_node_test_predicate_sequence_ut_2_node2();
					node2.SetClassNameString("Action");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				{
					Action_bt_node_test_predicate_sequence_ut_2_node5 node5 = new Action_bt_node_test_predicate_sequence_ut_2_node5();
					node5.SetClassNameString("Action");
					node5.SetId(5);
#if !BEHAVIAC_RELEASE
					node5.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node5);
					node0.SetHasEvents(node0.HasEvents() | node5.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/predicate_sequence_ut_3

	class Predicate_bt_node_test_predicate_sequence_ut_3_attach1 : behaviac.Predicate
	{
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_FAILURE;
			this.m_bAnd = true;
			int opl = ((AgentNodeTest)pAgent).testVar_0;
			int opr = -1;
			bool op = opl == opr;
			if (op)
				result = EBTStatus.BT_SUCCESS;
			return result;
		}
	}

	class Predicate_bt_node_test_predicate_sequence_ut_3_attach3 : behaviac.Predicate
	{
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_FAILURE;
			this.m_bAnd = true;
			int opl = ((AgentNodeTest)pAgent).testVar_1;
			int opr = -1;
			bool op = opl == opr;
			if (op)
				result = EBTStatus.BT_SUCCESS;
			return result;
		}
	}

	class Action_bt_node_test_predicate_sequence_ut_3_node5 : behaviac.Action
	{
		public Action_bt_node_test_predicate_sequence_ut_3_node5()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Action_bt_node_test_predicate_sequence_ut_3_node4 : behaviac.Action
	{
		public Action_bt_node_test_predicate_sequence_ut_3_node4()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_1(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Action_bt_node_test_predicate_sequence_ut_3_node2 : behaviac.Action
	{
		public Action_bt_node_test_predicate_sequence_ut_3_node2()
		{
			method_p0 = 0f;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_2(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		float method_p0;
	}

	public static class bt_node_test_predicate_sequence_ut_3
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/predicate_sequence_ut_3");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Sequence node0 = new Sequence();
				node0.SetClassNameString("Sequence");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				// attachments
				{
					Predicate_bt_node_test_predicate_sequence_ut_3_attach1 attach1 = new Predicate_bt_node_test_predicate_sequence_ut_3_attach1();
					attach1.SetClassNameString("Predicate");
					attach1.SetId(1);
#if !BEHAVIAC_RELEASE
					attach1.SetAgentType("AgentNodeTest");
#endif
					node0.Attach(attach1);
				}
				{
					Predicate_bt_node_test_predicate_sequence_ut_3_attach3 attach3 = new Predicate_bt_node_test_predicate_sequence_ut_3_attach3();
					attach3.SetClassNameString("Predicate");
					attach3.SetId(3);
#if !BEHAVIAC_RELEASE
					attach3.SetAgentType("AgentNodeTest");
#endif
					node0.Attach(attach3);
				}
				bt.AddChild(node0);
				{
					Action_bt_node_test_predicate_sequence_ut_3_node5 node5 = new Action_bt_node_test_predicate_sequence_ut_3_node5();
					node5.SetClassNameString("Action");
					node5.SetId(5);
#if !BEHAVIAC_RELEASE
					node5.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node5);
					node0.SetHasEvents(node0.HasEvents() | node5.HasEvents());
				}
				{
					Action_bt_node_test_predicate_sequence_ut_3_node4 node4 = new Action_bt_node_test_predicate_sequence_ut_3_node4();
					node4.SetClassNameString("Action");
					node4.SetId(4);
#if !BEHAVIAC_RELEASE
					node4.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node4);
					node0.SetHasEvents(node0.HasEvents() | node4.HasEvents());
				}
				{
					Action_bt_node_test_predicate_sequence_ut_3_node2 node2 = new Action_bt_node_test_predicate_sequence_ut_3_node2();
					node2.SetClassNameString("Action");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/predicate_sequence_ut_4

	class Predicate_bt_node_test_predicate_sequence_ut_4_attach1 : behaviac.Predicate
	{
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_FAILURE;
			this.m_bAnd = true;
			int opl = ((AgentNodeTest)pAgent).testVar_0;
			int opr = -1;
			bool op = opl == opr;
			if (op)
				result = EBTStatus.BT_SUCCESS;
			return result;
		}
	}

	class Predicate_bt_node_test_predicate_sequence_ut_4_attach3 : behaviac.Predicate
	{
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_FAILURE;
			this.m_bAnd = false;
			int opl = ((AgentNodeTest)pAgent).testVar_1;
			int opr = -1;
			bool op = opl == opr;
			if (op)
				result = EBTStatus.BT_SUCCESS;
			return result;
		}
	}

	class Action_bt_node_test_predicate_sequence_ut_4_node5 : behaviac.Action
	{
		public Action_bt_node_test_predicate_sequence_ut_4_node5()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Action_bt_node_test_predicate_sequence_ut_4_node4 : behaviac.Action
	{
		public Action_bt_node_test_predicate_sequence_ut_4_node4()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_1(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Action_bt_node_test_predicate_sequence_ut_4_node2 : behaviac.Action
	{
		public Action_bt_node_test_predicate_sequence_ut_4_node2()
		{
			method_p0 = 0f;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_2(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		float method_p0;
	}

	public static class bt_node_test_predicate_sequence_ut_4
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/predicate_sequence_ut_4");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Sequence node0 = new Sequence();
				node0.SetClassNameString("Sequence");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				// attachments
				{
					Predicate_bt_node_test_predicate_sequence_ut_4_attach1 attach1 = new Predicate_bt_node_test_predicate_sequence_ut_4_attach1();
					attach1.SetClassNameString("Predicate");
					attach1.SetId(1);
#if !BEHAVIAC_RELEASE
					attach1.SetAgentType("AgentNodeTest");
#endif
					node0.Attach(attach1);
				}
				{
					Predicate_bt_node_test_predicate_sequence_ut_4_attach3 attach3 = new Predicate_bt_node_test_predicate_sequence_ut_4_attach3();
					attach3.SetClassNameString("Predicate");
					attach3.SetId(3);
#if !BEHAVIAC_RELEASE
					attach3.SetAgentType("AgentNodeTest");
#endif
					node0.Attach(attach3);
				}
				bt.AddChild(node0);
				{
					Action_bt_node_test_predicate_sequence_ut_4_node5 node5 = new Action_bt_node_test_predicate_sequence_ut_4_node5();
					node5.SetClassNameString("Action");
					node5.SetId(5);
#if !BEHAVIAC_RELEASE
					node5.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node5);
					node0.SetHasEvents(node0.HasEvents() | node5.HasEvents());
				}
				{
					Action_bt_node_test_predicate_sequence_ut_4_node4 node4 = new Action_bt_node_test_predicate_sequence_ut_4_node4();
					node4.SetClassNameString("Action");
					node4.SetId(4);
#if !BEHAVIAC_RELEASE
					node4.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node4);
					node0.SetHasEvents(node0.HasEvents() | node4.HasEvents());
				}
				{
					Action_bt_node_test_predicate_sequence_ut_4_node2 node2 = new Action_bt_node_test_predicate_sequence_ut_4_node2();
					node2.SetClassNameString("Action");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/predicate_sequence_ut_5

	class Predicate_bt_node_test_predicate_sequence_ut_5_attach1 : behaviac.Predicate
	{
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_FAILURE;
			this.m_bAnd = true;
			int opl = ((AgentNodeTest)pAgent).testVar_0;
			int opr = 0;
			bool op = opl == opr;
			if (op)
				result = EBTStatus.BT_SUCCESS;
			return result;
		}
	}

	class Predicate_bt_node_test_predicate_sequence_ut_5_attach3 : behaviac.Predicate
	{
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_FAILURE;
			this.m_bAnd = false;
			int opl = ((AgentNodeTest)pAgent).testVar_1;
			int opr = -1;
			bool op = opl == opr;
			if (op)
				result = EBTStatus.BT_SUCCESS;
			return result;
		}
	}

	class Predicate_bt_node_test_predicate_sequence_ut_5_attach6 : behaviac.Predicate
	{
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_FAILURE;
			this.m_bAnd = true;
			float opl = ((AgentNodeTest)pAgent).testVar_2;
			float opr = -1f;
			bool op = opl == opr;
			if (op)
				result = EBTStatus.BT_SUCCESS;
			return result;
		}
	}

	class Action_bt_node_test_predicate_sequence_ut_5_node5 : behaviac.Action
	{
		public Action_bt_node_test_predicate_sequence_ut_5_node5()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Action_bt_node_test_predicate_sequence_ut_5_node4 : behaviac.Action
	{
		public Action_bt_node_test_predicate_sequence_ut_5_node4()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_1(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Action_bt_node_test_predicate_sequence_ut_5_node2 : behaviac.Action
	{
		public Action_bt_node_test_predicate_sequence_ut_5_node2()
		{
			method_p0 = 0f;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_2(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		float method_p0;
	}

	class Action_bt_node_test_predicate_sequence_ut_5_node7 : behaviac.Action
	{
		public Action_bt_node_test_predicate_sequence_ut_5_node7()
		{
			method_p0 = 1f;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_2(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		float method_p0;
	}

	public static class bt_node_test_predicate_sequence_ut_5
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/predicate_sequence_ut_5");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Sequence node0 = new Sequence();
				node0.SetClassNameString("Sequence");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				// attachments
				{
					Predicate_bt_node_test_predicate_sequence_ut_5_attach1 attach1 = new Predicate_bt_node_test_predicate_sequence_ut_5_attach1();
					attach1.SetClassNameString("Predicate");
					attach1.SetId(1);
#if !BEHAVIAC_RELEASE
					attach1.SetAgentType("AgentNodeTest");
#endif
					node0.Attach(attach1);
				}
				{
					Predicate_bt_node_test_predicate_sequence_ut_5_attach3 attach3 = new Predicate_bt_node_test_predicate_sequence_ut_5_attach3();
					attach3.SetClassNameString("Predicate");
					attach3.SetId(3);
#if !BEHAVIAC_RELEASE
					attach3.SetAgentType("AgentNodeTest");
#endif
					node0.Attach(attach3);
				}
				{
					Predicate_bt_node_test_predicate_sequence_ut_5_attach6 attach6 = new Predicate_bt_node_test_predicate_sequence_ut_5_attach6();
					attach6.SetClassNameString("Predicate");
					attach6.SetId(6);
#if !BEHAVIAC_RELEASE
					attach6.SetAgentType("AgentNodeTest");
#endif
					node0.Attach(attach6);
				}
				bt.AddChild(node0);
				{
					Action_bt_node_test_predicate_sequence_ut_5_node5 node5 = new Action_bt_node_test_predicate_sequence_ut_5_node5();
					node5.SetClassNameString("Action");
					node5.SetId(5);
#if !BEHAVIAC_RELEASE
					node5.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node5);
					node0.SetHasEvents(node0.HasEvents() | node5.HasEvents());
				}
				{
					Action_bt_node_test_predicate_sequence_ut_5_node4 node4 = new Action_bt_node_test_predicate_sequence_ut_5_node4();
					node4.SetClassNameString("Action");
					node4.SetId(4);
#if !BEHAVIAC_RELEASE
					node4.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node4);
					node0.SetHasEvents(node0.HasEvents() | node4.HasEvents());
				}
				{
					Action_bt_node_test_predicate_sequence_ut_5_node2 node2 = new Action_bt_node_test_predicate_sequence_ut_5_node2();
					node2.SetClassNameString("Action");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				{
					Action_bt_node_test_predicate_sequence_ut_5_node7 node7 = new Action_bt_node_test_predicate_sequence_ut_5_node7();
					node7.SetClassNameString("Action");
					node7.SetId(7);
#if !BEHAVIAC_RELEASE
					node7.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node7);
					node0.SetHasEvents(node0.HasEvents() | node7.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/query_subtree_0

	class Action_bt_node_test_query_subtree_0_node3 : behaviac.Action
	{
		public Action_bt_node_test_query_subtree_0_node3()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	public static class bt_node_test_query_subtree_0
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/query_subtree_0");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			bt.SetDomains("test subtree0");
			bt.SetDescriptors("1:{Descriptor=int Self.AgentNodeTest::testVar_1;Reference=const int 20;}");
			// children
			{
				Sequence node0 = new Sequence();
				node0.SetClassNameString("Sequence");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					Action_bt_node_test_query_subtree_0_node3 node3 = new Action_bt_node_test_query_subtree_0_node3();
					node3.SetClassNameString("Action");
					node3.SetId(3);
#if !BEHAVIAC_RELEASE
					node3.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node3);
					node0.SetHasEvents(node0.HasEvents() | node3.HasEvents());
				}
				{
					True node2 = new True();
					node2.SetClassNameString("True");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/query_subtree_1

	class Action_bt_node_test_query_subtree_1_node1 : behaviac.Action
	{
		public Action_bt_node_test_query_subtree_1_node1()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	public static class bt_node_test_query_subtree_1
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/query_subtree_1");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			bt.SetDomains("test subtree1");
			bt.SetDescriptors("1:{Descriptor=int Self.AgentNodeTest::testVar_1;Reference=const int 50;}");
			// children
			{
				Sequence node0 = new Sequence();
				node0.SetClassNameString("Sequence");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					Action_bt_node_test_query_subtree_1_node1 node1 = new Action_bt_node_test_query_subtree_1_node1();
					node1.SetClassNameString("Action");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					True node2 = new True();
					node2.SetClassNameString("True");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/query_subtree_2

	class Action_bt_node_test_query_subtree_2_node1 : behaviac.Action
	{
		public Action_bt_node_test_query_subtree_2_node1()
		{
			method_p0 = 2;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	public static class bt_node_test_query_subtree_2
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/query_subtree_2");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			bt.SetDomains("test subtree2");
			bt.SetDescriptors("1:{Descriptor=int Self.AgentNodeTest::testVar_1;Reference=const int 80;}");
			// children
			{
				Sequence node0 = new Sequence();
				node0.SetClassNameString("Sequence");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					Action_bt_node_test_query_subtree_2_node1 node1 = new Action_bt_node_test_query_subtree_2_node1();
					node1.SetClassNameString("Action");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					True node2 = new True();
					node2.SetClassNameString("True");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/query_ut_0

	class Sequence_bt_node_test_query_ut_0_node0 : behaviac.Sequence
	{
		public Sequence_bt_node_test_query_ut_0_node0()
		{
			EnterAction_p0 = 0f;
			ExitAction_p0 = 0;
			ExitAction_p1 = "";
		}
		public override bool enteraction_impl(Agent pAgent)
		{
			((AgentNodeTest)pAgent).enter_action_1(EnterAction_p0);
			return true;
		}
		public override bool exitaction_impl(Agent pAgent)
		{
			((AgentNodeTest)pAgent).exit_action_2(ExitAction_p0, ExitAction_p1);
			return true;
		}
		float EnterAction_p0;
		int ExitAction_p0;
		string ExitAction_p1;
	}

	class Query_bt_node_test_query_ut_0_node1 : behaviac.Query
	{
		public Query_bt_node_test_query_ut_0_node1()
		{
			this.Initialize("test", "1:{Attribute=int Self.AgentNodeTest::testVar_1;Reference=const int 0;Weight=100;}");
		}
		public void Initialize(string domain, string descriptors)
		{
			this.m_domain = domain;
			this.SetDescriptors(descriptors);
		}
	}

	class Query_bt_node_test_query_ut_0_node3 : behaviac.Query
	{
		public Query_bt_node_test_query_ut_0_node3()
		{
			this.Initialize("test", "1:{Attribute=int Self.AgentNodeTest::testVar_1;Reference=const int 50;Weight=100;}");
		}
		public void Initialize(string domain, string descriptors)
		{
			this.m_domain = domain;
			this.SetDescriptors(descriptors);
		}
	}

	class Query_bt_node_test_query_ut_0_node4 : behaviac.Query
	{
		public Query_bt_node_test_query_ut_0_node4()
		{
			this.Initialize("test", "1:{Attribute=int Self.AgentNodeTest::testVar_1;Reference=const int 100;Weight=100;}");
		}
		public void Initialize(string domain, string descriptors)
		{
			this.m_domain = domain;
			this.SetDescriptors(descriptors);
		}
	}

	public static class bt_node_test_query_ut_0
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/query_ut_0");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Sequence_bt_node_test_query_ut_0_node0 node0 = new Sequence_bt_node_test_query_ut_0_node0();
				node0.SetClassNameString("Sequence");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					Query_bt_node_test_query_ut_0_node1 node1 = new Query_bt_node_test_query_ut_0_node1();
					node1.SetClassNameString("Query");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					Selector node2 = new Selector();
					node2.SetClassNameString("Selector");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					{
						Query_bt_node_test_query_ut_0_node3 node3 = new Query_bt_node_test_query_ut_0_node3();
						node3.SetClassNameString("Query");
						node3.SetId(3);
#if !BEHAVIAC_RELEASE
						node3.SetAgentType("AgentNodeTest");
#endif
						node2.AddChild(node3);
						node2.SetHasEvents(node2.HasEvents() | node3.HasEvents());
					}
					{
						Query_bt_node_test_query_ut_0_node4 node4 = new Query_bt_node_test_query_ut_0_node4();
						node4.SetClassNameString("Query");
						node4.SetId(4);
#if !BEHAVIAC_RELEASE
						node4.SetAgentType("AgentNodeTest");
#endif
						node2.AddChild(node4);
						node2.SetHasEvents(node2.HasEvents() | node4.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/query_ut_1

	class Sequence_bt_node_test_query_ut_1_node0 : behaviac.Sequence
	{
		public Sequence_bt_node_test_query_ut_1_node0()
		{
			EnterAction_p0 = 0f;
			ExitAction_p0 = 0;
			ExitAction_p1 = "";
		}
		public override bool enteraction_impl(Agent pAgent)
		{
			((AgentNodeTest)pAgent).enter_action_1(EnterAction_p0);
			return true;
		}
		public override bool exitaction_impl(Agent pAgent)
		{
			((AgentNodeTest)pAgent).exit_action_2(ExitAction_p0, ExitAction_p1);
			return true;
		}
		float EnterAction_p0;
		int ExitAction_p0;
		string ExitAction_p1;
	}

	class Query_bt_node_test_query_ut_1_node1 : behaviac.Query
	{
		public Query_bt_node_test_query_ut_1_node1()
		{
			this.Initialize("test", "1:{Attribute=int Self.AgentNodeTest::testVar_1;Reference=const int 0;Weight=100;}");
		}
		public void Initialize(string domain, string descriptors)
		{
			this.m_domain = domain;
			this.SetDescriptors(descriptors);
		}
	}

	class Query_bt_node_test_query_ut_1_node3 : behaviac.Query
	{
		public Query_bt_node_test_query_ut_1_node3()
		{
			this.Initialize("test", "1:{Attribute=int Self.AgentNodeTest::testVar_1;Reference=const int 50;Weight=100;}");
		}
		public void Initialize(string domain, string descriptors)
		{
			this.m_domain = domain;
			this.SetDescriptors(descriptors);
		}
	}

	class Query_bt_node_test_query_ut_1_node4 : behaviac.Query
	{
		public Query_bt_node_test_query_ut_1_node4()
		{
			this.Initialize("test", "1:{Attribute=int Self.AgentNodeTest::testVar_1;Reference=const int 100;Weight=100;}");
		}
		public void Initialize(string domain, string descriptors)
		{
			this.m_domain = domain;
			this.SetDescriptors(descriptors);
		}
	}

	public static class bt_node_test_query_ut_1
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/query_ut_1");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Sequence_bt_node_test_query_ut_1_node0 node0 = new Sequence_bt_node_test_query_ut_1_node0();
				node0.SetClassNameString("Sequence");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					Query_bt_node_test_query_ut_1_node1 node1 = new Query_bt_node_test_query_ut_1_node1();
					node1.SetClassNameString("Query");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					Sequence node2 = new Sequence();
					node2.SetClassNameString("Sequence");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					{
						Query_bt_node_test_query_ut_1_node3 node3 = new Query_bt_node_test_query_ut_1_node3();
						node3.SetClassNameString("Query");
						node3.SetId(3);
#if !BEHAVIAC_RELEASE
						node3.SetAgentType("AgentNodeTest");
#endif
						node2.AddChild(node3);
						node2.SetHasEvents(node2.HasEvents() | node3.HasEvents());
					}
					{
						Query_bt_node_test_query_ut_1_node4 node4 = new Query_bt_node_test_query_ut_1_node4();
						node4.SetClassNameString("Query");
						node4.SetId(4);
#if !BEHAVIAC_RELEASE
						node4.SetAgentType("AgentNodeTest");
#endif
						node2.AddChild(node4);
						node2.SetHasEvents(node2.HasEvents() | node4.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/query_ut_2

	class Sequence_bt_node_test_query_ut_2_node0 : behaviac.Sequence
	{
		public Sequence_bt_node_test_query_ut_2_node0()
		{
			EnterAction_p0 = 0f;
			ExitAction_p0 = 0;
			ExitAction_p1 = "";
		}
		public override bool enteraction_impl(Agent pAgent)
		{
			((AgentNodeTest)pAgent).enter_action_1(EnterAction_p0);
			return true;
		}
		public override bool exitaction_impl(Agent pAgent)
		{
			((AgentNodeTest)pAgent).exit_action_2(ExitAction_p0, ExitAction_p1);
			return true;
		}
		float EnterAction_p0;
		int ExitAction_p0;
		string ExitAction_p1;
	}

	class Query_bt_node_test_query_ut_2_node1 : behaviac.Query
	{
		public Query_bt_node_test_query_ut_2_node1()
		{
			this.Initialize("test", "1:{Attribute=int Self.AgentNodeTest::testVar_1;Reference=const int 0;Weight=100;}");
		}
		public void Initialize(string domain, string descriptors)
		{
			this.m_domain = domain;
			this.SetDescriptors(descriptors);
		}
	}

	class Query_bt_node_test_query_ut_2_node3 : behaviac.Query
	{
		public Query_bt_node_test_query_ut_2_node3()
		{
			this.Initialize("test", "1:{Attribute=int Self.AgentNodeTest::testVar_1;Reference=const int 50;Weight=100;}");
		}
		public void Initialize(string domain, string descriptors)
		{
			this.m_domain = domain;
			this.SetDescriptors(descriptors);
		}
	}

	class Query_bt_node_test_query_ut_2_node4 : behaviac.Query
	{
		public Query_bt_node_test_query_ut_2_node4()
		{
			this.Initialize("test", "1:{Attribute=int Self.AgentNodeTest::testVar_1;Reference=const int 100;Weight=100;}");
		}
		public void Initialize(string domain, string descriptors)
		{
			this.m_domain = domain;
			this.SetDescriptors(descriptors);
		}
	}

	public static class bt_node_test_query_ut_2
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/query_ut_2");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Sequence_bt_node_test_query_ut_2_node0 node0 = new Sequence_bt_node_test_query_ut_2_node0();
				node0.SetClassNameString("Sequence");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					Query_bt_node_test_query_ut_2_node1 node1 = new Query_bt_node_test_query_ut_2_node1();
					node1.SetClassNameString("Query");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					Sequence node2 = new Sequence();
					node2.SetClassNameString("Sequence");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					{
						Query_bt_node_test_query_ut_2_node3 node3 = new Query_bt_node_test_query_ut_2_node3();
						node3.SetClassNameString("Query");
						node3.SetId(3);
#if !BEHAVIAC_RELEASE
						node3.SetAgentType("AgentNodeTest");
#endif
						node2.AddChild(node3);
						node2.SetHasEvents(node2.HasEvents() | node3.HasEvents());
					}
					{
						Query_bt_node_test_query_ut_2_node4 node4 = new Query_bt_node_test_query_ut_2_node4();
						node4.SetClassNameString("Query");
						node4.SetId(4);
#if !BEHAVIAC_RELEASE
						node4.SetAgentType("AgentNodeTest");
#endif
						node2.AddChild(node4);
						node2.SetHasEvents(node2.HasEvents() | node4.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/query_ut_3

	class Sequence_bt_node_test_query_ut_3_node0 : behaviac.Sequence
	{
		public Sequence_bt_node_test_query_ut_3_node0()
		{
			EnterAction_p0 = 0f;
			ExitAction_p0 = 0;
			ExitAction_p1 = "";
		}
		public override bool enteraction_impl(Agent pAgent)
		{
			((AgentNodeTest)pAgent).enter_action_1(EnterAction_p0);
			return true;
		}
		public override bool exitaction_impl(Agent pAgent)
		{
			((AgentNodeTest)pAgent).exit_action_2(ExitAction_p0, ExitAction_p1);
			return true;
		}
		float EnterAction_p0;
		int ExitAction_p0;
		string ExitAction_p1;
	}

	class Query_bt_node_test_query_ut_3_node1 : behaviac.Query
	{
		public Query_bt_node_test_query_ut_3_node1()
		{
			this.Initialize("test", "1:{Attribute=int Self.AgentNodeTest::testVar_1;Reference=const int 0;Weight=100;}");
		}
		public void Initialize(string domain, string descriptors)
		{
			this.m_domain = domain;
			this.SetDescriptors(descriptors);
		}
	}

	class Query_bt_node_test_query_ut_3_node3 : behaviac.Query
	{
		public Query_bt_node_test_query_ut_3_node3()
		{
			this.Initialize("test", "1:{Attribute=int Self.AgentNodeTest::testVar_1;Reference=const int 0;Weight=100;}");
		}
		public void Initialize(string domain, string descriptors)
		{
			this.m_domain = domain;
			this.SetDescriptors(descriptors);
		}
	}

	class Query_bt_node_test_query_ut_3_node4 : behaviac.Query
	{
		public Query_bt_node_test_query_ut_3_node4()
		{
			this.Initialize("test", "1:{Attribute=int Self.AgentNodeTest::testVar_1;Reference=const int 0;Weight=100;}");
		}
		public void Initialize(string domain, string descriptors)
		{
			this.m_domain = domain;
			this.SetDescriptors(descriptors);
		}
	}

	public static class bt_node_test_query_ut_3
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/query_ut_3");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Sequence_bt_node_test_query_ut_3_node0 node0 = new Sequence_bt_node_test_query_ut_3_node0();
				node0.SetClassNameString("Sequence");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					Query_bt_node_test_query_ut_3_node1 node1 = new Query_bt_node_test_query_ut_3_node1();
					node1.SetClassNameString("Query");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					Sequence node2 = new Sequence();
					node2.SetClassNameString("Sequence");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					{
						Query_bt_node_test_query_ut_3_node3 node3 = new Query_bt_node_test_query_ut_3_node3();
						node3.SetClassNameString("Query");
						node3.SetId(3);
#if !BEHAVIAC_RELEASE
						node3.SetAgentType("AgentNodeTest");
#endif
						node2.AddChild(node3);
						node2.SetHasEvents(node2.HasEvents() | node3.HasEvents());
					}
					{
						Query_bt_node_test_query_ut_3_node4 node4 = new Query_bt_node_test_query_ut_3_node4();
						node4.SetClassNameString("Query");
						node4.SetId(4);
#if !BEHAVIAC_RELEASE
						node4.SetAgentType("AgentNodeTest");
#endif
						node2.AddChild(node4);
						node2.SetHasEvents(node2.HasEvents() | node4.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/reference_sub_1

	public static class bt_node_test_reference_sub_1
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/reference_sub_1");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// pars
			bt.AddPar("int", "_$local_task_param_$_0", "0", "");
			bt.AddPar("float", "_$local_task_param_$_1", "0", "");
			// children
			{
				False node0 = new False();
				node0.SetClassNameString("False");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/selector_loop_ut_0

	class Action_bt_node_test_selector_loop_ut_0_node5 : behaviac.Action
	{
		public Action_bt_node_test_selector_loop_ut_0_node5()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Action_bt_node_test_selector_loop_ut_0_node6 : behaviac.Action
	{
		public Action_bt_node_test_selector_loop_ut_0_node6()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	public static class bt_node_test_selector_loop_ut_0
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/selector_loop_ut_0");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				SelectorLoop node0 = new SelectorLoop();
				node0.SetClassNameString("SelectorLoop");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					WithPrecondition node1 = new WithPrecondition();
					node1.SetClassNameString("WithPrecondition");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					{
						True node4 = new True();
						node4.SetClassNameString("True");
						node4.SetId(4);
#if !BEHAVIAC_RELEASE
						node4.SetAgentType("AgentNodeTest");
#endif
						node1.AddChild(node4);
						node1.SetHasEvents(node1.HasEvents() | node4.HasEvents());
					}
					{
						Action_bt_node_test_selector_loop_ut_0_node5 node5 = new Action_bt_node_test_selector_loop_ut_0_node5();
						node5.SetClassNameString("Action");
						node5.SetId(5);
#if !BEHAVIAC_RELEASE
						node5.SetAgentType("AgentNodeTest");
#endif
						node1.AddChild(node5);
						node1.SetHasEvents(node1.HasEvents() | node5.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					WithPrecondition node2 = new WithPrecondition();
					node2.SetClassNameString("WithPrecondition");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					{
						True node3 = new True();
						node3.SetClassNameString("True");
						node3.SetId(3);
#if !BEHAVIAC_RELEASE
						node3.SetAgentType("AgentNodeTest");
#endif
						node2.AddChild(node3);
						node2.SetHasEvents(node2.HasEvents() | node3.HasEvents());
					}
					{
						Action_bt_node_test_selector_loop_ut_0_node6 node6 = new Action_bt_node_test_selector_loop_ut_0_node6();
						node6.SetClassNameString("Action");
						node6.SetId(6);
#if !BEHAVIAC_RELEASE
						node6.SetAgentType("AgentNodeTest");
#endif
						node2.AddChild(node6);
						node2.SetHasEvents(node2.HasEvents() | node6.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/selector_loop_ut_1

	class Action_bt_node_test_selector_loop_ut_1_node5 : behaviac.Action
	{
		public Action_bt_node_test_selector_loop_ut_1_node5()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_FAILURE;
		}
		int method_p0;
	}

	class Action_bt_node_test_selector_loop_ut_1_node6 : behaviac.Action
	{
		public Action_bt_node_test_selector_loop_ut_1_node6()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	public static class bt_node_test_selector_loop_ut_1
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/selector_loop_ut_1");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				SelectorLoop node0 = new SelectorLoop();
				node0.SetClassNameString("SelectorLoop");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					WithPrecondition node1 = new WithPrecondition();
					node1.SetClassNameString("WithPrecondition");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					{
						True node4 = new True();
						node4.SetClassNameString("True");
						node4.SetId(4);
#if !BEHAVIAC_RELEASE
						node4.SetAgentType("AgentNodeTest");
#endif
						node1.AddChild(node4);
						node1.SetHasEvents(node1.HasEvents() | node4.HasEvents());
					}
					{
						Action_bt_node_test_selector_loop_ut_1_node5 node5 = new Action_bt_node_test_selector_loop_ut_1_node5();
						node5.SetClassNameString("Action");
						node5.SetId(5);
#if !BEHAVIAC_RELEASE
						node5.SetAgentType("AgentNodeTest");
#endif
						node1.AddChild(node5);
						node1.SetHasEvents(node1.HasEvents() | node5.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					WithPrecondition node2 = new WithPrecondition();
					node2.SetClassNameString("WithPrecondition");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					{
						True node3 = new True();
						node3.SetClassNameString("True");
						node3.SetId(3);
#if !BEHAVIAC_RELEASE
						node3.SetAgentType("AgentNodeTest");
#endif
						node2.AddChild(node3);
						node2.SetHasEvents(node2.HasEvents() | node3.HasEvents());
					}
					{
						Action_bt_node_test_selector_loop_ut_1_node6 node6 = new Action_bt_node_test_selector_loop_ut_1_node6();
						node6.SetClassNameString("Action");
						node6.SetId(6);
#if !BEHAVIAC_RELEASE
						node6.SetAgentType("AgentNodeTest");
#endif
						node2.AddChild(node6);
						node2.SetHasEvents(node2.HasEvents() | node6.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/selector_loop_ut_2

	class Action_bt_node_test_selector_loop_ut_2_node5 : behaviac.Action
	{
		public Action_bt_node_test_selector_loop_ut_2_node5()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_FAILURE;
		}
		int method_p0;
	}

	class Action_bt_node_test_selector_loop_ut_2_node6 : behaviac.Action
	{
		public Action_bt_node_test_selector_loop_ut_2_node6()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	public static class bt_node_test_selector_loop_ut_2
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/selector_loop_ut_2");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				SelectorLoop node0 = new SelectorLoop();
				node0.SetClassNameString("SelectorLoop");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					WithPrecondition node1 = new WithPrecondition();
					node1.SetClassNameString("WithPrecondition");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					{
						True node4 = new True();
						node4.SetClassNameString("True");
						node4.SetId(4);
#if !BEHAVIAC_RELEASE
						node4.SetAgentType("AgentNodeTest");
#endif
						node1.AddChild(node4);
						node1.SetHasEvents(node1.HasEvents() | node4.HasEvents());
					}
					{
						Action_bt_node_test_selector_loop_ut_2_node5 node5 = new Action_bt_node_test_selector_loop_ut_2_node5();
						node5.SetClassNameString("Action");
						node5.SetId(5);
#if !BEHAVIAC_RELEASE
						node5.SetAgentType("AgentNodeTest");
#endif
						node1.AddChild(node5);
						node1.SetHasEvents(node1.HasEvents() | node5.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					WithPrecondition node2 = new WithPrecondition();
					node2.SetClassNameString("WithPrecondition");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					{
						False node3 = new False();
						node3.SetClassNameString("False");
						node3.SetId(3);
#if !BEHAVIAC_RELEASE
						node3.SetAgentType("AgentNodeTest");
#endif
						node2.AddChild(node3);
						node2.SetHasEvents(node2.HasEvents() | node3.HasEvents());
					}
					{
						Action_bt_node_test_selector_loop_ut_2_node6 node6 = new Action_bt_node_test_selector_loop_ut_2_node6();
						node6.SetClassNameString("Action");
						node6.SetId(6);
#if !BEHAVIAC_RELEASE
						node6.SetAgentType("AgentNodeTest");
#endif
						node2.AddChild(node6);
						node2.SetHasEvents(node2.HasEvents() | node6.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/selector_loop_ut_3

	class Action_bt_node_test_selector_loop_ut_3_node5 : behaviac.Action
	{
		public Action_bt_node_test_selector_loop_ut_3_node5()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_RUNNING;
		}
		int method_p0;
	}

	class Action_bt_node_test_selector_loop_ut_3_node6 : behaviac.Action
	{
		public Action_bt_node_test_selector_loop_ut_3_node6()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	public static class bt_node_test_selector_loop_ut_3
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/selector_loop_ut_3");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				SelectorLoop node0 = new SelectorLoop();
				node0.SetClassNameString("SelectorLoop");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					WithPrecondition node1 = new WithPrecondition();
					node1.SetClassNameString("WithPrecondition");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					{
						False node4 = new False();
						node4.SetClassNameString("False");
						node4.SetId(4);
#if !BEHAVIAC_RELEASE
						node4.SetAgentType("AgentNodeTest");
#endif
						node1.AddChild(node4);
						node1.SetHasEvents(node1.HasEvents() | node4.HasEvents());
					}
					{
						Action_bt_node_test_selector_loop_ut_3_node5 node5 = new Action_bt_node_test_selector_loop_ut_3_node5();
						node5.SetClassNameString("Action");
						node5.SetId(5);
#if !BEHAVIAC_RELEASE
						node5.SetAgentType("AgentNodeTest");
#endif
						node1.AddChild(node5);
						node1.SetHasEvents(node1.HasEvents() | node5.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					WithPrecondition node2 = new WithPrecondition();
					node2.SetClassNameString("WithPrecondition");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					{
						False node3 = new False();
						node3.SetClassNameString("False");
						node3.SetId(3);
#if !BEHAVIAC_RELEASE
						node3.SetAgentType("AgentNodeTest");
#endif
						node2.AddChild(node3);
						node2.SetHasEvents(node2.HasEvents() | node3.HasEvents());
					}
					{
						Action_bt_node_test_selector_loop_ut_3_node6 node6 = new Action_bt_node_test_selector_loop_ut_3_node6();
						node6.SetClassNameString("Action");
						node6.SetId(6);
#if !BEHAVIAC_RELEASE
						node6.SetAgentType("AgentNodeTest");
#endif
						node2.AddChild(node6);
						node2.SetHasEvents(node2.HasEvents() | node6.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/selector_loop_ut_4

	class Action_bt_node_test_selector_loop_ut_4_node5 : behaviac.Action
	{
		public Action_bt_node_test_selector_loop_ut_4_node5()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_1(method_p0);
			return EBTStatus.BT_FAILURE;
		}
		int method_p0;
	}

	class Action_bt_node_test_selector_loop_ut_4_node6 : behaviac.Action
	{
		public Action_bt_node_test_selector_loop_ut_4_node6()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_RUNNING;
		}
		int method_p0;
	}

	public static class bt_node_test_selector_loop_ut_4
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/selector_loop_ut_4");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				SelectorLoop node0 = new SelectorLoop();
				node0.SetClassNameString("SelectorLoop");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					WithPrecondition node1 = new WithPrecondition();
					node1.SetClassNameString("WithPrecondition");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					{
						True node4 = new True();
						node4.SetClassNameString("True");
						node4.SetId(4);
#if !BEHAVIAC_RELEASE
						node4.SetAgentType("AgentNodeTest");
#endif
						node1.AddChild(node4);
						node1.SetHasEvents(node1.HasEvents() | node4.HasEvents());
					}
					{
						Action_bt_node_test_selector_loop_ut_4_node5 node5 = new Action_bt_node_test_selector_loop_ut_4_node5();
						node5.SetClassNameString("Action");
						node5.SetId(5);
#if !BEHAVIAC_RELEASE
						node5.SetAgentType("AgentNodeTest");
#endif
						node1.AddChild(node5);
						node1.SetHasEvents(node1.HasEvents() | node5.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					WithPrecondition node2 = new WithPrecondition();
					node2.SetClassNameString("WithPrecondition");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					{
						True node3 = new True();
						node3.SetClassNameString("True");
						node3.SetId(3);
#if !BEHAVIAC_RELEASE
						node3.SetAgentType("AgentNodeTest");
#endif
						node2.AddChild(node3);
						node2.SetHasEvents(node2.HasEvents() | node3.HasEvents());
					}
					{
						Action_bt_node_test_selector_loop_ut_4_node6 node6 = new Action_bt_node_test_selector_loop_ut_4_node6();
						node6.SetClassNameString("Action");
						node6.SetId(6);
#if !BEHAVIAC_RELEASE
						node6.SetAgentType("AgentNodeTest");
#endif
						node2.AddChild(node6);
						node2.SetHasEvents(node2.HasEvents() | node6.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/selector_loop_ut_5

	class Action_bt_node_test_selector_loop_ut_5_node5 : behaviac.Action
	{
		public Action_bt_node_test_selector_loop_ut_5_node5()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_RUNNING;
		}
		int method_p0;
	}

	class Action_bt_node_test_selector_loop_ut_5_node6 : behaviac.Action
	{
		public Action_bt_node_test_selector_loop_ut_5_node6()
		{
			method_p0 = "node_test/reference_sub_1";
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			behaviac.EBTStatus result = (behaviac.EBTStatus)((AgentNodeTest)pAgent).switchRef(method_p0);
			return result;
		}
		string method_p0;
	}

	class Action_bt_node_test_selector_loop_ut_5_node9 : behaviac.Action
	{
		public Action_bt_node_test_selector_loop_ut_5_node9()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	public static class bt_node_test_selector_loop_ut_5
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/selector_loop_ut_5");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				SelectorLoop node0 = new SelectorLoop();
				node0.SetClassNameString("SelectorLoop");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					WithPrecondition node1 = new WithPrecondition();
					node1.SetClassNameString("WithPrecondition");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					{
						False node4 = new False();
						node4.SetClassNameString("False");
						node4.SetId(4);
#if !BEHAVIAC_RELEASE
						node4.SetAgentType("AgentNodeTest");
#endif
						node1.AddChild(node4);
						node1.SetHasEvents(node1.HasEvents() | node4.HasEvents());
					}
					{
						Action_bt_node_test_selector_loop_ut_5_node5 node5 = new Action_bt_node_test_selector_loop_ut_5_node5();
						node5.SetClassNameString("Action");
						node5.SetId(5);
#if !BEHAVIAC_RELEASE
						node5.SetAgentType("AgentNodeTest");
#endif
						node1.AddChild(node5);
						node1.SetHasEvents(node1.HasEvents() | node5.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					WithPrecondition node2 = new WithPrecondition();
					node2.SetClassNameString("WithPrecondition");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					{
						True node3 = new True();
						node3.SetClassNameString("True");
						node3.SetId(3);
#if !BEHAVIAC_RELEASE
						node3.SetAgentType("AgentNodeTest");
#endif
						node2.AddChild(node3);
						node2.SetHasEvents(node2.HasEvents() | node3.HasEvents());
					}
					{
						Action_bt_node_test_selector_loop_ut_5_node6 node6 = new Action_bt_node_test_selector_loop_ut_5_node6();
						node6.SetClassNameString("Action");
						node6.SetId(6);
#if !BEHAVIAC_RELEASE
						node6.SetAgentType("AgentNodeTest");
#endif
						node2.AddChild(node6);
						node2.SetHasEvents(node2.HasEvents() | node6.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				{
					WithPrecondition node7 = new WithPrecondition();
					node7.SetClassNameString("WithPrecondition");
					node7.SetId(7);
#if !BEHAVIAC_RELEASE
					node7.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node7);
					{
						True node8 = new True();
						node8.SetClassNameString("True");
						node8.SetId(8);
#if !BEHAVIAC_RELEASE
						node8.SetAgentType("AgentNodeTest");
#endif
						node7.AddChild(node8);
						node7.SetHasEvents(node7.HasEvents() | node8.HasEvents());
					}
					{
						Action_bt_node_test_selector_loop_ut_5_node9 node9 = new Action_bt_node_test_selector_loop_ut_5_node9();
						node9.SetClassNameString("Action");
						node9.SetId(9);
#if !BEHAVIAC_RELEASE
						node9.SetAgentType("AgentNodeTest");
#endif
						node7.AddChild(node9);
						node7.SetHasEvents(node7.HasEvents() | node9.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node7.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/selector_probability_ut_0

	class SelectorProbability_bt_node_test_selector_probability_ut_0_node0 : behaviac.SelectorProbability
	{
		public SelectorProbability_bt_node_test_selector_probability_ut_0_node0()
		{
		}
		public void Initialize(string method)
		{
			this.m_method = Action.LoadMethod(method);
		}
	}

	class DecoratorWeight_bt_node_test_selector_probability_ut_0_node3 : behaviac.DecoratorWeight
	{
		public DecoratorWeight_bt_node_test_selector_probability_ut_0_node3()
		{
			m_bDecorateWhenChildEnds = false;
		}
		protected override int GetWeight(Agent pAgent)
		{
			return 20;
		}
	}

	class Action_bt_node_test_selector_probability_ut_0_node1 : behaviac.Action
	{
		public Action_bt_node_test_selector_probability_ut_0_node1()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class DecoratorWeight_bt_node_test_selector_probability_ut_0_node5 : behaviac.DecoratorWeight
	{
		public DecoratorWeight_bt_node_test_selector_probability_ut_0_node5()
		{
			m_bDecorateWhenChildEnds = false;
		}
		protected override int GetWeight(Agent pAgent)
		{
			return 30;
		}
	}

	class Action_bt_node_test_selector_probability_ut_0_node2 : behaviac.Action
	{
		public Action_bt_node_test_selector_probability_ut_0_node2()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class DecoratorWeight_bt_node_test_selector_probability_ut_0_node6 : behaviac.DecoratorWeight
	{
		public DecoratorWeight_bt_node_test_selector_probability_ut_0_node6()
		{
			m_bDecorateWhenChildEnds = false;
		}
		protected override int GetWeight(Agent pAgent)
		{
			return 50;
		}
	}

	class Action_bt_node_test_selector_probability_ut_0_node4 : behaviac.Action
	{
		public Action_bt_node_test_selector_probability_ut_0_node4()
		{
			method_p0 = 2;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	public static class bt_node_test_selector_probability_ut_0
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/selector_probability_ut_0");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				SelectorProbability_bt_node_test_selector_probability_ut_0_node0 node0 = new SelectorProbability_bt_node_test_selector_probability_ut_0_node0();
				node0.SetClassNameString("SelectorProbability");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					DecoratorWeight_bt_node_test_selector_probability_ut_0_node3 node3 = new DecoratorWeight_bt_node_test_selector_probability_ut_0_node3();
					node3.SetClassNameString("DecoratorWeight");
					node3.SetId(3);
#if !BEHAVIAC_RELEASE
					node3.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node3);
					{
						Action_bt_node_test_selector_probability_ut_0_node1 node1 = new Action_bt_node_test_selector_probability_ut_0_node1();
						node1.SetClassNameString("Action");
						node1.SetId(1);
#if !BEHAVIAC_RELEASE
						node1.SetAgentType("AgentNodeTest");
#endif
						node3.AddChild(node1);
						node3.SetHasEvents(node3.HasEvents() | node1.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node3.HasEvents());
				}
				{
					DecoratorWeight_bt_node_test_selector_probability_ut_0_node5 node5 = new DecoratorWeight_bt_node_test_selector_probability_ut_0_node5();
					node5.SetClassNameString("DecoratorWeight");
					node5.SetId(5);
#if !BEHAVIAC_RELEASE
					node5.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node5);
					{
						Action_bt_node_test_selector_probability_ut_0_node2 node2 = new Action_bt_node_test_selector_probability_ut_0_node2();
						node2.SetClassNameString("Action");
						node2.SetId(2);
#if !BEHAVIAC_RELEASE
						node2.SetAgentType("AgentNodeTest");
#endif
						node5.AddChild(node2);
						node5.SetHasEvents(node5.HasEvents() | node2.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node5.HasEvents());
				}
				{
					DecoratorWeight_bt_node_test_selector_probability_ut_0_node6 node6 = new DecoratorWeight_bt_node_test_selector_probability_ut_0_node6();
					node6.SetClassNameString("DecoratorWeight");
					node6.SetId(6);
#if !BEHAVIAC_RELEASE
					node6.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node6);
					{
						Action_bt_node_test_selector_probability_ut_0_node4 node4 = new Action_bt_node_test_selector_probability_ut_0_node4();
						node4.SetClassNameString("Action");
						node4.SetId(4);
#if !BEHAVIAC_RELEASE
						node4.SetAgentType("AgentNodeTest");
#endif
						node6.AddChild(node4);
						node6.SetHasEvents(node6.HasEvents() | node4.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node6.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/selector_probability_ut_1

	class SelectorProbability_bt_node_test_selector_probability_ut_1_node0 : behaviac.SelectorProbability
	{
		public SelectorProbability_bt_node_test_selector_probability_ut_1_node0()
		{
		}
		public void Initialize(string method)
		{
			this.m_method = Action.LoadMethod(method);
		}
	}

	class DecoratorWeight_bt_node_test_selector_probability_ut_1_node4 : behaviac.DecoratorWeight
	{
		public DecoratorWeight_bt_node_test_selector_probability_ut_1_node4()
		{
			m_bDecorateWhenChildEnds = false;
		}
		protected override int GetWeight(Agent pAgent)
		{
			return 0;
		}
	}

	class Action_bt_node_test_selector_probability_ut_1_node1 : behaviac.Action
	{
		public Action_bt_node_test_selector_probability_ut_1_node1()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_FAILURE;
		}
		int method_p0;
	}

	class DecoratorWeight_bt_node_test_selector_probability_ut_1_node5 : behaviac.DecoratorWeight
	{
		public DecoratorWeight_bt_node_test_selector_probability_ut_1_node5()
		{
			m_bDecorateWhenChildEnds = false;
		}
		protected override int GetWeight(Agent pAgent)
		{
			return 1;
		}
	}

	class Action_bt_node_test_selector_probability_ut_1_node2 : behaviac.Action
	{
		public Action_bt_node_test_selector_probability_ut_1_node2()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_FAILURE;
		}
		int method_p0;
	}

	class DecoratorWeight_bt_node_test_selector_probability_ut_1_node6 : behaviac.DecoratorWeight
	{
		public DecoratorWeight_bt_node_test_selector_probability_ut_1_node6()
		{
			m_bDecorateWhenChildEnds = false;
		}
		protected override int GetWeight(Agent pAgent)
		{
			return 1;
		}
	}

	class Action_bt_node_test_selector_probability_ut_1_node3 : behaviac.Action
	{
		public Action_bt_node_test_selector_probability_ut_1_node3()
		{
			method_p0 = 2;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	public static class bt_node_test_selector_probability_ut_1
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/selector_probability_ut_1");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				SelectorProbability_bt_node_test_selector_probability_ut_1_node0 node0 = new SelectorProbability_bt_node_test_selector_probability_ut_1_node0();
				node0.SetClassNameString("SelectorProbability");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					DecoratorWeight_bt_node_test_selector_probability_ut_1_node4 node4 = new DecoratorWeight_bt_node_test_selector_probability_ut_1_node4();
					node4.SetClassNameString("DecoratorWeight");
					node4.SetId(4);
#if !BEHAVIAC_RELEASE
					node4.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node4);
					{
						Action_bt_node_test_selector_probability_ut_1_node1 node1 = new Action_bt_node_test_selector_probability_ut_1_node1();
						node1.SetClassNameString("Action");
						node1.SetId(1);
#if !BEHAVIAC_RELEASE
						node1.SetAgentType("AgentNodeTest");
#endif
						node4.AddChild(node1);
						node4.SetHasEvents(node4.HasEvents() | node1.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node4.HasEvents());
				}
				{
					DecoratorWeight_bt_node_test_selector_probability_ut_1_node5 node5 = new DecoratorWeight_bt_node_test_selector_probability_ut_1_node5();
					node5.SetClassNameString("DecoratorWeight");
					node5.SetId(5);
#if !BEHAVIAC_RELEASE
					node5.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node5);
					{
						Action_bt_node_test_selector_probability_ut_1_node2 node2 = new Action_bt_node_test_selector_probability_ut_1_node2();
						node2.SetClassNameString("Action");
						node2.SetId(2);
#if !BEHAVIAC_RELEASE
						node2.SetAgentType("AgentNodeTest");
#endif
						node5.AddChild(node2);
						node5.SetHasEvents(node5.HasEvents() | node2.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node5.HasEvents());
				}
				{
					DecoratorWeight_bt_node_test_selector_probability_ut_1_node6 node6 = new DecoratorWeight_bt_node_test_selector_probability_ut_1_node6();
					node6.SetClassNameString("DecoratorWeight");
					node6.SetId(6);
#if !BEHAVIAC_RELEASE
					node6.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node6);
					{
						Action_bt_node_test_selector_probability_ut_1_node3 node3 = new Action_bt_node_test_selector_probability_ut_1_node3();
						node3.SetClassNameString("Action");
						node3.SetId(3);
#if !BEHAVIAC_RELEASE
						node3.SetAgentType("AgentNodeTest");
#endif
						node6.AddChild(node3);
						node6.SetHasEvents(node6.HasEvents() | node3.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node6.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/selector_probability_ut_2

	class SelectorProbability_bt_node_test_selector_probability_ut_2_node0 : behaviac.SelectorProbability
	{
		public SelectorProbability_bt_node_test_selector_probability_ut_2_node0()
		{
		}
		public void Initialize(string method)
		{
			this.m_method = Action.LoadMethod(method);
		}
	}

	class DecoratorWeight_bt_node_test_selector_probability_ut_2_node4 : behaviac.DecoratorWeight
	{
		public DecoratorWeight_bt_node_test_selector_probability_ut_2_node4()
		{
			m_bDecorateWhenChildEnds = false;
		}
		protected override int GetWeight(Agent pAgent)
		{
			return 0;
		}
	}

	class Action_bt_node_test_selector_probability_ut_2_node1 : behaviac.Action
	{
		public Action_bt_node_test_selector_probability_ut_2_node1()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class DecoratorWeight_bt_node_test_selector_probability_ut_2_node5 : behaviac.DecoratorWeight
	{
		public DecoratorWeight_bt_node_test_selector_probability_ut_2_node5()
		{
			m_bDecorateWhenChildEnds = false;
		}
		protected override int GetWeight(Agent pAgent)
		{
			return 0;
		}
	}

	class Action_bt_node_test_selector_probability_ut_2_node2 : behaviac.Action
	{
		public Action_bt_node_test_selector_probability_ut_2_node2()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class DecoratorWeight_bt_node_test_selector_probability_ut_2_node6 : behaviac.DecoratorWeight
	{
		public DecoratorWeight_bt_node_test_selector_probability_ut_2_node6()
		{
			m_bDecorateWhenChildEnds = false;
		}
		protected override int GetWeight(Agent pAgent)
		{
			return 0;
		}
	}

	class Action_bt_node_test_selector_probability_ut_2_node3 : behaviac.Action
	{
		public Action_bt_node_test_selector_probability_ut_2_node3()
		{
			method_p0 = 2;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	public static class bt_node_test_selector_probability_ut_2
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/selector_probability_ut_2");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				SelectorProbability_bt_node_test_selector_probability_ut_2_node0 node0 = new SelectorProbability_bt_node_test_selector_probability_ut_2_node0();
				node0.SetClassNameString("SelectorProbability");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					DecoratorWeight_bt_node_test_selector_probability_ut_2_node4 node4 = new DecoratorWeight_bt_node_test_selector_probability_ut_2_node4();
					node4.SetClassNameString("DecoratorWeight");
					node4.SetId(4);
#if !BEHAVIAC_RELEASE
					node4.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node4);
					{
						Action_bt_node_test_selector_probability_ut_2_node1 node1 = new Action_bt_node_test_selector_probability_ut_2_node1();
						node1.SetClassNameString("Action");
						node1.SetId(1);
#if !BEHAVIAC_RELEASE
						node1.SetAgentType("AgentNodeTest");
#endif
						node4.AddChild(node1);
						node4.SetHasEvents(node4.HasEvents() | node1.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node4.HasEvents());
				}
				{
					DecoratorWeight_bt_node_test_selector_probability_ut_2_node5 node5 = new DecoratorWeight_bt_node_test_selector_probability_ut_2_node5();
					node5.SetClassNameString("DecoratorWeight");
					node5.SetId(5);
#if !BEHAVIAC_RELEASE
					node5.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node5);
					{
						Action_bt_node_test_selector_probability_ut_2_node2 node2 = new Action_bt_node_test_selector_probability_ut_2_node2();
						node2.SetClassNameString("Action");
						node2.SetId(2);
#if !BEHAVIAC_RELEASE
						node2.SetAgentType("AgentNodeTest");
#endif
						node5.AddChild(node2);
						node5.SetHasEvents(node5.HasEvents() | node2.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node5.HasEvents());
				}
				{
					DecoratorWeight_bt_node_test_selector_probability_ut_2_node6 node6 = new DecoratorWeight_bt_node_test_selector_probability_ut_2_node6();
					node6.SetClassNameString("DecoratorWeight");
					node6.SetId(6);
#if !BEHAVIAC_RELEASE
					node6.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node6);
					{
						Action_bt_node_test_selector_probability_ut_2_node3 node3 = new Action_bt_node_test_selector_probability_ut_2_node3();
						node3.SetClassNameString("Action");
						node3.SetId(3);
#if !BEHAVIAC_RELEASE
						node3.SetAgentType("AgentNodeTest");
#endif
						node6.AddChild(node3);
						node6.SetHasEvents(node6.HasEvents() | node3.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node6.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/selector_stochastic_ut_0

	class SelectorStochastic_bt_node_test_selector_stochastic_ut_0_node0 : behaviac.SelectorStochastic
	{
		public SelectorStochastic_bt_node_test_selector_stochastic_ut_0_node0()
		{
		}
		public void Initialize(string method)
		{
			this.m_method = Action.LoadMethod(method);
		}
	}

	class Action_bt_node_test_selector_stochastic_ut_0_node1 : behaviac.Action
	{
		public Action_bt_node_test_selector_stochastic_ut_0_node1()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Action_bt_node_test_selector_stochastic_ut_0_node2 : behaviac.Action
	{
		public Action_bt_node_test_selector_stochastic_ut_0_node2()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Action_bt_node_test_selector_stochastic_ut_0_node3 : behaviac.Action
	{
		public Action_bt_node_test_selector_stochastic_ut_0_node3()
		{
			method_p0 = 2;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	public static class bt_node_test_selector_stochastic_ut_0
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/selector_stochastic_ut_0");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				SelectorStochastic_bt_node_test_selector_stochastic_ut_0_node0 node0 = new SelectorStochastic_bt_node_test_selector_stochastic_ut_0_node0();
				node0.SetClassNameString("SelectorStochastic");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					Action_bt_node_test_selector_stochastic_ut_0_node1 node1 = new Action_bt_node_test_selector_stochastic_ut_0_node1();
					node1.SetClassNameString("Action");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					Action_bt_node_test_selector_stochastic_ut_0_node2 node2 = new Action_bt_node_test_selector_stochastic_ut_0_node2();
					node2.SetClassNameString("Action");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				{
					Action_bt_node_test_selector_stochastic_ut_0_node3 node3 = new Action_bt_node_test_selector_stochastic_ut_0_node3();
					node3.SetClassNameString("Action");
					node3.SetId(3);
#if !BEHAVIAC_RELEASE
					node3.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node3);
					node0.SetHasEvents(node0.HasEvents() | node3.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/selector_stochastic_ut_1

	class SelectorStochastic_bt_node_test_selector_stochastic_ut_1_node0 : behaviac.SelectorStochastic
	{
		public SelectorStochastic_bt_node_test_selector_stochastic_ut_1_node0()
		{
		}
		public void Initialize(string method)
		{
			this.m_method = Action.LoadMethod(method);
		}
	}

	class Action_bt_node_test_selector_stochastic_ut_1_node1 : behaviac.Action
	{
		public Action_bt_node_test_selector_stochastic_ut_1_node1()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	public static class bt_node_test_selector_stochastic_ut_1
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/selector_stochastic_ut_1");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				SelectorStochastic_bt_node_test_selector_stochastic_ut_1_node0 node0 = new SelectorStochastic_bt_node_test_selector_stochastic_ut_1_node0();
				node0.SetClassNameString("SelectorStochastic");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					Action_bt_node_test_selector_stochastic_ut_1_node1 node1 = new Action_bt_node_test_selector_stochastic_ut_1_node1();
					node1.SetClassNameString("Action");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					True node2 = new True();
					node2.SetClassNameString("True");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				{
					True node3 = new True();
					node3.SetClassNameString("True");
					node3.SetId(3);
#if !BEHAVIAC_RELEASE
					node3.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node3);
					node0.SetHasEvents(node0.HasEvents() | node3.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/selector_stochastic_ut_2

	class SelectorStochastic_bt_node_test_selector_stochastic_ut_2_node4 : behaviac.SelectorStochastic
	{
		public SelectorStochastic_bt_node_test_selector_stochastic_ut_2_node4()
		{
		}
		public void Initialize(string method)
		{
			this.m_method = Action.LoadMethod(method);
		}
	}

	class Action_bt_node_test_selector_stochastic_ut_2_node5 : behaviac.Action
	{
		public Action_bt_node_test_selector_stochastic_ut_2_node5()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	public static class bt_node_test_selector_stochastic_ut_2
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/selector_stochastic_ut_2");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				SelectorStochastic_bt_node_test_selector_stochastic_ut_2_node4 node4 = new SelectorStochastic_bt_node_test_selector_stochastic_ut_2_node4();
				node4.SetClassNameString("SelectorStochastic");
				node4.SetId(4);
#if !BEHAVIAC_RELEASE
				node4.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node4);
				{
					Action_bt_node_test_selector_stochastic_ut_2_node5 node5 = new Action_bt_node_test_selector_stochastic_ut_2_node5();
					node5.SetClassNameString("Action");
					node5.SetId(5);
#if !BEHAVIAC_RELEASE
					node5.SetAgentType("AgentNodeTest");
#endif
					node4.AddChild(node5);
					node4.SetHasEvents(node4.HasEvents() | node5.HasEvents());
				}
				{
					False node0 = new False();
					node0.SetClassNameString("False");
					node0.SetId(0);
#if !BEHAVIAC_RELEASE
					node0.SetAgentType("AgentNodeTest");
#endif
					node4.AddChild(node0);
					node4.SetHasEvents(node4.HasEvents() | node0.HasEvents());
				}
				{
					True node2 = new True();
					node2.SetClassNameString("True");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node4.AddChild(node2);
					node4.SetHasEvents(node4.HasEvents() | node2.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node4.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/selector_ut_0

	class Action_bt_node_test_selector_ut_0_node1 : behaviac.Action
	{
		public Action_bt_node_test_selector_ut_0_node1()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Action_bt_node_test_selector_ut_0_node2 : behaviac.Action
	{
		public Action_bt_node_test_selector_ut_0_node2()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_FAILURE;
		}
		int method_p0;
	}

	class Action_bt_node_test_selector_ut_0_node3 : behaviac.Action
	{
		public Action_bt_node_test_selector_ut_0_node3()
		{
			method_p0 = 2;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_FAILURE;
		}
		int method_p0;
	}

	public static class bt_node_test_selector_ut_0
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/selector_ut_0");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Selector node0 = new Selector();
				node0.SetClassNameString("Selector");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					Action_bt_node_test_selector_ut_0_node1 node1 = new Action_bt_node_test_selector_ut_0_node1();
					node1.SetClassNameString("Action");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					Action_bt_node_test_selector_ut_0_node2 node2 = new Action_bt_node_test_selector_ut_0_node2();
					node2.SetClassNameString("Action");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				{
					Action_bt_node_test_selector_ut_0_node3 node3 = new Action_bt_node_test_selector_ut_0_node3();
					node3.SetClassNameString("Action");
					node3.SetId(3);
#if !BEHAVIAC_RELEASE
					node3.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node3);
					node0.SetHasEvents(node0.HasEvents() | node3.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/selector_ut_1

	class Action_bt_node_test_selector_ut_1_node1 : behaviac.Action
	{
		public Action_bt_node_test_selector_ut_1_node1()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_FAILURE;
		}
		int method_p0;
	}

	class Action_bt_node_test_selector_ut_1_node2 : behaviac.Action
	{
		public Action_bt_node_test_selector_ut_1_node2()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Action_bt_node_test_selector_ut_1_node3 : behaviac.Action
	{
		public Action_bt_node_test_selector_ut_1_node3()
		{
			method_p0 = 2;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_FAILURE;
		}
		int method_p0;
	}

	public static class bt_node_test_selector_ut_1
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/selector_ut_1");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Selector node0 = new Selector();
				node0.SetClassNameString("Selector");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					Action_bt_node_test_selector_ut_1_node1 node1 = new Action_bt_node_test_selector_ut_1_node1();
					node1.SetClassNameString("Action");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					Action_bt_node_test_selector_ut_1_node2 node2 = new Action_bt_node_test_selector_ut_1_node2();
					node2.SetClassNameString("Action");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				{
					Action_bt_node_test_selector_ut_1_node3 node3 = new Action_bt_node_test_selector_ut_1_node3();
					node3.SetClassNameString("Action");
					node3.SetId(3);
#if !BEHAVIAC_RELEASE
					node3.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node3);
					node0.SetHasEvents(node0.HasEvents() | node3.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/selector_ut_2

	class Action_bt_node_test_selector_ut_2_node1 : behaviac.Action
	{
		public Action_bt_node_test_selector_ut_2_node1()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_FAILURE;
		}
		int method_p0;
	}

	class Action_bt_node_test_selector_ut_2_node2 : behaviac.Action
	{
		public Action_bt_node_test_selector_ut_2_node2()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_FAILURE;
		}
		int method_p0;
	}

	class Action_bt_node_test_selector_ut_2_node3 : behaviac.Action
	{
		public Action_bt_node_test_selector_ut_2_node3()
		{
			method_p0 = 2;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	public static class bt_node_test_selector_ut_2
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/selector_ut_2");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Selector node0 = new Selector();
				node0.SetClassNameString("Selector");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					Action_bt_node_test_selector_ut_2_node1 node1 = new Action_bt_node_test_selector_ut_2_node1();
					node1.SetClassNameString("Action");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					Action_bt_node_test_selector_ut_2_node2 node2 = new Action_bt_node_test_selector_ut_2_node2();
					node2.SetClassNameString("Action");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				{
					Action_bt_node_test_selector_ut_2_node3 node3 = new Action_bt_node_test_selector_ut_2_node3();
					node3.SetClassNameString("Action");
					node3.SetId(3);
#if !BEHAVIAC_RELEASE
					node3.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node3);
					node0.SetHasEvents(node0.HasEvents() | node3.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/selector_ut_3

	class Action_bt_node_test_selector_ut_3_node1 : behaviac.Action
	{
		public Action_bt_node_test_selector_ut_3_node1()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_FAILURE;
		}
		int method_p0;
	}

	class Action_bt_node_test_selector_ut_3_node2 : behaviac.Action
	{
		public Action_bt_node_test_selector_ut_3_node2()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_FAILURE;
		}
		int method_p0;
	}

	class Action_bt_node_test_selector_ut_3_node3 : behaviac.Action
	{
		public Action_bt_node_test_selector_ut_3_node3()
		{
			method_p0 = 2;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_FAILURE;
		}
		int method_p0;
	}

	public static class bt_node_test_selector_ut_3
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/selector_ut_3");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Selector node0 = new Selector();
				node0.SetClassNameString("Selector");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					Action_bt_node_test_selector_ut_3_node1 node1 = new Action_bt_node_test_selector_ut_3_node1();
					node1.SetClassNameString("Action");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					Action_bt_node_test_selector_ut_3_node2 node2 = new Action_bt_node_test_selector_ut_3_node2();
					node2.SetClassNameString("Action");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				{
					Action_bt_node_test_selector_ut_3_node3 node3 = new Action_bt_node_test_selector_ut_3_node3();
					node3.SetClassNameString("Action");
					node3.SetId(3);
#if !BEHAVIAC_RELEASE
					node3.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node3);
					node0.SetHasEvents(node0.HasEvents() | node3.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/selector_ut_4

	class Action_bt_node_test_selector_ut_4_node1 : behaviac.Action
	{
		public Action_bt_node_test_selector_ut_4_node1()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Action_bt_node_test_selector_ut_4_node2 : behaviac.Action
	{
		public Action_bt_node_test_selector_ut_4_node2()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Action_bt_node_test_selector_ut_4_node3 : behaviac.Action
	{
		public Action_bt_node_test_selector_ut_4_node3()
		{
			method_p0 = 2;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	public static class bt_node_test_selector_ut_4
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/selector_ut_4");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Selector node0 = new Selector();
				node0.SetClassNameString("Selector");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					Action_bt_node_test_selector_ut_4_node1 node1 = new Action_bt_node_test_selector_ut_4_node1();
					node1.SetClassNameString("Action");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					Action_bt_node_test_selector_ut_4_node2 node2 = new Action_bt_node_test_selector_ut_4_node2();
					node2.SetClassNameString("Action");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				{
					Action_bt_node_test_selector_ut_4_node3 node3 = new Action_bt_node_test_selector_ut_4_node3();
					node3.SetClassNameString("Action");
					node3.SetId(3);
#if !BEHAVIAC_RELEASE
					node3.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node3);
					node0.SetHasEvents(node0.HasEvents() | node3.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/sequence_stochastic_ut_0

	class SequenceStochastic_bt_node_test_sequence_stochastic_ut_0_node0 : behaviac.SequenceStochastic
	{
		public SequenceStochastic_bt_node_test_sequence_stochastic_ut_0_node0()
		{
		}
		public void Initialize(string method)
		{
			this.m_method = Action.LoadMethod(method);
		}
	}

	class Action_bt_node_test_sequence_stochastic_ut_0_node1 : behaviac.Action
	{
		public Action_bt_node_test_sequence_stochastic_ut_0_node1()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Action_bt_node_test_sequence_stochastic_ut_0_node2 : behaviac.Action
	{
		public Action_bt_node_test_sequence_stochastic_ut_0_node2()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Action_bt_node_test_sequence_stochastic_ut_0_node3 : behaviac.Action
	{
		public Action_bt_node_test_sequence_stochastic_ut_0_node3()
		{
			method_p0 = 2;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	public static class bt_node_test_sequence_stochastic_ut_0
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/sequence_stochastic_ut_0");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				SequenceStochastic_bt_node_test_sequence_stochastic_ut_0_node0 node0 = new SequenceStochastic_bt_node_test_sequence_stochastic_ut_0_node0();
				node0.SetClassNameString("SequenceStochastic");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					Action_bt_node_test_sequence_stochastic_ut_0_node1 node1 = new Action_bt_node_test_sequence_stochastic_ut_0_node1();
					node1.SetClassNameString("Action");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					Action_bt_node_test_sequence_stochastic_ut_0_node2 node2 = new Action_bt_node_test_sequence_stochastic_ut_0_node2();
					node2.SetClassNameString("Action");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				{
					Action_bt_node_test_sequence_stochastic_ut_0_node3 node3 = new Action_bt_node_test_sequence_stochastic_ut_0_node3();
					node3.SetClassNameString("Action");
					node3.SetId(3);
#if !BEHAVIAC_RELEASE
					node3.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node3);
					node0.SetHasEvents(node0.HasEvents() | node3.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/sequence_stochastic_ut_1

	class SequenceStochastic_bt_node_test_sequence_stochastic_ut_1_node0 : behaviac.SequenceStochastic
	{
		public SequenceStochastic_bt_node_test_sequence_stochastic_ut_1_node0()
		{
		}
		public void Initialize(string method)
		{
			this.m_method = Action.LoadMethod(method);
		}
	}

	class Action_bt_node_test_sequence_stochastic_ut_1_node1 : behaviac.Action
	{
		public Action_bt_node_test_sequence_stochastic_ut_1_node1()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	public static class bt_node_test_sequence_stochastic_ut_1
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/sequence_stochastic_ut_1");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				SequenceStochastic_bt_node_test_sequence_stochastic_ut_1_node0 node0 = new SequenceStochastic_bt_node_test_sequence_stochastic_ut_1_node0();
				node0.SetClassNameString("SequenceStochastic");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					Action_bt_node_test_sequence_stochastic_ut_1_node1 node1 = new Action_bt_node_test_sequence_stochastic_ut_1_node1();
					node1.SetClassNameString("Action");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					False node2 = new False();
					node2.SetClassNameString("False");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				{
					False node3 = new False();
					node3.SetClassNameString("False");
					node3.SetId(3);
#if !BEHAVIAC_RELEASE
					node3.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node3);
					node0.SetHasEvents(node0.HasEvents() | node3.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/sequence_stochastic_ut_2

	class SequenceStochastic_bt_node_test_sequence_stochastic_ut_2_node0 : behaviac.SequenceStochastic
	{
		public SequenceStochastic_bt_node_test_sequence_stochastic_ut_2_node0()
		{
		}
		public void Initialize(string method)
		{
			this.m_method = Action.LoadMethod(method);
		}
	}

	class Action_bt_node_test_sequence_stochastic_ut_2_node1 : behaviac.Action
	{
		public Action_bt_node_test_sequence_stochastic_ut_2_node1()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	public static class bt_node_test_sequence_stochastic_ut_2
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/sequence_stochastic_ut_2");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				SequenceStochastic_bt_node_test_sequence_stochastic_ut_2_node0 node0 = new SequenceStochastic_bt_node_test_sequence_stochastic_ut_2_node0();
				node0.SetClassNameString("SequenceStochastic");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					False node2 = new False();
					node2.SetClassNameString("False");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				{
					Action_bt_node_test_sequence_stochastic_ut_2_node1 node1 = new Action_bt_node_test_sequence_stochastic_ut_2_node1();
					node1.SetClassNameString("Action");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					False node3 = new False();
					node3.SetClassNameString("False");
					node3.SetId(3);
#if !BEHAVIAC_RELEASE
					node3.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node3);
					node0.SetHasEvents(node0.HasEvents() | node3.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/sequence_stochastic_ut_3

	class SequenceStochastic_bt_node_test_sequence_stochastic_ut_3_node0 : behaviac.SequenceStochastic
	{
		public SequenceStochastic_bt_node_test_sequence_stochastic_ut_3_node0()
		{
		}
		public void Initialize(string method)
		{
			this.m_method = Action.LoadMethod(method);
		}
	}

	class Action_bt_node_test_sequence_stochastic_ut_3_node1 : behaviac.Action
	{
		public Action_bt_node_test_sequence_stochastic_ut_3_node1()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	public static class bt_node_test_sequence_stochastic_ut_3
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/sequence_stochastic_ut_3");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				SequenceStochastic_bt_node_test_sequence_stochastic_ut_3_node0 node0 = new SequenceStochastic_bt_node_test_sequence_stochastic_ut_3_node0();
				node0.SetClassNameString("SequenceStochastic");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					False node2 = new False();
					node2.SetClassNameString("False");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				{
					False node3 = new False();
					node3.SetClassNameString("False");
					node3.SetId(3);
#if !BEHAVIAC_RELEASE
					node3.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node3);
					node0.SetHasEvents(node0.HasEvents() | node3.HasEvents());
				}
				{
					Action_bt_node_test_sequence_stochastic_ut_3_node1 node1 = new Action_bt_node_test_sequence_stochastic_ut_3_node1();
					node1.SetClassNameString("Action");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/sequence_ut_0

	class Action_bt_node_test_sequence_ut_0_node1 : behaviac.Action
	{
		public Action_bt_node_test_sequence_ut_0_node1()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_FAILURE;
		}
		int method_p0;
	}

	class Action_bt_node_test_sequence_ut_0_node2 : behaviac.Action
	{
		public Action_bt_node_test_sequence_ut_0_node2()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_FAILURE;
		}
		int method_p0;
	}

	class Action_bt_node_test_sequence_ut_0_node3 : behaviac.Action
	{
		public Action_bt_node_test_sequence_ut_0_node3()
		{
			method_p0 = 2;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_FAILURE;
		}
		int method_p0;
	}

	public static class bt_node_test_sequence_ut_0
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/sequence_ut_0");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Sequence node0 = new Sequence();
				node0.SetClassNameString("Sequence");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					Action_bt_node_test_sequence_ut_0_node1 node1 = new Action_bt_node_test_sequence_ut_0_node1();
					node1.SetClassNameString("Action");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					Action_bt_node_test_sequence_ut_0_node2 node2 = new Action_bt_node_test_sequence_ut_0_node2();
					node2.SetClassNameString("Action");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				{
					Action_bt_node_test_sequence_ut_0_node3 node3 = new Action_bt_node_test_sequence_ut_0_node3();
					node3.SetClassNameString("Action");
					node3.SetId(3);
#if !BEHAVIAC_RELEASE
					node3.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node3);
					node0.SetHasEvents(node0.HasEvents() | node3.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/sequence_ut_1

	class Action_bt_node_test_sequence_ut_1_node1 : behaviac.Action
	{
		public Action_bt_node_test_sequence_ut_1_node1()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Action_bt_node_test_sequence_ut_1_node2 : behaviac.Action
	{
		public Action_bt_node_test_sequence_ut_1_node2()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_FAILURE;
		}
		int method_p0;
	}

	class Action_bt_node_test_sequence_ut_1_node3 : behaviac.Action
	{
		public Action_bt_node_test_sequence_ut_1_node3()
		{
			method_p0 = 2;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_FAILURE;
		}
		int method_p0;
	}

	public static class bt_node_test_sequence_ut_1
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/sequence_ut_1");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Sequence node0 = new Sequence();
				node0.SetClassNameString("Sequence");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					Action_bt_node_test_sequence_ut_1_node1 node1 = new Action_bt_node_test_sequence_ut_1_node1();
					node1.SetClassNameString("Action");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					Action_bt_node_test_sequence_ut_1_node2 node2 = new Action_bt_node_test_sequence_ut_1_node2();
					node2.SetClassNameString("Action");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				{
					Action_bt_node_test_sequence_ut_1_node3 node3 = new Action_bt_node_test_sequence_ut_1_node3();
					node3.SetClassNameString("Action");
					node3.SetId(3);
#if !BEHAVIAC_RELEASE
					node3.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node3);
					node0.SetHasEvents(node0.HasEvents() | node3.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/sequence_ut_2

	class Action_bt_node_test_sequence_ut_2_node1 : behaviac.Action
	{
		public Action_bt_node_test_sequence_ut_2_node1()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Action_bt_node_test_sequence_ut_2_node2 : behaviac.Action
	{
		public Action_bt_node_test_sequence_ut_2_node2()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Action_bt_node_test_sequence_ut_2_node3 : behaviac.Action
	{
		public Action_bt_node_test_sequence_ut_2_node3()
		{
			method_p0 = 2;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_FAILURE;
		}
		int method_p0;
	}

	public static class bt_node_test_sequence_ut_2
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/sequence_ut_2");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Sequence node0 = new Sequence();
				node0.SetClassNameString("Sequence");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					Action_bt_node_test_sequence_ut_2_node1 node1 = new Action_bt_node_test_sequence_ut_2_node1();
					node1.SetClassNameString("Action");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					Action_bt_node_test_sequence_ut_2_node2 node2 = new Action_bt_node_test_sequence_ut_2_node2();
					node2.SetClassNameString("Action");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				{
					Action_bt_node_test_sequence_ut_2_node3 node3 = new Action_bt_node_test_sequence_ut_2_node3();
					node3.SetClassNameString("Action");
					node3.SetId(3);
#if !BEHAVIAC_RELEASE
					node3.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node3);
					node0.SetHasEvents(node0.HasEvents() | node3.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/sequence_ut_3

	class Action_bt_node_test_sequence_ut_3_node1 : behaviac.Action
	{
		public Action_bt_node_test_sequence_ut_3_node1()
		{
			method_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_FAILURE;
		}
		int method_p0;
	}

	class Action_bt_node_test_sequence_ut_3_node2 : behaviac.Action
	{
		public Action_bt_node_test_sequence_ut_3_node2()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Action_bt_node_test_sequence_ut_3_node3 : behaviac.Action
	{
		public Action_bt_node_test_sequence_ut_3_node3()
		{
			method_p0 = 2;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_FAILURE;
		}
		int method_p0;
	}

	public static class bt_node_test_sequence_ut_3
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/sequence_ut_3");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Sequence node0 = new Sequence();
				node0.SetClassNameString("Sequence");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					Action_bt_node_test_sequence_ut_3_node1 node1 = new Action_bt_node_test_sequence_ut_3_node1();
					node1.SetClassNameString("Action");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					Action_bt_node_test_sequence_ut_3_node2 node2 = new Action_bt_node_test_sequence_ut_3_node2();
					node2.SetClassNameString("Action");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				{
					Action_bt_node_test_sequence_ut_3_node3 node3 = new Action_bt_node_test_sequence_ut_3_node3();
					node3.SetClassNameString("Action");
					node3.SetId(3);
#if !BEHAVIAC_RELEASE
					node3.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node3);
					node0.SetHasEvents(node0.HasEvents() | node3.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/wait_ut_0

	class Action_bt_node_test_wait_ut_0_node1 : behaviac.Action
	{
		public Action_bt_node_test_wait_ut_0_node1()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Wait_bt_node_test_wait_ut_0_node2 : behaviac.Wait
	{
		public Wait_bt_node_test_wait_ut_0_node2()
		{
			m_ignoreTimeScale = false;
		}
		protected override float GetTime(Agent pAgent)
		{
			return 1000f;
		}
	}

	public static class bt_node_test_wait_ut_0
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/wait_ut_0");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Sequence node0 = new Sequence();
				node0.SetClassNameString("Sequence");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					Action_bt_node_test_wait_ut_0_node1 node1 = new Action_bt_node_test_wait_ut_0_node1();
					node1.SetClassNameString("Action");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					Wait_bt_node_test_wait_ut_0_node2 node2 = new Wait_bt_node_test_wait_ut_0_node2();
					node2.SetClassNameString("Wait");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: node_test/wait_ut_1

	class Action_bt_node_test_wait_ut_1_node1 : behaviac.Action
	{
		public Action_bt_node_test_wait_ut_1_node1()
		{
			method_p0 = 1;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((AgentNodeTest)pAgent).setTestVar_0(method_p0);
			return EBTStatus.BT_SUCCESS;
		}
		int method_p0;
	}

	class Wait_bt_node_test_wait_ut_1_node2 : behaviac.Wait
	{
		public Wait_bt_node_test_wait_ut_1_node2()
		{
			m_ignoreTimeScale = true;
		}
		protected override float GetTime(Agent pAgent)
		{
			return 1000f;
		}
	}

	public static class bt_node_test_wait_ut_1
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("node_test/wait_ut_1");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("AgentNodeTest");
#endif
			// children
			{
				Sequence node0 = new Sequence();
				node0.SetClassNameString("Sequence");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("AgentNodeTest");
#endif
				bt.AddChild(node0);
				{
					Action_bt_node_test_wait_ut_1_node1 node1 = new Action_bt_node_test_wait_ut_1_node1();
					node1.SetClassNameString("Action");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node1);
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					Wait_bt_node_test_wait_ut_1_node2 node2 = new Wait_bt_node_test_wait_ut_1_node2();
					node2.SetClassNameString("Wait");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("AgentNodeTest");
#endif
					node0.AddChild(node2);
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: par_test/custom_property_as_left_value_and_param

	class Assignment_bt_par_test_custom_property_as_left_value_and_param_node11 : behaviac.Assignment
	{
		public Assignment_bt_par_test_custom_property_as_left_value_and_param_node11()
		{
			opr.x = 1f;
			opr.y = 1f;
			opr.z = 1f;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			AgentExtra_Generated.SetProperty(pAgent, "Location", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("Location") == 2906627922u);
			pAgent.SetVariable<UnityEngine.Vector3>("Location", opr, 2906627922u);
			return result;
		}
		UnityEngine.Vector3 opr;
	}

	class Assignment_bt_par_test_custom_property_as_left_value_and_param_node8 : behaviac.Assignment
	{
		public Assignment_bt_par_test_custom_property_as_left_value_and_param_node8()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			UnityEngine.Vector3 opr = ((CustomPropertyAgent)pAgent).Location;
			Debug.Check(behaviac.Utils.MakeVariableId("l_Location") == 3698229766u);
			pAgent.SetVariable<UnityEngine.Vector3>("l_Location", opr, 3698229766u);
			return result;
		}
	}

	class Assignment_bt_par_test_custom_property_as_left_value_and_param_node10 : behaviac.Assignment
	{
		public Assignment_bt_par_test_custom_property_as_left_value_and_param_node10()
		{
			opr.x = 2f;
			opr.y = 2f;
			opr.z = 2f;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			AgentExtra_Generated.SetProperty(pAgent, "Location", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("Location") == 2906627922u);
			pAgent.SetVariable<UnityEngine.Vector3>("Location", opr, 2906627922u);
			return result;
		}
		UnityEngine.Vector3 opr;
	}

	class DecoratorLoop_bt_par_test_custom_property_as_left_value_and_param_node6 : behaviac.DecoratorLoop
	{
		public DecoratorLoop_bt_par_test_custom_property_as_left_value_and_param_node6()
		{
			m_bDecorateWhenChildEnds = true;
		}
		protected override int GetCount(Agent pAgent)
		{
			return -1;
		}
	}

	public static class bt_par_test_custom_property_as_left_value_and_param
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("par_test/custom_property_as_left_value_and_param");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("CustomPropertyAgent");
#endif
			// pars
			bt.AddPar("int", "l_Int", "1", "");
			bt.AddPar("UnityEngine.Vector3", "l_Location", "{x=0;y=0;z=0;}", "");
			// children
			{
				Sequence node5 = new Sequence();
				node5.SetClassNameString("Sequence");
				node5.SetId(5);
#if !BEHAVIAC_RELEASE
				node5.SetAgentType("CustomPropertyAgent");
#endif
				bt.AddChild(node5);
				{
					Sequence node13 = new Sequence();
					node13.SetClassNameString("Sequence");
					node13.SetId(13);
#if !BEHAVIAC_RELEASE
					node13.SetAgentType("CustomPropertyAgent");
#endif
					node5.AddChild(node13);
					{
						Assignment_bt_par_test_custom_property_as_left_value_and_param_node11 node11 = new Assignment_bt_par_test_custom_property_as_left_value_and_param_node11();
						node11.SetClassNameString("Assignment");
						node11.SetId(11);
#if !BEHAVIAC_RELEASE
						node11.SetAgentType("CustomPropertyAgent");
#endif
						node13.AddChild(node11);
						node13.SetHasEvents(node13.HasEvents() | node11.HasEvents());
					}
					{
						Assignment_bt_par_test_custom_property_as_left_value_and_param_node8 node8 = new Assignment_bt_par_test_custom_property_as_left_value_and_param_node8();
						node8.SetClassNameString("Assignment");
						node8.SetId(8);
#if !BEHAVIAC_RELEASE
						node8.SetAgentType("CustomPropertyAgent");
#endif
						node13.AddChild(node8);
						node13.SetHasEvents(node13.HasEvents() | node8.HasEvents());
					}
					{
						Assignment_bt_par_test_custom_property_as_left_value_and_param_node10 node10 = new Assignment_bt_par_test_custom_property_as_left_value_and_param_node10();
						node10.SetClassNameString("Assignment");
						node10.SetId(10);
#if !BEHAVIAC_RELEASE
						node10.SetAgentType("CustomPropertyAgent");
#endif
						node13.AddChild(node10);
						node13.SetHasEvents(node13.HasEvents() | node10.HasEvents());
					}
					node5.SetHasEvents(node5.HasEvents() | node13.HasEvents());
				}
				{
					DecoratorLoop_bt_par_test_custom_property_as_left_value_and_param_node6 node6 = new DecoratorLoop_bt_par_test_custom_property_as_left_value_and_param_node6();
					node6.SetClassNameString("DecoratorLoop");
					node6.SetId(6);
#if !BEHAVIAC_RELEASE
					node6.SetAgentType("CustomPropertyAgent");
#endif
					node5.AddChild(node6);
					{
						Noop node7 = new Noop();
						node7.SetClassNameString("Noop");
						node7.SetId(7);
#if !BEHAVIAC_RELEASE
						node7.SetAgentType("CustomPropertyAgent");
#endif
						node6.AddChild(node7);
						node6.SetHasEvents(node6.HasEvents() | node7.HasEvents());
					}
					node5.SetHasEvents(node5.HasEvents() | node6.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node5.HasEvents());
			}
			return true;
		}
	}

	// Source file: par_test/par_as_left_value_and_param

	class Assignment_bt_par_test_par_as_left_value_and_param_node0 : behaviac.Assignment
	{
		public Assignment_bt_par_test_par_as_left_value_and_param_node0()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par2_agent_0") == 3876418331u);
			behaviac.Agent opr_p0 = pAgent.GetVariable<behaviac.Agent>(3876418331u);
			behaviac.Agent opr = (behaviac.Agent)((EmployeeParTestAgent)pAgent).Func_AgentIR(opr_p0);
			Debug.Check(behaviac.Utils.MakeVariableId("par2_agent_0") == 3876418331u);
			pAgent.SetVariable<behaviac.Agent>("par2_agent_0", opr, 3876418331u);
			return result;
		}
	}

	class Assignment_bt_par_test_par_as_left_value_and_param_node30 : behaviac.Assignment
	{
		public Assignment_bt_par_test_par_as_left_value_and_param_node30()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par2_ParTestAgentBase_0") == 2489994139u);
			ParTestAgentBase opr_p0 = pAgent.GetVariable<ParTestAgentBase>(2489994139u);
			ParTestAgentBase opr = (ParTestAgentBase)((EmployeeParTestAgent)pAgent).Func_ParTestAgentBaseIR(opr_p0);
			Debug.Check(behaviac.Utils.MakeVariableId("par2_ParTestAgentBase_0") == 2489994139u);
			pAgent.SetVariable<ParTestAgentBase>("par2_ParTestAgentBase_0", opr, 2489994139u);
			return result;
		}
	}

	class Assignment_bt_par_test_par_as_left_value_and_param_node15 : behaviac.Assignment
	{
		public Assignment_bt_par_test_par_as_left_value_and_param_node15()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par2_agent_list_0") == 1126732011u);
			List<behaviac.Agent> opr_p0 = pAgent.GetVariable<List<behaviac.Agent>>(1126732011u);
			List<behaviac.Agent> opr = (List<behaviac.Agent>)((EmployeeParTestAgent)pAgent).Func_AgentListIR(opr_p0);
			Debug.Check(behaviac.Utils.MakeVariableId("par2_agent_list_0") == 1126732011u);
			pAgent.SetVariable<List<behaviac.Agent>>("par2_agent_list_0", opr, 1126732011u);
			return result;
		}
	}

	class Assignment_bt_par_test_par_as_left_value_and_param_node31 : behaviac.Assignment
	{
		public Assignment_bt_par_test_par_as_left_value_and_param_node31()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par2_ParTestAgentBaseList_0") == 3110436684u);
			List<ParTestAgentBase> opr_p0 = pAgent.GetVariable<List<ParTestAgentBase>>(3110436684u);
			List<ParTestAgentBase> opr = (List<ParTestAgentBase>)((EmployeeParTestAgent)pAgent).Func_ParTestAgentBaseListIR(opr_p0);
			Debug.Check(behaviac.Utils.MakeVariableId("par2_ParTestAgentBaseList_0") == 3110436684u);
			pAgent.SetVariable<List<ParTestAgentBase>>("par2_ParTestAgentBaseList_0", opr, 3110436684u);
			return result;
		}
	}

	class Assignment_bt_par_test_par_as_left_value_and_param_node2 : behaviac.Assignment
	{
		public Assignment_bt_par_test_par_as_left_value_and_param_node2()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par2_double_0") == 2183367433u);
			double opr_p0 = pAgent.GetVariable<double>(2183367433u);
			double opr = (double)((EmployeeParTestAgent)pAgent).Func_DoubleIR(opr_p0);
			Debug.Check(behaviac.Utils.MakeVariableId("par2_double_0") == 2183367433u);
			pAgent.SetVariable<double>("par2_double_0", opr, 2183367433u);
			return result;
		}
	}

	class Assignment_bt_par_test_par_as_left_value_and_param_node3 : behaviac.Assignment
	{
		public Assignment_bt_par_test_par_as_left_value_and_param_node3()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par2_single_0") == 3120166065u);
			float opr_p0 = pAgent.GetVariable<float>(3120166065u);
			float opr = (float)((EmployeeParTestAgent)pAgent).Func_SingleIR(opr_p0);
			Debug.Check(behaviac.Utils.MakeVariableId("par2_single_0") == 3120166065u);
			pAgent.SetVariable<float>("par2_single_0", opr, 3120166065u);
			return result;
		}
	}

	class Assignment_bt_par_test_par_as_left_value_and_param_node4 : behaviac.Assignment
	{
		public Assignment_bt_par_test_par_as_left_value_and_param_node4()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par2_single_list_0") == 3448877207u);
			List<float> opr_p0 = pAgent.GetVariable<List<float>>(3448877207u);
			List<float> opr = (List<float>)((EmployeeParTestAgent)pAgent).Func_SingleListIR(opr_p0);
			Debug.Check(behaviac.Utils.MakeVariableId("par2_single_list_0") == 3448877207u);
			pAgent.SetVariable<List<float>>("par2_single_list_0", opr, 3448877207u);
			return result;
		}
	}

	class Assignment_bt_par_test_par_as_left_value_and_param_node5 : behaviac.Assignment
	{
		public Assignment_bt_par_test_par_as_left_value_and_param_node5()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par2_string_0") == 351984746u);
			string opr_p0 = pAgent.GetVariable<string>(351984746u);
			string opr = (string)((EmployeeParTestAgent)pAgent).Func_StringIR(opr_p0);
			Debug.Check(behaviac.Utils.MakeVariableId("par2_string_0") == 351984746u);
			pAgent.SetVariable<string>("par2_string_0", opr, 351984746u);
			return result;
		}
	}

	class Assignment_bt_par_test_par_as_left_value_and_param_node6 : behaviac.Assignment
	{
		public Assignment_bt_par_test_par_as_left_value_and_param_node6()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par2_string_list_0") == 1339885043u);
			List<string> opr_p0 = pAgent.GetVariable<List<string>>(1339885043u);
			List<string> opr = (List<string>)((EmployeeParTestAgent)pAgent).Func_StringListIR(opr_p0);
			Debug.Check(behaviac.Utils.MakeVariableId("par2_string_list_0") == 1339885043u);
			pAgent.SetVariable<List<string>>("par2_string_list_0", opr, 1339885043u);
			return result;
		}
	}

	class Assignment_bt_par_test_par_as_left_value_and_param_node7 : behaviac.Assignment
	{
		public Assignment_bt_par_test_par_as_left_value_and_param_node7()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par2_uint32_0") == 2738393615u);
			uint opr_p0 = pAgent.GetVariable<uint>(2738393615u);
			uint opr = (uint)((EmployeeParTestAgent)pAgent).Func_UInt32IR(opr_p0);
			Debug.Check(behaviac.Utils.MakeVariableId("par2_uint32_0") == 2738393615u);
			pAgent.SetVariable<uint>("par2_uint32_0", opr, 2738393615u);
			return result;
		}
	}

	class Assignment_bt_par_test_par_as_left_value_and_param_node8 : behaviac.Assignment
	{
		public Assignment_bt_par_test_par_as_left_value_and_param_node8()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par2_uint64_0") == 1320370851u);
			ulong opr_p0 = pAgent.GetVariable<ulong>(1320370851u);
			ulong opr = (ulong)((EmployeeParTestAgent)pAgent).Func_UInt64IR(opr_p0);
			Debug.Check(behaviac.Utils.MakeVariableId("par2_uint64_0") == 1320370851u);
			pAgent.SetVariable<ulong>("par2_uint64_0", opr, 1320370851u);
			return result;
		}
	}

	class Assignment_bt_par_test_par_as_left_value_and_param_node9 : behaviac.Assignment
	{
		public Assignment_bt_par_test_par_as_left_value_and_param_node9()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par1_int16_0") == 160665580u);
			short opr_p0 = pAgent.GetVariable<short>(160665580u);
			short opr = (short)((ParTestAgent)pAgent).Func_Int16IR(opr_p0);
			Debug.Check(behaviac.Utils.MakeVariableId("par1_int16_0") == 160665580u);
			pAgent.SetVariable<short>("par1_int16_0", opr, 160665580u);
			return result;
		}
	}

	class Assignment_bt_par_test_par_as_left_value_and_param_node10 : behaviac.Assignment
	{
		public Assignment_bt_par_test_par_as_left_value_and_param_node10()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par1_int32_0") == 4231089115u);
			int opr_p0 = pAgent.GetVariable<int>(4231089115u);
			int opr = (int)((ParTestAgent)pAgent).Func_Int32IR(opr_p0);
			Debug.Check(behaviac.Utils.MakeVariableId("par1_int32_0") == 4231089115u);
			pAgent.SetVariable<int>("par1_int32_0", opr, 4231089115u);
			return result;
		}
	}

	class Assignment_bt_par_test_par_as_left_value_and_param_node11 : behaviac.Assignment
	{
		public Assignment_bt_par_test_par_as_left_value_and_param_node11()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par1_int32_list_0") == 468025104u);
			List<int> opr_p0 = pAgent.GetVariable<List<int>>(468025104u);
			List<int> opr = (List<int>)((ParTestAgent)pAgent).Func_Int32ListIR(opr_p0);
			Debug.Check(behaviac.Utils.MakeVariableId("par1_int32_list_0") == 468025104u);
			pAgent.SetVariable<List<int>>("par1_int32_list_0", opr, 468025104u);
			return result;
		}
	}

	class Assignment_bt_par_test_par_as_left_value_and_param_node12 : behaviac.Assignment
	{
		public Assignment_bt_par_test_par_as_left_value_and_param_node12()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par1_int64_0") == 297442167u);
			long opr_p0 = pAgent.GetVariable<long>(297442167u);
			long opr = (long)((ParTestAgent)pAgent).Func_Int64IR(opr_p0);
			Debug.Check(behaviac.Utils.MakeVariableId("par1_int64_0") == 297442167u);
			pAgent.SetVariable<long>("par1_int64_0", opr, 297442167u);
			return result;
		}
	}

	class Assignment_bt_par_test_par_as_left_value_and_param_node17 : behaviac.Assignment
	{
		public Assignment_bt_par_test_par_as_left_value_and_param_node17()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par1_kemployee_0") == 4045482770u);
			TNS.ST.PER.WRK.kEmployee opr_p0 = pAgent.GetVariable<TNS.ST.PER.WRK.kEmployee>(4045482770u);
			TNS.ST.PER.WRK.kEmployee opr = (TNS.ST.PER.WRK.kEmployee)((ParTestAgent)pAgent).Func_kEmployeeIR(opr_p0);
			Debug.Check(behaviac.Utils.MakeVariableId("par1_kemployee_0") == 4045482770u);
			pAgent.SetVariable<TNS.ST.PER.WRK.kEmployee>("par1_kemployee_0", opr, 4045482770u);
			return result;
		}
	}

	class Assignment_bt_par_test_par_as_left_value_and_param_node19 : behaviac.Assignment
	{
		public Assignment_bt_par_test_par_as_left_value_and_param_node19()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par1_kemployee_list_0") == 506976637u);
			List<TNS.ST.PER.WRK.kEmployee> opr_p0 = pAgent.GetVariable<List<TNS.ST.PER.WRK.kEmployee>>(506976637u);
			List<TNS.ST.PER.WRK.kEmployee> opr = (List<TNS.ST.PER.WRK.kEmployee>)((ParTestAgent)pAgent).Func_kEmployeeListIR(opr_p0);
			Debug.Check(behaviac.Utils.MakeVariableId("par1_kemployee_list_0") == 506976637u);
			pAgent.SetVariable<List<TNS.ST.PER.WRK.kEmployee>>("par1_kemployee_list_0", opr, 506976637u);
			return result;
		}
	}

	class Assignment_bt_par_test_par_as_left_value_and_param_node18 : behaviac.Assignment
	{
		public Assignment_bt_par_test_par_as_left_value_and_param_node18()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par1_uint16_0") == 3480760377u);
			ushort opr_p0 = pAgent.GetVariable<ushort>(3480760377u);
			ushort opr = (ushort)((ParTestAgent)pAgent).Func_UInt16IR(opr_p0);
			Debug.Check(behaviac.Utils.MakeVariableId("par1_uint16_0") == 3480760377u);
			pAgent.SetVariable<ushort>("par1_uint16_0", opr, 3480760377u);
			return result;
		}
	}

	class Assignment_bt_par_test_par_as_left_value_and_param_node16 : behaviac.Assignment
	{
		public Assignment_bt_par_test_par_as_left_value_and_param_node16()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par0_boolean_0") == 1912381985u);
			bool opr_p0 = pAgent.GetVariable<bool>(1912381985u);
			bool opr = (bool)((ParTestAgentBase)pAgent).Func_BooleanIR(opr_p0);
			Debug.Check(behaviac.Utils.MakeVariableId("par0_boolean_0") == 1912381985u);
			pAgent.SetVariable<bool>("par0_boolean_0", opr, 1912381985u);
			return result;
		}
	}

	class Assignment_bt_par_test_par_as_left_value_and_param_node20 : behaviac.Assignment
	{
		public Assignment_bt_par_test_par_as_left_value_and_param_node20()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par0_boolean_list_0") == 109714028u);
			List<bool> opr_p0 = pAgent.GetVariable<List<bool>>(109714028u);
			List<bool> opr = (List<bool>)((ParTestAgentBase)pAgent).Func_BooleanListIR(opr_p0);
			Debug.Check(behaviac.Utils.MakeVariableId("par0_boolean_list_0") == 109714028u);
			pAgent.SetVariable<List<bool>>("par0_boolean_list_0", opr, 109714028u);
			return result;
		}
	}

	class Assignment_bt_par_test_par_as_left_value_and_param_node24 : behaviac.Assignment
	{
		public Assignment_bt_par_test_par_as_left_value_and_param_node24()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par0_byte_0") == 2120958860u);
			byte opr_p0 = pAgent.GetVariable<byte>(2120958860u);
			byte opr = (byte)((ParTestAgentBase)pAgent).Func_ByteIR(opr_p0);
			Debug.Check(behaviac.Utils.MakeVariableId("par0_byte_0") == 2120958860u);
			pAgent.SetVariable<byte>("par0_byte_0", opr, 2120958860u);
			return result;
		}
	}

	class Assignment_bt_par_test_par_as_left_value_and_param_node25 : behaviac.Assignment
	{
		public Assignment_bt_par_test_par_as_left_value_and_param_node25()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par0_byte_list_0") == 1459492261u);
			List<byte> opr_p0 = pAgent.GetVariable<List<byte>>(1459492261u);
			List<byte> opr = (List<byte>)((ParTestAgentBase)pAgent).Func_ByteListIR(opr_p0);
			Debug.Check(behaviac.Utils.MakeVariableId("par0_byte_list_0") == 1459492261u);
			pAgent.SetVariable<List<byte>>("par0_byte_list_0", opr, 1459492261u);
			return result;
		}
	}

	class Assignment_bt_par_test_par_as_left_value_and_param_node26 : behaviac.Assignment
	{
		public Assignment_bt_par_test_par_as_left_value_and_param_node26()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par0_char_0") == 1968762578u);
			char opr_p0 = pAgent.GetVariable<char>(1968762578u);
			char opr = (char)((ParTestAgentBase)pAgent).Func_CharIR(opr_p0);
			Debug.Check(behaviac.Utils.MakeVariableId("par0_char_0") == 1968762578u);
			pAgent.SetVariable<char>("par0_char_0", opr, 1968762578u);
			return result;
		}
	}

	class Assignment_bt_par_test_par_as_left_value_and_param_node27 : behaviac.Assignment
	{
		public Assignment_bt_par_test_par_as_left_value_and_param_node27()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par0_char_list_0") == 2869241813u);
			List<char> opr_p0 = pAgent.GetVariable<List<char>>(2869241813u);
			List<char> opr = (List<char>)((ParTestAgentBase)pAgent).Func_CharListIR(opr_p0);
			Debug.Check(behaviac.Utils.MakeVariableId("par0_char_list_0") == 2869241813u);
			pAgent.SetVariable<List<char>>("par0_char_list_0", opr, 2869241813u);
			return result;
		}
	}

	class Assignment_bt_par_test_par_as_left_value_and_param_node21 : behaviac.Assignment
	{
		public Assignment_bt_par_test_par_as_left_value_and_param_node21()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par0_ecolor_0") == 3914433730u);
			TNS.NE.NAT.eColor opr_p0 = pAgent.GetVariable<TNS.NE.NAT.eColor>(3914433730u);
			TNS.NE.NAT.eColor opr = (TNS.NE.NAT.eColor)((ParTestAgentBase)pAgent).Func_eColorIR(opr_p0);
			Debug.Check(behaviac.Utils.MakeVariableId("par0_ecolor_0") == 3914433730u);
			pAgent.SetVariable<TNS.NE.NAT.eColor>("par0_ecolor_0", opr, 3914433730u);
			return result;
		}
	}

	class Assignment_bt_par_test_par_as_left_value_and_param_node23 : behaviac.Assignment
	{
		public Assignment_bt_par_test_par_as_left_value_and_param_node23()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par0_ecolor_list_0") == 1963776920u);
			List<TNS.NE.NAT.eColor> opr_p0 = pAgent.GetVariable<List<TNS.NE.NAT.eColor>>(1963776920u);
			List<TNS.NE.NAT.eColor> opr = (List<TNS.NE.NAT.eColor>)((ParTestAgentBase)pAgent).Func_eColorListIR(opr_p0);
			Debug.Check(behaviac.Utils.MakeVariableId("par0_ecolor_list_0") == 1963776920u);
			pAgent.SetVariable<List<TNS.NE.NAT.eColor>>("par0_ecolor_list_0", opr, 1963776920u);
			return result;
		}
	}

	class Assignment_bt_par_test_par_as_left_value_and_param_node28 : behaviac.Assignment
	{
		public Assignment_bt_par_test_par_as_left_value_and_param_node28()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par0_sbyte_0") == 968869870u);
			sbyte opr_p0 = pAgent.GetVariable<sbyte>(968869870u);
			sbyte opr = (sbyte)((ParTestAgentBase)pAgent).Func_SByteIR(opr_p0);
			Debug.Check(behaviac.Utils.MakeVariableId("par0_sbyte_0") == 968869870u);
			pAgent.SetVariable<sbyte>("par0_sbyte_0", opr, 968869870u);
			return result;
		}
	}

	class Assignment_bt_par_test_par_as_left_value_and_param_node29 : behaviac.Assignment
	{
		public Assignment_bt_par_test_par_as_left_value_and_param_node29()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par0_sbyte_list_0") == 2290963684u);
			List<sbyte> opr_p0 = pAgent.GetVariable<List<sbyte>>(2290963684u);
			List<sbyte> opr = (List<sbyte>)((ParTestAgentBase)pAgent).Func_SByteListIR(opr_p0);
			Debug.Check(behaviac.Utils.MakeVariableId("par0_sbyte_list_0") == 2290963684u);
			pAgent.SetVariable<List<sbyte>>("par0_sbyte_list_0", opr, 2290963684u);
			return result;
		}
	}

	public static class bt_par_test_par_as_left_value_and_param
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("par_test/par_as_left_value_and_param");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("EmployeeParTestAgent");
#endif
			// pars
			bt.AddPar("double", "par2_double_0", "5.7", "");
			bt.AddPar("float", "par2_single_0", "98.2", "");
			bt.AddPar("vector<float>", "par2_single_list_0", "2:5.1|6.2", "");
			bt.AddPar("string", "par2_string_0", "origin", "");
			bt.AddPar("vector<string>", "par2_string_list_0", "4:\"string0\"|\"string1\"|\"string2\"|\"string3\"", "");
			bt.AddPar("uint", "par2_uint32_0", "9", "");
			bt.AddPar("ulong", "par2_uint64_0", "300", "");
			bt.AddPar("short", "par1_int16_0", "78", "");
			bt.AddPar("int", "par1_int32_0", "-3", "");
			bt.AddPar("vector<int>", "par1_int32_list_0", "3:9999|12345|0", "");
			bt.AddPar("long", "par1_int64_0", "1500", "");
			bt.AddPar("vector<TNS.ST.PER.WRK.kEmployee>", "par1_kemployee_list_0", "1:{boss=null;car={brand=\"Lexus\";color=BLUE;price=93840;};code=q;id=9;isMale=true;name=\"John\";skinColor=GREEN;weight=110;}", "");
			bt.AddPar("ushort", "par1_uint16_0", "2001", "");
			bt.AddPar("bool", "par0_boolean_0", "true", "");
			bt.AddPar("vector<bool>", "par0_boolean_list_0", "2:false|true", "");
			bt.AddPar("TNS.NE.NAT.eColor", "par0_ecolor_0", "YELLOW", "");
			bt.AddPar("vector<TNS.NE.NAT.eColor>", "par0_ecolor_list_0", "2:RED|GREEN", "");
			bt.AddPar("behaviac.Agent", "par2_agent_0", "null", "");
			bt.AddPar("vector<behaviac.Agent>", "par2_agent_list_0", "2:null|null", "");
			bt.AddPar("char", "par0_char_0", "A", "");
			bt.AddPar("TNS.ST.PER.WRK.kEmployee", "par1_kemployee_0", "{boss=null;car={brand=\"Alpha\";color=WHITE;price=5700;};code=A;id=83;isMale=false;name=\"Tom\";skinColor=RED;weight=97.3;}", "");
			bt.AddPar("byte", "par0_byte_0", "197", "");
			bt.AddPar("sbyte", "par0_sbyte_0", "-60", "");
			bt.AddPar("vector<char>", "par0_char_list_0", "4:d|j|F|A", "");
			bt.AddPar("vector<sbyte>", "par0_sbyte_list_0", "3:127|-128|0", "");
			bt.AddPar("vector<byte>", "par0_byte_list_0", "3:167|23|152", "");
			bt.AddPar("ParTestAgentBase", "par2_ParTestAgentBase_0", "null", "");
			bt.AddPar("vector<ParTestAgentBase>", "par2_ParTestAgentBaseList_0", "2:null|null", "");
			// children
			{
				Sequence node13 = new Sequence();
				node13.SetClassNameString("Sequence");
				node13.SetId(13);
#if !BEHAVIAC_RELEASE
				node13.SetAgentType("EmployeeParTestAgent");
#endif
				bt.AddChild(node13);
				{
					Sequence node1 = new Sequence();
					node1.SetClassNameString("Sequence");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("EmployeeParTestAgent");
#endif
					node13.AddChild(node1);
					{
						Assignment_bt_par_test_par_as_left_value_and_param_node0 node0 = new Assignment_bt_par_test_par_as_left_value_and_param_node0();
						node0.SetClassNameString("Assignment");
						node0.SetId(0);
#if !BEHAVIAC_RELEASE
						node0.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node0);
						node1.SetHasEvents(node1.HasEvents() | node0.HasEvents());
					}
					{
						Assignment_bt_par_test_par_as_left_value_and_param_node30 node30 = new Assignment_bt_par_test_par_as_left_value_and_param_node30();
						node30.SetClassNameString("Assignment");
						node30.SetId(30);
#if !BEHAVIAC_RELEASE
						node30.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node30);
						node1.SetHasEvents(node1.HasEvents() | node30.HasEvents());
					}
					{
						Assignment_bt_par_test_par_as_left_value_and_param_node15 node15 = new Assignment_bt_par_test_par_as_left_value_and_param_node15();
						node15.SetClassNameString("Assignment");
						node15.SetId(15);
#if !BEHAVIAC_RELEASE
						node15.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node15);
						node1.SetHasEvents(node1.HasEvents() | node15.HasEvents());
					}
					{
						Assignment_bt_par_test_par_as_left_value_and_param_node31 node31 = new Assignment_bt_par_test_par_as_left_value_and_param_node31();
						node31.SetClassNameString("Assignment");
						node31.SetId(31);
#if !BEHAVIAC_RELEASE
						node31.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node31);
						node1.SetHasEvents(node1.HasEvents() | node31.HasEvents());
					}
					{
						Assignment_bt_par_test_par_as_left_value_and_param_node2 node2 = new Assignment_bt_par_test_par_as_left_value_and_param_node2();
						node2.SetClassNameString("Assignment");
						node2.SetId(2);
#if !BEHAVIAC_RELEASE
						node2.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node2);
						node1.SetHasEvents(node1.HasEvents() | node2.HasEvents());
					}
					{
						Assignment_bt_par_test_par_as_left_value_and_param_node3 node3 = new Assignment_bt_par_test_par_as_left_value_and_param_node3();
						node3.SetClassNameString("Assignment");
						node3.SetId(3);
#if !BEHAVIAC_RELEASE
						node3.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node3);
						node1.SetHasEvents(node1.HasEvents() | node3.HasEvents());
					}
					{
						Assignment_bt_par_test_par_as_left_value_and_param_node4 node4 = new Assignment_bt_par_test_par_as_left_value_and_param_node4();
						node4.SetClassNameString("Assignment");
						node4.SetId(4);
#if !BEHAVIAC_RELEASE
						node4.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node4);
						node1.SetHasEvents(node1.HasEvents() | node4.HasEvents());
					}
					{
						Assignment_bt_par_test_par_as_left_value_and_param_node5 node5 = new Assignment_bt_par_test_par_as_left_value_and_param_node5();
						node5.SetClassNameString("Assignment");
						node5.SetId(5);
#if !BEHAVIAC_RELEASE
						node5.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node5);
						node1.SetHasEvents(node1.HasEvents() | node5.HasEvents());
					}
					{
						Assignment_bt_par_test_par_as_left_value_and_param_node6 node6 = new Assignment_bt_par_test_par_as_left_value_and_param_node6();
						node6.SetClassNameString("Assignment");
						node6.SetId(6);
#if !BEHAVIAC_RELEASE
						node6.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node6);
						node1.SetHasEvents(node1.HasEvents() | node6.HasEvents());
					}
					{
						Assignment_bt_par_test_par_as_left_value_and_param_node7 node7 = new Assignment_bt_par_test_par_as_left_value_and_param_node7();
						node7.SetClassNameString("Assignment");
						node7.SetId(7);
#if !BEHAVIAC_RELEASE
						node7.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node7);
						node1.SetHasEvents(node1.HasEvents() | node7.HasEvents());
					}
					{
						Assignment_bt_par_test_par_as_left_value_and_param_node8 node8 = new Assignment_bt_par_test_par_as_left_value_and_param_node8();
						node8.SetClassNameString("Assignment");
						node8.SetId(8);
#if !BEHAVIAC_RELEASE
						node8.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node8);
						node1.SetHasEvents(node1.HasEvents() | node8.HasEvents());
					}
					node13.SetHasEvents(node13.HasEvents() | node1.HasEvents());
				}
				{
					Sequence node14 = new Sequence();
					node14.SetClassNameString("Sequence");
					node14.SetId(14);
#if !BEHAVIAC_RELEASE
					node14.SetAgentType("EmployeeParTestAgent");
#endif
					node13.AddChild(node14);
					{
						Assignment_bt_par_test_par_as_left_value_and_param_node9 node9 = new Assignment_bt_par_test_par_as_left_value_and_param_node9();
						node9.SetClassNameString("Assignment");
						node9.SetId(9);
#if !BEHAVIAC_RELEASE
						node9.SetAgentType("EmployeeParTestAgent");
#endif
						node14.AddChild(node9);
						node14.SetHasEvents(node14.HasEvents() | node9.HasEvents());
					}
					{
						Assignment_bt_par_test_par_as_left_value_and_param_node10 node10 = new Assignment_bt_par_test_par_as_left_value_and_param_node10();
						node10.SetClassNameString("Assignment");
						node10.SetId(10);
#if !BEHAVIAC_RELEASE
						node10.SetAgentType("EmployeeParTestAgent");
#endif
						node14.AddChild(node10);
						node14.SetHasEvents(node14.HasEvents() | node10.HasEvents());
					}
					{
						Assignment_bt_par_test_par_as_left_value_and_param_node11 node11 = new Assignment_bt_par_test_par_as_left_value_and_param_node11();
						node11.SetClassNameString("Assignment");
						node11.SetId(11);
#if !BEHAVIAC_RELEASE
						node11.SetAgentType("EmployeeParTestAgent");
#endif
						node14.AddChild(node11);
						node14.SetHasEvents(node14.HasEvents() | node11.HasEvents());
					}
					{
						Assignment_bt_par_test_par_as_left_value_and_param_node12 node12 = new Assignment_bt_par_test_par_as_left_value_and_param_node12();
						node12.SetClassNameString("Assignment");
						node12.SetId(12);
#if !BEHAVIAC_RELEASE
						node12.SetAgentType("EmployeeParTestAgent");
#endif
						node14.AddChild(node12);
						node14.SetHasEvents(node14.HasEvents() | node12.HasEvents());
					}
					{
						Assignment_bt_par_test_par_as_left_value_and_param_node17 node17 = new Assignment_bt_par_test_par_as_left_value_and_param_node17();
						node17.SetClassNameString("Assignment");
						node17.SetId(17);
#if !BEHAVIAC_RELEASE
						node17.SetAgentType("EmployeeParTestAgent");
#endif
						node14.AddChild(node17);
						node14.SetHasEvents(node14.HasEvents() | node17.HasEvents());
					}
					{
						Assignment_bt_par_test_par_as_left_value_and_param_node19 node19 = new Assignment_bt_par_test_par_as_left_value_and_param_node19();
						node19.SetClassNameString("Assignment");
						node19.SetId(19);
#if !BEHAVIAC_RELEASE
						node19.SetAgentType("EmployeeParTestAgent");
#endif
						node14.AddChild(node19);
						node14.SetHasEvents(node14.HasEvents() | node19.HasEvents());
					}
					{
						Assignment_bt_par_test_par_as_left_value_and_param_node18 node18 = new Assignment_bt_par_test_par_as_left_value_and_param_node18();
						node18.SetClassNameString("Assignment");
						node18.SetId(18);
#if !BEHAVIAC_RELEASE
						node18.SetAgentType("EmployeeParTestAgent");
#endif
						node14.AddChild(node18);
						node14.SetHasEvents(node14.HasEvents() | node18.HasEvents());
					}
					node13.SetHasEvents(node13.HasEvents() | node14.HasEvents());
				}
				{
					Sequence node22 = new Sequence();
					node22.SetClassNameString("Sequence");
					node22.SetId(22);
#if !BEHAVIAC_RELEASE
					node22.SetAgentType("EmployeeParTestAgent");
#endif
					node13.AddChild(node22);
					{
						Assignment_bt_par_test_par_as_left_value_and_param_node16 node16 = new Assignment_bt_par_test_par_as_left_value_and_param_node16();
						node16.SetClassNameString("Assignment");
						node16.SetId(16);
#if !BEHAVIAC_RELEASE
						node16.SetAgentType("EmployeeParTestAgent");
#endif
						node22.AddChild(node16);
						node22.SetHasEvents(node22.HasEvents() | node16.HasEvents());
					}
					{
						Assignment_bt_par_test_par_as_left_value_and_param_node20 node20 = new Assignment_bt_par_test_par_as_left_value_and_param_node20();
						node20.SetClassNameString("Assignment");
						node20.SetId(20);
#if !BEHAVIAC_RELEASE
						node20.SetAgentType("EmployeeParTestAgent");
#endif
						node22.AddChild(node20);
						node22.SetHasEvents(node22.HasEvents() | node20.HasEvents());
					}
					{
						Assignment_bt_par_test_par_as_left_value_and_param_node24 node24 = new Assignment_bt_par_test_par_as_left_value_and_param_node24();
						node24.SetClassNameString("Assignment");
						node24.SetId(24);
#if !BEHAVIAC_RELEASE
						node24.SetAgentType("EmployeeParTestAgent");
#endif
						node22.AddChild(node24);
						node22.SetHasEvents(node22.HasEvents() | node24.HasEvents());
					}
					{
						Assignment_bt_par_test_par_as_left_value_and_param_node25 node25 = new Assignment_bt_par_test_par_as_left_value_and_param_node25();
						node25.SetClassNameString("Assignment");
						node25.SetId(25);
#if !BEHAVIAC_RELEASE
						node25.SetAgentType("EmployeeParTestAgent");
#endif
						node22.AddChild(node25);
						node22.SetHasEvents(node22.HasEvents() | node25.HasEvents());
					}
					{
						Assignment_bt_par_test_par_as_left_value_and_param_node26 node26 = new Assignment_bt_par_test_par_as_left_value_and_param_node26();
						node26.SetClassNameString("Assignment");
						node26.SetId(26);
#if !BEHAVIAC_RELEASE
						node26.SetAgentType("EmployeeParTestAgent");
#endif
						node22.AddChild(node26);
						node22.SetHasEvents(node22.HasEvents() | node26.HasEvents());
					}
					{
						Assignment_bt_par_test_par_as_left_value_and_param_node27 node27 = new Assignment_bt_par_test_par_as_left_value_and_param_node27();
						node27.SetClassNameString("Assignment");
						node27.SetId(27);
#if !BEHAVIAC_RELEASE
						node27.SetAgentType("EmployeeParTestAgent");
#endif
						node22.AddChild(node27);
						node22.SetHasEvents(node22.HasEvents() | node27.HasEvents());
					}
					{
						Assignment_bt_par_test_par_as_left_value_and_param_node21 node21 = new Assignment_bt_par_test_par_as_left_value_and_param_node21();
						node21.SetClassNameString("Assignment");
						node21.SetId(21);
#if !BEHAVIAC_RELEASE
						node21.SetAgentType("EmployeeParTestAgent");
#endif
						node22.AddChild(node21);
						node22.SetHasEvents(node22.HasEvents() | node21.HasEvents());
					}
					{
						Assignment_bt_par_test_par_as_left_value_and_param_node23 node23 = new Assignment_bt_par_test_par_as_left_value_and_param_node23();
						node23.SetClassNameString("Assignment");
						node23.SetId(23);
#if !BEHAVIAC_RELEASE
						node23.SetAgentType("EmployeeParTestAgent");
#endif
						node22.AddChild(node23);
						node22.SetHasEvents(node22.HasEvents() | node23.HasEvents());
					}
					{
						Assignment_bt_par_test_par_as_left_value_and_param_node28 node28 = new Assignment_bt_par_test_par_as_left_value_and_param_node28();
						node28.SetClassNameString("Assignment");
						node28.SetId(28);
#if !BEHAVIAC_RELEASE
						node28.SetAgentType("EmployeeParTestAgent");
#endif
						node22.AddChild(node28);
						node22.SetHasEvents(node22.HasEvents() | node28.HasEvents());
					}
					{
						Assignment_bt_par_test_par_as_left_value_and_param_node29 node29 = new Assignment_bt_par_test_par_as_left_value_and_param_node29();
						node29.SetClassNameString("Assignment");
						node29.SetId(29);
#if !BEHAVIAC_RELEASE
						node29.SetAgentType("EmployeeParTestAgent");
#endif
						node22.AddChild(node29);
						node22.SetHasEvents(node22.HasEvents() | node29.HasEvents());
					}
					node13.SetHasEvents(node13.HasEvents() | node22.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node13.HasEvents());
			}
			return true;
		}
	}

	// Source file: par_test/par_as_ref_param

	class Action_bt_par_test_par_as_ref_param_node0 : behaviac.Action
	{
		public Action_bt_par_test_par_as_ref_param_node0()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			Debug.Check(behaviac.Utils.MakeVariableId("par2_agent_0") == 3876418331u);
			behaviac.Agent method_p0 = pAgent.GetVariable<behaviac.Agent>(3876418331u);
			((EmployeeParTestAgent)pAgent).Func_AgentRef(ref method_p0);
			Debug.Check(behaviac.Utils.MakeVariableId("par2_agent_0") == 3876418331u);
			pAgent.SetVariable<behaviac.Agent>("par2_agent_0", method_p0, 3876418331u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_par_as_ref_param_node17 : behaviac.Action
	{
		public Action_bt_par_test_par_as_ref_param_node17()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			Debug.Check(behaviac.Utils.MakeVariableId("par2_agent_list_0") == 1126732011u);
			List<behaviac.Agent> method_p0 = pAgent.GetVariable<List<behaviac.Agent>>(1126732011u);
			((EmployeeParTestAgent)pAgent).Func_AgentListRef(ref method_p0);
			Debug.Check(behaviac.Utils.MakeVariableId("par2_agent_list_0") == 1126732011u);
			pAgent.SetVariable<List<behaviac.Agent>>("par2_agent_list_0", method_p0, 1126732011u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_par_as_ref_param_node2 : behaviac.Action
	{
		public Action_bt_par_test_par_as_ref_param_node2()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			Debug.Check(behaviac.Utils.MakeVariableId("par2_double_0") == 2183367433u);
			double method_p0 = pAgent.GetVariable<double>(2183367433u);
			((EmployeeParTestAgent)pAgent).Func_DoubleRef(ref method_p0);
			Debug.Check(behaviac.Utils.MakeVariableId("par2_double_0") == 2183367433u);
			pAgent.SetVariable<double>("par2_double_0", method_p0, 2183367433u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_par_as_ref_param_node3 : behaviac.Action
	{
		public Action_bt_par_test_par_as_ref_param_node3()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			Debug.Check(behaviac.Utils.MakeVariableId("par2_single_0") == 3120166065u);
			float method_p0 = pAgent.GetVariable<float>(3120166065u);
			((EmployeeParTestAgent)pAgent).Func_SingleRef(ref method_p0);
			Debug.Check(behaviac.Utils.MakeVariableId("par2_single_0") == 3120166065u);
			pAgent.SetVariable<float>("par2_single_0", method_p0, 3120166065u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_par_as_ref_param_node4 : behaviac.Action
	{
		public Action_bt_par_test_par_as_ref_param_node4()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			Debug.Check(behaviac.Utils.MakeVariableId("par2_single_list_0") == 3448877207u);
			List<float> method_p0 = pAgent.GetVariable<List<float>>(3448877207u);
			((EmployeeParTestAgent)pAgent).Func_SingleListRef(ref method_p0);
			Debug.Check(behaviac.Utils.MakeVariableId("par2_single_list_0") == 3448877207u);
			pAgent.SetVariable<List<float>>("par2_single_list_0", method_p0, 3448877207u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_par_as_ref_param_node5 : behaviac.Action
	{
		public Action_bt_par_test_par_as_ref_param_node5()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			Debug.Check(behaviac.Utils.MakeVariableId("par2_string_0") == 351984746u);
			string method_p0 = pAgent.GetVariable<string>(351984746u);
			((EmployeeParTestAgent)pAgent).Func_StringRef(ref method_p0);
			Debug.Check(behaviac.Utils.MakeVariableId("par2_string_0") == 351984746u);
			pAgent.SetVariable<string>("par2_string_0", method_p0, 351984746u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_par_as_ref_param_node6 : behaviac.Action
	{
		public Action_bt_par_test_par_as_ref_param_node6()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			Debug.Check(behaviac.Utils.MakeVariableId("par2_string_list_0") == 1339885043u);
			List<string> method_p0 = pAgent.GetVariable<List<string>>(1339885043u);
			((EmployeeParTestAgent)pAgent).Func_StringListRef(ref method_p0);
			Debug.Check(behaviac.Utils.MakeVariableId("par2_string_list_0") == 1339885043u);
			pAgent.SetVariable<List<string>>("par2_string_list_0", method_p0, 1339885043u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_par_as_ref_param_node7 : behaviac.Action
	{
		public Action_bt_par_test_par_as_ref_param_node7()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			Debug.Check(behaviac.Utils.MakeVariableId("par2_uint32_0") == 2738393615u);
			uint method_p0 = pAgent.GetVariable<uint>(2738393615u);
			((EmployeeParTestAgent)pAgent).Func_UInt32Ref(ref method_p0);
			Debug.Check(behaviac.Utils.MakeVariableId("par2_uint32_0") == 2738393615u);
			pAgent.SetVariable<uint>("par2_uint32_0", method_p0, 2738393615u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_par_as_ref_param_node8 : behaviac.Action
	{
		public Action_bt_par_test_par_as_ref_param_node8()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			Debug.Check(behaviac.Utils.MakeVariableId("par2_uint64_0") == 1320370851u);
			ulong method_p0 = pAgent.GetVariable<ulong>(1320370851u);
			((EmployeeParTestAgent)pAgent).Func_UInt64Ref(ref method_p0);
			Debug.Check(behaviac.Utils.MakeVariableId("par2_uint64_0") == 1320370851u);
			pAgent.SetVariable<ulong>("par2_uint64_0", method_p0, 1320370851u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_par_as_ref_param_node9 : behaviac.Action
	{
		public Action_bt_par_test_par_as_ref_param_node9()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			Debug.Check(behaviac.Utils.MakeVariableId("par1_int16_0") == 160665580u);
			short method_p0 = pAgent.GetVariable<short>(160665580u);
			((ParTestAgent)pAgent).Func_Int16Ref(ref method_p0);
			Debug.Check(behaviac.Utils.MakeVariableId("par1_int16_0") == 160665580u);
			pAgent.SetVariable<short>("par1_int16_0", method_p0, 160665580u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_par_as_ref_param_node10 : behaviac.Action
	{
		public Action_bt_par_test_par_as_ref_param_node10()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			Debug.Check(behaviac.Utils.MakeVariableId("par1_int32_0") == 4231089115u);
			int method_p0 = pAgent.GetVariable<int>(4231089115u);
			((ParTestAgent)pAgent).Func_Int32Ref(ref method_p0);
			Debug.Check(behaviac.Utils.MakeVariableId("par1_int32_0") == 4231089115u);
			pAgent.SetVariable<int>("par1_int32_0", method_p0, 4231089115u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_par_as_ref_param_node11 : behaviac.Action
	{
		public Action_bt_par_test_par_as_ref_param_node11()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			Debug.Check(behaviac.Utils.MakeVariableId("par1_int32_list_0") == 468025104u);
			List<int> method_p0 = pAgent.GetVariable<List<int>>(468025104u);
			((ParTestAgent)pAgent).Func_Int32ListRef(ref method_p0);
			Debug.Check(behaviac.Utils.MakeVariableId("par1_int32_list_0") == 468025104u);
			pAgent.SetVariable<List<int>>("par1_int32_list_0", method_p0, 468025104u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_par_as_ref_param_node12 : behaviac.Action
	{
		public Action_bt_par_test_par_as_ref_param_node12()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			Debug.Check(behaviac.Utils.MakeVariableId("par1_int64_0") == 297442167u);
			long method_p0 = pAgent.GetVariable<long>(297442167u);
			((ParTestAgent)pAgent).Func_Int64Ref(ref method_p0);
			Debug.Check(behaviac.Utils.MakeVariableId("par1_int64_0") == 297442167u);
			pAgent.SetVariable<long>("par1_int64_0", method_p0, 297442167u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_par_as_ref_param_node18 : behaviac.Action
	{
		public Action_bt_par_test_par_as_ref_param_node18()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			Debug.Check(behaviac.Utils.MakeVariableId("par1_kemployee_0") == 4045482770u);
			TNS.ST.PER.WRK.kEmployee method_p0 = pAgent.GetVariable<TNS.ST.PER.WRK.kEmployee>(4045482770u);
			((ParTestAgent)pAgent).Func_kEmployeeRef(ref method_p0);
			Debug.Check(behaviac.Utils.MakeVariableId("par1_kemployee_0") == 4045482770u);
			pAgent.SetVariable<TNS.ST.PER.WRK.kEmployee>("par1_kemployee_0", method_p0, 4045482770u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_par_as_ref_param_node19 : behaviac.Action
	{
		public Action_bt_par_test_par_as_ref_param_node19()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			Debug.Check(behaviac.Utils.MakeVariableId("par1_kemployee_list_0") == 506976637u);
			List<TNS.ST.PER.WRK.kEmployee> method_p0 = pAgent.GetVariable<List<TNS.ST.PER.WRK.kEmployee>>(506976637u);
			((ParTestAgent)pAgent).Func_kEmployeeListRef(ref method_p0);
			Debug.Check(behaviac.Utils.MakeVariableId("par1_kemployee_list_0") == 506976637u);
			pAgent.SetVariable<List<TNS.ST.PER.WRK.kEmployee>>("par1_kemployee_list_0", method_p0, 506976637u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_par_as_ref_param_node20 : behaviac.Action
	{
		public Action_bt_par_test_par_as_ref_param_node20()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			Debug.Check(behaviac.Utils.MakeVariableId("par1_uint16_0") == 3480760377u);
			ushort method_p0 = pAgent.GetVariable<ushort>(3480760377u);
			((ParTestAgent)pAgent).Func_UInt16Ref(ref method_p0);
			Debug.Check(behaviac.Utils.MakeVariableId("par1_uint16_0") == 3480760377u);
			pAgent.SetVariable<ushort>("par1_uint16_0", method_p0, 3480760377u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_par_as_ref_param_node16 : behaviac.Action
	{
		public Action_bt_par_test_par_as_ref_param_node16()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			Debug.Check(behaviac.Utils.MakeVariableId("par0_boolean_0") == 1912381985u);
			bool method_p0 = pAgent.GetVariable<bool>(1912381985u);
			((ParTestAgentBase)pAgent).Func_BooleanRef(ref method_p0);
			Debug.Check(behaviac.Utils.MakeVariableId("par0_boolean_0") == 1912381985u);
			pAgent.SetVariable<bool>("par0_boolean_0", method_p0, 1912381985u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_par_as_ref_param_node21 : behaviac.Action
	{
		public Action_bt_par_test_par_as_ref_param_node21()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			Debug.Check(behaviac.Utils.MakeVariableId("par0_boolean_list_0") == 109714028u);
			List<bool> method_p0 = pAgent.GetVariable<List<bool>>(109714028u);
			((ParTestAgentBase)pAgent).Func_BooleanListRef(ref method_p0);
			Debug.Check(behaviac.Utils.MakeVariableId("par0_boolean_list_0") == 109714028u);
			pAgent.SetVariable<List<bool>>("par0_boolean_list_0", method_p0, 109714028u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_par_as_ref_param_node15 : behaviac.Action
	{
		public Action_bt_par_test_par_as_ref_param_node15()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			Debug.Check(behaviac.Utils.MakeVariableId("par0_byte_0") == 2120958860u);
			byte method_p0 = pAgent.GetVariable<byte>(2120958860u);
			((ParTestAgentBase)pAgent).Func_ByteRef(ref method_p0);
			Debug.Check(behaviac.Utils.MakeVariableId("par0_byte_0") == 2120958860u);
			pAgent.SetVariable<byte>("par0_byte_0", method_p0, 2120958860u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_par_as_ref_param_node29 : behaviac.Action
	{
		public Action_bt_par_test_par_as_ref_param_node29()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			Debug.Check(behaviac.Utils.MakeVariableId("par0_byte_list_0") == 1459492261u);
			List<byte> method_p0 = pAgent.GetVariable<List<byte>>(1459492261u);
			((ParTestAgentBase)pAgent).Func_ByteListRef(ref method_p0);
			Debug.Check(behaviac.Utils.MakeVariableId("par0_byte_list_0") == 1459492261u);
			pAgent.SetVariable<List<byte>>("par0_byte_list_0", method_p0, 1459492261u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_par_as_ref_param_node26 : behaviac.Action
	{
		public Action_bt_par_test_par_as_ref_param_node26()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			Debug.Check(behaviac.Utils.MakeVariableId("par0_char_0") == 1968762578u);
			char method_p0 = pAgent.GetVariable<char>(1968762578u);
			((ParTestAgentBase)pAgent).Func_CharRef(ref method_p0);
			Debug.Check(behaviac.Utils.MakeVariableId("par0_char_0") == 1968762578u);
			pAgent.SetVariable<char>("par0_char_0", method_p0, 1968762578u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_par_as_ref_param_node27 : behaviac.Action
	{
		public Action_bt_par_test_par_as_ref_param_node27()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			Debug.Check(behaviac.Utils.MakeVariableId("par0_char_list_0") == 2869241813u);
			List<char> method_p0 = pAgent.GetVariable<List<char>>(2869241813u);
			((ParTestAgentBase)pAgent).Func_CharListRef(ref method_p0);
			Debug.Check(behaviac.Utils.MakeVariableId("par0_char_list_0") == 2869241813u);
			pAgent.SetVariable<List<char>>("par0_char_list_0", method_p0, 2869241813u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_par_as_ref_param_node24 : behaviac.Action
	{
		public Action_bt_par_test_par_as_ref_param_node24()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			Debug.Check(behaviac.Utils.MakeVariableId("par0_ecolor_0") == 3914433730u);
			TNS.NE.NAT.eColor method_p0 = pAgent.GetVariable<TNS.NE.NAT.eColor>(3914433730u);
			((ParTestAgentBase)pAgent).Func_eColorRef(ref method_p0);
			Debug.Check(behaviac.Utils.MakeVariableId("par0_ecolor_0") == 3914433730u);
			pAgent.SetVariable<TNS.NE.NAT.eColor>("par0_ecolor_0", method_p0, 3914433730u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_par_as_ref_param_node25 : behaviac.Action
	{
		public Action_bt_par_test_par_as_ref_param_node25()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			Debug.Check(behaviac.Utils.MakeVariableId("par0_ecolor_list_0") == 1963776920u);
			List<TNS.NE.NAT.eColor> method_p0 = pAgent.GetVariable<List<TNS.NE.NAT.eColor>>(1963776920u);
			((ParTestAgentBase)pAgent).Func_eColorListRef(ref method_p0);
			Debug.Check(behaviac.Utils.MakeVariableId("par0_ecolor_list_0") == 1963776920u);
			pAgent.SetVariable<List<TNS.NE.NAT.eColor>>("par0_ecolor_list_0", method_p0, 1963776920u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_par_as_ref_param_node23 : behaviac.Action
	{
		public Action_bt_par_test_par_as_ref_param_node23()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			Debug.Check(behaviac.Utils.MakeVariableId("par0_sbyte_0") == 968869870u);
			sbyte method_p0 = pAgent.GetVariable<sbyte>(968869870u);
			((ParTestAgentBase)pAgent).Func_SByteRef(ref method_p0);
			Debug.Check(behaviac.Utils.MakeVariableId("par0_sbyte_0") == 968869870u);
			pAgent.SetVariable<sbyte>("par0_sbyte_0", method_p0, 968869870u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_par_as_ref_param_node28 : behaviac.Action
	{
		public Action_bt_par_test_par_as_ref_param_node28()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			Debug.Check(behaviac.Utils.MakeVariableId("par0_sbyte_list_0") == 2290963684u);
			List<sbyte> method_p0 = pAgent.GetVariable<List<sbyte>>(2290963684u);
			((ParTestAgentBase)pAgent).Func_SByteListRef(ref method_p0);
			Debug.Check(behaviac.Utils.MakeVariableId("par0_sbyte_list_0") == 2290963684u);
			pAgent.SetVariable<List<sbyte>>("par0_sbyte_list_0", method_p0, 2290963684u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	public static class bt_par_test_par_as_ref_param
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("par_test/par_as_ref_param");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("EmployeeParTestAgent");
#endif
			// pars
			bt.AddPar("bool", "par0_boolean_0", "false", "");
			bt.AddPar("vector<bool>", "par0_boolean_list_0", "0:", "");
			bt.AddPar("byte", "par0_byte_0", "0", "");
			bt.AddPar("vector<byte>", "par0_byte_list_0", "0:", "");
			bt.AddPar("char", "par0_char_0", "A", "");
			bt.AddPar("vector<char>", "par0_char_list_0", "0:", "");
			bt.AddPar("TNS.NE.NAT.eColor", "par0_ecolor_0", "WHITE", "");
			bt.AddPar("vector<TNS.NE.NAT.eColor>", "par0_ecolor_list_0", "0:", "");
			bt.AddPar("sbyte", "par0_sbyte_0", "0", "");
			bt.AddPar("vector<sbyte>", "par0_sbyte_list_0", "0:", "");
			bt.AddPar("short", "par1_int16_0", "0", "");
			bt.AddPar("int", "par1_int32_0", "0", "");
			bt.AddPar("vector<int>", "par1_int32_list_0", "0:", "");
			bt.AddPar("long", "par1_int64_0", "0", "");
			bt.AddPar("TNS.ST.PER.WRK.kEmployee", "par1_kemployee_0", "{boss=null;car={brand=\"\";color=RED;price=0;};code=c;id=0;isMale=false;name=\"tomlp\";skinColor=RED;weight=0;}", "");
			bt.AddPar("vector<TNS.ST.PER.WRK.kEmployee>", "par1_kemployee_list_0", "0:", "");
			bt.AddPar("ushort", "par1_uint16_0", "0", "");
			bt.AddPar("behaviac.Agent", "par2_agent_0", "null", "");
			bt.AddPar("vector<behaviac.Agent>", "par2_agent_list_0", "0:", "");
			bt.AddPar("double", "par2_double_0", "0", "");
			bt.AddPar("float", "par2_single_0", "0", "");
			bt.AddPar("vector<float>", "par2_single_list_0", "0:", "");
			bt.AddPar("string", "par2_string_0", "", "");
			bt.AddPar("vector<string>", "par2_string_list_0", "0:", "");
			bt.AddPar("uint", "par2_uint32_0", "0", "");
			bt.AddPar("ulong", "par2_uint64_0", "0", "");
			// children
			{
				Sequence node13 = new Sequence();
				node13.SetClassNameString("Sequence");
				node13.SetId(13);
#if !BEHAVIAC_RELEASE
				node13.SetAgentType("EmployeeParTestAgent");
#endif
				bt.AddChild(node13);
				{
					Sequence node1 = new Sequence();
					node1.SetClassNameString("Sequence");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("EmployeeParTestAgent");
#endif
					node13.AddChild(node1);
					{
						Action_bt_par_test_par_as_ref_param_node0 node0 = new Action_bt_par_test_par_as_ref_param_node0();
						node0.SetClassNameString("Action");
						node0.SetId(0);
#if !BEHAVIAC_RELEASE
						node0.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node0);
						node1.SetHasEvents(node1.HasEvents() | node0.HasEvents());
					}
					{
						Action_bt_par_test_par_as_ref_param_node17 node17 = new Action_bt_par_test_par_as_ref_param_node17();
						node17.SetClassNameString("Action");
						node17.SetId(17);
#if !BEHAVIAC_RELEASE
						node17.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node17);
						node1.SetHasEvents(node1.HasEvents() | node17.HasEvents());
					}
					{
						Action_bt_par_test_par_as_ref_param_node2 node2 = new Action_bt_par_test_par_as_ref_param_node2();
						node2.SetClassNameString("Action");
						node2.SetId(2);
#if !BEHAVIAC_RELEASE
						node2.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node2);
						node1.SetHasEvents(node1.HasEvents() | node2.HasEvents());
					}
					{
						Action_bt_par_test_par_as_ref_param_node3 node3 = new Action_bt_par_test_par_as_ref_param_node3();
						node3.SetClassNameString("Action");
						node3.SetId(3);
#if !BEHAVIAC_RELEASE
						node3.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node3);
						node1.SetHasEvents(node1.HasEvents() | node3.HasEvents());
					}
					{
						Action_bt_par_test_par_as_ref_param_node4 node4 = new Action_bt_par_test_par_as_ref_param_node4();
						node4.SetClassNameString("Action");
						node4.SetId(4);
#if !BEHAVIAC_RELEASE
						node4.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node4);
						node1.SetHasEvents(node1.HasEvents() | node4.HasEvents());
					}
					{
						Action_bt_par_test_par_as_ref_param_node5 node5 = new Action_bt_par_test_par_as_ref_param_node5();
						node5.SetClassNameString("Action");
						node5.SetId(5);
#if !BEHAVIAC_RELEASE
						node5.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node5);
						node1.SetHasEvents(node1.HasEvents() | node5.HasEvents());
					}
					{
						Action_bt_par_test_par_as_ref_param_node6 node6 = new Action_bt_par_test_par_as_ref_param_node6();
						node6.SetClassNameString("Action");
						node6.SetId(6);
#if !BEHAVIAC_RELEASE
						node6.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node6);
						node1.SetHasEvents(node1.HasEvents() | node6.HasEvents());
					}
					{
						Action_bt_par_test_par_as_ref_param_node7 node7 = new Action_bt_par_test_par_as_ref_param_node7();
						node7.SetClassNameString("Action");
						node7.SetId(7);
#if !BEHAVIAC_RELEASE
						node7.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node7);
						node1.SetHasEvents(node1.HasEvents() | node7.HasEvents());
					}
					{
						Action_bt_par_test_par_as_ref_param_node8 node8 = new Action_bt_par_test_par_as_ref_param_node8();
						node8.SetClassNameString("Action");
						node8.SetId(8);
#if !BEHAVIAC_RELEASE
						node8.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node8);
						node1.SetHasEvents(node1.HasEvents() | node8.HasEvents());
					}
					node13.SetHasEvents(node13.HasEvents() | node1.HasEvents());
				}
				{
					Sequence node14 = new Sequence();
					node14.SetClassNameString("Sequence");
					node14.SetId(14);
#if !BEHAVIAC_RELEASE
					node14.SetAgentType("EmployeeParTestAgent");
#endif
					node13.AddChild(node14);
					{
						Action_bt_par_test_par_as_ref_param_node9 node9 = new Action_bt_par_test_par_as_ref_param_node9();
						node9.SetClassNameString("Action");
						node9.SetId(9);
#if !BEHAVIAC_RELEASE
						node9.SetAgentType("EmployeeParTestAgent");
#endif
						node14.AddChild(node9);
						node14.SetHasEvents(node14.HasEvents() | node9.HasEvents());
					}
					{
						Action_bt_par_test_par_as_ref_param_node10 node10 = new Action_bt_par_test_par_as_ref_param_node10();
						node10.SetClassNameString("Action");
						node10.SetId(10);
#if !BEHAVIAC_RELEASE
						node10.SetAgentType("EmployeeParTestAgent");
#endif
						node14.AddChild(node10);
						node14.SetHasEvents(node14.HasEvents() | node10.HasEvents());
					}
					{
						Action_bt_par_test_par_as_ref_param_node11 node11 = new Action_bt_par_test_par_as_ref_param_node11();
						node11.SetClassNameString("Action");
						node11.SetId(11);
#if !BEHAVIAC_RELEASE
						node11.SetAgentType("EmployeeParTestAgent");
#endif
						node14.AddChild(node11);
						node14.SetHasEvents(node14.HasEvents() | node11.HasEvents());
					}
					{
						Action_bt_par_test_par_as_ref_param_node12 node12 = new Action_bt_par_test_par_as_ref_param_node12();
						node12.SetClassNameString("Action");
						node12.SetId(12);
#if !BEHAVIAC_RELEASE
						node12.SetAgentType("EmployeeParTestAgent");
#endif
						node14.AddChild(node12);
						node14.SetHasEvents(node14.HasEvents() | node12.HasEvents());
					}
					{
						Action_bt_par_test_par_as_ref_param_node18 node18 = new Action_bt_par_test_par_as_ref_param_node18();
						node18.SetClassNameString("Action");
						node18.SetId(18);
#if !BEHAVIAC_RELEASE
						node18.SetAgentType("EmployeeParTestAgent");
#endif
						node14.AddChild(node18);
						node14.SetHasEvents(node14.HasEvents() | node18.HasEvents());
					}
					{
						Action_bt_par_test_par_as_ref_param_node19 node19 = new Action_bt_par_test_par_as_ref_param_node19();
						node19.SetClassNameString("Action");
						node19.SetId(19);
#if !BEHAVIAC_RELEASE
						node19.SetAgentType("EmployeeParTestAgent");
#endif
						node14.AddChild(node19);
						node14.SetHasEvents(node14.HasEvents() | node19.HasEvents());
					}
					{
						Action_bt_par_test_par_as_ref_param_node20 node20 = new Action_bt_par_test_par_as_ref_param_node20();
						node20.SetClassNameString("Action");
						node20.SetId(20);
#if !BEHAVIAC_RELEASE
						node20.SetAgentType("EmployeeParTestAgent");
#endif
						node14.AddChild(node20);
						node14.SetHasEvents(node14.HasEvents() | node20.HasEvents());
					}
					node13.SetHasEvents(node13.HasEvents() | node14.HasEvents());
				}
				{
					Sequence node22 = new Sequence();
					node22.SetClassNameString("Sequence");
					node22.SetId(22);
#if !BEHAVIAC_RELEASE
					node22.SetAgentType("EmployeeParTestAgent");
#endif
					node13.AddChild(node22);
					{
						Action_bt_par_test_par_as_ref_param_node16 node16 = new Action_bt_par_test_par_as_ref_param_node16();
						node16.SetClassNameString("Action");
						node16.SetId(16);
#if !BEHAVIAC_RELEASE
						node16.SetAgentType("EmployeeParTestAgent");
#endif
						node22.AddChild(node16);
						node22.SetHasEvents(node22.HasEvents() | node16.HasEvents());
					}
					{
						Action_bt_par_test_par_as_ref_param_node21 node21 = new Action_bt_par_test_par_as_ref_param_node21();
						node21.SetClassNameString("Action");
						node21.SetId(21);
#if !BEHAVIAC_RELEASE
						node21.SetAgentType("EmployeeParTestAgent");
#endif
						node22.AddChild(node21);
						node22.SetHasEvents(node22.HasEvents() | node21.HasEvents());
					}
					{
						Action_bt_par_test_par_as_ref_param_node15 node15 = new Action_bt_par_test_par_as_ref_param_node15();
						node15.SetClassNameString("Action");
						node15.SetId(15);
#if !BEHAVIAC_RELEASE
						node15.SetAgentType("EmployeeParTestAgent");
#endif
						node22.AddChild(node15);
						node22.SetHasEvents(node22.HasEvents() | node15.HasEvents());
					}
					{
						Action_bt_par_test_par_as_ref_param_node29 node29 = new Action_bt_par_test_par_as_ref_param_node29();
						node29.SetClassNameString("Action");
						node29.SetId(29);
#if !BEHAVIAC_RELEASE
						node29.SetAgentType("EmployeeParTestAgent");
#endif
						node22.AddChild(node29);
						node22.SetHasEvents(node22.HasEvents() | node29.HasEvents());
					}
					{
						Action_bt_par_test_par_as_ref_param_node26 node26 = new Action_bt_par_test_par_as_ref_param_node26();
						node26.SetClassNameString("Action");
						node26.SetId(26);
#if !BEHAVIAC_RELEASE
						node26.SetAgentType("EmployeeParTestAgent");
#endif
						node22.AddChild(node26);
						node22.SetHasEvents(node22.HasEvents() | node26.HasEvents());
					}
					{
						Action_bt_par_test_par_as_ref_param_node27 node27 = new Action_bt_par_test_par_as_ref_param_node27();
						node27.SetClassNameString("Action");
						node27.SetId(27);
#if !BEHAVIAC_RELEASE
						node27.SetAgentType("EmployeeParTestAgent");
#endif
						node22.AddChild(node27);
						node22.SetHasEvents(node22.HasEvents() | node27.HasEvents());
					}
					{
						Action_bt_par_test_par_as_ref_param_node24 node24 = new Action_bt_par_test_par_as_ref_param_node24();
						node24.SetClassNameString("Action");
						node24.SetId(24);
#if !BEHAVIAC_RELEASE
						node24.SetAgentType("EmployeeParTestAgent");
#endif
						node22.AddChild(node24);
						node22.SetHasEvents(node22.HasEvents() | node24.HasEvents());
					}
					{
						Action_bt_par_test_par_as_ref_param_node25 node25 = new Action_bt_par_test_par_as_ref_param_node25();
						node25.SetClassNameString("Action");
						node25.SetId(25);
#if !BEHAVIAC_RELEASE
						node25.SetAgentType("EmployeeParTestAgent");
#endif
						node22.AddChild(node25);
						node22.SetHasEvents(node22.HasEvents() | node25.HasEvents());
					}
					{
						Action_bt_par_test_par_as_ref_param_node23 node23 = new Action_bt_par_test_par_as_ref_param_node23();
						node23.SetClassNameString("Action");
						node23.SetId(23);
#if !BEHAVIAC_RELEASE
						node23.SetAgentType("EmployeeParTestAgent");
#endif
						node22.AddChild(node23);
						node22.SetHasEvents(node22.HasEvents() | node23.HasEvents());
					}
					{
						Action_bt_par_test_par_as_ref_param_node28 node28 = new Action_bt_par_test_par_as_ref_param_node28();
						node28.SetClassNameString("Action");
						node28.SetId(28);
#if !BEHAVIAC_RELEASE
						node28.SetAgentType("EmployeeParTestAgent");
#endif
						node22.AddChild(node28);
						node22.SetHasEvents(node22.HasEvents() | node28.HasEvents());
					}
					node13.SetHasEvents(node13.HasEvents() | node22.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node13.HasEvents());
			}
			return true;
		}
	}

	// Source file: par_test/property_as_left_value

	class Assignment_bt_par_test_property_as_left_value_node0 : behaviac.Assignment
	{
		public Assignment_bt_par_test_property_as_left_value_node0()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par2_agent_0") == 3876418331u);
			behaviac.Agent opr_p0 = pAgent.GetVariable<behaviac.Agent>(3876418331u);
			behaviac.Agent opr = (behaviac.Agent)((EmployeeParTestAgent)pAgent).Func_AgentIR(opr_p0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_AGENT_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_AGENT_0") == 2234467067u);
			pAgent.SetVariable<behaviac.Agent>("TV_AGENT_0", opr, 2234467067u);
			return result;
		}
	}

	class Assignment_bt_par_test_property_as_left_value_node15 : behaviac.Assignment
	{
		public Assignment_bt_par_test_property_as_left_value_node15()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par2_agent_list_0") == 1126732011u);
			List<behaviac.Agent> opr_p0 = pAgent.GetVariable<List<behaviac.Agent>>(1126732011u);
			List<behaviac.Agent> opr = (List<behaviac.Agent>)((EmployeeParTestAgent)pAgent).Func_AgentListIR(opr_p0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_LIST_AGENT_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_LIST_AGENT_0") == 350152458u);
			pAgent.SetVariable<List<behaviac.Agent>>("TV_LIST_AGENT_0", opr, 350152458u);
			return result;
		}
	}

	class Assignment_bt_par_test_property_as_left_value_node2 : behaviac.Assignment
	{
		public Assignment_bt_par_test_property_as_left_value_node2()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par2_double_0") == 2183367433u);
			double opr_p0 = pAgent.GetVariable<double>(2183367433u);
			double opr = (double)((EmployeeParTestAgent)pAgent).Func_DoubleIR(opr_p0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_D_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_D_0") == 2418961396u);
			pAgent.SetVariable<double>("TV_D_0", opr, 2418961396u);
			return result;
		}
	}

	class Assignment_bt_par_test_property_as_left_value_node3 : behaviac.Assignment
	{
		public Assignment_bt_par_test_property_as_left_value_node3()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par2_single_0") == 3120166065u);
			float opr_p0 = pAgent.GetVariable<float>(3120166065u);
			float opr = (float)((EmployeeParTestAgent)pAgent).Func_SingleIR(opr_p0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_F_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_F_0") == 975676287u);
			pAgent.SetVariable<float>("TV_F_0", opr, 975676287u);
			return result;
		}
	}

	class Assignment_bt_par_test_property_as_left_value_node4 : behaviac.Assignment
	{
		public Assignment_bt_par_test_property_as_left_value_node4()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par2_single_list_0") == 3448877207u);
			List<float> opr_p0 = pAgent.GetVariable<List<float>>(3448877207u);
			List<float> opr = (List<float>)((EmployeeParTestAgent)pAgent).Func_SingleListIR(opr_p0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_LIST_F_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_LIST_F_0") == 3277708114u);
			pAgent.SetVariable<List<float>>("TV_LIST_F_0", opr, 3277708114u);
			return result;
		}
	}

	class Assignment_bt_par_test_property_as_left_value_node5 : behaviac.Assignment
	{
		public Assignment_bt_par_test_property_as_left_value_node5()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par2_string_0") == 351984746u);
			string opr_p0 = pAgent.GetVariable<string>(351984746u);
			string opr = (string)((EmployeeParTestAgent)pAgent).Func_StringIR(opr_p0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_STR_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_STR_0") == 3765213955u);
			pAgent.SetVariable<string>("TV_STR_0", opr, 3765213955u);
			return result;
		}
	}

	class Assignment_bt_par_test_property_as_left_value_node6 : behaviac.Assignment
	{
		public Assignment_bt_par_test_property_as_left_value_node6()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par2_string_list_0") == 1339885043u);
			List<string> opr_p0 = pAgent.GetVariable<List<string>>(1339885043u);
			List<string> opr = (List<string>)((EmployeeParTestAgent)pAgent).Func_StringListIR(opr_p0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_LIST_STR_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_LIST_STR_0") == 3861554756u);
			pAgent.SetVariable<List<string>>("TV_LIST_STR_0", opr, 3861554756u);
			return result;
		}
	}

	class Assignment_bt_par_test_property_as_left_value_node7 : behaviac.Assignment
	{
		public Assignment_bt_par_test_property_as_left_value_node7()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par2_uint32_0") == 2738393615u);
			uint opr_p0 = pAgent.GetVariable<uint>(2738393615u);
			uint opr = (uint)((EmployeeParTestAgent)pAgent).Func_UInt32IR(opr_p0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_UI32_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_UI32_0") == 94887999u);
			pAgent.SetVariable<uint>("TV_UI32_0", opr, 94887999u);
			return result;
		}
	}

	class Assignment_bt_par_test_property_as_left_value_node8 : behaviac.Assignment
	{
		public Assignment_bt_par_test_property_as_left_value_node8()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par2_uint64_0") == 1320370851u);
			ulong opr_p0 = pAgent.GetVariable<ulong>(1320370851u);
			ulong opr = (ulong)((EmployeeParTestAgent)pAgent).Func_UInt64IR(opr_p0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_UI64_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_UI64_0") == 3895210131u);
			pAgent.SetVariable<ulong>("TV_UI64_0", opr, 3895210131u);
			return result;
		}
	}

	class Assignment_bt_par_test_property_as_left_value_node9 : behaviac.Assignment
	{
		public Assignment_bt_par_test_property_as_left_value_node9()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par1_int16_0") == 160665580u);
			short opr_p0 = pAgent.GetVariable<short>(160665580u);
			short opr = (short)((ParTestAgent)pAgent).Func_Int16IR(opr_p0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_I16_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_I16_0") == 2813797015u);
			pAgent.SetVariable<short>("TV_I16_0", opr, 2813797015u);
			return result;
		}
	}

	class Assignment_bt_par_test_property_as_left_value_node10 : behaviac.Assignment
	{
		public Assignment_bt_par_test_property_as_left_value_node10()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par1_int32_0") == 4231089115u);
			int opr_p0 = pAgent.GetVariable<int>(4231089115u);
			int opr = (int)((ParTestAgent)pAgent).Func_Int32IR(opr_p0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_I32_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_I32_0") == 1377167008u);
			pAgent.SetVariable<int>("TV_I32_0", opr, 1377167008u);
			return result;
		}
	}

	class Assignment_bt_par_test_property_as_left_value_node11 : behaviac.Assignment
	{
		public Assignment_bt_par_test_property_as_left_value_node11()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par1_int32_list_0") == 468025104u);
			List<int> opr_p0 = pAgent.GetVariable<List<int>>(468025104u);
			List<int> opr = (List<int>)((ParTestAgent)pAgent).Func_Int32ListIR(opr_p0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_LIST_I32_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_LIST_I32_0") == 1414781927u);
			pAgent.SetVariable<List<int>>("TV_LIST_I32_0", opr, 1414781927u);
			return result;
		}
	}

	class Assignment_bt_par_test_property_as_left_value_node12 : behaviac.Assignment
	{
		public Assignment_bt_par_test_property_as_left_value_node12()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par1_int64_0") == 297442167u);
			long opr_p0 = pAgent.GetVariable<long>(297442167u);
			long opr = (long)((ParTestAgent)pAgent).Func_Int64IR(opr_p0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_I64_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_I64_0") == 3214816780u);
			pAgent.SetVariable<long>("TV_I64_0", opr, 3214816780u);
			return result;
		}
	}

	class Assignment_bt_par_test_property_as_left_value_node17 : behaviac.Assignment
	{
		public Assignment_bt_par_test_property_as_left_value_node17()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par1_kemployee_0") == 4045482770u);
			TNS.ST.PER.WRK.kEmployee opr_p0 = pAgent.GetVariable<TNS.ST.PER.WRK.kEmployee>(4045482770u);
			TNS.ST.PER.WRK.kEmployee opr = (TNS.ST.PER.WRK.kEmployee)((ParTestAgent)pAgent).Func_kEmployeeIR(opr_p0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_KEMPLOYEE_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_KEMPLOYEE_0") == 2788553297u);
			pAgent.SetVariable<TNS.ST.PER.WRK.kEmployee>("TV_KEMPLOYEE_0", opr, 2788553297u);
			return result;
		}
	}

	class Assignment_bt_par_test_property_as_left_value_node19 : behaviac.Assignment
	{
		public Assignment_bt_par_test_property_as_left_value_node19()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par1_kemployee_list_0") == 506976637u);
			List<TNS.ST.PER.WRK.kEmployee> opr_p0 = pAgent.GetVariable<List<TNS.ST.PER.WRK.kEmployee>>(506976637u);
			List<TNS.ST.PER.WRK.kEmployee> opr = (List<TNS.ST.PER.WRK.kEmployee>)((ParTestAgent)pAgent).Func_kEmployeeListIR(opr_p0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_LIST_KEMPLOYEE_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_LIST_KEMPLOYEE_0") == 1712688287u);
			pAgent.SetVariable<List<TNS.ST.PER.WRK.kEmployee>>("TV_LIST_KEMPLOYEE_0", opr, 1712688287u);
			return result;
		}
	}

	class Assignment_bt_par_test_property_as_left_value_node18 : behaviac.Assignment
	{
		public Assignment_bt_par_test_property_as_left_value_node18()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par1_uint16_0") == 3480760377u);
			ushort opr_p0 = pAgent.GetVariable<ushort>(3480760377u);
			ushort opr = (ushort)((ParTestAgent)pAgent).Func_UInt16IR(opr_p0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_UI16_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_UI16_0") == 4026868744u);
			pAgent.SetVariable<ushort>("TV_UI16_0", opr, 4026868744u);
			return result;
		}
	}

	class Assignment_bt_par_test_property_as_left_value_node16 : behaviac.Assignment
	{
		public Assignment_bt_par_test_property_as_left_value_node16()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par0_boolean_0") == 1912381985u);
			bool opr_p0 = pAgent.GetVariable<bool>(1912381985u);
			bool opr = (bool)((ParTestAgentBase)pAgent).Func_BooleanIR(opr_p0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_BOOL_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_BOOL_0") == 3326442243u);
			pAgent.SetVariable<bool>("TV_BOOL_0", opr, 3326442243u);
			return result;
		}
	}

	class Assignment_bt_par_test_property_as_left_value_node20 : behaviac.Assignment
	{
		public Assignment_bt_par_test_property_as_left_value_node20()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par0_boolean_list_0") == 109714028u);
			List<bool> opr_p0 = pAgent.GetVariable<List<bool>>(109714028u);
			List<bool> opr = (List<bool>)((ParTestAgentBase)pAgent).Func_BooleanListIR(opr_p0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_LIST_BOOL_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_LIST_BOOL_0") == 3454568683u);
			pAgent.SetVariable<List<bool>>("TV_LIST_BOOL_0", opr, 3454568683u);
			return result;
		}
	}

	class Assignment_bt_par_test_property_as_left_value_node24 : behaviac.Assignment
	{
		public Assignment_bt_par_test_property_as_left_value_node24()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par0_byte_0") == 2120958860u);
			byte opr_p0 = pAgent.GetVariable<byte>(2120958860u);
			byte opr = (byte)((ParTestAgentBase)pAgent).Func_ByteIR(opr_p0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_BYTE_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_BYTE_0") == 2045932444u);
			pAgent.SetVariable<byte>("TV_BYTE_0", opr, 2045932444u);
			return result;
		}
	}

	class Assignment_bt_par_test_property_as_left_value_node25 : behaviac.Assignment
	{
		public Assignment_bt_par_test_property_as_left_value_node25()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par0_byte_list_0") == 1459492261u);
			List<byte> opr_p0 = pAgent.GetVariable<List<byte>>(1459492261u);
			List<byte> opr = (List<byte>)((ParTestAgentBase)pAgent).Func_ByteListIR(opr_p0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_LIST_BYTE_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_LIST_BYTE_0") == 1918861428u);
			pAgent.SetVariable<List<byte>>("TV_LIST_BYTE_0", opr, 1918861428u);
			return result;
		}
	}

	class Assignment_bt_par_test_property_as_left_value_node26 : behaviac.Assignment
	{
		public Assignment_bt_par_test_property_as_left_value_node26()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par0_char_0") == 1968762578u);
			char opr_p0 = pAgent.GetVariable<char>(1968762578u);
			char opr = (char)((ParTestAgentBase)pAgent).Func_CharIR(opr_p0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_CHAR_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_CHAR_0") == 1925308098u);
			pAgent.SetVariable<char>("TV_CHAR_0", opr, 1925308098u);
			return result;
		}
	}

	class Assignment_bt_par_test_property_as_left_value_node27 : behaviac.Assignment
	{
		public Assignment_bt_par_test_property_as_left_value_node27()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par0_char_list_0") == 2869241813u);
			List<char> opr_p0 = pAgent.GetVariable<List<char>>(2869241813u);
			List<char> opr = (List<char>)((ParTestAgentBase)pAgent).Func_CharListIR(opr_p0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_LIST_CHAR_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_LIST_CHAR_0") == 2037132586u);
			pAgent.SetVariable<List<char>>("TV_LIST_CHAR_0", opr, 2037132586u);
			return result;
		}
	}

	class Assignment_bt_par_test_property_as_left_value_node21 : behaviac.Assignment
	{
		public Assignment_bt_par_test_property_as_left_value_node21()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par0_ecolor_0") == 3914433730u);
			TNS.NE.NAT.eColor opr_p0 = pAgent.GetVariable<TNS.NE.NAT.eColor>(3914433730u);
			TNS.NE.NAT.eColor opr = (TNS.NE.NAT.eColor)((ParTestAgentBase)pAgent).Func_eColorIR(opr_p0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_ECOLOR_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_ECOLOR_0") == 241062087u);
			pAgent.SetVariable<TNS.NE.NAT.eColor>("TV_ECOLOR_0", opr, 241062087u);
			return result;
		}
	}

	class Assignment_bt_par_test_property_as_left_value_node23 : behaviac.Assignment
	{
		public Assignment_bt_par_test_property_as_left_value_node23()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par0_ecolor_list_0") == 1963776920u);
			List<TNS.NE.NAT.eColor> opr_p0 = pAgent.GetVariable<List<TNS.NE.NAT.eColor>>(1963776920u);
			List<TNS.NE.NAT.eColor> opr = (List<TNS.NE.NAT.eColor>)((ParTestAgentBase)pAgent).Func_eColorListIR(opr_p0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_LIST_ECOLOR_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_LIST_ECOLOR_0") == 862412353u);
			pAgent.SetVariable<List<TNS.NE.NAT.eColor>>("TV_LIST_ECOLOR_0", opr, 862412353u);
			return result;
		}
	}

	class Assignment_bt_par_test_property_as_left_value_node28 : behaviac.Assignment
	{
		public Assignment_bt_par_test_property_as_left_value_node28()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par0_sbyte_0") == 968869870u);
			sbyte opr_p0 = pAgent.GetVariable<sbyte>(968869870u);
			sbyte opr = (sbyte)((ParTestAgentBase)pAgent).Func_SByteIR(opr_p0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_SBYTE_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_SBYTE_0") == 1600661043u);
			pAgent.SetVariable<sbyte>("TV_SBYTE_0", opr, 1600661043u);
			return result;
		}
	}

	class Assignment_bt_par_test_property_as_left_value_node29 : behaviac.Assignment
	{
		public Assignment_bt_par_test_property_as_left_value_node29()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			Debug.Check(behaviac.Utils.MakeVariableId("par0_sbyte_list_0") == 2290963684u);
			List<sbyte> opr_p0 = pAgent.GetVariable<List<sbyte>>(2290963684u);
			List<sbyte> opr = (List<sbyte>)((ParTestAgentBase)pAgent).Func_SByteListIR(opr_p0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_LIST_SBYTE_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_LIST_SBYTE_0") == 3466167234u);
			pAgent.SetVariable<List<sbyte>>("TV_LIST_SBYTE_0", opr, 3466167234u);
			return result;
		}
	}

	public static class bt_par_test_property_as_left_value
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("par_test/property_as_left_value");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("EmployeeParTestAgent");
#endif
			// pars
			bt.AddPar("double", "par2_double_0", "5.7", "");
			bt.AddPar("float", "par2_single_0", "98.2", "");
			bt.AddPar("vector<float>", "par2_single_list_0", "2:5.1|6.2", "");
			bt.AddPar("string", "par2_string_0", "origin", "");
			bt.AddPar("vector<string>", "par2_string_list_0", "4:\"string0\"|\"string1\"|\"string2\"|\"string3\"", "");
			bt.AddPar("uint", "par2_uint32_0", "9", "");
			bt.AddPar("ulong", "par2_uint64_0", "300", "");
			bt.AddPar("short", "par1_int16_0", "78", "");
			bt.AddPar("int", "par1_int32_0", "-3", "");
			bt.AddPar("vector<int>", "par1_int32_list_0", "3:9999|12345|0", "");
			bt.AddPar("long", "par1_int64_0", "1500", "");
			bt.AddPar("vector<TNS.ST.PER.WRK.kEmployee>", "par1_kemployee_list_0", "1:{boss=null;car={brand=\"Lexus\";color=BLUE;price=93840;};code=q;id=9;isMale=true;name=\"John\";skinColor=GREEN;weight=110;}", "");
			bt.AddPar("ushort", "par1_uint16_0", "2001", "");
			bt.AddPar("bool", "par0_boolean_0", "true", "");
			bt.AddPar("vector<bool>", "par0_boolean_list_0", "2:false|true", "");
			bt.AddPar("TNS.NE.NAT.eColor", "par0_ecolor_0", "YELLOW", "");
			bt.AddPar("vector<TNS.NE.NAT.eColor>", "par0_ecolor_list_0", "2:RED|GREEN", "");
			bt.AddPar("behaviac.Agent", "par2_agent_0", "null", "");
			bt.AddPar("vector<behaviac.Agent>", "par2_agent_list_0", "2:null|null", "");
			bt.AddPar("char", "par0_char_0", "A", "");
			bt.AddPar("TNS.ST.PER.WRK.kEmployee", "par1_kemployee_0", "{boss=null;car={brand=\"Alpha\";color=WHITE;price=5700;};code=A;id=83;isMale=false;name=\"Tom\";skinColor=RED;weight=97.3;}", "");
			bt.AddPar("byte", "par0_byte_0", "197", "");
			bt.AddPar("sbyte", "par0_sbyte_0", "-60", "");
			bt.AddPar("vector<char>", "par0_char_list_0", "4:d|j|F|A", "");
			bt.AddPar("vector<sbyte>", "par0_sbyte_list_0", "3:127|-128|0", "");
			bt.AddPar("vector<byte>", "par0_byte_list_0", "3:167|23|152", "");
			// children
			{
				Sequence node13 = new Sequence();
				node13.SetClassNameString("Sequence");
				node13.SetId(13);
#if !BEHAVIAC_RELEASE
				node13.SetAgentType("EmployeeParTestAgent");
#endif
				bt.AddChild(node13);
				{
					Sequence node1 = new Sequence();
					node1.SetClassNameString("Sequence");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("EmployeeParTestAgent");
#endif
					node13.AddChild(node1);
					{
						Assignment_bt_par_test_property_as_left_value_node0 node0 = new Assignment_bt_par_test_property_as_left_value_node0();
						node0.SetClassNameString("Assignment");
						node0.SetId(0);
#if !BEHAVIAC_RELEASE
						node0.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node0);
						node1.SetHasEvents(node1.HasEvents() | node0.HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_node15 node15 = new Assignment_bt_par_test_property_as_left_value_node15();
						node15.SetClassNameString("Assignment");
						node15.SetId(15);
#if !BEHAVIAC_RELEASE
						node15.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node15);
						node1.SetHasEvents(node1.HasEvents() | node15.HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_node2 node2 = new Assignment_bt_par_test_property_as_left_value_node2();
						node2.SetClassNameString("Assignment");
						node2.SetId(2);
#if !BEHAVIAC_RELEASE
						node2.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node2);
						node1.SetHasEvents(node1.HasEvents() | node2.HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_node3 node3 = new Assignment_bt_par_test_property_as_left_value_node3();
						node3.SetClassNameString("Assignment");
						node3.SetId(3);
#if !BEHAVIAC_RELEASE
						node3.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node3);
						node1.SetHasEvents(node1.HasEvents() | node3.HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_node4 node4 = new Assignment_bt_par_test_property_as_left_value_node4();
						node4.SetClassNameString("Assignment");
						node4.SetId(4);
#if !BEHAVIAC_RELEASE
						node4.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node4);
						node1.SetHasEvents(node1.HasEvents() | node4.HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_node5 node5 = new Assignment_bt_par_test_property_as_left_value_node5();
						node5.SetClassNameString("Assignment");
						node5.SetId(5);
#if !BEHAVIAC_RELEASE
						node5.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node5);
						node1.SetHasEvents(node1.HasEvents() | node5.HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_node6 node6 = new Assignment_bt_par_test_property_as_left_value_node6();
						node6.SetClassNameString("Assignment");
						node6.SetId(6);
#if !BEHAVIAC_RELEASE
						node6.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node6);
						node1.SetHasEvents(node1.HasEvents() | node6.HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_node7 node7 = new Assignment_bt_par_test_property_as_left_value_node7();
						node7.SetClassNameString("Assignment");
						node7.SetId(7);
#if !BEHAVIAC_RELEASE
						node7.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node7);
						node1.SetHasEvents(node1.HasEvents() | node7.HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_node8 node8 = new Assignment_bt_par_test_property_as_left_value_node8();
						node8.SetClassNameString("Assignment");
						node8.SetId(8);
#if !BEHAVIAC_RELEASE
						node8.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node8);
						node1.SetHasEvents(node1.HasEvents() | node8.HasEvents());
					}
					node13.SetHasEvents(node13.HasEvents() | node1.HasEvents());
				}
				{
					Sequence node14 = new Sequence();
					node14.SetClassNameString("Sequence");
					node14.SetId(14);
#if !BEHAVIAC_RELEASE
					node14.SetAgentType("EmployeeParTestAgent");
#endif
					node13.AddChild(node14);
					{
						Assignment_bt_par_test_property_as_left_value_node9 node9 = new Assignment_bt_par_test_property_as_left_value_node9();
						node9.SetClassNameString("Assignment");
						node9.SetId(9);
#if !BEHAVIAC_RELEASE
						node9.SetAgentType("EmployeeParTestAgent");
#endif
						node14.AddChild(node9);
						node14.SetHasEvents(node14.HasEvents() | node9.HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_node10 node10 = new Assignment_bt_par_test_property_as_left_value_node10();
						node10.SetClassNameString("Assignment");
						node10.SetId(10);
#if !BEHAVIAC_RELEASE
						node10.SetAgentType("EmployeeParTestAgent");
#endif
						node14.AddChild(node10);
						node14.SetHasEvents(node14.HasEvents() | node10.HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_node11 node11 = new Assignment_bt_par_test_property_as_left_value_node11();
						node11.SetClassNameString("Assignment");
						node11.SetId(11);
#if !BEHAVIAC_RELEASE
						node11.SetAgentType("EmployeeParTestAgent");
#endif
						node14.AddChild(node11);
						node14.SetHasEvents(node14.HasEvents() | node11.HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_node12 node12 = new Assignment_bt_par_test_property_as_left_value_node12();
						node12.SetClassNameString("Assignment");
						node12.SetId(12);
#if !BEHAVIAC_RELEASE
						node12.SetAgentType("EmployeeParTestAgent");
#endif
						node14.AddChild(node12);
						node14.SetHasEvents(node14.HasEvents() | node12.HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_node17 node17 = new Assignment_bt_par_test_property_as_left_value_node17();
						node17.SetClassNameString("Assignment");
						node17.SetId(17);
#if !BEHAVIAC_RELEASE
						node17.SetAgentType("EmployeeParTestAgent");
#endif
						node14.AddChild(node17);
						node14.SetHasEvents(node14.HasEvents() | node17.HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_node19 node19 = new Assignment_bt_par_test_property_as_left_value_node19();
						node19.SetClassNameString("Assignment");
						node19.SetId(19);
#if !BEHAVIAC_RELEASE
						node19.SetAgentType("EmployeeParTestAgent");
#endif
						node14.AddChild(node19);
						node14.SetHasEvents(node14.HasEvents() | node19.HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_node18 node18 = new Assignment_bt_par_test_property_as_left_value_node18();
						node18.SetClassNameString("Assignment");
						node18.SetId(18);
#if !BEHAVIAC_RELEASE
						node18.SetAgentType("EmployeeParTestAgent");
#endif
						node14.AddChild(node18);
						node14.SetHasEvents(node14.HasEvents() | node18.HasEvents());
					}
					node13.SetHasEvents(node13.HasEvents() | node14.HasEvents());
				}
				{
					Sequence node22 = new Sequence();
					node22.SetClassNameString("Sequence");
					node22.SetId(22);
#if !BEHAVIAC_RELEASE
					node22.SetAgentType("EmployeeParTestAgent");
#endif
					node13.AddChild(node22);
					{
						Assignment_bt_par_test_property_as_left_value_node16 node16 = new Assignment_bt_par_test_property_as_left_value_node16();
						node16.SetClassNameString("Assignment");
						node16.SetId(16);
#if !BEHAVIAC_RELEASE
						node16.SetAgentType("EmployeeParTestAgent");
#endif
						node22.AddChild(node16);
						node22.SetHasEvents(node22.HasEvents() | node16.HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_node20 node20 = new Assignment_bt_par_test_property_as_left_value_node20();
						node20.SetClassNameString("Assignment");
						node20.SetId(20);
#if !BEHAVIAC_RELEASE
						node20.SetAgentType("EmployeeParTestAgent");
#endif
						node22.AddChild(node20);
						node22.SetHasEvents(node22.HasEvents() | node20.HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_node24 node24 = new Assignment_bt_par_test_property_as_left_value_node24();
						node24.SetClassNameString("Assignment");
						node24.SetId(24);
#if !BEHAVIAC_RELEASE
						node24.SetAgentType("EmployeeParTestAgent");
#endif
						node22.AddChild(node24);
						node22.SetHasEvents(node22.HasEvents() | node24.HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_node25 node25 = new Assignment_bt_par_test_property_as_left_value_node25();
						node25.SetClassNameString("Assignment");
						node25.SetId(25);
#if !BEHAVIAC_RELEASE
						node25.SetAgentType("EmployeeParTestAgent");
#endif
						node22.AddChild(node25);
						node22.SetHasEvents(node22.HasEvents() | node25.HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_node26 node26 = new Assignment_bt_par_test_property_as_left_value_node26();
						node26.SetClassNameString("Assignment");
						node26.SetId(26);
#if !BEHAVIAC_RELEASE
						node26.SetAgentType("EmployeeParTestAgent");
#endif
						node22.AddChild(node26);
						node22.SetHasEvents(node22.HasEvents() | node26.HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_node27 node27 = new Assignment_bt_par_test_property_as_left_value_node27();
						node27.SetClassNameString("Assignment");
						node27.SetId(27);
#if !BEHAVIAC_RELEASE
						node27.SetAgentType("EmployeeParTestAgent");
#endif
						node22.AddChild(node27);
						node22.SetHasEvents(node22.HasEvents() | node27.HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_node21 node21 = new Assignment_bt_par_test_property_as_left_value_node21();
						node21.SetClassNameString("Assignment");
						node21.SetId(21);
#if !BEHAVIAC_RELEASE
						node21.SetAgentType("EmployeeParTestAgent");
#endif
						node22.AddChild(node21);
						node22.SetHasEvents(node22.HasEvents() | node21.HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_node23 node23 = new Assignment_bt_par_test_property_as_left_value_node23();
						node23.SetClassNameString("Assignment");
						node23.SetId(23);
#if !BEHAVIAC_RELEASE
						node23.SetAgentType("EmployeeParTestAgent");
#endif
						node22.AddChild(node23);
						node22.SetHasEvents(node22.HasEvents() | node23.HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_node28 node28 = new Assignment_bt_par_test_property_as_left_value_node28();
						node28.SetClassNameString("Assignment");
						node28.SetId(28);
#if !BEHAVIAC_RELEASE
						node28.SetAgentType("EmployeeParTestAgent");
#endif
						node22.AddChild(node28);
						node22.SetHasEvents(node22.HasEvents() | node28.HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_node29 node29 = new Assignment_bt_par_test_property_as_left_value_node29();
						node29.SetClassNameString("Assignment");
						node29.SetId(29);
#if !BEHAVIAC_RELEASE
						node29.SetAgentType("EmployeeParTestAgent");
#endif
						node22.AddChild(node29);
						node22.SetHasEvents(node22.HasEvents() | node29.HasEvents());
					}
					node13.SetHasEvents(node13.HasEvents() | node22.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node13.HasEvents());
			}
			return true;
		}
	}

	// Source file: par_test/property_as_left_value_and_param

	class Assignment_bt_par_test_property_as_left_value_and_param_node0 : behaviac.Assignment
	{
		public Assignment_bt_par_test_property_as_left_value_and_param_node0()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			behaviac.Agent opr = (behaviac.Agent)((EmployeeParTestAgent)pAgent).Func_AgentIR(((EmployeeParTestAgent)pAgent).TV_AGENT_0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_AGENT_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_AGENT_0") == 2234467067u);
			pAgent.SetVariable<behaviac.Agent>("TV_AGENT_0", opr, 2234467067u);
			return result;
		}
	}

	class Assignment_bt_par_test_property_as_left_value_and_param_node15 : behaviac.Assignment
	{
		public Assignment_bt_par_test_property_as_left_value_and_param_node15()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			List<behaviac.Agent> opr = (List<behaviac.Agent>)((EmployeeParTestAgent)pAgent).Func_AgentListIR(((EmployeeParTestAgent)pAgent).TV_LIST_AGENT_0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_LIST_AGENT_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_LIST_AGENT_0") == 350152458u);
			pAgent.SetVariable<List<behaviac.Agent>>("TV_LIST_AGENT_0", opr, 350152458u);
			return result;
		}
	}

	class Assignment_bt_par_test_property_as_left_value_and_param_node2 : behaviac.Assignment
	{
		public Assignment_bt_par_test_property_as_left_value_and_param_node2()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			double opr = (double)((EmployeeParTestAgent)pAgent).Func_DoubleIR(((EmployeeParTestAgent)pAgent).TV_D_0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_D_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_D_0") == 2418961396u);
			pAgent.SetVariable<double>("TV_D_0", opr, 2418961396u);
			return result;
		}
	}

	class Assignment_bt_par_test_property_as_left_value_and_param_node3 : behaviac.Assignment
	{
		public Assignment_bt_par_test_property_as_left_value_and_param_node3()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			float opr = (float)((EmployeeParTestAgent)pAgent).Func_SingleIR(((EmployeeParTestAgent)pAgent).TV_F_0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_F_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_F_0") == 975676287u);
			pAgent.SetVariable<float>("TV_F_0", opr, 975676287u);
			return result;
		}
	}

	class Assignment_bt_par_test_property_as_left_value_and_param_node4 : behaviac.Assignment
	{
		public Assignment_bt_par_test_property_as_left_value_and_param_node4()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			List<float> opr = (List<float>)((EmployeeParTestAgent)pAgent).Func_SingleListIR(((EmployeeParTestAgent)pAgent).TV_LIST_F_0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_LIST_F_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_LIST_F_0") == 3277708114u);
			pAgent.SetVariable<List<float>>("TV_LIST_F_0", opr, 3277708114u);
			return result;
		}
	}

	class Assignment_bt_par_test_property_as_left_value_and_param_node5 : behaviac.Assignment
	{
		public Assignment_bt_par_test_property_as_left_value_and_param_node5()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			string opr = (string)((EmployeeParTestAgent)pAgent).Func_StringIR(((EmployeeParTestAgent)pAgent).TV_STR_0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_STR_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_STR_0") == 3765213955u);
			pAgent.SetVariable<string>("TV_STR_0", opr, 3765213955u);
			return result;
		}
	}

	class Assignment_bt_par_test_property_as_left_value_and_param_node6 : behaviac.Assignment
	{
		public Assignment_bt_par_test_property_as_left_value_and_param_node6()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			List<string> opr = (List<string>)((EmployeeParTestAgent)pAgent).Func_StringListIR(((EmployeeParTestAgent)pAgent).TV_LIST_STR_0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_LIST_STR_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_LIST_STR_0") == 3861554756u);
			pAgent.SetVariable<List<string>>("TV_LIST_STR_0", opr, 3861554756u);
			return result;
		}
	}

	class Assignment_bt_par_test_property_as_left_value_and_param_node7 : behaviac.Assignment
	{
		public Assignment_bt_par_test_property_as_left_value_and_param_node7()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			uint opr = (uint)((EmployeeParTestAgent)pAgent).Func_UInt32IR(((EmployeeParTestAgent)pAgent).TV_UI32_0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_UI32_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_UI32_0") == 94887999u);
			pAgent.SetVariable<uint>("TV_UI32_0", opr, 94887999u);
			return result;
		}
	}

	class Assignment_bt_par_test_property_as_left_value_and_param_node8 : behaviac.Assignment
	{
		public Assignment_bt_par_test_property_as_left_value_and_param_node8()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			ulong opr = (ulong)((EmployeeParTestAgent)pAgent).Func_UInt64IR(((EmployeeParTestAgent)pAgent).TV_UI64_0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_UI64_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_UI64_0") == 3895210131u);
			pAgent.SetVariable<ulong>("TV_UI64_0", opr, 3895210131u);
			return result;
		}
	}

	class Assignment_bt_par_test_property_as_left_value_and_param_node9 : behaviac.Assignment
	{
		public Assignment_bt_par_test_property_as_left_value_and_param_node9()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			short opr = (short)((ParTestAgent)pAgent).Func_Int16IR(((ParTestAgent)pAgent).TV_I16_0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_I16_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_I16_0") == 2813797015u);
			pAgent.SetVariable<short>("TV_I16_0", opr, 2813797015u);
			return result;
		}
	}

	class Assignment_bt_par_test_property_as_left_value_and_param_node10 : behaviac.Assignment
	{
		public Assignment_bt_par_test_property_as_left_value_and_param_node10()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			int opr = (int)((ParTestAgent)pAgent).Func_Int32IR(((ParTestAgent)pAgent).TV_I32_0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_I32_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_I32_0") == 1377167008u);
			pAgent.SetVariable<int>("TV_I32_0", opr, 1377167008u);
			return result;
		}
	}

	class Assignment_bt_par_test_property_as_left_value_and_param_node11 : behaviac.Assignment
	{
		public Assignment_bt_par_test_property_as_left_value_and_param_node11()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			List<int> opr = (List<int>)((ParTestAgent)pAgent).Func_Int32ListIR(((ParTestAgent)pAgent).TV_LIST_I32_0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_LIST_I32_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_LIST_I32_0") == 1414781927u);
			pAgent.SetVariable<List<int>>("TV_LIST_I32_0", opr, 1414781927u);
			return result;
		}
	}

	class Assignment_bt_par_test_property_as_left_value_and_param_node12 : behaviac.Assignment
	{
		public Assignment_bt_par_test_property_as_left_value_and_param_node12()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			long opr = (long)((ParTestAgent)pAgent).Func_Int64IR(((ParTestAgent)pAgent).TV_I64_0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_I64_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_I64_0") == 3214816780u);
			pAgent.SetVariable<long>("TV_I64_0", opr, 3214816780u);
			return result;
		}
	}

	class Assignment_bt_par_test_property_as_left_value_and_param_node17 : behaviac.Assignment
	{
		public Assignment_bt_par_test_property_as_left_value_and_param_node17()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			TNS.ST.PER.WRK.kEmployee opr = (TNS.ST.PER.WRK.kEmployee)((ParTestAgent)pAgent).Func_kEmployeeIR(((ParTestAgent)pAgent).TV_KEMPLOYEE_0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_KEMPLOYEE_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_KEMPLOYEE_0") == 2788553297u);
			pAgent.SetVariable<TNS.ST.PER.WRK.kEmployee>("TV_KEMPLOYEE_0", opr, 2788553297u);
			return result;
		}
	}

	class Assignment_bt_par_test_property_as_left_value_and_param_node19 : behaviac.Assignment
	{
		public Assignment_bt_par_test_property_as_left_value_and_param_node19()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			List<TNS.ST.PER.WRK.kEmployee> opr = (List<TNS.ST.PER.WRK.kEmployee>)((ParTestAgent)pAgent).Func_kEmployeeListIR(((ParTestAgent)pAgent).TV_LIST_KEMPLOYEE_0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_LIST_KEMPLOYEE_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_LIST_KEMPLOYEE_0") == 1712688287u);
			pAgent.SetVariable<List<TNS.ST.PER.WRK.kEmployee>>("TV_LIST_KEMPLOYEE_0", opr, 1712688287u);
			return result;
		}
	}

	class Assignment_bt_par_test_property_as_left_value_and_param_node18 : behaviac.Assignment
	{
		public Assignment_bt_par_test_property_as_left_value_and_param_node18()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			ushort opr = (ushort)((ParTestAgent)pAgent).Func_UInt16IR(((ParTestAgent)pAgent).TV_UI16_0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_UI16_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_UI16_0") == 4026868744u);
			pAgent.SetVariable<ushort>("TV_UI16_0", opr, 4026868744u);
			return result;
		}
	}

	class Assignment_bt_par_test_property_as_left_value_and_param_node16 : behaviac.Assignment
	{
		public Assignment_bt_par_test_property_as_left_value_and_param_node16()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			bool opr = (bool)((ParTestAgentBase)pAgent).Func_BooleanIR(((ParTestAgentBase)pAgent).TV_BOOL_0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_BOOL_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_BOOL_0") == 3326442243u);
			pAgent.SetVariable<bool>("TV_BOOL_0", opr, 3326442243u);
			return result;
		}
	}

	class Assignment_bt_par_test_property_as_left_value_and_param_node20 : behaviac.Assignment
	{
		public Assignment_bt_par_test_property_as_left_value_and_param_node20()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			List<bool> opr = (List<bool>)((ParTestAgentBase)pAgent).Func_BooleanListIR(((ParTestAgentBase)pAgent).TV_LIST_BOOL_0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_LIST_BOOL_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_LIST_BOOL_0") == 3454568683u);
			pAgent.SetVariable<List<bool>>("TV_LIST_BOOL_0", opr, 3454568683u);
			return result;
		}
	}

	class Assignment_bt_par_test_property_as_left_value_and_param_node24 : behaviac.Assignment
	{
		public Assignment_bt_par_test_property_as_left_value_and_param_node24()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			byte opr = (byte)((ParTestAgentBase)pAgent).Func_ByteIR(((ParTestAgentBase)pAgent).TV_BYTE_0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_BYTE_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_BYTE_0") == 2045932444u);
			pAgent.SetVariable<byte>("TV_BYTE_0", opr, 2045932444u);
			return result;
		}
	}

	class Assignment_bt_par_test_property_as_left_value_and_param_node25 : behaviac.Assignment
	{
		public Assignment_bt_par_test_property_as_left_value_and_param_node25()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			List<byte> opr = (List<byte>)((ParTestAgentBase)pAgent).Func_ByteListIR(((ParTestAgentBase)pAgent).TV_LIST_BYTE_0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_LIST_BYTE_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_LIST_BYTE_0") == 1918861428u);
			pAgent.SetVariable<List<byte>>("TV_LIST_BYTE_0", opr, 1918861428u);
			return result;
		}
	}

	class Assignment_bt_par_test_property_as_left_value_and_param_node26 : behaviac.Assignment
	{
		public Assignment_bt_par_test_property_as_left_value_and_param_node26()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			char opr = (char)((ParTestAgentBase)pAgent).Func_CharIR(((ParTestAgentBase)pAgent).TV_CHAR_0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_CHAR_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_CHAR_0") == 1925308098u);
			pAgent.SetVariable<char>("TV_CHAR_0", opr, 1925308098u);
			return result;
		}
	}

	class Assignment_bt_par_test_property_as_left_value_and_param_node27 : behaviac.Assignment
	{
		public Assignment_bt_par_test_property_as_left_value_and_param_node27()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			List<char> opr = (List<char>)((ParTestAgentBase)pAgent).Func_CharListIR(((ParTestAgentBase)pAgent).TV_LIST_CHAR_0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_LIST_CHAR_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_LIST_CHAR_0") == 2037132586u);
			pAgent.SetVariable<List<char>>("TV_LIST_CHAR_0", opr, 2037132586u);
			return result;
		}
	}

	class Assignment_bt_par_test_property_as_left_value_and_param_node21 : behaviac.Assignment
	{
		public Assignment_bt_par_test_property_as_left_value_and_param_node21()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			TNS.NE.NAT.eColor opr = (TNS.NE.NAT.eColor)((ParTestAgentBase)pAgent).Func_eColorIR(((ParTestAgentBase)pAgent).TV_ECOLOR_0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_ECOLOR_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_ECOLOR_0") == 241062087u);
			pAgent.SetVariable<TNS.NE.NAT.eColor>("TV_ECOLOR_0", opr, 241062087u);
			return result;
		}
	}

	class Assignment_bt_par_test_property_as_left_value_and_param_node23 : behaviac.Assignment
	{
		public Assignment_bt_par_test_property_as_left_value_and_param_node23()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			List<TNS.NE.NAT.eColor> opr = (List<TNS.NE.NAT.eColor>)((ParTestAgentBase)pAgent).Func_eColorListIR(((ParTestAgentBase)pAgent).TV_LIST_ECOLOR_0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_LIST_ECOLOR_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_LIST_ECOLOR_0") == 862412353u);
			pAgent.SetVariable<List<TNS.NE.NAT.eColor>>("TV_LIST_ECOLOR_0", opr, 862412353u);
			return result;
		}
	}

	class Assignment_bt_par_test_property_as_left_value_and_param_node28 : behaviac.Assignment
	{
		public Assignment_bt_par_test_property_as_left_value_and_param_node28()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			sbyte opr = (sbyte)((ParTestAgentBase)pAgent).Func_SByteIR(((ParTestAgentBase)pAgent).TV_SBYTE_0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_SBYTE_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_SBYTE_0") == 1600661043u);
			pAgent.SetVariable<sbyte>("TV_SBYTE_0", opr, 1600661043u);
			return result;
		}
	}

	class Assignment_bt_par_test_property_as_left_value_and_param_node29 : behaviac.Assignment
	{
		public Assignment_bt_par_test_property_as_left_value_and_param_node29()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			List<sbyte> opr = (List<sbyte>)((ParTestAgentBase)pAgent).Func_SByteListIR(((ParTestAgentBase)pAgent).TV_LIST_SBYTE_0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_LIST_SBYTE_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_LIST_SBYTE_0") == 3466167234u);
			pAgent.SetVariable<List<sbyte>>("TV_LIST_SBYTE_0", opr, 3466167234u);
			return result;
		}
	}

	public static class bt_par_test_property_as_left_value_and_param
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("par_test/property_as_left_value_and_param");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("EmployeeParTestAgent");
#endif
			// children
			{
				Sequence node13 = new Sequence();
				node13.SetClassNameString("Sequence");
				node13.SetId(13);
#if !BEHAVIAC_RELEASE
				node13.SetAgentType("EmployeeParTestAgent");
#endif
				bt.AddChild(node13);
				{
					Sequence node1 = new Sequence();
					node1.SetClassNameString("Sequence");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("EmployeeParTestAgent");
#endif
					node13.AddChild(node1);
					{
						Assignment_bt_par_test_property_as_left_value_and_param_node0 node0 = new Assignment_bt_par_test_property_as_left_value_and_param_node0();
						node0.SetClassNameString("Assignment");
						node0.SetId(0);
#if !BEHAVIAC_RELEASE
						node0.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node0);
						node1.SetHasEvents(node1.HasEvents() | node0.HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_and_param_node15 node15 = new Assignment_bt_par_test_property_as_left_value_and_param_node15();
						node15.SetClassNameString("Assignment");
						node15.SetId(15);
#if !BEHAVIAC_RELEASE
						node15.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node15);
						node1.SetHasEvents(node1.HasEvents() | node15.HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_and_param_node2 node2 = new Assignment_bt_par_test_property_as_left_value_and_param_node2();
						node2.SetClassNameString("Assignment");
						node2.SetId(2);
#if !BEHAVIAC_RELEASE
						node2.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node2);
						node1.SetHasEvents(node1.HasEvents() | node2.HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_and_param_node3 node3 = new Assignment_bt_par_test_property_as_left_value_and_param_node3();
						node3.SetClassNameString("Assignment");
						node3.SetId(3);
#if !BEHAVIAC_RELEASE
						node3.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node3);
						node1.SetHasEvents(node1.HasEvents() | node3.HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_and_param_node4 node4 = new Assignment_bt_par_test_property_as_left_value_and_param_node4();
						node4.SetClassNameString("Assignment");
						node4.SetId(4);
#if !BEHAVIAC_RELEASE
						node4.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node4);
						node1.SetHasEvents(node1.HasEvents() | node4.HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_and_param_node5 node5 = new Assignment_bt_par_test_property_as_left_value_and_param_node5();
						node5.SetClassNameString("Assignment");
						node5.SetId(5);
#if !BEHAVIAC_RELEASE
						node5.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node5);
						node1.SetHasEvents(node1.HasEvents() | node5.HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_and_param_node6 node6 = new Assignment_bt_par_test_property_as_left_value_and_param_node6();
						node6.SetClassNameString("Assignment");
						node6.SetId(6);
#if !BEHAVIAC_RELEASE
						node6.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node6);
						node1.SetHasEvents(node1.HasEvents() | node6.HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_and_param_node7 node7 = new Assignment_bt_par_test_property_as_left_value_and_param_node7();
						node7.SetClassNameString("Assignment");
						node7.SetId(7);
#if !BEHAVIAC_RELEASE
						node7.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node7);
						node1.SetHasEvents(node1.HasEvents() | node7.HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_and_param_node8 node8 = new Assignment_bt_par_test_property_as_left_value_and_param_node8();
						node8.SetClassNameString("Assignment");
						node8.SetId(8);
#if !BEHAVIAC_RELEASE
						node8.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node8);
						node1.SetHasEvents(node1.HasEvents() | node8.HasEvents());
					}
					node13.SetHasEvents(node13.HasEvents() | node1.HasEvents());
				}
				{
					Sequence node14 = new Sequence();
					node14.SetClassNameString("Sequence");
					node14.SetId(14);
#if !BEHAVIAC_RELEASE
					node14.SetAgentType("EmployeeParTestAgent");
#endif
					node13.AddChild(node14);
					{
						Assignment_bt_par_test_property_as_left_value_and_param_node9 node9 = new Assignment_bt_par_test_property_as_left_value_and_param_node9();
						node9.SetClassNameString("Assignment");
						node9.SetId(9);
#if !BEHAVIAC_RELEASE
						node9.SetAgentType("EmployeeParTestAgent");
#endif
						node14.AddChild(node9);
						node14.SetHasEvents(node14.HasEvents() | node9.HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_and_param_node10 node10 = new Assignment_bt_par_test_property_as_left_value_and_param_node10();
						node10.SetClassNameString("Assignment");
						node10.SetId(10);
#if !BEHAVIAC_RELEASE
						node10.SetAgentType("EmployeeParTestAgent");
#endif
						node14.AddChild(node10);
						node14.SetHasEvents(node14.HasEvents() | node10.HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_and_param_node11 node11 = new Assignment_bt_par_test_property_as_left_value_and_param_node11();
						node11.SetClassNameString("Assignment");
						node11.SetId(11);
#if !BEHAVIAC_RELEASE
						node11.SetAgentType("EmployeeParTestAgent");
#endif
						node14.AddChild(node11);
						node14.SetHasEvents(node14.HasEvents() | node11.HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_and_param_node12 node12 = new Assignment_bt_par_test_property_as_left_value_and_param_node12();
						node12.SetClassNameString("Assignment");
						node12.SetId(12);
#if !BEHAVIAC_RELEASE
						node12.SetAgentType("EmployeeParTestAgent");
#endif
						node14.AddChild(node12);
						node14.SetHasEvents(node14.HasEvents() | node12.HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_and_param_node17 node17 = new Assignment_bt_par_test_property_as_left_value_and_param_node17();
						node17.SetClassNameString("Assignment");
						node17.SetId(17);
#if !BEHAVIAC_RELEASE
						node17.SetAgentType("EmployeeParTestAgent");
#endif
						node14.AddChild(node17);
						node14.SetHasEvents(node14.HasEvents() | node17.HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_and_param_node19 node19 = new Assignment_bt_par_test_property_as_left_value_and_param_node19();
						node19.SetClassNameString("Assignment");
						node19.SetId(19);
#if !BEHAVIAC_RELEASE
						node19.SetAgentType("EmployeeParTestAgent");
#endif
						node14.AddChild(node19);
						node14.SetHasEvents(node14.HasEvents() | node19.HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_and_param_node18 node18 = new Assignment_bt_par_test_property_as_left_value_and_param_node18();
						node18.SetClassNameString("Assignment");
						node18.SetId(18);
#if !BEHAVIAC_RELEASE
						node18.SetAgentType("EmployeeParTestAgent");
#endif
						node14.AddChild(node18);
						node14.SetHasEvents(node14.HasEvents() | node18.HasEvents());
					}
					node13.SetHasEvents(node13.HasEvents() | node14.HasEvents());
				}
				{
					Sequence node22 = new Sequence();
					node22.SetClassNameString("Sequence");
					node22.SetId(22);
#if !BEHAVIAC_RELEASE
					node22.SetAgentType("EmployeeParTestAgent");
#endif
					node13.AddChild(node22);
					{
						Assignment_bt_par_test_property_as_left_value_and_param_node16 node16 = new Assignment_bt_par_test_property_as_left_value_and_param_node16();
						node16.SetClassNameString("Assignment");
						node16.SetId(16);
#if !BEHAVIAC_RELEASE
						node16.SetAgentType("EmployeeParTestAgent");
#endif
						node22.AddChild(node16);
						node22.SetHasEvents(node22.HasEvents() | node16.HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_and_param_node20 node20 = new Assignment_bt_par_test_property_as_left_value_and_param_node20();
						node20.SetClassNameString("Assignment");
						node20.SetId(20);
#if !BEHAVIAC_RELEASE
						node20.SetAgentType("EmployeeParTestAgent");
#endif
						node22.AddChild(node20);
						node22.SetHasEvents(node22.HasEvents() | node20.HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_and_param_node24 node24 = new Assignment_bt_par_test_property_as_left_value_and_param_node24();
						node24.SetClassNameString("Assignment");
						node24.SetId(24);
#if !BEHAVIAC_RELEASE
						node24.SetAgentType("EmployeeParTestAgent");
#endif
						node22.AddChild(node24);
						node22.SetHasEvents(node22.HasEvents() | node24.HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_and_param_node25 node25 = new Assignment_bt_par_test_property_as_left_value_and_param_node25();
						node25.SetClassNameString("Assignment");
						node25.SetId(25);
#if !BEHAVIAC_RELEASE
						node25.SetAgentType("EmployeeParTestAgent");
#endif
						node22.AddChild(node25);
						node22.SetHasEvents(node22.HasEvents() | node25.HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_and_param_node26 node26 = new Assignment_bt_par_test_property_as_left_value_and_param_node26();
						node26.SetClassNameString("Assignment");
						node26.SetId(26);
#if !BEHAVIAC_RELEASE
						node26.SetAgentType("EmployeeParTestAgent");
#endif
						node22.AddChild(node26);
						node22.SetHasEvents(node22.HasEvents() | node26.HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_and_param_node27 node27 = new Assignment_bt_par_test_property_as_left_value_and_param_node27();
						node27.SetClassNameString("Assignment");
						node27.SetId(27);
#if !BEHAVIAC_RELEASE
						node27.SetAgentType("EmployeeParTestAgent");
#endif
						node22.AddChild(node27);
						node22.SetHasEvents(node22.HasEvents() | node27.HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_and_param_node21 node21 = new Assignment_bt_par_test_property_as_left_value_and_param_node21();
						node21.SetClassNameString("Assignment");
						node21.SetId(21);
#if !BEHAVIAC_RELEASE
						node21.SetAgentType("EmployeeParTestAgent");
#endif
						node22.AddChild(node21);
						node22.SetHasEvents(node22.HasEvents() | node21.HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_and_param_node23 node23 = new Assignment_bt_par_test_property_as_left_value_and_param_node23();
						node23.SetClassNameString("Assignment");
						node23.SetId(23);
#if !BEHAVIAC_RELEASE
						node23.SetAgentType("EmployeeParTestAgent");
#endif
						node22.AddChild(node23);
						node22.SetHasEvents(node22.HasEvents() | node23.HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_and_param_node28 node28 = new Assignment_bt_par_test_property_as_left_value_and_param_node28();
						node28.SetClassNameString("Assignment");
						node28.SetId(28);
#if !BEHAVIAC_RELEASE
						node28.SetAgentType("EmployeeParTestAgent");
#endif
						node22.AddChild(node28);
						node22.SetHasEvents(node22.HasEvents() | node28.HasEvents());
					}
					{
						Assignment_bt_par_test_property_as_left_value_and_param_node29 node29 = new Assignment_bt_par_test_property_as_left_value_and_param_node29();
						node29.SetClassNameString("Assignment");
						node29.SetId(29);
#if !BEHAVIAC_RELEASE
						node29.SetAgentType("EmployeeParTestAgent");
#endif
						node22.AddChild(node29);
						node22.SetHasEvents(node22.HasEvents() | node29.HasEvents());
					}
					node13.SetHasEvents(node13.HasEvents() | node22.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node13.HasEvents());
			}
			return true;
		}
	}

	// Source file: par_test/property_as_ref_param

	class Action_bt_par_test_property_as_ref_param_node0 : behaviac.Action
	{
		public Action_bt_par_test_property_as_ref_param_node0()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((EmployeeParTestAgent)pAgent).Func_AgentRef(ref ((EmployeeParTestAgent)pAgent).TV_AGENT_0);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_AGENT_0") == 2234467067u);
			pAgent.SetVariable<behaviac.Agent>("TV_AGENT_0", ((EmployeeParTestAgent)pAgent).TV_AGENT_0, 2234467067u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_property_as_ref_param_node17 : behaviac.Action
	{
		public Action_bt_par_test_property_as_ref_param_node17()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((EmployeeParTestAgent)pAgent).Func_AgentListRef(ref ((EmployeeParTestAgent)pAgent).TV_LIST_AGENT_0);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_LIST_AGENT_0") == 350152458u);
			pAgent.SetVariable<List<behaviac.Agent>>("TV_LIST_AGENT_0", ((EmployeeParTestAgent)pAgent).TV_LIST_AGENT_0, 350152458u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_property_as_ref_param_node2 : behaviac.Action
	{
		public Action_bt_par_test_property_as_ref_param_node2()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((EmployeeParTestAgent)pAgent).Func_DoubleRef(ref ((EmployeeParTestAgent)pAgent).TV_D_0);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_D_0") == 2418961396u);
			pAgent.SetVariable<double>("TV_D_0", ((EmployeeParTestAgent)pAgent).TV_D_0, 2418961396u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_property_as_ref_param_node3 : behaviac.Action
	{
		public Action_bt_par_test_property_as_ref_param_node3()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((EmployeeParTestAgent)pAgent).Func_SingleRef(ref ((EmployeeParTestAgent)pAgent).TV_F_0);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_F_0") == 975676287u);
			pAgent.SetVariable<float>("TV_F_0", ((EmployeeParTestAgent)pAgent).TV_F_0, 975676287u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_property_as_ref_param_node4 : behaviac.Action
	{
		public Action_bt_par_test_property_as_ref_param_node4()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((EmployeeParTestAgent)pAgent).Func_SingleListRef(ref ((EmployeeParTestAgent)pAgent).TV_LIST_F_0);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_LIST_F_0") == 3277708114u);
			pAgent.SetVariable<List<float>>("TV_LIST_F_0", ((EmployeeParTestAgent)pAgent).TV_LIST_F_0, 3277708114u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_property_as_ref_param_node5 : behaviac.Action
	{
		public Action_bt_par_test_property_as_ref_param_node5()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((EmployeeParTestAgent)pAgent).Func_StringRef(ref ((EmployeeParTestAgent)pAgent).TV_STR_0);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_STR_0") == 3765213955u);
			pAgent.SetVariable<string>("TV_STR_0", ((EmployeeParTestAgent)pAgent).TV_STR_0, 3765213955u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_property_as_ref_param_node6 : behaviac.Action
	{
		public Action_bt_par_test_property_as_ref_param_node6()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((EmployeeParTestAgent)pAgent).Func_StringListRef(ref ((EmployeeParTestAgent)pAgent).TV_LIST_STR_0);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_LIST_STR_0") == 3861554756u);
			pAgent.SetVariable<List<string>>("TV_LIST_STR_0", ((EmployeeParTestAgent)pAgent).TV_LIST_STR_0, 3861554756u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_property_as_ref_param_node7 : behaviac.Action
	{
		public Action_bt_par_test_property_as_ref_param_node7()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((EmployeeParTestAgent)pAgent).Func_UInt32Ref(ref ((EmployeeParTestAgent)pAgent).TV_UI32_0);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_UI32_0") == 94887999u);
			pAgent.SetVariable<uint>("TV_UI32_0", ((EmployeeParTestAgent)pAgent).TV_UI32_0, 94887999u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_property_as_ref_param_node8 : behaviac.Action
	{
		public Action_bt_par_test_property_as_ref_param_node8()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((EmployeeParTestAgent)pAgent).Func_UInt64Ref(ref ((EmployeeParTestAgent)pAgent).TV_UI64_0);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_UI64_0") == 3895210131u);
			pAgent.SetVariable<ulong>("TV_UI64_0", ((EmployeeParTestAgent)pAgent).TV_UI64_0, 3895210131u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_property_as_ref_param_node9 : behaviac.Action
	{
		public Action_bt_par_test_property_as_ref_param_node9()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((ParTestAgent)pAgent).Func_Int16Ref(ref ((ParTestAgent)pAgent).TV_I16_0);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_I16_0") == 2813797015u);
			pAgent.SetVariable<short>("TV_I16_0", ((ParTestAgent)pAgent).TV_I16_0, 2813797015u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_property_as_ref_param_node10 : behaviac.Action
	{
		public Action_bt_par_test_property_as_ref_param_node10()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((ParTestAgent)pAgent).Func_Int32Ref(ref ((ParTestAgent)pAgent).TV_I32_0);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_I32_0") == 1377167008u);
			pAgent.SetVariable<int>("TV_I32_0", ((ParTestAgent)pAgent).TV_I32_0, 1377167008u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_property_as_ref_param_node11 : behaviac.Action
	{
		public Action_bt_par_test_property_as_ref_param_node11()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((ParTestAgent)pAgent).Func_Int32ListRef(ref ((ParTestAgent)pAgent).TV_LIST_I32_0);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_LIST_I32_0") == 1414781927u);
			pAgent.SetVariable<List<int>>("TV_LIST_I32_0", ((ParTestAgent)pAgent).TV_LIST_I32_0, 1414781927u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_property_as_ref_param_node12 : behaviac.Action
	{
		public Action_bt_par_test_property_as_ref_param_node12()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((ParTestAgent)pAgent).Func_Int64Ref(ref ((ParTestAgent)pAgent).TV_I64_0);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_I64_0") == 3214816780u);
			pAgent.SetVariable<long>("TV_I64_0", ((ParTestAgent)pAgent).TV_I64_0, 3214816780u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_property_as_ref_param_node18 : behaviac.Action
	{
		public Action_bt_par_test_property_as_ref_param_node18()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((ParTestAgent)pAgent).Func_kEmployeeRef(ref ((ParTestAgent)pAgent).TV_KEMPLOYEE_0);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_KEMPLOYEE_0") == 2788553297u);
			pAgent.SetVariable<TNS.ST.PER.WRK.kEmployee>("TV_KEMPLOYEE_0", ((ParTestAgent)pAgent).TV_KEMPLOYEE_0, 2788553297u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_property_as_ref_param_node19 : behaviac.Action
	{
		public Action_bt_par_test_property_as_ref_param_node19()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((ParTestAgent)pAgent).Func_kEmployeeListRef(ref ((ParTestAgent)pAgent).TV_LIST_KEMPLOYEE_0);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_LIST_KEMPLOYEE_0") == 1712688287u);
			pAgent.SetVariable<List<TNS.ST.PER.WRK.kEmployee>>("TV_LIST_KEMPLOYEE_0", ((ParTestAgent)pAgent).TV_LIST_KEMPLOYEE_0, 1712688287u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_property_as_ref_param_node20 : behaviac.Action
	{
		public Action_bt_par_test_property_as_ref_param_node20()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((ParTestAgent)pAgent).Func_UInt16Ref(ref ((ParTestAgent)pAgent).TV_UI16_0);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_UI16_0") == 4026868744u);
			pAgent.SetVariable<ushort>("TV_UI16_0", ((ParTestAgent)pAgent).TV_UI16_0, 4026868744u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_property_as_ref_param_node16 : behaviac.Action
	{
		public Action_bt_par_test_property_as_ref_param_node16()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((ParTestAgentBase)pAgent).Func_BooleanRef(ref ((ParTestAgentBase)pAgent).TV_BOOL_0);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_BOOL_0") == 3326442243u);
			pAgent.SetVariable<bool>("TV_BOOL_0", ((ParTestAgentBase)pAgent).TV_BOOL_0, 3326442243u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_property_as_ref_param_node21 : behaviac.Action
	{
		public Action_bt_par_test_property_as_ref_param_node21()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((ParTestAgentBase)pAgent).Func_BooleanListRef(ref ((ParTestAgentBase)pAgent).TV_LIST_BOOL_0);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_LIST_BOOL_0") == 3454568683u);
			pAgent.SetVariable<List<bool>>("TV_LIST_BOOL_0", ((ParTestAgentBase)pAgent).TV_LIST_BOOL_0, 3454568683u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_property_as_ref_param_node15 : behaviac.Action
	{
		public Action_bt_par_test_property_as_ref_param_node15()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((ParTestAgentBase)pAgent).Func_ByteRef(ref ((ParTestAgentBase)pAgent).TV_BYTE_0);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_BYTE_0") == 2045932444u);
			pAgent.SetVariable<byte>("TV_BYTE_0", ((ParTestAgentBase)pAgent).TV_BYTE_0, 2045932444u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_property_as_ref_param_node29 : behaviac.Action
	{
		public Action_bt_par_test_property_as_ref_param_node29()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((ParTestAgentBase)pAgent).Func_ByteListRef(ref ((ParTestAgentBase)pAgent).TV_LIST_BYTE_0);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_LIST_BYTE_0") == 1918861428u);
			pAgent.SetVariable<List<byte>>("TV_LIST_BYTE_0", ((ParTestAgentBase)pAgent).TV_LIST_BYTE_0, 1918861428u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_property_as_ref_param_node26 : behaviac.Action
	{
		public Action_bt_par_test_property_as_ref_param_node26()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((ParTestAgentBase)pAgent).Func_CharRef(ref ((ParTestAgentBase)pAgent).TV_CHAR_0);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_CHAR_0") == 1925308098u);
			pAgent.SetVariable<char>("TV_CHAR_0", ((ParTestAgentBase)pAgent).TV_CHAR_0, 1925308098u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_property_as_ref_param_node27 : behaviac.Action
	{
		public Action_bt_par_test_property_as_ref_param_node27()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((ParTestAgentBase)pAgent).Func_CharListRef(ref ((ParTestAgentBase)pAgent).TV_LIST_CHAR_0);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_LIST_CHAR_0") == 2037132586u);
			pAgent.SetVariable<List<char>>("TV_LIST_CHAR_0", ((ParTestAgentBase)pAgent).TV_LIST_CHAR_0, 2037132586u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_property_as_ref_param_node24 : behaviac.Action
	{
		public Action_bt_par_test_property_as_ref_param_node24()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((ParTestAgentBase)pAgent).Func_eColorRef(ref ((ParTestAgentBase)pAgent).TV_ECOLOR_0);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_ECOLOR_0") == 241062087u);
			pAgent.SetVariable<TNS.NE.NAT.eColor>("TV_ECOLOR_0", ((ParTestAgentBase)pAgent).TV_ECOLOR_0, 241062087u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_property_as_ref_param_node25 : behaviac.Action
	{
		public Action_bt_par_test_property_as_ref_param_node25()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((ParTestAgentBase)pAgent).Func_eColorListRef(ref ((ParTestAgentBase)pAgent).TV_LIST_ECOLOR_0);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_LIST_ECOLOR_0") == 862412353u);
			pAgent.SetVariable<List<TNS.NE.NAT.eColor>>("TV_LIST_ECOLOR_0", ((ParTestAgentBase)pAgent).TV_LIST_ECOLOR_0, 862412353u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_property_as_ref_param_node23 : behaviac.Action
	{
		public Action_bt_par_test_property_as_ref_param_node23()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((ParTestAgentBase)pAgent).Func_SByteRef(ref ((ParTestAgentBase)pAgent).TV_SBYTE_0);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_SBYTE_0") == 1600661043u);
			pAgent.SetVariable<sbyte>("TV_SBYTE_0", ((ParTestAgentBase)pAgent).TV_SBYTE_0, 1600661043u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_property_as_ref_param_node28 : behaviac.Action
	{
		public Action_bt_par_test_property_as_ref_param_node28()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((ParTestAgentBase)pAgent).Func_SByteListRef(ref ((ParTestAgentBase)pAgent).TV_LIST_SBYTE_0);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_LIST_SBYTE_0") == 3466167234u);
			pAgent.SetVariable<List<sbyte>>("TV_LIST_SBYTE_0", ((ParTestAgentBase)pAgent).TV_LIST_SBYTE_0, 3466167234u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	public static class bt_par_test_property_as_ref_param
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("par_test/property_as_ref_param");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("EmployeeParTestAgent");
#endif
			// pars
			bt.AddPar("ulong", "par2_uint64_0", "0", "");
			bt.AddPar("uint", "par2_uint32_0", "0", "");
			bt.AddPar("vector<string>", "par2_string_list_0", "0:", "");
			bt.AddPar("string", "par2_string_0", "", "");
			bt.AddPar("vector<float>", "par2_single_list_0", "0:", "");
			bt.AddPar("float", "par2_single_0", "0", "");
			bt.AddPar("double", "par2_double_0", "0", "");
			bt.AddPar("vector<behaviac.Agent>", "par2_agent_list_0", "0:", "");
			bt.AddPar("behaviac.Agent", "par2_agent_0", "null", "");
			bt.AddPar("ushort", "par1_uint16_0", "65535", "");
			bt.AddPar("vector<TNS.ST.PER.WRK.kEmployee>", "par1_kemployee_list_0", "0:", "");
			bt.AddPar("TNS.ST.PER.WRK.kEmployee", "par1_kemployee_0", "{boss=null;car={brand=\"\";color=RED;price=0;};code=c;id=0;isMale=false;name=\"tomlp\";skinColor=RED;weight=0;}", "");
			bt.AddPar("long", "par1_int64_0", "0", "");
			bt.AddPar("vector<int>", "par1_int32_list_0", "0:", "");
			bt.AddPar("int", "par1_int32_0", "0", "");
			bt.AddPar("short", "par1_int16_0", "0", "");
			bt.AddPar("vector<sbyte>", "par0_sbyte_list_0", "0:", "");
			bt.AddPar("sbyte", "par0_sbyte_0", "0", "");
			bt.AddPar("vector<TNS.NE.NAT.eColor>", "par0_ecolor_list_0", "0:", "");
			bt.AddPar("TNS.NE.NAT.eColor", "par0_ecolor_0", "WHITE", "");
			bt.AddPar("vector<char>", "par0_char_list_0", "0:", "");
			bt.AddPar("char", "par0_char_0", "A", "");
			bt.AddPar("vector<byte>", "par0_byte_list_0", "0:", "");
			bt.AddPar("byte", "par0_byte_0", "0", "");
			bt.AddPar("vector<bool>", "par0_boolean_list_0", "0:", "");
			bt.AddPar("bool", "par0_boolean_0", "false", "");
			// children
			{
				Sequence node13 = new Sequence();
				node13.SetClassNameString("Sequence");
				node13.SetId(13);
#if !BEHAVIAC_RELEASE
				node13.SetAgentType("EmployeeParTestAgent");
#endif
				bt.AddChild(node13);
				{
					Sequence node1 = new Sequence();
					node1.SetClassNameString("Sequence");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("EmployeeParTestAgent");
#endif
					node13.AddChild(node1);
					{
						Action_bt_par_test_property_as_ref_param_node0 node0 = new Action_bt_par_test_property_as_ref_param_node0();
						node0.SetClassNameString("Action");
						node0.SetId(0);
#if !BEHAVIAC_RELEASE
						node0.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node0);
						node1.SetHasEvents(node1.HasEvents() | node0.HasEvents());
					}
					{
						Action_bt_par_test_property_as_ref_param_node17 node17 = new Action_bt_par_test_property_as_ref_param_node17();
						node17.SetClassNameString("Action");
						node17.SetId(17);
#if !BEHAVIAC_RELEASE
						node17.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node17);
						node1.SetHasEvents(node1.HasEvents() | node17.HasEvents());
					}
					{
						Action_bt_par_test_property_as_ref_param_node2 node2 = new Action_bt_par_test_property_as_ref_param_node2();
						node2.SetClassNameString("Action");
						node2.SetId(2);
#if !BEHAVIAC_RELEASE
						node2.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node2);
						node1.SetHasEvents(node1.HasEvents() | node2.HasEvents());
					}
					{
						Action_bt_par_test_property_as_ref_param_node3 node3 = new Action_bt_par_test_property_as_ref_param_node3();
						node3.SetClassNameString("Action");
						node3.SetId(3);
#if !BEHAVIAC_RELEASE
						node3.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node3);
						node1.SetHasEvents(node1.HasEvents() | node3.HasEvents());
					}
					{
						Action_bt_par_test_property_as_ref_param_node4 node4 = new Action_bt_par_test_property_as_ref_param_node4();
						node4.SetClassNameString("Action");
						node4.SetId(4);
#if !BEHAVIAC_RELEASE
						node4.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node4);
						node1.SetHasEvents(node1.HasEvents() | node4.HasEvents());
					}
					{
						Action_bt_par_test_property_as_ref_param_node5 node5 = new Action_bt_par_test_property_as_ref_param_node5();
						node5.SetClassNameString("Action");
						node5.SetId(5);
#if !BEHAVIAC_RELEASE
						node5.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node5);
						node1.SetHasEvents(node1.HasEvents() | node5.HasEvents());
					}
					{
						Action_bt_par_test_property_as_ref_param_node6 node6 = new Action_bt_par_test_property_as_ref_param_node6();
						node6.SetClassNameString("Action");
						node6.SetId(6);
#if !BEHAVIAC_RELEASE
						node6.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node6);
						node1.SetHasEvents(node1.HasEvents() | node6.HasEvents());
					}
					{
						Action_bt_par_test_property_as_ref_param_node7 node7 = new Action_bt_par_test_property_as_ref_param_node7();
						node7.SetClassNameString("Action");
						node7.SetId(7);
#if !BEHAVIAC_RELEASE
						node7.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node7);
						node1.SetHasEvents(node1.HasEvents() | node7.HasEvents());
					}
					{
						Action_bt_par_test_property_as_ref_param_node8 node8 = new Action_bt_par_test_property_as_ref_param_node8();
						node8.SetClassNameString("Action");
						node8.SetId(8);
#if !BEHAVIAC_RELEASE
						node8.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node8);
						node1.SetHasEvents(node1.HasEvents() | node8.HasEvents());
					}
					node13.SetHasEvents(node13.HasEvents() | node1.HasEvents());
				}
				{
					Sequence node14 = new Sequence();
					node14.SetClassNameString("Sequence");
					node14.SetId(14);
#if !BEHAVIAC_RELEASE
					node14.SetAgentType("EmployeeParTestAgent");
#endif
					node13.AddChild(node14);
					{
						Action_bt_par_test_property_as_ref_param_node9 node9 = new Action_bt_par_test_property_as_ref_param_node9();
						node9.SetClassNameString("Action");
						node9.SetId(9);
#if !BEHAVIAC_RELEASE
						node9.SetAgentType("EmployeeParTestAgent");
#endif
						node14.AddChild(node9);
						node14.SetHasEvents(node14.HasEvents() | node9.HasEvents());
					}
					{
						Action_bt_par_test_property_as_ref_param_node10 node10 = new Action_bt_par_test_property_as_ref_param_node10();
						node10.SetClassNameString("Action");
						node10.SetId(10);
#if !BEHAVIAC_RELEASE
						node10.SetAgentType("EmployeeParTestAgent");
#endif
						node14.AddChild(node10);
						node14.SetHasEvents(node14.HasEvents() | node10.HasEvents());
					}
					{
						Action_bt_par_test_property_as_ref_param_node11 node11 = new Action_bt_par_test_property_as_ref_param_node11();
						node11.SetClassNameString("Action");
						node11.SetId(11);
#if !BEHAVIAC_RELEASE
						node11.SetAgentType("EmployeeParTestAgent");
#endif
						node14.AddChild(node11);
						node14.SetHasEvents(node14.HasEvents() | node11.HasEvents());
					}
					{
						Action_bt_par_test_property_as_ref_param_node12 node12 = new Action_bt_par_test_property_as_ref_param_node12();
						node12.SetClassNameString("Action");
						node12.SetId(12);
#if !BEHAVIAC_RELEASE
						node12.SetAgentType("EmployeeParTestAgent");
#endif
						node14.AddChild(node12);
						node14.SetHasEvents(node14.HasEvents() | node12.HasEvents());
					}
					{
						Action_bt_par_test_property_as_ref_param_node18 node18 = new Action_bt_par_test_property_as_ref_param_node18();
						node18.SetClassNameString("Action");
						node18.SetId(18);
#if !BEHAVIAC_RELEASE
						node18.SetAgentType("EmployeeParTestAgent");
#endif
						node14.AddChild(node18);
						node14.SetHasEvents(node14.HasEvents() | node18.HasEvents());
					}
					{
						Action_bt_par_test_property_as_ref_param_node19 node19 = new Action_bt_par_test_property_as_ref_param_node19();
						node19.SetClassNameString("Action");
						node19.SetId(19);
#if !BEHAVIAC_RELEASE
						node19.SetAgentType("EmployeeParTestAgent");
#endif
						node14.AddChild(node19);
						node14.SetHasEvents(node14.HasEvents() | node19.HasEvents());
					}
					{
						Action_bt_par_test_property_as_ref_param_node20 node20 = new Action_bt_par_test_property_as_ref_param_node20();
						node20.SetClassNameString("Action");
						node20.SetId(20);
#if !BEHAVIAC_RELEASE
						node20.SetAgentType("EmployeeParTestAgent");
#endif
						node14.AddChild(node20);
						node14.SetHasEvents(node14.HasEvents() | node20.HasEvents());
					}
					node13.SetHasEvents(node13.HasEvents() | node14.HasEvents());
				}
				{
					Sequence node22 = new Sequence();
					node22.SetClassNameString("Sequence");
					node22.SetId(22);
#if !BEHAVIAC_RELEASE
					node22.SetAgentType("EmployeeParTestAgent");
#endif
					node13.AddChild(node22);
					{
						Action_bt_par_test_property_as_ref_param_node16 node16 = new Action_bt_par_test_property_as_ref_param_node16();
						node16.SetClassNameString("Action");
						node16.SetId(16);
#if !BEHAVIAC_RELEASE
						node16.SetAgentType("EmployeeParTestAgent");
#endif
						node22.AddChild(node16);
						node22.SetHasEvents(node22.HasEvents() | node16.HasEvents());
					}
					{
						Action_bt_par_test_property_as_ref_param_node21 node21 = new Action_bt_par_test_property_as_ref_param_node21();
						node21.SetClassNameString("Action");
						node21.SetId(21);
#if !BEHAVIAC_RELEASE
						node21.SetAgentType("EmployeeParTestAgent");
#endif
						node22.AddChild(node21);
						node22.SetHasEvents(node22.HasEvents() | node21.HasEvents());
					}
					{
						Action_bt_par_test_property_as_ref_param_node15 node15 = new Action_bt_par_test_property_as_ref_param_node15();
						node15.SetClassNameString("Action");
						node15.SetId(15);
#if !BEHAVIAC_RELEASE
						node15.SetAgentType("EmployeeParTestAgent");
#endif
						node22.AddChild(node15);
						node22.SetHasEvents(node22.HasEvents() | node15.HasEvents());
					}
					{
						Action_bt_par_test_property_as_ref_param_node29 node29 = new Action_bt_par_test_property_as_ref_param_node29();
						node29.SetClassNameString("Action");
						node29.SetId(29);
#if !BEHAVIAC_RELEASE
						node29.SetAgentType("EmployeeParTestAgent");
#endif
						node22.AddChild(node29);
						node22.SetHasEvents(node22.HasEvents() | node29.HasEvents());
					}
					{
						Action_bt_par_test_property_as_ref_param_node26 node26 = new Action_bt_par_test_property_as_ref_param_node26();
						node26.SetClassNameString("Action");
						node26.SetId(26);
#if !BEHAVIAC_RELEASE
						node26.SetAgentType("EmployeeParTestAgent");
#endif
						node22.AddChild(node26);
						node22.SetHasEvents(node22.HasEvents() | node26.HasEvents());
					}
					{
						Action_bt_par_test_property_as_ref_param_node27 node27 = new Action_bt_par_test_property_as_ref_param_node27();
						node27.SetClassNameString("Action");
						node27.SetId(27);
#if !BEHAVIAC_RELEASE
						node27.SetAgentType("EmployeeParTestAgent");
#endif
						node22.AddChild(node27);
						node22.SetHasEvents(node22.HasEvents() | node27.HasEvents());
					}
					{
						Action_bt_par_test_property_as_ref_param_node24 node24 = new Action_bt_par_test_property_as_ref_param_node24();
						node24.SetClassNameString("Action");
						node24.SetId(24);
#if !BEHAVIAC_RELEASE
						node24.SetAgentType("EmployeeParTestAgent");
#endif
						node22.AddChild(node24);
						node22.SetHasEvents(node22.HasEvents() | node24.HasEvents());
					}
					{
						Action_bt_par_test_property_as_ref_param_node25 node25 = new Action_bt_par_test_property_as_ref_param_node25();
						node25.SetClassNameString("Action");
						node25.SetId(25);
#if !BEHAVIAC_RELEASE
						node25.SetAgentType("EmployeeParTestAgent");
#endif
						node22.AddChild(node25);
						node22.SetHasEvents(node22.HasEvents() | node25.HasEvents());
					}
					{
						Action_bt_par_test_property_as_ref_param_node23 node23 = new Action_bt_par_test_property_as_ref_param_node23();
						node23.SetClassNameString("Action");
						node23.SetId(23);
#if !BEHAVIAC_RELEASE
						node23.SetAgentType("EmployeeParTestAgent");
#endif
						node22.AddChild(node23);
						node22.SetHasEvents(node22.HasEvents() | node23.HasEvents());
					}
					{
						Action_bt_par_test_property_as_ref_param_node28 node28 = new Action_bt_par_test_property_as_ref_param_node28();
						node28.SetClassNameString("Action");
						node28.SetId(28);
#if !BEHAVIAC_RELEASE
						node28.SetAgentType("EmployeeParTestAgent");
#endif
						node22.AddChild(node28);
						node22.SetHasEvents(node22.HasEvents() | node28.HasEvents());
					}
					node13.SetHasEvents(node13.HasEvents() | node22.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node13.HasEvents());
			}
			return true;
		}
	}

	// Source file: par_test/register_name_as_left_value_and_param

	class Assignment_bt_par_test_register_name_as_left_value_and_param_node1 : behaviac.Assignment
	{
		public Assignment_bt_par_test_register_name_as_left_value_and_param_node1()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			behaviac.Agent pAgent_opr_p0 = behaviac.Agent.GetInstance("ParTestRegNameAgent", pAgent.GetContextId());
			Debug.Check(pAgent_opr_p0 != null);
			behaviac.Agent pAgent_opr = behaviac.Agent.GetInstance("ParTestRegNameAgent", pAgent.GetContextId());
			Debug.Check(pAgent_opr != null);
			TNS.ST.PER.WRK.kEmployee opr = (TNS.ST.PER.WRK.kEmployee)((ParTestRegNameAgent)pAgent_opr).Func_kEmployeeIR(ParTestRegNameAgent.STV_KEMPLOYEE_0);
			behaviac.Agent pAgent_opl = behaviac.Agent.GetInstance("ParTestRegNameAgent", pAgent.GetContextId());
			Debug.Check(pAgent_opl != null);
			AgentExtra_Generated.SetProperty(pAgent_opl, "STV_KEMPLOYEE_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("STV_KEMPLOYEE_0") == 197916387u);
			pAgent_opl.SetVariable<TNS.ST.PER.WRK.kEmployee>("STV_KEMPLOYEE_0", opr, 197916387u);
			return result;
		}
	}

	class Assignment_bt_par_test_register_name_as_left_value_and_param_node4 : behaviac.Assignment
	{
		public Assignment_bt_par_test_register_name_as_left_value_and_param_node4()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			behaviac.Agent pAgent_opr_p0 = behaviac.Agent.GetInstance("ParTestRegNameAgent", pAgent.GetContextId());
			Debug.Check(pAgent_opr_p0 != null);
			behaviac.Agent pAgent_opr = behaviac.Agent.GetInstance("ParTestRegNameAgent", pAgent.GetContextId());
			Debug.Check(pAgent_opr != null);
			List<TNS.ST.PER.WRK.kEmployee> opr = (List<TNS.ST.PER.WRK.kEmployee>)((ParTestRegNameAgent)pAgent_opr).Func_kEmployeeListIR(ParTestRegNameAgent.STV_LIST_KEMPLOYEE_0);
			behaviac.Agent pAgent_opl = behaviac.Agent.GetInstance("ParTestRegNameAgent", pAgent.GetContextId());
			Debug.Check(pAgent_opl != null);
			AgentExtra_Generated.SetProperty(pAgent_opl, "STV_LIST_KEMPLOYEE_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("STV_LIST_KEMPLOYEE_0") == 1924897476u);
			pAgent_opl.SetVariable<List<TNS.ST.PER.WRK.kEmployee>>("STV_LIST_KEMPLOYEE_0", opr, 1924897476u);
			return result;
		}
	}

	class Assignment_bt_par_test_register_name_as_left_value_and_param_node5 : behaviac.Assignment
	{
		public Assignment_bt_par_test_register_name_as_left_value_and_param_node5()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			behaviac.Agent pAgent_opr_p0 = behaviac.Agent.GetInstance("ParTestRegNameAgent", pAgent.GetContextId());
			Debug.Check(pAgent_opr_p0 != null);
			behaviac.Agent pAgent_opr = behaviac.Agent.GetInstance("ParTestRegNameAgent", pAgent.GetContextId());
			Debug.Check(pAgent_opr != null);
			List<sbyte> opr = (List<sbyte>)((ParTestRegNameAgent)pAgent_opr).Func_SByteListIR(ParTestRegNameAgent.STV_LIST_SBYTE_0);
			behaviac.Agent pAgent_opl = behaviac.Agent.GetInstance("ParTestRegNameAgent", pAgent.GetContextId());
			Debug.Check(pAgent_opl != null);
			AgentExtra_Generated.SetProperty(pAgent_opl, "STV_LIST_SBYTE_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("STV_LIST_SBYTE_0") == 2135462866u);
			pAgent_opl.SetVariable<List<sbyte>>("STV_LIST_SBYTE_0", opr, 2135462866u);
			return result;
		}
	}

	class Assignment_bt_par_test_register_name_as_left_value_and_param_node6 : behaviac.Assignment
	{
		public Assignment_bt_par_test_register_name_as_left_value_and_param_node6()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			behaviac.Agent pAgent_opr_p0 = behaviac.Agent.GetInstance("ParTestRegNameAgent", pAgent.GetContextId());
			Debug.Check(pAgent_opr_p0 != null);
			behaviac.Agent pAgent_opr = behaviac.Agent.GetInstance("ParTestRegNameAgent", pAgent.GetContextId());
			Debug.Check(pAgent_opr != null);
			behaviac.Agent opr = (behaviac.Agent)((ParTestRegNameAgent)pAgent_opr).Func_AgentIR(((ParTestRegNameAgent)pAgent_opr_p0).TV_AGENT_0);
			behaviac.Agent pAgent_opl = behaviac.Agent.GetInstance("ParTestRegNameAgent", pAgent.GetContextId());
			Debug.Check(pAgent_opl != null);
			AgentExtra_Generated.SetProperty(pAgent_opl, "TV_AGENT_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_AGENT_0") == 2234467067u);
			pAgent_opl.SetVariable<behaviac.Agent>("TV_AGENT_0", opr, 2234467067u);
			return result;
		}
	}

	class Assignment_bt_par_test_register_name_as_left_value_and_param_node7 : behaviac.Assignment
	{
		public Assignment_bt_par_test_register_name_as_left_value_and_param_node7()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			behaviac.Agent pAgent_opr_p0 = behaviac.Agent.GetInstance("ParTestRegNameAgent", pAgent.GetContextId());
			Debug.Check(pAgent_opr_p0 != null);
			behaviac.Agent pAgent_opr = behaviac.Agent.GetInstance("ParTestRegNameAgent", pAgent.GetContextId());
			Debug.Check(pAgent_opr != null);
			byte opr = (byte)((ParTestRegNameAgent)pAgent_opr).Func_ByteIR(((ParTestRegNameAgent)pAgent_opr_p0).TV_BYTE_0);
			behaviac.Agent pAgent_opl = behaviac.Agent.GetInstance("ParTestRegNameAgent", pAgent.GetContextId());
			Debug.Check(pAgent_opl != null);
			AgentExtra_Generated.SetProperty(pAgent_opl, "TV_BYTE_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_BYTE_0") == 2045932444u);
			pAgent_opl.SetVariable<byte>("TV_BYTE_0", opr, 2045932444u);
			return result;
		}
	}

	class Assignment_bt_par_test_register_name_as_left_value_and_param_node8 : behaviac.Assignment
	{
		public Assignment_bt_par_test_register_name_as_left_value_and_param_node8()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			behaviac.Agent pAgent_opr_p0 = behaviac.Agent.GetInstance("ParTestRegNameAgent", pAgent.GetContextId());
			Debug.Check(pAgent_opr_p0 != null);
			behaviac.Agent pAgent_opr = behaviac.Agent.GetInstance("ParTestRegNameAgent", pAgent.GetContextId());
			Debug.Check(pAgent_opr != null);
			char opr = (char)((ParTestRegNameAgent)pAgent_opr).Func_CharIR(((ParTestRegNameAgent)pAgent_opr_p0).TV_CHAR_0);
			behaviac.Agent pAgent_opl = behaviac.Agent.GetInstance("ParTestRegNameAgent", pAgent.GetContextId());
			Debug.Check(pAgent_opl != null);
			AgentExtra_Generated.SetProperty(pAgent_opl, "TV_CHAR_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_CHAR_0") == 1925308098u);
			pAgent_opl.SetVariable<char>("TV_CHAR_0", opr, 1925308098u);
			return result;
		}
	}

	class Assignment_bt_par_test_register_name_as_left_value_and_param_node9 : behaviac.Assignment
	{
		public Assignment_bt_par_test_register_name_as_left_value_and_param_node9()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			behaviac.Agent pAgent_opr_p0 = behaviac.Agent.GetInstance("ParTestRegNameAgent", pAgent.GetContextId());
			Debug.Check(pAgent_opr_p0 != null);
			behaviac.Agent pAgent_opr = behaviac.Agent.GetInstance("ParTestRegNameAgent", pAgent.GetContextId());
			Debug.Check(pAgent_opr != null);
			TNS.ST.PER.WRK.kEmployee opr = (TNS.ST.PER.WRK.kEmployee)((ParTestRegNameAgent)pAgent_opr).Func_kEmployeeIR(((ParTestRegNameAgent)pAgent_opr_p0).TV_KEMPLOYEE_0);
			behaviac.Agent pAgent_opl = behaviac.Agent.GetInstance("ParTestRegNameAgent", pAgent.GetContextId());
			Debug.Check(pAgent_opl != null);
			AgentExtra_Generated.SetProperty(pAgent_opl, "TV_KEMPLOYEE_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_KEMPLOYEE_0") == 2788553297u);
			pAgent_opl.SetVariable<TNS.ST.PER.WRK.kEmployee>("TV_KEMPLOYEE_0", opr, 2788553297u);
			return result;
		}
	}

	class Assignment_bt_par_test_register_name_as_left_value_and_param_node10 : behaviac.Assignment
	{
		public Assignment_bt_par_test_register_name_as_left_value_and_param_node10()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			behaviac.Agent pAgent_opr_p0 = behaviac.Agent.GetInstance("ParTestRegNameAgent", pAgent.GetContextId());
			Debug.Check(pAgent_opr_p0 != null);
			behaviac.Agent pAgent_opr = behaviac.Agent.GetInstance("ParTestRegNameAgent", pAgent.GetContextId());
			Debug.Check(pAgent_opr != null);
			List<TNS.ST.PER.WRK.kEmployee> opr = (List<TNS.ST.PER.WRK.kEmployee>)((ParTestRegNameAgent)pAgent_opr).Func_kEmployeeListIR(((ParTestRegNameAgent)pAgent_opr_p0).TV_LIST_KEMPLOYEE_0);
			behaviac.Agent pAgent_opl = behaviac.Agent.GetInstance("ParTestRegNameAgent", pAgent.GetContextId());
			Debug.Check(pAgent_opl != null);
			AgentExtra_Generated.SetProperty(pAgent_opl, "TV_LIST_KEMPLOYEE_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_LIST_KEMPLOYEE_0") == 1712688287u);
			pAgent_opl.SetVariable<List<TNS.ST.PER.WRK.kEmployee>>("TV_LIST_KEMPLOYEE_0", opr, 1712688287u);
			return result;
		}
	}

	class Assignment_bt_par_test_register_name_as_left_value_and_param_node11 : behaviac.Assignment
	{
		public Assignment_bt_par_test_register_name_as_left_value_and_param_node11()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			behaviac.Agent pAgent_opr_p0 = behaviac.Agent.GetInstance("ParTestRegNameAgent", pAgent.GetContextId());
			Debug.Check(pAgent_opr_p0 != null);
			behaviac.Agent pAgent_opr = behaviac.Agent.GetInstance("ParTestRegNameAgent", pAgent.GetContextId());
			Debug.Check(pAgent_opr != null);
			sbyte opr = (sbyte)((ParTestRegNameAgent)pAgent_opr).Func_SByteIR(((ParTestRegNameAgent)pAgent_opr_p0).TV_SBYTE_0);
			behaviac.Agent pAgent_opl = behaviac.Agent.GetInstance("ParTestRegNameAgent", pAgent.GetContextId());
			Debug.Check(pAgent_opl != null);
			AgentExtra_Generated.SetProperty(pAgent_opl, "TV_SBYTE_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_SBYTE_0") == 1600661043u);
			pAgent_opl.SetVariable<sbyte>("TV_SBYTE_0", opr, 1600661043u);
			return result;
		}
	}

	class Assignment_bt_par_test_register_name_as_left_value_and_param_node12 : behaviac.Assignment
	{
		public Assignment_bt_par_test_register_name_as_left_value_and_param_node12()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			behaviac.Agent pAgent_opr_p0 = behaviac.Agent.GetInstance("ParTestRegNameAgent", pAgent.GetContextId());
			Debug.Check(pAgent_opr_p0 != null);
			behaviac.Agent pAgent_opr = behaviac.Agent.GetInstance("ParTestRegNameAgent", pAgent.GetContextId());
			Debug.Check(pAgent_opr != null);
			string opr = (string)((ParTestRegNameAgent)pAgent_opr).Func_StringIR(((ParTestRegNameAgent)pAgent_opr_p0).TV_STR_0);
			behaviac.Agent pAgent_opl = behaviac.Agent.GetInstance("ParTestRegNameAgent", pAgent.GetContextId());
			Debug.Check(pAgent_opl != null);
			AgentExtra_Generated.SetProperty(pAgent_opl, "TV_STR_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_STR_0") == 3765213955u);
			pAgent_opl.SetVariable<string>("TV_STR_0", opr, 3765213955u);
			return result;
		}
	}

	public static class bt_par_test_register_name_as_left_value_and_param
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("par_test/register_name_as_left_value_and_param");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("EmployeeParTestAgent");
#endif
			// children
			{
				Sequence node0 = new Sequence();
				node0.SetClassNameString("Sequence");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("EmployeeParTestAgent");
#endif
				bt.AddChild(node0);
				{
					Assignment_bt_par_test_register_name_as_left_value_and_param_node1 node1 = new Assignment_bt_par_test_register_name_as_left_value_and_param_node1();
					node1.SetClassNameString("Assignment");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("EmployeeParTestAgent");
#endif
					node0.AddChild(node1);
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					Assignment_bt_par_test_register_name_as_left_value_and_param_node4 node4 = new Assignment_bt_par_test_register_name_as_left_value_and_param_node4();
					node4.SetClassNameString("Assignment");
					node4.SetId(4);
#if !BEHAVIAC_RELEASE
					node4.SetAgentType("EmployeeParTestAgent");
#endif
					node0.AddChild(node4);
					node0.SetHasEvents(node0.HasEvents() | node4.HasEvents());
				}
				{
					Assignment_bt_par_test_register_name_as_left_value_and_param_node5 node5 = new Assignment_bt_par_test_register_name_as_left_value_and_param_node5();
					node5.SetClassNameString("Assignment");
					node5.SetId(5);
#if !BEHAVIAC_RELEASE
					node5.SetAgentType("EmployeeParTestAgent");
#endif
					node0.AddChild(node5);
					node0.SetHasEvents(node0.HasEvents() | node5.HasEvents());
				}
				{
					Assignment_bt_par_test_register_name_as_left_value_and_param_node6 node6 = new Assignment_bt_par_test_register_name_as_left_value_and_param_node6();
					node6.SetClassNameString("Assignment");
					node6.SetId(6);
#if !BEHAVIAC_RELEASE
					node6.SetAgentType("EmployeeParTestAgent");
#endif
					node0.AddChild(node6);
					node0.SetHasEvents(node0.HasEvents() | node6.HasEvents());
				}
				{
					Assignment_bt_par_test_register_name_as_left_value_and_param_node7 node7 = new Assignment_bt_par_test_register_name_as_left_value_and_param_node7();
					node7.SetClassNameString("Assignment");
					node7.SetId(7);
#if !BEHAVIAC_RELEASE
					node7.SetAgentType("EmployeeParTestAgent");
#endif
					node0.AddChild(node7);
					node0.SetHasEvents(node0.HasEvents() | node7.HasEvents());
				}
				{
					Assignment_bt_par_test_register_name_as_left_value_and_param_node8 node8 = new Assignment_bt_par_test_register_name_as_left_value_and_param_node8();
					node8.SetClassNameString("Assignment");
					node8.SetId(8);
#if !BEHAVIAC_RELEASE
					node8.SetAgentType("EmployeeParTestAgent");
#endif
					node0.AddChild(node8);
					node0.SetHasEvents(node0.HasEvents() | node8.HasEvents());
				}
				{
					Assignment_bt_par_test_register_name_as_left_value_and_param_node9 node9 = new Assignment_bt_par_test_register_name_as_left_value_and_param_node9();
					node9.SetClassNameString("Assignment");
					node9.SetId(9);
#if !BEHAVIAC_RELEASE
					node9.SetAgentType("EmployeeParTestAgent");
#endif
					node0.AddChild(node9);
					node0.SetHasEvents(node0.HasEvents() | node9.HasEvents());
				}
				{
					Assignment_bt_par_test_register_name_as_left_value_and_param_node10 node10 = new Assignment_bt_par_test_register_name_as_left_value_and_param_node10();
					node10.SetClassNameString("Assignment");
					node10.SetId(10);
#if !BEHAVIAC_RELEASE
					node10.SetAgentType("EmployeeParTestAgent");
#endif
					node0.AddChild(node10);
					node0.SetHasEvents(node0.HasEvents() | node10.HasEvents());
				}
				{
					Assignment_bt_par_test_register_name_as_left_value_and_param_node11 node11 = new Assignment_bt_par_test_register_name_as_left_value_and_param_node11();
					node11.SetClassNameString("Assignment");
					node11.SetId(11);
#if !BEHAVIAC_RELEASE
					node11.SetAgentType("EmployeeParTestAgent");
#endif
					node0.AddChild(node11);
					node0.SetHasEvents(node0.HasEvents() | node11.HasEvents());
				}
				{
					Assignment_bt_par_test_register_name_as_left_value_and_param_node12 node12 = new Assignment_bt_par_test_register_name_as_left_value_and_param_node12();
					node12.SetClassNameString("Assignment");
					node12.SetId(12);
#if !BEHAVIAC_RELEASE
					node12.SetAgentType("EmployeeParTestAgent");
#endif
					node0.AddChild(node12);
					node0.SetHasEvents(node0.HasEvents() | node12.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: par_test/static_member_function_test_0

	class Assignment_bt_par_test_static_member_function_test_0_node4 : behaviac.Assignment
	{
		public Assignment_bt_par_test_static_member_function_test_0_node4()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			char opr = (char)ParTestAgentBase.Func_CharSMF(((ParTestAgentBase)pAgent).TV_CHAR_0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_CHAR_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_CHAR_0") == 1925308098u);
			pAgent.SetVariable<char>("TV_CHAR_0", opr, 1925308098u);
			return result;
		}
	}

	class Assignment_bt_par_test_static_member_function_test_0_node5 : behaviac.Assignment
	{
		public Assignment_bt_par_test_static_member_function_test_0_node5()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			byte opr = (byte)ParTestAgentBase.Func_ByteSMF(((ParTestAgentBase)pAgent).TV_BYTE_0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_BYTE_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_BYTE_0") == 2045932444u);
			pAgent.SetVariable<byte>("TV_BYTE_0", opr, 2045932444u);
			return result;
		}
	}

	class Assignment_bt_par_test_static_member_function_test_0_node6 : behaviac.Assignment
	{
		public Assignment_bt_par_test_static_member_function_test_0_node6()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			sbyte opr = (sbyte)ParTestAgentBase.Func_SByteSMF(((ParTestAgentBase)pAgent).TV_SBYTE_0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_SBYTE_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_SBYTE_0") == 1600661043u);
			pAgent.SetVariable<sbyte>("TV_SBYTE_0", opr, 1600661043u);
			return result;
		}
	}

	class Assignment_bt_par_test_static_member_function_test_0_node7 : behaviac.Assignment
	{
		public Assignment_bt_par_test_static_member_function_test_0_node7()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			List<char> opr = (List<char>)ParTestAgentBase.Func_CharListSMF(((ParTestAgentBase)pAgent).TV_LIST_CHAR_0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_LIST_CHAR_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_LIST_CHAR_0") == 2037132586u);
			pAgent.SetVariable<List<char>>("TV_LIST_CHAR_0", opr, 2037132586u);
			return result;
		}
	}

	class Assignment_bt_par_test_static_member_function_test_0_node8 : behaviac.Assignment
	{
		public Assignment_bt_par_test_static_member_function_test_0_node8()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			List<sbyte> opr = (List<sbyte>)ParTestAgentBase.Func_SByteListSMF(((ParTestAgentBase)pAgent).TV_LIST_SBYTE_0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_LIST_SBYTE_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_LIST_SBYTE_0") == 3466167234u);
			pAgent.SetVariable<List<sbyte>>("TV_LIST_SBYTE_0", opr, 3466167234u);
			return result;
		}
	}

	class Assignment_bt_par_test_static_member_function_test_0_node9 : behaviac.Assignment
	{
		public Assignment_bt_par_test_static_member_function_test_0_node9()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			TNS.ST.PER.WRK.kEmployee opr = (TNS.ST.PER.WRK.kEmployee)ParTestAgent.Func_kEmployeeSMF(((ParTestAgent)pAgent).TV_KEMPLOYEE_0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_KEMPLOYEE_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_KEMPLOYEE_0") == 2788553297u);
			pAgent.SetVariable<TNS.ST.PER.WRK.kEmployee>("TV_KEMPLOYEE_0", opr, 2788553297u);
			return result;
		}
	}

	class Assignment_bt_par_test_static_member_function_test_0_node10 : behaviac.Assignment
	{
		public Assignment_bt_par_test_static_member_function_test_0_node10()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			List<TNS.ST.PER.WRK.kEmployee> opr = (List<TNS.ST.PER.WRK.kEmployee>)ParTestAgent.Func_kEmployeeListSMF(((ParTestAgent)pAgent).TV_LIST_KEMPLOYEE_0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_LIST_KEMPLOYEE_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_LIST_KEMPLOYEE_0") == 1712688287u);
			pAgent.SetVariable<List<TNS.ST.PER.WRK.kEmployee>>("TV_LIST_KEMPLOYEE_0", opr, 1712688287u);
			return result;
		}
	}

	class Assignment_bt_par_test_static_member_function_test_0_node11 : behaviac.Assignment
	{
		public Assignment_bt_par_test_static_member_function_test_0_node11()
		{
			opr_p0 = 0;
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			ulong opr = (ulong)EmployeeParTestAgent.Func_UInt64SMF(opr_p0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_UI64_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_UI64_0") == 3895210131u);
			pAgent.SetVariable<ulong>("TV_UI64_0", opr, 3895210131u);
			return result;
		}
		ulong opr_p0;
	}

	class Assignment_bt_par_test_static_member_function_test_0_node12 : behaviac.Assignment
	{
		public Assignment_bt_par_test_static_member_function_test_0_node12()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			string opr = (string)EmployeeParTestAgent.Func_StringSMF(((EmployeeParTestAgent)pAgent).TV_STR_0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_STR_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_STR_0") == 3765213955u);
			pAgent.SetVariable<string>("TV_STR_0", opr, 3765213955u);
			return result;
		}
	}

	class Assignment_bt_par_test_static_member_function_test_0_node13 : behaviac.Assignment
	{
		public Assignment_bt_par_test_static_member_function_test_0_node13()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			List<string> opr = (List<string>)EmployeeParTestAgent.Func_StringListSMF(((EmployeeParTestAgent)pAgent).TV_LIST_STR_0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_LIST_STR_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_LIST_STR_0") == 3861554756u);
			pAgent.SetVariable<List<string>>("TV_LIST_STR_0", opr, 3861554756u);
			return result;
		}
	}

	class Assignment_bt_par_test_static_member_function_test_0_node14 : behaviac.Assignment
	{
		public Assignment_bt_par_test_static_member_function_test_0_node14()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			behaviac.Agent opr = (behaviac.Agent)EmployeeParTestAgent.Func_AgentSMF(((EmployeeParTestAgent)pAgent).TV_AGENT_0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_AGENT_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_AGENT_0") == 2234467067u);
			pAgent.SetVariable<behaviac.Agent>("TV_AGENT_0", opr, 2234467067u);
			return result;
		}
	}

	class Assignment_bt_par_test_static_member_function_test_0_node15 : behaviac.Assignment
	{
		public Assignment_bt_par_test_static_member_function_test_0_node15()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			List<behaviac.Agent> opr = (List<behaviac.Agent>)EmployeeParTestAgent.Func_AgentListSMF(((EmployeeParTestAgent)pAgent).TV_LIST_AGENT_0);
			AgentExtra_Generated.SetProperty(pAgent, "TV_LIST_AGENT_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("TV_LIST_AGENT_0") == 350152458u);
			pAgent.SetVariable<List<behaviac.Agent>>("TV_LIST_AGENT_0", opr, 350152458u);
			return result;
		}
	}

	public static class bt_par_test_static_member_function_test_0
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("par_test/static_member_function_test_0");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("EmployeeParTestAgent");
#endif
			// children
			{
				Sequence node0 = new Sequence();
				node0.SetClassNameString("Sequence");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("EmployeeParTestAgent");
#endif
				bt.AddChild(node0);
				{
					Sequence node1 = new Sequence();
					node1.SetClassNameString("Sequence");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("EmployeeParTestAgent");
#endif
					node0.AddChild(node1);
					{
						Assignment_bt_par_test_static_member_function_test_0_node4 node4 = new Assignment_bt_par_test_static_member_function_test_0_node4();
						node4.SetClassNameString("Assignment");
						node4.SetId(4);
#if !BEHAVIAC_RELEASE
						node4.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node4);
						node1.SetHasEvents(node1.HasEvents() | node4.HasEvents());
					}
					{
						Assignment_bt_par_test_static_member_function_test_0_node5 node5 = new Assignment_bt_par_test_static_member_function_test_0_node5();
						node5.SetClassNameString("Assignment");
						node5.SetId(5);
#if !BEHAVIAC_RELEASE
						node5.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node5);
						node1.SetHasEvents(node1.HasEvents() | node5.HasEvents());
					}
					{
						Assignment_bt_par_test_static_member_function_test_0_node6 node6 = new Assignment_bt_par_test_static_member_function_test_0_node6();
						node6.SetClassNameString("Assignment");
						node6.SetId(6);
#if !BEHAVIAC_RELEASE
						node6.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node6);
						node1.SetHasEvents(node1.HasEvents() | node6.HasEvents());
					}
					{
						Assignment_bt_par_test_static_member_function_test_0_node7 node7 = new Assignment_bt_par_test_static_member_function_test_0_node7();
						node7.SetClassNameString("Assignment");
						node7.SetId(7);
#if !BEHAVIAC_RELEASE
						node7.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node7);
						node1.SetHasEvents(node1.HasEvents() | node7.HasEvents());
					}
					{
						Assignment_bt_par_test_static_member_function_test_0_node8 node8 = new Assignment_bt_par_test_static_member_function_test_0_node8();
						node8.SetClassNameString("Assignment");
						node8.SetId(8);
#if !BEHAVIAC_RELEASE
						node8.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node8);
						node1.SetHasEvents(node1.HasEvents() | node8.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					Sequence node2 = new Sequence();
					node2.SetClassNameString("Sequence");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("EmployeeParTestAgent");
#endif
					node0.AddChild(node2);
					{
						Assignment_bt_par_test_static_member_function_test_0_node9 node9 = new Assignment_bt_par_test_static_member_function_test_0_node9();
						node9.SetClassNameString("Assignment");
						node9.SetId(9);
#if !BEHAVIAC_RELEASE
						node9.SetAgentType("EmployeeParTestAgent");
#endif
						node2.AddChild(node9);
						node2.SetHasEvents(node2.HasEvents() | node9.HasEvents());
					}
					{
						Assignment_bt_par_test_static_member_function_test_0_node10 node10 = new Assignment_bt_par_test_static_member_function_test_0_node10();
						node10.SetClassNameString("Assignment");
						node10.SetId(10);
#if !BEHAVIAC_RELEASE
						node10.SetAgentType("EmployeeParTestAgent");
#endif
						node2.AddChild(node10);
						node2.SetHasEvents(node2.HasEvents() | node10.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				{
					Sequence node3 = new Sequence();
					node3.SetClassNameString("Sequence");
					node3.SetId(3);
#if !BEHAVIAC_RELEASE
					node3.SetAgentType("EmployeeParTestAgent");
#endif
					node0.AddChild(node3);
					{
						Assignment_bt_par_test_static_member_function_test_0_node11 node11 = new Assignment_bt_par_test_static_member_function_test_0_node11();
						node11.SetClassNameString("Assignment");
						node11.SetId(11);
#if !BEHAVIAC_RELEASE
						node11.SetAgentType("EmployeeParTestAgent");
#endif
						node3.AddChild(node11);
						node3.SetHasEvents(node3.HasEvents() | node11.HasEvents());
					}
					{
						Assignment_bt_par_test_static_member_function_test_0_node12 node12 = new Assignment_bt_par_test_static_member_function_test_0_node12();
						node12.SetClassNameString("Assignment");
						node12.SetId(12);
#if !BEHAVIAC_RELEASE
						node12.SetAgentType("EmployeeParTestAgent");
#endif
						node3.AddChild(node12);
						node3.SetHasEvents(node3.HasEvents() | node12.HasEvents());
					}
					{
						Assignment_bt_par_test_static_member_function_test_0_node13 node13 = new Assignment_bt_par_test_static_member_function_test_0_node13();
						node13.SetClassNameString("Assignment");
						node13.SetId(13);
#if !BEHAVIAC_RELEASE
						node13.SetAgentType("EmployeeParTestAgent");
#endif
						node3.AddChild(node13);
						node3.SetHasEvents(node3.HasEvents() | node13.HasEvents());
					}
					{
						Assignment_bt_par_test_static_member_function_test_0_node14 node14 = new Assignment_bt_par_test_static_member_function_test_0_node14();
						node14.SetClassNameString("Assignment");
						node14.SetId(14);
#if !BEHAVIAC_RELEASE
						node14.SetAgentType("EmployeeParTestAgent");
#endif
						node3.AddChild(node14);
						node3.SetHasEvents(node3.HasEvents() | node14.HasEvents());
					}
					{
						Assignment_bt_par_test_static_member_function_test_0_node15 node15 = new Assignment_bt_par_test_static_member_function_test_0_node15();
						node15.SetClassNameString("Assignment");
						node15.SetId(15);
#if !BEHAVIAC_RELEASE
						node15.SetAgentType("EmployeeParTestAgent");
#endif
						node3.AddChild(node15);
						node3.SetHasEvents(node3.HasEvents() | node15.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node3.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: par_test/static_property_as_left_value_and_param

	class Assignment_bt_par_test_static_property_as_left_value_and_param_node4 : behaviac.Assignment
	{
		public Assignment_bt_par_test_static_property_as_left_value_and_param_node4()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			TNS.NE.NAT.eColor opr = (TNS.NE.NAT.eColor)((ParTestAgentBase)pAgent).Func_eColorIR(ParTestAgentBase.STV_ECOLOR_0);
			AgentExtra_Generated.SetProperty(pAgent, "STV_ECOLOR_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("STV_ECOLOR_0") == 1356537398u);
			pAgent.SetVariable<TNS.NE.NAT.eColor>("STV_ECOLOR_0", opr, 1356537398u);
			return result;
		}
	}

	class Assignment_bt_par_test_static_property_as_left_value_and_param_node5 : behaviac.Assignment
	{
		public Assignment_bt_par_test_static_property_as_left_value_and_param_node5()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			bool opr = (bool)((ParTestAgentBase)pAgent).Func_BooleanIR(ParTestAgentBase.STV_BOOL_0);
			AgentExtra_Generated.SetProperty(pAgent, "STV_BOOL_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("STV_BOOL_0") == 907888646u);
			pAgent.SetVariable<bool>("STV_BOOL_0", opr, 907888646u);
			return result;
		}
	}

	class Assignment_bt_par_test_static_property_as_left_value_and_param_node6 : behaviac.Assignment
	{
		public Assignment_bt_par_test_static_property_as_left_value_and_param_node6()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			char opr = (char)((ParTestAgentBase)pAgent).Func_CharIR(ParTestAgentBase.STV_CHAR_0);
			AgentExtra_Generated.SetProperty(pAgent, "STV_CHAR_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("STV_CHAR_0") == 2191125959u);
			pAgent.SetVariable<char>("STV_CHAR_0", opr, 2191125959u);
			return result;
		}
	}

	class Assignment_bt_par_test_static_property_as_left_value_and_param_node7 : behaviac.Assignment
	{
		public Assignment_bt_par_test_static_property_as_left_value_and_param_node7()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			List<TNS.NE.NAT.eColor> opr = (List<TNS.NE.NAT.eColor>)((ParTestAgentBase)pAgent).Func_eColorListIR(ParTestAgentBase.STV_LIST_ECOLOR_0);
			AgentExtra_Generated.SetProperty(pAgent, "STV_LIST_ECOLOR_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("STV_LIST_ECOLOR_0") == 2487001405u);
			pAgent.SetVariable<List<TNS.NE.NAT.eColor>>("STV_LIST_ECOLOR_0", opr, 2487001405u);
			return result;
		}
	}

	class Assignment_bt_par_test_static_property_as_left_value_and_param_node8 : behaviac.Assignment
	{
		public Assignment_bt_par_test_static_property_as_left_value_and_param_node8()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			List<bool> opr = (List<bool>)((ParTestAgentBase)pAgent).Func_BooleanListIR(ParTestAgentBase.STV_LIST_BOOL_0);
			AgentExtra_Generated.SetProperty(pAgent, "STV_LIST_BOOL_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("STV_LIST_BOOL_0") == 1612090457u);
			pAgent.SetVariable<List<bool>>("STV_LIST_BOOL_0", opr, 1612090457u);
			return result;
		}
	}

	class Assignment_bt_par_test_static_property_as_left_value_and_param_node9 : behaviac.Assignment
	{
		public Assignment_bt_par_test_static_property_as_left_value_and_param_node9()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			List<char> opr = (List<char>)((ParTestAgentBase)pAgent).Func_CharListIR(ParTestAgentBase.STV_LIST_CHAR_0);
			AgentExtra_Generated.SetProperty(pAgent, "STV_LIST_CHAR_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("STV_LIST_CHAR_0") == 3566348696u);
			pAgent.SetVariable<List<char>>("STV_LIST_CHAR_0", opr, 3566348696u);
			return result;
		}
	}

	class Assignment_bt_par_test_static_property_as_left_value_and_param_node10 : behaviac.Assignment
	{
		public Assignment_bt_par_test_static_property_as_left_value_and_param_node10()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			List<sbyte> opr = (List<sbyte>)((ParTestAgentBase)pAgent).Func_SByteListIR(ParTestAgentBase.STV_LIST_SBYTE_0);
			AgentExtra_Generated.SetProperty(pAgent, "STV_LIST_SBYTE_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("STV_LIST_SBYTE_0") == 2135462866u);
			pAgent.SetVariable<List<sbyte>>("STV_LIST_SBYTE_0", opr, 2135462866u);
			return result;
		}
	}

	class Assignment_bt_par_test_static_property_as_left_value_and_param_node15 : behaviac.Assignment
	{
		public Assignment_bt_par_test_static_property_as_left_value_and_param_node15()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			int opr = (int)((ParTestAgent)pAgent).Func_Int32IR(ParTestAgent.STV_I32_0);
			AgentExtra_Generated.SetProperty(pAgent, "STV_I32_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("STV_I32_0") == 1924306853u);
			pAgent.SetVariable<int>("STV_I32_0", opr, 1924306853u);
			return result;
		}
	}

	class Assignment_bt_par_test_static_property_as_left_value_and_param_node12 : behaviac.Assignment
	{
		public Assignment_bt_par_test_static_property_as_left_value_and_param_node12()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			TNS.ST.PER.WRK.kEmployee opr = (TNS.ST.PER.WRK.kEmployee)((ParTestAgent)pAgent).Func_kEmployeeIR(ParTestAgent.STV_KEMPLOYEE_0);
			AgentExtra_Generated.SetProperty(pAgent, "STV_KEMPLOYEE_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("STV_KEMPLOYEE_0") == 197916387u);
			pAgent.SetVariable<TNS.ST.PER.WRK.kEmployee>("STV_KEMPLOYEE_0", opr, 197916387u);
			return result;
		}
	}

	class Assignment_bt_par_test_static_property_as_left_value_and_param_node13 : behaviac.Assignment
	{
		public Assignment_bt_par_test_static_property_as_left_value_and_param_node13()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			List<int> opr = (List<int>)((ParTestAgent)pAgent).Func_Int32ListIR(ParTestAgent.STV_LIST_I32_0);
			AgentExtra_Generated.SetProperty(pAgent, "STV_LIST_I32_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("STV_LIST_I32_0") == 1423343158u);
			pAgent.SetVariable<List<int>>("STV_LIST_I32_0", opr, 1423343158u);
			return result;
		}
	}

	class Assignment_bt_par_test_static_property_as_left_value_and_param_node11 : behaviac.Assignment
	{
		public Assignment_bt_par_test_static_property_as_left_value_and_param_node11()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			List<TNS.ST.PER.WRK.kEmployee> opr = (List<TNS.ST.PER.WRK.kEmployee>)((ParTestAgent)pAgent).Func_kEmployeeListIR(ParTestAgent.STV_LIST_KEMPLOYEE_0);
			AgentExtra_Generated.SetProperty(pAgent, "STV_LIST_KEMPLOYEE_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("STV_LIST_KEMPLOYEE_0") == 1924897476u);
			pAgent.SetVariable<List<TNS.ST.PER.WRK.kEmployee>>("STV_LIST_KEMPLOYEE_0", opr, 1924897476u);
			return result;
		}
	}

	class Assignment_bt_par_test_static_property_as_left_value_and_param_node14 : behaviac.Assignment
	{
		public Assignment_bt_par_test_static_property_as_left_value_and_param_node14()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			float opr = (float)((EmployeeParTestAgent)pAgent).Func_SingleIR(EmployeeParTestAgent.STV_F_0);
			AgentExtra_Generated.SetProperty(pAgent, "STV_F_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("STV_F_0") == 1858562011u);
			pAgent.SetVariable<float>("STV_F_0", opr, 1858562011u);
			return result;
		}
	}

	class Assignment_bt_par_test_static_property_as_left_value_and_param_node19 : behaviac.Assignment
	{
		public Assignment_bt_par_test_static_property_as_left_value_and_param_node19()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			string opr = (string)((EmployeeParTestAgent)pAgent).Func_StringIR(EmployeeParTestAgent.STV_STR_0);
			AgentExtra_Generated.SetProperty(pAgent, "STV_STR_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("STV_STR_0") == 3234589190u);
			pAgent.SetVariable<string>("STV_STR_0", opr, 3234589190u);
			return result;
		}
	}

	class Assignment_bt_par_test_static_property_as_left_value_and_param_node17 : behaviac.Assignment
	{
		public Assignment_bt_par_test_static_property_as_left_value_and_param_node17()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			behaviac.Agent opr = (behaviac.Agent)((EmployeeParTestAgent)pAgent).Func_AgentIR(EmployeeParTestAgent.STV_AGENT_0);
			AgentExtra_Generated.SetProperty(pAgent, "STV_AGENT_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("STV_AGENT_0") == 2845805842u);
			pAgent.SetVariable<behaviac.Agent>("STV_AGENT_0", opr, 2845805842u);
			return result;
		}
	}

	class Assignment_bt_par_test_static_property_as_left_value_and_param_node18 : behaviac.Assignment
	{
		public Assignment_bt_par_test_static_property_as_left_value_and_param_node18()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			List<float> opr = (List<float>)((EmployeeParTestAgent)pAgent).Func_SingleListIR(EmployeeParTestAgent.STV_LIST_F_0);
			AgentExtra_Generated.SetProperty(pAgent, "STV_LIST_F_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("STV_LIST_F_0") == 2648216995u);
			pAgent.SetVariable<List<float>>("STV_LIST_F_0", opr, 2648216995u);
			return result;
		}
	}

	class Assignment_bt_par_test_static_property_as_left_value_and_param_node16 : behaviac.Assignment
	{
		public Assignment_bt_par_test_static_property_as_left_value_and_param_node16()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			List<string> opr = (List<string>)((EmployeeParTestAgent)pAgent).Func_StringListIR(EmployeeParTestAgent.STV_LIST_STR_0);
			AgentExtra_Generated.SetProperty(pAgent, "STV_LIST_STR_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("STV_LIST_STR_0") == 3870229397u);
			pAgent.SetVariable<List<string>>("STV_LIST_STR_0", opr, 3870229397u);
			return result;
		}
	}

	class Assignment_bt_par_test_static_property_as_left_value_and_param_node20 : behaviac.Assignment
	{
		public Assignment_bt_par_test_static_property_as_left_value_and_param_node20()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			EBTStatus result = EBTStatus.BT_SUCCESS;
			List<behaviac.Agent> opr = (List<behaviac.Agent>)((EmployeeParTestAgent)pAgent).Func_AgentListIR(EmployeeParTestAgent.STV_LIST_AGENT_0);
			AgentExtra_Generated.SetProperty(pAgent, "STV_LIST_AGENT_0", opr);
			Debug.Check(behaviac.Utils.MakeVariableId("STV_LIST_AGENT_0") == 2769286938u);
			pAgent.SetVariable<List<behaviac.Agent>>("STV_LIST_AGENT_0", opr, 2769286938u);
			return result;
		}
	}

	public static class bt_par_test_static_property_as_left_value_and_param
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("par_test/static_property_as_left_value_and_param");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("EmployeeParTestAgent");
#endif
			// children
			{
				Sequence node0 = new Sequence();
				node0.SetClassNameString("Sequence");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("EmployeeParTestAgent");
#endif
				bt.AddChild(node0);
				{
					Sequence node1 = new Sequence();
					node1.SetClassNameString("Sequence");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("EmployeeParTestAgent");
#endif
					node0.AddChild(node1);
					{
						Assignment_bt_par_test_static_property_as_left_value_and_param_node4 node4 = new Assignment_bt_par_test_static_property_as_left_value_and_param_node4();
						node4.SetClassNameString("Assignment");
						node4.SetId(4);
#if !BEHAVIAC_RELEASE
						node4.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node4);
						node1.SetHasEvents(node1.HasEvents() | node4.HasEvents());
					}
					{
						Assignment_bt_par_test_static_property_as_left_value_and_param_node5 node5 = new Assignment_bt_par_test_static_property_as_left_value_and_param_node5();
						node5.SetClassNameString("Assignment");
						node5.SetId(5);
#if !BEHAVIAC_RELEASE
						node5.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node5);
						node1.SetHasEvents(node1.HasEvents() | node5.HasEvents());
					}
					{
						Assignment_bt_par_test_static_property_as_left_value_and_param_node6 node6 = new Assignment_bt_par_test_static_property_as_left_value_and_param_node6();
						node6.SetClassNameString("Assignment");
						node6.SetId(6);
#if !BEHAVIAC_RELEASE
						node6.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node6);
						node1.SetHasEvents(node1.HasEvents() | node6.HasEvents());
					}
					{
						Assignment_bt_par_test_static_property_as_left_value_and_param_node7 node7 = new Assignment_bt_par_test_static_property_as_left_value_and_param_node7();
						node7.SetClassNameString("Assignment");
						node7.SetId(7);
#if !BEHAVIAC_RELEASE
						node7.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node7);
						node1.SetHasEvents(node1.HasEvents() | node7.HasEvents());
					}
					{
						Assignment_bt_par_test_static_property_as_left_value_and_param_node8 node8 = new Assignment_bt_par_test_static_property_as_left_value_and_param_node8();
						node8.SetClassNameString("Assignment");
						node8.SetId(8);
#if !BEHAVIAC_RELEASE
						node8.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node8);
						node1.SetHasEvents(node1.HasEvents() | node8.HasEvents());
					}
					{
						Assignment_bt_par_test_static_property_as_left_value_and_param_node9 node9 = new Assignment_bt_par_test_static_property_as_left_value_and_param_node9();
						node9.SetClassNameString("Assignment");
						node9.SetId(9);
#if !BEHAVIAC_RELEASE
						node9.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node9);
						node1.SetHasEvents(node1.HasEvents() | node9.HasEvents());
					}
					{
						Assignment_bt_par_test_static_property_as_left_value_and_param_node10 node10 = new Assignment_bt_par_test_static_property_as_left_value_and_param_node10();
						node10.SetClassNameString("Assignment");
						node10.SetId(10);
#if !BEHAVIAC_RELEASE
						node10.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node10);
						node1.SetHasEvents(node1.HasEvents() | node10.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					Sequence node2 = new Sequence();
					node2.SetClassNameString("Sequence");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("EmployeeParTestAgent");
#endif
					node0.AddChild(node2);
					{
						Assignment_bt_par_test_static_property_as_left_value_and_param_node15 node15 = new Assignment_bt_par_test_static_property_as_left_value_and_param_node15();
						node15.SetClassNameString("Assignment");
						node15.SetId(15);
#if !BEHAVIAC_RELEASE
						node15.SetAgentType("EmployeeParTestAgent");
#endif
						node2.AddChild(node15);
						node2.SetHasEvents(node2.HasEvents() | node15.HasEvents());
					}
					{
						Assignment_bt_par_test_static_property_as_left_value_and_param_node12 node12 = new Assignment_bt_par_test_static_property_as_left_value_and_param_node12();
						node12.SetClassNameString("Assignment");
						node12.SetId(12);
#if !BEHAVIAC_RELEASE
						node12.SetAgentType("EmployeeParTestAgent");
#endif
						node2.AddChild(node12);
						node2.SetHasEvents(node2.HasEvents() | node12.HasEvents());
					}
					{
						Assignment_bt_par_test_static_property_as_left_value_and_param_node13 node13 = new Assignment_bt_par_test_static_property_as_left_value_and_param_node13();
						node13.SetClassNameString("Assignment");
						node13.SetId(13);
#if !BEHAVIAC_RELEASE
						node13.SetAgentType("EmployeeParTestAgent");
#endif
						node2.AddChild(node13);
						node2.SetHasEvents(node2.HasEvents() | node13.HasEvents());
					}
					{
						Assignment_bt_par_test_static_property_as_left_value_and_param_node11 node11 = new Assignment_bt_par_test_static_property_as_left_value_and_param_node11();
						node11.SetClassNameString("Assignment");
						node11.SetId(11);
#if !BEHAVIAC_RELEASE
						node11.SetAgentType("EmployeeParTestAgent");
#endif
						node2.AddChild(node11);
						node2.SetHasEvents(node2.HasEvents() | node11.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				{
					Sequence node3 = new Sequence();
					node3.SetClassNameString("Sequence");
					node3.SetId(3);
#if !BEHAVIAC_RELEASE
					node3.SetAgentType("EmployeeParTestAgent");
#endif
					node0.AddChild(node3);
					{
						Assignment_bt_par_test_static_property_as_left_value_and_param_node14 node14 = new Assignment_bt_par_test_static_property_as_left_value_and_param_node14();
						node14.SetClassNameString("Assignment");
						node14.SetId(14);
#if !BEHAVIAC_RELEASE
						node14.SetAgentType("EmployeeParTestAgent");
#endif
						node3.AddChild(node14);
						node3.SetHasEvents(node3.HasEvents() | node14.HasEvents());
					}
					{
						Assignment_bt_par_test_static_property_as_left_value_and_param_node19 node19 = new Assignment_bt_par_test_static_property_as_left_value_and_param_node19();
						node19.SetClassNameString("Assignment");
						node19.SetId(19);
#if !BEHAVIAC_RELEASE
						node19.SetAgentType("EmployeeParTestAgent");
#endif
						node3.AddChild(node19);
						node3.SetHasEvents(node3.HasEvents() | node19.HasEvents());
					}
					{
						Assignment_bt_par_test_static_property_as_left_value_and_param_node17 node17 = new Assignment_bt_par_test_static_property_as_left_value_and_param_node17();
						node17.SetClassNameString("Assignment");
						node17.SetId(17);
#if !BEHAVIAC_RELEASE
						node17.SetAgentType("EmployeeParTestAgent");
#endif
						node3.AddChild(node17);
						node3.SetHasEvents(node3.HasEvents() | node17.HasEvents());
					}
					{
						Assignment_bt_par_test_static_property_as_left_value_and_param_node18 node18 = new Assignment_bt_par_test_static_property_as_left_value_and_param_node18();
						node18.SetClassNameString("Assignment");
						node18.SetId(18);
#if !BEHAVIAC_RELEASE
						node18.SetAgentType("EmployeeParTestAgent");
#endif
						node3.AddChild(node18);
						node3.SetHasEvents(node3.HasEvents() | node18.HasEvents());
					}
					{
						Assignment_bt_par_test_static_property_as_left_value_and_param_node16 node16 = new Assignment_bt_par_test_static_property_as_left_value_and_param_node16();
						node16.SetClassNameString("Assignment");
						node16.SetId(16);
#if !BEHAVIAC_RELEASE
						node16.SetAgentType("EmployeeParTestAgent");
#endif
						node3.AddChild(node16);
						node3.SetHasEvents(node3.HasEvents() | node16.HasEvents());
					}
					{
						Assignment_bt_par_test_static_property_as_left_value_and_param_node20 node20 = new Assignment_bt_par_test_static_property_as_left_value_and_param_node20();
						node20.SetClassNameString("Assignment");
						node20.SetId(20);
#if !BEHAVIAC_RELEASE
						node20.SetAgentType("EmployeeParTestAgent");
#endif
						node3.AddChild(node20);
						node3.SetHasEvents(node3.HasEvents() | node20.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node3.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

	// Source file: par_test/static_property_as_ref_param

	class Action_bt_par_test_static_property_as_ref_param_node4 : behaviac.Action
	{
		public Action_bt_par_test_static_property_as_ref_param_node4()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((ParTestAgentBase)pAgent).Func_eColorRef(ref ParTestAgentBase.STV_ECOLOR_0);
			Debug.Check(behaviac.Utils.MakeVariableId("STV_ECOLOR_0") == 1356537398u);
			pAgent.SetVariable<TNS.NE.NAT.eColor>("STV_ECOLOR_0", ParTestAgentBase.STV_ECOLOR_0, 1356537398u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_static_property_as_ref_param_node5 : behaviac.Action
	{
		public Action_bt_par_test_static_property_as_ref_param_node5()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((ParTestAgentBase)pAgent).Func_BooleanRef(ref ParTestAgentBase.STV_BOOL_0);
			Debug.Check(behaviac.Utils.MakeVariableId("STV_BOOL_0") == 907888646u);
			pAgent.SetVariable<bool>("STV_BOOL_0", ParTestAgentBase.STV_BOOL_0, 907888646u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_static_property_as_ref_param_node6 : behaviac.Action
	{
		public Action_bt_par_test_static_property_as_ref_param_node6()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((ParTestAgentBase)pAgent).Func_CharRef(ref ParTestAgentBase.STV_CHAR_0);
			Debug.Check(behaviac.Utils.MakeVariableId("STV_CHAR_0") == 2191125959u);
			pAgent.SetVariable<char>("STV_CHAR_0", ParTestAgentBase.STV_CHAR_0, 2191125959u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_static_property_as_ref_param_node7 : behaviac.Action
	{
		public Action_bt_par_test_static_property_as_ref_param_node7()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((ParTestAgentBase)pAgent).Func_eColorListRef(ref ParTestAgentBase.STV_LIST_ECOLOR_0);
			Debug.Check(behaviac.Utils.MakeVariableId("STV_LIST_ECOLOR_0") == 2487001405u);
			pAgent.SetVariable<List<TNS.NE.NAT.eColor>>("STV_LIST_ECOLOR_0", ParTestAgentBase.STV_LIST_ECOLOR_0, 2487001405u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_static_property_as_ref_param_node8 : behaviac.Action
	{
		public Action_bt_par_test_static_property_as_ref_param_node8()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((ParTestAgentBase)pAgent).Func_BooleanListRef(ref ParTestAgentBase.STV_LIST_BOOL_0);
			Debug.Check(behaviac.Utils.MakeVariableId("STV_LIST_BOOL_0") == 1612090457u);
			pAgent.SetVariable<List<bool>>("STV_LIST_BOOL_0", ParTestAgentBase.STV_LIST_BOOL_0, 1612090457u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_static_property_as_ref_param_node9 : behaviac.Action
	{
		public Action_bt_par_test_static_property_as_ref_param_node9()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((ParTestAgentBase)pAgent).Func_CharListRef(ref ParTestAgentBase.STV_LIST_CHAR_0);
			Debug.Check(behaviac.Utils.MakeVariableId("STV_LIST_CHAR_0") == 3566348696u);
			pAgent.SetVariable<List<char>>("STV_LIST_CHAR_0", ParTestAgentBase.STV_LIST_CHAR_0, 3566348696u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_static_property_as_ref_param_node10 : behaviac.Action
	{
		public Action_bt_par_test_static_property_as_ref_param_node10()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((ParTestAgentBase)pAgent).Func_SByteListRef(ref ParTestAgentBase.STV_LIST_SBYTE_0);
			Debug.Check(behaviac.Utils.MakeVariableId("STV_LIST_SBYTE_0") == 2135462866u);
			pAgent.SetVariable<List<sbyte>>("STV_LIST_SBYTE_0", ParTestAgentBase.STV_LIST_SBYTE_0, 2135462866u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_static_property_as_ref_param_node15 : behaviac.Action
	{
		public Action_bt_par_test_static_property_as_ref_param_node15()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((ParTestAgent)pAgent).Func_Int32Ref(ref ParTestAgent.STV_I32_0);
			Debug.Check(behaviac.Utils.MakeVariableId("STV_I32_0") == 1924306853u);
			pAgent.SetVariable<int>("STV_I32_0", ParTestAgent.STV_I32_0, 1924306853u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_static_property_as_ref_param_node12 : behaviac.Action
	{
		public Action_bt_par_test_static_property_as_ref_param_node12()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((ParTestAgent)pAgent).Func_kEmployeeRef(ref ParTestAgent.STV_KEMPLOYEE_0);
			Debug.Check(behaviac.Utils.MakeVariableId("STV_KEMPLOYEE_0") == 197916387u);
			pAgent.SetVariable<TNS.ST.PER.WRK.kEmployee>("STV_KEMPLOYEE_0", ParTestAgent.STV_KEMPLOYEE_0, 197916387u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_static_property_as_ref_param_node13 : behaviac.Action
	{
		public Action_bt_par_test_static_property_as_ref_param_node13()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((ParTestAgent)pAgent).Func_Int32ListRef(ref ParTestAgent.STV_LIST_I32_0);
			Debug.Check(behaviac.Utils.MakeVariableId("STV_LIST_I32_0") == 1423343158u);
			pAgent.SetVariable<List<int>>("STV_LIST_I32_0", ParTestAgent.STV_LIST_I32_0, 1423343158u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_static_property_as_ref_param_node11 : behaviac.Action
	{
		public Action_bt_par_test_static_property_as_ref_param_node11()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((ParTestAgent)pAgent).Func_kEmployeeListRef(ref ParTestAgent.STV_LIST_KEMPLOYEE_0);
			Debug.Check(behaviac.Utils.MakeVariableId("STV_LIST_KEMPLOYEE_0") == 1924897476u);
			pAgent.SetVariable<List<TNS.ST.PER.WRK.kEmployee>>("STV_LIST_KEMPLOYEE_0", ParTestAgent.STV_LIST_KEMPLOYEE_0, 1924897476u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_static_property_as_ref_param_node14 : behaviac.Action
	{
		public Action_bt_par_test_static_property_as_ref_param_node14()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((EmployeeParTestAgent)pAgent).Func_SingleRef(ref EmployeeParTestAgent.STV_F_0);
			Debug.Check(behaviac.Utils.MakeVariableId("STV_F_0") == 1858562011u);
			pAgent.SetVariable<float>("STV_F_0", EmployeeParTestAgent.STV_F_0, 1858562011u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_static_property_as_ref_param_node16 : behaviac.Action
	{
		public Action_bt_par_test_static_property_as_ref_param_node16()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((EmployeeParTestAgent)pAgent).Func_StringRef(ref EmployeeParTestAgent.STV_STR_0);
			Debug.Check(behaviac.Utils.MakeVariableId("STV_STR_0") == 3234589190u);
			pAgent.SetVariable<string>("STV_STR_0", EmployeeParTestAgent.STV_STR_0, 3234589190u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_static_property_as_ref_param_node17 : behaviac.Action
	{
		public Action_bt_par_test_static_property_as_ref_param_node17()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((EmployeeParTestAgent)pAgent).Func_AgentRef(ref EmployeeParTestAgent.STV_AGENT_0);
			Debug.Check(behaviac.Utils.MakeVariableId("STV_AGENT_0") == 2845805842u);
			pAgent.SetVariable<behaviac.Agent>("STV_AGENT_0", EmployeeParTestAgent.STV_AGENT_0, 2845805842u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_static_property_as_ref_param_node18 : behaviac.Action
	{
		public Action_bt_par_test_static_property_as_ref_param_node18()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((EmployeeParTestAgent)pAgent).Func_SingleListRef(ref EmployeeParTestAgent.STV_LIST_F_0);
			Debug.Check(behaviac.Utils.MakeVariableId("STV_LIST_F_0") == 2648216995u);
			pAgent.SetVariable<List<float>>("STV_LIST_F_0", EmployeeParTestAgent.STV_LIST_F_0, 2648216995u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_static_property_as_ref_param_node19 : behaviac.Action
	{
		public Action_bt_par_test_static_property_as_ref_param_node19()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((EmployeeParTestAgent)pAgent).Func_StringListRef(ref EmployeeParTestAgent.STV_LIST_STR_0);
			Debug.Check(behaviac.Utils.MakeVariableId("STV_LIST_STR_0") == 3870229397u);
			pAgent.SetVariable<List<string>>("STV_LIST_STR_0", EmployeeParTestAgent.STV_LIST_STR_0, 3870229397u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	class Action_bt_par_test_static_property_as_ref_param_node20 : behaviac.Action
	{
		public Action_bt_par_test_static_property_as_ref_param_node20()
		{
		}
		protected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)
		{
			((EmployeeParTestAgent)pAgent).Func_AgentListRef(ref EmployeeParTestAgent.STV_LIST_AGENT_0);
			Debug.Check(behaviac.Utils.MakeVariableId("STV_LIST_AGENT_0") == 2769286938u);
			pAgent.SetVariable<List<behaviac.Agent>>("STV_LIST_AGENT_0", EmployeeParTestAgent.STV_LIST_AGENT_0, 2769286938u);
			return EBTStatus.BT_SUCCESS;
		}
	}

	public static class bt_par_test_static_property_as_ref_param
	{
		public static bool build_behavior_tree(BehaviorTree bt)
		{
			bt.SetClassNameString("BehaviorTree");
			bt.SetId(-1);
			bt.SetName("par_test/static_property_as_ref_param");
#if !BEHAVIAC_RELEASE
			bt.SetAgentType("EmployeeParTestAgent");
#endif
			// children
			{
				Sequence node0 = new Sequence();
				node0.SetClassNameString("Sequence");
				node0.SetId(0);
#if !BEHAVIAC_RELEASE
				node0.SetAgentType("EmployeeParTestAgent");
#endif
				bt.AddChild(node0);
				{
					Sequence node1 = new Sequence();
					node1.SetClassNameString("Sequence");
					node1.SetId(1);
#if !BEHAVIAC_RELEASE
					node1.SetAgentType("EmployeeParTestAgent");
#endif
					node0.AddChild(node1);
					{
						Action_bt_par_test_static_property_as_ref_param_node4 node4 = new Action_bt_par_test_static_property_as_ref_param_node4();
						node4.SetClassNameString("Action");
						node4.SetId(4);
#if !BEHAVIAC_RELEASE
						node4.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node4);
						node1.SetHasEvents(node1.HasEvents() | node4.HasEvents());
					}
					{
						Action_bt_par_test_static_property_as_ref_param_node5 node5 = new Action_bt_par_test_static_property_as_ref_param_node5();
						node5.SetClassNameString("Action");
						node5.SetId(5);
#if !BEHAVIAC_RELEASE
						node5.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node5);
						node1.SetHasEvents(node1.HasEvents() | node5.HasEvents());
					}
					{
						Action_bt_par_test_static_property_as_ref_param_node6 node6 = new Action_bt_par_test_static_property_as_ref_param_node6();
						node6.SetClassNameString("Action");
						node6.SetId(6);
#if !BEHAVIAC_RELEASE
						node6.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node6);
						node1.SetHasEvents(node1.HasEvents() | node6.HasEvents());
					}
					{
						Action_bt_par_test_static_property_as_ref_param_node7 node7 = new Action_bt_par_test_static_property_as_ref_param_node7();
						node7.SetClassNameString("Action");
						node7.SetId(7);
#if !BEHAVIAC_RELEASE
						node7.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node7);
						node1.SetHasEvents(node1.HasEvents() | node7.HasEvents());
					}
					{
						Action_bt_par_test_static_property_as_ref_param_node8 node8 = new Action_bt_par_test_static_property_as_ref_param_node8();
						node8.SetClassNameString("Action");
						node8.SetId(8);
#if !BEHAVIAC_RELEASE
						node8.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node8);
						node1.SetHasEvents(node1.HasEvents() | node8.HasEvents());
					}
					{
						Action_bt_par_test_static_property_as_ref_param_node9 node9 = new Action_bt_par_test_static_property_as_ref_param_node9();
						node9.SetClassNameString("Action");
						node9.SetId(9);
#if !BEHAVIAC_RELEASE
						node9.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node9);
						node1.SetHasEvents(node1.HasEvents() | node9.HasEvents());
					}
					{
						Action_bt_par_test_static_property_as_ref_param_node10 node10 = new Action_bt_par_test_static_property_as_ref_param_node10();
						node10.SetClassNameString("Action");
						node10.SetId(10);
#if !BEHAVIAC_RELEASE
						node10.SetAgentType("EmployeeParTestAgent");
#endif
						node1.AddChild(node10);
						node1.SetHasEvents(node1.HasEvents() | node10.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node1.HasEvents());
				}
				{
					Sequence node2 = new Sequence();
					node2.SetClassNameString("Sequence");
					node2.SetId(2);
#if !BEHAVIAC_RELEASE
					node2.SetAgentType("EmployeeParTestAgent");
#endif
					node0.AddChild(node2);
					{
						Action_bt_par_test_static_property_as_ref_param_node15 node15 = new Action_bt_par_test_static_property_as_ref_param_node15();
						node15.SetClassNameString("Action");
						node15.SetId(15);
#if !BEHAVIAC_RELEASE
						node15.SetAgentType("EmployeeParTestAgent");
#endif
						node2.AddChild(node15);
						node2.SetHasEvents(node2.HasEvents() | node15.HasEvents());
					}
					{
						Action_bt_par_test_static_property_as_ref_param_node12 node12 = new Action_bt_par_test_static_property_as_ref_param_node12();
						node12.SetClassNameString("Action");
						node12.SetId(12);
#if !BEHAVIAC_RELEASE
						node12.SetAgentType("EmployeeParTestAgent");
#endif
						node2.AddChild(node12);
						node2.SetHasEvents(node2.HasEvents() | node12.HasEvents());
					}
					{
						Action_bt_par_test_static_property_as_ref_param_node13 node13 = new Action_bt_par_test_static_property_as_ref_param_node13();
						node13.SetClassNameString("Action");
						node13.SetId(13);
#if !BEHAVIAC_RELEASE
						node13.SetAgentType("EmployeeParTestAgent");
#endif
						node2.AddChild(node13);
						node2.SetHasEvents(node2.HasEvents() | node13.HasEvents());
					}
					{
						Action_bt_par_test_static_property_as_ref_param_node11 node11 = new Action_bt_par_test_static_property_as_ref_param_node11();
						node11.SetClassNameString("Action");
						node11.SetId(11);
#if !BEHAVIAC_RELEASE
						node11.SetAgentType("EmployeeParTestAgent");
#endif
						node2.AddChild(node11);
						node2.SetHasEvents(node2.HasEvents() | node11.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node2.HasEvents());
				}
				{
					Sequence node3 = new Sequence();
					node3.SetClassNameString("Sequence");
					node3.SetId(3);
#if !BEHAVIAC_RELEASE
					node3.SetAgentType("EmployeeParTestAgent");
#endif
					node0.AddChild(node3);
					{
						Action_bt_par_test_static_property_as_ref_param_node14 node14 = new Action_bt_par_test_static_property_as_ref_param_node14();
						node14.SetClassNameString("Action");
						node14.SetId(14);
#if !BEHAVIAC_RELEASE
						node14.SetAgentType("EmployeeParTestAgent");
#endif
						node3.AddChild(node14);
						node3.SetHasEvents(node3.HasEvents() | node14.HasEvents());
					}
					{
						Action_bt_par_test_static_property_as_ref_param_node16 node16 = new Action_bt_par_test_static_property_as_ref_param_node16();
						node16.SetClassNameString("Action");
						node16.SetId(16);
#if !BEHAVIAC_RELEASE
						node16.SetAgentType("EmployeeParTestAgent");
#endif
						node3.AddChild(node16);
						node3.SetHasEvents(node3.HasEvents() | node16.HasEvents());
					}
					{
						Action_bt_par_test_static_property_as_ref_param_node17 node17 = new Action_bt_par_test_static_property_as_ref_param_node17();
						node17.SetClassNameString("Action");
						node17.SetId(17);
#if !BEHAVIAC_RELEASE
						node17.SetAgentType("EmployeeParTestAgent");
#endif
						node3.AddChild(node17);
						node3.SetHasEvents(node3.HasEvents() | node17.HasEvents());
					}
					{
						Action_bt_par_test_static_property_as_ref_param_node18 node18 = new Action_bt_par_test_static_property_as_ref_param_node18();
						node18.SetClassNameString("Action");
						node18.SetId(18);
#if !BEHAVIAC_RELEASE
						node18.SetAgentType("EmployeeParTestAgent");
#endif
						node3.AddChild(node18);
						node3.SetHasEvents(node3.HasEvents() | node18.HasEvents());
					}
					{
						Action_bt_par_test_static_property_as_ref_param_node19 node19 = new Action_bt_par_test_static_property_as_ref_param_node19();
						node19.SetClassNameString("Action");
						node19.SetId(19);
#if !BEHAVIAC_RELEASE
						node19.SetAgentType("EmployeeParTestAgent");
#endif
						node3.AddChild(node19);
						node3.SetHasEvents(node3.HasEvents() | node19.HasEvents());
					}
					{
						Action_bt_par_test_static_property_as_ref_param_node20 node20 = new Action_bt_par_test_static_property_as_ref_param_node20();
						node20.SetClassNameString("Action");
						node20.SetId(20);
#if !BEHAVIAC_RELEASE
						node20.SetAgentType("EmployeeParTestAgent");
#endif
						node3.AddChild(node20);
						node3.SetHasEvents(node3.HasEvents() | node20.HasEvents());
					}
					node0.SetHasEvents(node0.HasEvents() | node3.HasEvents());
				}
				bt.SetHasEvents(bt.HasEvents() | node0.HasEvents());
			}
			return true;
		}
	}

}
