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

#if !BEHAVIAC_RELEASE
#if !UNITY_WEBPLAYER && (UNITY_EDITOR || UNITY_STANDALONE_WIN || UNITY_STANDALONE_OSX)
	#define BEHAVIAC_HOTRELOAD
#endif
#endif

using System;
using System.IO;
#if !BEHAVIAC_RELEASE
using System.Xml;
#endif
using System.Collections;
using System.Collections.Generic;
using System.Reflection;
using System.Threading;
using System.Security;
using UnityEngine;
using Mono.Xml;

#if UNITY_EDITOR || UNITY_STANDALONE_WIN
using System.Runtime.InteropServices;
#endif

namespace behaviac
{
    #region Config
    public static class Config
    {
        readonly private static bool ms_bIsDesktopPlayer = (Application.platform == RuntimePlatform.WindowsPlayer || Application.platform == RuntimePlatform.OSXPlayer);
        readonly private static bool ms_bIsDesktopEditor = (Application.platform == RuntimePlatform.WindowsEditor || Application.platform == RuntimePlatform.OSXPlayer);

		static bool ms_bDebugging = false;
		public static bool IsDebugging
		{
			get
			{
				return ms_bDebugging;
			}
			set
			{
#if !BEHAVIAC_RELEASE
				ms_bDebugging = value;
#else
				if (ms_bDebugging)
				{
					behaviac.Debug.LogWarning("Debugging can't be enabled on Release! please don't define BEHAVIAC_RELEASE to enable it!\n");
				}
#endif
			}
		}
		
		static bool ms_bProfiling = false;
		public static bool IsProfiling
		{
			get
			{
				return ms_bProfiling;
			}
			set
			{
#if !BEHAVIAC_RELEASE
				ms_bProfiling = value;
#else
				if (ms_bProfiling)
				{
					behaviac.Debug.LogWarning("Profiling can't be enabled on Release! please don't define BEHAVIAC_RELEASE to enable it!\n");
				}
#endif
			}
		}
		
        public static bool IsDesktopPlayer
        {
            get
            {
                return ms_bIsDesktopPlayer;
            }
        }

        public static bool IsDesktopEditor
        {
            get
            {
                return ms_bIsDesktopEditor;
            }
        }

        public static bool IsDesktop
        {
            get
            {
                return ms_bIsDesktopPlayer || ms_bIsDesktopEditor;
            }
        }

        public static bool IsLoggingOrSocketing
        {
            get
            {
                return IsLogging || IsSocketing;
            }
        }

#if !BEHAVIAC_RELEASE
		private static bool ms_bIsLogging = false;
#else
		private static bool ms_bIsLogging = false;
#endif
		///it is disable on pc by default
		public static bool IsLogging
		{
			get
			{
				//logging is only enabled on pc platform, it is disabled on android, ios, etc.
				return IsDesktop && ms_bIsLogging;
			}
			set
			{
#if !BEHAVIAC_RELEASE
				ms_bIsLogging = value;
#else
				if (ms_bIsLogging)
				{
					behaviac.Debug.LogWarning("Logging can't be enabled on Release! please don't define BEHAVIAC_RELEASE to enable it!\n");
				}
#endif
			}
		}

#if !BEHAVIAC_RELEASE
		private static bool ms_bIsSocketing = IsDesktop;
#else
		private static bool ms_bIsSocketing = false;
#endif
		//it is enabled on pc by default
		public static bool IsSocketing
		{
			get
			{
				return ms_bIsSocketing;
			}
			set
			{
#if !BEHAVIAC_RELEASE
				ms_bIsSocketing = value;
#else
				if (ms_bIsLogging)
				{
					behaviac.Debug.LogWarning("Socketing can't be enabled on Release! please don't define BEHAVIAC_RELEASE to enable it!\n");
				}
#endif
			}
		}

		static bool ms_bIsSuppressingNonPublicWarning;
		/// <summary>
		/// Gets or sets a value indicating is supressing non public warning.
		/// </summary>
		/// <value><c>true</c> if is supressing non public warning; otherwise, <c>false</c>.</value>
		public static bool IsSuppressingNonPublicWarning
		{
			get
			{
				return ms_bIsSuppressingNonPublicWarning;
			}
			set
			{
				ms_bIsSuppressingNonPublicWarning = value;
			}
		}

    }
    #endregion

    public static class Workspace
    {
        [Flags]
        public enum EFileFormat
        {
            EFF_xml     = 1,		                    //specify to use xml
            EFF_bson    = 2,		                    //specify to use bson
            EFF_cs      = 4,                            //specify to use cs
            EFF_default = EFF_xml | EFF_bson | EFF_cs,  //use the format specified by SetWorkspaceSettings
        };

        private static EFileFormat fileFormat_ = EFileFormat.EFF_xml;
        public static EFileFormat FileFormat
        {
            get
            {
                return fileFormat_;
            }
            set
            {
                fileFormat_ = value;
            }
        }

        //read from 'WorkspaceFile', prepending with 'WorkspacePath', relative to the exe's path
        private static string ms_workspaceExportPath;
        public static string WorkspaceExportPath
        {
            get
            {
                Debug.Check(!string.IsNullOrEmpty(ms_workspaceExportPath));

                return ms_workspaceExportPath;
            }
        }
#if !BEHAVIAC_RELEASE
        private static string ms_workspaceExportPathAbs;
#endif
        /**
            'handler' will be called for ever behavior node.
        */
        private delegate void BehaviorNodeLoadedHandler_t(string nodeType, List<property_t> properties);
		private static event BehaviorNodeLoadedHandler_t OnNodeLoaded;

        public static void HandleNodeLoaded(string nodeType, List<property_t> properties)
        {
            if (OnNodeLoaded != null)
            {
                OnNodeLoaded(nodeType, properties);
            }
        }

        public delegate void DRespondToBreakHandler(string msg, string title);
        public static event DRespondToBreakHandler RespondToBreakHandler;

#if UNITY_EDITOR || UNITY_STANDALONE_WIN
		[DllImport("user32.dll", CharSet=CharSet.Auto)]
		private static extern int MessageBox(int hWnd, String text, String caption, int options);
#endif
        // respond to msg, where msg = string.Format("BehaviorTreeTask Breakpoints at: '{0}{1}'\n\nOk to continue.", btMsg, actionResultStr);
        // display a message box to block the execution and then continue the execution after closing the message box
        public static void RespondToBreak(string msg, string title)
        {
            if (RespondToBreakHandler != null)
            {
                RespondToBreakHandler(msg, title);

                return;
            }
			else
			{
				WaitforContinue();

//#if UNITY_EDITOR || UNITY_STANDALONE_WIN
//				if (Application.platform == RuntimePlatform.WindowsPlayer || Application.platform == RuntimePlatform.WindowsEditor)
//				{
//					const int MB_SYSTEMMODAL = 0x00001000;
//					MessageBox(0, msg, title, MB_SYSTEMMODAL);
//				}
//#endif
			}

            //MessageBoxEvent
            System.Threading.Thread.Sleep(500);
        }
		/**
		set the workspace settings
		
		'workspaceRootPath_' specifies the file path of of the exported path of the workspace file which is configured in the workspace file(.workspace.xml), 
		it can be either an absolute path or relative to the current path.
		'format' specify the format to use, xml or bson, 
		
		the default format is xml.

		@return false if 'path' is not a valid path holding valid data
		*/
        public static bool SetWorkspaceSettings(string workspaceExportPath, EFileFormat format)
        {
            Debug.Check(!workspaceExportPath.EndsWith("\\"), "use '/' instead of '\\'");

			bool bFirstTime = string.IsNullOrEmpty(ms_workspaceExportPath);

            ms_workspaceExportPath = workspaceExportPath;

            if (!ms_workspaceExportPath.EndsWith("/"))
            {
                ms_workspaceExportPath += '/';
            }

            fileFormat_ = format;

            if (string.IsNullOrEmpty(ms_workspaceExportPath))
            {
                behaviac.Debug.LogError("No workspace file is specified!");
                behaviac.Debug.Check(false);

                return false;
            }

            LoadWorkspaceAbsolutePath();

            ms_deltaFrames = 1;

            //////////////////////////////////////////////////////////
			//only register metas and others at the 1st time
			if (bFirstTime)
			{
				behaviac.Details.RegisterCompareValue();
	            behaviac.Details.RegisterComputeValue();
	            behaviac.Workspace.RegisterBehaviorNode();
	            behaviac.Workspace.RegisterMetas();
			}

#if !BEHAVIAC_RELEASE
#if BEHAVIAC_HOTRELOAD
            // set the file watcher
            if (Config.IsDesktop)
            {
                if (FileFormat != EFileFormat.EFF_cs)
                {
                    if (ms_DirectoryMonitor == null)
                    {
                        ms_DirectoryMonitor = new DirectoryMonitor();
                        ms_DirectoryMonitor.Changed += new DirectoryMonitor.FileSystemEvent(OnFileChanged);
                    }

                    string filter = "*.*";
                    if (FileFormat == EFileFormat.EFF_xml)
                    {
                        filter = "*.xml";
                    }
                    else if (FileFormat == EFileFormat.EFF_bson)
                    {
                        filter = "*.bson.bytes";
                    }

                    ms_DirectoryMonitor.Start(workspaceExportPath, filter);
                }
            }
#endif//BEHAVIAC_HOTRELOAD

			
			SocketUtils.SendWorkspaceSettings();
#endif

            return true;
        }

        public static bool SetWorkspaceSettings(string workspaceExportPath)
        {
            return SetWorkspaceSettings(workspaceExportPath, EFileFormat.EFF_xml);
        }

        private static int ms_deltaFrames;

        public static void SetDeltaFrames(int deltaFrames)
        {
            ms_deltaFrames = deltaFrames;
        }

        public static int GetDeltaFrames()
        {
            return ms_deltaFrames;
        }

        static bool LoadWorkspaceSetting(string file, string ext, ref string workspaceFile)
        {
			try
			{
            	byte[] pBuffer = ReadFileToBuffer(file, ext);
                if (pBuffer != null)
                {
                    string xml = System.Text.Encoding.UTF8.GetString(pBuffer);
					SecurityParser xmlDoc = new SecurityParser();
                    xmlDoc.LoadXml(xml);

                    SecurityElement rootNode = xmlDoc.ToXml();
                    if (rootNode.Tag == "workspace")
                    {
                        workspaceFile = rootNode.Attribute("path");
                        return true;
                    }
                }
            }
            catch (Exception e)
            {
				string errorInfo = string.Format("Load Workspace {0} Error : {1}", file, e.Message);
				behaviac.Debug.LogError(errorInfo);
			}

            return false;
        }

        static string m_workspaceFileAbs = "";
        public static string GetWorkspaceAbsolutePath()
        {
            return m_workspaceFileAbs;
        }

        public static void LoadWorkspaceAbsolutePath()
        {
#if !BEHAVIAC_RELEASE
            if (Config.IsLoggingOrSocketing)
            {
                //relative to exe's current path
                string workspaceExportPath = WorkspaceExportPath;

                //workspaceExportPath is the path to the export:
                //like: ..\example\spaceship\data\bt\exported
                string fullPath = Path.Combine(workspaceExportPath, "behaviors.dbg");

                string workspaceFilePathRelative = "";
                bool bOk = LoadWorkspaceSetting(fullPath, ".xml", ref workspaceFilePathRelative);
                if (bOk)
                {
                    //workspaceFilePathRelative stored in behaviors.dbg.xml is the path relative to export
                    //convert it to the full path
                    if (!Path.IsPathRooted(workspaceExportPath))
                    {
                        ms_workspaceExportPathAbs = Path.GetDirectoryName(System.Reflection.Assembly.GetExecutingAssembly().Location);

                        {
                            int p = ms_workspaceExportPathAbs.LastIndexOf("Assets", StringComparison.OrdinalIgnoreCase);
                            if (p != -1)
                            {
                                ms_workspaceExportPathAbs = ms_workspaceExportPathAbs.Substring(0, p);
                            }
                        }

                        ms_workspaceExportPathAbs = Path.Combine(ms_workspaceExportPathAbs, workspaceExportPath);
                    }
                    else
                    {
                        ms_workspaceExportPathAbs = workspaceExportPath;
                    }

                    ms_workspaceExportPathAbs = ms_workspaceExportPathAbs.Replace('\\', '/');

                    m_workspaceFileAbs = Path.Combine(ms_workspaceExportPathAbs, workspaceFilePathRelative);
                }
				else
				{
				}
            }
#endif
        }


        #region HotReload
#if BEHAVIAC_HOTRELOAD
		#region DirectoryMonitor
		public class DirectoryMonitor
		{
			public delegate void FileSystemEvent(string path);
			public event FileSystemEvent Changed;
			
			private readonly FileSystemWatcher m_fileSystemWatcher = new FileSystemWatcher();
			private readonly Dictionary<string, DateTime> m_pendingEvents = new Dictionary<string, DateTime>();
			private readonly Timer m_timer;
			private bool m_timerStarted = false;
			
			public DirectoryMonitor()
			{
				m_fileSystemWatcher.IncludeSubdirectories = true;
				m_fileSystemWatcher.NotifyFilter = NotifyFilters.LastWrite;
				m_fileSystemWatcher.Changed += new FileSystemEventHandler(OnChanged);
				m_fileSystemWatcher.EnableRaisingEvents = false;
				
				m_timer = new Timer(OnTimeout, null, Timeout.Infinite, Timeout.Infinite);
			}
			
			public void Start(string dirPath, string filter)
			{
				m_fileSystemWatcher.Path = dirPath;
				m_fileSystemWatcher.Filter = filter;
				m_fileSystemWatcher.EnableRaisingEvents = true;
			}
			
			public void Stop()
			{
				m_fileSystemWatcher.EnableRaisingEvents = false;
			}
			
			private void OnChanged(object sender, FileSystemEventArgs e)
			{
				// Don't want other threads messing with the pending events right now
				lock (m_pendingEvents)
				{
					// Save a timestamp for the most recent event for this path
					m_pendingEvents[e.FullPath] = DateTime.Now;
					
					// Start a timer if not already started
					if (!m_timerStarted)
					{
						m_timer.Change(100, 100);
						m_timerStarted = true;
					}
				}
			}
			
			private void OnTimeout(object state)
			{
				List<string> paths;
				
				// Don't want other threads messing with the pending events right now
				lock (m_pendingEvents)
				{
					// Get a list of all paths that should have events thrown
					paths = FindReadyPaths(m_pendingEvents);
					
					// Remove paths that are going to be used now
					paths.ForEach(delegate(string path)
					              {
						m_pendingEvents.Remove(path);
					});
					
					// Stop the timer if there are no more events pending
					if (m_pendingEvents.Count == 0)
					{
						m_timer.Change(Timeout.Infinite, Timeout.Infinite);
						m_timerStarted = false;
					}
				}
				
				// Fire an event for each path that has changed
				paths.ForEach(delegate(string path)
				              {
					FireEvent(path);
				});
			}
			
			private List<string> FindReadyPaths(Dictionary<string, DateTime> events)
			{
				List<string> results = new List<string>();
				DateTime now = DateTime.Now;
				
				foreach (KeyValuePair<string, DateTime> entry in events)
				{
					// If the path has not received a new event in the last 75ms
					// an event for the path should be fired
					double diff = now.Subtract(entry.Value).TotalMilliseconds;
					if (diff >= 75)
					{
						results.Add(entry.Key);
					}
				}
				
				return results;
			}
			
			private void FireEvent(string path)
			{
				FileSystemEvent evt = this.Changed;
				if (evt != null)
				{
					evt(path);
				}
			}
		}
		#endregion

        private static DirectoryMonitor ms_DirectoryMonitor = null;
        private static bool ms_AutoHotReload = true;
        private static List<string> ms_ModifiedFiles = new List<string>();

        private static void OnFileChanged(string fullpath)
        {
            if (string.IsNullOrEmpty(fullpath))
                return;

            //behaviac.behaviac.Debug.LogWarning(string.Format("OnFileChanged:{0}", fullpath));

            int index = -1;
            for (int i = 0; i < fullpath.Length - 1; ++i)
            {
                if (fullpath[i] == '.' && fullpath[i + 1] != '.'
                    && fullpath[i + 1] != '/' && fullpath[i + 1] != '\\')
                {
                    index = i;
                    break;
                }
            }

            if (index >= 0)
            {
                string filename = fullpath.Substring(0, index).Replace('\\', '/');
                string ext = fullpath.Substring(index).ToLowerInvariant();

                if (!string.IsNullOrEmpty(ext) &&
                    (FileFormat & EFileFormat.EFF_xml) == EFileFormat.EFF_xml && ext == ".xml" ||
                    (FileFormat & EFileFormat.EFF_bson) == EFileFormat.EFF_bson && ext == ".bson.bytes")
                {
                    int pos = filename.IndexOf(ms_workspaceExportPathAbs);

                    if (pos != -1)
                    {
                        filename = filename.Substring(ms_workspaceExportPathAbs.Length + pos);
                        lock (ms_ModifiedFiles)
                        {
                            if (!ms_ModifiedFiles.Contains(filename))
                            {
                                ms_ModifiedFiles.Add(filename);
                            }
                        }
                    }
                }
            }
        }

        private static List<string> ms_modifiedFiles = new List<string>();
        private static List<string> ModifiedFiles
        {
            get
            {
                return ms_modifiedFiles;
            }
        }

        private static bool GetModifiedFiles()
        {
            if (ms_ModifiedFiles.Count > 0)
            {
                lock (ms_ModifiedFiles)
                {
                    ms_modifiedFiles.Clear();
                    ms_modifiedFiles.AddRange(ms_ModifiedFiles);
                    ms_ModifiedFiles.Clear();
                }

                return true;
            }

            return false;
        }

        public static void SetAutoHotReload(bool enable)
        {
            ms_AutoHotReload = enable;
        }

        public static bool GetAutoHotReload()
        {
#if !BEHAVIAC_RELEASE
            return Config.IsDesktop && ms_AutoHotReload;
#else
			return false;
#endif
        }

        public static void HotReload()
        {
#if !BEHAVIAC_RELEASE
            if (Config.IsDesktop)
            {
                if (GetModifiedFiles())
                {
                    for (int i = 0; i < ModifiedFiles.Count; ++i)
                    {
                        string relativePath = ModifiedFiles[i];
                        if (ms_allBehaviorTreeTasks.ContainsKey(relativePath))
                        {
                            behaviac.Debug.LogWarning(string.Format("Hotreload:{0}", relativePath));

                            if (Load(relativePath, true))
                            {
                                BTItem_t btItem = ms_allBehaviorTreeTasks[relativePath];
                                BehaviorTree behaviorTree = ms_behaviortrees[relativePath];

                                for (int j = 0; j < btItem.bts.Count; ++j)
                                {
                                    BehaviorTreeTask behaviorTreeTask = btItem.bts[j];
                                    behaviorTreeTask.reset(null);
                                    behaviorTreeTask.Clear();
                                    behaviorTreeTask.Init(behaviorTree);
                                }

                                for (int j = 0; j < btItem.agents.Count; ++j)
                                {
                                    Agent agent = btItem.agents[j];
                                    agent.bthotreloaded(behaviorTree);
                                }
                            }
                        }
                    }
                }
            }
#endif
        }
#else
		public static void SetAutoHotReload(bool enable)
		{
		}
		
		public static bool GetAutoHotReload()
		{
			return false;
		}

		public static void HotReload()
		{
		}
#endif//#if BEHAVIAC_HOTRELOAD
        #endregion

		#region Development
		static uint m_frame;
#if !BEHAVIAC_RELEASE
		static string m_applogFilter;
#endif		
		//[breakpoint] set TestBehaviorGroup\btunittest.xml Sequence[3] enter
		//[breakpoint] set TestBehaviorGroup\btunittest.xml Sequence[3] exit
		//[breakpoint] clear TestBehaviorGroup\btunittest.xml Sequence[3] enter
		class BreakpointInfo_t
		{
			public string btname;
			
			public ushort hit_config;
			
			public EActionResult action_result;
			
			public BreakpointInfo_t()
			{
				hit_config = 0;
				action_result = EActionResult.EAR_all;
			}
		};
		
		static Dictionary<uint, BreakpointInfo_t> m_breakpoints = new Dictionary<uint, BreakpointInfo_t>();
		
		static Dictionary<CStringID, int> m_actions_count = new Dictionary<CStringID, int>();
		
		
		//[breakpoint] add TestBehaviorGroup\btunittest.xml.Sequence[3]:enter all Hit=1
		//[breakpoint] add TestBehaviorGroup\btunittest.xml.Sequence[3]:exit all Hit=1
		//[breakpoint] add TestBehaviorGroup\btunittest.xml.Sequence[3]:exit success Hit=1
		//[breakpoint] add TestBehaviorGroup\btunittest.xml.Sequence[3]:exit failure Hit=1
		//[breakpoint] remove TestBehaviorGroup\btunittest.x1ml.Sequence[3]:enter all Hit=10
		static void ParseBreakpoint(string[] tokens)
		{
			BreakpointInfo_t bp = new BreakpointInfo_t();
			
			bool bAdd = false;
			bool bRemove = false;
			
			if (tokens[1] == "add")
			{
				bAdd = true;
			}
			else if (tokens[1] == "remove")
			{
				bRemove = true;
			}
			else
			{
				Debug.Check(false);
			}
			
			bp.btname = tokens[2];
			
			if (tokens[3] == "all")
			{
				Debug.Check(bp.action_result == EActionResult.EAR_all);
			}
			else if (tokens[3] == "success")
			{
				bp.action_result = EActionResult.EAR_success;
			}
			else if (tokens[3] == "failure")
			{
				bp.action_result = EActionResult.EAR_failure;
			}
			else
			{
				Debug.Check(false);
			}
			
			const string kHitNumber = "Hit=";
			int posb = tokens[4].IndexOf(kHitNumber);
			if (posb != -1)
			{
				posb = tokens[4].IndexOf('=');
				Debug.Check(posb != -1);
				
				int size = -1;
				//tokens[4] is the last one with '\n'
				int pose = tokens[4].IndexOf('\n');
				if (pose != -1)
				{
					size = pose - posb - 1;
				}
				else
				{
					size = tokens[4].Length - posb - 1;
				}
				
				string numString = tokens[4].Substring(posb + 1, size);
				bp.hit_config = ushort.Parse(numString);
			}
			
			uint bpid = Utils.MakeVariableId(bp.btname);
			
			if (bAdd)
			{
				m_breakpoints[bpid] = bp;
			}
			else if (bRemove)
			{
				m_breakpoints.Remove(bpid);
			}
		}
		
		
		static void ParseBreakCPP(string[] tokens)
		{
			if (tokens[1] == "true")
			{
				Config.IsDebugging = true;
			}
			else if (tokens[1] == "false")
			{
				Config.IsDebugging = false;
			}
			else
			{
				Debug.Check(false);
			}
			
		}
		
		static void ParseProfiling(string[] tokens)
		{
			if (tokens[1] == "true")
			{
				Config.IsProfiling = true;
			}
			else if (tokens[1] == "false")
			{
				Config.IsProfiling = false;
			}
			else
			{
				Debug.Check(false);
			}
		}
		
		static void ParseAppLogFilter(string[] tokens)
		{
#if !BEHAVIAC_RELEASE
			m_applogFilter = tokens[1];
#endif
		}
		
		//[property] WorldState::WorldState int WorldState::time.185606213
		//[property] Ship::Ship_2_3 long GameObject::age.91291
		//[property] Ship::Ship_2_3 bool par_a.true
		static void ParseProperty(string[] tokens)
		{
#if !BEHAVIAC_RELEASE
			string agentName = tokens[1];
			Agent pAgent = Agent.GetAgent(agentName);
			
			//pAgent could be 0
			if (!System.Object.ReferenceEquals(pAgent, null) && tokens.Length == 4)
			{
				//string varTypeName = tokens[2];
				string varNameValue = tokens[3];
				
				int posb = varNameValue.IndexOf(".");
				Debug.Check(posb != -1);
				
				if (posb != -1)
				{
					int size = -1;
					//varNameValue is the last one with '\n'
					int pose = varNameValue.IndexOf('\n');
					if (pose != -1)
					{
						size = pose - posb - 1;
					}
					
					string varName = varNameValue.Substring(0, posb);
					string varValue = varNameValue.Substring(posb + 2, size);
					
					if (!System.Object.ReferenceEquals(pAgent, null))
					{
						pAgent.SetVariableFromString(varName, varValue);
					}//end of if (pAgent)
				}
			}
#endif
		}
		
		public static void LogFrames()
		{
			LogManager.Log("[frame]{0}\n", m_frame++);
		}

		public static void WaitforContinue()
		{
#if !BEHAVIAC_RELEASE
			while (!HandleRequests())
			{
				System.Threading.Thread.Sleep(200);
			}
#endif//BEHAVIAC_RELEASE
		}

		public static bool HandleRequests()
		{
			bool bContinue = false;

#if !BEHAVIAC_RELEASE
			if (Config.IsSocketing)
			{
				string command = "";
				if (SocketUtils.ReadText(ref command))
				{
					const string kBreakpoint      = "[breakpoint]";
					const string kProperty        = "[property]";
					const string kBreakCPP        = "[breakcpp]";
					const string kProfiling       = "[profiling]";
					const string kStart           = "[start]";
					const string kAppLogFilter    = "[applogfilter]";
					const string kContinue        = "[continue]";
					const string kCloseConnection = "[closeconnection]";
					
					string[] cs = command.Split('\n');
					
					foreach (string c in cs)
					{
						if (string.IsNullOrEmpty(c))
						{
							continue;
						}

						string[] tokens = c.Split(' ');
						
						if (tokens[0] == kBreakpoint)
						{
							ParseBreakpoint(tokens);
						}
						else if (tokens[0] == kProperty)
						{
							ParseProperty(tokens);
						}
						else if (tokens[0] == kBreakCPP)
						{
							ParseBreakCPP(tokens);
						}
						else if (tokens[0] == kProfiling)
						{
							ParseProfiling(tokens);
						}
						else if (tokens[0] == kStart)
						{
							Debug.Check(true);
						}
						else if (tokens[0] == kAppLogFilter)
						{
							ParseAppLogFilter(tokens);
						}
						else if (tokens[0] == kContinue)
						{
							bContinue = true;
						}
						else if (tokens[0] == kCloseConnection)
						{
							m_breakpoints.Clear();
							bContinue = true;
						}
						else
						{
							Debug.Check(false);
						}
					}//end of for
				}//end of if (Socket::ReadText(command))
			}
			else
			{
				bContinue = true;
			}
			#endif

			return bContinue;
		}
		
		public static bool CheckBreakpoint(Agent pAgent, BehaviorTask b, string action, EActionResult actionResult)
		{
#if !BEHAVIAC_RELEASE
			if (Config.IsSocketing)
			{
				string bpStr = BehaviorTask.GetTickInfo(pAgent, b, action);
				
				uint bpid = Utils.MakeVariableId(bpStr);
				
				if (m_breakpoints.ContainsKey(bpid))
				{
					BreakpointInfo_t bp = m_breakpoints[bpid];
					
					if ((bp.action_result & actionResult) != 0)
					{
						int count = GetActionCount(bpStr);
						Debug.Check(count > 0);
						
						if (bp.hit_config == 0 || bp.hit_config == count)
						{
							return true;
						}
					}
				}
			}
			#endif
			return false;
		}
		
		public static bool CheckAppLogFilter(string filter)
		{
#if !BEHAVIAC_RELEASE
			if (Config.IsSocketing)
			{
				//m_applogFilter is UPPER
				if (!string.IsNullOrEmpty(m_applogFilter))
				{
					if (m_applogFilter == "ALL")
					{
						return true;
					}
					else
					{
						string f = filter.ToUpper();
						
						if (m_applogFilter == f)
						{
							return true;
						}
					}
				}
			}
			#endif
			return false;
		}
		
		public static int UpdateActionCount(string actionString)
		{
			lock (m_actions_count)
			{
				int count = 1;
				CStringID actionId = new CStringID(actionString);
				if (!m_actions_count.ContainsKey(actionId))
				{
					m_actions_count[actionId] = count;
				}
				else
				{
					count = m_actions_count[actionId];
					count++;
					m_actions_count[actionId] = count;
				}
				
				return count;
			}
		}
		
		public static int GetActionCount(string actionString)
		{
			lock (m_actions_count)
			{
				int count = 0;
				CStringID actionId = new CStringID(actionString);
				if (m_actions_count.ContainsKey(actionId))
				{
					count = m_actions_count[actionId];
				}
				
				return count;
			}
		}
		#endregion

        #region Load
        private static Dictionary<string, BehaviorTree> ms_behaviortrees;
		private static Dictionary<string, BehaviorTree> BehaviorTrees
        {
            get
            {
                if (ms_behaviortrees == null)
                {
                    ms_behaviortrees = new Dictionary<string, BehaviorTree>();
                }

                return ms_behaviortrees;
            }
        }

        private static Dictionary<string, MethodInfo> ms_btCreators;
        private static Dictionary<string, MethodInfo> BTCreators
        {
            get
            {
                if (ms_btCreators == null)
                {
                    ms_btCreators = new Dictionary<string, MethodInfo>();
                }

                return ms_btCreators;
            }
        }


        public static void RecordBTAgentMapping(string relativePath, Agent agent)
        {
            if (ms_allBehaviorTreeTasks == null)
            {
                ms_allBehaviorTreeTasks = new Dictionary<string, BTItem_t>();
            }

            if (!ms_allBehaviorTreeTasks.ContainsKey(relativePath))
            {
                ms_allBehaviorTreeTasks[relativePath] = new BTItem_t();
            }

            BTItem_t btItems = ms_allBehaviorTreeTasks[relativePath];
            //bool bFound = false;

            if (btItems.agents.IndexOf(agent) == -1)
            {
                btItems.agents.Add(agent);
            }
        }


        public static void UnLoad(string relativePath)
        {
            Debug.Check(string.IsNullOrEmpty(StringUtils.FindExtension(relativePath)), "no extention to specify");
            Debug.Check(Workspace.IsValidPath(relativePath));

            if (BehaviorTrees.ContainsKey(relativePath))
            {
                BehaviorTrees.Remove(relativePath);
            }
        }

        public static void UnLoadAll()
        {
            ms_allBehaviorTreeTasks.Clear();
            BehaviorTrees.Clear();
            BTCreators.Clear();
            if (ms_metaRegistered)
            {
                //TODO inappropriate place to place UnRegisterBasicTypes(), because after call this method to unregister basic types, the program will
                // use ms_IVariableCreators immediately, but all the types in it was unregistered
                // so comment it first 
                //IVariable.UnRegisterBasicTypes();
                //ms_metaRegistered = false;
            }
        }

	    static byte[] ReadFileToBuffer(string file, string ext)
	    {
            byte[] pBuffer = FileManager.Instance.FileOpen(file, ext);

		    return pBuffer;
	    }

        static void PopFileFromBuffer(string file, string ext, byte[] pBuffer)
	    {
            FileManager.Instance.FileClose(file, ext, pBuffer);
	    }

		private static string getValidFilename(string filename)
		{
			filename = filename.Replace("/", "_");
			filename = filename.Replace("-", "_");
			return filename;
		}

        /**
        relativePath is relateve to the workspace path. relativePath should not include extension.
        the file format(xml/bson) is specified by SetWorkspaceSettings.

        @param bForce
        force to load, otherwise it just uses the one in the cache
        */
        public static bool Load(string relativePath, bool bForce)
        {
            Debug.Check(string.IsNullOrEmpty(StringUtils.FindExtension(relativePath)), "no extention to specify");
            Debug.Check(Workspace.IsValidPath(relativePath));

            BehaviorTree pBT = null;
            if (BehaviorTrees.ContainsKey(relativePath))
            {
                if (!bForce)
                {
                    return true;
                }

                pBT = BehaviorTrees[relativePath];
            }

            string fullPath = Workspace.WorkspaceExportPath;
            fullPath += relativePath;

            string ext = "";
            EFileFormat f = Workspace.FileFormat;
            switch (f)
            {
                case EFileFormat.EFF_default:
                    {
					    // try to load the behavior in xml
						ext = ".xml";
					    if (FileManager.Instance.FileExist(fullPath, ext))
					    {
						    f = EFileFormat.EFF_xml;
					    }
					    else
					    {
						    // try to load the behavior in bson
                            ext = ".bson";
                            if (FileManager.Instance.FileExist(fullPath, ext))
						    {
                                f = EFileFormat.EFF_bson;
						    }
						    else
						    {
                                // try to load the behavior in cs
                                f = EFileFormat.EFF_cs;
						    }
					    }
				    }
                    break;

                case EFileFormat.EFF_xml:
                    ext = ".xml";
                    break;

                case EFileFormat.EFF_bson:
                    ext = ".bson";
                    break;

                case EFileFormat.EFF_cs:
                    break;

                default:
                    Debug.Check(false);
                    break;
            }

            bool bLoadResult = false;

            bool bCleared = false;
            bool bNewly = false;
            if (pBT == null)
            {
                bNewly = true;
                pBT = new BehaviorTree();

                //in case of circular referencebehavior
                BehaviorTrees[relativePath] = pBT;
            }

            Debug.Check(pBT != null);

            if (f == EFileFormat.EFF_xml || f == EFileFormat.EFF_bson)
            {
                byte[] pBuffer = ReadFileToBuffer(fullPath, ext);
                if (pBuffer != null)
                {
                    //if forced to reload
                    if (!bNewly)
                    {
                        bCleared = true;
                        pBT.Clear();
                    }

                    if (f == EFileFormat.EFF_xml)
                    {
                        bLoadResult = pBT.load_xml(pBuffer);
                    }
                    else
                    {
                        bLoadResult = pBT.load_bson(pBuffer);
                    }

                    PopFileFromBuffer(fullPath, ext, pBuffer);
                }
            }
            else if (f == EFileFormat.EFF_cs)
            {
                if (!bNewly)
                {
                    bCleared = true;
                    pBT.Clear();
                }

				try
				{
	                MethodInfo m = null;

	                if (BTCreators.ContainsKey(relativePath))
	                {
	                    m = BTCreators[relativePath];
	                }
	                else
	                {
						string clsName = "behaviac.bt_" + getValidFilename(relativePath);
	                    Type type = Utils.GetType(clsName);
	                    if (type != null)
	                    {
	                        m = type.GetMethod("build_behavior_tree", BindingFlags.Public | BindingFlags.Static);
	                        Debug.Check(m != null);
	                        if (m != null)
	                        {
	                            BTCreators[relativePath] = m;
	                        }
	                    }
	                }

	                if (m != null)
	                {
	                    object[] args = { pBT };
	                    bLoadResult = (bool)m.Invoke(null, args);
	                }
					else
					{
						Debug.Check(false);
						Debug.LogWarning("The generated_behaviors.cs file should be added into the app.");
					}
				}
				catch (Exception e)
				{
					string errorInfo = string.Format("The behavior {0} failed to be loaded : {1}", relativePath, e.Message);
					Debug.LogError(errorInfo);
				}
            }
            else
            {
                Debug.Check(false);
            }

            if (bLoadResult)
            {
                Debug.Check(pBT.GetName() == relativePath);
                if (!bNewly)
                {
                    Debug.Check(BehaviorTrees[pBT.GetName()] == pBT);
                }
            }
            else
            {
                if (bNewly)
                {
                    bool removed = BehaviorTrees.Remove(relativePath);
                    Debug.Check(removed);
                }
                else if (bCleared)
                {
                    //it has been cleared but failed to load, to remove it
                    BehaviorTrees.Remove(relativePath);
                }

                behaviac.Debug.LogWarning(string.Format("BehaviorTree {0} not loaded!", fullPath));
            }

            return bLoadResult;
        }

        public static bool Load(string relativePath)
        {
            return Load(relativePath, false);
        }

        public static bool IsValidPath(string relativePath)
        {
            Debug.Check(!string.IsNullOrEmpty(relativePath));

            if (relativePath[0] == '.' && (relativePath[1] == '/' || relativePath[1] == '\\'))
            {
                // ./dummy_bt
                return false;
            }
            else if (relativePath[0] == '/' || relativePath[0] == '\\')
            {
                // /dummy_bt
                return false;
            }

            return true;
        }

        class BTItem_t
        {
            public List<BehaviorTreeTask> bts = new List<BehaviorTreeTask>();
            public List<Agent> agents = new List<Agent>();
        };

        static Dictionary<string, BTItem_t> ms_allBehaviorTreeTasks = new Dictionary<string, BTItem_t>();

        /**
        uses the behavior tree in the cache, if not loaded yet, it loads the behavior tree first
        */
        public static BehaviorTreeTask CreateBehaviorTreeTask(string relativePath)
        {
            Debug.Check(string.IsNullOrEmpty(Path.GetExtension(relativePath)), "no extention to specify");
            Debug.Check(Workspace.IsValidPath(relativePath));

            BehaviorTree bt = null;
            if (BehaviorTrees.ContainsKey(relativePath))
            {
                bt = BehaviorTrees[relativePath];
            }
            else
            {
                bool bOk = Workspace.Load(relativePath);

                if (bOk)
                {
                    bt = BehaviorTrees[relativePath];
                }
            }

            if (bt != null)
            {
                BehaviorTask task = bt.CreateAndInitTask();
                Debug.Check(task is BehaviorTreeTask);
                BehaviorTreeTask behaviorTreeTask = task as BehaviorTreeTask;

                if (!ms_allBehaviorTreeTasks.ContainsKey(relativePath))
                {
                    ms_allBehaviorTreeTasks[relativePath] = new BTItem_t();
                }

                BTItem_t btItem = ms_allBehaviorTreeTasks[relativePath];
                if (!btItem.bts.Contains(behaviorTreeTask))
                {
                    btItem.bts.Add(behaviorTreeTask);
                }

                return behaviorTreeTask;
            }

            return null;
        }

        public static void DestroyBehaviorTreeTask(BehaviorTreeTask behaviorTreeTask, Agent agent)
        {
            if (behaviorTreeTask != null)
            {
                if (ms_allBehaviorTreeTasks.ContainsKey(behaviorTreeTask.GetName()))
                {
                    BTItem_t btItem = ms_allBehaviorTreeTasks[behaviorTreeTask.GetName()];
                    btItem.bts.Remove(behaviorTreeTask);

					if (agent != null)
					{
                        btItem.agents.Remove(agent);
					}
                }

                BehaviorTask.DestroyTask(behaviorTreeTask);
            }
        }

        public static Dictionary<string, BehaviorTree> GetBehaviorTrees()
        {
            return ms_behaviortrees;
        }

        #endregion

        #region ExportMeta
        private static Dictionary<string, Type> ms_behaviorNodeTypes;
		public static void RegisterBehaviorNode()
		{
			//Assembly a = Assembly.GetExecutingAssembly();
			Assembly a = Assembly.GetCallingAssembly();

			RegisterBehaviorNode (a);
		}

		public static void RegisterBehaviorNode(Assembly a)
        {
            //Debug.Check(ms_behaviorNodeTypes != null);
            if (ms_behaviorNodeTypes == null) {
                ms_behaviorNodeTypes = new Dictionary<string, Type>();
            }

            //List<Type> agentTypes = new List<Type>();
            Type[] types = a.GetTypes();
            foreach (Type type in types)
            {
                if (type.IsSubclassOf(typeof(behaviac.BehaviorNode)) && !type.IsAbstract)
                {
                    //Attribute[] attributes = (Attribute[])type.GetCustomAttributes(typeof(Behaviac.Design.BehaviorNodeDescAttribute), false);
                    //if (attributes.Length > 0)
                    {
                        ms_behaviorNodeTypes[type.Name] = type;
                    }
                }
            }
        }

        public static BehaviorNode CreateBehaviorNode(string className)
        {
            if (ms_behaviorNodeTypes.ContainsKey(className))
            {
                Type type = ms_behaviorNodeTypes[className];
                object p = Activator.CreateInstance(type);
                return p as BehaviorNode;
            }

            return null;
        }

#if !BEHAVIAC_RELEASE
		private static void ExportStructTypeField(Dictionary<string, Type> types, XmlWriter xmlWriter, Type type, bool onlyExportPublicMembers)
        {
			bool bIsAgentDerived = Utils.IsAgentType(type);
			if (!bIsAgentDerived && Utils.IsCustomClassType(type))
            {
                string displayName = type.Name;
                string desc = displayName;

                Attribute[] attributes = (Attribute[])type.GetCustomAttributes(typeof(behaviac.TypeMetaInfoAttribute), false);
                if (attributes.Length > 0)
                {
                    behaviac.TypeMetaInfoAttribute cda = (behaviac.TypeMetaInfoAttribute)attributes[0];
                    if (!string.IsNullOrEmpty(cda.DisplayName))
                    {
                        displayName = cda.DisplayName;
                    }

                    if (!string.IsNullOrEmpty(cda.Description))
                    {
                        desc = cda.Description;
                    }
                }

				string typeFullName = GetFullTypeName(type);

                if (types == null)
                {
                    xmlWriter.WriteStartElement("struct");

					xmlWriter.WriteAttributeString("Type", typeFullName);
                    xmlWriter.WriteAttributeString("DisplayName", displayName);
                    xmlWriter.WriteAttributeString("Desc", desc);

					if (!Utils.IsNullValueType(type))
					{
						ExportType(types, xmlWriter, type, false, onlyExportPublicMembers);
					}

					//end of struct
					xmlWriter.WriteEndElement();
                }
                else
                {
					if (!types.ContainsKey(typeFullName))
					{
						types.Add(typeFullName, type);

						if (!Utils.IsNullValueType(type))
						{
							ExportType(types, xmlWriter, type, false, onlyExportPublicMembers);
						}
					}
                }
            }
        }

        private static void ExportEnumTypeField(Dictionary<string, Type> types, XmlWriter xmlWriter, Type type)
        {
            if (Utils.IsEnumType(type))
            {
                string displayName = type.Name;
                string desc = displayName;

                Attribute[] attributes = (Attribute[])type.GetCustomAttributes(typeof(behaviac.TypeMetaInfoAttribute), false);
                if (attributes.Length > 0)
                {
                    behaviac.TypeMetaInfoAttribute eda = (behaviac.TypeMetaInfoAttribute)attributes[0];
                    displayName = eda.DisplayName;
                    desc = eda.Description;
                }

				string typeFullName = GetFullTypeName(type);

                if (types == null)
                {
                    //xmlWriter.WriteAttributeString("enum", "true");

                    xmlWriter.WriteStartElement("enumtype");
                    xmlWriter.WriteAttributeString("Type", typeFullName);
                    xmlWriter.WriteAttributeString("DisplayName", displayName);
                    xmlWriter.WriteAttributeString("Desc", desc);

                    Array list = Enum.GetValues(type);
                    foreach (object enumVal in list)
                    {
                        xmlWriter.WriteStartElement("enum");
                        xmlWriter.WriteAttributeString("NativeValue", Enum.GetName(type, enumVal));
                        xmlWriter.WriteAttributeString("Value", Enum.GetName(type, enumVal));
                        xmlWriter.WriteAttributeString("DisplayName", behaviac.MemberMetaInfoAttribute.GetEnumDisplayName(enumVal));
                        xmlWriter.WriteAttributeString("Desc", behaviac.MemberMetaInfoAttribute.GetEnumDescription(enumVal));

                        //end of enum
                        xmlWriter.WriteEndElement();
                    }

                    //end of enumtype
                    xmlWriter.WriteEndElement();
                }
                else
                {
                    if (!types.ContainsKey(typeFullName))
                        types.Add(typeFullName, type);
                }
            }
        }

        private static string GetFullTypeName(Type type)
        {
            string baseTypeName = Utils.GetNativeTypeName(type);
            if (Utils.IsEnumType(type) || Utils.IsCustomClassType(type))
            {
				if (type.DeclaringType != null)
				{
					string declaringType = type.DeclaringType.Name.Replace(".", "::");
					baseTypeName = string.Format("{0}::{1}", declaringType, baseTypeName);
				}

                if (!string.IsNullOrEmpty(type.Namespace))
				{
					baseTypeName = string.Format("{0}::{1}", type.Namespace.Replace(".", "::"), baseTypeName);
				}
            }
            else if (Utils.IsArrayType(type))
            {
                Type elementType = type.GetGenericArguments()[0];
                baseTypeName = string.Format("vector<{0}>", GetFullTypeName(elementType));
            }

            return baseTypeName;
        }

		private static bool IsMemberReadonly(MemberInfo m)
		{
			FieldInfo field = m as FieldInfo;
			if (field != null)
			{
				return field.IsInitOnly || field.IsLiteral;
			}
			
			PropertyInfo f = m as PropertyInfo;
			
			MethodInfo getter = f.GetGetMethod();
			if (getter != null)
			{
				MethodInfo settter = f.GetSetMethod();
				
				if (settter == null)
				{
					return true;
				}
			}
			
			return false;
		}

		private static void ExportType(Dictionary<string, Type> types, XmlWriter xmlWriter, Type type, bool bIsAgentType, bool onlyExportPublicMembers)
        {
            //FieldInfo[] fields = agentType.GetFields(BindingFlags.Instance | BindingFlags.Static);
            FieldInfo[] fields = type.GetFields(BindingFlags.NonPublic | BindingFlags.Public | BindingFlags.Instance | BindingFlags.Static | BindingFlags.DeclaredOnly);

            for (int i = 0; i < fields.Length; ++i)
            {
                FieldInfo f = fields[i];
				string displayName = f.Name;
                string desc = displayName;
				string classFullName = GetFullTypeName(type);
                if (bIsAgentType)
                {
                    Attribute[] attributes = (Attribute[])f.GetCustomAttributes(typeof(behaviac.MemberMetaInfoAttribute), false);
                    if (attributes.Length > 0)
                    {
                        behaviac.MemberMetaInfoAttribute memberDesc = (behaviac.MemberMetaInfoAttribute)attributes[0];

                        displayName = memberDesc.DisplayName;
                        desc = memberDesc.Description;
                    }
                    else
                    {
                        //skip those members which are not decorated by MemberDescAttribute
                        continue;
                    }
                }

				if (!f.IsPublic)
				{
					if (!Config.IsSuppressingNonPublicWarning)
					{
						string warningInfo = string.Format("Export non-public property : {0}.{1}", f.DeclaringType.Name, f.Name);
						Debug.LogWarning(warningInfo);
					}
					
					if (onlyExportPublicMembers)
					{
						continue;
					}
				}

                if (types == null)
                {
//					if (f.Name == "code")
//					{
//						Debug.Check(true);
//					}
                    string memberType = GetFullTypeName(f.FieldType);

                    xmlWriter.WriteStartElement("Member");

                    xmlWriter.WriteAttributeString("Name", f.Name);
                    xmlWriter.WriteAttributeString("DisplayName", displayName);
                    xmlWriter.WriteAttributeString("Desc", desc);
                    xmlWriter.WriteAttributeString("Type", memberType);
                    xmlWriter.WriteAttributeString("Class", classFullName);

					if (IsMemberReadonly(f))
					{
						xmlWriter.WriteAttributeString("Readonly", "true");
					}

                    if (f.IsStatic)
                    {
                        xmlWriter.WriteAttributeString("Static", "true");
                    }
                    if (f.IsPublic)
                    {
                        xmlWriter.WriteAttributeString("Public", "true");
                    }

                    //end of Member
                    xmlWriter.WriteEndElement();
                }
                else
                {
                    if (Utils.IsArrayType(f.FieldType))
                    {
                        Type elementType = f.FieldType.GetGenericArguments()[0];

                        if (Utils.IsCustomClassType(elementType)) // struct
                        {
							ExportStructTypeField(types, xmlWriter, elementType, onlyExportPublicMembers);
                        }
                        else if (Utils.IsEnumType(elementType)) // enum
                        {
                            ExportEnumTypeField(types, xmlWriter, elementType);
                        }
                    }
                    else if (Utils.IsCustomClassType(f.FieldType)) // struct
                    {
						ExportStructTypeField(types, xmlWriter, f.FieldType, onlyExportPublicMembers);
                    }
                    else if (Utils.IsEnumType(f.FieldType)) // enum
                    {
                        ExportEnumTypeField(types, xmlWriter, f.FieldType);
                    }
                }
            }

			if (bIsAgentType)
			{
				List<string> exportedMethods = new List<string>();
				
				BindingFlags bindingFlags = BindingFlags.NonPublic | BindingFlags.Public | BindingFlags.Instance | BindingFlags.Static | BindingFlags.DeclaredOnly;
				MethodInfo[] methods = type.GetMethods(bindingFlags);
				foreach (MethodInfo m in methods)
				{
					Attribute[] attributes = (Attribute[])m.GetCustomAttributes(typeof(behaviac.MethodMetaInfoAttribute), false);
					if (attributes.Length > 0)
					{
						behaviac.MethodMetaInfoAttribute methodDesc = (behaviac.MethodMetaInfoAttribute)attributes[0];
						
						ExportMethod(types, xmlWriter, m, methodDesc, null, onlyExportPublicMembers);
						
						if (exportedMethods.Contains(m.Name))
						{
							string info = string.Format("There are more than one method with the same name {0} in class {1}.", m.Name, m.DeclaringType.Name);
							Debug.LogError(info);
						}
						else
						{
							exportedMethods.Add(m.Name);
						}
					}
				}

				Type[] delegates = type.GetNestedTypes(bindingFlags);
				foreach (Type d in delegates)
				{
					Attribute[] attributes = (Attribute[])d.GetCustomAttributes(typeof(behaviac.EventMetaInfoAttribute), false);
					if (attributes.Length > 0)
					{
						behaviac.EventMetaInfoAttribute eventDesc = (behaviac.EventMetaInfoAttribute)attributes[0];
						
						MethodInfo m = d.GetMethod("Invoke");
						ExportMethod(types, xmlWriter, m, eventDesc, d.Name, onlyExportPublicMembers);

						if (exportedMethods.Contains(d.Name))
						{
							string info = string.Format("There are more than one method or event with the same name {0} in class {1}.", d.Name, d.DeclaringType.Name);
							Debug.LogError(info);
						}
						else
						{
							exportedMethods.Add(d.Name);
						}
					}
				}
			}
		}
		
		private static void ExportMethod(Dictionary<string, Type> types, XmlWriter xmlWriter, MethodInfo m, behaviac.MethodMetaInfoAttribute methodDesc, string eventName, bool onlyExportPublicMembers)
		{
			string methodName = !string.IsNullOrEmpty(eventName) ? eventName : m.Name;

//			if (methodName == "Func_SByteListIR")
//			{
//				Debug.Check(true);
//			}

			if (!m.IsPublic)
			{
				if (!Config.IsSuppressingNonPublicWarning)
				{
					string warningInfo = string.Format("Export non-public method : {0}.{1}()", m.DeclaringType.Name, methodName);
					Debug.LogWarning(warningInfo);
				}
				
				if (onlyExportPublicMembers)
				{
					return;
				}
			}

            Type returnType = m.ReturnType;
            if (methodDesc.IsNamedEvent && returnType != typeof(bool))
            {
				string clsName = (m.DeclaringType.DeclaringType != null) ? m.DeclaringType.DeclaringType.Name : m.DeclaringType.Name;
				behaviac.Debug.LogWarning(string.Format("The return type of {0}.{1}() is not bool type", clsName, methodName));
                returnType = typeof(bool);
            }

            string returnTypeStr = GetFullTypeName(returnType);

            Type parentClassType = m.DeclaringType;
            if (methodDesc.IsNamedEvent)
            {
                parentClassType = m.DeclaringType.DeclaringType;
            }

			string parentClassTypeFullName = GetFullTypeName(parentClassType);

            if (types == null)
            {
                xmlWriter.WriteStartElement("Method");

                xmlWriter.WriteAttributeString("Name", methodName);
                xmlWriter.WriteAttributeString("DisplayName", methodDesc.DisplayName);
                xmlWriter.WriteAttributeString("Desc", methodDesc.Description);
                xmlWriter.WriteAttributeString("ReturnType", returnTypeStr);
                xmlWriter.WriteAttributeString("Class", parentClassTypeFullName);

                if (m.IsStatic)
                {
                    xmlWriter.WriteAttributeString("Static", "true");
                }
                if (m.IsPublic)
                {
                    xmlWriter.WriteAttributeString("Public", "true");
                }
                if (methodDesc.IsNamedEvent)
                {
                    xmlWriter.WriteAttributeString("Flag", "namedevent");
                }
            }

            //TODO:IsActionMethodOnly

            ParameterInfo[] parameters = m.GetParameters();

            foreach (ParameterInfo para in parameters)
            {
                Attribute[] paramAttributes = (Attribute[])para.GetCustomAttributes(typeof(behaviac.ParamMetaInfoAttribute), false);

                Type paramType = para.ParameterType;
                if (para.ParameterType.IsByRef)
                {
                    paramType = para.ParameterType.GetElementType();
                }

                string paramNativeType = GetFullTypeName(paramType);
                string paramDisplayName = para.Name;
                string paramDescription = paramDisplayName;
                string defaultValue = "";
                float rangeMin = float.MinValue;
                float rangeMax = float.MaxValue;

                if (paramAttributes.Length > 0)
                {
                    behaviac.ParamMetaInfoAttribute paramDescAttr = ((behaviac.ParamMetaInfoAttribute)paramAttributes[0]);
                    paramDisplayName = paramDescAttr.DisplayName;
                    paramDescription = paramDescAttr.Description;
                    defaultValue = paramDescAttr.DefaultValue;
                    rangeMin = paramDescAttr.RangeMin;
                    rangeMax = paramDescAttr.RangeMax;
                }

                if (para.ParameterType.IsByRef)
                {
                    paramNativeType += "&";
                }

				bool bIsNullValueType = Utils.IsNullValueType(paramType);
				if (bIsNullValueType)
                {
                    paramNativeType += "*";
                }

                if (types == null)
                {
                    xmlWriter.WriteStartElement("Param");
                    xmlWriter.WriteAttributeString("DisplayName", paramDisplayName);
                    xmlWriter.WriteAttributeString("Desc", paramDescription);
                    xmlWriter.WriteAttributeString("Type", paramNativeType);
                    if (!string.IsNullOrEmpty(defaultValue))
                    {
                        xmlWriter.WriteAttributeString("Default", defaultValue);
                    }
                    if (rangeMin != float.MinValue)
                    {
                        xmlWriter.WriteAttributeString("RangeMin", rangeMin.ToString());
                    }
                    if (rangeMax != float.MaxValue)
                    {
                        xmlWriter.WriteAttributeString("RangeMax", rangeMax.ToString());
                    }

                    //end of Param
                    xmlWriter.WriteEndElement();
                }
                else
                {
					if (Utils.IsArrayType(paramType))
					{
						Type elementType = paramType.GetGenericArguments()[0];
						if (Utils.IsCustomClassType(elementType))
						{
							ExportStructTypeField(types, xmlWriter, elementType, onlyExportPublicMembers);
						}
						else if (Utils.IsEnumType(elementType))
						{
							ExportEnumTypeField(types, xmlWriter, elementType);
						}
					}
					else if (Utils.IsCustomClassType(paramType))
					{
						ExportStructTypeField(types, xmlWriter, paramType, onlyExportPublicMembers);
					}
					else if (Utils.IsEnumType(paramType))
					{
						ExportEnumTypeField(types, xmlWriter, paramType);
					}
				}
			}

			if (types == null)
			{
				//end of Method
				xmlWriter.WriteEndElement();
			}
			else
			{
				if (Utils.IsArrayType(returnType))
				{
					Type elementType = returnType.GetGenericArguments()[0];
					if (Utils.IsCustomClassType(elementType))
					{
						ExportStructTypeField(types, xmlWriter, elementType, onlyExportPublicMembers);
					}
					else if (Utils.IsEnumType(elementType))
					{
						ExportEnumTypeField(types, xmlWriter, elementType);
					}
				}
				else if (Utils.IsCustomClassType(returnType))
				{
					ExportStructTypeField(types, xmlWriter, returnType, onlyExportPublicMembers);
				}
				else if (Utils.IsEnumType(returnType))
				{
					ExportEnumTypeField(types, xmlWriter, returnType);
				}
			}
		}
		#endif
		
		#if !BEHAVIAC_RELEASE
		private static void ExportNames(XmlWriter xmlWriter)
		{
			if (Agent.Names.Count > 0)
			{
				xmlWriter.WriteStartElement("instances");
				foreach (Agent.AgentName_t m in Agent.Names.Values)
				{
					xmlWriter.WriteStartElement("instance");
					
					xmlWriter.WriteAttributeString("name", m.instantceName_.Replace(".", "::"));
					xmlWriter.WriteAttributeString("class", m.className_.Replace(".", "::"));
					xmlWriter.WriteAttributeString("DisplayName", m.displayName_);
					xmlWriter.WriteAttributeString("Desc", m.desc_);
					
					xmlWriter.WriteEndElement();
				}
				
				xmlWriter.WriteEndElement();
			}
		}
#endif

		public static bool ExportMetas(string filePath, bool onlyExportPublicMembers)
        {
#if !BEHAVIAC_RELEASE
            if (Config.IsDesktopEditor)
            {
				RegisterMetas();

                try
                {
                    // export to the file
                    using (StreamWriter file = new StreamWriter(filePath))
                    {
                        XmlWriterSettings ws = new XmlWriterSettings();
                        ws.Indent = true;
                        //ws.OmitXmlDeclaration = true;

                        using (XmlWriter xmlWriter = XmlWriter.Create(file, ws))
                        {
                            xmlWriter.WriteStartDocument();
                            xmlWriter.WriteComment("EXPORTED BY TOOL, DON'T MODIFY IT!");

                            xmlWriter.WriteStartElement("metas");
                            string versionStr = "2.0";
                            xmlWriter.WriteAttributeString("version", versionStr);

                            // collect all types
                            Dictionary<string, Type> exportedTypes = new Dictionary<string, Type>();

                            foreach (TypeInfo_t typeInfo in ms_agentTypes)
                            {
                                Type agentType = typeInfo.type;
								Debug.Check(Utils.IsAgentType(agentType) || Utils.IsStaticType(agentType));

								Attribute[] attributes = (Attribute[])agentType.GetCustomAttributes(typeof(behaviac.TypeMetaInfoAttribute), false);
                                if (attributes.Length > 0)
                                {
                                    //Agent.CTagObjectDescriptor objectDesc = Agent.GetDescriptorByName(agentType.Name);

									ExportType(exportedTypes, xmlWriter, agentType, true, onlyExportPublicMembers);
                                }
                            }

                            // export all types
                            xmlWriter.WriteStartElement("types");

                            // export all enums
                            foreach (KeyValuePair<string, Type> type in exportedTypes)
                            {
                                if (Utils.IsEnumType(type.Value)) // enum
                                {
                                    ExportEnumTypeField(null, xmlWriter, type.Value);
                                }
                            }

                            // export all structs
                            foreach (KeyValuePair<string, Type> type in exportedTypes)
                            {
                                if (Utils.IsCustomClassType(type.Value)) // struct
                                {
									ExportStructTypeField(null, xmlWriter, type.Value, onlyExportPublicMembers);
                                }
                            }

                            // end of types
                            xmlWriter.WriteEndElement();

                            // agents
                            xmlWriter.WriteStartElement("agents");

                            foreach (TypeInfo_t typeInfo in ms_agentTypes)
                            {
                                Type agentType = typeInfo.type;
								Debug.Check(Utils.IsAgentType(agentType) || Utils.IsStaticType(agentType));
								
								xmlWriter.WriteStartElement("agent");

								string agentFullName = GetFullTypeName(agentType);
                                xmlWriter.WriteAttributeString("classfullname", agentFullName);

                                if (agentType.BaseType != null && agentType.BaseType != typeof(object) && agentType != typeof(Agent))
                                {
                                    string baseClass = GetFullTypeName(agentType.BaseType);
                                    xmlWriter.WriteAttributeString("base", baseClass);
                                }

                                Attribute[] attributes = (Attribute[])agentType.GetCustomAttributes(typeof(behaviac.TypeMetaInfoAttribute), false);
                                if (attributes.Length > 0)
                                {
                                    //behaviac.AgentTypeAttribute cda = (behaviac.AgentTypeAttribute)attributes[0];
                                    Agent.CTagObjectDescriptor objectDesc = Agent.GetDescriptorByName(agentType.Name);

                                    xmlWriter.WriteAttributeString("DisplayName", objectDesc.displayName);
                                    xmlWriter.WriteAttributeString("Desc", objectDesc.desc);

									ExportType(null, xmlWriter, agentType, true, onlyExportPublicMembers);
                                }
                                else
                                {
									if (Utils.IsAgentType(agentType))
									{
										xmlWriter.WriteAttributeString("inherited", "true");
                                    }

                                    xmlWriter.WriteAttributeString("DisplayName", "");
                                    xmlWriter.WriteAttributeString("Desc", "");

                                    if (!string.IsNullOrEmpty(agentType.Namespace))
                                    {
										xmlWriter.WriteAttributeString("Namespace", agentType.Namespace.Replace(".", "::"));
                                    }
                                }

                                // end of agent
                                xmlWriter.WriteEndElement();
                            }

                            // end of agents
                            xmlWriter.WriteEndElement();

                            // instances
                            ExportNames(xmlWriter);

                            // end of metas
                            xmlWriter.WriteEndElement();

                            xmlWriter.WriteEndDocument();
                        }

                        file.Close();
                    }

                    //TODO:names

                    return true;
                }
                catch (Exception ex)
                {
                    behaviac.Debug.LogError(ex.Message);
                }
            }
#endif
            return false;
        }

		public static bool ExportMetas(string filePath)
		{
			return ExportMetas(filePath, false);
		}

        class TypeInfo_t
        {
            public Type type;
            public bool bIsInherited;
        }
        private static List<TypeInfo_t> ms_agentTypes = new List<TypeInfo_t>();

        private static bool IsRegisterd(Type type)
        {
            int p = ms_agentTypes.FindIndex(delegate(TypeInfo_t t) { return t.type == type; });

            return p != -1;
        }

		private static bool ms_metaRegistered = false;
		private static void RegisterMetas()
		{
			if (!ms_metaRegistered)
			{
				Assembly a = Assembly.GetCallingAssembly();

				RegisterMetas (a);
                IVariable.RegisterBasicTypes();

				ms_metaRegistered = true;
			}
		}

		private static void RegisterMetas(Assembly a)
        {
            List<Type> baseTypes = new List<Type>();

            Type[] types = a.GetTypes();
            foreach (Type type in types)
            {
				if (type.IsSubclassOf(typeof(behaviac.Agent)) || Utils.IsStaticType(type))
                {
                    if (!IsRegisterd(type))
                    {
                        Attribute[] attributes = (Attribute[])type.GetCustomAttributes(typeof(behaviac.TypeMetaInfoAttribute), false);
                        if (attributes.Length > 0)
                        {
                            TypeInfo_t typeInfo = new TypeInfo_t();
                            typeInfo.type = type;

                            ms_agentTypes.Add(typeInfo);

                            //find all the base type and ancestors
                            Type ti = type.BaseType;
                            while (ti != null && Utils.IsAgentType(ti))
                            {
                                baseTypes.Add(ti);
                                ti = ti.BaseType;
                            }

							if (Utils.IsStaticType(type))
							{
								behaviac.TypeMetaInfoAttribute typeMetaInfo = attributes[0] as behaviac.TypeMetaInfoAttribute;
								Agent.RegisterStaticClass(type, typeMetaInfo.DisplayName, typeMetaInfo.Description);
							}
                        }
                    }
                }
            }

            foreach (Type type in baseTypes)
            {
                if (!IsRegisterd(type))
                {
                    TypeInfo_t ft = ms_agentTypes.Find(delegate(TypeInfo_t t) { return t.type == type; });

                    //not found
                    if (ft == null)
                    {
                        TypeInfo_t typeInfo = new TypeInfo_t();
                        typeInfo.type = type;
                        typeInfo.bIsInherited = true;

                        ms_agentTypes.Add(typeInfo);
                    }
                }
            }

            ms_agentTypes.Sort(delegate(TypeInfo_t x, TypeInfo_t y)
            {
                if (x.bIsInherited && !y.bIsInherited)
                {
                    return -1;
                }
                else if (!x.bIsInherited && y.bIsInherited)
                {
                    return 1;
                }

                if (x.type.IsSubclassOf(y.type))
                {
                    return 1;
                }
                else if (y.type.IsSubclassOf(x.type))
                {
                    return -1;
                }

                return x.type.FullName.CompareTo(y.type.FullName);
            });

            foreach (TypeInfo_t typeInfo in ms_agentTypes)
            {
                Type type = typeInfo.type;
				Debug.Check(Utils.IsAgentType(type) || Utils.IsStaticType(type));
				RegisterType(type, true);
            }
        }

        private static void RegisterType(Type type, bool bIsAgentType)
        {
            Attribute[] attributes = (Attribute[])type.GetCustomAttributes(typeof(behaviac.TypeMetaInfoAttribute), false);

            //agent type must have behaviac.AgentTypeAttribute
            if (!bIsAgentType || attributes.Length > 0)
            {
                behaviac.TypeMetaInfoAttribute cda = attributes.Length > 0 ? (behaviac.TypeMetaInfoAttribute)attributes[0] : null;

                Agent.CTagObjectDescriptor objectDesc = Agent.GetDescriptorByName(type.FullName);

                if (Utils.IsAgentType(type.BaseType))
                {
                    Agent.CTagObjectDescriptor baseObjectDesc = Agent.GetDescriptorByName(type.BaseType.FullName);
                    objectDesc.m_parent = baseObjectDesc;
                }

                objectDesc.type = type;
                objectDesc.displayName = ((cda == null || string.IsNullOrEmpty(cda.DisplayName)) ? type.FullName : cda.DisplayName);
                objectDesc.desc = ((cda == null || string.IsNullOrEmpty(cda.Description)) ? objectDesc.displayName : cda.Description);

                if (Utils.IsEnumType(type))
                {
                    return;
                }

                BindingFlags bindingFlags = BindingFlags.NonPublic | BindingFlags.Public | BindingFlags.Instance | BindingFlags.Static | BindingFlags.DeclaredOnly;

                FieldInfo[] fields = type.GetFields(bindingFlags);
                foreach (FieldInfo f in fields)
                {
                    //for agent type, only register members with MemberDescAttribute
                    bool bToRegister = false;

                    behaviac.MemberMetaInfoAttribute memberDesc = null;
                    if (bIsAgentType)
                    {
                        Attribute[] attributes1 = (Attribute[])f.GetCustomAttributes(typeof(behaviac.MemberMetaInfoAttribute), false);
                        if (attributes1.Length > 0)
                        {
                            memberDesc = (behaviac.MemberMetaInfoAttribute)attributes1[0];
                            bToRegister = true;
                        }
                    }
                    else
                    {
                        bToRegister = true;
                    }

                    if (bToRegister)
                    {
                        CMemberBase m = new CMemberBase(f, memberDesc);

						CMemberBase pMember = objectDesc.ms_members.Find(delegate(CMemberBase m1) { return m1.GetId() == m.GetId(); });
						Debug.Check(pMember == null, "RegisterMetas is called more than once!");

                        objectDesc.ms_members.Add(m);

                        if ((Utils.IsCustomClassType(f.FieldType) || Utils.IsEnumType(f.FieldType)) &&
                            !Agent.IsTypeRegisterd(f.FieldType.FullName))
                        {
                            RegisterType(f.FieldType, false);
                        }
                    }
                }

                if (bIsAgentType)
                {
                    MethodInfo[] methods = type.GetMethods(bindingFlags);
                    foreach (MethodInfo m in methods)
                    {
                        Attribute[] attributes2 = (Attribute[])m.GetCustomAttributes(typeof(behaviac.MethodMetaInfoAttribute), false);
                        if (attributes2.Length > 0)
                        {
                            behaviac.MethodMetaInfoAttribute methodDesc = (behaviac.MethodMetaInfoAttribute)attributes2[0];

                            CMethodBase method = new CMethodBase(m, methodDesc, null);
                            objectDesc.ms_methods.Add(method);

                            ParameterInfo[] parameters = m.GetParameters();

                            foreach (ParameterInfo para in parameters)
                            {
                                if ((Utils.IsCustomClassType(para.ParameterType) || Utils.IsEnumType(para.ParameterType)) &&
                                    !Agent.IsTypeRegisterd(para.ParameterType.FullName))
                                {
                                    RegisterType(para.ParameterType, false);
                                }
                            }

                            if ((Utils.IsCustomClassType(m.ReturnType) || Utils.IsEnumType(m.ReturnType)) &&
                                !Agent.IsTypeRegisterd(m.ReturnType.FullName))
                            {
                                RegisterType(m.ReturnType, false);
                            }
                        }
                    }//end of foreach

                    Type[] delegates = type.GetNestedTypes(bindingFlags);
                    foreach (Type d in delegates)
                    {
                        Attribute[] attributes0 = (Attribute[])d.GetCustomAttributes(typeof(behaviac.EventMetaInfoAttribute), false);
                        if (attributes0.Length > 0)
                        {
                            behaviac.EventMetaInfoAttribute eventDesc = (behaviac.EventMetaInfoAttribute)attributes0[0];

                            MethodInfo m = d.GetMethod("Invoke");

                            CNamedEvent method = new CNamedEvent(m, eventDesc, d.Name);
                            objectDesc.ms_methods.Add(method);
                        }
                    }
                }//if (bIsAgentType)
            }
        }
        #endregion
     }
}