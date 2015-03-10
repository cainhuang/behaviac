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

#include "behaviac/behaviortree/behaviortree.h"
#include "behaviac/agent/registermacros.h"
#include "behaviac/behaviortree/propertymember.h"
#include "behaviac/behaviortree/attachments/event.h"

namespace rapidxml
{
    //! When exceptions are disabled by defining RAPIDXML_NO_EXCEPTIONS, 
    //! this function is called to notify user about the error.
    //! It must be defined by the user.
    //! <br><br>
    //! This function cannot return. If it does, the results are undefined.
    //! <br><br>
    //! A very simple definition might look like that:
    //! <pre>
    //! void %rapidxml::%parse_error_handler(const char *what, void *where)
    //! {
    //!     std::cout << "Parse error: " << what << "\n";
    //!     std::abort();
    //! }
    //! </pre>
    //! \param what Human readable description of the error.
    //! \param where Pointer to character data where error was detected.
    void parse_error_handler(const char *what, void *where)
	{
		BEHAVIAC_UNUSED_VAR(where); 

		BEHAVIAC_LOGERROR("rapidxml parse error: %s\n", what);
		BEHAVIAC_ASSERT(0);
	}
}

namespace behaviac
{
    static const char* kStrBehavior = "behavior";
    static const char* kStrAgentType = "agenttype";

	static const char* kStrId = "id";

	static const char* kStrPars = "pars";
	static const char* kStrPar = "par";

    static const char* kStrNode = "node";
	//static const char* kStrProperties = "properties";
    static const char* kStrProperty = "property";
	//static const char* kStrAttachments = "attachments";
    static const char* kStrAttachment = "attachment";
    static const char* kStrClass = "class";

	static const char* kStrName = "name";
	static const char* kStrType = "type";
	static const char* kStrValue = "value";
	static const char* kEventParam = "eventParam";

	static const char* kStrVersion = "version";

    CFactory<BehaviorNode>* BehaviorNode::ms_factory;
	CFactory<BehaviorNode>& BehaviorNode::Factory()
    {
		if (!ms_factory)
		{
			ms_factory = BEHAVIAC_NEW CFactory<BehaviorNode>;
		}

		BEHAVIAC_ASSERT(ms_factory);

        return *ms_factory;
    }

	void BehaviorNode::Cleanup()
	{
		if (ms_factory)
		{
			BEHAVIAC_DELETE(ms_factory);
			ms_factory = 0;
		}
	}

    BehaviorNode* BehaviorNode::Create(const char* className)
    {
        CStringID classId(className);
        BehaviorNode* pBehaviorNode = Factory().CreateObject(classId);
        return pBehaviorNode;
    }

	BehaviorNode::BehaviorNode() : m_id(INVALID_NODE_ID), m_attachments(0), m_pars(0),
		m_parent(0), m_children(0), m_enterAction(0), m_exitAction(0), m_bHasEvents(false)
	{
	}

	BehaviorNode::~BehaviorNode() {
		this->Clear();
	}

	void BehaviorNode::Clear()
	{
		BEHAVIAC_DELETE(m_enterAction);
		BEHAVIAC_DELETE(m_exitAction);

		if (this->m_pars)
		{
			for (Properties_t::iterator it = this->m_pars->begin(); it != this->m_pars->end(); ++it)
			{
				Property* pProperty = *it;
				Property::DeleteFromCache(pProperty);

				BEHAVIAC_DELETE(pProperty);
			}

			this->m_pars->clear();
			BEHAVIAC_DELETE(this->m_pars);
			this->m_pars = 0;
		}

		if (this->m_attachments)
		{
			for (size_t i = 0; i < this->m_attachments->size(); ++i)
			{
				BehaviorNode* pAttachment = (*m_attachments)[i];
				BEHAVIAC_DELETE(pAttachment);
			}
			this->m_attachments->clear();
			BEHAVIAC_DELETE(this->m_attachments);
			this->m_attachments = 0;
		}

		if (this->m_children)
		{
			for (size_t i = 0; i < this->m_children->size(); ++i)
			{
				BehaviorNode* pChild = (*m_children)[i];
				BEHAVIAC_DELETE(pChild);
			}
			this->m_children->clear();
			BEHAVIAC_DELETE(this->m_children);
			this->m_children = 0;
		}
	}


	BehaviorTask* BehaviorNode::CreateAndInitTask() const
	{
		BehaviorTask* pTask = this->createTask();
		pTask->Init(this);

		return pTask;
	}

	bool BehaviorNode::HasEvents() const
	{
		return this->m_bHasEvents;
	}

	void BehaviorNode::SetHasEvents(bool hasEvents)
	{
		this->m_bHasEvents = hasEvents;
	}

	uint32_t BehaviorNode::GetChildrenCount() const
	{
		if (this->m_children)
		{
			return this->m_children->size();
		}

		return 0;
	}

	const BehaviorNode* BehaviorNode::GetChild(uint32_t index) const
	{
		if (this->m_children && index < this->m_children->size())
		{
			return (*this->m_children)[index];
		}

		return 0;
	}


	uint32_t BehaviorNode::GetAttachmentsCount() const
	{
		if (this->m_attachments)
		{
			return this->m_attachments->size();
		}

		return 0;
	}


	const BehaviorNode* BehaviorNode::GetAttachment(uint32_t index) const
	{
		if (this->m_attachments && index < this->m_attachments->size())
		{
			return (*this->m_attachments)[index];
		}

		return 0;
	}


	void BehaviorNode::SetClassNameString(const char* className)
	{
		this->m_className = className;
	}


	const behaviac::string& BehaviorNode::GetClassNameString() const
	{
		return this->m_className;
	}

	int BehaviorNode::GetId() const
	{
		//BEHAVIAC_ASSERT(this->m_id != INVALID_NODE_ID);

		return this->m_id;
	}

	void BehaviorNode::SetId(int id)
	{
		this->m_id = id;
	}

	void BehaviorNode::SetAgentType(const behaviac::string& agentType)
	{
#if !defined(BEHAVIAC_RELEASE)
		this->m_agentType = agentType;
#endif
	}

	void BehaviorNode::AddPar(const char* type, const char* name, const char* value, const char* eventParam)
	{
		Property* pProperty = Property::Create(type, name, value, false, false);
		if (eventParam && eventParam[0] != '\0')
		{
			pProperty->SetRefName(eventParam);
		}

		if (!this->m_pars)
		{
			this->m_pars = BEHAVIAC_NEW Properties_t;
		}
		this->m_pars->push_back(pProperty);
	}

	CMethodBase* LoadMethod(const char* value_);

	bool BehaviorNode::IsValid(Agent* pAgent, BehaviorTask* pTask) const
	{
		BEHAVIAC_UNUSED_VAR(pAgent);
		BEHAVIAC_UNUSED_VAR(pTask);
#if !defined(BEHAVIAC_RELEASE)
		BEHAVIAC_ASSERT(!this->m_agentType.empty());
		CStringID btAgentClass(this->m_agentType.c_str());

		return pAgent->IsAKindOf(btAgentClass);
#else
		return true;
#endif//#if !defined(BEHAVIAC_RELEASE)
	}

	void BehaviorNode::load(int version, const char* agentType, const properties_t& properties)
	{
		BEHAVIAC_UNUSED_VAR(version); 
		BEHAVIAC_UNUSED_VAR(agentType); 
		BEHAVIAC_UNUSED_VAR(properties); 

		for (propertie_const_iterator_t it = properties.begin(); it != properties.end(); ++it)
		{
			const property_t& p = (*it);

			if (strcmp(p.name, "EnterAction") == 0)
			{
				if (p.value[0] != '\0')
				{
					this->m_enterAction = LoadMethod(p.value);
				}//if (p.value[0] != '\0')
			}
			else if (strcmp(p.name, "ExitAction") == 0)
			{
				if (p.value[0] != '\0')
				{
					this->m_exitAction = LoadMethod(p.value);
				}//if (p.value[0] != '\0')
			}
		}

		Workspace::BehaviorNodeLoadedHandler_t loadedHandler = Workspace::GetLoadedHandler();

		if (loadedHandler)
		{
			const char* nodeType = this->GetObjectTypeName();
			(*loadedHandler)(nodeType, properties);
		}
	}

	void BehaviorNode::load_attachments(int version, const char* agentType, rapidxml::xml_node<>* node)
	{
		rapidxml::xml_node<>* nodesAttachment = node->first_node(kStrAttachment);

		for (rapidxml::xml_node<>* attachmentNode = nodesAttachment; attachmentNode; attachmentNode = attachmentNode->next_sibling())
		{
			if (strcmp(attachmentNode->name(), kStrAttachment) == 0)
			{
				BehaviorNode* pAttachment = 0;

				int versionAttach = 0;
				if (rapidxml::xml_attribute<>* attrVersionAttach = attachmentNode->first_attribute(kStrVersion))
				{
					versionAttach = atoi(attrVersionAttach->value());
				}

				BEHAVIAC_UNUSED_VAR(versionAttach);

				const char* pAttachClassName = 0;

				if (rapidxml::xml_attribute<>* attr = attachmentNode->first_attribute(kStrClass))
				{
					//std::cout << attr->name() << ":" << attr->value() << std::endl;
					BEHAVIAC_ASSERT(strcmp(attr->name(), kStrClass) == 0);
					pAttachClassName = attr->value();
					pAttachment = BehaviorNode::Create(pAttachClassName);

					if (!pAttachment)
					{
						BEHAVIAC_LOGWARNING("invalid attachment class '%s'\n", pAttachClassName);
					}
				}

				BEHAVIAC_ASSERT(pAttachment);

				if (pAttachment)
				{
					pAttachment->SetClassNameString(pAttachClassName);

					if (rapidxml::xml_attribute<>* attrId = attachmentNode->first_attribute(kStrId))
					{
						pAttachment->SetId(atoi(attrId->value()));
					}

					pAttachment->load_properties_pars(version, agentType, attachmentNode);

					this->Attach(pAttachment);

					this->m_bHasEvents |= (Event::DynamicCast(pAttachment) != 0);
				}
			}
		}//end of for attachment
	}

	void BehaviorNode::load_par(int version, const char* agentType, rapidxml::xml_node<>* node)
	{
		BEHAVIAC_UNUSED_VAR(version); 
		BEHAVIAC_UNUSED_VAR(agentType); 

        if (strcmp(node->name(), kStrPar) != 0)
        {
            BEHAVIAC_ASSERT(0);
            return;
        }

        //std::cout << "par attribute:" << std::endl;
		rapidxml::xml_attribute<>* attrName = node->first_attribute(kStrName);
		rapidxml::xml_attribute<>* attrType = node->first_attribute(kStrType);
		rapidxml::xml_attribute<>* attrEventParam = node->first_attribute(kEventParam);
        if (attrName && attrType)
        {
			rapidxml::xml_attribute<>* attrValue = node->first_attribute(kStrValue);
            BEHAVIAC_ASSERT(strcmp(attrName->name(), kStrName) == 0);
			BEHAVIAC_ASSERT(strcmp(attrType->name(), kStrType) == 0);

            const char* name = attrName->value();
			const char* type = attrType->value();
			const char* value = attrValue ? attrValue->value() : 0;
			char* eventParam = NULL;
			if (attrEventParam)
			{
				eventParam = attrEventParam->value();
			}

			this->AddPar(type, name, value, eventParam);
        }
    }

	void BehaviorNode::load_properties(int version, const char* agentType, rapidxml::xml_node<>* node)
	{
#if !defined(BEHAVIAC_RELEASE)
        this->m_agentType = agentType;
#endif//#ifdef _DEBUG

		properties_t properties;

        rapidxml::xml_node<>* nodesProperty = node->first_node(kStrProperty);

        for (rapidxml::xml_node<>* attachmentNode = nodesProperty; attachmentNode; attachmentNode = attachmentNode->next_sibling())
        {
            if (strcmp(attachmentNode->name(), kStrProperty) == 0)
            {
                if (rapidxml::xml_attribute<>* attr = attachmentNode->first_attribute())
                {
                    //std::cout << attr->name() << ":" << attr->value() << std::endl;
                    const char* pPropertyName = attr->name();
                    const char* pPropertyValue = attr->value();
                    properties.push_back(property_t(pPropertyName, pPropertyValue));
                }
            }
        }

		if (properties.size() > 0)
		{
			this->load(version, agentType, properties);
		}
	}

	void BehaviorNode::load_properties_pars(int version, const char* agentType, rapidxml::xml_node<>* node)
	{
		this->load_properties(version, agentType, node);

		//pars
		rapidxml::xml_node<>* pars = node->first_node(kStrPars);
		if (pars)
		{
			rapidxml::xml_node<>* parNode = pars->first_node(kStrPar);

			for (; parNode; parNode = parNode->next_sibling())
			{
				this->load_par(version, agentType, parNode);
			}
		}
	}

	void BehaviorNode::load_properties_pars_attachments_children(int version, const char* agentType, rapidxml::xml_node<>* node)
	{
		//pars
		this->load_properties_pars(version, agentType, node);

		this->load_attachments(version, agentType, node);

		bool bHasEvents = this->HasEvents();

		rapidxml::xml_node<>* children = node->first_node(kStrNode);

		for (rapidxml::xml_node<>* child = children; child; child = child->next_sibling())
		{
			BehaviorNode* pChildNode = this->load(agentType, child);
			bHasEvents |= pChildNode->m_bHasEvents;

			this->AddChild(pChildNode);
		}

		this->m_bHasEvents = bHasEvents;
	}

    BehaviorNode* BehaviorNode::load(const char* agentType, rapidxml::xml_node<>* node)
    {
        BehaviorNode* pNode = 0;

        if (strcmp(node->name(), kStrNode) != 0)
        {
            BEHAVIAC_ASSERT(0);
            return pNode;
        }

		int version = 0;
		if (rapidxml::xml_attribute<>* attrVersion = node->first_attribute(kStrVersion))
		{
			version = atoi(attrVersion->value());
		}

		const char* pClassName = 0;
        if (rapidxml::xml_attribute<>* attr = node->first_attribute(kStrClass))
        {
            BEHAVIAC_ASSERT(strcmp(attr->name(), kStrClass) == 0);
            pClassName = attr->value();
			pNode = BehaviorNode::Create(pClassName);

            if (!pNode)
            {
                BEHAVIAC_LOGWARNING("invalid node class '%s'\n", pClassName);
            }

            BEHAVIAC_ASSERT(pNode);
        }

        BEHAVIAC_ASSERT(pNode);

        if (pNode)
        {
			pNode->SetClassNameString(pClassName);
			if (rapidxml::xml_attribute<>* attrId = node->first_attribute(kStrId))
			{
				pNode->SetId(atoi(attrId->value()));
			}

			pNode->load_properties_pars_attachments_children(version, agentType, node);
        }

        return pNode;
    }

	void BehaviorNode::Attach(BehaviorNode* pAttachment)
	{
        if (!this->m_attachments)
        {
            this->m_attachments = BEHAVIAC_NEW Attachments;
        }

        this->m_attachments->push_back(pAttachment);
    }

	void BehaviorNode::AddChild(BehaviorNode* pChild)
	{
		pChild->m_parent = this;

		if (!this->m_children)
		{
			this->m_children = BEHAVIAC_NEW Nodes;
		}

		this->m_children->push_back(pChild);
	}

	DecoratorNode::DecoratorNode() : m_bDecorateWhenChildEnds(false)
	{}

	DecoratorNode::~DecoratorNode()
	{}

	void DecoratorNode::load(int version, const char* agentType, const properties_t& properties)
	{
		super::load(version, agentType, properties);
		for (propertie_const_iterator_t it = properties.begin(); it != properties.end(); ++it)
		{
			const property_t& p = (*it);

			if (strcmp(p.name, "DecorateWhenChildEnds") == 0)
			{
				if (p.value[0] != '\0')
				{
					if (string_icmp(p.value, "true") == 0)
					{
						this->m_bDecorateWhenChildEnds = true;
					}
				}//if (p.value[0] != '\0')
			}
			else
			{
				//BEHAVIAC_ASSERT(0, "unrecognised property %s", p.name);
			}
		}
	}

	bool DecoratorNode::IsValid(Agent* pAgent, BehaviorTask* pTask) const
	{
		if (!DecoratorNode::DynamicCast(pTask->GetNode()))
		{
			return false;
		}
	
		return super::IsValid(pAgent, pTask);
	}


	BehaviorTree::BehaviorTree() : BehaviorNode()
	{
	}

	BehaviorTree::~BehaviorTree()
	{
		this->m_descriptorRefs.clear();
	}

	//Property* LoadLeft(const char* value, behaviac::string& propertyName, const char* constValue);
	//Property* LoadRight(const char* value, const behaviac::string& propertyName, behaviac::string& typeName);

	BEGIN_PROPERTIES_DESCRIPTION(BehaviorTree::Descriptor_t)
		REGISTER_PROPERTY(Descriptor);
		REGISTER_PROPERTY(Reference);
	END_PROPERTIES_DESCRIPTION()

	void BehaviorTree::load(int version, const char* agentType, const properties_t& properties)
	{
		super::load(version, agentType, properties);

		if (properties.size() > 0)
		{
			for (propertie_const_iterator_t it = properties.begin(); it != properties.end(); ++it)
			{
				const property_t& p = (*it);

				if (strcmp(p.name, "Domains") == 0)
				{
					SetDomains(p.value);
				}
				else if (strcmp(p.name, "DescriptorRefs") == 0)
				{
					SetDescriptors(p.value);
				}
				else
				{
					//BEHAVIAC_ASSERT(0, "unrecognised property %s", p.name);
				}
			}	
		}
	}

	const behaviac::string& BehaviorTree::GetDomains() const
	{
		return this->m_domains;
	}

	void BehaviorTree::SetDomains(const behaviac::string& domains)
	{
		this->m_domains = domains;
	}

	const BehaviorTree::Descriptors_t BehaviorTree::GetDescriptors() const
	{
		return m_descriptorRefs;
	}

	void BehaviorTree::SetDescriptors(const char* descriptors)
	{
		behaviac::StringUtils::FromString(descriptors, this->m_descriptorRefs);

		for (size_t i = 0; i < this->m_descriptorRefs.size(); ++i)
		{
			Descriptor_t& d = this->m_descriptorRefs[i];
			if (d.Descriptor)
				d.Descriptor->SetDefaultValue(d.Reference);
		}
	}

	/**
	<?xml version="1.0" encoding="utf-8"?>
	<behavior agenttype="AgentTest">
	  <!--EXPORTED BY TOOL, DON'T MODIFY IT!-->
	  <!--Source File: ... -->
	  <node class="DecoratorLoopTask">
		<property Count="10" />
		<node class="SelectorTask">
			...
		</node>
	  </node>
	</behavior>
	*/
    bool BehaviorTree::load_xml(char* pBuffer)
	{
		//behaviac::string fileStr = file;
		//behaviac::StringUtils::UnifySeparator(fileStr);
		//IFile* fp = CFileManager::GetInstance()->FileOpen(fileStr.c_str(), CFileSystem::EOpenAccess_Read);
		rapidxml::xml_document<> doc;
		doc.parse<0>(pBuffer);
		//std::cout << std::endl;
		rapidxml::xml_node<>* nodeBehavior = doc.first_node(kStrBehavior);
		if (!nodeBehavior || strcmp(nodeBehavior->name(), kStrBehavior) != 0)
		{
			return false;
		}

		if (rapidxml::xml_attribute<>* attrName = nodeBehavior->first_attribute(kStrName))
		{
			this->m_name = attrName->value();
		}

		rapidxml::xml_attribute<>* attrAgentType = nodeBehavior->first_attribute(kStrAgentType);
		BEHAVIAC_ASSERT(attrAgentType && strcmp(attrAgentType->name(), kStrAgentType) == 0);
		const char* agentType = attrAgentType->value();
		//BEHAVIAC_ASSERT(Agent::IsRegistered(agentType));

		rapidxml::xml_attribute<>* attrVersion = nodeBehavior->first_attribute(kStrVersion);

		int version = 0;
		if (attrVersion)
		{
			version = atoi(attrVersion->value());
		}

		this->SetClassNameString("BehaviorTree");
		this->SetId(-1);

		this->load_properties_pars_attachments_children(version, agentType, nodeBehavior);

		return true;
	}


	BehaviorTask* BehaviorTree::createTask() const
	{
		BehaviorTreeTask* pTask = BEHAVIAC_NEW BehaviorTreeTask();
		

		return pTask;
	}

#define LITTLE_ENDIAN_ONLY		1
#define USE_STRING_COUNT_HEAD	1
//#define USE_DOCUMENET			1

	//bson deserizer
	class BsonDeserizer
	{
	public:
		enum BsonTypes
		{
			BT_None = 0,
			BT_Double = 1,
			BT_String = 2,
			BT_Object = 3,
			BT_Array = 4,
			BT_Binary = 5,
			BT_Undefined = 6,
			BT_ObjectId = 7,
			BT_Boolean = 8,
			BT_DateTime = 9,
			BT_Null = 10,
			BT_Regex = 11,
			BT_Reference = 12,
			BT_Code = 13,
			BT_Symbol = 14,
			BT_ScopedCode = 15,
			BT_Int32 = 16,
			BT_Timestamp = 17,
			BT_Int64 = 18,
			BT_Float = 19,
			BT_Element = 20,
			BT_Set = 21, 
			BT_BehaviorElement = 22,
			BT_PropertiesElement = 23,
			BT_ParsElement = 24,
			BT_ParElement = 25,
			BT_NodeElement = 26,
			BT_AttachmentsElement = 27,
			BT_AttachmentElement = 28
		};
	public:
		BsonDeserizer();
		virtual ~BsonDeserizer();

		bool Init(const char* pBuffer);

		bool OpenDocument();
		void CloseDocument(bool bEatEod = false);

		BsonTypes ReadType();
		int32_t ReadInt32();
		uint16_t ReadUInt16();
		float ReadFloat();
		bool ReadBool();
		const char* ReadString();

		bool eod() const;

	private:
		const char*		m_pBuffer;
		const char*		m_pPtr;
#if USE_DOCUMENET
		const char*		m_document;

		static const int kDocumentStackMax = 100;
		int				m_documentStackTop;
		const char*		m_documentStack[kDocumentStackMax];
#endif//USE_DOCUMENET
	};

	static bool isLittleEndian()
	{
		static bool s_bDetected = false;
		static bool s_bLittleEndian = true;
		if (!s_bDetected)
		{
			int number = 0x1;
			char *numPtr = (char*)&number;

			s_bLittleEndian = (numPtr[0] == 1);
			s_bDetected = true;
		}

		return s_bLittleEndian;
	}

	BsonDeserizer::BsonDeserizer() : m_pBuffer(0), m_pPtr(0)
#if USE_DOCUMENET
		, m_document(0), m_documentStackTop(0)
#endif
	{
	}

	BsonDeserizer::~BsonDeserizer()
	{
	}

	bool BsonDeserizer::Init(const char* pBuffer)
	{
		this->m_pBuffer = pBuffer;
		if (this->m_pBuffer)
		{
			this->m_pPtr = this->m_pBuffer;
			if (this->OpenDocument())
			{
				return true;
			}
		}

		BEHAVIAC_ASSERT(0);

		return false;
	}

	bool BsonDeserizer::OpenDocument()
	{
		const char* head = this->m_pPtr;
		uint32_t size = this->ReadInt32();
		//uint16_t size = this->ReadUInt16();

		const char* end = head + size - 1;
		if (*end == 0)
		{
#if USE_DOCUMENET
			BEHAVIAC_ASSERT(this->m_documentStackTop >= 0 && this->m_documentStackTop < kDocumentStackMax - 1);
			this->m_documentStack[this->m_documentStackTop++] = this->m_document;
			this->m_document = head;
#endif
			return true;
		}

		BEHAVIAC_ASSERT(0);

		return false;
	}

	void BsonDeserizer::CloseDocument(bool bEatEod)
	{
		BEHAVIAC_ASSERT(this->m_pPtr && this->m_pPtr > this->m_pBuffer);

		if (bEatEod)
		{
			const char* endLast = this->m_pPtr++;
			BEHAVIAC_ASSERT(*endLast == 0);
			BEHAVIAC_UNUSED_VAR(endLast);
		}
		else
		{
			const char* endLast = this->m_pPtr - 1;
			BEHAVIAC_ASSERT(*endLast == 0);
			BEHAVIAC_UNUSED_VAR(endLast);
		}
#if USE_DOCUMENET
		BEHAVIAC_ASSERT(this->m_documentStackTop > 0 && this->m_documentStackTop < kDocumentStackMax);
		this->m_document = this->m_documentStack[--this->m_documentStackTop];
#endif
	}

	BsonDeserizer::BsonTypes BsonDeserizer::ReadType()
	{
		char t = *this->m_pPtr++;

		return (BsonTypes)t;
	}

	int32_t BsonDeserizer::ReadInt32()
	{
		int32_t* pInt32 = (int32_t*)this->m_pPtr;

		this->m_pPtr += 4;
#if LITTLE_ENDIAN_ONLY
		bool bIsLittleEndian = isLittleEndian();
		BEHAVIAC_UNUSED_VAR(bIsLittleEndian);
		BEHAVIAC_ASSERT(bIsLittleEndian);

		return *pInt32;
#else
		if (isLittleEndian())
		{
			return *pInt32;
		}

		uint8_t* pByte = (uint8_t*)pInt32;

		int32_t uint32 = (pByte[0] << 24 | pByte[1] << 16 | pByte[2] << 8 | pByte[3]);

		return uint32;
#endif//LITTLE_ENDIAN_ONLY
	}

	uint16_t BsonDeserizer::ReadUInt16()
	{
		uint16_t* pUInt16 = (uint16_t*)this->m_pPtr;

		this->m_pPtr += 2;
#if LITTLE_ENDIAN_ONLY
		BEHAVIAC_ASSERT(isLittleEndian());

		return *pUInt16;
#else
		if (isLittleEndian())
		{
			return *pUInt16;
		}

		uint8_t* pByte = (uint8_t*)pUInt16;

		int32_t uint32 = (pByte[0] << 8 | pByte[1]);

		return uint32;
#endif//LITTLE_ENDIAN_ONLY
	}

	float BsonDeserizer::ReadFloat()
	{
		float* pFloat = (float*)this->m_pPtr;

		this->m_pPtr += 4;
#if LITTLE_ENDIAN_ONLY
		BEHAVIAC_ASSERT(isLittleEndian());

		return *pFloat;
#else
		if (isLittleEndian())
		{
			return *pFloat;
		}

		uint8_t* pByte = (uint8_t*)pFloat;

		int32_t uint32 = (pByte[0] << 24 | pByte[1] << 16 | pByte[2] << 8 | pByte[3]);

		return (float&)uint32;
#endif//LITTLE_ENDIAN_ONLY
	}

	bool BsonDeserizer::ReadBool()
	{
		char* pByte = (char*)this->m_pPtr;

		this->m_pPtr += 1;

		return *pByte != 0 ? true : false;
	}


	const char* BsonDeserizer::ReadString()
	{
#if USE_STRING_COUNT_HEAD
		uint16_t count = ReadUInt16();

		const char* pStr = this->m_pPtr;

		this->m_pPtr += count;
		BEHAVIAC_ASSERT(*(this->m_pPtr - 1) == 0);

		return pStr;
#else
		const char* pStr = this->m_pPtr;

		while (*this->m_pPtr)
		{
			this->m_pPtr++;
		}

		//skip the ending 0
		this->m_pPtr++;

		return pStr;
#endif
	}

	bool BsonDeserizer::eod() const
	{
		char c = *this->m_pPtr;
		return c == 0;
	}


	bool BehaviorTree::load_bson(const char* pBuffer)
	{
		BsonDeserizer d;

		if (d.Init(pBuffer))
		{
			BsonDeserizer::BsonTypes type = d.ReadType();
			if (type == BsonDeserizer::BT_BehaviorElement)
			{
				bool bOk = d.OpenDocument();
				BEHAVIAC_ASSERT(bOk);
				BEHAVIAC_UNUSED_VAR(bOk);

				this->m_name = d.ReadString();
				const char* agentType = d.ReadString();
				//BEHAVIAC_ASSERT(Agent::IsRegistered(agentType));
				const char* versionStr = d.ReadString();

				int version = atoi(versionStr);

				this->SetClassNameString("BehaviorTree");
				this->SetId(-1);

				this->load_properties_pars_attachments_children(version, agentType, d);

				d.CloseDocument();

				return true;
			}

			BEHAVIAC_ASSERT(false);
		}

		return false;
	}

	void BehaviorNode::load_properties(int version, const char* agentType, BsonDeserizer& d)
	{
#if !defined(BEHAVIAC_RELEASE)
        this->m_agentType = agentType;
#endif//#ifdef _DEBUG

		d.OpenDocument();

		//load property after loading par as property might reference par
		properties_t properties;

		BsonDeserizer::BsonTypes type = d.ReadType();
		while (type == BsonDeserizer::BT_String)
		{
			const char* propertyName = d.ReadString();
			const char* propertyValue = d.ReadString();

			properties.push_back(property_t(propertyName, propertyValue));

			type = d.ReadType();
		}

		if (properties.size() > 0)
		{
			this->load(version, agentType, properties);
		}

		BEHAVIAC_ASSERT(type == BsonDeserizer::BT_None);
		d.CloseDocument();
	}

	void BehaviorNode::load_pars(int version, const char* agentType, BsonDeserizer& d)
	{
		d.OpenDocument();

		BsonDeserizer::BsonTypes type = d.ReadType();
		while (type == BsonDeserizer::BT_ParElement)
		{
			this->load_par(version, agentType, d);

			type = d.ReadType();
		}

		BEHAVIAC_ASSERT(type == BsonDeserizer::BT_None);
		d.CloseDocument();
	}

	void BehaviorNode::load_children(int version, const char* agentType, BsonDeserizer& d)
	{
		BEHAVIAC_UNUSED_VAR(version); 
		BEHAVIAC_UNUSED_VAR(agentType); 

		d.OpenDocument();

		BehaviorNode* pChildNode = this->load(agentType, d);
		bool bHasEvents = pChildNode->m_bHasEvents;

		this->AddChild(pChildNode);

		this->m_bHasEvents |= bHasEvents;

		d.CloseDocument();
	}

	void BehaviorNode::load_properties_pars_attachments_children(int version, const char* agentType, BsonDeserizer& d)
	{
		BsonDeserizer::BsonTypes type = d.ReadType();

		while (type != BsonDeserizer::BT_None)
		{
			if (type == BsonDeserizer::BT_PropertiesElement)
			{
				this->load_properties(version, agentType, d);
			}
			else if (type == BsonDeserizer::BT_ParsElement)
			{
				this->load_pars(version, agentType, d);
			}
			else if (type == BsonDeserizer::BT_AttachmentsElement)
			{
				this->load_attachments(version, agentType, d);

				this->m_bHasEvents |= this->HasEvents();
			}
			else if (type == BsonDeserizer::BT_NodeElement)
			{
				this->load_children(version, agentType, d);
			}
			else
			{
				BEHAVIAC_ASSERT(0);
			}

			type = d.ReadType();
		}
	}

	BehaviorNode* BehaviorNode::load(const char* agentType, BsonDeserizer& d)
	{
		const char* pClassName = d.ReadString();
		BehaviorNode* pNode = BehaviorNode::Create(pClassName);

		if (!pNode)
		{
			BEHAVIAC_LOGWARNING("invalid node class '%s'\n", pClassName);
		}

		const char* verString = d.ReadString();
		int version = atoi(verString);

		BEHAVIAC_ASSERT(pNode);

		if (pNode)
		{
			pNode->SetClassNameString(pClassName);
			const char* idString = d.ReadString();
			pNode->SetId(atoi(idString));

			pNode->load_properties_pars_attachments_children(version, agentType, d);
		}

		return pNode;
	}

	void BehaviorNode::load_par(int version, const char* agentType, BsonDeserizer& d)
	{
		BEHAVIAC_UNUSED_VAR(version); 
		BEHAVIAC_UNUSED_VAR(agentType); 

		d.OpenDocument();

		const char* name = d.ReadString();
		const char* type = d.ReadString();
		const char* value = d.ReadString();
		char* eventParam = NULL;
		if (!d.eod())
		{
			eventParam = (char*)d.ReadString();
		}

		this->AddPar(type, name, value, eventParam);

		d.CloseDocument(true);
	}

	void BehaviorNode::load_attachments(int version, const char* agentType, BsonDeserizer& d)
	{
		d.OpenDocument();

		BsonDeserizer::BsonTypes type = d.ReadType();
		while (type == BsonDeserizer::BT_AttachmentElement)
		{
			{
				d.OpenDocument();

				const char* attachClassName = d.ReadString();

				BehaviorNode* pAttachment = BehaviorNode::Create(attachClassName);
				if (!pAttachment)
				{
					BEHAVIAC_LOGWARNING("invalid attachment class '%s'\n", attachClassName);
				}

				BEHAVIAC_ASSERT(pAttachment);

				if (pAttachment)
				{
					pAttachment->SetClassNameString(attachClassName);

					const char* idString = d.ReadString();
					pAttachment->SetId(atoi(idString));

					pAttachment->load_properties_pars_attachments_children(version, agentType, d);

					this->Attach(pAttachment);

					this->m_bHasEvents |= (Event::DynamicCast(pAttachment) != 0);
				}

				d.CloseDocument();
			}

			type = d.ReadType();
		}

		BEHAVIAC_ASSERT(type == BsonDeserizer::BT_None);
		d.CloseDocument();
	}

}//namespace behaviac
