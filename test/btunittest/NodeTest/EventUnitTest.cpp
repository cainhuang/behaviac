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

#include "../btloadtestsuite.h"
#include "behaviac/base/core/profiler/profiler.h"

//LOAD_TEST(btunittest, event_ut_0)
//{
//	AgentNodeTest* myTestAgent = initTestEnvNode("node_test/event_ut_0", format);
//	myTestAgent->resetProperties();
//
//	myTestAgent->FireEvent("event_test_void");
//	behaviac::EBTStatus status = myTestAgent->btexec();
//
//	CHECK_EQUAL(behaviac::BT_RUNNING, status);
//
//	myTestAgent->FireEvent("event_test_void");
//	CHECK_EQUAL(true, myTestAgent->event_test_var_bool);
//
//	status = myTestAgent->btexec();
//	CHECK_EQUAL(behaviac::BT_RUNNING, status);
//
//	myTestAgent->resetProperties();
//	myTestAgent->FireEvent("event_test_int", 13);
//	CHECK_EQUAL(13, myTestAgent->event_test_var_int);
//
//	status = myTestAgent->btexec();
//	CHECK_EQUAL(behaviac::BT_RUNNING, status);
//
//	myTestAgent->resetProperties();
//	myTestAgent->FireEvent("event_test_int_bool", 15, true);
//	CHECK_EQUAL(true, myTestAgent->event_test_var_bool);
//	CHECK_EQUAL(15, myTestAgent->event_test_var_int);
//
//	status = myTestAgent->btexec();
//	CHECK_EQUAL(behaviac::BT_RUNNING, status);
//
//	myTestAgent->resetProperties();
//	myTestAgent->FireEvent("event_test_int_bool_float", 15, true, 27.3f);
//	CHECK_EQUAL(true, myTestAgent->event_test_var_bool);
//	CHECK_EQUAL(15, myTestAgent->event_test_var_int);
//	CHECK_EQUAL(27.3f, myTestAgent->event_test_var_float);
//
//	status = myTestAgent->btexec();
//	CHECK_EQUAL(behaviac::BT_RUNNING, status);
//
//	myTestAgent->resetProperties();
//	myTestAgent->testVar_0 = 0;
//	status = myTestAgent->btexec();
//	CHECK_EQUAL(behaviac::BT_SUCCESS, status);
//	CHECK_EQUAL(0, myTestAgent->testVar_1);
//
//	myTestAgent->FireEvent("event_test_int_bool_float", 19, true, 11.9f);
//	CHECK_EQUAL(false, myTestAgent->event_test_var_bool);
//	CHECK_EQUAL(-1, myTestAgent->event_test_var_int);
//	CHECK_EQUAL(-1.0f, myTestAgent->event_test_var_float);
//	finlTestEnvNode(myTestAgent);
//}
