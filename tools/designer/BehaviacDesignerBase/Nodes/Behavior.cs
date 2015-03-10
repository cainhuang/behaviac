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

//#define QUERY_EANBLED

using System;
using System.Collections.Generic;
using System.Text;
using System.Drawing;
using System.IO;
using Behaviac.Design.Attributes;
using Behaviac.Design.Attachments;
using Behaviac.Design.Properties;


namespace Behaviac.Design.Nodes
{
    public interface BehaviorNode : ICloneable
    {
        FileManagers.FileManager FileManager { get; set; }
        string Folder { get; set; }
        string Filename { get; set; }
        string RelativePath { get; }
        bool IsPrefab { get; set; }

        void Restore(BehaviorNode source);

        AgentType AgentType { get; set; }
        int ModificationID { get; }
        bool IsModified { get; set; }
        Node.Connector GenericChildren { get; }

        string MakeAbsolute(string filename);
        string MakeRelative(string filename);

        void TriggerWasSaved();
        void TriggerWasRenamed();
        string GetPathLabel(string behaviorFolder);

        event Behavior.AgentTypeEventDelegate AgentTypeChanged;
        event Behavior.WasSavedEventDelegate WasSaved;
        event Behavior.WasRenamedEventDelegate WasRenamed;
    }

    /// <summary>
    /// This node represents the behaviour tree's root node.
    /// </summary>
    public class Behavior : Node, BehaviorNode
    {
        public override string ExportClass
        {
            get { return "Behavior"; }
        }

        public override bool AlwaysExpanded()
        {
            return true;
        }

        public override bool CanBeDragged()
        {
            return false;
        }

        public void Restore(BehaviorNode source)
        {
            Debug.Check(source is Nodes.Node);

            Behavior sourceBehavior = (Behavior)source;
            Behavior targetBehavior = (Behavior)this;

            // Restore the agent type.
            targetBehavior.AgentType = sourceBehavior.AgentType;

            // Restore the child connector.
            targetBehavior._genericChildren = sourceBehavior._genericChildren;

            Node sourceNode = (Node)source;
            Node targetNode = (Node)this;

            // Restore the hierarchy.
            targetNode.ReplaceChildren(sourceNode);

            sourceBehavior.CloneProperties(this);
        }

        public override object Clone()
        {
            // Clone the hierarchy.
            Nodes.BehaviorNode behavior = (Nodes.BehaviorNode)this.CloneBranch();

            // Set the agent type.
            behavior.AgentType = this.AgentType;

            // Clone the file manager.
            if (this.FileManager != null)
            {
                behavior.FileManager = (FileManagers.FileManager)this.FileManager.Clone();
                behavior.FileManager.Behavior = behavior;
            }
            else
            {
                behavior.Filename = this.Filename;
            }

            return behavior;
        }

        private bool _isVisiting = false;

        private string _folder = "";
        public string Folder
        {
            get { return _folder; }
            set { _folder = value; }
        }

        private bool _isPrefab = false;
        public bool IsPrefab
        {
            get { return _isPrefab; }
            set { _isPrefab = value; }
        }

        protected Connector _genericChildren;
        public Connector GenericChildren
        {
            get { return _genericChildren; }
        }

        private bool _isModified = false;

        /// <summary>
        /// This flag determines if the behaviour was modified, so it can be saved when closing the editor.
        /// </summary>
        public bool IsModified
        {
            get { return _isModified; }
            set 
            { 
                _isModified = value;
                UpdateModified();
            }
        }

        protected FileManagers.FileManager _fileManager = null;

        /// <summary>
        /// The file manager the behaviour was saved with. Required so you can simply click save later on.
        /// </summary>
        public FileManagers.FileManager FileManager
        {
            get { return _fileManager; }
            set { _fileManager = value; }
        }

        private void UpdateModified()
        {
            if (!_isModified && _fileManager != null)
                Label = Path.GetFileNameWithoutExtension(_fileManager.Filename);

            if (!_isModified && WasSaved != null)
                WasSaved(this);
        }

        /// <summary>
        /// The filename of the behaviour.
        /// </summary>
        //[DesignerString("BehaviorFilename", "BehaviorFilenameDesc", "CategoryBasic", DesignerProperty.DisplayMode.NoDisplay, 0, DesignerProperty.DesignerFlags.ReadOnly|DesignerProperty.DesignerFlags.NoExport|DesignerProperty.DesignerFlags.NoSave)]
        private string _filename = string.Empty;
        public string Filename
        {
            get 
            { 
                return (_fileManager == null) ? _filename : _fileManager.Filename; 
            }

            set
            {
                _filename = value;

                if (_fileManager != null)
                {
                    _fileManager.Filename = _filename;
                }
            }
        }
#if QUERY_EANBLED
        //private string _EventName = "";
        //[DesignerString("BehaviorEventName", "BehaviorEventNameDesc", "CategoryBasic", DesignerProperty.DisplayMode.NoDisplay, 0, DesignerProperty.DesignerFlags.NoExport)]
        //public string EventName
        //{
        //    get { return _EventName; }
        //    set { _EventName = value; }
        //}

        private string _domains = "";
        [DesignerString("BehaviorDomains", "BehaviorDomainsDesc", "Query", DesignerProperty.DisplayMode.NoDisplay, 0, DesignerProperty.DesignerFlags.NoFlags | DesignerProperty.DesignerFlags.QueryRelated)]
        public string Domains
        {
            get { return _domains; }
            set { _domains = value; }
        }

        public class DescriptorRef
        {
            private VariableDef _descriptor;
            [DesignerPropertyEnum("Descriptor", "DescriptorDesc", "Query", DesignerProperty.DisplayMode.NoDisplay, 1, DesignerProperty.DesignerFlags.NoFlags, DesignerPropertyEnum.AllowStyles.Self | DesignerPropertyEnum.AllowStyles.Global, "", "Reference")]
            public VariableDef Descriptor
            {
                get { return _descriptor; }
                set { _descriptor = value; }
            }

            private VariableDef _reference;

            [DesignerPropertyEnum("Reference", "ReferenceDesc", "Query", DesignerProperty.DisplayMode.NoDisplay, 2, DesignerProperty.DesignerFlags.NoFlags, DesignerPropertyEnum.AllowStyles.Const, "Descriptor", "")]
            public VariableDef Reference
            {
                get { return _reference; }
                set { _reference = value; }
            }
        }

        private List<DescriptorRef> _descriptorRefs = new List<DescriptorRef>();

        [DesignerArrayStruct("DescriptorRefs", "DescriptorRefsDesc", "Query", DesignerProperty.DisplayMode.NoDisplay, 1, DesignerProperty.DesignerFlags.NoSave | DesignerProperty.DesignerFlags.NoExport | DesignerProperty.DesignerFlags.QueryRelated)]
        public List<DescriptorRef> DescriptorRefs
        {
            get { return _descriptorRefs; }
            set { this._descriptorRefs = value; }
        }
#endif//#if QUERY_EANBLED

        private AgentType _agentType;
        public delegate void AgentTypeEventDelegate(AgentType agentType);
        public event AgentTypeEventDelegate AgentTypeChanged;

        /// <summary>
        /// The AgentType of the behaviour.
        /// </summary>
        [DesignerTypeEnum("BehaviorAgentType", "BehaviorAgentTypeDesc", "CategoryBasic", DesignerProperty.DisplayMode.Parameter, 0, DesignerProperty.DesignerFlags.NoExport)]
        public AgentType AgentType
        {
            get { return _agentType; }
            set
            {
                if (this._agentType != value)
                {
                    bool bEmpty = (this._agentType == null);
                    this._agentType = value;

                    if (!bEmpty && this.Children.Count > 0 && AgentTypeChanged != null)
                    {
                        AgentTypeChanged(value);
                    }
                }
            }
        }

        public Behavior(string label, bool createConnector = true)
            : base(label, "BehaviorDesc")
        {
            if (createConnector)
                _genericChildren = new ConnectorSingle(_children, string.Empty, "GenericChildren");
        }

        public Behavior()
            : this(string.Empty)
        {
        }

        private readonly static Brush __defaultBackgroundBrush = new SolidBrush(Color.FromArgb(100, 120, 80));
        protected override Brush DefaultBackgroundBrush
        {
            get { return __defaultBackgroundBrush; }
        }

        private static string _behaviorPath = "";
        public static string BehaviorPath
        {
            get { return _behaviorPath; }
            set { _behaviorPath = value; }
        }

        /// <summary>
        /// Makes a filename relative to the filename of this behaviour. Used for referenced behaviours.
        /// </summary>
        /// <param name="filename">The filename which will become relative to this behaviour.</param>
        /// <returns>Returns the relative filename of the filename parameter.</returns>
        public string MakeRelative(string filename)
        {
            //return FileManagers.FileManager.MakeRelative(Path.GetDirectoryName(_fileManager.Filename), filename);
            return FileManagers.FileManager.MakeRelative(_behaviorPath, filename);
        }

        public string RelativePath
        {
            get { return string.IsNullOrEmpty(Filename) ? string.Empty : MakeRelative(Filename); }
        }

        /// <summary>
        /// Makes a filename absolute which is relative to the filename of this behaviour. Used for referenced behaviours.
        /// </summary>
        /// <param name="filename">The filename which is relative and will become absolute.</param>
        /// <returns>Returns the sbolute filename of the filename parameter.</returns>
        public string MakeAbsolute(string filename)
        {
            //return FileManagers.FileManager.MakeAbsolute(Path.GetDirectoryName(_fileManager.Filename), filename);
            return FileManagers.FileManager.MakeAbsolute(_behaviorPath, filename);
        }

        public delegate void WasSavedEventDelegate(BehaviorNode node);

        /// <summary>
        /// Is called when the behaviour was saved.
        /// </summary>
        public event WasSavedEventDelegate WasSaved;

        public void TriggerWasSaved()
        {
            _isModified = false;

            if (WasSaved != null)
                WasSaved(this);
        }

        public delegate void WasRenamedEventDelegate(BehaviorNode node);

        /// <summary>
        /// Is called when the behaviour is renamed.
        /// </summary>
        public event WasRenamedEventDelegate WasRenamed;

        public void TriggerWasRenamed()
        {
            if (WasRenamed != null)
                WasRenamed(this);
        }

        protected int _modificationID = 0;

        /// <summary>
        /// The ID of the last modification. This allows the referenced behaviours to check if they still represent the latest version of the behaviour.
        /// </summary>
        public int ModificationID
        {
            get { return _modificationID; }
        }

        /// <summary>
        /// Marks this behaviour as being modified.
        /// </summary>
        /// <param name="layoutChanged">If true causes the view to recalculate the layout.</param>
        public override void BehaviorWasModified()
        {
            //_isModified = true;

            // update the modification ID
            _modificationID++;

            // call WasModified event
            DoWasModified();
        }

        /// <summary>
        /// Returns the relative filename and path of the behaviour.
        /// Used to show a unique behaviour name in the CheckForErrors dialogue.
        /// </summary>
        /// <param name="behaviorFolder">The root folder of the behaviour.</param>
        /// <returns>Returns a string with the relative path of this behaviour.</returns>
        public string GetPathLabel(string behaviorFolder)
        {
            string label = Label;
            if (FileManager != null && FileManager.Filename != string.Empty)
            {
                // cut away the behaviour folder
                label = FileManager.Filename.Substring(behaviorFolder.Length + 1);

                // remove the extension
                string ext = System.IO.Path.GetExtension(label);
                label = label.Substring(0, label.Length - ext.Length);

                // replace ugly back-slashes with nicer forward-slashes
                label = label.Replace('\\', '/');
            }

            return label;
        }

        public override void GetAllPars(ref List<ParInfo> pars)
        {
            if (!this._isVisiting)
            {
                this._isVisiting = true;

                base.GetAllPars(ref pars);

                this._isVisiting = false;
            }
        }

        public override void CheckForErrors(BehaviorNode rootBehavior, List<ErrorCheck> result)
        {
            if (!this._isVisiting)
            {
                this._isVisiting = true;

                // check if the node has any children
                if (_genericChildren.ChildCount < 1)
                    result.Add(new Node.ErrorCheck(this, ErrorCheckLevel.Error, Resources.BehaviorIsEmptyError));

                if (this._agentType == null)
                    result.Add(new Node.ErrorCheck(this, ErrorCheckLevel.Error, Resources.NoAgent));

                base.CheckForErrors(rootBehavior, result);

                this._isVisiting = false;
            }
        }

        public override void ResetMembers(AgentType agentType, bool resetPar)
        {
            if (!this._isVisiting)
            {
                this._isVisiting = true;

                base.ResetMembers(agentType, resetPar);

                this._isVisiting = false;
            }
        }

        public override void GetReferencedFiles(ref List<string> referencedFiles)
        {
            if (!this._isVisiting)
            {
                this._isVisiting = true;

                base.GetReferencedFiles(ref referencedFiles);

                this._isVisiting = false;
            }
        }

        public override bool ResetReferenceBehavior(string referenceFilename)
        {
            bool reset = false;

            if (!this._isVisiting)
            {
                this._isVisiting = true;

                reset = base.ResetReferenceBehavior(referenceFilename);

                this._isVisiting = false;
            }

            return reset;
        }

        public override void GetObjectsByType(Nodes.Node root, string nodeType, bool matchCase, bool matchWholeWord, ref List<ObjectPair> objects)
        {
            if (!this._isVisiting)
            {
                this._isVisiting = true;

                base.GetObjectsByType(root, nodeType, matchCase, matchWholeWord, ref objects);

                this._isVisiting = false;
            }
        }

        public override void GetObjectsByPropertyMethod(Nodes.Node root, string propertyName, bool matchCase, bool matchWholeWord, ref List<ObjectPair> objects)
        {
            if (!this._isVisiting)
            {
                this._isVisiting = true;

                base.GetObjectsByPropertyMethod(root, propertyName, matchCase, matchWholeWord, ref objects);

                this._isVisiting = false;
            }
        }
    }
}
