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
using System.IO;
using System.Xml;
using System.Windows.Forms;
using Behaviac.Design.Data;
using Behaviac.Design.Properties;
using Behaviac.Design.Network;

namespace Behaviac.Design
{
    class MessageHandler
    {
        internal static void RegisterMessageHandler()
        {
            MessageQueue.ProcessMessageHandler -= processMessage;
            MessageQueue.ProcessMessageHandler += processMessage;
        }

        private static Dictionary<string, bool> _checkedBehaviorFiles = new Dictionary<string, bool>();

        public static void Init()
        {
            _checkedBehaviorFiles.Clear();
        }

        private static bool ms_workspace_handled = false;
        private static string ms_fileFormat = "xml";

        private static UpdateModes processMessage(string msg)
        {
            if (msg.StartsWith("[workspace]"))
            {
                if (!ms_workspace_handled && Plugin.WorkspaceDelegateHandler != null)
                {
                    string str_ = msg.Substring(11);
                    string format = "";

                    //skip the space
                    int pos = 1;
                    for (; pos < str_.Length; ++pos)
                    {
                        format += str_[pos];
                        if (str_[pos] == ' ')
                        {
                            break;
                        }
                    }

                    ms_fileFormat = format.Trim();

                    Debug.Check(ms_fileFormat == "xml" || ms_fileFormat == "bson");

                    //skip the space
                    string str = str_.Substring(pos + 1);
                    if (!string.IsNullOrEmpty(str))
                    {
                        string wksName = string.Empty;
                        if (str[0] == '\"')
                        {
                            for (int i = 1; i < str.Length; ++i)
                            {
                                if (str[i] == '\"')
                                {
                                    wksName = str.Substring(1, i-1);
                                    break;
                                }
                            }
                        }
                        else
                        {
                            string[] tokens = str.Split(' ');
                            wksName = tokens[0].Trim(new char[] { ' ', '\"' });
                        }

                        if (!string.IsNullOrEmpty(wksName))
                        {
                            wksName = Path.GetFullPath(wksName);

                            //Plugin_WorkspaceDelegateHandler might be blocked
                            ms_workspace_handled = true;
                            Plugin.WorkspaceDelegateHandler(wksName, false, true);
                            ms_workspace_handled = false;
                        }

                        //
                        AgentDataPool.TotalFrames = 0;
                    }
                }
            }
            else if (msg.StartsWith("[connected]"))
            {
                MessageQueue.IsConnected = true;

                //sending breakpoints after receving those precaches messages
                NetworkManager.Instance.SendLoadedBreakpoints();
                NetworkManager.Instance.SendProfiling(Settings.Default.ShowProfilingInfo);

                //BreakAPP can only be sent to cpp after all the breakpoints info have been sent
                //sending BreakAPP to cpp to enable the debugging
                NetworkManager.Instance.SendBreakAPP(Settings.Default.BreakAPP);
                NetworkManager.Instance.SendText("[start]\n");
            }
            else if (msg.StartsWith("[frame]"))
            {
                // [frame]0
                AgentDataPool.TotalFrames = (int.Parse(msg.Substring(7)));
            }
            else if (msg.StartsWith("[property]"))
            {
                // Par:   [property]a->10
                // World: [property]WorldTest::World WorldTest::Property3->10
                // Agent: [property]AgentTest::AgentTest_1 AgentTest::Property5::type::name->10

                string[] tokens = msg.Substring(10).Split(' ');
                Debug.Check(tokens.Length > 0);

                string agentType = string.Empty;
                string agentName = string.Empty;
                string agentFullname = string.Empty;

                // Par
                if (tokens.Length == 1)
                {
                    agentType = string.Empty;
                    agentName = VariableDef.kPar;
                    agentFullname = tokens[0];
                }
                // Global or Agent
                else
                {
                    string[] types = tokens[0].Split(new char[] { '#' }, StringSplitOptions.RemoveEmptyEntries);
                    Debug.Check(types.Length == 2);
                    agentType = types[0];
                    agentName = types[1];
                    agentFullname = tokens[0];

                    AgentInstancePool.AddInstance(agentType, agentName);
                }

                Debug.Check(!string.IsNullOrEmpty(agentFullname));

                string[] values = tokens[tokens.Length - 1].Split(new string[] { "->", "\n" }, StringSplitOptions.RemoveEmptyEntries);
                if (values.Length == 2)
                {
                    if (AgentDataPool.TotalFrames > -1 && !string.IsNullOrEmpty(agentFullname))
                    {
                        AgentDataPool.AddValue(agentFullname, values[0], AgentDataPool.TotalFrames, values[1]);
                    }
                }
            }
            else if (msg.StartsWith("[tick]"))
            {
                // [tick]Ship::Ship_1 ships\basic.xml->BehaviorTree[0]:enter [all/success/failure] [1]
                // [tick]Ship::Ship_1 ships\basic.xml->BehaviorTree[0]:update [1]

                string[] tokens = msg.Substring(6).Split(' ');
                if (tokens.Length == 4)
                {
                    string[] types = tokens[0].Split(new char[] { '#' }, StringSplitOptions.RemoveEmptyEntries);
                    Debug.Check(types.Length == 2);
                    string agentType = types[0];
                    string agentName = types[1];
                    string agentFullname = tokens[0];

                    AgentInstancePool.AddInstance(agentType, agentName, true);

                    string[] nodes = tokens[1].Split(new string[] { "->" }, StringSplitOptions.RemoveEmptyEntries);
                    if (nodes.Length == 2)
                    {
                        string behaviorFilename = nodes[0];

                        checkBehaviorFiles(behaviorFilename);
                        
                        string[] actions = nodes[1].Split(new char[] { '[', ']' }, StringSplitOptions.RemoveEmptyEntries);
                        if (actions.Length == 3)
                        {
                            string[] actionResults = tokens[2].Split(new char[] { '[', ']' }, StringSplitOptions.RemoveEmptyEntries);
                            string[] hitCounts = tokens[3].Split(new char[] { '[', ']' }, StringSplitOptions.RemoveEmptyEntries);
                            int hitCount = int.Parse(hitCounts[0]);
                            string nodeId = actions[1];

                            if (actions[2] == ":enter")
                            {
                                FrameStatePool.EnterNode(agentFullname, AgentDataPool.TotalFrames, behaviorFilename, nodeId, actionResults[0], hitCount);
                            }
                            else if (actions[2] == ":exit")
                            {
                                FrameStatePool.ExitNode(agentFullname, AgentDataPool.TotalFrames, behaviorFilename, nodeId, actionResults[0], hitCount);
                            }
                            else if (actions[2] == ":update")
                            {
                                List<string> highlightNodeIds = FrameStatePool.GetHighlightNodeIds(agentFullname, AgentDataPool.TotalFrames, behaviorFilename);
                                if (highlightNodeIds != null && !highlightNodeIds.Contains(nodeId))
                                    FrameStatePool.EnterNode(agentFullname, AgentDataPool.TotalFrames, behaviorFilename, actions[1], actionResults[0], hitCount);
                            }
                        }
                    }
                }
            }
            else if (msg.StartsWith("[jump]"))
            {
                // [jump]Ship::Ship_1 ships/1_1_suicide[5] ships\basic

                string[] tokens = msg.Substring(6).Split(' ');
                if (tokens.Length == 3)
                {
                    string[] types = tokens[0].Split(new char[] { '#' }, StringSplitOptions.RemoveEmptyEntries);
                    Debug.Check(types.Length == 2);
                    string agentType = types[0];
                    string agentName = types[1];
                    string agentFullname = tokens[0];

                    //AgentInstancePool.AddInstance(agentType, agentName, true);
                    string thisTree = null;

                    int nodeId = -1;
                    string[] nodes = tokens[1].Split(new char[] { '[', ']' }, StringSplitOptions.RemoveEmptyEntries);
                    if (nodes.Length == 2)
                    {
                        thisTree = nodes[0];
                        nodeId = int.Parse(nodes[1]);
                    }
                    else
                    {
                        Debug.Check(false);
                    }

                    string jumpTree = tokens[2].Trim(new char[] { '\n' });

                    FrameStatePool.SetJumpInfo(agentFullname, thisTree, nodeId, jumpTree);
                }
            }
            else if (msg.StartsWith("[return]"))
            {
                // [return]Ship::Ship_1 ships\basic

                string[] tokens = msg.Substring(8).Split(' ');
                if (tokens.Length == 2)
                {
                    string[] types = tokens[0].Split(new char[] { '#' }, StringSplitOptions.RemoveEmptyEntries);
                    Debug.Check(types.Length == 2);
                    string agentType = types[0];
                    string agentName = types[1];
                    string agentFullname = tokens[0];

                    //AgentInstancePool.AddInstance(agentType, agentName, true);

                    string lastTree = tokens[1].Trim(new char[] { '\n' });

                    FrameStatePool.SetReturnInfo(agentFullname, lastTree);
                }
            }
            else if (msg.StartsWith("[breaked]"))
            {
                //BreakAPP could be toggled off when the break dialog is prompted
                //Debug.Check(MessageQueue.BreakAPP);
                if (MessageQueue.BreakAPP)
                {
                    string msg_real = msg.Substring(9);
                    if (msg_real.StartsWith("[applog]"))
                    {
                        FrameStatePool.RespondToCPPBreak(AgentDataPool.TotalFrames, msg_real);
                    }
                    else
                    {
                        //[breaked]Ship::Ship_1 ships\basic.xml->BehaviorTree[0]:enter [all/success/failure] [1]
                        string[] tokens = msg_real.Split(' ');
                        if (tokens.Length == 4)
                        {
                            string agentFullname = tokens[0];
                            //if (string.IsNullOrEmpty(Plugin.DebugAgentInstance))
                            {
                                Plugin.DebugAgentInstance = agentFullname;
                            }

                            string[] nodes = tokens[1].Split(new string[] { "->" }, StringSplitOptions.RemoveEmptyEntries);
                            if (nodes.Length == 2)
                            {
                                string[] actions = nodes[1].Split(new char[] { '[', ']' }, StringSplitOptions.RemoveEmptyEntries);
                                if (actions.Length == 3)
                                {
                                    Debug.Check(actions[2].StartsWith(":"));
                                    string actionName = actions[2].Substring(1);
                                    string[] actionResults = tokens[2].Split(new char[] { '[', ']' }, StringSplitOptions.RemoveEmptyEntries);

                                    //although actionResult can be EAR_none or EAR_all, but, as this is the real result of an action
                                    //it can only be success or failure
                                    Debug.Check(actionResults.Length == 1 && (actionResults[0] == "success" || actionResults[0] == "failure"));

                                    string[] hitCounts = tokens[3].Split(new char[] { '[', ']' }, StringSplitOptions.RemoveEmptyEntries);
                                    int hitCount = int.Parse(hitCounts[0]);

                                    FrameStatePool.RespondToAPPBreak(agentFullname, AgentDataPool.TotalFrames, nodes[0], actions[1], actionName, actionResults[0], hitCount);
                                }
                            }
                        }
                    }

                    Plugin.UpdateMode = UpdateModes.Break;
                }
            }
            else if (msg.StartsWith("[continue]"))
            {
                if (MessageQueue.ContinueHandler != null)
                    MessageQueue.ContinueHandler(msg);
            }
            else if (msg.StartsWith("[applog]"))
            {
                int frame = AgentDataPool.TotalFrames;
                FrameStatePool.AddAppLog(frame, msg);
            }
            else if (msg.StartsWith("[log]"))
            {
                int frame = AgentDataPool.TotalFrames;
                FrameStatePool.AddLog(frame, msg);
            }
            else if (msg.StartsWith("[profiler]"))
            {
                //[profiler]ships\0_basic.xml->BehaviorTree[-1] 685
                string[] tokens = msg.Substring(10).Split(new char[] { ' ', '\n' }, StringSplitOptions.RemoveEmptyEntries);
                if (tokens.Length == 2)
                {
                    string[] nodes = tokens[0].Split(new string[] { "->" }, StringSplitOptions.RemoveEmptyEntries);
                    if (nodes.Length == 2)
                    {
                        string behaviorFilename = nodes[0];

                        string[] ids = nodes[1].Split(new char[] { '[', ']' }, StringSplitOptions.RemoveEmptyEntries);
                        if (ids.Length == 2)
                        {
                            FrameStatePool.SetProfileInfo(AgentDataPool.TotalFrames, behaviorFilename, ids[1], 0.001f * int.Parse(tokens[1]));
                        }
                    }
                }
            }
            else
            {
                //
                //Debug.Check(false);
            }

            return Plugin.UpdateMode;
        }

        private static void checkBehaviorFiles(string behaviorFilename)
        {
            if (_checkedBehaviorFiles.ContainsKey(behaviorFilename))
                return;

            _checkedBehaviorFiles[behaviorFilename] = true;

            try
            {
                string sourceFilename = Path.Combine(Workspace.Current.Folder, behaviorFilename);
                string exportedFilename = Path.Combine(Workspace.Current.DefaultExportFolder, behaviorFilename);

                //remove the extension
                int pos = exportedFilename.IndexOf(".xml");
                if (pos != -1)
                {
                    exportedFilename = exportedFilename.Remove(pos);
                }

                exportedFilename += string.Format(".{0}", ms_fileFormat);

                if (File.Exists(sourceFilename) && File.Exists(exportedFilename))
                {
                    FileInfo sourceFileInfo = new FileInfo(sourceFilename);
                    FileInfo exportedFileInfo = new FileInfo(exportedFilename);
                    if (sourceFileInfo.LastWriteTime > exportedFileInfo.LastWriteTime)
                    {
                        string info = string.Format(Resources.FileModifiedInfo, behaviorFilename);
                        MessageBox.Show(info, Resources.FileModified, MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    }
                }
            }
            catch (Exception)
            {
            }
        }
    }
}
