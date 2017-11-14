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

#include "CustomPropertyAgent.h"

BEHAVIAC_BEGIN_PROPERTIES(UnityEngine::Vector3)
{
    BEHAVIAC_REGISTER_PROPERTY(x);
    BEHAVIAC_REGISTER_PROPERTY(y);
    BEHAVIAC_REGISTER_PROPERTY(z);
}
BEHAVIAC_END_PROPERTIES()


BEHAVIAC_BEGIN_PROPERTIES(TestNamespace::Float2)
{
	BEHAVIAC_REGISTER_PROPERTY(x);
	BEHAVIAC_REGISTER_PROPERTY(y);
}
BEHAVIAC_END_PROPERTIES()

BEHAVIAC_BEGIN_PROPERTIES(TestNamespace::ClassAsValueType)
{
	BEHAVIAC_REGISTER_PROPERTY(x);
	BEHAVIAC_REGISTER_PROPERTY(y);
}
BEHAVIAC_END_PROPERTIES()

int CustomPropertyAgent::IntMemberConst = 0;

CustomPropertyAgent::CustomPropertyAgent()
{
    init();
}

CustomPropertyAgent::~CustomPropertyAgent()
{
}

BEHAVIAC_BEGIN_PROPERTIES(CustomPropertyAgent)
{
    //BEHAVIAC_CLASS_DISPLAYNAME(L"CustomPropertyAgent DisplayName")
    //BEHAVIAC_CLASS_DESC(L"CustomPropertyAgent Desc")
    BEHAVIAC_REGISTER_PROPERTY(IntProperty);
    BEHAVIAC_REGISTER_PROPERTY(FloatPropertyReadonly);
    BEHAVIAC_REGISTER_PROPERTY(BoolMemberReadonly);
    BEHAVIAC_REGISTER_PROPERTY(IntMemberConst);
    BEHAVIAC_REGISTER_PROPERTY(StringMemberReadonly);
    BEHAVIAC_REGISTER_PROPERTY(Location);

    BEHAVIAC_REGISTER_METHOD(FnWithOutParam);
	BEHAVIAC_REGISTER_METHOD(TestFn1);
	BEHAVIAC_REGISTER_METHOD(TestFn2);
}
BEHAVIAC_END_PROPERTIES()
