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

#pragma once

#include "behaviac/base/base.h"
#include "behaviac/agent/agent.h"
#include "behaviac/agent/registermacros.h"
#include "Agent/UnitTestTypes.h"

using TNS::NE::NAT::eColor;
using TNS::NE::NAT::WHITE;
using TNS::NE::NAT::RED;
using TNS::NE::NAT::GREEN;
using TNS::NE::NAT::YELLOW;
using TNS::NE::NAT::BLUE;
using TNS::ST::PER::WRK::kEmployee;

namespace UnityEngine
{
    class GameObject
    {
    public:
        GameObject()
        {}

        virtual ~GameObject()
        {}

        behaviac::string name;

        DECLARE_BEHAVIAC_OBJECT_STRUCT(UnityEngine::GameObject);
    };
}

class AgentNodeTest : public behaviac::Agent
{
public:
    AgentNodeTest();
    virtual ~AgentNodeTest();

    DECLARE_BEHAVIAC_AGENT(AgentNodeTest, behaviac::Agent);

    int testVar_0;
    int testVar_1;
    float testVar_2;
    float testVar_3;
    int waiting_timeout_interval;
    behaviac::string testVar_str_0;

    int event_test_var_int;
    bool event_test_var_bool;
    float event_test_var_float;

    // enter action and exit action
    int action_0_enter_count;
    int action_0_exit_count;
    int action_1_enter_count;
    int action_1_exit_count;
    int action_2_enter_count;
    int action_2_exit_count;

public:
    virtual void resetProperties();

    void init()
    {
        resetProperties();
    }

    void finl()
    {
    }

    void setEventVarInt(int var)
    {
        event_test_var_int = var;
    }

    void setEventVarBool(bool var)
    {
        event_test_var_bool = var;
    }

    void setEventVarFloat(float var)
    {
        event_test_var_float = var;
    }

    int getConstOne()
    {
        return 1;
    }

    void setTestVar_0(int var)
    {
        testVar_0 = var;
    }

    void setTestVar_1(int var)
    {
        testVar_1 = var;
    }

    void setTestVar_2(float var)
    {
        testVar_2 = var;
    }

    void setTestVar_0_2(int var0, float var2)
    {
        testVar_0 = var0;
        testVar_2 = var2;
    }

    float setTestVar_R()
    {
        return (float)testVar_0 + testVar_2;
    }

    void setTestVar_3(float var)
    {
        testVar_3 = var;
    }

    UnityEngine::GameObject* createGameObject()
    {
        UnityEngine::GameObject* go = BEHAVIAC_NEW UnityEngine::GameObject();
        go->name = "HC";
        return go;
    }

    void testGameObject(UnityEngine::GameObject* go)
    {
        BEHAVIAC_ASSERT(go != NULL);
        testVar_str_0 = go->name;
    }

    behaviac::EBTStatus switchRef(const behaviac::string& refTree)
    {
        this->btreferencetree(refTree.c_str());

        return behaviac::BT_RUNNING;
    }

    bool enter_action_0()
    {
        action_0_enter_count++;
        return true;
    }

    void exit_action_0()
    {
        action_0_exit_count++;
    }

    bool enter_action_1(float f)
    {
        action_1_enter_count++;
        return true;
    }

    void exit_action_1(float f)
    {
        action_1_exit_count++;
    }

    bool enter_action_2(int i, behaviac::string str)
    {
        testVar_1 = i;
        testVar_str_0 = str;
        action_2_enter_count++;

        return true;
    }

    void exit_action_2(int i, behaviac::string str)
    {
        testVar_1 = i;
        testVar_str_0 = str;
        action_2_exit_count++;
    }
};
