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

using UnityEngine;

[behaviac.TypeMetaInfo()]
public class AgentNodeTest : behaviac.Agent
{
    [behaviac.MemberMetaInfo()]
    public int testVar_0 = -1;

    [behaviac.MemberMetaInfo("testVar_1", "testVar_1 property", 100)]
    public int testVar_1 = -1;

    [behaviac.MemberMetaInfo()]
    public float testVar_2 = -1.0f;

    [behaviac.MemberMetaInfo()]
    public float testVar_3 = -1.0f;

    [behaviac.MemberMetaInfo()]
    public int waiting_timeout_interval = 0;

    [behaviac.MemberMetaInfo()]
    public string testVar_str_0 = string.Empty;

    //// event
    //[behaviac.EventMetaInfo()]
    //delegate bool event_test_void();

    //[behaviac.EventMetaInfo()]
    //delegate bool event_test_int(int val_int);

    //[behaviac.EventMetaInfo()]
    //delegate bool event_test_int_bool(int val_int, bool val_bool);

    //[behaviac.EventMetaInfo()]
    //delegate bool event_test_int_bool_float(int val_int, bool val_bool, float val_float);

    public int event_test_var_int = -1;
    public bool event_test_var_bool = false;
    public float event_test_var_float = -1.0f;

    public void resetProperties() {
        testVar_0 = -1;
        testVar_1 = -1;
        testVar_2 = -1.0f;
        testVar_3 = -1.0f;
        event_test_var_int = -1;
        event_test_var_bool = false;
        event_test_var_float = -1.0f;
        waiting_timeout_interval = 0;

        action_0_enter_count = 0;
        action_0_exit_count = 0;
        action_1_enter_count = 0;
        action_1_exit_count = 0;
        action_2_enter_count = 0;
        action_2_exit_count = 0;

        testVar_str_0 = string.Empty;
    }

    public void init() {
        base.Init();
        resetProperties();
    }

    public void finl() {
    }

    [behaviac.MethodMetaInfo()]
    public void setEventVarInt(int var) {
        event_test_var_int = var;
    }

    [behaviac.MethodMetaInfo()]
    public void setEventVarBool(bool var) {
        event_test_var_bool = var;
    }

    [behaviac.MethodMetaInfo()]
    public void setEventVarFloat(float var) {
        event_test_var_float = var;
    }

    [behaviac.MethodMetaInfo()]
    public int getConstOne() {
        return 1;
    }

    [behaviac.MethodMetaInfo()]
    public void setTestVar_0(int var) {
        testVar_0 = var;
    }

    [behaviac.MethodMetaInfo()]
    public void setTestVar_1(int var) {
        testVar_1 = var;
    }

    [behaviac.MethodMetaInfo()]
    public void setTestVar_2(float var) {
        testVar_2 = var;
    }

    [behaviac.MethodMetaInfo()]
    private void setTestVar_0_2(int var0, float var2) {
        testVar_0 = var0;
        testVar_2 = var2;
    }

    [behaviac.MethodMetaInfo()]
    private float setTestVar_R() {
        return (float)testVar_0 + testVar_2;
    }

    [behaviac.MethodMetaInfo()]
    public void setTestVar_3(float var) {
        testVar_3 = var;
    }

    [behaviac.MethodMetaInfo()]
    public GameObject createGameObject() {
        GameObject go = new GameObject();
        go.name = "HC";
        return go;
    }

    [behaviac.MethodMetaInfo()]
    public void testGameObject(GameObject go) {
        testVar_str_0 = go.name;
    }

    [behaviac.MethodMetaInfo()]
    public behaviac.EBTStatus switchRef(string refTree) {
        this.btreferencetree(refTree);

        return behaviac.EBTStatus.BT_RUNNING;
    }

    // enter action and exit action
    public int action_0_enter_count = 0;

    public int action_0_exit_count = 0;
    public int action_1_enter_count = 0;
    public int action_1_exit_count = 0;
    public int action_2_enter_count = 0;
    public int action_2_exit_count = 0;

    [behaviac.MethodMetaInfo()]
    public bool enter_action_0() {
        action_0_enter_count++;
        return true;
    }

    [behaviac.MethodMetaInfo()]
    public void exit_action_0() {
        action_0_exit_count++;
    }

    [behaviac.MethodMetaInfo()]
    public bool enter_action_1(float f) {
        action_1_enter_count++;
        return true;
    }

    [behaviac.MethodMetaInfo()]
    public void exit_action_1(float f) {
        action_1_exit_count++;
    }

    [behaviac.MethodMetaInfo()]
    public bool enter_action_2(int i, string str) {
        testVar_1 = i;
        testVar_str_0 = str;
        action_2_enter_count++;
        return true;
    }

    [behaviac.MethodMetaInfo()]
    public void exit_action_2(int i, string str) {
        testVar_1 = i;
        testVar_str_0 = str;
        action_2_exit_count++;
    }
}
