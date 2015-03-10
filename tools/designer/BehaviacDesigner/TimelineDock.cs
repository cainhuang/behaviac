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
using Behaviac.Design.Network;
using Behaviac.Design.Nodes;
using Behaviac.Design.Properties;
using WeifenLuo.WinFormsUI.Docking;

namespace Behaviac.Design
{
    internal partial class TimelineDock : WeifenLuo.WinFormsUI.Docking.DockContent
    {
        private static TimelineDock _timelineDock = null;

        internal static void Inspect()
        {
            if (_timelineDock == null || !_timelineDock.Visible)
            {
                _timelineDock = new TimelineDock();
                _timelineDock.Show(MainWindow.Instance.DockPanel.DockWindows[DockState.DockTop].DockPanel, WeifenLuo.WinFormsUI.Docking.DockState.DockTop);
                _timelineDock.Show();

                while (!_timelineDock._loaded && !_timelineDock.IsHandleCreated)
                {
                    System.Threading.Thread.Sleep(10);
                }

                Debug.Check(_timelineDock.IsHandleCreated);
            }
            else
            {
                _timelineDock.Show();
            }
        }

        internal static void UpdateUIState(EditModes editMode)
        {
            if (_timelineDock != null)
            {
                if (Plugin.UpdateMode == UpdateModes.Continue)
                {
                    _timelineDock.playButton.Image = Resources.Pause;
                    _timelineDock.toolTip.SetToolTip(_timelineDock.playButton, "Pause");
                    _timelineDock.numericUpDownFPS.Visible = false;
                    _timelineDock.effectTimer.Enabled = true;
                    _timelineDock.checkBoxBreakCPP.Visible = true;
                    _timelineDock.checkBoxBreakCPP.Checked = Settings.Default.BreakAPP;
                    //_timelineDock.playButton.Enabled = !Settings.Default.BreakAPP;
                }
                else
                {
                    _timelineDock.playButton.Image = Resources.Play;
                    _timelineDock.toolTip.SetToolTip(_timelineDock.playButton, "Continue (F5)");
                    _timelineDock.numericUpDownFPS.Visible = true;
                    _timelineDock.effectTimer.Enabled = false;
                    _timelineDock.checkBoxBreakCPP.Visible = false;
                }

                if (editMode != EditModes.Connect)
                {
                    MessageQueue.IsConnected = false;
                }

                _currentFrame = AgentDataPool.TotalFrames;
            }
        }

        internal static void CloseAll()
        {
            if (_timelineDock != null)
            {
                _timelineDock.Close();

                MessageQueue.ContinueHandler -= _timelineDock.Continue_handler;
                FrameStatePool.UpdateAppLogHandler -= _timelineDock.FrameStatePool_UpdateAppLogHandler;

                _timelineDock = null;
            }
        }

        internal static void SetCurrentFrame(int frame)
        {
            if (_timelineDock != null)
                _timelineDock.setCurrentFrame(frame);
        }

        internal static void SetTotalFrame(int totalFrame, int firstFrame = -1)
        {
            if (_timelineDock != null)
            {
                if (totalFrame < 0)
                    totalFrame = 0;

                _timelineDock.setFrame(totalFrame, firstFrame);
            }
        }

        private static void updateUI(int frame)
        {
            if (_timelineDock != null)
            {
                //when breaking cpp, only check breakpoints after [connected], i.e. skip breakpoints before connecting
                if (!Settings.Default.BreakAPP || MessageQueue.IsConnected)
                {
                    HighlightBreakPoint breakPoint = HighlightBreakPoint.Instance;
                    string agentName = Plugin.DebugAgentInstance;

                    if (breakPoint != null || agentName == Plugin.DebugAgentInstance)
                    {
                        List<string> highlightNodeIds = null;
                        List<string> updatedNodeIds = null;
                        Dictionary<string, FrameStatePool.NodeProfileInfos.ProfileInfo> profileInfos = null;

                        if (!string.IsNullOrEmpty(agentName))
                        {
                            string behaviorFilename = FrameStatePool.GetBehaviorFilename(agentName, frame);
                            if (!string.IsNullOrEmpty(behaviorFilename))
                            {
                                highlightNodeIds = FrameStatePool.GetHighlightNodeIds(agentName, frame, behaviorFilename);
                                updatedNodeIds = FrameStatePool.GetUpdatedNodeIds(agentName, frame, behaviorFilename);
                                profileInfos = FrameStatePool.GetProfileInfos(frame, behaviorFilename);
                            }
                        }

                        _timelineDock.updateHighlights(agentName, frame, highlightNodeIds, updatedNodeIds, breakPoint, profileInfos);

                        if (breakPoint != null)
                        {
                            string prompt = string.Format("Break: {0}->{1}[{2}]:{3}", breakPoint.BehaviorFilename, breakPoint.NodeType, breakPoint.NodeId, breakPoint.ActionName);
                            if (breakPoint.ActionResult == "success" || breakPoint.ActionResult == "failure")
                            {
                                prompt += string.Format(" [{0}]", breakPoint.ActionResult);
                            }

                            _timelineDock.setUpdateMode(UpdateModes.Break, prompt);
                        }
                    }
                }
            }
        }

        private void FrameStatePool_UpdateAppLogHandler(int frame, string appLog)
        {
            if (Plugin.UpdateMode == UpdateModes.Continue)
            {
                SetTotalFrame(frame);
                AgentDataPool.CurrentFrame = AgentDataPool.TotalFrames;

                if (_timelineDock != null)
                {
                    //when breaking cpp, only check breakpoints after [connected], i.e. skip breakpoints before connecting
                    if (!Settings.Default.BreakAPP || MessageQueue.IsConnected)
                    {
                        _timelineDock.setUpdateMode(UpdateModes.Break, appLog);
                    }
                }
            }
        }

        public TimelineDock()
        {
            InitializeComponent();

            this.Enabled = (Plugin.EditMode != EditModes.Design);

            _timelineDock = this;
            _timelineDock.promptLabel.Text = "";

            _loaded = false;

            MessageQueue.ContinueHandler += Continue_handler;
            FrameStatePool.UpdateAppLogHandler += FrameStatePool_UpdateAppLogHandler;

            this.Disposed += new EventHandler(TimelineDock_Disposed);
        }

        void TimelineDock_Disposed(object sender, EventArgs e)
        {
            this.Disposed -= TimelineDock_Disposed;

            if (this.toolTip != null)
            {
                this.toolTip.Dispose();
                this.toolTip = null;
            }
        }

        protected override void OnClosed(EventArgs e)
        {
            // Just hide this instance, instead of closing it.
            this.Hide();
        }

        private void setLabels()
        {
            startLabel.Text = trackBar.Minimum.ToString();
            endLabel.Text = trackBar.Maximum.ToString();
        }

        private void setFrame(int frame, int firstFrame = -1)
        {
            if (frame > -1 && trackBar.Value != frame)
            {
                trackBar.Minimum = (firstFrame < 0) ? 0 : firstFrame;

                if (frame > 0)
                {
                    gotoNumericUpDown.Maximum = frame;
                    //gotoNumericUpDown.Value = frame;
                    trackBar.Maximum = frame;
                }

                trackBar.TickFrequency = trackBar.Maximum / 10;
                trackBar.SmallChange = trackBar.TickFrequency / 2;
                trackBar.LargeChange = trackBar.TickFrequency;
                trackBar.Value = frame;

                setLabels();
            }
        }

        private void setCurrentFrame(int frame)
        {
            if (frame > -1)
            {
                //gotoNumericUpDown.Value = frame;
                trackBar.Value = frame;
            }
        }

        private void updateParameters(AgentType agentType, string agentName, int frame)
        {
            if (string.IsNullOrEmpty(agentName))
                return;

            string typeName = (agentType == null) ? agentName : agentType.ToString();
            string agentFullname = (agentType == null) ? agentName : agentType.ToString() + "#" + agentName;
            List<AgentDataPool.ValueMark> values = AgentDataPool.GetValidValues(_updateNode, agentType, agentFullname, frame);
            foreach (AgentDataPool.ValueMark value in values)
            {
                ParametersDock.SetProperty(typeName, agentName, value.Name, value.Value);
            }
        }

        private Nodes.Node _updateNode = null;
        private void updateHighlights(string agentFullname, int frame, List<string> highlightNodeIds, List<string> updatedNodeIds, HighlightBreakPoint breakPoint, Dictionary<string, FrameStatePool.NodeProfileInfos.ProfileInfo> profileInfos)
        {
            //if (agentFullname == Plugin.DebugAgentInstance || breakPoint != null)
            {
                BehaviorNode behavior = UIUtilities.ShowBehaviorTree(agentFullname, frame, highlightNodeIds, updatedNodeIds, breakPoint, profileInfos);
                _updateNode = behavior as Nodes.Node;
            }
        }

        private string _break_prompt = "";
        private HighlightBreakPoint checkBreakpoint(string behaviorFilename, List<FrameStatePool.FrameState.Action> actions, ref int lastBreakPointIndex)
        {
            if (string.IsNullOrEmpty(behaviorFilename) || actions == null)
                return null;

            int index = -1;
            foreach (FrameStatePool.FrameState.Action action in actions)
            {
                DebugDataPool.BreakPoint breakPoint = DebugDataPool.FindBreakPoint(behaviorFilename, action.NodeId, action.Name);
                if (breakPoint != null && breakPoint.IsActive(action.Name, action.Result))
                {
                    index++;
                    if (index == lastBreakPointIndex)
                    {
                        lastBreakPointIndex++;

                        _break_prompt = string.Format("Break: {0}->{1}[{2}]:{3}", behaviorFilename, breakPoint.NodeType, action.NodeId, action.Name);
                        if (action.Result == "success" || action.Result == "failure")
                            _break_prompt += string.Format(" [{0}]", action.Result);

                        return new HighlightBreakPoint(behaviorFilename, action.NodeId, breakPoint.NodeType, action.Name, action.Result);
                    }
                }
            }

            return null;
        }

        private static int _agenttype_index = -1;
        private static int _agentinstance_index = -1;
        private static int _lastBreakFrame = -1;
        private static int _lastBreakPointIndex = 0;

        private int _log_index = -1;

        private bool update(int frame)
        {
            ConsoleDock.SetMesssages(frame);

            if (Plugin.EditMode == EditModes.Connect)
            {
                if (Plugin.UpdateMode == UpdateModes.Continue)
                {
                    SetTotalFrame(frame);
                    AgentDataPool.CurrentFrame = AgentDataPool.TotalFrames;
                }

                updateUI(frame);
            }

            if (_agenttype_index != -1 && _agentinstance_index != -1)
            {
                //update could be entered multiple times for a 'frame' if there are multiple breakpoints in 'frame'
                if (_agenttype_index == 0 && _agentinstance_index == 0)
                {
                    AgentDataPool.CurrentFrame = frame;

                    // Global
                    //foreach (Plugin.InstanceName_t agentType in Plugin.InstanceNames)
                    //{
                    //    updateParameters(agentType.agentType_, agentType.agentType_.AgentTypeName, frame);
                    //}
                }

                this._break_prompt = "";

                // Agent
                while (_agenttype_index < Plugin.AgentTypes.Count)
                {
                    AgentType agentType = Plugin.AgentTypes[_agenttype_index];

                    if (!agentType.IsInherited)
                    {
                        List<string> instances = AgentInstancePool.GetInstances(agentType.ToString());
                        while (_agentinstance_index < instances.Count)
                        {
                            string instance = instances[_agentinstance_index++];

                            // Parameters
                            updateParameters(agentType, instance, frame);

                            if (Plugin.EditMode == EditModes.Analyze)
                            {
                                string agentName = string.Format("{0}#{1}", agentType, instance);
                                string behaviorFilename = FrameStatePool.GetBehaviorFilename(agentName, frame);

                                if (_lastBreakFrame != frame)
                                {
                                    _lastBreakPointIndex = 0;
                                }

                                // Breakpoint
                                List<FrameStatePool.FrameState.Action> actions = FrameStatePool.GetActions(agentName, frame, behaviorFilename);
                                HighlightBreakPoint.Instance = checkBreakpoint(behaviorFilename, actions, ref _lastBreakPointIndex);

                                if (HighlightBreakPoint.Instance != null || agentName == Plugin.DebugAgentInstance)
                                {
                                    // Highlights
                                    List<string> highlightNodeIds = FrameStatePool.GetHighlightNodeIds(agentName, frame, behaviorFilename);
                                    List<string> updatedNodeIds = FrameStatePool.GetUpdatedNodeIds(agentName, frame, behaviorFilename);
                                    Dictionary<string, FrameStatePool.NodeProfileInfos.ProfileInfo> profileInfos = FrameStatePool.GetProfileInfos(frame, behaviorFilename);

                                    updateHighlights(agentName, frame, highlightNodeIds, updatedNodeIds, HighlightBreakPoint.Instance, profileInfos);
                                }

                                // Return if there is breakpoint breaked.
                                if (HighlightBreakPoint.Instance != null)
                                {
                                    _lastBreakFrame = frame;
                                    return true;
                                }
                            }
                        }
                    }

                    _agenttype_index++;
                    _agentinstance_index = 0;
                }

                _agenttype_index = -1;
                _agentinstance_index = -1;

                //after checking breakpoints, to check applog
                _log_index = 0;
            }

            if (_log_index != -1)
            {
                if (Plugin.EditMode == EditModes.Analyze)
                {
                    bool bCheckLog = (this.comboBoxLogFilter.Text != "");
                    if (bCheckLog)
                    {
                        if (Plugin.EditMode == EditModes.Analyze)
                        {
                            Debug.Check(true);
                        }
                        else if (!Settings.Default.BreakAPP || MessageQueue.IsConnected)
                        {
                            //when breaking cpp, only check breakpoints after [connected], i.e. skip breakpoints before connecting
                            Debug.Check(true);
                        }
                        else
                        {
                            bCheckLog = false;
                        }
                    }

                    if (bCheckLog)
                    {
                        List<string> logs = FrameStatePool.GetAppLog(frame, this.comboBoxLogFilter.Text);
                        if (logs != null && _log_index < logs.Count)
                        {
                            this._break_prompt = logs[_log_index++];
                            return true;
                        }
                    }
                }

                _log_index = -1;
            }

            return false;
        }

        private const int kFPS = 20;

        private void setUpdateMode(UpdateModes updataMode, string prompt)
        {
            Plugin.UpdateMode = updataMode;

            this.promptLabel.Text = prompt;

            if (updataMode == UpdateModes.Break)
            {
                this.playButton.Image = Resources.Play;
                this.toolTip.SetToolTip(_timelineDock.playButton, "Continue (F5)");
                this.effectTimer.Enabled = false;

                //when breaked by cpp, allow to disable BreakAPP
                //when breaked by designer, don't allow to enable BreakAPP as it will cause inconsistence
                if (!Settings.Default.BreakAPP)
                {
                    this.checkBoxBreakCPP.Enabled = false;
                }
            }
            else
            {
                _currentFrame = AgentDataPool.TotalFrames;
                this.effectTimer.Enabled = true;
                this.playButton.Image = Resources.Pause;
                this.toolTip.SetToolTip(_timelineDock.playButton, "Pause");
                this.checkBoxBreakCPP.Enabled = true;

                if (Plugin.EditMode == EditModes.Analyze)
                {
                    bool bBreakedByLog = this._break_prompt.StartsWith("[applog]");
                    if (string.IsNullOrEmpty(this._break_prompt))
                    {
                        _agenttype_index = 0;
                        _agentinstance_index = 0;
                    }
                }
            }
        }

        public static void Continue()
        {
            _timelineDock.setUpdateMode(UpdateModes.Continue, ".");
            if (Plugin.EditMode == EditModes.Connect)
                Network.NetworkManager.Instance.SendContinue();
        }

        private void playButton_Click(object sender, EventArgs e)
        {
            if (Settings.Default.BreakAPP)
            {
                TimelineDock.Continue();
            }
            else
            {
                if (Plugin.UpdateMode == UpdateModes.Continue)
                    setUpdateMode(UpdateModes.Break, "Break manually.");
                else
                    setUpdateMode(UpdateModes.Continue, ".");
            }
        }

        private void startButton_Click(object sender, EventArgs e)
        {
            trackBar.Value = trackBar.Minimum;
        }

        private void backwardButton_Click(object sender, EventArgs e)
        {
            if (trackBar.Value > trackBar.Minimum)
                trackBar.Value--;
        }

        private void forwardButton_Click(object sender, EventArgs e)
        {
            if (trackBar.Value < trackBar.Maximum)
                trackBar.Value++;
        }

        private void endButton_Click(object sender, EventArgs e)
        {
            trackBar.Value = trackBar.Maximum;
        }

        private void zoomOutButton_Click(object sender, EventArgs e)
        {
            int size = trackBar.Maximum - trackBar.Minimum;

            trackBar.Minimum = trackBar.Value - size;
            if (trackBar.Minimum < 0)
                trackBar.Minimum = 0;

            trackBar.Maximum = trackBar.Value + size;

            setLabels();
        }

        private void zoomInButton_Click(object sender, EventArgs e)
        {
            int size = trackBar.Maximum - trackBar.Minimum;
            if (size >= 10)
            {
                size = size / 4;

                trackBar.Minimum = trackBar.Value - size;
                if (trackBar.Minimum < 0)
                    trackBar.Minimum = 0;

                trackBar.Maximum = trackBar.Value + size;

                setLabels();
            }
        }

        private void effectTimer_Tick(object sender, EventArgs e)
        {
            if (_timelineDock != null)
            {
                if (Plugin.UpdateMode == UpdateModes.Continue)
                {
                    if (_timelineDock.promptLabel.Text.Length < 20)
                        _timelineDock.promptLabel.Text += " .";
                    else
                        _timelineDock.promptLabel.Text = ".";
                }
                else
                {
                    _timelineDock.effectTimer.Enabled = false;
                }
            }
        }

        private void checkBoxBreakCPP_CheckedChanged(object sender, EventArgs e)
        {
            if (Settings.Default.BreakAPP != _timelineDock.checkBoxBreakCPP.Checked)
            {
                Settings.Default.BreakAPP = _timelineDock.checkBoxBreakCPP.Checked;

                NetworkManager.Instance.SendBreakAPP(Settings.Default.BreakAPP);
            }

            //_timelineDock.playButton.Enabled = !Settings.Default.BreakAPP;
        }

        private void Continue_handler(string btMsg)
        {
            //if (Plugin.UpdateMode == UpdateModes.Break)
            {
                //it could be toggled off when the breakpoint dialog is prompted
                //Debug.Check(Settings.Default.BreakAPP);
                Debug.Check(this.IsHandleCreated);
                Debug.Check(btMsg.StartsWith("[continue]"));

                string msg = btMsg.Substring(10);

                if (msg.StartsWith("[applog]"))
                {
                    int pos = this.promptLabel.Text.IndexOf(msg);
                    Debug.Check(pos != -1);
                }
                else
                {
                    string[] bts = msg.Split(' ');
                    Debug.Check(bts.Length >= 2);

                    int posNewline = bts[1].IndexOf('\n');
                    if (posNewline != -1)
                    {
                        bts[1] = bts[1].Substring(0, posNewline);
                    }

                    int pos = this.promptLabel.Text.IndexOf(bts[1]);
                    //Debug.Check(pos != -1);
                }

                this.setUpdateMode(UpdateModes.Continue, "");
            }
        }

        private bool _loaded = false;
        private void TimelineDock_Load(object sender, EventArgs e)
        {
            _loaded = true;
        }

        private bool isFromGotoNumericUpDown = false;
        private bool isFromTrackBar = false;
        private bool isUpdateValue = true;

        private void updateValue()
        {
            _agenttype_index = 0;
            _agentinstance_index = 0;

            if (this.update(_timelineDock.trackBar.Value))
            {
                this.setUpdateMode(UpdateModes.Break, this._break_prompt);
            }
            else
            {
                if (Plugin.EditMode == EditModes.Analyze)
                {
                    BehaviorTreeViewDock.ClearHighlightBreakPoint();
                    _timelineDock.promptLabel.Text = "";
                }
            }
        }

        private void gotoNumericUpDown_ValueChanged(Object sender, EventArgs e)
        {
            if (isFromTrackBar)
                return;

            isFromGotoNumericUpDown = true;
            trackBar.Value = (int)gotoNumericUpDown.Value;
            isFromGotoNumericUpDown = false;

            if (isUpdateValue)
                updateValue();
        }

        private void trackBar_ValueChanged(Object sender, EventArgs e)
        {
            if (isFromGotoNumericUpDown)
                return;

            isFromTrackBar = true;
            gotoNumericUpDown.Value = trackBar.Value;
            isFromTrackBar = false;

            if (isUpdateValue)
                updateValue();
        }

        const long kTimeThreshold = 50;
        private static int _currentFrame = -1;
        private static System.Diagnostics.Stopwatch _stopwatch = new System.Diagnostics.Stopwatch();

        public static void Tick()
        {
            if (Plugin.EditMode == EditModes.Connect)
            {
                int totalFrames = AgentDataPool.TotalFrames;
                if (totalFrames >= 0)
                {
                    if (_currentFrame < 0)
                    {
                        _currentFrame = totalFrames;
                    }

                    if (_currentFrame <= totalFrames)
                    {
                        bool bUpdate = !MessageQueue.BreakAPP || Plugin.UpdateMode == UpdateModes.Continue;

                        if (bUpdate)
                        {
                            _stopwatch.Reset();
                            _stopwatch.Start();
                        }

                        while (_currentFrame <= totalFrames)
                        {
                            SetTotalFrame(_currentFrame);

                            _currentFrame++;

                            if (bUpdate)
                            {
                                long ms = _stopwatch.ElapsedMilliseconds;
                                if (ms > kTimeThreshold)
                                {
                                    _currentFrame = totalFrames;
                                    break;
                                }
                            }
                        }

                        if (bUpdate)
                        {
                            _stopwatch.Stop();
                        }
                    }
                    else if (AgentDataPool.BreakFrame > -1 && _currentFrame > AgentDataPool.BreakFrame)
                    {
                        _currentFrame = AgentDataPool.BreakFrame;
                        AgentDataPool.BreakFrame = -1;

                        SetTotalFrame(_currentFrame);
                        _timelineDock.update(_currentFrame);
                    }
                }
            }
            else if (Plugin.EditMode == EditModes.Analyze)
            {
                if (Plugin.UpdateMode == UpdateModes.Break)
                    return;

                int current = _timelineDock.trackBar.Value;
                int framesPerStep = (int)_timelineDock.numericUpDownFPS.Value / kFPS;
                int end = current + framesPerStep;
                if (end > _timelineDock.trackBar.Maximum)
                {
                    end = _timelineDock.trackBar.Maximum;
                }

                for (int i = current; i <= end; ++i)
                {
                    _agenttype_index = 0;
                    _agentinstance_index = 0;

                    if (_timelineDock.update(i))
                    {
                        _timelineDock.isUpdateValue = false;
                        _timelineDock.trackBar.Value = i;
                        _timelineDock.isUpdateValue = true;

                        Debug.Check(!string.IsNullOrEmpty(_timelineDock._break_prompt));

                        //timer will be stopped
                        _timelineDock.setUpdateMode(UpdateModes.Break, _timelineDock._break_prompt);
                        return;
                    }
                }

                _timelineDock.isUpdateValue = false;
                _timelineDock.trackBar.Value = end;
                _timelineDock.isUpdateValue = true;

                if (_timelineDock.trackBar.Value >= _timelineDock.trackBar.Maximum)
                {
                    _timelineDock.setUpdateMode(UpdateModes.Break, "No breakpoints found.");
                }
            }
        }

        private void comboBoxLogFilter_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (this.comboBoxLogFilter.Text != "")
            {
                NetworkManager.Instance.SendLogFilter(this.comboBoxLogFilter.Text);
            }
        }

        private void comboBoxLogFilter_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter && this.comboBoxLogFilter.Text != "")
            {
                NetworkManager.Instance.SendLogFilter(this.comboBoxLogFilter.Text);
            }
        }
    }
}
