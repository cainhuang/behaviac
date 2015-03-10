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

#ifndef _ENGINESERVICES_ENTITYPROXY_H_
#define _ENGINESERVICES_ENTITYPROXY_H_

#include "behaviac/base/smartptr.h"
#include "behaviac/base/entity/entityid.h"

#include <map>

class CBaseEntity;
class CEntityProxy;
template<class T> class TEntityHandle;

typedef behaviac::map<EntityId, CEntityProxy*> EntityProxyHashMap;

class CEntityProxy
{
public:
    BEHAVIAC_DECLARE_MEMORY_OPERATORS(CEntityProxy);

    BEHAVIAC_API CEntityProxy(CBaseEntity* entity, EntityId entityId);
    BEHAVIAC_API CEntityProxy(EntityId entityId);
    BEHAVIAC_API CEntityProxy(TEntityHandle<CBaseEntity>& entity, EntityId entityId);

    BEHAVIAC_API ~CEntityProxy();

    BEHAVIAC_API static CEntityProxy* GetEntityProxy(EntityId entityId);
    BEHAVIAC_API static CEntityProxy* GetEntityProxy(CBaseEntity* entity, EntityId entityId);

    BEHAVIAC_API static void OnMarkAsGarbage(EntityId entityId, CBaseEntity* entity);
    BEHAVIAC_API static void OnEntityDestroy(EntityId entityId, CBaseEntity* entity);
    BEHAVIAC_API static void OnEntityIdChange(EntityId prevId, EntityId newId, CBaseEntity* entity);

    BEHAVIAC_API static CEntityProxy* GetInvalidProxy();

    EntityId        m_entityId;

    uint32_t           m_refCounter;

    CBaseEntity*    m_entity;
    CEntityProxy*   m_next;

    bool          m_isGarbage;

private:

    CEntityProxy(CBaseEntity* entity, EntityId entityId, uint32_t refCounter);
    static EntityProxyHashMap* GetProxyMap();

    void IncRef()
    {
        ++m_refCounter;
    }

    void DecRef()
    {
        if (--m_refCounter <= 0)
        {
            BEHAVIAC_DELETE(this);
        }
    }

    static EntityProxyHashMap* m_entityProxyMap;
    BEHAVIAC_API static CEntityProxy* ms_invalidProxy;

    friend class CSmartEntityProxyPtr;
};


class CSmartEntityProxyPtr
{
public:
    explicit CSmartEntityProxyPtr(CEntityProxy* entityProxy) : m_entityProxy(entityProxy)
    {
        m_entityProxy->IncRef();
    }

    CSmartEntityProxyPtr(const CSmartEntityProxyPtr& smartPtr) : m_entityProxy(smartPtr.m_entityProxy)
    {
        m_entityProxy->IncRef();
    }

    ~CSmartEntityProxyPtr()
    {
        m_entityProxy->DecRef();
    }

    CSmartEntityProxyPtr& operator=(const CSmartEntityProxyPtr& smartPtr)
    {
        smartPtr.m_entityProxy->IncRef();
        m_entityProxy->DecRef();
        m_entityProxy = smartPtr.m_entityProxy;
        return *this;
    }

    bool operator==(const CSmartEntityProxyPtr& smartPtr) const
    {
        return m_entityProxy == smartPtr.m_entityProxy;
    }

    bool operator!=(const CSmartEntityProxyPtr& smartPtr) const
    {
        return m_entityProxy != smartPtr.m_entityProxy;
    }

    bool operator<(const CSmartEntityProxyPtr& smartPtr) const
    {
        return m_entityProxy < smartPtr.m_entityProxy;
    }

    CEntityProxy* operator->() const
    {
        return m_entityProxy;
    }
    CEntityProxy* GetPtr() const
    {
        return m_entityProxy;
    }

private:
    CEntityProxy*   m_entityProxy;
};


#endif // #ifndef _ENGINESERVICES_ENTITYPROXY_H_
