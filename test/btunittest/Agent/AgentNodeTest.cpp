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

#include "AgentNodeTest.h"


BEHAVIAC_BEGIN_ENUM(EnumTest, EnumTest)
{
	BEHAVIAC_ENUM_ITEM(EnumTest_One, "EnumTest_One");
	BEHAVIAC_ENUM_ITEM(EnumTest_OneAfterOne, "EnumTest_OneAfterOne");
}
BEHAVIAC_END_ENUM()

AgentNodeTest::AgentNodeTest()
{
}

AgentNodeTest::~AgentNodeTest()
{
}

void AgentNodeTest::resetProperties()
{
    testVar_0 = -1;
    testVar_1 = -1;
    testVar_2 = -1.0f;
    testVar_3 = -1.0f;
    event_test_var_int = -1;
    event_test_var_bool = false;
    event_test_var_float = -1.0f;
	event_test_var_agent = NULL;
    waiting_timeout_interval = 0;

    action_0_enter_count = 0;
    action_0_exit_count = 0;
    action_1_enter_count = 0;
    action_1_exit_count = 0;
    action_2_enter_count = 0;
    action_2_exit_count = 0;

    testVar_str_0 = "";
	testColor = EnumTest_One;

	m_bCanSee = false;
	m_bTargetValid = false;

	TestFloat2.x = 2.0f;
	TestFloat2.y = 2.0f;
}

namespace UnityEngine
{
    BEHAVIAC_BEGIN_PROPERTIES(GameObject)
    {
        BEHAVIAC_REGISTER_PROPERTY(name);
    }
    BEHAVIAC_END_PROPERTIES()
}

BEHAVIAC_BEGIN_PROPERTIES(AgentNodeTest)
{
    //BEHAVIAC_CLASS_DISPLAYNAME(L"²âÊÔbehaviac::Agent")
    //BEHAVIAC_CLASS_DESC(L"²âÊÔbehaviac::AgentµÄËµÃ÷")
    BEHAVIAC_REGISTER_PROPERTY(testVar_0);
    BEHAVIAC_REGISTER_PROPERTY(testVar_1).DISPLAYNAME(L"testVar_1").DESC(L"testVar_1 property").RANGE(100);
    BEHAVIAC_REGISTER_PROPERTY(testVar_2);
    BEHAVIAC_REGISTER_PROPERTY(testVar_3);
    BEHAVIAC_REGISTER_PROPERTY(waiting_timeout_interval);
    BEHAVIAC_REGISTER_PROPERTY(testVar_str_0);
	BEHAVIAC_REGISTER_PROPERTY(testColor);

    BEHAVIAC_REGISTER_METHOD(setEventVarInt);
    BEHAVIAC_REGISTER_METHOD(setEventVarBool);
    BEHAVIAC_REGISTER_METHOD(setEventVarFloat);
    BEHAVIAC_REGISTER_METHOD(setEventVarAgent);
	BEHAVIAC_REGISTER_METHOD(getConstOne);
	BEHAVIAC_REGISTER_METHOD(getConstThousand);
    BEHAVIAC_REGISTER_METHOD(setTestVar_0);
    BEHAVIAC_REGISTER_METHOD(setTestVar_1);
    BEHAVIAC_REGISTER_METHOD(setTestVar_2);
    BEHAVIAC_REGISTER_METHOD(setTestVar_0_2);
    BEHAVIAC_REGISTER_METHOD(setTestVar_R);
    BEHAVIAC_REGISTER_METHOD(setTestVar_3);
    BEHAVIAC_REGISTER_METHOD(enter_action_0);
    BEHAVIAC_REGISTER_METHOD(exit_action_0);
    BEHAVIAC_REGISTER_METHOD(enter_action_1);
    BEHAVIAC_REGISTER_METHOD(exit_action_1);
    BEHAVIAC_REGISTER_METHOD(enter_action_2);
    BEHAVIAC_REGISTER_METHOD(exit_action_2);
    BEHAVIAC_REGISTER_METHOD(createGameObject);
    BEHAVIAC_REGISTER_METHOD(testGameObject);
	BEHAVIAC_REGISTER_METHOD(createExtendedNode);
	BEHAVIAC_REGISTER_METHOD(testExtendedRefType);
	BEHAVIAC_REGISTER_METHOD(testExtendedStruct);
	BEHAVIAC_REGISTER_METHOD(getExtendedStruct);
	BEHAVIAC_REGISTER_METHOD(getConstExtendedStruct);
    BEHAVIAC_REGISTER_METHOD(switchRef);

	BEHAVIAC_REGISTER_METHOD(Stop);
	BEHAVIAC_REGISTER_METHOD(SelectTarget);

	BEHAVIAC_REGISTER_METHOD(IsTargetValid);
	BEHAVIAC_REGISTER_METHOD(CanSeeEnemy);
	BEHAVIAC_REGISTER_METHOD(Move);
	BEHAVIAC_REGISTER_METHOD(MoveToTarget);
	BEHAVIAC_REGISTER_METHOD(GetRefTree);
	BEHAVIAC_REGISTER_METHOD(initChildAgent);
	BEHAVIAC_REGISTER_METHOD(initChildAgentTest);

	BEHAVIAC_REGISTER_METHOD(testVectorStruct);
}
BEHAVIAC_END_PROPERTIES()

void AgentNodeTest::initChildAgentTest()
{
	ChildNodeTest* testChildAgent = this->getChildAgent<ChildNodeTest>(1, "par_child_agent_1");
	this->SetVariable("par_child_agent_1", testChildAgent);
}

void AgentNodeTest::initChildAgent()
{
    ChildNodeTest* test = this->GetVariable<ChildNodeTest*>("par_child_agent_1");

    test->resetProperties();
    test->testVar_1 = 888;
}

ChildNodeTest::ChildNodeTest(int var_0)
{
	testVar_0 = var_0;
}

ChildNodeTest::~ChildNodeTest()
{
}

float ChildNodeTest::GetConstFloatValue()
{
	return 1000.0f;
}

double ChildNodeTest::GetConstDoubleValue()
{
	return 1000.0;
}

BEHAVIAC_BEGIN_PROPERTIES(ChildNodeTest)
{
	BEHAVIAC_REGISTER_METHOD(GetConstFloatValue);
	BEHAVIAC_REGISTER_METHOD(GetConstDoubleValue);
}
BEHAVIAC_END_PROPERTIES()
