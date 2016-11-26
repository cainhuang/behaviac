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

#ifndef BEHAVIAC_BASE_OBJECT_REGISTERMACROS_H
#define BEHAVIAC_BASE_OBJECT_REGISTERMACROS_H

#include "behaviac/agent/agent.h"
#include "behaviac/property/property_t.h"
#include "behaviac/base/object/genericmember.h"
#include "behaviac/base/object/method.h"
#include "behaviac/behaviortree/nodes/conditions/condition.h"
#include "behaviac/property/typeregister.h"
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//register property
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define BEHAVIAC_REGISTER_PROPERTY_V1(memberName) \
    behaviac::_addMember(ms_members, behaviac::CMemberFactory::Create<DefaultTypeHandler, behaviac::EPersistenceType_Description | behaviac::EPersistenceType_UiInfo> \
               (objectType::GetClassTypeName(), #memberName, &objectType::memberName, UiDescriptorAllocate_##DefaultUiInfo))

#define BEHAVIAC_REGISTER_PROPERTY_V2(memberNameStr, getter) \
    behaviac::_addMember(ms_members, behaviac::CMemberFactory::Create<DefaultTypeHandler, behaviac::EPersistenceType_Description | behaviac::EPersistenceType_UiInfo> \
               (objectType::GetClassTypeName(), memberNameStr, &objectType::getter, UiDescriptorAllocate_##DefaultUiInfo))

#define BEHAVIAC_REGISTER_PROPERTY_V3(memberNameStr, getter, settter) \
    behaviac::_addMember(ms_members, behaviac::CMemberFactory::Create<DefaultTypeHandler, behaviac::EPersistenceType_Description | behaviac::EPersistenceType_UiInfo> \
               (objectType::GetClassTypeName(), memberNameStr, &objectType::getter, &objectType::settter, UiDescriptorAllocate_##DefaultUiInfo))

#define BEHAVIAC_REGISTER_PROPERTY(...) _BEHAVIAC_ARGUMENT_SELECTOR4_((__VA_ARGS__, BEHAVIAC_REGISTER_PROPERTY_V3, BEHAVIAC_REGISTER_PROPERTY_V2, BEHAVIAC_REGISTER_PROPERTY_V1))(__VA_ARGS__)
#define _BEHAVIAC_ARGUMENT_SELECTOR4_(__args) _BEHAVIAC_GET_4TH_ARGUMENT_ __args
#define _BEHAVIAC_GET_4TH_ARGUMENT_(__p1,__p2,__p3,__n,...) __n
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///register method
/**
register method

methodName is the c++ method, which can return void or any other value, like int, float, bool, enum, etc.

after exectuing 'methodName' once, the status of the node is determined by the node's result option, please refer to the "Behaviac Overview"
*/
#define BEHAVIAC_REGISTER_METHOD(methodName)				behaviac::_addMethod(ms_methods, &behaviac::CMethodFactory::Create(&objectType::methodName, objectType::GetClassTypeName(), #methodName))

//deprecated
#define REGISTER_PROPERTY   BEHAVIAC_REGISTER_PROPERTY
#define REGISTER_METHOD     BEHAVIAC_REGISTER_METHOD

#endif//BEHAVIAC_BASE_OBJECT_REGISTERMACROS_H
