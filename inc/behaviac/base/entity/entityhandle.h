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

#ifndef _ENGINESERVICES_ENTITYHANDLE_H_
#define _ENGINESERVICES_ENTITYHANDLE_H_

#include "behaviac/base/dynamictype.h"
#include "behaviac/base/entity/entityproxy.h"
#include "behaviac/base/entity/entityid.h"

class CEntity;
class CBaseEntity;

#define INVALID_ENTITY_HANDLE  CBaseEntityHandle()

template<class T>
class TEntityHandle
{
public:
    BEHAVIAC_DECLARE_MEMORY_OPERATORS(TEntityHandle);

public:
    typedef T* PointerType;
    typedef T ObjectType;

    TEntityHandle() : m_entityProxy(CEntityProxy::GetInvalidProxy())
    {
    }

    explicit TEntityHandle(EntityId id) : m_entityProxy(CEntityProxy::GetEntityProxy(id))
    {
    }

    template<class H>
    TEntityHandle(const TEntityHandle<H>& handle) : m_entityProxy(handle.m_entityProxy)
    {
    }

    explicit TEntityHandle(const CSmartEntityProxyPtr& entityProxy) :  m_entityProxy(entityProxy)
    {
    }

    TEntityHandle(const TEntityHandle& handle) : m_entityProxy(handle.m_entityProxy)
    {
    }

    ~TEntityHandle()
    {
    }

    template<class T2>
    bool operator<(const TEntityHandle<T2>& handle) const
    {
        return m_entityProxy->m_entity < handle.m_entityProxy->m_entity;
    }

    template<class T2>
    bool operator==(const TEntityHandle<T2>& handle) const
    {
        return GetId() == handle.GetId() && m_entityProxy->m_entity == handle.m_entityProxy->m_entity;
    }

    template<class T2>
    bool operator!=(const TEntityHandle<T2>& handle) const
    {
        return GetId() != handle.GetId() || m_entityProxy->m_entity != handle.m_entityProxy->m_entity;
    }

    TEntityHandle&  operator=(const TEntityHandle& handle)
    {
        m_entityProxy = handle.m_entityProxy;
        return *this;
    }

    bool IsValid() const
    {
        return m_entityProxy->m_entity != NULL;
    }

    T* operator->() const
    {
        T* ptr = static_cast<T*>(m_entityProxy->m_entity);
        ptr->T::Lock();
        return ptr;
    }

    template<class H>
    static TEntityHandle<T> DynamicCast(const TEntityHandle<H>& handle)
    {
        T* entity = T::DynamicCast(handle.data());

        if (entity)
        {
            return TEntityHandle<T>(entity->GetHandle());
        }
        else
        {
            return TEntityHandle<T>();
        }
    }

    template<class H>
    static TEntityHandle<T> StaticCast(const TEntityHandle<H>& handle)
    {
        T* entity = T::StaticCast(handle.data());

        if (entity)
        {
            return TEntityHandle<T>(entity->GetHandle());
        }
        else
        {
            return TEntityHandle<T>();
        }
    }

    T* GetPtr() const
    {
        return static_cast<T*>(m_entityProxy->m_entity);
    }

    EntityId GetId() const
    {
        return m_entityProxy->m_entityId;
    }

    const CSmartEntityProxyPtr& GetProxy() const
    {
        return m_entityProxy;
    }

    template<class T2>
    friend class TEntityHandle;
protected:
    mutable CSmartEntityProxyPtr    m_entityProxy;
};


typedef TEntityHandle<CBaseEntity> CBaseEntityHandle;
typedef TEntityHandle<CEntity> CEntityHandle;


//template<typename Type>
//struct TypeTraits<TEntityHandle<Type> > : public ObjectTypeTraits<TEntityHandle<Type> >
//{
//	enum { isCopiable = 1 };
//};


BEHAVIAC_OVERRIDE_TYPE_NAME(CEntityHandle);
BEHAVIAC_OVERRIDE_TYPE_NAME(CBaseEntity);

namespace stdext
{
    template<class T>
    inline size_t hash_value(const TEntityHandle<T>& keyval)
    {
        // hash _Keyval to size_t value one-to-one
        return ((size_t)keyval.data() ^ ((size_t)0xdeadbeef));
    }
}


#endif // #ifndef _ENGINESERVICES_ENTITYHANDLE_H_
