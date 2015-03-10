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
    /// This is the base class for all nodes which are part of a behaviour.
    /// </summary>
    public abstract partial class BaseNode
    {
        protected BaseNode _parent;

        /// <summary>
        /// The parent of this node. Can be null for root.
        /// </summary>
        public BaseNode Parent
        {
            get { return _parent; }
        }

        protected Connector _parentConnector;

        /// <summary>
        /// The connector the ode is connected to its parent with.
        /// </summary>
        public Connector ParentConnector
        {
            get { return _parentConnector; }
        }

        /// <summary>
        /// Holds a list of all children connected to this node by a connector.
        /// </summary>
        protected ConnectedChildren _children;

        /// <summary>
        /// The child nodes of this node. Is never null.
        /// </summary>
        public IList<BaseNode> Children
        {
            get { return _children.Children; }
        }

        /// <summary>
        /// Replace the children of this node from the source node.
        /// </summary>
        public void ReplaceChildren(BaseNode source)
        {
            _children = source._children;

            foreach (BaseNode child in source._children)
            {
                child._parent = this;
            }
        }

        /// <summary>
        /// Gets a connector of the node by an indentifier.
        /// </summary>
        /// <param name="identifier">The identifier of the connector we are looking for.</param>
        /// <returns>Returns null if no connector could be found.</returns>
        public Connector GetConnector(string identifier)
        {
            return _children.GetConnector(identifier);
        }

        /// <summary>
        /// Gets a connector of the node by a child connected to it.
        /// </summary>
        /// <param name="child">The child of the connector we are looking for.</param>
        /// <returns>Returns null if no connector could be found.</returns>
        public Connector GetConnector(BaseNode child)
        {
            return _children.GetConnector(child);
        }

        /// <summary>
        /// A list of all connectors registered on the node.
        /// </summary>
        public IList<Connector> Connectors
        {
            get { return _children.Connectors; }
        }

        /// <summary>
        /// Creates a new node and attaches the default attributes DebugName and ExportType.
        /// </summary>
        protected BaseNode()
        {
            _children = new ConnectedChildren(this);
        }

        /// <summary>
        /// Returns if any of the node's parents is a given node.
        /// </summary>
        /// <param name="parent">The node we want to check if it is a ancestor of this node.</param>
        /// <returns>Returns true if this node is a descendant of the given node.</returns>
        public bool HasParent(BaseNode parent)
        {
            if (_parent == null)
                return false;

            if (_parent == parent)
                return true;

            return _parent.HasParent(parent);
        }

        /// <summary>
        /// The sibling node before this one.
        /// </summary>
        public BaseNode PreviousNode
        {
            get
            {
                if (_parent == null)
                    return null;

                int n = _parent.Children.IndexOf(this);
                return n > 0 ? _parent.Children[n - 1] : null;
            }
        }

        /// <summary>
        /// The sibling node after this one.
        /// </summary>
        public BaseNode NextNode
        {
            get
            {
                if (_parent == null)
                    return null;

                int n = _parent.Children.IndexOf(this);
                return n < _parent.Children.Count - 1 ? _parent.Children[n + 1] : null;
            }
        }

        /// <summary>
        /// The behaviour this node belongs to.
        /// </summary>
        public BehaviorNode Behavior
        {
            get
            {
                BaseNode node = this;
                while (node != null)
                {
                    if (node is BehaviorNode)
                        return (BehaviorNode)node;

                    node = node._parent;
                }

                return null;
            }
        }

        /// <summary>
        /// Returns if a given noe is a sibling of this node.
        /// </summary>
        /// <param name="sibling">The assumed sibling we want to check.</param>
        /// <returns>Returns true if the given node is a sibling of this node.</returns>
        public bool IsSibling(BaseNode sibling)
        {
            if (_parent == null)
                return false;

            return _parent.Children.Contains(sibling);
        }

        /// <summary>
        /// Returns if the given node is the parent of this node and it is its last child.
        /// </summary>
        /// <param name="node">The parent we want to check if this is its last child.</param>
        /// <returns>Returns true if this node is the last child of the given node.</returns>
        public bool IsLastChildOf(BaseNode parent)
        {
            if (parent == null || parent.Children.Count < 1)
                return false;

            return parent.Children[parent.Children.Count - 1] == this;
        }

        /// <summary>
        /// This method is called before the layout gets updated so you can add new children or remove some. Used by referenced behaviour nodes.
        /// </summary>
        /// <param name="nvd">Thew NodeViewData of the node in the current view. Children can be invalid!</param>
        public virtual void PreLayoutUpdate(NodeViewData nvd)
        {
        }

        /// <summary>
        /// Returns if the parent of this node can adopt the children of this node.
        /// </summary>
        public bool ParentCanAdoptChildren
        {
            get { return _parentConnector != null && _parentConnector.AcceptsChildren(_children, true); }
        }

        /// <summary>
        /// Checks if a new node can be adopted by this one.
        /// </summary>
        /// <param name="child">The node we want to adopt.</param>
        /// <returns>Returns true if this node can adopt the given child.</returns>
        public virtual bool CanAdopt(BaseNode child)
        {
            return child != null && child.CanBeAdoptedBy(this);
        }

        /// <summary>
        /// Checks if this node can by adopted by the given one.
        /// </summary>
        /// <param name="parent">The node which can adopt this one.</param>
        /// <returns>Returns true if this node can by adopted by the given parent.</returns>
        protected virtual bool CanBeAdoptedBy(BaseNode parent)
        {
            return (parent != null);
        }

        /// <summary>
        /// Checks if an existing node can be adopted by this one.
        /// </summary>
        /// <param name="child">The node we want to adopt.</param>
        /// <returns>Returns true if this node can adopt the given child.</returns>
        public bool CanAdoptNode(BaseNode child)
        {
            return CanAdopt(child) && _children.CanAdoptNode(child);
        }

        /// <summary>
        /// Checks if the children of a node can be adopted by this one.
        /// </summary>
        /// <param name="node">The node we want to adopt its children.</param>
        /// <returns>Returns true if this node can adopt the children of the given node.</returns>
        public bool CanAdoptChildren(BaseNode node)
        {
            foreach (Connector connector in node.Connectors)
            {
                if (connector.ChildCount > 0)
                {
                    // Get the connector to adapt those children
                    Connector conn = GetConnector(connector.Identifier);

                    // Check if this connector accepts those children
                    if (conn == null || !conn.AcceptsChildren(connector))
                    {
                        return false;
                    }
                }
            }

            return true;
        }

#if DEBUG
        public virtual void DebugCheckIntegrity()
        {
            Debug.Check((_parent == null) == (_parentConnector == null));
            Debug.Check(_parentConnector == null || _parentConnector.Owner == _parent);
            Debug.Check(_parentConnector == null || _parentConnector.HasChild(this));

            if (_parent != null && _parent is ReferencedBehaviorNode)
                Debug.Check(_debugIsSubreferencedGraphNode);

            foreach (Connector connector in _children.Connectors)
            {
                for (int i = 0; i < connector.ChildCount; ++i)
                    Debug.Check(_children.Children.Contains(connector.GetChild(i)));
            }
        }

        protected bool _debugIsSubreferencedGraphNode = false;
        public bool DebugIsSubreferencedGraphNode
        {
            get { return _debugIsSubreferencedGraphNode; }
        }

        public void IsSubreferencedGraphNode()
        {
            _debugIsSubreferencedGraphNode = true;
        }
#endif
    }
}
