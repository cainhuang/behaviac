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

#include "EmployeeParTestAgent.h"

float EmployeeParTestAgent::STV_F_0 = 0.0f;
behaviac::string EmployeeParTestAgent::STV_STR_0 = "";
behaviac::Agent* EmployeeParTestAgent::STV_AGENT_0 = NULL;
behaviac::vector<float> EmployeeParTestAgent::STV_LIST_F_0;
behaviac::vector<behaviac::string> EmployeeParTestAgent::STV_LIST_STR_0;
behaviac::vector<behaviac::Agent*> EmployeeParTestAgent::STV_LIST_AGENT_0;


EmployeeParTestAgent::EmployeeParTestAgent()
{
	TV_UI32_0 = 0;
	TV_UI64_0 = 0L;
	TV_F_0 = 0.0f;
	TV_D_0 = 0.0;
	TV_STR_0 = "";
	TV_AGENT_0 = NULL;
}

EmployeeParTestAgent::~EmployeeParTestAgent()
{
}

void EmployeeParTestAgent::resetProperties()
{
	super::resetProperties();

	TV_UI32_0 = 0;
	TV_UI64_0 = 0L;
	TV_F_0 = 0.0f;
	STV_F_0 = 0.0f;
	TV_D_0 = 0.0;
	TV_STR_0 = "";
	STV_STR_0 = "";
	TV_AGENT_0 = NULL;
	STV_AGENT_0 = NULL;

	TV_LIST_F_0.clear();
	STV_LIST_F_0.clear();
	TV_LIST_STR_0.clear();
	STV_LIST_STR_0.clear();
	TV_LIST_AGENT_0.clear();
	STV_LIST_AGENT_0.clear();
}

BEGIN_PROPERTIES_DESCRIPTION(EmployeeParTestAgent)

//CLASS_DISPLAY_INFO(L"EmployeeParTestAgent", L"")

REGISTER_PROPERTY(TV_UI32_0).DISPLAY_INFO(L"2 # TV_UI32_0", L"A");
REGISTER_PROPERTY(TV_UI64_0).DISPLAYNAME(L"2 # TV_UI64_0").DESC(L"A");
REGISTER_PROPERTY(TV_F_0).DISPLAYNAME(L"2 # TV_F_0").DESC(L"A");
REGISTER_PROPERTY(STV_F_0).DISPLAYNAME(L"2 # STV_F_0").DESC(L"A");;
REGISTER_PROPERTY(TV_D_0).DISPLAYNAME(L"2 # TV_D_0").DESC(L"A");
REGISTER_PROPERTY(TV_STR_0).DISPLAYNAME(L"2 # TV_STR_0").DESC(L"A");
REGISTER_PROPERTY(STV_STR_0).DISPLAYNAME(L"2 # STV_STR_0").DESC(L"A");
REGISTER_PROPERTY(TV_AGENT_0).DISPLAYNAME(L"2 # TV_AGENT_0").DESC(L"A");
REGISTER_PROPERTY(STV_AGENT_0).DISPLAYNAME(L"2 # STV_AGENT_0").DESC(L"A");
REGISTER_PROPERTY(TV_LIST_F_0).DISPLAYNAME(L"2 # TV_LIST_F_0").DESC(L"A");
REGISTER_PROPERTY(STV_LIST_F_0).DISPLAYNAME(L"2 # STV_LIST_F_0").DESC(L"A");
REGISTER_PROPERTY(TV_LIST_STR_0).DISPLAYNAME(L"2 # TV_LIST_STR_0").DESC(L"A");
REGISTER_PROPERTY(STV_LIST_STR_0).DISPLAYNAME(L"2 # STV_LIST_STR_0").DESC(L"A");
REGISTER_PROPERTY(TV_LIST_AGENT_0).DISPLAYNAME(L"2 # TV_LIST_AGENT_0").DESC(L"A");
REGISTER_PROPERTY(STV_LIST_AGENT_0).DISPLAYNAME(L"2 # STV_LIST_AGENT_0").DESC(L"A");

REGISTER_METHOD(Func_UInt32Ref).DISPLAYNAME(L"2 # UPR_UInt32").DESC(L"A");
REGISTER_METHOD(Func_UInt64Ref).DISPLAYNAME(L"2 # UPR_UInt64").DESC(L"A");
REGISTER_METHOD(Func_SingleRef).DISPLAYNAME(L"2 # UPR_Single").DESC(L"A");
REGISTER_METHOD(Func_DoubleRef).DISPLAYNAME(L"2 # UPR_Double").DESC(L"A");
REGISTER_METHOD(Func_StringRef).DISPLAYNAME(L"2 # UPR_String").DESC(L"A");
REGISTER_METHOD(Func_AgentRef).DISPLAYNAME(L"2 # UPR_Agent").DESC(L"A");
REGISTER_METHOD(Func_SingleListRef).DISPLAYNAME(L"2 # UPR_SingleList").DESC(L"A");
REGISTER_METHOD(Func_StringListRef).DISPLAYNAME(L"2 # UPR_StringList").DESC(L"A");
REGISTER_METHOD(Func_AgentListRef).DISPLAYNAME(L"2 # UPR_AgentList").DESC(L"A");

REGISTER_METHOD(Func_UInt32IR).DISPLAYNAME(L"2 # PIR_UInt32").DESC(L"A");
REGISTER_METHOD(Func_UInt64IR).DISPLAYNAME(L"2 # PIR_UInt64").DESC(L"A");
REGISTER_METHOD(Func_SingleIR).DISPLAYNAME(L"2 # PIR_Single").DESC(L"A");
REGISTER_METHOD(Func_DoubleIR).DISPLAYNAME(L"2 # PIR_Double").DESC(L"A");
REGISTER_METHOD(Func_StringIR).DISPLAYNAME(L"2 # PIR_String").DESC(L"A");
REGISTER_METHOD(Func_AgentIR).DISPLAYNAME(L"2 # PIR_Agent").DESC(L"A");
REGISTER_METHOD(Func_ParTestAgentBaseIR).DISPLAYNAME(L"2 # PIR_ParTestAgentBase").DESC(L"A");
REGISTER_METHOD(Func_SingleListIR).DISPLAYNAME(L"2 # PIR_SingleList").DESC(L"A");
REGISTER_METHOD(Func_StringListIR).DISPLAYNAME(L"2 # PIR_StringList").DESC(L"A");
REGISTER_METHOD(Func_AgentListIR).DISPLAYNAME(L"2 # PIR_AgentList").DESC(L"A");
REGISTER_METHOD(Func_ParTestAgentBaseListIR).DISPLAYNAME(L"2 # PIR_ParTestAgentBaseList").DESC(L"A");

REGISTER_METHOD(Func_UInt64SMF).DISPLAYNAME(L"2 # SMF_UInt64").DESC(L"A");
REGISTER_METHOD(Func_StringSMF).DISPLAYNAME(L"2 # SMF_String").DESC(L"A");
REGISTER_METHOD(Func_StringListSMF).DISPLAYNAME(L"2 # SMF_StringList").DESC(L"A");
REGISTER_METHOD(Func_AgentSMF).DISPLAYNAME(L"2 # SMF_Agent").DESC(L"A");
REGISTER_METHOD(Func_AgentListSMF).DISPLAYNAME(L"2 # SMF_AgentList").DESC(L"A");

END_PROPERTIES_DESCRIPTION()