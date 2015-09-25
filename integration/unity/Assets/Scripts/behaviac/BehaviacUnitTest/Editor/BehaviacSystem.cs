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

[AddComponentMenu("BehaviacSystem")]
public class BehaviacSystem
{
    #region singleon
    private static BehaviacSystem _instance;
    public static BehaviacSystem Instance
    {
        get
        {
            if (_instance == null)
            {
                _instance = new BehaviacSystem();
            }

            return _instance;
        }
    }
    #endregion
    
    private bool m_bIsInited = false;
	protected static BehaviacFileManager fileSystem = null;

#if UNITY_EDITOR || UNITY_STANDALONE_WIN
	[DllImport("user32.dll", CharSet=CharSet.Auto)]
	public static extern int MessageBox(int hWnd, String text, String caption, int options);
#endif

	private static void RespondToBreak (string msg, string title)
	{
#if UNITY_EDITOR || UNITY_STANDALONE_WIN
		//if (Application.platform == RuntimePlatform.WindowsEditor) 
		//{
		//	UnityEditor.EditorUtility.DisplayDialog (title, msg, "Ok");
		//} 
		//else if (Application.platform == RuntimePlatform.WindowsPlayer) 
		//{
		//	//Application.pause
		//}
		MessageBox(0, msg, title, 0);
#endif
	}

	public static string exportPath
	{
		get
		{
			string path = "";
			if(Application.platform == RuntimePlatform.WindowsEditor)
			{
				path = Application.dataPath + "/Resources/behaviac/BehaviacData/exported";
			}
			else if(Application.platform == RuntimePlatform.WindowsPlayer)
			{
				path = Application.dataPath + "/Resources/behaviac/BehaviacData/exported";
			}
			else
			{
				path = "Assets/Resources/behaviac/BehaviacData/exported";
			}

			return path;
		}
	}

	public static string workspacePath
	{
		get
		{
			string path = "";
			if(Application.platform == RuntimePlatform.WindowsEditor)
			{
				path = Application.dataPath + "/BehaviorTrees/BTWorkspace";
			}
			else if(Application.platform == RuntimePlatform.WindowsPlayer)
			{
				path = Application.dataPath + "/BehaviorTrees/BTWorkspace";
			}
			else
			{
				behaviac.Debug.LogWarning("only for dev!");
			}
			
			return path;
		}
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

			int formatID = getTestFormat();
			behaviac.Workspace.EFileFormat btFormat = (behaviac.Workspace.EFileFormat)formatID;

			string btExportPath = exportPath;
			behaviac.Workspace.EFileFormat btFileFormat = btFormat;
			behaviac.Workspace.SetWorkspaceSettings (btExportPath, btFileFormat);            
			//register names
			behaviac.Agent.RegisterName<ParTestRegNameAgent>();

			string metaExportPath = workspacePath + "/xmlmeta/UnitTestMeta.xml";
			behaviac.Workspace.ExportMetas(metaExportPath);

            //TODO
            behaviac.IVariable.Register<TNS.ST.PER.WRK.kEmployee>("TNS.ST.PER.WRK.kEmployee");
            behaviac.IVariable.Register<TNS.NE.NAT.eColor>("TNS.NE.NAT.eColor");
            behaviac.IVariable.Register<ParTestAgentBase>("ParTestAgentBase");
            behaviac.IVariable.Register<TNS.ST.PER.WRK.kEmployee>("kEmployee");
            behaviac.IVariable.Register<TNS.NE.NAT.eColor>("eColor");

			behaviac.Debug.Log ("Behaviac meta data export over.");
            
			behaviac.Workspace.RespondToBreakHandler += RespondToBreak;

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

	public int getTestFormat()
	{
		GameObject obj = GameObject.Find("@UnitTest_0");
		if(obj != null)
			return 1;

		obj = GameObject.Find("@UnitTest_1");
		if(obj != null)
			return 2;

		obj = GameObject.Find("@UnitTest_2");
		if(obj != null)
			return 4;

		return -1;
	}
}
