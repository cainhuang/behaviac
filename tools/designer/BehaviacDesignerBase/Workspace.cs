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
using System.Text;
using System.IO;
using System.Windows.Forms;
using System.Xml;
using Behaviac.Design.Properties;

namespace Behaviac.Design
{
	/// <summary>
	/// This class represents a workspace available to the user.
	/// </summary>
	public sealed class Workspace
	{
        public delegate void WorkspaceChangedDelegate();
        public static WorkspaceChangedDelegate WorkspaceChangedHandler;

        private static Workspace _current = null;
        public static Workspace Current
        {
            get { return _current; }
            set
            {
                if (_current != value)
                {
                    _current = value;

                    if (WorkspaceChangedHandler != null)
                    {
                        WorkspaceChangedHandler();
                    }
                }
            }
        }

        public static bool DebugWorkspace = true;

        private string _name;

		/// <summary>
		/// The name of the workspace.
		/// </summary>
		public string Name
		{
			get { return _name; }
		}

        private string _file_name;
        public string FileName
        {
            get
            {
                //return Path.Combine(_folder, _name) + ".xml";
                return _file_name;
            }
        }

		private string _folder;

		/// <summary>
		/// The folder the behaviors are saved in.
		/// </summary>
		public string Folder
		{
			get { return _folder; }
		}

        public string RelativeFolder
        {
            get { return MakeRelativePath(_folder); }
        }

		private string _defaultExportFolder;

		/// <summary>
		/// The default folder behaviours are exported to.
		/// </summary>
		public string DefaultExportFolder
		{
			get { return _defaultExportFolder; }
		}

        public string RelativeDefaultExportFolder
        {
            get { return MakeRelativePath(_defaultExportFolder); }
        }

        private string _xmlFolder;

        /// <summary>
        /// The folder the XML plugins are saved in.
        /// </summary>
        public string XMLFolder
        {
            get { return _xmlFolder; }
            set { _xmlFolder = value; }
        }

        public string RelativeXMLFolder
        {
            get { return MakeRelativePath(_xmlFolder); }
        }

        private List<string> _xmlPlugins = new List<string>();

        /// <summary>
        /// The list of XML plugins which will be loaded for the workspace.
        /// </summary>
        public IList<string> XMLPlugins
        {
            get { return _xmlPlugins.AsReadOnly(); }
        }

        /// <summary>
        /// Adds a xml plugin which will be loaded to the workspace.
        /// </summary>
        /// <param name="filename">The filename of the xml plugin which will be loaded.</param>
        public void AddXMLPlugin(string filename)
        {
            if (!_xmlPlugins.Contains(filename))
                _xmlPlugins.Add(filename);
        }

        public class ExportData
        {
            private bool _isExported = true;
            public bool IsExported
            {
                get { return _isExported; }
                set { _isExported = value; }
            }

            private string _exportFilename = "";
            public string ExportFilename
            {
                get { return string.IsNullOrEmpty(_exportFilename) ? "generated_behaviors" : _exportFilename; }
                set { _exportFilename = value; }
            }

            /// <summary>
            /// ExportFolder should be saved as relative path, but used as absoluted path.
            /// </summary>
            private string _exportFolder = "";
            public string ExportFolder
            {
                get { return _exportFolder; }
                set { _exportFolder = value; }
            }

            /// <summary>
            /// ExportIncludedFilenames should be saved and used as relative path.
            /// </summary>
            private List<string> _exportIncludedFilenames = new List<string>();
            public List<string> ExportIncludedFilenames
            {
                get { return _exportIncludedFilenames; }
            }
        }

        private Dictionary<string, ExportData> _exportDatas = new Dictionary<string, ExportData>();
        public Dictionary<string, ExportData> ExportDatas
        {
            get { return _exportDatas; }
        }

        public void SetExportInfo(string format, bool isExported, string filename = null, string folder = null, List<string> includedFilenames = null)
        {
            if (!_exportDatas.ContainsKey(format))
            {
                _exportDatas[format] = new ExportData();
            }

            ExportData data = _exportDatas[format];
            data.IsExported = isExported;
            if (filename != null)
            {
                data.ExportFilename = filename;
            }
            if (folder != null)
            {
                data.ExportFolder = folder;
            }
            if (includedFilenames != null)
            {
                data.ExportIncludedFilenames.Clear();
                data.ExportIncludedFilenames.AddRange(includedFilenames);
            }
        }

        public bool ShouldBeExported(string format)
        {
            if (_exportDatas.ContainsKey(format))
            {
                ExportData data = _exportDatas[format];
                return data.IsExported;
            }

            return true;
        }

        public string GetExportFilename(string format)
        {
            Debug.Check(!string.IsNullOrEmpty(format));

            if (_exportDatas.ContainsKey(format))
            {
                ExportData data = _exportDatas[format];
                if (string.IsNullOrEmpty(Path.GetExtension(data.ExportFilename)))
                {
                    data.ExportFilename = Path.ChangeExtension(data.ExportFilename, format);
                }
                return data.ExportFilename;
            }

            return "generated_behaviors." + format;
        }

        public string GetExportFolder(string format)
        {
            if (_exportDatas.ContainsKey(format))
            {
                ExportData data = _exportDatas[format];
                return data.ExportFolder;
            }

            return string.Empty;
        }

        public List<string> GetExportIncludedFilenames(string format)
        {
            if (_exportDatas.ContainsKey(format))
            {
                ExportData data = _exportDatas[format];
                return data.ExportIncludedFilenames;
            }

            return new List<string>();
        }

		private string MakeAbsolutePath(string relativePath)
		{
			string absolute= relativePath;

			absolute= absolute.Replace("$DESKTOP", Environment.GetFolderPath(Environment.SpecialFolder.DesktopDirectory));
			absolute= absolute.Replace("$PERSONAL", Environment.GetFolderPath(Environment.SpecialFolder.Personal));
			absolute= absolute.Replace("$DOCUMENTS", Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments));
			absolute= absolute.Replace("$APPDATA", Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData));
			absolute= absolute.Replace("$LOCALAPPDATA", Environment.GetFolderPath(Environment.SpecialFolder.LocalApplicationData));
			absolute= absolute.Replace("$COMMONAPPDATA", Environment.GetFolderPath(Environment.SpecialFolder.CommonApplicationData));
			absolute= absolute.Replace("$PICTURES", Environment.GetFolderPath(Environment.SpecialFolder.MyPictures));

            if (Path.IsPathRooted(absolute))
            {
                return absolute;
            }

            string path = Path.GetDirectoryName(_file_name);
            string result = Path.Combine(path, absolute);
            return result;
		}

		private string MakeRelativePath(string absolutePath)
		{
            string path = Path.GetDirectoryName(_file_name);
            string relative = MakeRelative(absolutePath, path, true, true);

			return relative;
		}

		/// <summary>
		/// Creates a new workspace.
		/// </summary>
		/// <param name="name">The name of the workspace.</param>
		/// <param name="folder">The folder the behaviors will be loaded from.</param>
		/// <param name="defaultExportFolder">The folder behaviours are exported to by default.</param>
        public Workspace(string path, string name, string xmlfolder, string folder, string defaultExportFolder, Dictionary<string, ExportData> exportDatas = null)
        {
            _file_name = Path.GetFullPath(path);
            _name = name;

            Debug.Check(_file_name != null);
            _xmlFolder = MakeAbsolutePath(xmlfolder);
            _folder = MakeAbsolutePath(folder);
            _defaultExportFolder = MakeAbsolutePath(defaultExportFolder);
            if (exportDatas != null)
                _exportDatas = exportDatas;
        }

		/// <summary>
		/// This is required for the combobox used in the workspace selection dialogue.
		/// </summary>
		/// <returns>Returns the name of the workspace.</returns>
		public override string ToString()
		{
			return _name;
		}

        /// <summary>
        /// Creates a relative path from one file
        /// or folder to another.
        /// </summary>
        /// <param name="fromDirectory">
        /// Contains the directory that defines the
        /// start of the relative path.
        /// </param>
        /// <param name="toPath">
        /// Contains the path that defines the
        /// endpoint of the relative path.
        /// </param>
        /// <returns>
        /// The relative path from the start
        /// directory to the end path.
        /// </returns>
        /// <exception cref="ArgumentNullException"></exception>
        public static string MakeRelative(string toPath, string fromDirectory_, bool bDifferent, bool from_is_path = false)
        {
            if (fromDirectory_ == null)
                throw new ArgumentNullException("fromDirectory");

            string fromDirectory = fromDirectory_;
            if (!from_is_path)
            {
                fromDirectory = Path.GetDirectoryName(fromDirectory_);
            }

            if (toPath == null)
                throw new ArgumentNullException("toPath");

            bool isRooted = (Path.IsPathRooted(fromDirectory) && Path.IsPathRooted(toPath));

            if (isRooted)
            {
                bool isDifferentRoot = (string.Compare(Path.GetPathRoot(fromDirectory), Path.GetPathRoot(toPath), true) != 0);

                if (isDifferentRoot)
                    return toPath;
            }

            List<string> relativePath = new List<string>();
            string[] fromDirectories = fromDirectory.Split(Path.DirectorySeparatorChar);

            string[] toDirectories = toPath.Split(Path.DirectorySeparatorChar);

            int length = Math.Min(fromDirectories.Length, toDirectories.Length);

            int lastCommonRoot = -1;

            // find common root
            for (int x = 0; x < length; x++)
            {
                if (string.Compare(fromDirectories[x], toDirectories[x], true) != 0)
                    break;

                lastCommonRoot = x;
            }

            if (lastCommonRoot == -1)
                return toPath;

            // add relative folders in from path
            int higherLevel = bDifferent ? 1 : 0;
            for (int x = lastCommonRoot + higherLevel; x < fromDirectories.Length; x++)
            {
                if (fromDirectories[x].Length > 0)
                    relativePath.Add("..");
            }

            // add to folders to path
            for (int x = lastCommonRoot + 1; x < toDirectories.Length; x++)
            {
                relativePath.Add(toDirectories[x]);
            }

            // create relative path
            string[] relativeParts = new string[relativePath.Count];
            relativePath.CopyTo(relativeParts, 0);

            string newPath = string.Join(Path.DirectorySeparatorChar.ToString(), relativeParts);

            if (string.IsNullOrEmpty(newPath))
            {
                newPath = ".";
            }

            return newPath;
        }

        /// <summary>
        /// Retrieves an attribute from a XML node. If the attribute does not exist an exception is thrown.
        /// </summary>
        /// <param name="node">The XML node we want to get the attribute from.</param>
        /// <param name="att">The name of the attribute we want.</param>
        /// <returns>Returns the attributes value. Is always valid.</returns>
        private static string GetAttribute(XmlNode node, string att)
        {
            XmlNode value = node.Attributes.GetNamedItem(att);
            if (value != null && value.NodeType == XmlNodeType.Attribute)
                return value.Value;

            return string.Empty;
        }

        public static Workspace LoadWorkspaceFile(string filename)
        {
            try
            {
                if (!File.Exists(filename))
                    return null;

                XmlDocument xml = new XmlDocument();
                xml.Load(filename);

                XmlNode root = xml.ChildNodes[1];
                if (root.Name == "workspace")
                {
                    string name = GetAttribute(root, "name");
                    string xmlfolder = GetAttribute(root, "xmlmetafolder");
                    string folder = GetAttribute(root, "folder");
                    string defaultExportFolder = GetAttribute(root, "export");
                    if (string.IsNullOrEmpty(name) ||
                        string.IsNullOrEmpty(xmlfolder) ||
                        string.IsNullOrEmpty(folder) ||
                        string.IsNullOrEmpty(defaultExportFolder))
                    {
                        throw new Exception(Resources.LoadWorkspaceError);
                    }

                    Workspace ws = new Workspace(filename, name, xmlfolder, folder, defaultExportFolder);

                    foreach (XmlNode subnode in root)
                    {
                        if (subnode.NodeType == XmlNodeType.Element)
                        {
                            switch (subnode.Name)
                            {
                                // Load all XML plugins.
                                case "xmlmeta":
                                    string nodeName = subnode.InnerText.Trim();
                                    if (!string.IsNullOrEmpty(nodeName))
                                        ws.AddXMLPlugin(nodeName);
                                    break;

                                // Load export nodes.
                                case "export":
                                    foreach (XmlNode exportNode in subnode)
                                    {
                                        if (exportNode.NodeType == XmlNodeType.Element)
                                        {
                                            if (!ws._exportDatas.ContainsKey(exportNode.Name))
                                            {
                                                ws._exportDatas[exportNode.Name] = new ExportData();
                                            }
                                            ExportData data = ws._exportDatas[exportNode.Name];

                                            foreach (XmlNode exportInfoNode in exportNode)
                                            {
                                                switch (exportInfoNode.Name)
                                                {
                                                    case "isexported":
                                                        data.IsExported = Boolean.Parse(exportInfoNode.InnerText.Trim());
                                                        break;

                                                    case "filename":
                                                        data.ExportFilename = exportInfoNode.InnerText.Trim();
                                                        break;

                                                    case "folder":
                                                        data.ExportFolder = exportInfoNode.InnerText.Trim();
                                                        break;

                                                    case "includedfilenames":
                                                        foreach (XmlNode sn in exportInfoNode)
                                                        {
                                                            if (sn.NodeType == XmlNodeType.Element && sn.Name == "includedfilename")
                                                            {
                                                                string includeFilename = sn.InnerText.Trim();
                                                                if (!data.ExportIncludedFilenames.Contains(includeFilename))
                                                                    data.ExportIncludedFilenames.Add(includeFilename);
                                                            }
                                                        }
                                                        break;
                                                }
                                            }
                                        }
                                    }
                                    break;
                            }
                        }
                    }

                    return ws;
                }
            }
            catch(Exception)
            {
                string msgError = string.Format(Resources.LoadWorkspaceError, filename);
                MessageBox.Show(msgError, Resources.LoadError, MessageBoxButtons.OK);
            }

            return null;
        }

        public static void SaveWorkspaceFile(Workspace ws)
        {
            // check if we have a valid result
            if (ws != null && !string.IsNullOrEmpty(ws.FileName))
            {
                try
                {
                    XmlDocument xml = new XmlDocument();

                    // Create the xml declaration.
                    XmlDeclaration declaration = xml.CreateXmlDeclaration("1.0", "utf-8", null);
                    xml.AppendChild(declaration);

                    {
                        // Create workspace node.
                        XmlElement workspace = xml.CreateElement("workspace");
                        workspace.SetAttribute("name", ws.Name);
                        workspace.SetAttribute("xmlmetafolder", ws.RelativeXMLFolder);
                        workspace.SetAttribute("folder", ws.RelativeFolder);
                        workspace.SetAttribute("export", ws.RelativeDefaultExportFolder);
                        xml.AppendChild(workspace);

                        // Create XML plugin nodes.
                        foreach (string xmlPlugin in ws.XMLPlugins)
                        {
                            XmlElement p = xml.CreateElement("xmlmeta");
                            p.InnerText = xmlPlugin;
                            workspace.AppendChild(p);
                        }

                        // Create export nodes.
                        XmlElement export = xml.CreateElement("export");
                        workspace.AppendChild(export);

                        foreach (string format in ws._exportDatas.Keys)
                        {
                            ExportData data = ws._exportDatas[format];

                            // Create exporter nodes.
                            XmlElement exporter = xml.CreateElement(format);
                            export.AppendChild(exporter);

                            // Create isExported node.
                            XmlElement isExported = xml.CreateElement("isexported");
                            isExported.InnerText = data.IsExported.ToString();
                            exporter.AppendChild(isExported);

                            // Create filename nodes
                            if (!string.IsNullOrEmpty(data.ExportFilename))
                            {
                                XmlElement filename = xml.CreateElement("filename");
                                filename.InnerText = data.ExportFilename;
                                exporter.AppendChild(filename);
                            }

                            // Create folder node.
                            if (!string.IsNullOrEmpty(data.ExportFolder))
                            {
                                XmlElement folder = xml.CreateElement("folder");
                                folder.InnerText = data.ExportFolder;
                                exporter.AppendChild(folder);
                            }

                            // Create includedfilenames nodes.
                            if (data.ExportIncludedFilenames.Count > 0)
                            {
                                XmlElement exportincludedfilenames = xml.CreateElement("includedfilenames");
                                exporter.AppendChild(exportincludedfilenames);
                                foreach (string includedFilename in data.ExportIncludedFilenames)
                                {
                                    XmlElement exportincludedfilename = xml.CreateElement("includedfilename");
                                    exportincludedfilename.InnerText = includedFilename;
                                    exportincludedfilenames.AppendChild(exportincludedfilename);
                                }
                            }
                        }
                    }

                    //FileManagers.FileManager.MakeWritable(filename);

                    //string dir = Path.GetDirectoryName(filename);
                    //if (!string.IsNullOrEmpty(dir) && !Directory.Exists(dir))
                    //{
                    //    Directory.CreateDirectory(dir);
                    //}

                    // save workspaces
                    xml.Save(ws.FileName);
                }
                catch (Exception)
                {
                    string msgError = string.Format(Resources.SaveWorkspaceError, ws.FileName);
                    MessageBox.Show(msgError, Resources.SaveError, MessageBoxButtons.OK);
                }
            }
        }
	}
}
