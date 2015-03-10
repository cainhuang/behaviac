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

using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Text;
using System.Windows.Forms;
using System.Windows.Forms.Design;
using System.Reflection;
using Behaviac.Design.Data;
using Behaviac.Design.Nodes;
using Behaviac.Design.Properties;

namespace Behaviac.Design
{
    internal partial class ParametersDock : WeifenLuo.WinFormsUI.Docking.DockContent
    {
        private static List<ParametersDock> _parameterDocks = new List<ParametersDock>();
        internal static IList<ParametersDock> Docks()
        {
            return _parameterDocks.AsReadOnly();
        }

        internal static void CloseAll()
        {
            ParametersDock[] docks = _parameterDocks.ToArray();
            foreach (ParametersDock dock in docks)
            {
                dock.Close();
            }
        }

        internal static void Inspect(AgentType agentType, string agentName, string agentFullname)
        {
            ParametersDock dock = findParametersDock(agentType, agentName);

            if (dock == null)
            {
                dock = new ParametersDock();
                dock.Show(MainWindow.Instance.DockPanel, WeifenLuo.WinFormsUI.Docking.DockState.DockBottom);
            }

            dock.InspectObject(agentType, agentName, agentFullname);
        }

        internal static void Inspect(string agentFullname, bool isPar)
        {
            Debug.Check(!string.IsNullOrEmpty(agentFullname));

            string[] tokens = agentFullname.Split('#');
            string agentName = tokens[tokens.Length - 1];

            Debug.Check(tokens.Length == 2);

            // Agent
            if (!isPar && tokens.Length > 1)
            {
                AgentType agentType = Plugin.GetAgentType(tokens[0]);

                Inspect(agentType, agentName, agentFullname);
            }
            // Par or Global
            else
            {
                Inspect(Plugin.GetInstanceAgentType(agentFullname), agentName, agentFullname);
            }
        }

        internal static void SetProperty(string agentType, string agentName, string valueName, string valueStr)
        {
            foreach (ParametersDock dock in _parameterDocks)
            {
                bool bSet = dock.setProperty(agentType, agentName, valueName, valueStr);
                if (bSet)
                    break;
            }
        }

        private static ParametersDock findParametersDock(AgentType agentType, string agentName)
        {
            foreach (ParametersDock dock in _parameterDocks)
            {
                if (dock.AgentType == agentType && (string.IsNullOrEmpty(dock.AgentName) || dock.AgentName == agentName))
                    return dock;
            }

            return null;
        }

        public ParametersDock()
        {
            InitializeComponent();

            _parameterDocks.Add(this);
        }

        protected override void OnClosed(EventArgs e)
        {
            _parameterDocks.Remove(this);

            base.OnClosed(e);
        }

        private string _agentName = string.Empty;
        private AgentType _agentType = null;

        private AgentType AgentType
        {
            get { return _agentType; }
        }

        private string AgentName
        {
            get { return _agentName; }
        }

        private void InspectObject(AgentType agentType, string agentName, string agentFullname)
        {
            Nodes.Node node = null;
            if (agentType == null && !string.IsNullOrEmpty(agentFullname))
            {
                int frame = AgentDataPool.CurrentFrame > -1 ? AgentDataPool.CurrentFrame : 0;
                string behaviorFilename = FrameStatePool.GetBehaviorFilename(agentFullname, frame);
                List<string> highlightNodeIds = FrameStatePool.GetHighlightNodeIds(agentFullname, frame, behaviorFilename);
                List<string> updatedNodeIds = FrameStatePool.GetUpdatedNodeIds(agentFullname, frame, behaviorFilename);
                Dictionary<string, FrameStatePool.NodeProfileInfos.ProfileInfo> profileInfos = FrameStatePool.GetProfileInfos(frame, behaviorFilename);

                BehaviorNode behavior = UIUtilities.ShowBehaviorTree(agentFullname, frame, highlightNodeIds, updatedNodeIds, HighlightBreakPoint.Instance, profileInfos);
                node = behavior as Nodes.Node;
            }

            _agentType = agentType;
            _agentName = agentName;

            Hide();

            setText(agentType, agentName);
            parametersPanel.InspectObject(agentType, agentFullname, node);

            if (AgentDataPool.CurrentFrame > -1 && !string.IsNullOrEmpty(agentName))
            {
                List<AgentDataPool.ValueMark> valueSet = AgentDataPool.GetValidValues(node, agentType, agentFullname, AgentDataPool.CurrentFrame);
                foreach (AgentDataPool.ValueMark value in valueSet)
                {
                    SetProperty(agentType != null ? agentType.ToString() : null, agentName, value.Name, value.Value);
                }
            }

            lostAnyFocus();
            Show();
        }

        private bool setProperty(string agentType, string agentName, string valueName, string valueStr)
        {
            if ((_agentType == null || _agentType.ToString() == agentType) && _agentName == agentName)
            {
                return parametersPanel.SetProperty(valueName, valueStr);
            }

            return false;
        }

        private void setText(AgentType agentType, string agentName)
        {
            // Par
            if (agentType == null)
            {
                Text = TabText = string.IsNullOrEmpty(agentName) ? Resources.Pars : string.Format(Resources.ParsOf, agentName);
            }
            // Global
            else if (Plugin.IsInstanceAgentType(agentType))
            {
                Text = TabText = string.Format(Resources.PropertiesOf, agentType.ToString());
            }
            // Agent
            else
            {
                Text = TabText = string.Format(Resources.PropertiesOf + "::{1}", agentType.ToString(), agentName);
            }
        }

        private void setParameter(string parName)
        {
            if (string.IsNullOrEmpty(parName))
                return;

            if (parName == VariableDef.kPar)
            {
                InspectObject(null, parName, parName);
            }
            else if (Plugin.IsInstanceName(parName))
            {
                InspectObject(Plugin.GetInstanceAgentType(parName), parName, parName);
            }
            else
            {
                if (Plugin.AgentTypes.Count > 0)
                {
                    string[] types = parName.Split(new char[] { '#' }, StringSplitOptions.RemoveEmptyEntries);
                    Debug.Check(types.Length > 0);
                    string agentName = (types.Length > 1) ? types[1] : string.Empty;

                    AgentType agentType = getAgentType(types[0]);
                    if (agentType == null)
                        agentType = Plugin.AgentTypes[0];

                    InspectObject(agentType, agentName, parName);
                }
            }
        }

        private AgentType getAgentType(string typeName)
        {
            foreach (AgentType agentType in Plugin.AgentTypes)
            {
                if (agentType.ToString() == typeName)
                    return agentType;
            }

            return null;
        }

        private void lostAnyFocus()
        {
            this.Enabled = false;
            this.Enabled = true;
        }

        private void ParametersDock_Click(object sender, EventArgs e)
        {
            lostAnyFocus();
        }
    }
}
