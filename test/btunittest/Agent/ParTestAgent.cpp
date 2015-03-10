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

#include "ParTestAgent.h"


signed int ParTestAgent::STV_I32_0 = 0;
kEmployee ParTestAgent::STV_KEMPLOYEE_0;
behaviac::vector<signed int> ParTestAgent::STV_LIST_I32_0;
behaviac::vector<kEmployee> ParTestAgent::STV_LIST_KEMPLOYEE_0;

ParTestAgent::ParTestAgent()
{
	TV_KEMPLOYEE_0.resetProperties();

	TV_I16_0 = 0;
	TV_I32_0 = 0;
	TV_I64_0 = 0L;
	TV_UI16_0 = 0;
}

ParTestAgent::~ParTestAgent()
{
}

void ParTestAgent::resetProperties()
{
	super::resetProperties();

	TV_I16_0 = 0;
	TV_I32_0 = 0;
	STV_I32_0 = 0;
	TV_I64_0 = 0L;
	TV_UI16_0 = 0;

	TV_KEMPLOYEE_0.resetProperties();
	STV_KEMPLOYEE_0.resetProperties();

	TV_LIST_I32_0.clear();
	STV_LIST_I32_0.clear();
	TV_LIST_KEMPLOYEE_0.clear();
	STV_LIST_KEMPLOYEE_0.clear();
}

BEGIN_PROPERTIES_DESCRIPTION(ParTestAgent)

//CLASS_DISPLAY_INFO(L"ParTestAgent", L"")

REGISTER_PROPERTY(TV_I16_0).DISPLAY_INFO(L"1 # TV_I16_0", L"A");
REGISTER_PROPERTY(TV_I32_0).DISPLAYNAME(L"1 # TV_I32_0").DESC(L"A");
REGISTER_PROPERTY(STV_I32_0).DISPLAYNAME(L"1 # STV_I32_0").DESC(L"A");
REGISTER_PROPERTY(TV_I64_0).DISPLAYNAME(L"1 # TV_I64_0").DESC(L"A");;
REGISTER_PROPERTY(TV_UI16_0).DISPLAYNAME(L"1 # TV_UI16_0").DESC(L"A");
REGISTER_PROPERTY(TV_KEMPLOYEE_0).DISPLAYNAME(L"1 # TV_KEMPLOYEE_0").DESC(L"A");
REGISTER_PROPERTY(STV_KEMPLOYEE_0).DISPLAYNAME(L"1 # STV_KEMPLOYEE_0").DESC(L"A");
REGISTER_PROPERTY(TV_LIST_I32_0).DISPLAYNAME(L"1 # TV_LIST_I32_0").DESC(L"A");
REGISTER_PROPERTY(STV_LIST_I32_0).DISPLAYNAME(L"1 # STV_LIST_I32_0").DESC(L"A");
REGISTER_PROPERTY(TV_LIST_KEMPLOYEE_0).DISPLAYNAME(L"1 # TV_LIST_KEMPLOYEE_0").DESC(L"A");
REGISTER_PROPERTY(STV_LIST_KEMPLOYEE_0).DISPLAYNAME(L"1 # STV_LIST_KEMPLOYEE_0").DESC(L"A");

REGISTER_METHOD(Func_Int16Ref).DISPLAYNAME(L"1 # UPR_Int16").DESC(L"A");
REGISTER_METHOD(Func_Int32Ref).DISPLAYNAME(L"1 # UPR_Int32").DESC(L"A");
REGISTER_METHOD(Func_Int64Ref).DISPLAYNAME(L"1 # UPR_Int64").DESC(L"A");
REGISTER_METHOD(Func_UInt16Ref).DISPLAYNAME(L"1 # UPR_UInt16").DESC(L"A");
REGISTER_METHOD(Func_kEmployeeRef).DISPLAYNAME(L"1 # UPR_kEmployee").DESC(L"A");
REGISTER_METHOD(Func_Int32ListRef).DISPLAYNAME(L"1 # UPR_Int32List").DESC(L"A");
REGISTER_METHOD(Func_kEmployeeListRef).DISPLAYNAME(L"1 # UPR_kEmployeeList").DESC(L"A");

REGISTER_METHOD(Func_Int16IR).DISPLAYNAME(L"1 # PIR_Int16").DESC(L"A");
REGISTER_METHOD(Func_Int32IR).DISPLAYNAME(L"1 # PIR_Int32").DESC(L"A");
REGISTER_METHOD(Func_Int64IR).DISPLAYNAME(L"1 # PIR_Int64").DESC(L"A");
REGISTER_METHOD(Func_UInt16IR).DISPLAYNAME(L"1 # PIR_UInt16").DESC(L"A");
REGISTER_METHOD(Func_kEmployeeIR).DISPLAYNAME(L"1 # PIR_kEmployee").DESC(L"A");
REGISTER_METHOD(Func_Int32ListIR).DISPLAYNAME(L"1 # PIR_Int32List").DESC(L"A");
REGISTER_METHOD(Func_kEmployeeListIR).DISPLAYNAME(L"1 # PIR_kEmployeeList").DESC(L"A");

REGISTER_METHOD(Func_kEmployeeSMF).DISPLAYNAME(L"1 # SMF_kEmployee").DESC(L"A");
REGISTER_METHOD(Func_kEmployeeListSMF).DISPLAYNAME(L"1 # SMF_kEmployeeList").DESC(L"A");

END_PROPERTIES_DESCRIPTION()