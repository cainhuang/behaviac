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

#ifndef FACTORY_SCRIPT_H_
#define FACTORY_SCRIPT_H_
#include "behaviac/base/base.h"

#if BEHAVIAC_ENABLE_LUA
#include "behaviac/base/file/filemanager.h"
#include "behaviac/base/factory.h"

//
template<typename T>
class CFactoryScript : public CFactory<T>
{
public:
    CFactoryScript(const char* scriptBaseType = NULL)
        : m_scriptBaseType(scriptBaseType)
    {
    }

    virtual T* CreateObject(const CStringID& typeID)
    {
        SFactoryBucketScript bucket(typeID, CStringID(), NULL);
        CreatorItScript itEnd(m_creatorsScript.end());
        CreatorItScript itFound(std::find(m_creatorsScript.begin(), itEnd, bucket));
        T* newObject = NULL;

        if (itFound != itEnd)
        {
            // this is a lua object, find the base C++ class
            InstantiateFunctionPointer funcPtr;
            GetInstanciateFunction((*itFound).m_baseType, funcPtr);

            if (!funcPtr)
            {
                BEHAVIAC_ASSERT(0, "The base class %s is not a valid C++ class for the lua class %s\n", (*itFound).m_baseType.c_str(), typeID.c_str());
                return NULL;
            }

            newObject = (*funcPtr)(typeID);
        }
        else
        {
            // this is a C++ object
            newObject = CFactory<T>::CreateObject(typeID);
        }

        return newObject;
    }

    void LoadScriptRegistry(const char* registryFilename)
    {
        BEHAVIAC_ASSERT(registryFilename && "CBiFactory::RegisterScript() Invalid load registry filename\n");
        XmlParser parser;
        XmlConstNodeRef registry = parser.parse(registryFilename);
        int error = 0;
        int cnt = registry->getChildCount();

        for (int i = 0 ; i < cnt ; i++)
        {
            XmlConstNodeRef child = registry->getChild(i);

            if (!RegisterScript(child))
            {
                error++;
            }
        }

        if (error)
        {
            BEHAVIAC_ASSERT(0, "%d Error while loading the registry %s\n", registryFilename);
        }
    }

    bool RegisterScript(const XmlConstNodeRef& node)
    {
        const char* typeName = node->getAttr("name");
        const char* baseName = node->getAttr("base");
        const char* luaFile = node->getAttr("script");
        // valid type
        CStringID typeID(typeName);

        if (!typeID.IsValid())
        {
            // must have a valid type id.
            return false;
        }

        // valid base
        CStringID baseID(baseName);

        if (!baseID.IsValid())
        {
            // no base id specified, using default one
            baseID = m_scriptBaseType;

            if (!baseID.IsValid())
            {
                // still not valid, we need one
                BEHAVIAC_ASSERT(0, "The type %s need a base C++ class\n", typeName);
                return false;
            }
        }

        // valid lua filename
        if (!luaFile || !(*luaFile))
        {
            BEHAVIAC_ASSERT(0, "No lua filename specified for a type.\n");
            return false;
        }
        else
        {
            /* The fileexist need to be fix to have the same behavior as fileopen
            if( !FILEMANAGER_FILEEXISTS(luaFile) )
            {
            	BEHAVIAC_ASSERT(0, "Cannot find the specified lua file: %s.\n", luaFile);
            	return false;
            }*/
        }

        CScriptSystem::GetInstance()->ExecuteFile(luaFile, true, false);
        // register the new type
        SFactoryBucketScript bucket(typeID, baseID, luaFile);
        CreatorItScript itEnd(m_creatorsScript.end());
        CreatorItScript itFound(std::find(m_creatorsScript.begin(), itEnd, bucket));
        bool wasThere = (itFound != itEnd);

        if (wasThere)
        {
            BEHAVIAC_ASSERT(0, "The type %s is already registered into the facotry\n", typeName);
            return false;
        }

        // finally!
        m_creatorsScript.push_back(bucket);
        return true;
    }

private:
    CStringID	m_scriptBaseType;

    struct SFactoryBucketScript
    {
        SFactoryBucketScript(const CStringID& typeID, const CStringID& baseTypeID, const char* luaFile)
            : m_type(typeID)
            , m_baseType(baseTypeID)
            , m_luaFile(luaFile)
            , m_loaded(false)
        {
        }
        bool operator==(const SFactoryBucketScript& rhs)const
        {
            return m_type == rhs.m_type;
        }

        CStringID		m_type;
        CStringID		m_baseType;
        const char*		m_luaFile;
        bool			m_loaded;
    };

    typedef behaviac::vector< SFactoryBucketScript > FactoryContainerScript;
    typedef typename FactoryContainerScript::iterator CreatorItScript;

    FactoryContainerScript m_creatorsScript;	//Container of registered type.

};
#endif//#if BEHAVIAC_ENABLE_LUA

#endif //FACTORY_SCRIPT_H_

