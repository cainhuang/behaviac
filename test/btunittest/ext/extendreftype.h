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

#ifndef _BEHAVIAC_EXTENDREFTYPE_H_
#define _BEHAVIAC_EXTENDREFTYPE_H_

#include "behaviac/base/dynamictype.h"
#include "behaviac/base/object/typehandler.h"
#include "behaviac/base/string/valuefromstring.h"
#include "behaviac/base/string/valuetostring.h"

#include "behaviac/base/core/types.h"
#include "behaviac/base/dynamictype.h"

#include "behaviac/base/object/tagobject.h"
#include "behaviac/agent/agent.h"

//////////////////////////////////////////////////////////////////////////
//we declare a type "Node" to simulate a type defined in a thirdparty lib
namespace TestNS
{
	struct Node
	{
        behaviac::string name;
	};
}

//////////////////////////////////////////////////////////////////////////

#undef M_SPECIALIZE_TYPE_HANDLER_COMPOUND

#define M_SPECIALIZE_TYPE_HANDLER_COMPOUND()            M_SPECIALIZE_TYPE_HANDLER(TestNS::Node);

M_SPECIALIZE_TYPE_HANDLER_COMPOUND()

//
struct myNode
{
	DECLARE_BEHAVIAC_OBJECT_STRUCT(myNode, true);

	myNode()
	{}

	myNode(const TestNS::Node& v)
	{
	}

	behaviac::string name;
};

template <>
inline CTagObjectDescriptor& GetObjectDescriptor<TestNS::Node>()
{
	return myNode::GetObjectDescriptor();
}

template <>
inline void RegisterProperties<TestNS::Node>()
{
	myNode::RegisterProperties();
}

//add the following to a cpp
//BEGIN_PROPERTIES_DESCRIPTION(myNode)
//{
//	CLASS_DISPLAYNAME(L"")
//	CLASS_DESC(L"")
//
//	REGISTER_PROPERTY(x);
//	REGISTER_PROPERTY(y);
//}
//END_PROPERTIES_DESCRIPTION()

namespace behaviac
{
	// ValueToString & ValueFromString
	namespace StringUtils
	{
		namespace Private
		{
			template<>
			inline behaviac::string ToString(const TestNS::Node& val)
			{
				//myNode::ToString is defined by DECLARE_BEHAVIAC_OBJECT_STRUCT(myNode)
				myNode temp(val);
				return temp.ToString();
			}

			template<>
			inline bool FromString(const char* str, TestNS::Node& val)
			{
				myNode temp;

				//myNode::FromString is defined by DECLARE_BEHAVIAC_OBJECT_STRUCT(myNode)
				if (temp.FromString(str))
				{
					return true;
				}

				return false;
			}
		}
	}
}

// SwapByteTempl helpers
template< typename SWAPPER >
inline void SwapByteTempl(TestNS::Node& v)
{
}

//operators
namespace behaviac
{
	namespace Details
	{
		//------------------------------------------------------------------------
		template<>
		inline bool Equal(const TestNS::Node& lhs, const TestNS::Node& rhs)
		{
			return &lhs == &rhs;
		}
	}
}

#endif//_BEHAVIAC_EXTENDREFTYPE_H_
