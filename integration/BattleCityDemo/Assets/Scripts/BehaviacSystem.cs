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

using UnityEngine;
using System.Collections;
using System;
#if UNITY_EDITOR || UNITY_STANDALONE_WIN
using System.Runtime.InteropServices;
#endif

[AddComponentMenu("BattleCity/BehaviacSystem")]
public class BehaviacSystem : Singleton<BehaviacSystem>
{
		private bool m_bIsInited = false;
		protected static BehaviacFileManager fileSystem = null;

#if UNITY_EDITOR || UNITY_STANDALONE_WIN
		[DllImport("user32.dll", CharSet=CharSet.Auto)]
		public static extern int MessageBox(int hWnd, String text, String caption, int options);
#endif


		private static void RespondToBreak (string msg, string title)
		{
//#if UNITY_EDITOR
//		if (Application.platform == RuntimePlatform.WindowsEditor) 
//		{
//			UnityEditor.EditorUtility.DisplayDialog (title, msg, "Ok");
//		} 
//#endif
#if UNITY_EDITOR || UNITY_STANDALONE_WIN
			MessageBox(0, title, msg, 0);
#endif
		}

		public bool init ()
		{		
			if (!m_bIsInited) 
			{
				m_bIsInited = true;

				if(fileSystem == null)
				{
					fileSystem = new BehaviacFileManager ();
	            }
            	//behaviac.Workspace.RegisterBehaviorNode ();
				
				//register agents
				//behaviac.Workspace.RegisterMetas ();				
				string btExportPath = GameLevelCommon.WorkspaceExportedPath;
				behaviac.Workspace.EFileFormat btFileFormat = behaviac.Workspace.EFileFormat.EFF_xml;
				behaviac.Workspace.SetWorkspaceSettings (btExportPath, btFileFormat);            
				//register names
				behaviac.Agent.RegisterName<GameLevelCommon> ("GameLevel");
								
				string metaExportPath = GameLevelCommon.WorkspacePath + "/xmlmeta/BattleCityMeta.xml";
				behaviac.Workspace.ExportMetas (metaExportPath);
				behaviac.Debug.Log ("Behaviac meta data export over.");

				//behaviac.Workspace.RespondToBreakHandler += RespondToBreak;

				//< write log file
				//behaviac.Config.IsLogging = false;
				//behaviac.Config.IsSocketing = false;				
				
				bool isBlockSocket = false;
				behaviac.SocketUtils.SetupConnection (isBlockSocket);		
				behaviac.Agent.SetIdMask (0xffffffff);
			}

			return true;
		}

		public void finl ()
		{
				behaviac.Workspace.RespondToBreakHandler -= RespondToBreak;
				behaviac.SocketUtils.ShutdownConnection ();
		}
}
