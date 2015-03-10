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

#ifndef _ENGINESERVICES_ENTITYID_H_
#define _ENGINESERVICES_ENTITYID_H_

#include "behaviac/base/smartptr.h"
#include "behaviac/base/dynamictype.h"
#include "behaviac/base/core/string/stringid.h"

#define INVALID_ENTITY_ID EntityId()

class EntityId
{
public:
    // Type definitions.
    typedef uint64_t IdType;
    static const IdType InvalidEntityId = (uint64_t) - 1;

public:
    EntityId() : m_id(InvalidEntityId)
    {
    }

    explicit EntityId(IdType id) : m_id(id)
    {
    }

    bool IsValid() const
    {
        return (m_id != InvalidEntityId);
    }

    bool operator == (const EntityId& entityId) const
    {
        return m_id == entityId.m_id;
    }

    bool operator != (const EntityId& entityId) const
    {
        return m_id != entityId.m_id;
    }

    bool operator < (const EntityId& entityId) const
    {
        return m_id < entityId.m_id;
    }

    IdType GetUniqueID() const
    {
        return m_id;
    }

    bool IsDynamic() const
    {
        return (GetUniqueID() >> 63) == 1;
    }

private:
    EntityId(int id)
    {
        BEHAVIAC_UNUSED_VAR(id);
    }

    IdType m_id;
};

BEHAVIAC_OVERRIDE_TYPE_NAME(EntityId)

namespace stdext
{
    template<>
    inline size_t hash_value(const EntityId& keyval)
    {
        // hash _Keyval to size_t value one-to-one
        return ((size_t)keyval.GetUniqueID() ^ ((size_t)0xdeadbeef));
    }
}

#endif // #ifndef _ENGINESERVICES_ENTITYID_H_
