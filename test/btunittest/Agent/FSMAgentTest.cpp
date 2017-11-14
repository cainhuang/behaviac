﻿/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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

#include "FSMAgentTest.h"

FSMAgentTest::FSMAgentTest()
{
    Message = Invalid;
    TestVar = -1;
}

FSMAgentTest::~FSMAgentTest()
{
}

BEHAVIAC_BEGIN_ENUM(FSMAgentTest::EMessage, EMessage)
{
    BEHAVIAC_ENUM_ITEM(FSMAgentTest::Invalid, "Invalid");
    BEHAVIAC_ENUM_ITEM(FSMAgentTest::Begin, "Begin");
    BEHAVIAC_ENUM_ITEM(FSMAgentTest::End, "End");
    BEHAVIAC_ENUM_ITEM(FSMAgentTest::Pause, "Pause");
    BEHAVIAC_ENUM_ITEM(FSMAgentTest::Resume, "Resume");
    BEHAVIAC_ENUM_ITEM(FSMAgentTest::Exit, "Exit");
}
BEHAVIAC_END_ENUM()

BEHAVIAC_BEGIN_PROPERTIES(FSMAgentTest)
{
    //BEHAVIAC_CLASS_DISPLAYNAME(L"FSMAgentTest DisplayName")
    //BEHAVIAC_CLASS_DESC(L"FSMAgentTest Desc")

    BEHAVIAC_REGISTER_PROPERTY(Message);

    BEHAVIAC_REGISTER_METHOD(inactive_update);
    BEHAVIAC_REGISTER_METHOD(active_update);
    BEHAVIAC_REGISTER_METHOD(pause_update);
    BEHAVIAC_REGISTER_METHOD(exit_update);
}
BEHAVIAC_END_PROPERTIES()
