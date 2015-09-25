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
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Text;
using System.Threading;
using System.Windows.Forms;
using System.Xml;
using Behaviac.Design;
using Behaviac.Design.Attributes;
using Behaviac.Design.Data;
using Behaviac.Design.Nodes;
using Behaviac.Design.Properties;

namespace Behaviac.Design
{
    /// <summary>
    /// This is the main window which connects the BehaviorTreeList with each BehaviorTreeView.
    /// </summary>
    internal partial class MainWindow : Form
    {
        private static MainWindow _instance;
        internal static MainWindow Instance
        {
            get { return _instance; }
        }

        // The filename used for storing the layout
        private static string __layoutDesignFile = Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments) + "\\BehaviacDesigner\\config\\layout.xml";
        private static string __layoutDebugFile = Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments) + "\\BehaviacDesigner\\config\\layout_debug.xml";
        private static string __layoutFile = __layoutDesignFile;

        internal WeifenLuo.WinFormsUI.Docking.DockPanel DockPanel
        {
            get { return dockPanel; }
        }

        // For compatibility issues, we store here the controls which were previously directly accessible.
        private BehaviorTreeListDock behaviorTreeListDock = null;
        private BehaviorTreeList behaviorTreeList = null;
        private NodeTreeList nodeTreeList = null;

        internal NodeTreeList NodeTreeList
        {
            get { return nodeTreeList; }
        }

        public RecentMenu RecentFilesMenu;
        public RecentMenu RecentWorkspacesMenu;

        public MainWindow(bool bLoadWks)
        {
            _instance = this;

            Microsoft.Win32.RegistryKey regKey = Microsoft.Win32.Registry.CurrentUser.OpenSubKey("SOFTWARE\\Tencent\\Tag\\Behaviac");
            if (regKey != null)
            {
                regKey.Close();
            }

            //TODO: add a setting in base to hold all these settings
            Node.ColorTheme = (Node.ColorThemes)Settings.Default.ColorTheme;
            Behaviac.Design.Nodes.Action.NoResultTreatAsError = Settings.Default.NoResultTreatAsError;
            NodeViewData.ShowNodeId = Settings.Default.ShowVersionInfo;
            NodeViewData.IsDisplayLengthLimited = Settings.Default.IsDisplayLengthLimited;
            NodeViewData.LimitedDisplayLength = Settings.Default.LimitedDisplayLength;
            Plugin.UseBasicDisplayName = Settings.Default.UseBasicDisplayName;
            MessageQueue.LimitMessageCount = Settings.Default.LimitLogCount;
            MessageQueue.MaxMessageCount = Settings.Default.MaxLogCount;

            //if not chinese, to use as english
            switch ((Language)Settings.Default.Language)
            {
                case Language.Chinese:
                    Thread.CurrentThread.CurrentUICulture = new System.Globalization.CultureInfo("zh-CN");
                    break;

                default:
                   Thread.CurrentThread.CurrentUICulture = new System.Globalization.CultureInfo("en-US");
                   break;
            }

            // Add the designers resource manager to the list of all available resource managers
            Plugin.AddResourceManager(Resources.ResourceManager);

            // Load the config file
            loadConfig();

            // Restore layout
            loadLayout(Plugin.EditMode, __layoutFile, bLoadWks);

            this.Shown += new System.EventHandler(MainWindow_Shown);
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(MainWindow_FormClosing);

            this.dumpToolStripMenuItem.Visible = false;
        }

        private void OnMenuRecentWorkspaces(String filename)
        {
            if (!Plugin.WorkspaceDelegateHandler(filename, false, false))
            {
                this.RecentWorkspacesMenu.RemoveFile(filename);
            }
            else
            {
                int index = this.RecentWorkspacesMenu.FindFilenameNumber(filename);
                this.RecentWorkspacesMenu.SetFirstFile(index);
            }
        }

        private void CreateRecentFilesMenu(string workspace)
        {
            if (this.RecentFilesMenu != null)
            {
                this.RecentFilesMenu.SaveToRegistry();
                this.RecentFilesMenu.RemoveAll();
            }

            if (!string.IsNullOrEmpty(workspace))
            {
                int hashCode = workspace.GetHashCode();
                string key = "SOFTWARE\\Tencent\\Tag\\Behaviac\\MRF\\" + hashCode;
                this.RecentFilesMenu = new RecentMenu(recentFilesMenuItem, new RecentMenu.ClickedHandler(OnMenuRecentFiles), key);
            }
        }

        private void OnMenuRecentFiles(String filename)
        {
            if (this.RecentFilesMenu != null)
            {
                if (UIUtilities.ShowBehaviorTree(filename) == null)
                {
                    this.RecentFilesMenu.RemoveFile(filename);
                }
                else
                {
                    int index = this.RecentFilesMenu.FindFilenameNumber(filename);
                    this.RecentFilesMenu.SetFirstFile(index);
                }
            }
        }

        private System.IO.FileSystemWatcher m_Watcher = new FileSystemWatcher();

        public void EnableFileWatcher(bool bEnable)
        {
            m_Watcher.EnableRaisingEvents = bEnable;
        }

        private void MainWindow_Shown(object sender, EventArgs e)
        {
            this.WindowState = Settings.Default.MainWindowState;

            // Make sure the window is focused
            Focus();

            // Show controls
            if (Settings.Default.ShowControlsOnStartUp)
            {
                ControlsDialog ctrldlg = new ControlsDialog(true);
                ctrldlg.Show();
            }
        }

        private void MainWindow_FormClosing(object sender, FormClosingEventArgs e)
        {
            e.Cancel = (FileManagers.SaveResult.Cancelled == saveLayout(Plugin.EditMode, __layoutFile, true));
        }

        internal void UpdateUIState(EditModes editMode)
        {
            bool enabled = (editMode == EditModes.Design);
            this.saveBehaviorMenuItem.Enabled = enabled;
            this.saveAsBehaviorMenuItem.Enabled = enabled;
            this.saveAllMenuItem.Enabled = enabled;
            this.exportBehaviorMenuItem.Enabled = enabled;
            this.exportAllMenuItem.Enabled = enabled;
            this.dumpToolStripMenuItem.Visible = (editMode == EditModes.Connect);
            this.newWorkspaceMenuItem.Enabled = enabled;
            this.openWorkspaceMenuItem.Enabled = enabled;
            this.editWorkspaceToolStripMenuItem.Enabled = enabled;
            this.timelineMenuItem.Enabled = !enabled;
            this.recentFilesMenuItem.Enabled = enabled;
            this.recentWorkspacesMenuItem.Enabled = enabled;
            this.parMenuItem.Enabled = enabled;
            this.debugMenuButton.Enabled = !enabled;

            //this.deleteSelectedMenuItem.ShortcutKeys = Keys.Delete;
            //this.deleteTreeMenuItem.ShortcutKeys = Keys.Shift | Keys.Delete;

            this.cutSelectedMenuItem.Enabled = enabled;
            this.cutTreeMenuItem.Enabled = enabled;
            this.copySelectedMenuItem.Enabled = enabled;
            this.deleteSelectedMenuItem.Enabled = enabled;
            this.deleteTreeMenuItem.Enabled = enabled;

            switch (editMode)
            {
                case EditModes.Design:
                    this.connectMenuItem.Text = Resources.ConnectServer;
                    this.connectMenuItem.Image = Resources.connect;
                    this.debugMenuItem.Text = Resources.AnalyzeDump;
                    this.connectMenuItem.Enabled = true;
                    this.debugMenuItem.Enabled = true;
                    this.connectMenuItem.Image = Resources.connect;
                    break;

                case EditModes.Connect:
                    this.connectMenuItem.Image = Resources.disconnect;
                    this.connectMenuItem.Text = Resources.DisconnectServer;
                    this.connectMenuItem.Enabled = true;
                    this.debugMenuItem.Enabled = false;
                    break;

                case EditModes.Analyze:
                    this.debugMenuItem.Text = Resources.StopAnalyzing;
                    this.connectMenuItem.Enabled = false;
                    this.debugMenuItem.Enabled = true;
                    break;
            }
        }

        private void loadConfig()
        {
            try
            {
                string filename = "config.xml";
                if (File.Exists(filename))
                {
                    XmlDocument configFile = new XmlDocument();
                    configFile.Load(filename);

                    XmlNode configNode = configFile.ChildNodes[1];
                    foreach (XmlNode xmlNode in configNode.ChildNodes)
                    {
                        if (xmlNode.Name == "FilterNodes")
                        {
                            Plugin.FilterNodes.Clear();
                            foreach (XmlNode node in xmlNode.ChildNodes)
                            {
                                string nodeName = node.Attributes["FullName"].Value;
                                Plugin.FilterNodes.Add(nodeName);
                            }
                        }
                        else if (xmlNode.Name == "Themes")
                        {
                            Node.BackgroundBrushes.Clear();
                            foreach (XmlNode node in xmlNode.ChildNodes)
                            {
                                if (node.Name == "theme" && node.Attributes["Name"].Value == "Modern")
                                {
                                    foreach (XmlNode themeNode in node.ChildNodes)
                                    {
                                        string nodeName = themeNode.Attributes["FullName"].Value;
                                        string brushRGB = themeNode.Attributes["Color"].Value;
                                        string[] colors = brushRGB.Split(',');
                                        if (colors.Length == 3)
                                        {
                                            int r = int.Parse(colors[0].Trim());
                                            int g = int.Parse(colors[1].Trim());
                                            int b = int.Parse(colors[2].Trim());
                                            Node.BackgroundBrushes[nodeName] = new SolidBrush(Color.FromArgb(r, g, b));
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
        }

        public void ResetLayout()
        {
            try
            {
                bool layoutFileExisting = System.IO.File.Exists(__layoutFile);
                if (layoutFileExisting)
                {
                    System.IO.File.Delete(__layoutFile);
                }

                loadLayout(Plugin.EditMode, __layoutFile, true);
            }
            catch
            {
            }
        }

        private void loadLayout(EditModes editMode, string layoutFile, bool bLoadWks)
        {
            preLoadLayout(editMode);

            __layoutFile = layoutFile;

            // Remove all controls and create a new dockPanel.
            this.Controls.Clear();

            InitializeComponent();

            this.RecentWorkspacesMenu = new RecentMenu(this.recentWorkspacesMenuItem, new RecentMenu.ClickedHandler(OnMenuRecentWorkspaces), "SOFTWARE\\Tencent\\Tag\\Behaviac\\MRU");

            this.FormClosed -= this.MainWindow_FormClosed;
            this.FormClosed += this.MainWindow_FormClosed;
            this.KeyDown -= this.MainWindow_KeyDown;
            this.KeyDown += this.MainWindow_KeyDown;

            // Display the file version
            this.Text = "BehaviacDesigner " + this.ProductVersion;

            // Set the stored settings for the window
            this.WindowState = Settings.Default.MainWindowState;
            if (this.WindowState == FormWindowState.Normal)
            {
                this.Size = Settings.Default.MainWindowSize;
                this.Location = Settings.Default.MainWindowLocation;
                this.PerformLayout();
            }

            // If we have no stored layout, generate a default one
            if (behaviorTreeListDock != null)
            {
                nodeTreeList.Dispose();
                nodeTreeList = null;

                behaviorTreeList.Dispose();
                behaviorTreeList = null;

                behaviorTreeListDock.Close();
                behaviorTreeListDock = null;
            }

            bool layoutFileExisting = System.IO.File.Exists(layoutFile);
            if (layoutFileExisting)
            {
                // Add child controls for the dockPanel from the layout file.
                dockPanel.LoadFromXml(layoutFile, new WeifenLuo.WinFormsUI.Docking.DeserializeDockContent(GetContentFromPersistString));

                if (this.behaviorTreeList == null)
                {
                    //the corrupt layout file was deleted
                    layoutFileExisting = false;
                }
            }

            if (!layoutFileExisting)
            {
                BehaviorTreeListDock btlDock = new BehaviorTreeListDock();
                RegisterBehaviorTreeList(btlDock);
                btlDock.Show(dockPanel, WeifenLuo.WinFormsUI.Docking.DockState.DockLeft);

                PropertiesDock dock = new PropertiesDock();
                dock.Show(dockPanel, WeifenLuo.WinFormsUI.Docking.DockState.DockRight);
            }

            if (this.WindowState == FormWindowState.Maximized)
            {
                this.Hide();
                this.WindowState = FormWindowState.Minimized;
                this.WindowState = FormWindowState.Maximized;
                this.Show();

                if (!layoutFileExisting)
                {
                    this.dockPanel.Size = new Size(this.Size.Width - 20, this.Size.Height - 68);
                }
            }

            postLoadLayout(editMode, bLoadWks);

            // Make sure the window is focused
            Focus();
        }

        private FileManagers.SaveResult saveLayout(EditModes editMode, string layoutFile, bool isClosing = false)
        {
            FileManagers.SaveResult saveres = FileManagers.SaveResult.Cancelled;

            if (behaviorTreeList != null)
            {
                // add all the new behaviours to the list of unsaved ones
                List<BehaviorNode> behaviorsToSave = new List<BehaviorNode>();
                behaviorsToSave.AddRange(behaviorTreeList.NewBehaviors);

                // add all loaded and modified behaviours to the unsaved ones
                foreach (BehaviorNode node in behaviorTreeList.LoadedBehaviors)
                {
                    if (node.IsModified)
                        behaviorsToSave.Add(node);
                }

                // ask the user what to do with them
                bool[] result;
                saveres = SaveBehaviors(behaviorsToSave, out result);
            }

            // store GUI related stuff
            if (saveres == FileManagers.SaveResult.Succeeded)
            {
                if (Workspace.Current != null)
                {
                    // Save the debug info.
                    DebugDataPool.Save(Workspace.Current.FileName);
                }

                if (!isClosing)
                    preSaveLayout(editMode);

                // store the layout and ensure the folder exists
                string dir = System.IO.Path.GetDirectoryName(layoutFile);
                if (!System.IO.Directory.Exists(dir))
                    System.IO.Directory.CreateDirectory(dir);

                dockPanel.SaveAsXml(layoutFile);

                // store the application's settings
                if (this.WindowState == FormWindowState.Normal)
                {
                    Settings.Default.MainWindowLocation = Location;
                    Settings.Default.MainWindowSize = Size;
                    Settings.Default.MainWindowState = FormWindowState.Normal;
                }
                else if (this.WindowState == FormWindowState.Maximized)
                {
                    Settings.Default.MainWindowState = FormWindowState.Maximized;
                }

                Settings.Default.Save();
            }

            return saveres;
        }

        /// <summary>
        /// Set the workspace for the editor.
        /// <param name="workspaceName">The current workspace.</param>
        /// <param name="automatic">If ture, the workspace dialog will not be shown.</param>
        /// </summary>
        public bool SetWorkspace(string workSpaceFile, bool bNew)
        {
            bool setWorkspace = false;

            try
            {
                Workspace workspace = null;
                if (bNew)
                {
                    using (EditWorkspaceDialog dialog = new EditWorkspaceDialog())
                    {
                        dialog.ShowDialog();

                        // check if we have a valid result
                        if (dialog.Workspace != null)
                        {
                            Workspace.SaveWorkspaceFile(dialog.Workspace);
                        }

                        workspace = dialog.Workspace;
                    }
                }
                else
                {
                    workspace = Workspace.LoadWorkspaceFile(workSpaceFile);
                }

                if (workspace != null)
                {
                    bool bReopen = false;
                    if (Workspace.Current != null)
                    {
                        BehaviorTreeViewDock.CloseAll();

                        if (Workspace.Current.Name == workspace.Name)
                        {
                            //reopen those opened behaviors if the same workspace is opened again
                            bReopen = true;
                        }
                    }

                    behaviorTreeList.Enabled = false;
                    Workspace.Current = workspace;

                    // Display the file version
                    this.Text = workspace.Name + " - BehaviacDesigner " + this.ProductVersion;

                    behaviorTreeList.UnLoadPlugins(nodeTreeList);
                    behaviorTreeList.LoadPlugins(nodeTreeList, (Plugin.EditMode == EditModes.Design));

                    behaviorTreeList.UnLoadXMLPlugins();
                    setWorkspace = behaviorTreeList.LoadXMLPlugins(workspace.XMLFolder, workspace.XMLPlugins);

                    behaviorTreeList.BehaviorFolder = workspace.Folder;
                    Behavior.BehaviorPath = behaviorTreeList.BehaviorFolder;

                    m_Watcher.Path = behaviorTreeList.BehaviorFolder;
                    m_Watcher.Filter = "*.xml";
                    m_Watcher.IncludeSubdirectories = true;
                    m_Watcher.NotifyFilter = NotifyFilters.LastWrite;
                    //m_Watcher.SynchronizingObject = behaviorTreeList;

                    m_Watcher.Changed -= OnChanged;
                    m_Watcher.Changed += OnChanged;
                    m_Watcher.EnableRaisingEvents = true;

                    postSetWorkspace();

                    // reopen the last opened behaviors.
                    if (setWorkspace && bReopen)
                    {
                        foreach (string bt in BehaviorTreeViewDock.LastOpenedBehaviors)
                        {
                            UIUtilities.ShowBehaviorTree(bt);
                        }
                        BehaviorTreeViewDock.LastOpenedBehaviors.Clear();
                    }

                    // check if we found any exporter
                    this.exportAllMenuItem.Enabled &= (Plugin.Exporters.Count > 0);

                    // check if we found any file managers
                    this.saveAllMenuItem.Enabled &= behaviorTreeList.HasFileManagers();

                    behaviorTreeList.Enabled = true;

                    if (MetaStoreDock.IsVisible())
                    {
                        MetaStoreDock.Inspect();
                    }
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, Resources.WorkspaceError, MessageBoxButtons.OK);
            }

            return setWorkspace;
        }

        delegate BehaviorNode ForceLoadBehavior_t(BehaviorNode behavior, string behaviorFilename);
        static int ms_onchanged_flag = 0;

        private void OnChanged(object sender, FileSystemEventArgs e)
        {
            //don't know why the same file is notified twice
            if ((ms_onchanged_flag & 0x01) == 0)
            {
                string behaviorFilename = e.FullPath;

                BehaviorNode behavior = BehaviorManager.Instance.GetBehavior(behaviorFilename);
                if (behavior != null)
                {
                    BehaviorTreeList behaviorTreeList = BehaviorManager.Instance as BehaviorTreeList;
                    if (behaviorTreeList != null)
                    {
                        ForceLoadBehavior_t d = new ForceLoadBehavior_t(ForceLoadBehavior);
                        object[] parms = new object[] { behavior, behaviorFilename };
                        behaviorTreeList.Invoke(d, parms);

                        Thread.Sleep(100);
                    }
                }

                ms_onchanged_flag++;
            }
            else
            {
                ms_onchanged_flag = 0;
            }
        }

        private static BehaviorNode ForceLoadBehavior(BehaviorNode behavior, string behaviorFilename)
        {
            BehaviorTreeList behaviorTreeList = BehaviorManager.Instance as BehaviorTreeList;
            if (behaviorTreeList != null)
            {
                UndoManager.ClearAll();
                BehaviorTreeViewDock.CloseBehaviorTreeViewDock(behavior);
                behaviorTreeList.UnloadBehavior(behaviorFilename);

                behavior = BehaviorManager.Instance.LoadBehavior(behaviorFilename, true);

                if (behavior is Node)
                {
                    behaviorTreeList.ShowNode(behavior as Node);
                }
                return behavior;
            }

            return null;
        }

        private void RegisterBehaviorTreeList(BehaviorTreeListDock dock)
        {
            behaviorTreeListDock = dock;
            behaviorTreeList = dock.behaviorTreeList;
            nodeTreeList = dock.nodeTreeList;

            RegisterDelegateHandlers();
        }

        private void RegisterDelegateHandlers()
        {
            Plugin.EditModeHandler -= Plugin_EditModeHandler;
            Plugin.EditModeHandler += Plugin_EditModeHandler;

            Plugin.WorkspaceDelegateHandler -= Plugin_WorkspaceDelegateHandler;
            Plugin.WorkspaceDelegateHandler += Plugin_WorkspaceDelegateHandler;

            behaviorTreeList.BehaviorRenamed -= behaviorTreeList_BehaviorRenamed;
            behaviorTreeList.BehaviorRenamed += behaviorTreeList_BehaviorRenamed;
            
            behaviorTreeList.ClearBehaviors -= behaviorTreeList_ClearBehaviors;
            behaviorTreeList.ClearBehaviors += behaviorTreeList_ClearBehaviors;
            
            behaviorTreeList.ShowBehavior -= behaviorTreeList_ShowBehavior;
            behaviorTreeList.ShowBehavior += behaviorTreeList_ShowBehavior;

            behaviorTreeList.TickDelegateHandler -= behaviorTreeList_TickDelegateHandler;
            behaviorTreeList.TickDelegateHandler += behaviorTreeList_TickDelegateHandler;

            MessageHandler.RegisterMessageHandler();
        }

        private void preSaveLayout(EditModes editMode)
        {
            BehaviorTreeViewDock.CloseAll();

            if (editMode == EditModes.Design)
            {
                ConsoleDock.CloseAll();
                ErrorInfoDock.CloseAll();
                TimelineDock.CloseAll();
            }
            else
            {
                ParametersDock.CloseAll();
                ParSettingsDock.CloseAll();
            }
        }

        private void preLoadLayout(EditModes editMode)
        {
            BehaviorTreeViewDock.CloseAll();
            BreakPointsDock.CloseAll();
            ConsoleDock.CloseAll();
            ErrorInfoDock.CloseAll();
            ParametersDock.CloseAll();
            ParSettingsDock.CloseAll();
            PropertiesDock.CloseAll();
            TimelineDock.CloseAll();
        }

        private void postLoadLayout(EditModes editMode, bool bLoadWks)
        {
            if (Workspace.Current != null)
            {
                if (!SetWorkspace(Workspace.Current.FileName, false))
                {
                    this.RecentWorkspacesMenu.RemoveFile(Workspace.Current.FileName);
                }
            }
            else
            {
                if (bLoadWks)
                {
                    string wksFile = this.RecentWorkspacesMenu.GetFileAt(0);

                    if (!SetWorkspace(wksFile, false))
                    {
                        this.RecentWorkspacesMenu.RemoveFile(wksFile);
                    }
                }
            }

            if (Workspace.Current != null)
            {
                int index = MainWindow.Instance.RecentWorkspacesMenu.FindFilenameNumber(Workspace.Current.FileName);
                if (index < 0)
                {
                    MainWindow.Instance.RecentWorkspacesMenu.AddFile(Workspace.Current.FileName);
                    index = MainWindow.Instance.RecentWorkspacesMenu.FindFilenameNumber(Workspace.Current.FileName);
                }

                MainWindow.Instance.RecentWorkspacesMenu.SetFirstFile(index);
            }

            if (editMode != EditModes.Design)
            {
                BreakPointsDock.Inspect();
                ConsoleDock.Inspect();
                ErrorInfoDock.Inspect();
                TimelineDock.Inspect();

                MessageHandler.Init();
            }

            UpdateUIState(editMode);
            behaviorTreeList.UpdateUIState(editMode);
            TimelineDock.UpdateUIState(editMode);

            bool isDesignMode = (editMode == EditModes.Design);
            BehaviorTreeViewDock.ReadOnly = !isDesignMode;
            PropertiesDock.ReadOnly = !isDesignMode;
            ParSettingsDock.ReadOnly = !isDesignMode;
        }

        private void postSetWorkspace()
        {
            // Clear data
            UndoManager.ClearAll();

            // Clear UI
            BehaviorTreeViewDock.ClearHighlights();
            ConsoleDock.Clear();
            ErrorInfoDock.Clear();

            if (Workspace.Current != null)
            {
                // Load the debug info
                DebugDataPool.Load(Workspace.Current.FileName);

                // Create the recent files menu for the current workspace
                CreateRecentFilesMenu(Workspace.Current.FileName);
            }
        }

        private void Plugin_EditModeHandler(EditModes preEditMode, EditModes curEditMode)
        {
            try
            {
                // Clear data
                MessageQueue.Clear();
                UndoManager.ClearAll();

                if (curEditMode == EditModes.Design)
                {
                    saveLayout(preEditMode, __layoutDebugFile);

                    if (this.WindowState != FormWindowState.Normal)
                    {
                        this.Hide();
                        this.WindowState = FormWindowState.Normal;
                    }

                    loadLayout(curEditMode, __layoutDesignFile, true);
                }
                else
                {
                    saveLayout(preEditMode, __layoutDesignFile);

                    if (this.WindowState != FormWindowState.Normal)
                    {
                        this.Hide();
                        this.WindowState = FormWindowState.Normal;
                    }

                    loadLayout(curEditMode, __layoutDebugFile, true);

                    // Create the log related folders if not existed
                    string logFileDir = Utilities.GetLogFileDirectory();
                    if (!Directory.Exists(logFileDir))
                    {
                        Directory.CreateDirectory(logFileDir);
                    }

                    if (curEditMode == EditModes.Connect)
                    {
                        // Clear the log related folders
                        Utilities.ClearDirectory(logFileDir);
                    }
                }
            }
            catch
            {
            }

            Update();

            this.Show();
        }

        private bool Plugin_WorkspaceDelegateHandler(string workspacePath, bool bNew, bool bPromptError)
        {
            bool bOk = true;
            workspacePath = workspacePath.Replace('/', '\\');
            if (Workspace.Current == null || workspacePath != Workspace.Current.FileName)
            {
                string info = string.Empty;
                string previousWorkspace = "None";
                if (Workspace.Current != null)
                {
                    previousWorkspace = Workspace.Current.FileName;
                }

                if (this.SetWorkspace(workspacePath, bNew))
                {
                    info = string.Format(Resources.WorkspaceChangedInfo, previousWorkspace, Workspace.Current.Name);
                }
                else
                {
                    bOk = false;
                    if (bPromptError)
                    {
                        info = string.Format(Resources.WorkspaceWarningInfo, previousWorkspace, workspacePath);
                        MessageBox.Show(info, Resources.IncompatibleWorkspace, MessageBoxButtons.OK);
                    }
                }
            }

            this.nodeTreeList.SetNodeList();

            return bOk;
        }

        private void behaviorTreeList_TickDelegateHandler()
        {
            MessageQueue.Tick();

            TimelineDock.Tick();
        }

        private void control_ClickEvent(NodeViewData node)
        {
            if (node == null)
                return;

            // if there is no subitem selected, use the properties of the node
            if (node.SelectedSubItem == null || node.SelectedSubItem.SelectableObject == null)
            {
                PropertiesDock.InspectObject(node.RootBehavior, node.Node);
            }
            // publish the properties of the subitem's selection object
            else
            {
                PropertiesDock.InspectObject(node.RootBehavior, node.SelectedSubItem.SelectableObject);
            }
        }

        private void AsyncUpdateProperties()
        {
            this.Invoke((System.Action<NodeViewData>)delegate
            {
                if (_clickedNVD == null)
                {
                    PropertiesDock.InspectObject(null, null);
                }
                else
                {
                    PropertiesDock.InspectObject(_clickedNVD.RootBehavior, _clickedNVD.Node);
                }
            }, _clickedNVD);
        }

        private NodeViewData _clickedNVD = null;

        private void control_ClickNode(NodeViewData nvd)
        {
            _clickedNVD = nvd;

            Thread backgroundThread = new Thread(AsyncUpdateProperties);
            backgroundThread.SetApartmentState(ApartmentState.STA);
            backgroundThread.Start();
            while (backgroundThread.IsAlive)
            {
                Application.DoEvents();
            }

            _clickedNVD = null;
        }

        /// <summary>
        /// Handles when a behaviour is supposed to be presented to the user.
        /// </summary>
        /// <param name="node">The behaviour which will be presented to the user.</param>
        private BehaviorTreeViewDock behaviorTreeList_ShowBehavior(BehaviorNode node)
        {
            // check if there is a tab for the behaviour
            BehaviorTreeViewDock dock = BehaviorTreeViewDock.GetBehaviorTreeViewDock(node);
            BehaviorTreeView control = (dock == null) ? null : dock.BehaviorTreeView;

            if (control == null)
            {
                control = new BehaviorTreeView();
                control.Dock = DockStyle.Fill;
                control.RootNode = node;
                control.BehaviorTreeList = behaviorTreeList;

                control.ClickNode += new BehaviorTreeView.ClickNodeEventDelegate(control_ClickNode);
                control.ClickEvent += new BehaviorTreeView.ClickEventEventDelegate(control_ClickEvent);

                dock = new BehaviorTreeViewDock();
                dock.Text = ((Node)node).Label;
                dock.TabText = ((Node)node).Label;
                dock.BehaviorTreeView = control;
                dock.Activated += new EventHandler(dock_Activated);
                dock.FormClosed += new FormClosedEventHandler(dock_FormClosed);
                dock.Show(dockPanel, WeifenLuo.WinFormsUI.Docking.DockState.Document);

                dock.ToolTipText = FileManagers.FileManager.GetRelativePath(node.Filename);
            }

            dock.Focus();
            dock.MakeFocused();

            return dock;
        }

        private BehaviorTreeViewDock lastActivatedDock = null;
        private void dock_Activated(object sender, EventArgs e)
        {
            if (ParSettingsDock.IsVisible())
            {
                BehaviorTreeViewDock dock = sender as BehaviorTreeViewDock;
                if (lastActivatedDock != dock)
                {
                    lastActivatedDock = dock;
                    ParSettingsDock.Inspect((Node)dock.BehaviorTreeView.RootNode);
                }

                dock.BehaviorTreeView.Focus();
            }

            if (MetaStoreDock.IsVisible())
            {
                MetaStoreDock.Inspect();
            }
        }

        private void dock_FormClosed(object sender, FormClosedEventArgs e)
        {
            if (ParSettingsDock.IsVisible())
                ParSettingsDock.Inspect(null);
        }

        /// <summary>
        /// Handles when a behaviour was renamed.
        /// </summary>
        /// <param name="node">The behaviour which was renamed.</param>
        private void behaviorTreeList_BehaviorRenamed(BehaviorNode node)
        {
            ((Node)node).DoWasModified();

            BehaviorTreeViewDock dock = BehaviorTreeViewDock.GetBehaviorTreeViewDock(node);
            if (dock != null)
            {
                dock.Text = dock.TabText = ((Node)node).Label;
            }

            ParSettingsDock.Inspect((Node)node);
        }

        /// <summary>
        /// Handles when behaviours must be cleared.
        /// </summary>
        /// <param name="nodes">The nodes which must be saved and closed.</param>
        /// <param name="result">Returns which behaviours could be saved or discarded.</param>
        /// <param name="error">Is true if there was an error and result contains any false.</param>
        private void behaviorTreeList_ClearBehaviors(bool save, List<BehaviorNode> nodes, out bool[] result, out bool error)
        {
            if (save)
            {
                // try to save the behaviours
                FileManagers.SaveResult saveResult = SaveBehaviors(nodes, out result);

                // update the error value
                error = (saveResult != FileManagers.SaveResult.Succeeded);
            }
            else
            {
                result = new bool[nodes.Count];
                for (int i = 0; i < nodes.Count; ++i)
                {
                    result[i] = true;
                }

                error = false;
            }

            // for each behaviour which was...
            for (int i = 0; i < nodes.Count; ++i)
            {
                // successfully saved
                if (result[i])
                {
                    BehaviorTreeViewDock dock = BehaviorTreeViewDock.GetBehaviorTreeViewDock(nodes[i]);
                    if (dock != null)
                    {
                        dock.SaveBehaviorWhenClosing = save;
                        dock.Close();
                    }
                }
            }
        }

        /// <summary>
        /// Tries to save all of the behaviours in the list.
        /// </summary>
        /// <param name="behaviors">The list of the behaviours you want to save.</param>
        /// <param name="result">Holds if a behaviour could be saved or not.</param>
        /// <returns>Returns Failed if a bahevaiour could not be saved. Returns Cancelled if the user cancelled the process.</returns>
        public FileManagers.SaveResult SaveBehaviors(List<BehaviorNode> behaviors, out bool[] result)
        {
            // create anew dialogue
            using (MainWindowCloseDialog dialog = new MainWindowCloseDialog())
            {
                // create the results
                result = new bool[behaviors.Count];

                // check if there is any unsaved behaviour and update the result accordingly
                int unsavedBehaviors = 0;
                for (int i = 0; i < behaviors.Count; ++i)
                {
                    if (behaviors[i].IsModified)
                    {
                        unsavedBehaviors++;

                        // add the behaviour to the dialogue
                        dialog.AddUnsavedBehavior(behaviors[i]);

                        result[i] = false;
                    }
                    else
                    {
                        result[i] = true;
                    }
                }

                // if there is no unsaved behaviour, we are done
                if (unsavedBehaviors == 0)
                    return FileManagers.SaveResult.Succeeded;
                else if (unsavedBehaviors == 1)
                    dialog.ReadOnly = true;

                // show the dialogue
                DialogResult dialogResult = dialog.ShowDialog();

                // check if the user cancelled the process
                if (dialogResult == DialogResult.Cancel)
                {
                    for (int i = 0; i < behaviors.Count; ++i)
                    {
                        result[i] = true;
                    }

                    return FileManagers.SaveResult.Cancelled;
                }
                // the user decided to discard all the unsaved changes
                else if (dialogResult == DialogResult.No)
                {
                    for (int i = 0; i < behaviors.Count; ++i)
                    {
                        if (!result[i])
                        {
                            UndoManager.Reset(behaviors[i].Filename);
                            result[i] = true;
                        }
                    }

                    return FileManagers.SaveResult.Succeeded;
                }
                // the user decided to save some of the unsaved changes
                else if (dialogResult == DialogResult.Yes)
                {
                    // check for all the behaviours
                    for (int i = 0; i < behaviors.Count; ++i)
                    {
                        // check if the user wants to save the behaviour
                        if (dialog.IsSelected(behaviors[i]))
                        {
                            FileManagers.SaveResult saveResult = FileManagers.SaveResult.Failed;

                            // try to save the behaviour
                            try
                            {
                                saveResult = behaviorTreeList.SaveBehavior(behaviors[i], false);
                            }
                            catch
                            {
                                saveResult = FileManagers.SaveResult.Failed;
                            }

                            // if there was an exception or the user aborted the save
                            if (saveResult != FileManagers.SaveResult.Succeeded)
                                return saveResult;

                            // everything is fine
                            result[i] = true;
                        }
                        else
                        {
                            // this behaviour will be discarded. No error
                            result[i] = true;
                        }
                    }

                    return FileManagers.SaveResult.Succeeded;
                }
            }

            throw new Exception("undealt dialog return");
        }

        private void SaveAll(bool force)
        {
            if (force)
                this.behaviorTreeList.ForceSaveAll();
            else
                this.behaviorTreeList.SaveAll();
        }

        /// <summary>
        /// Used to store layout.
        /// </summary>
        private WeifenLuo.WinFormsUI.Docking.IDockContent GetContentFromPersistString(string persistString)
        {
            // we skip the behaviour views for now
            if (persistString == "Behaviac.Design.BehaviorTreeViewDock" ||
                persistString == "Behaviac.Design.ParametersDock")
                return null;

            // we only create the generic property dock
            if (PropertiesDock.Count > 0 && persistString == "Behaviac.Design.PropertiesDock")
                return null;

            // find the type of the dock which is supposed to be created
            Type type = Type.GetType(persistString);
            if (type == null)
                type = Plugin.GetType(persistString);

            // when we have no type we skip the window
            if (type == null)
                return null;

            // create new window
            WeifenLuo.WinFormsUI.Docking.IDockContent dockContent = (WeifenLuo.WinFormsUI.Docking.IDockContent)type.InvokeMember(string.Empty, System.Reflection.BindingFlags.CreateInstance, null, null, new object[0]);

            // register the behaviour tree list when created
            BehaviorTreeListDock treeListDock = dockContent as BehaviorTreeListDock;
            if (treeListDock != null)
            {
                RegisterBehaviorTreeList(treeListDock);
            }

            return dockContent;
        }

        private void MainWindow_FormClosed(object sender, FormClosedEventArgs e)
        {
            if (Plugin.EditMode == EditModes.Connect)
                Network.NetworkManager.Instance.Disconnect();

            if (behaviorTreeList != null)
            {
                if (Workspace.Current != null)
                {
                    this.RecentWorkspacesMenu.AddFile(Workspace.Current.FileName);

                    int index = this.RecentWorkspacesMenu.FindFilenameNumber(Workspace.Current.FileName);
                    this.RecentWorkspacesMenu.SetFirstFile(index);
                }

                this.RecentWorkspacesMenu.SaveToRegistry();

                if (this.RecentFilesMenu != null)
                {
                    this.RecentFilesMenu.SaveToRegistry();
                }
            }
        }

        /// <summary>
        /// Used to do undo or redo operation.
        /// </summary>
        /// <param name="undo">If true, do undo operateion, else do redo operation.</param>
        public void Undo(bool undo)
        {
            if (Plugin.EditMode == EditModes.Design && BehaviorTreeViewDock.LastFocused != null)
            {
                BehaviorTreeView behaviorTreeView = BehaviorTreeViewDock.LastFocused.BehaviorTreeView;
                if (behaviorTreeView != null && behaviorTreeView.RootNode != null)
                {
                    string filename = behaviorTreeView.RootNode.Filename;
                    if (undo)
                        UndoManager.Undo(filename);
                    else
                        UndoManager.Redo(filename);
                }
            }
        }

        public void SaveBehavior(bool saveAs)
        {
            if (Plugin.EditMode == EditModes.Design && BehaviorTreeViewDock.LastFocused != null)
            {
                BehaviorTreeView behaviorTreeView = BehaviorTreeViewDock.LastFocused.BehaviorTreeView;
                if (behaviorTreeView != null && behaviorTreeView.RootNode != null)
                    behaviorTreeView.Save(saveAs);
            }
        }

        public bool SaveBehavior(BehaviorNode behavior, bool saveAs = false)
        {
            if (behavior != null && behaviorTreeList != null)
            {
                try
                {
                    FileManagers.SaveResult result = behaviorTreeList.SaveBehavior(behavior, saveAs, false);

                    return result == FileManagers.SaveResult.Succeeded;
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message, Resources.SaveError, MessageBoxButtons.OK);
                }
            }

            return false;
        }

        public void ExportBehavior(bool allBehaviors, string format = "")
        {
            if (Plugin.EditMode == EditModes.Design)
            {
                if (allBehaviors)
                {
                    if (behaviorTreeList != null)
                    {
                        behaviorTreeList.ExportBehavior(null, format);
                    }
                }
                else if (BehaviorTreeViewDock.LastFocused != null)
                {
                    BehaviorTreeView behaviorTreeView = BehaviorTreeViewDock.LastFocused.BehaviorTreeView;
                    if (behaviorTreeView != null && behaviorTreeView.RootNode != null)
                    {
                        // Only non-prefab files can be exported.
                        if (behaviorTreeList == null || !isPrefabFile(behaviorTreeView.RootNode.Filename))
                            behaviorTreeView.Export();
                    }
                }
            }
        }

        public void CloseBehavior(bool allBehaviors)
        {
            if (allBehaviors)
            {
                BehaviorTreeViewDock.CloseAll();
            }
            else if (BehaviorTreeViewDock.LastFocused != null)
            {
                BehaviorTreeViewDock.LastFocused.Close();
            }
        }

        private void MainWindow_KeyDown(object sender, KeyEventArgs e)
        {
            switch (e.KeyCode)
            {
                case (Keys.W):
                    if (e.Control)
                    {
                        CloseBehavior(e.Shift);

                        e.Handled = true;
                    }
                    break;

                case (Keys.T):
                    if (e.Control)
                    {
                        ExportBehavior(e.Shift);
                        e.Handled = true;
                    }
                    break;

                case (Keys.O):
                    if (e.Alt && e.Shift)
                    {
                        FindFileDialog.Inspect();
                        e.Handled = true;
                    }
                    break;

                case (Keys.F):
                    if (e.Control)
                    {
                        FindDock.Inspect(e.Shift);
                        e.Handled = true;
                    }
                    break;

                case (Keys.R):
                    if (e.Control)
                    {
                        if (Workspace.Current != null)
                        {
                            MainWindow.Instance.SetWorkspace(Workspace.Current.FileName, false);
                            e.Handled = true;
                        }
                    }
                    break;

                case (Keys.L):
                    if (e.Control)
                    {
                        if (behaviorTreeList != null)
                        {
                            behaviorTreeList.HandleConnect();
                            e.Handled = true;
                        }
                    }
                    break;

                case (Keys.N):
                    if (e.Control)
                    {
                        if (behaviorTreeList != null)
                        {
                            behaviorTreeList.NewBehavior();
                            e.Handled = true;
                        }
                    }
                    break;

                case (Keys.S):
                    if (e.Control)
                    {
                        if (e.Shift)
                            SaveAll(e.Alt);
                        else
                            SaveBehavior(false);

                        e.Handled = true;
                    }
                    break;

                case (Keys.Y):
                    if (e.Control)
                    {
                        Undo(false);
                        e.Handled = true;
                    }
                    break;

                case (Keys.Z):
                    if (e.Control)
                    {
                        Undo(true);
                        e.Handled = true;
                    }
                    break;

                case (Keys.F5):
                    if (Plugin.EditMode == EditModes.Connect)
                    {
                        TimelineDock.Continue();
                        e.Handled = true;
                    }
                    break;
            }
        }

        private BehaviorTreeView getFocusedView()
        {
            return (BehaviorTreeViewDock.LastFocused != null) ? BehaviorTreeViewDock.LastFocused.BehaviorTreeView : null;
        }

        private bool isPrefabFile(string filename)
        {
            if (!string.IsNullOrEmpty(filename))
            {
                string prefabFolder = behaviorTreeList.GetPrefabFolder();
                if (!string.IsNullOrEmpty(prefabFolder) && filename.StartsWith(prefabFolder))
                    return true;
            }

            return false;
        }

        private void editMenuButton_DropDownOpening(object sender, EventArgs e)
        {
            this.undoMenuItem.Enabled = false;
            this.redoMenuItem.Enabled = false;

            this.cutSelectedMenuItem.Enabled = false;
            this.cutTreeMenuItem.Enabled = false;
            this.copySelectedMenuItem.Enabled = false;
            this.deleteSelectedMenuItem.Enabled = false;
            this.deleteTreeMenuItem.Enabled = false;

            if (Plugin.EditMode == EditModes.Design)
            {
                BehaviorTreeView behaviorTreeView = getFocusedView();
                if (behaviorTreeView != null && behaviorTreeView.RootNode != null)
                {
                    string filename = behaviorTreeView.RootNode.Filename;
                    this.undoMenuItem.Enabled = UndoManager.CanUndo(filename);
                    this.redoMenuItem.Enabled = UndoManager.CanRedo(filename);

                    this.cutSelectedMenuItem.Enabled = behaviorTreeView.SelectedNodeCanBeCut();
                    this.cutTreeMenuItem.Enabled = behaviorTreeView.SelectedTreeCanBeCut();
                    this.copySelectedMenuItem.Enabled = (behaviorTreeView.SelectedNode != null);
                    this.deleteSelectedMenuItem.Enabled = behaviorTreeView.SelectedNodeCanBeDeleted();
                    this.deleteTreeMenuItem.Enabled = behaviorTreeView.SelectedTreeCanBeDeleted();
                }
            }
        }

        private void fileMenuButton_DropDownOpening(object sender, EventArgs e)
        {
            bool enabled = (Plugin.EditMode == EditModes.Design && BehaviorTreeViewDock.LastFocused != null);

            saveBehaviorMenuItem.Enabled = enabled;
            saveAsBehaviorMenuItem.Enabled = enabled;
            exportBehaviorMenuItem.Enabled = enabled;
            closeBehaviorMenuItem.Enabled = (BehaviorTreeViewDock.LastFocused != null);

            saveBehaviorMenuItem.Text = Resources.Menu_SaveBehavior_Default;
            saveAsBehaviorMenuItem.Text = Resources.Menu_SaveBehaviorAs_Default;
            exportBehaviorMenuItem.Text = Resources.Menu_ExportBehavior_Default;
            closeBehaviorMenuItem.Text = Resources.Menu_CloseBehavior_Default;

            BehaviorTreeView behaviorTreeView = getFocusedView();
            if (behaviorTreeView != null && behaviorTreeView.RootNode != null)
            {
                Node root = (Node)behaviorTreeView.RootNode;
                exportBehaviorMenuItem.Enabled &= !isPrefabFile(behaviorTreeView.RootNode.Filename);

                saveBehaviorMenuItem.Text = string.Format(Resources.Menu_SaveBehavior, root.Label);
                saveAsBehaviorMenuItem.Text = string.Format(Resources.Menu_SaveBehaviorAs, root.Label);
                exportBehaviorMenuItem.Text = string.Format(Resources.Menu_ExportBehavior, root.Label);
                closeBehaviorMenuItem.Text = string.Format(Resources.Menu_CloseBehavior, root.Label);
            }
        }

        private void newWorkspaceMenuItem_Click(object sender, EventArgs e)
        {
            if (Plugin.WorkspaceDelegateHandler != null)
            {
                if (Plugin.WorkspaceDelegateHandler(string.Empty, true, false))
                {
                    MainWindow.Instance.RecentWorkspacesMenu.AddFile(Workspace.Current.FileName);

                    int index = MainWindow.Instance.RecentWorkspacesMenu.FindFilenameNumber(Workspace.Current.FileName);
                    MainWindow.Instance.RecentWorkspacesMenu.SetFirstFile(index);
                }
            }
        }

        private void openWorkspaceMenuItem_Click(object sender, EventArgs e)
        {
            behaviorTreeList.OpenWorkspace();
        }

        private void editWorkspaceToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Workspace ws = Workspace.Current;

            using (EditWorkspaceDialog dialog = new EditWorkspaceDialog())
            {
                dialog.EditWorkspace(ws);
                dialog.ShowDialog();

                if (dialog.Workspace != null)
                {
                    Workspace.SaveWorkspaceFile(dialog.Workspace);
                    MainWindow.Instance.SetWorkspace(dialog.Workspace.FileName, false);
                }
            }
        }

        private void reloadWorkspaceMenuItem_Click(object sender, EventArgs e)
        {
            if (Workspace.Current != null)
            {
                MainWindow.Instance.SetWorkspace(Workspace.Current.FileName, false);
            }
        }

        private void connectMenuItem_Click(object sender, EventArgs e)
        {
            behaviorTreeList.HandleConnect();
        }

        private void debugMenuItem_Click(object sender, EventArgs e)
        {
            behaviorTreeList.LoadDump();
        }

        private void dumpToolStripMenuItem_Click(object sender, EventArgs e)
        {
            behaviorTreeList.DumpLogFile();
        }

        private void newBehaviorMenuItem_Click(object sender, EventArgs e)
        {
            behaviorTreeList.NewBehavior();
        }

        private void createGroupMenuItem_Click(object sender, EventArgs e)
        {
            behaviorTreeList.CreateGroup();
        }

        private void saveBehaviorMenuItem_Click(object sender, EventArgs e)
        {
            this.SaveBehavior(false);
        }

        private void saveAsBehaviorMenuItem_Click(object sender, EventArgs e)
        {
            this.SaveBehavior(true);
        }

        private void exportBehaviorMenuItem_Click(object sender, EventArgs e)
        {
            this.ExportBehavior(false);
        }

        private void closeBehaviorMenuItem_Click(object sender, EventArgs e)
        {
            this.CloseBehavior(false);
        }

        private void saveAllMenuItem_Click(object sender, EventArgs e)
        {
            behaviorTreeList.SaveAll();
        }

        private void exportAllMenuItem_Click(object sender, EventArgs e)
        {
            behaviorTreeList.ExportBehavior(null);
        }

        private void closeAllMenuItem_Click(object sender, EventArgs e)
        {
            this.CloseBehavior(true);
        }

        private void settingsMenuItem_Click(object sender, EventArgs e)
        {
            using (SettingsDialog d = new SettingsDialog())
            {
                d.ShowDialog();
            }
        }

        private void exitMenuItem_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void undoMenuItem_Click(object sender, EventArgs e)
        {
            this.Undo(true);
        }

        private void redoMenuItem_Click(object sender, EventArgs e)
        {
            this.Undo(false);
        }

        private void cutSelectedMenuItem_Click(object sender, EventArgs e)
        {
            BehaviorTreeView behaviorTreeView = getFocusedView();
            if (behaviorTreeView != null)
                behaviorTreeView.CutSelectedNode();
        }

        private void cutTreeMenuItem_Click(object sender, EventArgs e)
        {
            BehaviorTreeView behaviorTreeView = getFocusedView();
            if (behaviorTreeView != null)
                behaviorTreeView.CutSelectedNode(true);
        }

        private void copySelectedMenuItem_Click(object sender, EventArgs e)
        {
            BehaviorTreeView behaviorTreeView = getFocusedView();
            if (behaviorTreeView != null)
                behaviorTreeView.CopySelectedNode();
        }

        private void deleteSelectedMenuItem_Click(object sender, EventArgs e)
        {
            BehaviorTreeView behaviorTreeView = getFocusedView();
            if (behaviorTreeView != null)
                behaviorTreeView.DeleteSelectedNode();
        }

        private void deleteTreeMenuItem_Click(object sender, EventArgs e)
        {
            BehaviorTreeView behaviorTreeView = getFocusedView();
            if (behaviorTreeView != null)
                behaviorTreeView.DeleteSelectedNode(true);
        }

        private void fitToViewMenuItem_Click(object sender, EventArgs e)
        {
            BehaviorTreeView behaviorTreeView = getFocusedView();
            if (behaviorTreeView != null && behaviorTreeView.RootNodeView != null)
                behaviorTreeView.CenterNode(behaviorTreeView.RootNodeView);
        }

        private void findFileMenuItem_Click(object sender, EventArgs e)
        {
            FindFileDialog.Inspect();
        }

        private void checkErrorMenuItem_Click(object sender, EventArgs e)
        {
            BehaviorTreeView behaviorTreeView = getFocusedView();
            if (behaviorTreeView != null && behaviorTreeView.RootNode != null)
                behaviorTreeView.CheckErrors(behaviorTreeView.RootNode, false);
        }

        private void saveImageMenuItem_Click(object sender, EventArgs e)
        {
            BehaviorTreeView behaviorTreeView = getFocusedView();
            if (behaviorTreeView != null)
                behaviorTreeView.SaveImage();
        }

        private void findMenuItem_Click(object sender, EventArgs e)
        {
            FindDock.Inspect(false);
        }

        private void findAllMenuItem_Click(object sender, EventArgs e)
        {
            FindDock.Inspect(true);
        }

        private void metaStoreMenuItem_Click(object sender, EventArgs e)
        {
            MetaStoreDock.Inspect();
        }

        private void propertyMenuItem_Click(object sender, EventArgs e)
        {
            BehaviorTreeView behaviorTreeView = getFocusedView();
            if (behaviorTreeView != null && behaviorTreeView.SelectedNode != null)
                PropertiesDock.CreateFloatDock(behaviorTreeView.RootNode, behaviorTreeView.SelectedNode.Node);
        }

        private void parMenuItem_Click(object sender, EventArgs e)
        {
            BehaviorTreeView behaviorTreeView = getFocusedView();
            if (behaviorTreeView != null && behaviorTreeView.RootNodeView != null)
                ParSettingsDock.Inspect(behaviorTreeView.RootNodeView.Node);
        }

        private void breakPointMenuItem_Click(object sender, EventArgs e)
        {
            BreakPointsDock.Inspect();
        }

        private void logConsoleMenuItem_Click(object sender, EventArgs e)
        {
            ConsoleDock.Inspect();
        }

        private void errorInfoMenuItem_Click(object sender, EventArgs e)
        {
            ErrorInfoDock.Inspect();
        }

        private void timelineMenuItem_Click(object sender, EventArgs e)
        {
            TimelineDock.Inspect();
        }

        private void instanceParMenuItem_Click(object sender, EventArgs e)
        {
            if (Plugin.EditMode == EditModes.Design || MainWindow.Instance.NodeTreeList == null)
                return;

            MainWindow.Instance.NodeTreeList.ShowInstancePar();
        }

        private void instancePropertyMenuItem_Click(object sender, EventArgs e)
        {
            if (Plugin.EditMode == EditModes.Design || MainWindow.Instance.NodeTreeList == null)
                return;

            MainWindow.Instance.NodeTreeList.ShowInstanceProperty();
        }

        private string getAbsolutePath(string relativePath)
        {
            string appDir = Path.GetDirectoryName(Application.ExecutablePath);
            string filename = Path.Combine(appDir, relativePath);

            return Path.GetFullPath(filename);
        }

        private void overviewMenuItem_Click(object sender, EventArgs e)
        {
            string overviewStr = getAbsolutePath("../../../docs/Behaviac Overview.pdf");
            if (File.Exists(overviewStr))
                System.Diagnostics.Process.Start(overviewStr);
        }

        private void tutorialMenuItem_Click(object sender, EventArgs e)
        {
            string tutorialStr = getAbsolutePath("../../../docs/Behaviac Tutorial.pdf");
            if (File.Exists(tutorialStr))
                System.Diagnostics.Process.Start(tutorialStr);
        }

        private void insideBehaviacToolStripMenuItem_Click(object sender, EventArgs e)
        {
            string tutorialStr = getAbsolutePath("../../../docs/Inside behaviac.pdf");
            if (File.Exists(tutorialStr))
                System.Diagnostics.Process.Start(tutorialStr);
        }

        private void performanceToolStripMenuItem_Click(object sender, EventArgs e)
        {
            string tutorialStr = getAbsolutePath("../../../docs/Behaviac Performance.pdf");
            if (File.Exists(tutorialStr))
                System.Diagnostics.Process.Start(tutorialStr);
        }

        private void controlsMenuItem_Click(object sender, EventArgs e)
        {
            ControlsDialog dlg = new ControlsDialog(false);
            dlg.Owner = MainWindow.Instance;
            dlg.Show();
        }

        private void reportAProblemMenuItem_Click(object sender, EventArgs e)
        {
        }

        private void getLatestVersionMenuItem_Click(object sender, EventArgs e)
        {
            behaviorTreeList.CheckVersionSync();
        }

        private void aboutMenuItem_Click(object sender, EventArgs e)
        {
            using (AboutBox box = new AboutBox())
            {
                box.ShowDialog();
            }
        }
    }
}
