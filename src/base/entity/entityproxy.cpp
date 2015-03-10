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

#include "behaviac/base/entity/entityproxy.h"
#include "behaviac/base/entity/entityhandle.h"

EntityProxyHashMap* CEntityProxy::m_entityProxyMap = NULL;
CEntityProxy* CEntityProxy::ms_invalidProxy = NULL;

CEntityProxy::CEntityProxy(CBaseEntity* entity, EntityId entityId, uint32_t refCounter) :
    m_entityId(entityId),
    m_refCounter(refCounter),
    m_entity(entity),
    m_next(NULL),
    m_isGarbage(false)
{
    BEHAVIAC_ASSERT(entityId == INVALID_ENTITY_ID);
    (*GetProxyMap())[entityId] = this;
}

CEntityProxy::CEntityProxy(CBaseEntity* entity, EntityId entityId) :
    m_entityId(entityId),
    m_refCounter(0),
    m_entity(entity),
    m_next(NULL),
    m_isGarbage(false)
{
}

CEntityProxy::CEntityProxy(EntityId entityId) :
    m_entityId(entityId),
    m_refCounter(0),
    m_entity(NULL),
    m_next(NULL),
    m_isGarbage(false)
{
}

CEntityProxy::CEntityProxy(TEntityHandle<CBaseEntity>& entity, EntityId entityId) :
    m_entityId(entityId),
    m_refCounter(0),
    m_entity(entity.GetPtr()),
    m_next(NULL),
    m_isGarbage(false)
{
}

CEntityProxy::~CEntityProxy()
{
    ASSERT_MAIN_THREAD();
    EntityProxyHashMap::iterator it = GetProxyMap()->find(m_entityId);
    BEHAVIAC_ASSERT(it != GetProxyMap()->end() || (m_entityId == INVALID_ENTITY_ID && m_refCounter == 1));

    if (it != GetProxyMap()->end())
    {
        CEntityProxy* proxy = (*it).second;
        CEntityProxy* previousProxy = NULL;

        while (proxy && proxy != this)
        {
            previousProxy = proxy;
            proxy = proxy->m_next;
        }

        if (previousProxy)
        {
            previousProxy->m_next = proxy->m_next;
        }
        else
        {
            (*it).second = proxy->m_next;
        }

        if ((*it).second == NULL)
        {
            GetProxyMap()->erase(m_entityId);
        }
    }
}

CEntityProxy* CEntityProxy::GetEntityProxy(EntityId entityId)
{
    CEntityProxy*& entityProxy = (*GetProxyMap())[entityId];

    if (entityProxy == NULL)
    {
        entityProxy = BEHAVIAC_NEW CEntityProxy(entityId);
    }

    return entityProxy;
}

CEntityProxy* CEntityProxy::GetEntityProxy(CBaseEntity* entity, EntityId entityId)
{
    if (entity)
    {
        CEntityProxy*& entityProxy = (*GetProxyMap())[entityId];

        if (entityProxy == NULL)
        {
            entityProxy = BEHAVIAC_NEW CEntityProxy(entity, entityId);
        }
        else
        {
            CEntityProxy* proxy = BEHAVIAC_NEW CEntityProxy(entity, entityId);
            proxy->m_next = entityProxy;
            entityProxy = proxy;
        }

        CEntityProxy* tmpProxy = entityProxy;

        while (tmpProxy)
        {
            BEHAVIAC_ASSERT(tmpProxy->m_entity == NULL || tmpProxy->m_entity == entity || tmpProxy->m_isGarbage);

            if (tmpProxy->m_entity == NULL)
            {
                tmpProxy->m_entity = entity;
            }

            tmpProxy = tmpProxy->m_next;
        }

        BEHAVIAC_ASSERT(entityProxy->m_entity == entity);
        return entityProxy;
    }
    else
    {
        return NULL;
    }
}

void CEntityProxy::OnEntityDestroy(EntityId entityId, CBaseEntity* entity)
{
    if (entityId != INVALID_ENTITY_ID)
    {
        EntityProxyHashMap::iterator it = GetProxyMap()->find(entityId);
        BEHAVIAC_ASSERT(it != GetProxyMap()->end());
        CEntityProxy* entityProxy = (*it).second;
        CBaseEntity* validEntity = NULL;

        while (entityProxy)
        {
            if (entityProxy->m_entity && entityProxy->m_entity != entity)
            {
                validEntity = entityProxy->m_entity;
                break;
            }

            entityProxy = entityProxy->m_next;
        }

        entityProxy = (*it).second;

        while (entityProxy)
        {
            if (entityProxy->m_entity == entity)
            {
                entityProxy->m_entity = validEntity;
            }

            entityProxy = entityProxy->m_next;
        }
    }
}

void CEntityProxy::OnMarkAsGarbage(EntityId entityId, CBaseEntity* entity)
{
    if (entityId != INVALID_ENTITY_ID)
    {
        EntityProxyHashMap::iterator it = GetProxyMap()->find(entityId);
        BEHAVIAC_ASSERT(it != GetProxyMap()->end());
        CEntityProxy* entityProxy = (*it).second;

        while (entityProxy)
        {
            if (entityProxy->m_entity == entity)
            {
                entityProxy->m_isGarbage = true;
            }

            entityProxy = entityProxy->m_next;
        }
    }
}

void CEntityProxy::OnEntityIdChange(EntityId prevId, EntityId newId, CBaseEntity* entity)
{
    EntityProxyHashMap::iterator it = GetProxyMap()->find(prevId);
    CEntityProxy* previousProxy = NULL;

    if (it != GetProxyMap()->end())
    {
        previousProxy = (*it).second;
        GetProxyMap()->erase(it);
    }

    CEntityProxy* proxy = previousProxy;

    while (proxy)
    {
        proxy->m_entityId = newId;
        proxy = proxy->m_next;
    }

    it = GetProxyMap()->find(newId);

    if (it != GetProxyMap()->end())
    {
        CEntityProxy* proxy = (*it).second;
        previousProxy->m_next = proxy;
        (*it).second = previousProxy;
    }
    else
    {
        (*GetProxyMap())[newId] = previousProxy;
    }

    proxy = previousProxy;

    while (proxy)
    {
        BEHAVIAC_ASSERT(proxy->m_entity == NULL || proxy->m_entity == entity || proxy->m_isGarbage);

        if (proxy->m_entity == NULL)
        {
            proxy->m_entity = entity;
        }

        proxy = proxy->m_next;
    }
}

CEntityProxy* CEntityProxy::GetInvalidProxy()
{
    if (ms_invalidProxy == NULL)
    {
        ms_invalidProxy = BEHAVIAC_NEW CEntityProxy(NULL, INVALID_ENTITY_ID, 1);
    }

    return ms_invalidProxy;
}

EntityProxyHashMap* CEntityProxy::GetProxyMap()
{
    if (m_entityProxyMap == NULL)
    {
        m_entityProxyMap = BEHAVIAC_NEW EntityProxyHashMap;
    }

    return m_entityProxyMap;
}
