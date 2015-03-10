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

#ifndef BEHAVIAC_BASE_OBJECT_REGISTERMACROS_H_
#define BEHAVIAC_BASE_OBJECT_REGISTERMACROS_H_

#include "behaviac/agent/agent.h"
#include "behaviac/base/object/genericmember.h"
#include "behaviac/base/object/method.h"
#include "behaviac/behaviortree/nodes/conditions/condition.h"
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//register property
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define REGISTER_PROPERTY(memberName) \
	_addMember(ms_members, CMemberFactory::Create<DefaultTypeHandler, EPersistenceType_Description | EPersistenceType_UiInfo> \
		(objectType::GetClassTypeName(), #memberName, &objectType::memberName, UiDescriptorAllocate_##DefaultUiInfo))
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///register method
/**
register method

methodName is the c++ method, which can return void or any other value, like int, float, bool, enum, etc.

after exectuing 'methodName' once, the status of the node is determined by the node's result option, please refer to the "Behaviac Overview"
*/
#define REGISTER_METHOD(methodName)				_addMethod(ms_methods, &CMethodFactory::Create(&objectType::methodName, objectType::GetClassTypeName(), #methodName))

///register method and check_result_fn
/**
register method and check_result_fn

'check_result_fn' is used to check the method's return value to determine the BT status.

deprecated, in the new version, it is advised to config 'check_result_fn' in the designer.
*/
#define REGISTER_METHOD_CHECKRESULT(methodName, check_result_fn)	_addMethod(ms_methods, &CMethodFactory::Create(&check_result_fn, &objectType::methodName, objectType::GetClassTypeName(), #methodName))
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///register event
/**
register event

REGISTER_EVENT can accept 1 to 4 arguments, the 1st argument must be event name and the other arguments are the types:
	REGISTER_EVENT("EventDead");
	REGISTER_EVENT("Exploded", int);
	REGISTER_EVENT("HurtBy", int, bool);
	REGISTER_EVENT("Killed", int, bool, float);
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define REGISTER_EVENT_V1(eventNameString)										_addEvent(ms_methods, &CEventFactory::Create(objectType::GetClassTypeName(), eventNameString))
#define REGISTER_EVENT_V2(eventNameString, paramType1)							_addEvent(ms_methods, &CEventFactory::Create<paramType1>(objectType::GetClassTypeName(), eventNameString))
#define REGISTER_EVENT_V3(eventNameString, paramType1, paramType2)				_addEvent(ms_methods, &CEventFactory::Create<paramType1, paramType2>(objectType::GetClassTypeName(), eventNameString))
#define REGISTER_EVENT_V4(eventNameString, paramType1, paramType2, paramType3)	_addEvent(ms_methods, &CEventFactory::Create<paramType1, paramType2, paramType3>(objectType::GetClassTypeName(), eventNameString))

#define REGISTER_EVENT(...) ARGUMENT_SELECTOR5((__VA_ARGS__, REGISTER_EVENT_V4, REGISTER_EVENT_V3, REGISTER_EVENT_V2, REGISTER_EVENT_V1))(__VA_ARGS__)
#define ARGUMENT_SELECTOR5(__args) GET_5TH_ARGUMENT __args
#define GET_5TH_ARGUMENT(__p1,__p2,__p3,__p4,__n,...) __n

//deprecated, to use REGISTER_EVENT(eventNameString, ...)
#define REGISTER_EVENT_PARAMS1(eventNameString, paramType1)							REGISTER_EVENT(eventNameString, paramType1)
#define REGISTER_EVENT_PARAMS2(eventNameString, paramType1, paramType2)				REGISTER_EVENT(eventNameString, paramType1, paramType2)
#define REGISTER_EVENT_PARAMS3(eventNameString, paramType1, paramType2, paramType3)	REGISTER_EVENT(eventNameString, paramType1, paramType2, paramType3)

#endif//BEHAVIAC_BASE_OBJECT_REGISTERMACROS_H_
