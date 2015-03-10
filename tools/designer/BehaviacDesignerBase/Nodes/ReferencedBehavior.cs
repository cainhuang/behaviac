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
using System.IO;
using System.Windows.Forms;
using Behaviac.Design.Attributes;
using Behaviac.Design.Properties;

namespace Behaviac.Design.Nodes
{
    public interface ReferencedBehaviorNode
    {
        BehaviorNode Reference { get; }
        string ReferenceFilename { get; set; }
        event ReferencedBehavior.ReferencedBehaviorWasModifiedEventDelegate ReferencedBehaviorWasModified;
    }

    /// <summary>
    /// This node represents a referenced behaviour which can be attached to the behaviour tree.
    /// </summary>
    public class ReferencedBehavior : Node, ReferencedBehaviorNode
    {
        protected Connector _genericChildren;
        protected BehaviorNode _referencedBehavior;

        /// <summary>
        /// The behaviour which is referenced by this node.
        /// </summary>
        public BehaviorNode Reference
        {
            get { return _referencedBehavior; }
        }

        /// <summary>
        /// The filename of the referenced behaviour.
        /// </summary>
        [DesignerString("ReferencedBehaviorFilename", "ReferencedBehaviorFilenameDesc", "CategoryBasic", DesignerProperty.DisplayMode.NoDisplay, 0, DesignerProperty.DesignerFlags.ReadOnly)]
        public string ReferenceFilename
        {
            get
            {
                if (_referencedBehavior == null)
                    return string.Empty;

                // make the path of the reference relative
                string relativeFilename = Behavior.MakeRelative(_referencedBehavior.FileManager.Filename);

                // make sure the behaviour filename is still correct
                Debug.Check(Behavior.MakeAbsolute(relativeFilename) == _referencedBehavior.FileManager.Filename);
                Debug.Check(!Path.IsPathRooted(relativeFilename));

                relativeFilename = relativeFilename.Replace('\\', '/');
                int pos = relativeFilename.IndexOf(".xml");
                if (pos != -1)
                {
                    relativeFilename = relativeFilename.Remove(pos);
                }
                
                return relativeFilename;
            }

            set
            {
                if (!string.IsNullOrEmpty(value))
                {
                    // transform referenced behaviour into an abolute path
                    string absoluteFilename = Behavior.MakeAbsolute(value);

                    // make sure the behaviour filename is still correct
                    Debug.Check(Path.IsPathRooted(absoluteFilename));

                    // update the label
                    Label = Path.GetFileNameWithoutExtension(absoluteFilename);
                    if (!absoluteFilename.EndsWith(".xml"))
                    {
                        absoluteFilename += ".xml";
                    }

                    if (!File.Exists(absoluteFilename))
                    {
                        string info = string.Format(Resources.ReferencedBehaviorError, Label);
                        MessageBox.Show(info, Resources.LoadWarning, MessageBoxButtons.OK, MessageBoxIcon.Warning);
                        return;
                    }

                    // load the referenced behaviour
                    _referencedBehavior = BehaviorManager.Instance.LoadBehavior(absoluteFilename);
                    Debug.Check(_referencedBehavior != null);

                    ((Node)_referencedBehavior).WasModified += new WasModifiedEventDelegate(referencedBehavior_WasModified);
                    _referencedBehavior.WasRenamed += new Behavior.WasRenamedEventDelegate(referencedBehavior_WasRenamed);

                    // assign the connector of the behaviour
                    _genericChildren = _referencedBehavior.GenericChildren;
                    _children.SetConnector(_genericChildren);

                    Behaviac.Design.Nodes.Behavior refB = ((Behaviac.Design.Nodes.Behavior)_referencedBehavior);
                    List<ParInfo> allPars = new List<ParInfo>();
                    ((Nodes.Node)refB).GetAllPars(ref allPars);

                    foreach (ParInfo p in allPars)
                    {
                        _pars.Add(p.Clone());
                    }
                }
            }
        }

        /// <summary>
        /// Creates a new referenced behaviour.
        /// </summary>
        /// <param name="rootBehavior">The behaviour this node belongs not. NOT the one is references.</param>
        /// <param name="referencedBehavior">The behaviour you want to reference.</param>
        public ReferencedBehavior(BehaviorNode rootBehavior, BehaviorNode referencedBehavior)
            : base(((Node)referencedBehavior).Label, Resources.ReferencedBehaviorDesc)
        {
            // when this node is saved, the children won't as they belong to another behaviour
            _saveChildren = false;

            _referencedBehavior = referencedBehavior;

            ((Node)_referencedBehavior).WasModified += new WasModifiedEventDelegate(referencedBehavior_WasModified);
            _referencedBehavior.WasRenamed += new Behavior.WasRenamedEventDelegate(referencedBehavior_WasRenamed);

            // assign the connector of the behaviour
            _genericChildren = _referencedBehavior.GenericChildren;
            _children.SetConnector(_genericChildren);

            List<ParInfo> pars = ((Node)_referencedBehavior).Pars;
            foreach (ParInfo p in pars)
            {
                _pars.Add(p.Clone());
            }
        }

        /// <summary>
        /// Creates a new referenced behaviour. The behaviour which will be referenced is read from the Reference attribute.
        /// </summary>
        public ReferencedBehavior()
            : base(string.Empty, Resources.ReferencedBehaviorDesc)
        {
            _genericChildren = new ConnectorMultiple(_children, string.Empty, "GenericChildren", 1, int.MaxValue);

            // when this node is saved, the children won't as they belong to another behaviour
            _saveChildren = false;

            _referencedBehavior = null;
        }

        public override string ExportClass
        {
            get { return "ReferencedBehavior"; }
        }

        protected override void CopyEventHandlers(Node from)
        {
            base.CopyEventHandlers(from);
            ReferencedBehaviorWasModified = ((ReferencedBehavior)from).ReferencedBehaviorWasModified;
        }

        public delegate void ReferencedBehaviorWasModifiedEventDelegate(ReferencedBehaviorNode node);

        /// <summary>
        /// Event is triggered when the behaviour referenced by this node is modified.
        /// </summary>
        public event ReferencedBehaviorWasModifiedEventDelegate ReferencedBehaviorWasModified;

        /// <summary>
        /// Handles when the behaviour referenced by this node is modified.
        /// </summary>
        /// <param name="node">The referenced behaviour node whose behaviour was modified.</param>
        void referencedBehavior_WasModified(Node node)
        {
            // update the filename and the label
            if (_referencedBehavior != null &&
                _referencedBehavior.FileManager != null &&
                _referencedBehavior.FileManager.Filename != string.Empty)
            {
                Label = Path.GetFileNameWithoutExtension(_referencedBehavior.FileManager.Filename);
            }

            // call the event
            if (ReferencedBehaviorWasModified != null)
                ReferencedBehaviorWasModified(this);
        }

        void referencedBehavior_WasRenamed(BehaviorNode node)
        {
            BehaviorWasModified();
        }

        public override void GetAllPars(ref List<ParInfo> pars)
        {
            Debug.Check(this.Reference != null);

            ((Node)this.Reference).GetAllPars(ref pars);
        }

        public override void CheckForErrors(BehaviorNode rootBehavior, List<ErrorCheck> result)
        {
            Debug.Check(this.Reference != null);

            // if our referenced behaviour could be loaded, check it as well for errors
            Behavior b = this.Reference as Behavior;
            if (b != null && b.AgentType != null)
            {
                Behavior rootB = rootBehavior as Behavior;
                Debug.Check(rootB != null);

                if (rootB.AgentType != null)
                {
                    string childBTAgent = b.AgentType.ToString();
                    string rootBTAgent = rootB.AgentType.ToString();

                    //the agent type specified at root bt should be derived from the agent type at child bt
                    if (!Plugin.IsAgentDerived(rootBTAgent, childBTAgent))
                    {
                        result.Add(new Node.ErrorCheck(this, ErrorCheckLevel.Error, Resources.AgentTypeError));
                    }
                }
            }

            List<Node.ErrorCheck> childResult = new List<Node.ErrorCheck>();
            ((Node)this.Reference).CheckForErrors(rootBehavior, childResult);

            if (childResult.Count > 0)
            {
                bool bErrorFound = false;
                foreach (var c in childResult)
                {
                    if (c.Level == ErrorCheckLevel.Error)
                    {
                        bErrorFound = true;
                        break;
                    }
                }

                result.Add(new Node.ErrorCheck(this, bErrorFound ? ErrorCheckLevel.Error : ErrorCheckLevel.Warning, bErrorFound ? Resources.ReferenceError : Resources.ReferenceWarning));
            }
        }

        public override void ResetMembers(AgentType agentType, bool resetPar)
        {
            // This function should be empty here, so don't remove it.
        }
 
        public override void GetReferencedFiles(ref List<string> referencedFiles)
        {
            Debug.Check(this.Reference != null);

            string file = this.ReferenceFilename;
            if (!string.IsNullOrEmpty(file) && !referencedFiles.Contains(file))
            {
                referencedFiles.Add(file);
            }

            ((Node)this.Reference).GetReferencedFiles(ref referencedFiles);
        }

        public override bool ResetReferenceBehavior(string referenceFilename)
        {
            Debug.Check(this.Reference != null);

            bool reset = false;

            if (this.ReferenceFilename == referenceFilename)
            {
                this.ReferenceFilename = referenceFilename;
                reset = true;
            }

            reset |= ((Node)this.Reference).ResetReferenceBehavior(referenceFilename);

            return reset;
        }

        public override void GetObjectsByType(Nodes.Node root, string nodeType, bool matchCase, bool matchWholeWord, ref List<ObjectPair> objects)
        {
            Debug.Check(this.Reference != null);

            GetObjectsBySelfType(root, nodeType, matchCase, matchWholeWord, ref objects);

            ((Node)this.Reference).GetObjectsByType(root, nodeType, matchCase, matchWholeWord, ref objects);
        }

        public override void GetObjectsByPropertyMethod(Nodes.Node root, string propertyName, bool matchCase, bool matchWholeWord, ref List<ObjectPair> objects)
        {
            Debug.Check(this.Reference != null);

            GetObjectsBySelfPropertyMethod(root, propertyName, matchCase, matchWholeWord, ref objects);

            ((Node)this.Reference).GetObjectsByPropertyMethod(root, propertyName, matchCase, matchWholeWord, ref objects);
        }

        private readonly static Brush __defaultBackgroundBrush = new SolidBrush(Color.FromArgb(140, 170, 80));
        protected override Brush DefaultBackgroundBrush
        {
            get { return __defaultBackgroundBrush; }
        }

        /// <summary>
        /// Creates a view for this node. Allows you to return your own class and store additional data.
        /// </summary>
        /// <param name="rootBehavior">The root of the graph of the current view.</param>
        /// <param name="parent">The parent of the NodeViewData created.</param>
        /// <returns>Returns a new NodeViewData object for this node.</returns>
        public override NodeViewData CreateNodeViewData(NodeViewData parent, BehaviorNode rootBehavior)
        {
            return new NodeViewDataReferencedBehavior(parent, rootBehavior, this, null, BackgroundBrush, Label, Description);
        }

        /// <summary>
        /// Searches a list for NodeViewData for this node. Internal use only.
        /// </summary>
        /// <param name="list">The list which is searched for the NodeViewData.</param>
        /// <returns>Returns null if no fitting NodeViewData could be found.</returns>
        public override NodeViewData FindNodeViewData(List<NodeViewData> list)
        {
            foreach (NodeViewData nvd in list)
            {
                if (nvd.Node is ReferencedBehavior)
                {
                    ReferencedBehavior refnode = (ReferencedBehavior)nvd.Node;

                    // if both nodes reference the same behaviour we copy the view related data
                    if (_referencedBehavior != null && refnode.Reference == _referencedBehavior ||
                        ReferenceFilename == refnode.ReferenceFilename)
                    {
                        NodeViewDataReferencedBehavior nvdrb = (NodeViewDataReferencedBehavior)nvd;
                        NodeViewDataReferencedBehavior newdata = (NodeViewDataReferencedBehavior)CreateNodeViewData(nvd.Parent, nvd.RootBehavior);

                        // copy data
                        newdata.IsExpanded = nvdrb.IsExpanded;

                        // return new data
                        return newdata;
                    }
                }

                if (nvd.Node == this)
                    return nvd;
            }

            return null;
        }

        /// <summary>
        /// Adds subitems for all children in the current connector.
        /// </summary>
        protected void AddSubItemsForConnector()
        {
            /*int count= Math.Max(_genericChildren.ChildCount, _genericChildren.MinCount);
            for(int i= 0; i <count; ++i)
            {
                Node child= i <_genericChildren.ChildCount ? _genericChildren.GetChild(i) : null;
                AddSubItem(new SubItemConnector(_genericChildren, child, i));
            }*/
        }

        /// <summary>
        /// Removes all subitems for all children in the current connector.
        /// </summary>
        protected void RemoveSubItemsForConnector()
        {
            /*for(int i= 0; i <_subItems.Count; ++i)
            {
                SubItemConnector subconn= _subItems[i] as SubItemConnector;
                if(subconn !=null && subconn.Connector ==_genericChildren)
                {
                    RemoveSubItem(subconn);
                    --i;
                }
            }*/
        }

        public override bool AddChild(Connector connector, Node node)
        {
            Debug.Check(connector.Owner == this || connector.Owner == _referencedBehavior);

            if (connector.Owner == this)
                return base.AddChild(connector, node);

            if (((Node)_referencedBehavior).AddChild(connector, node))
            {
                _children.RequiresRebuild();
                RemoveSubItemsForConnector();
                AddSubItemsForConnector();

                return true;
            }

            return false;
        }

        public override bool AddChild(Connector connector, Node node, int index)
        {
            Debug.Check(connector.Owner == this || connector.Owner == _referencedBehavior);

            if (connector.Owner == this)
                return base.AddChild(connector, node, index);

            if (((Node)_referencedBehavior).AddChild(connector, node, index))
            {
                _children.RequiresRebuild();
                RemoveSubItemsForConnector();
                AddSubItemsForConnector();

                return true;
            }

            return false;
        }

        public override bool AddChildNotModified(Node.Connector connector, Node node)
        {
            Debug.Check(connector.Owner == this || connector.Owner == _referencedBehavior);

            if (connector.Owner == this)
                return base.AddChildNotModified(connector, node);

            if (((Node)_referencedBehavior).AddChildNotModified(connector, node))
            {
                _children.RequiresRebuild();
                RemoveSubItemsForConnector();
                AddSubItemsForConnector();

                return true;
            }

            return false;
        }

        public override void RemoveChild(Connector connector, Node node)
        {
            Debug.Check(connector.Owner == this || connector.Owner == _referencedBehavior);

            if (connector.Owner == this)
            {
                base.RemoveChild(connector, node);
                return;
            }

            ((Node)_referencedBehavior).RemoveChild(connector, node);

            _children.RequiresRebuild();
            RemoveSubItemsForConnector();
        }

        protected override void CloneProperties(Node newnode)
        {
            base.CloneProperties(newnode);

            ReferencedBehavior refbehav = (ReferencedBehavior)newnode;
            refbehav.Label = Label;
            if (_referencedBehavior != null)
            {
                refbehav._referencedBehavior = _referencedBehavior;
                refbehav._genericChildren = refbehav._referencedBehavior.GenericChildren;
                refbehav._children.SetConnector(refbehav._genericChildren);
            }

            // Clone the Pars.
            Nodes.Node clone = (Nodes.Node)refbehav;
            clone.Pars.Clear();
            foreach (ParInfo par in this.Pars)
            {
                ParInfo clonePar = par.Clone();
                clone.Pars.Add(clonePar);
            }
        }
    }
}
