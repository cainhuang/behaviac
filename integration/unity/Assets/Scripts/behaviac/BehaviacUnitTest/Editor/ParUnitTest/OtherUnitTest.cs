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

using System;
using System.Threading;
using NUnit.Framework;
using UnityEngine;

namespace BehaviorOtherUnitTest
{
	[TestFixture]
	[Category ("OtherUnitTest")]
	internal class OtherUnitTest
	{
		EmployeeParTestAgent parTestAgent = null;
		AgentNodeTest nodeTestAgent = null;

//		AgentNodeTest nodeTestAgent_0 = null;
//		ParTestAgent parTestAgent_0 = null;
//		ParTestAgent parTestAgent_1 = null;
//		ParTestAgent parTestAgent_2 = null;
		
		[TestFixtureSetUp]  
		public void initGlobalTestEnv()  
		{
			BehaviacSystem.Instance.init();

			GameObject testAgentObject = new GameObject();
			testAgentObject.name = "@Agent_0";
			testAgentObject.transform.localPosition = Vector3.zero;
			testAgentObject.transform.localRotation = Quaternion.identity;
			testAgentObject.transform.localScale = Vector3.one;
			parTestAgent = testAgentObject.AddComponent<EmployeeParTestAgent>();			
			parTestAgent.init();

			testAgentObject = new GameObject();
			testAgentObject.name = "@NodeTestAgent_1";
			testAgentObject.transform.localPosition = Vector3.zero;
			testAgentObject.transform.localRotation = Quaternion.identity;
			testAgentObject.transform.localScale = Vector3.one;
			nodeTestAgent = testAgentObject.AddComponent<AgentNodeTest>();			
			nodeTestAgent.init();
			
//			testAgentObject = new GameObject();
//			testAgentObject.name = "@NodeTestAgent_0";
//			testAgentObject.transform.localPosition = Vector3.zero;
//			testAgentObject.transform.localRotation = Quaternion.identity;
//			testAgentObject.transform.localScale = Vector3.one;
//			nodeTestAgent_0 = testAgentObject.AddComponent<AgentNodeTest>();			
//			nodeTestAgent_0.init();
//
//			testAgentObject = new GameObject();
//			testAgentObject.name = "@ParTestAgent_0";
//			testAgentObject.transform.localPosition = Vector3.zero;
//			testAgentObject.transform.localRotation = Quaternion.identity;
//			testAgentObject.transform.localScale = Vector3.one;
//			parTestAgent_0 = testAgentObject.AddComponent<ParTestAgent>();			
//			parTestAgent_0.initAgent();
//
//			testAgentObject = new GameObject();
//			testAgentObject.name = "@ParTestAgent_1";
//			testAgentObject.transform.localPosition = Vector3.zero;
//			testAgentObject.transform.localRotation = Quaternion.identity;
//			testAgentObject.transform.localScale = Vector3.one;
//			parTestAgent_1 = testAgentObject.AddComponent<ParTestAgent>();			
//			parTestAgent_1.initAgent();
//
//			testAgentObject = new GameObject();
//			testAgentObject.name = "@ParTestAgent_2";
//			testAgentObject.transform.localPosition = Vector3.zero;
//			testAgentObject.transform.localRotation = Quaternion.identity;
//			testAgentObject.transform.localScale = Vector3.one;
//			parTestAgent_2 = testAgentObject.AddComponent<ParTestAgent>();			
//			parTestAgent_2.initAgent();
		}
		
		[TestFixtureTearDown]  
		public void finlGlobalTestEnv()  
		{
			nodeTestAgent.finl();
			parTestAgent.finl();

//			nodeTestAgent_0.finl();
//
//			parTestAgent_2.finlAgent();
//			parTestAgent_1.finlAgent();	
//			parTestAgent_0.finlAgent();	
			BehaviacSystem.Instance.finl();
		}
		
		[SetUp]  
		public void initTestEnv()  
		{
		}
		
		[TearDown]  
		public void finlTestEnv()  
		{
			behaviac.Workspace.UnLoadAll();
		}
		
		[Test]
		[Category ("test_agent_instance")]
		public void test_agent_instance ()
		{
			behaviac.Agent.RegisterName<AgentNodeTest>();
			behaviac.Agent.RegisterName<behaviac.Agent>("Name_Agent_0");
			behaviac.Agent.RegisterName<behaviac.Agent>("Name_Agent_1");
			behaviac.Agent.RegisterName<behaviac.Agent>("Name_Agent_2");
			
			//behaviac.Agent testAgentA = behaviac.Agent.CreateInstance<behaviac.Agent>("Name_Agent_0");
			//AgentNodeTest testAgentB = behaviac.Agent.CreateInstance<AgentNodeTest>(NULL);

			behaviac.Agent.BindInstance(parTestAgent, "Name_Agent_0");
			behaviac.Agent.BindInstance(nodeTestAgent, "AgentNodeTest");
			
			behaviac.Agent testAgent_0 = behaviac.Agent.GetInstance<behaviac.Agent>("Name_Agent_0");
			AgentNodeTest testAgent_1 = behaviac.Agent.GetInstance<AgentNodeTest>();
			AgentNodeTest testAgent_3 = behaviac.Agent.GetAgent("AgentNodeTest") as AgentNodeTest;
			
			Assert.AreEqual(testAgent_0, parTestAgent);
			Assert.AreEqual(testAgent_1, nodeTestAgent);
			Assert.AreEqual(testAgent_1, testAgent_3);
			Assert.NotNull(testAgent_0);
			Assert.NotNull(testAgent_1);
			
			behaviac.Agent.UnbindInstance("Name_Agent_0");
			behaviac.Agent.UnbindInstance("AgentNodeTest");

			testAgent_3 = behaviac.Agent.GetAgent("AgentNodeTest#@NodeTestAgent_1") as AgentNodeTest;
			Assert.AreEqual(nodeTestAgent, testAgent_3);
			
			behaviac.Agent testAgent_0_0 = behaviac.Agent.GetInstance<behaviac.Agent>("Name_Agent_0");
			AgentNodeTest testAgent_1_0 = behaviac.Agent.GetInstance<AgentNodeTest>();
			
			Assert.Null(testAgent_0_0);
			Assert.Null(testAgent_1_0);
			
			behaviac.Agent.BindInstance(testAgent_0, "Name_Agent_1");
			behaviac.Agent testAgent_0_1 = behaviac.Agent.GetInstance<behaviac.Agent>("Name_Agent_1");
			Assert.NotNull(testAgent_0_1);

			behaviac.Agent.BindInstance(testAgent_0, "Name_Agent_2");
			behaviac.Agent testAgent_0_2 = behaviac.Agent.GetInstance<behaviac.Agent>("Name_Agent_2");
			Assert.NotNull(testAgent_0_2);

			Assert.AreEqual(testAgent_0_1, testAgent_0_2);
			
			behaviac.Agent.UnbindInstance("Name_Agent_1");
			behaviac.Agent.UnbindInstance("Name_Agent_2");	
			
			//behaviac.Agent.DestroyInstance<behaviac.Agent>("Name_Agent_0");
			//behaviac.Agent.DestroyInstance<AgentNodeTest>();
			
			behaviac.Agent.UnRegisterName<behaviac.Agent>("Name_Agent_2");
			behaviac.Agent.UnRegisterName<behaviac.Agent>("Name_Agent_1");
			behaviac.Agent.UnRegisterName<behaviac.Agent>("Name_Agent_0");
			behaviac.Agent.UnRegisterName<AgentNodeTest>();
		}

//		[Test]
//		[Category ("test_behaviac_context")]
//		public void test_behaviac_context ()
//		{
//			EmployeeParTestAgent.clearAllStaticMemberVariables();
//
//			behaviac.Agent.RegisterName<ParTestAgent>("ParTestAgent");
//
//			//base.Init();			
//			//Agent.RegisterName<ParTestRegNameAgent>();
//			//Agent.BindInstance(this);
//
//			//ParTestAgent testAgent_0 = behaviac.Agent.CreateInstance<ParTestAgent>(0, 1);
//			//ParTestAgent testAgent_1 = behaviac.Agent.CreateInstance<ParTestAgent>(0, 2);
//			//ParTestAgent testAgent_2 = behaviac.Agent.CreateInstance<ParTestAgent>(0, 3);
//
//			ParTestAgent testAgent_0 = parTestAgent_0;
//			ParTestAgent testAgent_1 = parTestAgent_1;
//			ParTestAgent testAgent_2 = parTestAgent_2;
//			behaviac.Agent.BindInstance(testAgent_0, "ParTestAgent", 1);
//			behaviac.Agent.BindInstance(testAgent_1, "ParTestAgent", 2);
//			behaviac.Agent.BindInstance(testAgent_2, "ParTestAgent", 3);
//			
//			Assert.AreNotEqual(testAgent_0, testAgent_1);
//			Assert.AreNotEqual(testAgent_1, testAgent_2);
//			Assert.AreNotEqual(testAgent_2, testAgent_0);
//			
//			testAgent_0.resetProperties();
//			testAgent_1.resetProperties();
//			testAgent_2.resetProperties();
//			
//			testAgent_0.TV_BOOL_0 = true;
//			Assert.AreEqual(true, testAgent_0.TV_BOOL_0);
//			Assert.AreEqual(false, testAgent_1.TV_BOOL_0);
//			Assert.AreEqual(false, testAgent_2.TV_BOOL_0);
//			
//			testAgent_1.TV_BOOL_0 = true;
//			Assert.AreEqual(true, testAgent_0.TV_BOOL_0);
//			Assert.AreEqual(true, testAgent_1.TV_BOOL_0);
//			Assert.AreEqual(false, testAgent_2.TV_BOOL_0);
//			
//			testAgent_2.TV_BOOL_0 = true;
//			Assert.AreEqual(true, testAgent_0.TV_BOOL_0);
//			Assert.AreEqual(true, testAgent_1.TV_BOOL_0);
//			Assert.AreEqual(true, testAgent_1.TV_BOOL_0);
//			
////			behaviac.Agent.DestroyInstance<ParTestAgent>(0, 3);
////			behaviac.Agent.DestroyInstance<ParTestAgent>(0, 2);
////			behaviac.Agent.DestroyInstance<ParTestAgent>(0, 1);
//			
//			behaviac.Context.Cleanup(1);
//			behaviac.Context.Cleanup(2);
//			behaviac.Context.Cleanup(3);
//			
//			behaviac.Agent.UnRegisterName<ParTestAgent>("ParTestAgent");
//		}
//
//		[Test]
//		[Category ("test_agent_invoke")]
//		public void test_agent_invoke ()
//		{
//			EmployeeParTestAgent.clearAllStaticMemberVariables();
//
//			behaviac.Agent testAgent = nodeTestAgent_0;
//			AgentNodeTest nodeTestAgent = nodeTestAgent_0;
//			
//			//Assert.AreEqual(true, behaviac.Agent.Invoke(testAgent, "AgentNodeTest.setTestVar_0", 999));
//			Assert.AreEqual(999, nodeTestAgent.testVar_0);
//			
//			//Assert.AreEqual(true, behaviac.Agent.Invoke(testAgent, "AgentNodeTest.setTestVar_0_2", 8999, 1000.99f));
//			Assert.AreEqual(8999, nodeTestAgent.testVar_0);
//			Assert.AreEqual(1000.99f, nodeTestAgent.testVar_2);
//
//			//behaviac.Agent.Destory(testAgent);
//		}
	}
}
