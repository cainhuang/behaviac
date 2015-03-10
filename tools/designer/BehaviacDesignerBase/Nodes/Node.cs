////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2009, Daniel Kollmann
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without modification, are permitted
// provided that the following conditions are met:
//
// - Redistributions of source code must retain the above copyright notice, this list of conditions
//   and the following disclaimer.
//
// - Redistributions in binary form must reproduce the above copyright notice, this list of
//   conditions and the following disclaimer in the documentation and/or other materials provided
//   with the distribution.
//
// - Neither the name of Daniel Kollmann nor the names of its contributors may be used to endorse
//   or promote products derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
// FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY
// WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// The above software in this distribution may have been modified by THL A29 Limited ("Tencent Modifications").
//
// All Tencent Modifications are Copyright (C) 2015 THL A29 Limited.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

using System;
using System.Collections.Generic;
using System.Text;
using System.Drawing;
using System.Reflection;
using System.Windows.Forms;
using Behaviac.Design.Attributes;
using Behaviac.Design.Properties;
using Behaviac.Design.Attachments.Overrides;

namespace Behaviac.Design.Nodes
{
    /// <summary>
    /// This is the class for all nodes which are part of a behaviour tree and are not view data.
    /// </summary>
    public abstract partial class Node : BaseNode, NodeTag.DefaultObject, ICloneable
    {
        public enum ColorThemes
        {
            Default,
            Modern
        }

        private static ColorThemes _colorTheme = ColorThemes.Default;
        public static ColorThemes ColorTheme
        {
            get { return _colorTheme; }
            set { _colorTheme = value; }
        }

        public static Dictionary<string, Brush> BackgroundBrushes = new Dictionary<string, Brush>();

        protected readonly static Brush __backgroundBrush = new SolidBrush(Color.FromArgb(30, 99, 120));

        public Brush BackgroundBrush
        {
            get
            {
                if (ColorTheme == ColorThemes.Default)
                    return DefaultBackgroundBrush;

                string nodeName = this.GetType().FullName;
                if (BackgroundBrushes.ContainsKey(nodeName))
                    return BackgroundBrushes[nodeName];

                return __backgroundBrush;
            }
        }

        protected virtual Brush DefaultBackgroundBrush
        {
            get { return __backgroundBrush; }
        }

        protected List<ParInfo> _pars = new List<ParInfo>();
        public List<ParInfo> Pars
        {
            get { return _pars; }
            set { _pars = value; }
        }

        private bool _enable = true;
        [DesignerBoolean("Enable", "Enable or disable itself", "Debug", DesignerProperty.DisplayMode.NoDisplay, 0, DesignerProperty.DesignerFlags.NoDisplay | DesignerProperty.DesignerFlags.NoExport)]
        public bool Enable
        {
            get { return _enable; }
            set { _enable = value; }
        }

        public virtual bool CanBeDragged()
        {
            return true;
        }

        public virtual bool CanBeDeleted()
        {
            return ParentCanAdoptChildren;
        }

        public virtual bool CanBeDisabled()
        {
            return Enable ? (Parent != null && Parent.Children.Count > 1) : true;
        }

        public virtual bool AlwaysExpanded()
        {
            return false;
        }

        public virtual bool HasPrefixLabel
        {
            get { return true; }
        }

        public virtual bool HasMiddleLabel
        {
            get { return false; }
        }

        public virtual bool HasFirstLabel
        {
            get { return false; }
        }

        /// <summary>
        /// Add a new child but the behaviour does not need to be saved.
        /// Used for collapsed referenced behaviours which show the behaviours they reference.
        /// </summary>
        /// <param name="connector">The connector the node will be added to. Use null for default connector.</param>
        /// <param name="node">The node you want to append.</param>
        /// <returns>Returns true if the child could be added.</returns>
        public virtual bool AddChildNotModified(Connector connector, Node node)
        {
            Debug.Check(connector != null && _children.HasConnector(connector));

            if (!connector.AcceptsChild(node.GetType()))
            {
                //throw new Exception(Resources.ExceptionNodeHasTooManyChildren);
                return false;
            }

            if (!connector.AddChild(node))
            {
                return false;
            }

            node._parent = this;

            node.CopyWasModifiedFromParent(this);

            return true;
        }

        /// <summary>
        /// Add a new child node.
        /// </summary>
        /// <param name="connector">The connector the node will be added to. Use null for default connector.</param>
        /// <param name="node">The node you want to append.</param>
        /// <returns>Returns true if the child could be added.</returns>
        public virtual bool AddChild(Connector connector, Node node)
        {
            if (!AddChildNotModified(connector, node))
                return false;

            // behaviours must be saved
            BehaviorWasModified();

            return true;
        }

        /// <summary>
        /// Add a new child node.
        /// </summary>
        /// <param name="connector">The connector the node will be added to. Use null for default connector.</param>
        /// <param name="node">The node you want to append.</param>
        /// <param name="index">The index of the new node.</param>
        /// <returns>Returns true if the child could be added.</returns>
        public virtual bool AddChild(Connector connector, Node node, int index)
        {
            Debug.Check(connector != null && _children.HasConnector(connector));

            if (!connector.AcceptsChild(node.GetType()))
            {
                throw new Exception(Resources.ExceptionNodeHasTooManyChildren);
            }

            if (!connector.AddChild(node, index))
            {
                return false;
            }

            node._parent = this;

            BehaviorWasModified();

            return true;
        }

        /// <summary>
        /// Removes a child node.
        /// </summary>
        /// <param name="connector">The connector the child is attached to.</param>
        /// <param name="node">The child node we want to remove.</param>
        public virtual void RemoveChild(Connector connector, Node node)
        {
            Debug.Check(connector != null && _children.HasConnector(connector));

            if (!connector.RemoveChild(node))
                throw new Exception(Resources.ExceptionNodeIsNoChild);

            node._parent = null;

            BehaviorWasModified();
        }

        public new BehaviorNode Behavior
        {
            get { return ((BaseNode)this).Behavior; }
        }

        /// <summary>
        /// Determines if an attachment of a certain type is aceepted by this node or not.
        /// </summary>
        /// <param name="type">The type of the attachment we want to add.</param>
        /// <returns>Returns if the attachment may be added or not</returns>
        public virtual bool AcceptsAttachment(Type type)
        {
            return type.IsSubclassOf(typeof(Behaviac.Design.Attachments.Event));
        }

        protected List<Attachments.Attachment> _attachments;

        public IList<Attachments.Attachment> Attachments
        {
            get { return _attachments; }
        }

        public void AddAttachment(Attachments.Attachment attach)
        {
            _attachments.Add(attach);
        }

        public void AddAttachment(Attachments.Attachment attach, int index)
        {
            _attachments.Insert(index, attach);
        }

        public void RemoveAttachment(Attachments.Attachment attach)
        {
            _attachments.Remove(attach);
        }

        protected string _exportName = string.Empty;

        /// <summary>
        /// The name of the node used for the export process.
        /// </summary>
        public string ExportName
        {
            get { return _exportName; }
        }

        protected string _label;

        /// <summary>
        /// The label shown of the node.
        /// </summary>
        public string Label
        {
            get { return _label; }
            set { _label = value; }
        }

        protected readonly string _description;

        /// <summary>
        /// The description of this node.
        /// </summary>
        public virtual string Description
        {
            get { return /*Resources.ResourceManager.GetString(*/_description/*, Resources.Culture)*/; }
        }

        public virtual object[] GetExcludedEnums(DesignerEnum enumAttr)
        {
            return null;
        }

        /// <summary>
        /// Creates a new behaviour node.
        /// </summary>
        /// <param name="label">The label of the behaviour node.</param>
        /// <returns>Returns the created behaviour node.</returns>
        public static BehaviorNode CreateBehaviorNode(string label)
        {
            BehaviorNode node = (BehaviorNode)Plugin.BehaviorNodeType.InvokeMember(string.Empty, BindingFlags.CreateInstance, null, null, new object[] { label, true });

            if (node == null)
                throw new Exception(Resources.ExceptionMissingNodeConstructor);

            return node;
        }

        /// <summary>
        /// Creates a new referenced behaviour node.
        /// </summary>
        /// <param name="rootBehavior">The behaviour we are adding the reference to.</param>
        /// <param name="referencedBehavior">The behaviour we are referencing.</param>
        /// <returns>Returns the created referenced behaviour node.</returns>
        public static ReferencedBehaviorNode CreateReferencedBehaviorNode(BehaviorNode rootBehavior, BehaviorNode referencedBehavior)
        {
            ReferencedBehaviorNode node = (ReferencedBehaviorNode)Plugin.ReferencedBehaviorNodeType.InvokeMember(string.Empty, BindingFlags.CreateInstance, null, null, new object[] { rootBehavior, referencedBehavior });

            if (node == null)
                throw new Exception(Resources.ExceptionMissingNodeConstructor);

            return node;
        }

        /// <summary>
        /// Creates a node from a given type.
        /// </summary>
        /// <param name="type">The type we want to create a node of.</param>
        /// <returns>Returns the created node.</returns>
        public static Node Create(Type type)
        {
            Debug.Check(type != null);

            // use the type overrides when set
            if (type == typeof(BehaviorNode))
                type = Plugin.BehaviorNodeType;
            else if (type == typeof(ReferencedBehaviorNode))
                type = Plugin.ReferencedBehaviorNodeType;

            Debug.Check(type != null);
            Debug.Check(!type.IsAbstract);

            Node node = (Node)type.InvokeMember(string.Empty, BindingFlags.CreateInstance, null, null, new object[0]);

            if (node == null)
                throw new Exception(Resources.ExceptionMissingNodeConstructor);

            return node;
        }

        protected bool _saveChildren = true;

        /// <summary>
        /// Determines if the children of this node will be saved. Required for referenced behaviours.
        /// </summary>
        public bool SaveChildren
        {
            get { return _saveChildren; }
        }

        /// <summary>
        /// The name of the class we want to use for the exporter. This is usually the implemented node of the game.
        /// </summary>
        public virtual string ExportClass
        {
            get { return GetType().FullName; }
        }

        private Comment _comment = new Comment("");

        /// <summary>
        /// The comment object of the node.
        /// </summary>
        public Comment CommentObject
        {
            get { return _comment; }
            set { _comment = value; }
        }

        private MethodDef _enterAction;
        [DesignerMethodEnum("EnterAction", "EnterActionDesc", "NodeBasic", DesignerProperty.DisplayMode.List, 0, DesignerProperty.DesignerFlags.BeValid, MethodType.Method | MethodType.AllowNullMethod)]
        public MethodDef EnterAction
        {
            get { return _enterAction; }
            set { this._enterAction = value; }
        }

        private MethodDef _exitAction;
        [DesignerMethodEnum("ExitAction", "ExitActionDesc", "NodeBasic", DesignerProperty.DisplayMode.List, 1, DesignerProperty.DesignerFlags.BeValid, MethodType.Method | MethodType.AllowNullMethod)]
        public MethodDef ExitAction
        {
            get { return _exitAction; }
            set { this._exitAction = value; }
        }

        private int _id = -1;
        [DesignerInteger("NodeId", "NodeIdDesc", "NodeBasic", DesignerProperty.DisplayMode.NoDisplay, 2, DesignerProperty.DesignerFlags.ReadOnly | DesignerProperty.DesignerFlags.NoExport | DesignerProperty.DesignerFlags.NotPrefabRelated, null, int.MinValue, int.MaxValue, 1, null)]
        public int Id
        {
            get { return _id; }
            set { _id = value; }
        }

        /// <summary>
        /// The relative path of the prefab behavior
        /// </summary>
        private string _prefabName = string.Empty;
        [DesignerString("PrefabName", "PrefabNameDesc", "Prefab", DesignerProperty.DisplayMode.NoDisplay, 0, DesignerProperty.DesignerFlags.NoDisplay | DesignerProperty.DesignerFlags.NoExport | DesignerProperty.DesignerFlags.NotPrefabRelated)]
        public string PrefabName
        {
            get { return _prefabName; }
            set { _prefabName = value; }
        }

        /// <summary>
        /// The node id in the prefab behavior
        /// </summary>
        private int _prefabNodeId = -1;
        [DesignerInteger("PrefabNodeId", "PrefabNodeIdDesc", "Prefab", DesignerProperty.DisplayMode.NoDisplay, 1, DesignerProperty.DesignerFlags.NoDisplay | DesignerProperty.DesignerFlags.NoExport | DesignerProperty.DesignerFlags.NotPrefabRelated, null, int.MinValue, int.MaxValue, 1, null)]
        public int PrefabNodeId
        {
            get { return _prefabNodeId; }
            set { _prefabNodeId = value; }
        }

        /// <summary>
        /// If modifying the prefab data in the current node
        /// </summary>
        private bool _hasOwnPrefabData = false;
        [DesignerBoolean("HasOwnPrefabData", "HasOwnPrefabDataDesc", "Prefab", DesignerProperty.DisplayMode.NoDisplay, 2, DesignerProperty.DesignerFlags.NoDisplay | DesignerProperty.DesignerFlags.NoExport | DesignerProperty.DesignerFlags.NotPrefabRelated)]
        public bool HasOwnPrefabData
        {
            get { return _hasOwnPrefabData; }
            set { _hasOwnPrefabData = value; }
        }

        public bool IsPrefabDataDirty()
        {
            if (this.HasOwnPrefabData)
                return true;

            foreach (Node child in this.Children)
            {
                if (child.IsPrefabDataDirty())
                    return true;
            }

            return false;
        }

        /// <summary>
        /// The text of the comment shown for the node and its children.
        /// </summary>
        [DesignerString("NodeCommentText", "NodeCommentTextDesc", "CategoryComment", DesignerProperty.DisplayMode.NoDisplay, 10, DesignerProperty.DesignerFlags.NoExport | DesignerProperty.DesignerFlags.NoSave | DesignerProperty.DesignerFlags.NotPrefabRelated)]
        public string CommentText
        {
            get { return _comment == null ? string.Empty : _comment.Text; }

            set
            {
                string str = value.Trim();

                if (str.Length < 1)
                {
                    _comment = null;
                }
                else
                {
                    if (_comment == null)
                        _comment = new Comment(str);
                    else
                        _comment.Text = str;

                    if (_comment.Background == CommentColor.NoColor && !string.IsNullOrEmpty(str))
                        _comment.Background = CommentColor.Gray;
                }
            }
        }

        /// <summary>
        /// The color of the comment shown for the node and its children.
        /// </summary>
        [DesignerEnum("NodeCommentBackground", "NodeCommentBackgroundDesc", "CategoryComment", DesignerProperty.DisplayMode.NoDisplay, 20, DesignerProperty.DesignerFlags.NoExport | DesignerProperty.DesignerFlags.NoSave | DesignerProperty.DesignerFlags.NotPrefabRelated, "")]
        public CommentColor CommentBackground
        {
            get { return _comment == null ? CommentColor.NoColor : _comment.Background; }

            set
            {
                if (_comment != null)
                    _comment.Background = value;
            }
        }

        public void ResetId(bool setChildren)
        {
            Node root = (Node)this.Behavior;

            if (Id == -1 || null != Plugin.GetPreviousObjectById(root, Id, this))
            {
                Id = Plugin.NewNodeId(root);
            }

            foreach (Attachments.Attachment attach in Attachments)
            {
                attach.Id = Plugin.NewNodeId(root);
            }

            if (setChildren && !(this is ReferencedBehavior))
            {
                foreach (Node child in Children)
                {
                    child.ResetId(setChildren);
                }
            }
        }

        private void checkId()
        {
            Node root = (Node)this.Behavior;
            // If its id has existed, reset it.
            if (null != Plugin.GetPreviousObjectById(root, Id, this))
            {
                ResetId(false);

                BehaviorWasModified();
            }
        }

        private int _version;
        /// <summary>
        /// The version of this node. Used to update nodes when structure changes.
        /// </summary>
        [DesignerInteger("NodeVersion", "NodeVersionDesc", "CategoryVersion", DesignerProperty.DisplayMode.NoDisplay, 2, DesignerProperty.DesignerFlags.ReadOnly | DesignerProperty.DesignerFlags.NoExport | DesignerProperty.DesignerFlags.NoDisplay, null, int.MinValue, int.MaxValue, 1, null)]
        public int Version
        {
            get { return _version; }
            set { _version = value; }
        }

        /// <summary>
        /// The version of this node. Used to update nodes when structure changes.
        /// </summary>
        [DesignerInteger("NodeClassVersion", "NodeClassVersionDesc", "CategoryVersion", DesignerProperty.DisplayMode.NoDisplay, 3, DesignerProperty.DesignerFlags.ReadOnly | DesignerProperty.DesignerFlags.NoExport | DesignerProperty.DesignerFlags.NoSave | DesignerProperty.DesignerFlags.NoDisplay, null, int.MinValue, int.MaxValue, 1, null)]
        public int ClassVersion
        {
            get { return GetClassVersion(); }
        }

        /// <summary>
        /// Returns the current version of the class.
        /// This function should always look like this: return base.GetClassVersion() +your_version;
        /// </summary>
        /// <returns>Version of the class.</returns>
        public virtual int GetClassVersion()
        {
            return 0;
        }

        /// <summary>
        /// Is called when the version of a loaded node is lower than the class version and the node needs to be updated.
        /// </summary>
        /// <returns>Returns if the update was successful and the version number should be updated.</returns>
        public virtual bool UpdateVersion()
        {
            return true;
        }

        /// <summary>
        /// Creates a new node and attaches the default attributes DebugName and ExportType.
        /// </summary>
        /// <param name="label">The default label of the node.</param>
        /// <param name="description">The description of the node shown to the designer.</param>
        protected Node(string label, string description)
        {
            _children = new ConnectedChildren(this);

            _label = label;
            _description = description;
            _attachments = new List<Attachments.Attachment>();
        }

        /// <summary>
        /// Is called when one of the node's properties were modified.
        /// </summary>
        /// <param name="wasModified">Holds if the event was modified.</param>
        public void OnPropertyValueChanged(bool wasModified)
        {
            if (wasModified)
            {
                DoWasModified();
                BehaviorWasModified();
            }
        }

        public delegate void WasModifiedEventDelegate(Node node);

        /// <summary>
        /// Is called when the node was modified.
        /// </summary>
        public event WasModifiedEventDelegate WasModified;

        /// <summary>
        /// For internal use only.
        /// </summary>
        public void DoWasModified()
        {
            if (WasModified != null)
                WasModified(this);
        }

        public delegate void SubItemAddedEventDelegate(Node node, DesignerPropertyInfo property);
        public event SubItemAddedEventDelegate SubItemAdded;

        public void DoSubItemAdded(DesignerPropertyInfo property)
        {
            if (SubItemAdded != null)
                SubItemAdded(this, property);
        }

        /// <summary>
        /// Mark the behaviour this node belongs to as being modified.
        /// </summary>
        public virtual void BehaviorWasModified()
        {
            if (_parent != null)
                ((Node)_parent).BehaviorWasModified();
        }

        /// <summary>
        /// Is called after a property of a node was initialised, allowing further processing.
        /// </summary>
        /// <param name="property">The property which was initialised.</param>
        public virtual void PostPropertyInit(DesignerPropertyInfo property)
        {
        }

        /// <summary>
        /// Is called after the behaviour was loaded.
        /// </summary>
        /// <param name="behavior">The behaviour this node belongs to.</param>
        public void PostLoad(BehaviorNode behavior)
        {
            // update the version of the node if required
            if (_version < GetClassVersion() && UpdateVersion())
                _version = GetClassVersion();

            checkId();
        }

        /// <summary>
        /// Is called before the behaviour is saved.
        /// </summary>
        /// <param name="behavior">The behaviour this node belongs to.</param>
        public void PreSave(BehaviorNode behavior)
        {
            Version = 1;
        }

        /// <summary>
        /// Returns the name of the node's type for the attribute ExportType.
        /// This is done as the class attribute can be quite long and bad to handle.
        /// </summary>
        /// <returns>Returns the value for ExportType</returns>
        protected virtual string GetExportType()
        {
            return GetType().Name;
        }

        public int NodeCount
        {
            get
            {
                int nodeCount = 1;

                if (!(this is ReferencedBehavior))
                {
                    foreach (Node child in this._children)
                    {
                        nodeCount += child.NodeCount;
                    }
                }

                return nodeCount;
            }
        }

        public virtual void GetAllPars(ref List<ParInfo> pars)
        {
            pars.AddRange(this.Pars);

            foreach (Node child in this.Children)
            {
                child.GetAllPars(ref pars);
            }
        }

        public bool SetPrefab(string prefabName, bool prefabDirty = false, string oldPrefabName = "")
        {
            bool resetName = false;
            if (!string.IsNullOrEmpty(oldPrefabName))
            {
                if (this.PrefabName == oldPrefabName)
                {
                    this.PrefabName = prefabName;
                    resetName = true;
                }
            }
            else if (string.IsNullOrEmpty(this.PrefabName))
            {
                this.PrefabName = prefabName;
                this.PrefabNodeId = this.Id;
                this.HasOwnPrefabData = prefabDirty;
            }

            if (!(this is ReferencedBehavior))
            {
                foreach (Node child in this.Children)
                {
                    resetName |= child.SetPrefab(prefabName, prefabDirty, oldPrefabName);
                }
            }

            return resetName;
        }

        public bool ClearPrefab(string prefabName)
        {
            if (string.IsNullOrEmpty(prefabName))
                return false;

            bool clear = false;
            if (this.PrefabName == prefabName)
            {
                clear = true;

                this.PrefabName = string.Empty;
                this.PrefabNodeId = -1;
                this.HasOwnPrefabData = false;
            }

            if (!(this is ReferencedBehavior))
            {
                foreach (Node child in this.Children)
                {
                    clear |= child.ClearPrefab(prefabName);
                }
            }

            return clear;
        }

        private void ClearPrefabDirty(string prefabName)
        {
            if (this.PrefabName == prefabName)
            {
                this.HasOwnPrefabData = false;
            }

            if (!(this is ReferencedBehavior))
            {
                foreach (Node child in this.Children)
                {
                    child.ClearPrefabDirty(prefabName);
                }
            }
        }

        public void RestorePrefab(string prefabName)
        {
            if (this.PrefabName == prefabName)
            {
                this.PrefabName = string.Empty;
                this.Id = this.PrefabNodeId;
                this.PrefabNodeId = -1;
                this.HasOwnPrefabData = false;
            }

            if (!(this is ReferencedBehavior))
            {
                foreach (Node child in this.Children)
                {
                    child.RestorePrefab(prefabName);
                }
            }
        }

        public bool ResetPrefabInstances(string prefabName, Node instanceRootNode)
        {
            bool reset = instanceRootNode.ResetByPrefab(prefabName, this);

            if (!(this is ReferencedBehavior))
            {
                foreach (Node child in this.Children)
                {
                    reset |= child.ResetPrefabInstances(prefabName, instanceRootNode);
                }
            }

            return reset;
        }

        public bool ResetByPrefab(string prefabName, Node prefabNode)
        {
            bool reset = false;

            if (!this.HasOwnPrefabData && this.PrefabName == prefabName && this.PrefabNodeId == prefabNode.Id)
            {
                reset = true;

                int preId = this.Id;
                string prePrefabName = this.PrefabName;
                int prePrefabNodeId = this.PrefabNodeId;
                Comment preComment = (this.CommentObject != null) ? this.CommentObject.Clone() : null;

                prefabNode.CloneProperties(this);

                this.Id = preId;
                this.PrefabName = prePrefabName;
                this.PrefabNodeId = prePrefabNodeId;
                this.HasOwnPrefabData = false;
                this.CommentObject = preComment;

                // check the deleted children by the prefab node
                List<Node> deletedChildren = new List<Node>();
                foreach (Node child in this.Children)
                {
                    if (!child.HasOwnPrefabData && child.PrefabName == prefabName)
                    {
                        bool bFound = false;
                        foreach (Node prefabChild in prefabNode.Children)
                        {
                            if (child.PrefabNodeId == prefabChild.Id)
                            {
                                bFound = true;
                                break;
                            }
                        }

                        if (!bFound)
                        {
                            deletedChildren.Add(child);
                        }
                    }
                }

                foreach (Node child in deletedChildren)
                {
                    ((Node)child.Parent).RemoveChild(child.ParentConnector, child);
                }

                // check the added children by the prefab node
                List<Node> addedChildren = new List<Node>();
                List<int> indexes = new List<int>();
                for (int i = 0; i < prefabNode.Children.Count; ++i)
                {
                    Node prefabChild = (Node)prefabNode.Children[i];
                    bool bFound = false;
                    foreach (Node child in this.Children)
                    {
                        if (!string.IsNullOrEmpty(prefabChild.PrefabName) && child.PrefabName == prefabChild.PrefabName && child.PrefabNodeId == prefabChild.PrefabNodeId ||
                            child.PrefabName == prefabName && child.PrefabNodeId == prefabChild.Id)
                        {
                            bFound = true;
                            break;
                        }
                    }

                    if (!bFound)
                    {
                        addedChildren.Add(prefabChild);
                        indexes.Add(i);
                    }
                }

                for (int i = 0; i < addedChildren.Count; ++i)
                {
                    Node child = addedChildren[i].CloneBranch();
                    child.SetPrefab(prefabName);

                    Node.Connector conn = addedChildren[i].ParentConnector;
                    Debug.Check(conn != null);
                    Node.Connector childconn = this.GetConnector(conn.Identifier);
                    Debug.Check(childconn != null);

                    if (indexes[i] < this.Children.Count)
                        this.AddChild(childconn, child, indexes[i]);
                    else
                        this.AddChild(childconn, child);

                    child.ResetId(true);
                }
            }

            if (!(this is ReferencedBehavior))
            {
                foreach (Node child in this.Children)
                {
                    reset |= child.ResetByPrefab(prefabName, prefabNode);
                }
            }

            return reset;
        }

        public Node GetPrefabRoot()
        {
            string prefabName = this.PrefabName;
            if (!string.IsNullOrEmpty(prefabName))
            {
                Node node = this;
                Node root = this;

                while (node.Parent != null)
                {
                    string parentPrefabName = ((Node)node.Parent).PrefabName;
                    if (!string.IsNullOrEmpty(parentPrefabName))
                    {
                        if (parentPrefabName == prefabName)
                            root = (Node)node.Parent;
                        else
                            break;
                    }

                    node = (Node)node.Parent;
                }

                return root;
            }

            return null;
        }

        public BehaviorNode ApplyPrefabInstance()
        {
            string prefabName = this.PrefabName;
            if (!string.IsNullOrEmpty(prefabName))
            {
                Node root = this.GetPrefabRoot();
                if (root != null)
                {
                    string fullpath = FileManagers.FileManager.GetFullPath(prefabName);
                    BehaviorNode prefabBehavior = BehaviorManager.Instance.LoadBehavior(fullpath);
                    if (prefabBehavior != null)
                    {
                        root.ClearPrefabDirty(prefabName);

                        if (((Node)prefabBehavior).Children.Count > 0)
                        {
                            ((Node)prefabBehavior).RemoveChild(prefabBehavior.GenericChildren, (Node)((Node)prefabBehavior).Children[0]);
                        }
                        Node newnode = root.CloneBranch();
                        newnode.RestorePrefab(prefabName);
                        ((Node)prefabBehavior).AddChild(prefabBehavior.GenericChildren, newnode);

                        return prefabBehavior;
                    }
                }
            }

            return null;
        }

        public bool BreakPrefabInstance()
        {
            string prefabName = this.PrefabName;
            if (!string.IsNullOrEmpty(prefabName))
            {
                Node root = this.GetPrefabRoot();

                string fullpath = FileManagers.FileManager.GetFullPath(prefabName);
                Nodes.BehaviorNode prefabBehavior = BehaviorManager.Instance.LoadBehavior(fullpath);
                if (prefabBehavior != null)
                {
                    root.ResetByPrefab(prefabName, (Node)prefabBehavior);
                }

                return root.ClearPrefab(prefabName);
            }

            return false;
        }

        /// <summary>
        /// Checks the current node and its children for errors.
        /// </summary>
        /// <param name="rootBehavior">The behaviour we are currently checking.</param>
        /// <param name="result">The list the errors are added to.</param>
        public virtual void CheckForErrors(BehaviorNode rootBehavior, List<ErrorCheck> result)
        {
            if (!Enable)
            {
                result.Add(new Node.ErrorCheck(this, ErrorCheckLevel.Warning, Resources.Disabled));
            }

            foreach (ParInfo par in Pars)
            {
                List<ErrorCheck> parResult = new List<ErrorCheck>();
                Plugin.CheckPar(this, par, ref parResult);
                if (parResult.Count == 0)
                {
                    string info = string.Format(Resources.ParWarningInfo, par.Name);
                    result.Add(new Node.ErrorCheck(this, ErrorCheckLevel.Warning, info));
                }
            }

            foreach (Node node in _children)
            {
                node.CheckForErrors(rootBehavior, result);
            }

            foreach (Attachments.Attachment attachment in _attachments)
            {
                attachment.CheckForErrors(rootBehavior, result);
            }
        }

        public virtual void ResetMembers(AgentType agentType, bool resetPar)
        {
            if (this.EnterAction != null && this.EnterAction.ShouldBeReset(agentType, resetPar))
            {
                this.EnterAction = null;
            }

            if (this.ExitAction != null && this.ExitAction.ShouldBeReset(agentType, resetPar))
            {
                this.ExitAction = null;
            }

            foreach (Node child in this.Children)
            {
                child.ResetMembers(agentType, resetPar);
            }
        }

        public virtual void GetReferencedFiles(ref List<string> referencedFiles)
        {
            foreach (Attachments.Attachment attach in this.Attachments)
            {
                attach.GetReferencedFiles(ref referencedFiles);
            }

            foreach (Node child in this.Children)
            {
                child.GetReferencedFiles(ref referencedFiles);
            }
        }

        public virtual bool ResetReferenceBehavior(string referenceFilename)
        {
            bool reset = false;

            foreach (Node child in this.Children)
            {
                reset |= child.ResetReferenceBehavior(referenceFilename);
            }

            return reset;
        }

        public struct ObjectPair
        {
            public ObjectPair(Nodes.Node root, NodeTag.DefaultObject obj)
            {
                Root = root;
                Obj = obj;
            }

            public Nodes.Node Root;
            public NodeTag.DefaultObject Obj;
        }

        public virtual void GetObjectsByType(Nodes.Node root, string nodeType, bool matchCase, bool matchWholeWord, ref List<ObjectPair> objects)
        {
            if (root == null || string.IsNullOrEmpty(nodeType))
                return;

            GetObjectsBySelfType(root, nodeType, matchCase, matchWholeWord, ref objects);

            foreach (Attachments.Attachment attach in this.Attachments)
            {
                if (!ContainObjectPair(objects, root, attach) && CompareTwoTypes(attach.GetType().Name, nodeType, matchCase, matchWholeWord))
                    objects.Add(new ObjectPair(root, attach));
            }

            foreach (Nodes.Node child in this.Children)
            {
                child.GetObjectsByType(root, nodeType, matchCase, matchWholeWord, ref objects);
            }
        }

        protected void GetObjectsBySelfType(Nodes.Node root, string nodeType, bool matchCase, bool matchWholeWord, ref List<ObjectPair> objects)
        {
            if (root == null || string.IsNullOrEmpty(nodeType))
                return;

            if (!ContainObjectPair(objects, root, this) && CompareTwoTypes(this.GetType().Name, nodeType, matchCase, matchWholeWord))
                objects.Add(new ObjectPair(root, this));
        }

        public virtual void GetObjectsByPropertyMethod(Nodes.Node root, string propertyName, bool matchCase, bool matchWholeWord, ref List<ObjectPair> objects)
        {
            if (root == null || string.IsNullOrEmpty(propertyName))
                return;

            GetObjectsBySelfPropertyMethod(root, propertyName, matchCase, matchWholeWord, ref objects);

            foreach (Nodes.BaseNode child in this.Children)
            {
                if (child is Nodes.Node)
                {
                    Nodes.Node childNode = child as Nodes.Node;
                    childNode.GetObjectsByPropertyMethod(root, propertyName, matchCase, matchWholeWord, ref objects);
                }
            }
        }

        protected void GetObjectsBySelfPropertyMethod(Nodes.Node root, string propertyName, bool matchCase, bool matchWholeWord, ref List<ObjectPair> objects)
        {
            if (root == null || string.IsNullOrEmpty(propertyName))
                return;

            if (!ContainObjectPair(objects, root, this))
            {
                bool found = false;

                // search from its members
                Type type = this.GetType();
                foreach (System.Reflection.PropertyInfo property in type.GetProperties())
                {
                    Attribute[] attributes = (Attribute[])property.GetCustomAttributes(typeof(Behaviac.Design.Attributes.DesignerProperty), false);
                    if (attributes == null || attributes.Length == 0)
                    {
                        continue;
                    }

                    object value = property.GetValue(this, null);
                    if (value != null)
                    {
                        if (property.PropertyType == typeof(MethodDef))
                        {
                            MethodDef method = value as MethodDef;
                            Debug.Check(method != null);

                            if (CompareTwoTypes(method.Name, propertyName, matchCase, matchWholeWord) ||
                                CompareTwoTypes(method.DisplayName, propertyName, matchCase, matchWholeWord) ||
                                CompareTwoTypes(method.GetDisplayValue(), propertyName, matchCase, matchWholeWord) ||
                                CompareTwoTypes(method.GetExportValue(), propertyName, matchCase, matchWholeWord))
                            {
                                found = true;
                                break;
                            }
                        }
                        else if (property.PropertyType == typeof(VariableDef))
                        {
                            VariableDef var = value as VariableDef;
                            Debug.Check(var != null);

                            if (CompareTwoTypes(var.GetDisplayValue(), propertyName, matchCase, matchWholeWord) ||
                                CompareTwoTypes(var.GetExportValue(), propertyName, matchCase, matchWholeWord))
                            {
                                found = true;
                                break;
                            }
                        }
                        else if (property.PropertyType == typeof(RightValueDef))
                        {
                            RightValueDef rv = value as RightValueDef;
                            Debug.Check(rv != null);

                            if (CompareTwoTypes(rv.GetDisplayValue(), propertyName, matchCase, matchWholeWord) ||
                                CompareTwoTypes(rv.GetExportValue(), propertyName, matchCase, matchWholeWord))
                            {
                                found = true;
                                break;
                            }
                        }
                        else if (CompareTwoTypes(value.ToString(), propertyName, matchCase, matchWholeWord))
                        {
                            found = true;
                            break;
                        }
                    }
                }

                // search from its pars
                if (!found)
                {
                    foreach (ParInfo par in this.Pars)
                    {
                        if (CompareTwoTypes(par.Name, propertyName, matchCase, matchWholeWord))
                        {
                            found = true;
                            break;
                        }
                    }
                }

                if (found)
                {
                    objects.Add(new ObjectPair(root, this));
                }
            }
        }

        public static bool ContainObjectPair(List<ObjectPair> objects, Nodes.Node root, NodeTag.DefaultObject obj)
        {
            foreach (ObjectPair objPair in objects)
            {
                if (objPair.Root == root && objPair.Obj == obj)
                    return true;
            }

            return false;
        }

        public static bool CompareTwoObjectLists(List<ObjectPair> listA, List<ObjectPair> listB)
        {
            Debug.Check(listA != null && listB != null);

            if (listA.Count != listB.Count)
                return false;

            foreach (ObjectPair obj in listB)
            {
                if (!ContainObjectPair(listA, obj.Root, obj.Obj))
                    return false;
            }

            return true;
        }

        private static bool CompareTwoTypes(string strA, string strB, bool matchCase, bool matchWholeWord)
        {
            if (matchWholeWord)
            {
                if (matchCase)
                {
                    if (strA == strB || Plugin.GetResourceString(strA) == strB)
                        return true;
                }
                else
                {
                    strB = strB.ToLower();
                    if (strA.ToLower() == strB)
                        return true;

                    strA = Plugin.GetResourceString(strA);
                    if (strA.ToLower() == strB)
                        return true;
                }
            }
            else
            {
                if (matchCase)
                {
                    if (strA.Contains(strB) || Plugin.GetResourceString(strA).Contains(strB))
                        return true;
                }
                else
                {
                    strB = strB.ToLower();
                    if (strA.ToLower().Contains(strB))
                        return true;

                    strA = Plugin.GetResourceString(strA);
                    if (strA.ToLower().Contains(strB))
                        return true;
                }
            }

            return false;
        }

        /// <summary>
        /// Creates a view for this node. Allows you to return your own class and store additional data.
        /// </summary>
        /// <param name="rootBehavior">The root of the graph of the current view.</param>
        /// <param name="parent">The parent of the NodeViewData created.</param>
        /// <returns>Returns a new NodeViewData object for this node.</returns>
        public virtual NodeViewData CreateNodeViewData(NodeViewData parent, BehaviorNode rootBehavior)
        {
            return new NodeViewDataStyled(parent, rootBehavior, this, null, BackgroundBrush, _label, _description);
        }

        /// <summary>
        /// Searches a list for NodeViewData for this node. Internal use only.
        /// </summary>
        /// <param name="list">The list which is searched for the NodeViewData.</param>
        /// <returns>Returns null if no fitting NodeViewData could be found.</returns>
        public virtual NodeViewData FindNodeViewData(List<NodeViewData> list)
        {
            foreach (NodeViewData nvd in list)
            {
                if (nvd.Node == this)
                    return nvd;
            }

            return null;
        }

        /// <summary>
        /// Copies all the event handlers from one node to this one.
        /// </summary>
        /// <param name="from">Then node you want to copy the event handlers from.</param>
        protected virtual void CopyEventHandlers(Node from)
        {
            WasModified = from.WasModified;
        }

        /// <summary>
        /// Internally used by CloneBranch.
        /// </summary>
        /// <param name="newparent">The parent the clone children will be added to.</param>
        private void CloneChildNodes(Node newparent)
        {
            // we may not clone children of a referenced behavior
            if (newparent is ReferencedBehaviorNode)
                return;

            // for every connector...
            foreach (Connector connector in _children.Connectors)
            {
                // find the one from the new node...
                Connector localconn = newparent.GetConnector(connector.Identifier);
                Debug.Check(localconn != null);

                // and duplicate its children into the new node's connector
                for (int i = 0; i < connector.ChildCount; ++i)
                {
                    Node child = (Node)connector.GetChild(i);

                    Node newchild = (Node)child.Clone();
                    newparent.AddChild(localconn, newchild);

                    // do this for the children as well
                    child.CloneChildNodes(newchild);
                }
            }
        }

        /// <summary>
        /// Duplicates a node and all of its children.
        /// </summary>
        /// <returns>New node with new children.</returns>
        public Node CloneBranch()
        {
            Node newnode;
            if (this is ReferencedBehaviorNode)
            {
                // if we want to clone the branch of a referenced behaviour we have to create a new behaviour node for that.
                // this should only be used to visualise stuff, never in the behaviour tree itself!
                newnode = Create(typeof(BehaviorNode));
                //newnode.Label= Label;
            }
            else
            {
                newnode = Create(GetType());
                CloneProperties(newnode);
            }

            CloneChildNodes(newnode);

            newnode.OnPropertyValueChanged(false);

            return newnode;
        }

        /// <summary>
        /// Duplicates this node. Parent and children are not copied.
        /// </summary>
        /// <returns>New node without parent and children.</returns>
        public virtual object Clone()
        {
            Node newnode = Create(GetType());

            CloneProperties(newnode);

            newnode.OnPropertyValueChanged(false);

            return newnode;
        }

        private void checkPrefabFile()
        {
            if (!string.IsNullOrEmpty(this.PrefabName))
            {
                string prefabName = FileManagers.FileManager.GetFullPath(this.PrefabName);
                if (!System.IO.File.Exists(prefabName))
                {
                    this.PrefabName = string.Empty;
                    this.PrefabNodeId = -1;
                    this.HasOwnPrefabData = false;
                }
            }
        }

        /// <summary>
        /// Used to duplicate all properties. Any property added must be duplicated here as well.
        /// </summary>
        /// <param name="newnode">The new node which is supposed to get a copy of the properties.</param>
        protected virtual void CloneProperties(Node newnode)
        {
            Debug.Check(newnode != null);

            // clone properties
            newnode.Version = this.Version;
            newnode.Id = this.Id;
            newnode.Enable = this.Enable;
            newnode.WasModified = this.WasModified;
            if (this.CommentObject != null)
            {
                newnode.CommentObject = this.CommentObject.Clone();
            }

            checkPrefabFile();
            newnode.PrefabName = this.PrefabName;
            newnode.PrefabNodeId = this.PrefabNodeId;
            newnode.HasOwnPrefabData = this.HasOwnPrefabData;

            if (this.EnterAction != null)
            {
                newnode.EnterAction = (MethodDef)this.EnterAction.Clone();
            }
            if (this.ExitAction != null)
            {
                newnode.ExitAction = (MethodDef)this.ExitAction.Clone();
            }

            // clone pars.
            newnode.Pars.Clear();
            foreach (ParInfo par in this.Pars)
            {
                newnode.Pars.Add(par.Clone(newnode));
            }

            // clone attachements
            newnode.Attachments.Clear();
            foreach (Attachments.Attachment attach in _attachments)
            {
                newnode.AddAttachment(attach.Clone(newnode));
            }
        }

        /// <summary>
        /// This node will be removed from its parent and its children. The parent tries to adopt all children.
        /// </summary>
        /// <returns>Returns false if the parent cannot apobt the children and the operation fails.</returns>
        public bool ExtractNode()
        {
            // we cannot adopt children from a referenced behavior
            if (this is ReferencedBehaviorNode && _parent != null)
            {
                ((Node)_parent).RemoveChild(_parentConnector, this);
                return true;
            }

            // check if the parent is allowed to adopt the children
            if (ParentCanAdoptChildren)
            {
                Connector conn = _parentConnector;
                Node parent = (Node)_parent;

                int n = conn.GetChildIndex(this);
                Debug.Check(n >= 0);

                parent.RemoveChild(conn, this);

                // let the node's parent adopt all the children
                foreach (Connector connector in _children.Connectors)
                {
                    for (int i = 0; i < connector.ChildCount; ++i, ++n)
                        parent.AddChild(conn, (Node)connector[i], n);

                    // remove the adopted children from the old connector. Do NOT clear the _connector member which already points to the new connector.
                    connector.ClearChildrenInternal();
                }

                return true;
            }

            return false;
        }

        /// <summary>
        /// Returns a list of all properties which have a designer attribute attached.
        /// </summary>
        /// <returns>A list of all properties relevant to the designer.</returns>
        public IList<DesignerPropertyInfo> GetDesignerProperties()
        {
            return DesignerProperty.GetDesignerProperties(this.GetType());
        }

        /// <summary>
        /// Returns a list of all properties which have a designer attribute attached.
        /// </summary>
        /// <param name="comparison">The comparison used to sort the design properties.</param>
        /// <returns>A list of all properties relevant to the designer.</returns>
        public IList<DesignerPropertyInfo> GetDesignerProperties(Comparison<DesignerPropertyInfo> comparison)
        {
            return DesignerProperty.GetDesignerProperties(this.GetType(), comparison);
        }

        protected void CopyWasModifiedFromParent(Node parent)
        {
            if (parent != null)
                WasModified = parent.WasModified;
        }

        public override string ToString()
        {
            return _label;
        }

        /// <summary>
        /// Used when a DesignerNodeProperty property is exported to format the output.
        /// </summary>
        /// <returns>The format string used to write out the value.</returns>
        public virtual string GetNodePropertyExportString()
        {
            return "\"{0}\"";
        }

        /// <summary>
        /// Returns a list of properties that cannot be selected by a DesignerNodeProperty.
        /// </summary>
        /// <returns>Returns names of properties not allowed.</returns>
        public virtual string[] GetNodePropertyExcludedProperties()
        {
            return new string[] { "ClassVersion", "Version" };
        }

        /// <summary>
        /// Checks if this node has an override for a given property name.
        /// </summary>
        /// <param name="propertyName">The name of the property we are checking.</param>
        /// <returns>Returns true if there is an attachement override.</returns>
        public bool HasOverrride(string propertyName)
        {
            foreach (Attachments.Attachment attach in _attachments)
            {
                Override overr = attach as Override;
                if (overr != null && overr.PropertyToOverride == propertyName)
                {
                    return true;
                }
            }

            return false;
        }

        public string GenerateNewLabel()
        {
            // generate the new label with the arguments
            string newlabel = string.Empty;

            // check all properties for one which must be shown as a parameter on the node
            IList<DesignerPropertyInfo> properties = this.GetDesignerProperties(DesignerProperty.SortByDisplayOrder);
            int paramCount = 0;
            for (int p = 0; p < properties.Count; ++p)
            {
                // property must be shown as a parameter on the node
                if (properties[p].Attribute.Display == DesignerProperty.DisplayMode.Parameter)
                {
                    string strProperty = properties[p].GetDisplayValue(this);

                    if (paramCount > 0)
                        newlabel += this.HasMiddleLabel ? " = " : " ";

                    if (paramCount == 1 && this.HasFirstLabel)
                    {
                        newlabel += " = ";
                    }
                    else
                    {
                        newlabel += " ";
                    }

                    newlabel += strProperty;
                    paramCount++;
                }
            }

            if (paramCount > 0 && this.HasPrefixLabel)
                newlabel = this.Label + "(" + newlabel + ")";

            return newlabel;
        }
    }
}
