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
using System.Runtime.Serialization.Formatters.Binary;

namespace Behaviac.Design.Data
{
    public class FrameStatePool
    {
        [Serializable]
        public class FrameState
        {
            [Serializable]
            public class Action
            {
                private string _nodeId;
                public string NodeId
                {
                    get { return _nodeId; }
                    set { _nodeId = value; }
                }

                private string _name;
                public string Name
                {
                    get { return _name; }
                    set { _name = value; }
                }

                private string _result;
                public string Result
                {
                    get { return _result; }
                    set { _result = value; }
                }

                private int _hitCount = 0;
                public int HitCount
                {
                    get { return _hitCount; }
                    set { _hitCount = value; }
                }
            }

            private int _frame = -1;
            public int Frame
            {
                get { return _frame; }
                set { _frame = value; }
            }

            private string _behaviorFilename;
            public string BehaviorFilename
            {
                get { return _behaviorFilename; }
                set { _behaviorFilename = value; }
            }

            private List<Action> _actions = new List<Action>();
            public List<Action> Actions
            {
                get { return _actions; }
            }

            private List<string> _highlightNodeIds = new List<string>();
            public List<string> HighlightNodeIds
            {
                get { return _highlightNodeIds; }
            }

            private List<string> _updatedNodeIds = new List<string>();
            public List<string> UpdatedNodeIds
            {
                get { return _updatedNodeIds; }
            }
        }

        // key : agentName
        private static Dictionary<string, List<FrameState>> _frameStates = new Dictionary<string, List<FrameState>>();
        public static Dictionary<string, List<FrameState>> FrameStates
        {
            get { return _frameStates; }
        }

        [Serializable]
        public class NodeProfileInfos
        {
            [Serializable]
            public class ProfileInfo
            {
                private int _count = 0;
                public int Count
                {
                    get { return _count; }
                    set { _count = value; }
                }

                private float _time = -1;
                public float Time
                {
                    get { return _time; }
                    set { _time = value; }
                }

                private float _totalTime = 0;
                public float TotalTime
                {
                    get { return _totalTime; }
                    set { _totalTime = value; }
                }

                public ProfileInfo Clone()
                {
                    ProfileInfo clone = new ProfileInfo();
                    clone.Count = this.Count;
                    clone.Time = this.Time;
                    clone.TotalTime = this.TotalTime;

                    return clone;
                }

                public override bool Equals(object obj)
                {
                    if (obj is ProfileInfo)
                    {
                        ProfileInfo other = obj as ProfileInfo;
                        return (Count == other.Count) &&
                            (Time == other.Time) &&
                            (TotalTime == other.TotalTime);
                    }

                    return false;
                }

                public override int GetHashCode()
                {
                    return base.GetHashCode();
                }
            }

            private int _lastValidFrame = -1;
            public int LastValidFrame
            {
                get { return _lastValidFrame; }
                set { _lastValidFrame = value; }
            }

            // key : frame
            private Dictionary<int, ProfileInfo> _profileInfos = new Dictionary<int, ProfileInfo>();
            public Dictionary<int, ProfileInfo> ProfileInfos
            {
                get { return _profileInfos; }
                set { _profileInfos = value; }
            }
        }

        // key1 : behaviorFilename, key2 : nodeId
        private static Dictionary<string, Dictionary<string, NodeProfileInfos>> _nodeFrameProfiles = new Dictionary<string, Dictionary<string, NodeProfileInfos>>();
        public static Dictionary<string, Dictionary<string, NodeProfileInfos>> NodeFrameProfiles
        {
            get { return _nodeFrameProfiles; }
        }

        public static void SetProfileInfo(int frame, string behaviorFilename, string nodeId, float timeMs)
        {
            //CheckJump(agentFullname, ref behaviorFilename, ref nodeId);

            if (frame < 0 || string.IsNullOrEmpty(behaviorFilename) || string.IsNullOrEmpty(nodeId))
                return;

            if (!_nodeFrameProfiles.ContainsKey(behaviorFilename))
                _nodeFrameProfiles[behaviorFilename] = new Dictionary<string, NodeProfileInfos>();

            Dictionary<string, NodeProfileInfos> nodeProfileInfos = _nodeFrameProfiles[behaviorFilename];
            if (!nodeProfileInfos.ContainsKey(nodeId))
                nodeProfileInfos[nodeId] = new NodeProfileInfos();

            NodeProfileInfos profileInfos = nodeProfileInfos[nodeId];
            if (!profileInfos.ProfileInfos.ContainsKey(frame))
                profileInfos.ProfileInfos[frame] = new NodeProfileInfos.ProfileInfo();

            NodeProfileInfos.ProfileInfo profileInfo = profileInfos.ProfileInfos[frame];
            profileInfo.Time = timeMs;
            if (profileInfos.LastValidFrame < 0)
            {
                profileInfo.Count = 1;
                profileInfo.TotalTime = timeMs;
            }
            else
            {
                Debug.Check(profileInfos.ProfileInfos.ContainsKey(profileInfos.LastValidFrame));
                NodeProfileInfos.ProfileInfo lastProfileInfo = profileInfos.ProfileInfos[profileInfos.LastValidFrame];
                profileInfo.Count = lastProfileInfo.Count + 1;
                profileInfo.TotalTime = lastProfileInfo.TotalTime + timeMs;
            }
            profileInfos.LastValidFrame = frame;
        }

        public static Dictionary<string, NodeProfileInfos.ProfileInfo> GetProfileInfos(int frame, string behaviorFilename)
        {
            Dictionary<string, NodeProfileInfos.ProfileInfo> frameProfileInfos = new Dictionary<string, NodeProfileInfos.ProfileInfo>();
            if (frame < 0 || string.IsNullOrEmpty(behaviorFilename))
                return frameProfileInfos;

            if (_nodeFrameProfiles.ContainsKey(behaviorFilename))
            {
                Dictionary<string, NodeProfileInfos> nodeProfileInfos = _nodeFrameProfiles[behaviorFilename];
                foreach (string nodeId in nodeProfileInfos.Keys)
                {
                    NodeProfileInfos profileInfos = nodeProfileInfos[nodeId];
                    if (profileInfos.ProfileInfos.ContainsKey(frame))
                    {
                        frameProfileInfos[nodeId] = profileInfos.ProfileInfos[frame].Clone();
                    }
                    else if (profileInfos.LastValidFrame > -1)
                    {
                        Debug.Check(profileInfos.ProfileInfos.ContainsKey(profileInfos.LastValidFrame));
                        frameProfileInfos[nodeId] = profileInfos.ProfileInfos[profileInfos.LastValidFrame].Clone();
                        frameProfileInfos[nodeId].Time *= -1;
                    }
                }
            }

            return frameProfileInfos;
        }

        // key : frame
        private static Dictionary<int, Dictionary<string, List<string>>> _appLogs = new Dictionary<int, Dictionary<string, List<string>>>();
        public static List<string> GetAppLog(int frame, string filter)
        {
            if (_appLogs.ContainsKey(frame) && !string.IsNullOrEmpty(filter))
            {
                string filterStr = filter.ToUpper();
                if (filterStr != "ALL")
                {
                    if (_appLogs[frame].ContainsKey(filterStr))
                    {
                        return _appLogs[frame][filter];
                    }

                    return null;
                }
                else
                {
                    List<string> result = new List<string>();
                    foreach (List<string> msgs in _appLogs[frame].Values)
                    {
                        result.AddRange(msgs);
                    }

                    return result;
                }
            }

            return null;
        }

        public static void AddAppLog(int frame, string log)
        {
            //[applog]RED:door opened
            if (!_appLogs.ContainsKey(frame))
                _appLogs[frame] = new Dictionary<string, List<string>>();

            string msg = log.Substring(8);

            int pos = msg.IndexOf(':');
            if (pos != -1)
            {
                string filter = msg.Substring(0, pos);
                //string evtMsg = msg.Substring(pos + 1);

                if (!_appLogs[frame].ContainsKey(filter))
                {
                    _appLogs[frame][filter] = new List<string>();
                }

                _appLogs[frame][filter].Add(log);
            }
        }

        public delegate void AddLogDelegate(int frame, string log);
        public static AddLogDelegate AddLogHandler;

        // key : frame
        private static Dictionary<int, List<string>> _logs = new Dictionary<int, List<string>>();
        public static List<string> GetLog(int frame)
        {
            return _logs.ContainsKey(frame) ? _logs[frame] : null;
        }

        public static void AddLog(int frame, string log)
        {
            //[log]warning:*****
            //[log]error:*****
            if (!_logs.ContainsKey(frame))
                _logs[frame] = new List<string>();

            string msg = log.Substring(5);

            int pos = msg.IndexOf(':');
            if (pos != -1)
            {
                _logs[frame].Add(msg);

                if (AddLogHandler != null)
                    AddLogHandler(frame, msg);
            }
        }

        public static void Clear()
        {
            HighlightBreakPoint.Instance = null;
            _frameStates.Clear();
            _nodeFrameProfiles.Clear();
            _appLogs.Clear();
            _logs.Clear();

#if HANLE_JUMP_RETURN
            _btStack.Clear();
#endif
        }

#if HANLE_JUMP_RETURN
        private class BTStackItem
        {
            public string thisTree;
            public int nodeId;

            public string jumpTree;
        }

        private static Dictionary<string, List<BTStackItem>> _btStack = new Dictionary<string, List<BTStackItem>>();
        public static void SetJumpInfo(string agentFullname, string thisThree, int nodeId, string jumpTree)
        {
            if (!_btStack.ContainsKey(agentFullname))
            {
                _btStack[agentFullname] = new List<BTStackItem>();
            }

            BTStackItem item = new BTStackItem();
            item.thisTree = thisThree + ".xml";
            item.nodeId = nodeId;
            item.jumpTree = jumpTree + ".xml";

            //push at the end
            _btStack[agentFullname].Add(item);
        }

        public static void SetReturnInfo(string agentFullname, string lastThree)
        {
            if (_btStack.ContainsKey(agentFullname))
            {
                Debug.Check(_btStack[agentFullname].Count > 0);

                //pop last one
                _btStack[agentFullname].RemoveAt(_btStack[agentFullname].Count - 1);
            }
            else
            {
                //in case it is connected after the jumping
                //Debug.Check(false);
            }
        }

        private static List<BTStackItem> GetStack(string agentFullname)
        {
            if (_btStack.ContainsKey(agentFullname))
            {
                return _btStack[agentFullname];
            }

            return null;
        }

        private static void CheckJump(string agentFullname, ref string behaviorFilename, ref string nodeId)
        {
            List<BTStackItem> stack = GetStack(agentFullname);

            if (stack != null && stack.Count > 0)
            {
                BTStackItem top = stack[stack.Count - 1];

                if (top.jumpTree == behaviorFilename)
                {
                    behaviorFilename = stack[0].thisTree;

                    string id = "";
                    for (int i = 0; i < stack.Count; ++i)
                    {
                        id += string.Format("{0}:", stack[i].nodeId);
                    }

                    id += nodeId;

                    nodeId = id;
                }
            }
        }
#else
        public static void SetJumpInfo(string agentFullname, string thisThree, int nodeId, string jumpTree)
        {

        }

        public static void SetReturnInfo(string agentFullname, string lastThree)
        {

        }

        private static void CheckJump(string agentFullname, ref string behaviorFilename, ref string nodeId)
        {

        }
#endif//HANLE_JUMP_RETURN
        public static void EnterNode(string agentFullname, int frame, string behaviorFilename, string nodeId, string actionResult, int hitCount)
        {
            CheckJump(agentFullname, ref behaviorFilename, ref nodeId);

            if (frame < 0 || string.IsNullOrEmpty(agentFullname) || string.IsNullOrEmpty(behaviorFilename) || string.IsNullOrEmpty(nodeId))
                return;

            FrameState frameState = setFrameState(agentFullname, frame, behaviorFilename, nodeId, HighlightBreakPoint.kEnter, actionResult, hitCount);
            if (frameState != null)
            {
                frameState.UpdatedNodeIds.Remove(nodeId);
                if (!frameState.HighlightNodeIds.Contains(nodeId))
                    frameState.HighlightNodeIds.Add(nodeId);
            }
        }

        public static void ExitNode(string agentFullname, int frame, string behaviorFilename, string nodeId, string actionResult, int hitCount)
        {
            CheckJump(agentFullname, ref behaviorFilename, ref nodeId);

            if (frame < 0 || string.IsNullOrEmpty(agentFullname) || string.IsNullOrEmpty(behaviorFilename) || string.IsNullOrEmpty(nodeId))
                return;

            FrameState frameState = setFrameState(agentFullname, frame, behaviorFilename, nodeId, HighlightBreakPoint.kExit, actionResult, hitCount);
            if (frameState != null)
            {
                frameState.HighlightNodeIds.Remove(nodeId);
                if (!frameState.UpdatedNodeIds.Contains(nodeId))
                    frameState.UpdatedNodeIds.Add(nodeId);
            }
        }

        public static List<string> GetHighlightNodeIds(string agentFullname, int frame, string behaviorFilename)
        {
            if (!_frameStates.ContainsKey(agentFullname))
                return null;

            List<FrameState> frameStates = _frameStates[agentFullname];
            int index = findNearestFrame(frameStates, frame);
            if (index < 0)
                return null;

            FrameState frameState = frameStates[index];
            if (frameState.BehaviorFilename != behaviorFilename)
                return null;

            return frameState.HighlightNodeIds;
        }

        public static List<string> GetUpdatedNodeIds(string agentFullname, int frame, string behaviorFilename)
        {
            if (!_frameStates.ContainsKey(agentFullname))
                return null;

            List<FrameState> frameStates = _frameStates[agentFullname];
            int index = findFrame(frameStates, frame);
            if (index < 0)
                return null;

            FrameState frameState = frameStates[index];
            if (frameState.BehaviorFilename != behaviorFilename)
                return null;

            return frameState.UpdatedNodeIds;
        }

        public static List<FrameState.Action> GetActions(string agentFullname, int frame, string behaviorFilename)
        {
            if (!_frameStates.ContainsKey(agentFullname))
                return null;

            List<FrameState> frameStates = _frameStates[agentFullname];
            int index = findFrame(frameStates, frame);
            if (index < 0)
                return null;

            FrameState frameState = frameStates[index];
            if (frameState.BehaviorFilename != behaviorFilename)
                return null;

            return frameState.Actions;
        }

        public static string GetBehaviorFilename(string agentFullname, int frame)
        {
            if (!string.IsNullOrEmpty(agentFullname) && frame > -1)
            {
                if (!_frameStates.ContainsKey(agentFullname))
                    return string.Empty;

                List<FrameState> frameStates = _frameStates[agentFullname];
                int index = findNearestFrame(frameStates, frame);
                if (index < 0)
                    return string.Empty;

                return frameStates[index].BehaviorFilename;
            }

            return null;
        }

        private static int findFrame(List<FrameState> frameStates, int frame)
        {
            if (frame > -1 && frameStates.Count > 0)
            {
                //for (int i = frameStates.Count - 1; i >= 0; i--)
                //{
                //    if (frameStates[i].Frame == frame)
                //        return i;
                //    else if (frameStates[i].Frame < frame)
                //        return -1;
                //}

                int first = 0;
                int last = frameStates.Count - 1;
                int current = -1;
                while (first <= last)
                {
                    if (frame == frameStates[last].Frame)
                        return last;

                    if (frame == frameStates[first].Frame)
                        return first;

                    if (frame > frameStates[last].Frame || frame < frameStates[first].Frame)
                        return -1;

                    current = (first + last + 1) / 2;
                    if (frame < frameStates[current].Frame)
                        last = current - 1;
                    else if (frame > frameStates[current].Frame)
                        first = current + 1;
                    else
                        return current;
                }
            }

            return -1;
        }

        private static int findNearestFrame(List<FrameState> frameStates, int frame)
        {
            if (frame > -1 && frameStates.Count > 0)
            {
                //for (int i = frameStates.Count - 1; i >= 0; i--)
                //{
                //    if (frame >= frameStates[i].Frame)
                //        return i;
                //}

                int first = 0;
                int last = frameStates.Count - 1;
                int current = -1;
                while (first <= last)
                {
                    if (frame >= frameStates[last].Frame)
                        return last;

                    if (frame == frameStates[first].Frame)
                        return first;

                    if (frame < frameStates[first].Frame)
                        return -1;

                    current = (first + last + 1) / 2;
                    if (frame < frameStates[current].Frame)
                        last = current - 1;
                    else if (frame > frameStates[current].Frame)
                        first = current + 1;
                    else
                        return current;
                }
            }

            return -1;
        }

        private static FrameState setFrameState(string agentFullname, int frame, string behaviorFilename, string nodeId)
        {
            if (frame < 0 || string.IsNullOrEmpty(agentFullname) || string.IsNullOrEmpty(behaviorFilename) || string.IsNullOrEmpty(nodeId))
                return null;

            if (!_frameStates.ContainsKey(agentFullname))
                _frameStates[agentFullname] = new List<FrameState>();

            FrameState frameState = null;
            List<FrameState> frameStates = _frameStates[agentFullname];
            int index = findFrame(frameStates, frame);

            if (index < 0)
            {
                frameState = new FrameState();
                frameState.Frame = frame;
                frameState.BehaviorFilename = behaviorFilename;

                int neareatIndex = findNearestFrame(frameStates, frame);
                if (neareatIndex >= 0)
                {
                    foreach (string id in frameStates[neareatIndex].HighlightNodeIds)
                    {
                        frameState.HighlightNodeIds.Add(id);
                    }
                }

                frameStates.Add(frameState);
            }
            else
            {
                frameState = frameStates[index];
                if (frameState.BehaviorFilename != behaviorFilename)
                {
                    frameState.BehaviorFilename = behaviorFilename;
                    frameState.HighlightNodeIds.Clear();
                }
            }

            return frameState;
        }

        private static FrameState setFrameState(string agentFullname, int frame, string behaviorFilename, string nodeId, string actionName, string actionResult, int hitCount)
        {
            FrameState frameState = setFrameState(agentFullname, frame, behaviorFilename, nodeId);
            if (frameState != null)
            {
                FrameState.Action action = new FrameState.Action();
                action.NodeId = nodeId;
                action.Name = actionName;
                action.Result = actionResult;
                action.HitCount = hitCount;
                frameState.Actions.Add(action);

                if (!MessageQueue.BreakAPP && MessageQueue.IsConnected)
                    RespondToAPPBreak(agentFullname, frame, behaviorFilename, nodeId, actionName, actionResult, hitCount);
            }

            return frameState;
        }

        public static void RespondToAPPBreak(string agentFullname, int frame, string behaviorFilename, string nodeId, string actionName, string actionResult, int hitCount)
        {
            CheckJump(agentFullname, ref behaviorFilename, ref nodeId);

            if (behaviorFilename == GetBehaviorFilename(agentFullname, frame))
            {
                behaviorFilename = behaviorFilename.Replace('/', '\\');
                DebugDataPool.BreakPoint breakPoint = DebugDataPool.FindBreakPoint(behaviorFilename, nodeId, actionName);
                if (breakPoint != null && breakPoint.IsActive(actionName, actionResult, hitCount))
                {
                    HighlightBreakPoint.Instance = new HighlightBreakPoint(behaviorFilename, nodeId, breakPoint.NodeType, actionName, actionResult);
                    AgentDataPool.BreakFrame = frame;
                }
                else
                {
                    HighlightBreakPoint.Instance = null;
                    AgentDataPool.BreakFrame = -1;
                }
            }
        }

        public delegate void UpdateAppLogDelegate(int frame, string agentName);
        public static UpdateAppLogDelegate UpdateAppLogHandler;

        public static void RespondToCPPBreak(int frame, string appLog)
        {
            if (Plugin.UpdateMode != UpdateModes.Break)
            {
                UpdateAppLogHandler(frame, appLog);
            }
        }

        public static void Serialize(Stream stream, BinaryFormatter formatter)
        {
            formatter.Serialize(stream, _frameStates);
            formatter.Serialize(stream, _nodeFrameProfiles);
            formatter.Serialize(stream, _appLogs);
        }

        public static void Deserialize(Stream stream, BinaryFormatter formatter)
        {
            Clear();

            _frameStates = formatter.Deserialize(stream) as Dictionary<string, List<FrameState>>;
            _nodeFrameProfiles = formatter.Deserialize(stream) as Dictionary<string, Dictionary<string, NodeProfileInfos>>;
            _appLogs = formatter.Deserialize(stream) as Dictionary<int, Dictionary<string, List<string>>>;
        }
    }
}
