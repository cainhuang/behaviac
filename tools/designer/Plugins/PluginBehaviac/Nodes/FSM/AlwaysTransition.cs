using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using Behaviac.Design;
using Behaviac.Design.Attributes;
using Behaviac.Design.Nodes;
using Behaviac.Design.Attachments;
using PluginBehaviac.Properties;
using PluginBehaviac.Nodes;

namespace PluginBehaviac.Events
{
    [NodeDesc("FSM", "transition_icon")]
    class AlwaysTransition : StartCondition
    {
        public AlwaysTransition(Node node)
            : base(node, Resources.AlwaysTransition, Resources.TransitionConditionDesc)
        {
        }

        public AlwaysTransition(Node node, string label, string desc)
            : base(node, label, desc)
        {
        }

        public override string ExportClass
        {
            get { return "AlwaysTransition"; }
        }

        protected override string GeneratePropertiesLabel()
        {
            return "Always";
        }

        public override bool IsStartCondition
        {
            get { return false; }
        }
    }
}
