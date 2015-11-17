using System;
using System.Collections.Generic;
using System.Text;
using System.Drawing;
using Behaviac.Design;
using PluginBehaviac.Properties;
using Behaviac.Design.Nodes;
using Behaviac.Design.Attributes;
using Behaviac.Design.Attachments;

namespace PluginBehaviac.Nodes
{
    [NodeDesc("FSM", "state_icon")]
    public class State : Behaviac.Design.Nodes.Action
    {
        public State()
            : base(Resources.State, Resources.StateDesc)
        {
            this._methodResultOption = EBTStatus.BT_RUNNING;
        }

        public override bool IsFSM
        {
            get { return true; }
        }

        [DesignerString("Name", "NameDesc", "State", DesignerProperty.DisplayMode.NoDisplay, 0, DesignerProperty.DesignerFlags.NoExport)]
        public string Name
        {
            get { return this.Label; }
            set { this.Label = value; }
        }

        [DesignerMethodEnum("AgentMethod", "AgentMethodDesc", "Action", DesignerProperty.DisplayMode.Parameter, 1, DesignerProperty.DesignerFlags.NoFlags, MethodType.Method | MethodType.AllowNullMethod)]
        public override MethodDef Method
        {
            get { return _method; }
            set { this._method = value; }
        }

        public override Attachment CreateStartCondition(BaseNode owner)
        {
            return Attachment.Create(typeof(PluginBehaviac.Events.StartCondition), owner as Node);
        }

        [DesignerFloat("LocationX", "LocationX", "State", DesignerProperty.DisplayMode.NoDisplay, 1, DesignerProperty.DesignerFlags.NoDisplay | DesignerProperty.DesignerFlags.NoExport)]
        public float ScreenLocationX
        {
            get { return _screenLocation.X; }
            set { _screenLocation.X = value; }
        }

        [DesignerFloat("LocationY", "LocationY", "State", DesignerProperty.DisplayMode.NoDisplay, 2, DesignerProperty.DesignerFlags.NoDisplay | DesignerProperty.DesignerFlags.NoExport)]
        public float ScreenLocationY
        {
            get { return _screenLocation.Y; }
            set { _screenLocation.Y = value; }
        }

        private readonly static Brush __defaultBackgroundBrush = new SolidBrush(Color.FromArgb(79, 129, 189));
        protected override Brush DefaultBackgroundBrush
        {
            get { return __defaultBackgroundBrush; }
        }

        public override string GenerateNewLabel()
        {
            return this.Name;
        }

        public override NodeViewData CreateNodeViewData(NodeViewData parent, BehaviorNode rootBehavior)
        {
            NodeViewData nvd = base.CreateNodeViewData(parent, rootBehavior);
            nvd.ChangeShape(NodeShape.Rectangle);

            return nvd;
        }

        public override string ExportClass
        {
            get { return "State"; }
        }

        protected override bool CanBeAdoptedBy(BaseNode parent)
        {
            return base.CanBeAdoptedBy(parent) && (parent is Behavior) && (parent.IsFSM || (parent.Children.Count == 0)) && (parent.FSMNodes.Count == 0);
        }

        public override bool AcceptsAttachment(Type type)
        {
            return true;
        }

        protected override void CloneProperties(Node newnode)
        {
            base.CloneProperties(newnode);

            State state = (State)newnode;

            state.Name = this.Name;
            state.ScreenLocationX = this.ScreenLocationX;
            state.ScreenLocationY = this.ScreenLocationY;
        }

        private bool isPointedByOther()
        {
            if (this.Parent.FSMNodes.Count > 0)
            {
                foreach (Node node in this.Parent.FSMNodes)
                {
                    foreach (Attachment attachment in node.Attachments)
                    {
                        if (attachment.IsFSM && attachment.TargetFSMNodeId == this.Id)
                            return true;
                    }
                }
            }

            return false;
        }

        public override void CheckForErrors(BehaviorNode rootBehavior, List<ErrorCheck> result)
        {
            base.CheckForErrors(rootBehavior, result);

            if (string.IsNullOrEmpty(this.Name))
            {
                result.Add(new Node.ErrorCheck(this, ErrorCheckLevel.Error, "No name!"));
            }

            if (!this.isPointedByOther())
            {
                result.Add(new Node.ErrorCheck(this, ErrorCheckLevel.Warning, "This node is not transited by anyone!"));
            }
        }
    }
}
