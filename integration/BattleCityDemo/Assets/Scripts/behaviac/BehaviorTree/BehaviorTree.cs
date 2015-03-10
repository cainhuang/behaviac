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

#define LITTLE_ENDIAN_ONLY
#define USE_STRING_COUNT_HEAD

using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Security;
using Mono.Xml;

namespace behaviac
{
    public struct property_t
    {
        public string name;
        public string value;

        public property_t(string n, string v)
        {
            name = n;
            value = v;
        }
    }

    //bson deserizer
	public class BsonDeserizer
	{
	    public enum BsonTypes
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
		}

		public bool Init(byte[] pBuffer)
        {
            try
            {
                m_pBuffer = pBuffer;
                if (m_pBuffer != null && m_pBuffer.Length > 0)
                {
                    m_BinaryReader = new BinaryReader(new MemoryStream(m_pBuffer));

                    if (this.OpenDocument())
                    {
                        return true;
                    }
                }
            }
            catch (Exception e)
            {
                Debug.Check(false, e.Message);
            }

            Debug.Check(false);
		    return false;
	    }

        private int GetCurrentIndex()
        {
            Debug.Check(this.m_BinaryReader != null);
            return (int)this.m_BinaryReader.BaseStream.Position;
        }

		public bool OpenDocument()
        {
            int head = this.GetCurrentIndex();
		    int size = this.ReadInt32();
            int end = head + size - 1;
            if (this.m_pBuffer[end] == 0)
            {
                return true;
            }
            else
            {
                Debug.Check(false);
                return false;
            }
	    }

		public void CloseDocument(bool bEatEod /*= false*/)
	    {
            int endLast = this.GetCurrentIndex();
		    if (bEatEod)
		    {
                this.m_BinaryReader.BaseStream.Position++;
		    }
		    else
		    {
                endLast--;
		    }

            Debug.Check(this.m_pBuffer[endLast] == 0);
        }

		public BsonTypes ReadType()
        {
            byte b = m_BinaryReader.ReadByte();

            return (BsonTypes)b;
	    }

		public int ReadInt32()
        {
            int i = m_BinaryReader.ReadInt32();

#if LITTLE_ENDIAN_ONLY
            Debug.Check(BitConverter.IsLittleEndian);
		    return i;
#else
		    if (BitConverter.IsLittleEndian)
		    {
			    return i;
		    }
            else
            {
                byte[] bytes = BitConverter.GetBytes(i);
		        i = (bytes[0] << 24 | bytes[1] << 16 | bytes[2] << 8 | bytes[3]);

		        return i;
            }
#endif//LITTLE_ENDIAN_ONLY
        }

		public UInt16 ReadUInt16()
	    {
            ushort us = m_BinaryReader.ReadUInt16();

#if LITTLE_ENDIAN_ONLY
            Debug.Check(BitConverter.IsLittleEndian);
            return us;
#else
		    if (BitConverter.IsLittleEndian)
		    {
			    return us;
		    }
            else
            {
		        byte[] bytes = BitConverter.GetBytes(us);
                us = (ushort)(bytes[0] << 8 | bytes[1]);

		        return us;
            }
#endif//LITTLE_ENDIAN_ONLY
        }

		public float ReadFloat()
	    {
            float f = m_BinaryReader.ReadSingle();

#if LITTLE_ENDIAN_ONLY
		    Debug.Check(BitConverter.IsLittleEndian);
		    return f;
#else
		    if (BitConverter.IsLittleEndian)
		    {
			    return f;
		    }
            else
            {
                byte[] bytes = BitConverter.GetBytes(f);
                Array.Reverse(bytes);
		        f = BitConverter.ToSingle(bytes, 0);

		        return f;
            }
#endif//LITTLE_ENDIAN_ONLY
        }

		public bool ReadBool()
	    {
            byte b = m_BinaryReader.ReadByte();

		    return (b != 0) ? true : false;
	    }

		public string ReadString()
	    {
#if USE_STRING_COUNT_HEAD
		    UInt16 count = ReadUInt16();
            byte[] bytes = m_BinaryReader.ReadBytes(count);

            // The exporter uses UTF8 to export strings,
            // so the same encoding type is used here.
            string str = System.Text.Encoding.UTF8.GetString(bytes, 0, count - 1);

            Debug.Check(this.m_pBuffer[this.GetCurrentIndex() - 1] == 0);
		    return str;
#else
            List<byte> bytes = new List<byte>();
            while (true)
            {
                byte b = m_BinaryReader.ReadByte();
                if (b == 0)
                {
                    break;
                }
                bytes.Add(b);
            }

            // The exporter uses UTF8 to export strings,
            // so the same encoding type is used here.
            string str = System.Text.Encoding.UTF8.GetString(bytes.ToArray());

		    return str;
#endif
        }

		public bool eod()
	    {
            byte c = this.m_pBuffer[this.GetCurrentIndex()];
		    return (c == 0);
	    }

        private byte[] m_pBuffer = null;
        private BinaryReader m_BinaryReader = null;
	}

    /**
    * Base class for BehaviorTree Nodes. This is the static part
    */
    public abstract class BehaviorNode
    {
        public BehaviorTask CreateAndInitTask()
        {
            BehaviorTask pTask = this.createTask();
            pTask.Init(this);

            return pTask;
        }

        public bool HasEvents()
        {
            return this.m_bHasEvents;
        }

        public void SetHasEvents(bool hasEvents)
        {
            this.m_bHasEvents = hasEvents;
        }

        public int GetChildrenCount()
        {
            if (this.m_children != null)
            {
                return this.m_children.Count;
            }

            return 0;
        }

        public BehaviorNode GetChild(int index)
        {
            if (this.m_children != null && index < this.m_children.Count)
            {
                return this.m_children[index];
            }

            return null;
        }

        public int GetAttachmentsCount()
        {
            if (this.m_attachments != null)
            {
                return this.m_attachments.Count;
            }

            return 0;
        }

        public BehaviorNode GetAttachment(int index)
        {
            if (this.m_attachments != null && index < this.m_attachments.Count)
            {
                return this.m_attachments[index];
            }

            return null;
        }

        protected BehaviorNode()
        {
        }

        ~BehaviorNode()
        {
            this.Clear();
        }

        public void Clear()
        {
            m_enterAction = null;
            m_exitAction = null;

            if (this.m_pars != null)
            {
			    foreach (Property pProperty in this.m_pars)
			    {
				    Property.DeleteFromCache(pProperty);
			    }

                this.m_pars.Clear();
                this.m_pars = null;
            }

            if (this.m_attachments != null)
            {
                this.m_attachments.Clear();
                this.m_attachments = null;
            }

            if (this.m_children != null)
            {
                this.m_children.Clear();
                this.m_children = null;
            }
        }

        public virtual bool IsValid(Agent pAgent, BehaviorTask pTask)
        {
#if !BEHAVIAC_RELEASE
            Debug.Check(!string.IsNullOrEmpty(this.m_agentType));

            return Agent.IsDerived(pAgent, this.m_agentType);
#else
            return true;
#endif//#if !BEHAVIAC_RELEASE
        }

        #region Load
        protected static BehaviorNode Create(string className)
        {
            return Workspace.CreateBehaviorNode(className);
        }

        protected virtual void load(int version, string agentType, List<property_t> properties)
        {
            foreach (property_t p in properties)
            {
                if (p.name == "EnterAction")
                {
                    if (!string.IsNullOrEmpty(p.value))
                    {
                        this.m_enterAction = Action.LoadMethod(p.value);
                    }//if (p.value[0] != '\0')
                }
                else if (p.name == "ExitAction")
                {
                    if (!string.IsNullOrEmpty(p.value))
                    {
                        this.m_exitAction = Action.LoadMethod(p.value);
                    }//if (p.value[0] != '\0')
                }
            }

            string nodeType = this.GetClassNameString().Replace(".", "::");
            Workspace.HandleNodeLoaded(nodeType, properties);
        }

		void load_par(int version, string agentType, SecurityElement node)
        {
            if (node.Tag != "par")
            {
                Debug.Check(false);
                return;
            }

            string name = node.Attribute("name");
            string type = node.Attribute("type").Replace("::", ".");
			string value = node.Attribute("value");
			string eventParam = node.Attribute("eventParam");

            this.AddPar(type, name, value, eventParam);
        }


		protected void load_properties_pars_attachments_children(bool bNode, int version, string agentType, SecurityElement node)
        {
#if !BEHAVIAC_RELEASE
            SetAgentType(agentType);
#endif//#ifdef _DEBUG

            bool bHasEvents = this.HasEvents();

			if (node.Children != null)
			{
	            List<property_t> properties = new List<property_t>();

				foreach (SecurityElement c in node.Children)
	            {
	                if (!load_property_pars(ref properties, c, version, agentType))
	                {
	                    if (bNode)
	                    {
							if (c.Tag == "attachment")
							{
	                            string pAttachClassName = c.Attribute("class");
	                            BehaviorNode pAttachment = BehaviorNode.Create(pAttachClassName);

	                            Debug.Check(pAttachment != null);

	                            if (pAttachment != null)
	                            {
	                                pAttachment.SetClassNameString(pAttachClassName);
	                                string idStr = c.Attribute("id");
	                                pAttachment.SetId(Convert.ToInt32(idStr));

	                                pAttachment.load_properties_pars_attachments_children(false, version, agentType, c);

	                                this.Attach(pAttachment);

	                                bHasEvents |= (pAttachment is Event);
	                            }
	                        }
							else if (c.Tag == "node")
							{
	                            BehaviorNode pChildNode = BehaviorNode.load(agentType, c);
	                            bHasEvents |= pChildNode.m_bHasEvents;

	                            this.AddChild(pChildNode);
	                        }
	                    }
	                }
	            }

	            if (properties.Count > 0)
	            {
	                this.load(version, agentType, properties);
	            }
			}

            this.m_bHasEvents |= bHasEvents;
        }

		private bool load_property_pars(ref List<property_t> properties, SecurityElement c, int version, string agentType)
        {
            if (c.Tag == "property")
            {
                if (c.Attributes.Count == 1)
                {
					foreach (string propName in c.Attributes.Keys)
					{
						string propValue = (string)c.Attributes[propName];
						property_t p = new property_t(propName, propValue);
                    	properties.Add(p);
						break;
					}
                }

                return true;
            }
			else if (c.Tag == "pars")
            {
				if (c.Children != null)
				{
					foreach (SecurityElement parNode in c.Children)
	                {
	                    if (parNode.Tag == "par")
	                    {
	                        this.load_par(version, agentType, parNode);
	                    }
	                }
				}

                return true;
            }

            return false;
        }
        
		protected static BehaviorNode load(string agentType, SecurityElement node)
        {
            Debug.Check(node.Tag == "node");

            int version = int.Parse(node.Attribute("version"));

            string pClassName = node.Attribute("class");
            BehaviorNode pNode = BehaviorNode.Create(pClassName);

            Debug.Check(pNode != null);
            if (pNode != null)
            {
                pNode.SetClassNameString(pClassName);
                string idStr = node.Attribute("id");
                pNode.SetId(Convert.ToInt32(idStr));

                pNode.load_properties_pars_attachments_children(true, version, agentType, node);
            }

            return pNode;
        }

        protected void load_properties(int version, string agentType, BsonDeserizer d)
        {
#if !BEHAVIAC_RELEASE
            SetAgentType(agentType);
#endif

		    d.OpenDocument();

		    //load property after loading par as property might reference par
		    List<property_t> properties = new List<property_t>();

		    BsonDeserizer.BsonTypes type = d.ReadType();
		    while (type == BsonDeserizer.BsonTypes.BT_String)
		    {
			    string propertyName = d.ReadString();
			    string propertyValue = d.ReadString();

			    properties.Add(new property_t(propertyName, propertyValue));

			    type = d.ReadType();
		    }

		    if (properties.Count > 0)
		    {
			    this.load(version, agentType, properties);
		    }

		    Debug.Check(type == BsonDeserizer.BsonTypes.BT_None);
            d.CloseDocument(false);
	    }

	    protected void load_pars(int version, string agentType, BsonDeserizer d)
	    {
		    d.OpenDocument();

		    BsonDeserizer.BsonTypes type = d.ReadType();
		    while (type == BsonDeserizer.BsonTypes.BT_ParElement)
		    {
			    this.load_par(version, agentType, d);

			    type = d.ReadType();
		    }

            Debug.Check(type == BsonDeserizer.BsonTypes.BT_None);
            d.CloseDocument(false);
	    }

	    protected void load_children(int version, string agentType, BsonDeserizer d)
	    {
		    d.OpenDocument();

		    BehaviorNode pChildNode = this.load(agentType, d);
		    bool bHasEvents = pChildNode.m_bHasEvents;

		    this.AddChild(pChildNode);

		    this.m_bHasEvents |= bHasEvents;

            d.CloseDocument(false);
	    }

	    protected void load_properties_pars_attachments_children(int version, string agentType, BsonDeserizer d)
	    {
		    BsonDeserizer.BsonTypes type = d.ReadType();

            while (type != BsonDeserizer.BsonTypes.BT_None)
		    {
                if (type == BsonDeserizer.BsonTypes.BT_PropertiesElement)
			    {
                    try
                    {
                        this.load_properties(version, agentType, d);
                    }
                    catch (Exception e)
                    {
                        Debug.Check(false, e.Message);
                    }
			    }
                else if (type == BsonDeserizer.BsonTypes.BT_ParsElement)
			    {
				    this.load_pars(version, agentType, d);
			    }
                else if (type == BsonDeserizer.BsonTypes.BT_AttachmentsElement)
			    {
				    this.load_attachments(version, agentType, d);

				    this.m_bHasEvents |= this.HasEvents();
			    }
                else if (type == BsonDeserizer.BsonTypes.BT_NodeElement)
			    {
				    this.load_children(version, agentType, d);
			    }
			    else
			    {
				    Debug.Check(false);
			    }

			    type = d.ReadType();
		    }
	    }

	    protected BehaviorNode load(string agentType, BsonDeserizer d)
	    {
		    string pClassName = d.ReadString();
            BehaviorNode pNode = BehaviorNode.Create(pClassName);
            Debug.Check(pNode != null, pClassName);

		    string verString = d.ReadString();
		    int version = Convert.ToInt32(verString);

		    if (pNode != null)
		    {
			    pNode.SetClassNameString(pClassName);
			    string idString = d.ReadString();
			    pNode.SetId(Convert.ToInt32(idString));

			    pNode.load_properties_pars_attachments_children(version, agentType, d);
		    }

		    return pNode;
	    }

	    protected void load_par(int version, string agentType, BsonDeserizer d)
	    {
		    d.OpenDocument();

		    string name = d.ReadString();
            string type = d.ReadString().Replace("::", ".");
		    string value = d.ReadString();
		    string eventParam = null;
		    if (!d.eod())
		    {
			    eventParam = d.ReadString();
		    }

		    this.AddPar(type, name, value, eventParam);

		    d.CloseDocument(true);
	    }

	    protected void load_attachments(int version, string agentType, BsonDeserizer d)
	    {
		    d.OpenDocument();

		    BsonDeserizer.BsonTypes type = d.ReadType();
            while (type == BsonDeserizer.BsonTypes.BT_AttachmentElement)
		    {
			    {
				    d.OpenDocument();

				    string attachClassName = d.ReadString();

                    BehaviorNode pAttachment = BehaviorNode.Create(attachClassName);
                    Debug.Check(pAttachment != null, attachClassName);

                    if (pAttachment != null)
				    {
					    pAttachment.SetClassNameString(attachClassName);

					    string idString = d.ReadString();
					    pAttachment.SetId(Convert.ToInt32(idString));

					    pAttachment.load_properties_pars_attachments_children(version, agentType, d);

					    this.Attach(pAttachment);

                        this.m_bHasEvents |= (pAttachment is Event);
				    }

                    d.CloseDocument(false);
			    }

			    type = d.ReadType();
		    }

            Debug.Check(type == BsonDeserizer.BsonTypes.BT_None);
            d.CloseDocument(false);
	    }
        #endregion

        public void Attach(BehaviorNode pAttachment)
        {
            if (this.m_attachments == null)
            {
                this.m_attachments = new List<BehaviorNode>();
            }

            this.m_attachments.Add(pAttachment);
        }

        public virtual void AddChild(BehaviorNode pChild)
        {
            pChild.m_parent = this;

            if (this.m_children == null)
            {
                this.m_children = new List<BehaviorNode>();
            }

            this.m_children.Add(pChild);
        }

        protected virtual EBTStatus update_impl(Agent pAgent, EBTStatus childStatus) { return EBTStatus.BT_FAILURE; }

        public void SetClassNameString(string className)
        {
            this.m_className = className;
        }

        public string GetClassNameString()
        {
            return this.m_className;
        }

        public int GetId()
        {
            return this.m_id;
        }

        public void SetId(int id)
        {
            this.m_id = id;
        }

        public void AddPar(string type, string name, string value, string eventParam)
        {
            Property pProperty = Property.Create(type, name, value, false, false);
            if (!string.IsNullOrEmpty(eventParam))
            {
                pProperty.SetRefName(eventParam);
            }

            if (this.m_pars == null)
            {
                this.m_pars = new List<Property>();
            }
            this.m_pars.Add(pProperty);
        }

#if !BEHAVIAC_RELEASE
        private string m_agentType;

        public void SetAgentType(string agentType)
        {
            this.m_agentType = agentType.Replace("::", ".");
        }

        public string GetAgentType()
        {
            return this.m_agentType;
        }
#endif
        protected abstract BehaviorTask createTask();

        public virtual bool enteraction_impl(Agent pAgent) { return false; }
        public virtual bool exitaction_impl(Agent pAgent) { return false; }

        private string m_className;
        private int m_id;

        protected List<BehaviorNode> m_attachments;
        public List<Property> m_pars;

        protected BehaviorNode m_parent;
        protected List<BehaviorNode> m_children;

        public CMethodBase m_enterAction;
        public CMethodBase m_exitAction;

        protected bool m_bHasEvents;
    };


    public abstract class DecoratorNode : BehaviorNode
    {
        public DecoratorNode()
        {
            m_bDecorateWhenChildEnds = false;
        }

        ~DecoratorNode()
        { }

		protected override void load(int version, string agentType, List<property_t> properties)
		{
			base.load(version, agentType, properties);
			foreach (property_t p in properties)
			{
				if (p.name == "DecorateWhenChildEnds")
				{
					if (p.value == "true")
					{
						this.m_bDecorateWhenChildEnds = true;
					}
				}
			}
		}

        public override bool IsValid(Agent pAgent, BehaviorTask pTask)
        {
            if (!(pTask.GetNode() is DecoratorNode))
            {
                return false;
            }

            return base.IsValid(pAgent, pTask);
        }

        public bool m_bDecorateWhenChildEnds;
    };

    // ============================================================================
    public class BehaviorTree : BehaviorNode
    {
       	protected override void load(int version, string agentType, List<property_t> properties)
	    {
		    base.load(version, agentType, properties);

		    if (properties.Count > 0)
		    {
			    foreach (property_t p in properties)
			    {
				    if (p.name == "Domains")
				    {
					    m_domains = p.value;
				    }
				    else if (p.name == "DescriptorRefs")
				    {
                        this.m_descriptorRefs = (List<Descriptor_t>)StringUtils.FromString(typeof(List<Descriptor_t>), p.value, false);

					    for (int i = 0; i < this.m_descriptorRefs.Count; ++i)
					    {
						    Descriptor_t d = this.m_descriptorRefs[i];
						    if (d.Descriptor != null)
                            {
							    d.Descriptor.SetDefaultValue(d.Reference);
                            }
					    }
				    }
				    else
				    {
					    //BEHAVIAC_ASSERT(0, "unrecognised property %s", p.name);
				    }
			    }	
		    }
	    }

        /**
        <?xml version="1.0" encoding="utf-8"?>
        <behavior agenttype="AgentTest">
        <!--EXPORTED BY TOOL, DON'T MODIFY IT!-.
        <!--Source File: ... -.
        <node class="DecoratorLoopTask">
        <property Count="10" />
        <node class="SelectorTask">
            ...
        </node>
        </node>
        </behavior>
        */
        public bool load_xml(byte[] pBuffer)
        {
			try
			{
	            Debug.Check(pBuffer != null);
	            string xml = System.Text.Encoding.UTF8.GetString(pBuffer);

				SecurityParser xmlDoc = new SecurityParser();
				xmlDoc.LoadXml(xml);

				SecurityElement behaviorNode = xmlDoc.ToXml();
				if (behaviorNode.Tag != "behavior" && (behaviorNode.Children == null || behaviorNode.Children.Count != 1))
	            {
	                return false;
	            }

	            this.m_name = behaviorNode.Attribute("name");
	            string agentType = behaviorNode.Attribute("agenttype");
	            string versionStr = behaviorNode.Attribute("version");
	            int version = int.Parse(versionStr);

	            this.SetClassNameString("BehaviorTree");
	            this.SetId(-1);

	            this.load_properties_pars_attachments_children(true, version, agentType, behaviorNode);

				return true;
			}
			catch (Exception e)
			{
				Debug.Check(false, e.Message);
			}

			Debug.Check(false);
            return false;
        }

        public bool load_bson(byte[] pBuffer)
	    {
            try
            {
                BsonDeserizer d = new BsonDeserizer();

                if (d.Init(pBuffer))
                {
                    BsonDeserizer.BsonTypes type = d.ReadType();
                    if (type == BsonDeserizer.BsonTypes.BT_BehaviorElement)
                    {
                        bool bOk = d.OpenDocument();
                        Debug.Check(bOk);

                        this.m_name = d.ReadString();
                        string agentType = d.ReadString();
                        string versionStr = d.ReadString();
                        int version = Convert.ToInt32(versionStr);

                        this.SetClassNameString("BehaviorTree");
                        this.SetId(-1);

                        this.load_properties_pars_attachments_children(version, agentType, d);

                        d.CloseDocument(false);

                        return true;
                    }
                }
            }
            catch (Exception e)
            {
                Debug.Check(false, e.Message);
            }

            Debug.Check(false);
            return false;
	    }
	
        public static void Cleanup()
        {
            Workspace.UnLoadAll();
        }

        //return the path relative to the workspace path
        protected string m_name;
        public string GetName()
        {
            return this.m_name;
        }

        public void SetName(string name)
        {
            this.m_name = name;
        }

        public BehaviorTree()
        {
        }

        ~BehaviorTree()
        {
            if (m_descriptorRefs != null)
            {
                m_descriptorRefs.Clear();
            }
        }

        protected override BehaviorTask createTask()
        {
            BehaviorTreeTask pTask = new BehaviorTreeTask();
            return pTask;
        }

        public class Descriptor_t
		{
			public Property	Descriptor;
            public Property Reference;

            public Descriptor_t()
			{}

            public Descriptor_t(Descriptor_t copy)
			{
				Descriptor = copy.Descriptor != null ? copy.Descriptor.clone() : null;
				Reference = copy.Reference != null ? copy.Reference.clone() : null;
            }

			~Descriptor_t()
			{
				this.Descriptor = null;
				this.Reference = null;
			}
		};

        protected string m_domains;

		public string GetDomains()
		{
			return this.m_domains;
		}
		
		public void SetDomains(string domains)
		{
			this.m_domains = domains;
		}

        List<Descriptor_t> m_descriptorRefs;

        public List<Descriptor_t> GetDescriptors()
        {
            return m_descriptorRefs;
        }

		public void SetDescriptors(string descriptors)
		{
			this.m_descriptorRefs = (List<Descriptor_t>)StringUtils.FromString(typeof(List<Descriptor_t>), descriptors, false);
			
			for (int i = 0; i < this.m_descriptorRefs.Count; ++i)
			{
				Descriptor_t d = this.m_descriptorRefs[i];
				d.Descriptor.SetDefaultValue(d.Reference);
			}
		}
    };
}