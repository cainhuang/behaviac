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
using System.IO;
using System.Net;
using System.Text;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Runtime.Serialization.Formatters.Binary;

using Behaviac.Design.Properties;

namespace Behaviac.Design
{
    public class Utilities
    {
        public static void ClearDirectory(string folderName)
        {
            DirectoryInfo dir = new DirectoryInfo(folderName);

            foreach (FileInfo fi in dir.GetFiles())
            {
                fi.Delete();
            }

            foreach (DirectoryInfo di in dir.GetDirectories())
            {
                ClearDirectory(di.FullName);
                di.Delete();
            }
        }

        public static string GetDebugFileDirectory()
        {
            string dbgFileDir = Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments);
            return Path.Combine(dbgFileDir, "BehaviacDesigner");
        }

        public static string GetLogFileDirectory()
        {
            return Path.Combine(Path.GetTempPath(), "BehaviacDesigner");
        }

        public static bool IPOnlyNumbersAndDots(String s)
        {
            if (string.IsNullOrEmpty(s))
                return false;

            for (int i = 0; i < s.Length; ++i)
            {
                if (!char.IsDigit(s[i]) && s[i] != '.')
                    return false;
            }

            return true;
        }

        public static String GetLocalIP()
        {
            String strHostName = Dns.GetHostName();
            return GetIP(strHostName);
        }

        public static String GetIP(String strHostName)
        {
            // Find host by name
            IPHostEntry iphostentry = Dns.GetHostEntry(strHostName);

            // Grab the first IP addresses
            String IPStr = "";
            foreach (IPAddress ipaddress in iphostentry.AddressList)
            {
                IPStr = ipaddress.ToString();

                if (IPOnlyNumbersAndDots(IPStr))
                    return IPStr;
            }

            return IPStr;
        }

        private static bool ReportToTQOS(int intNum, string intList, int strNum, string strList)
        {
            try
            {
                string qosData = "http://ied-tqosweb.qq.com:8001/?tqos={\"Head\":{\"Cmd\":5},\"Body\":{\"QOSRep\":{\"BusinessID\":1,\"QosNum\":1,\"QosList\":[{\"QosID\":7001,\"QosVal\":0,\"AppendDescFlag\":2,\"AppendDesc\":{\"Comm\":{\"IntNum\":";
                qosData += intNum;
                qosData += ",\"IntList\":[";
                qosData += intList;
                qosData += "],\"StrNum\":";
                qosData += strNum;
                qosData += ",\"StrList\":[";
                qosData += strList;
                qosData += "]}}}]}}}";

                using (var client = new WebClient())
                {
                    Uri uri = new Uri(qosData);
                    client.OpenReadAsync(uri);
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
                return false;
            }

            return true;
        }

        [Serializable]
        enum OperationTypes
        {
            kOpenEditor = 1,
            kOpenWorkspace,
            kLoadBehavior,
            kExportBehavior,
            kConnectGame,
            kOpenDoc,
        }

        [Serializable]
        class OperationData
        {
            public OperationTypes Type;
            public int Count;
            public string Value;

            public OperationData(OperationTypes type, string value = "")
            {
                Type = type;
                Count = 1;
                Value = value;
            }
        }

        private static List<OperationData> _allOperations = new List<OperationData>();
        private static OperationData FindOperation(OperationTypes type, string value = "")
        {
            for (int i = 0; i < _allOperations.Count; ++i)
            {
                if (_allOperations[i].Type == type && _allOperations[i].Value == value)
                    return _allOperations[i];
            }

            return null;
        }

        private static string getHeaderString()
        {
            return string.Format("\"{0}\",\"{1}\"", GetLocalIP(), System.Reflection.Assembly.GetEntryAssembly().GetName().Version);
        }

        private static string getTqosFile()
        {
            string filename = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments), "BehaviacDesigner\\operations.tqos");
            filename = Path.GetFullPath(filename);
            return filename;
        }

        public static bool LoadOperations()
        {
            try
            {
                string filename = getTqosFile();
                Stream stream = File.Open(filename, FileMode.Open);
                BinaryFormatter formatter = new BinaryFormatter();

                _allOperations = formatter.Deserialize(stream) as List<OperationData>;
            }
            catch
            {
                return false;
            }

            SendOperations();

            return true;
        }

        public static bool SaveOperations()
        {
            if (SendOperations())
                return false;

            try
            {
                string filename = getTqosFile();
                Stream stream = File.Open(filename, FileMode.Create);
                BinaryFormatter formatter = new BinaryFormatter();

                formatter.Serialize(stream, _allOperations);
            }
            catch
            {
                return false;
            }

            return true;
        }

        public static bool SendOperations()
        {
            bool sendSuccess = true;

            foreach (OperationData operation in _allOperations)
            {
                int intNum = 8;
                string intList = string.Format("0,0,0,0,0,0,{0},{1}", (int)operation.Type, operation.Count);

                int strNum = 2;
                string strList = getHeaderString();

                if (operation.Type == OperationTypes.kOpenWorkspace || operation.Type == OperationTypes.kLoadBehavior)
                {
                    strNum = 3;
                    strList = string.Format("{0},\"{1}\"", strList, operation.Value);
                }

                if (!ReportToTQOS(intNum, intList, strNum, strList))
                {
                    sendSuccess = false;
                    break;
                }
            }

            if (sendSuccess)
            {
                _allOperations.Clear();
            }

            return sendSuccess;
        }

        public static void ReportOpenEditor()
        {
            OperationData operation = FindOperation(OperationTypes.kOpenEditor);
            if (operation == null)
            {
                operation = new OperationData(OperationTypes.kOpenEditor);
                _allOperations.Add(operation);
            }
            else
            {
                operation.Count++;
            }
        }

        public static void ReportOpenWorkspace(string workspaceName)
        {
            OperationData operation = FindOperation(OperationTypes.kOpenWorkspace, workspaceName);
            if (operation == null)
            {
                operation = new OperationData(OperationTypes.kOpenWorkspace, workspaceName);
                _allOperations.Add(operation);
            }
            else
            {
                operation.Count++;
            }
        }

        public static void ReportLoadBehavior(string behaviorName)
        {
            OperationData operation = FindOperation(OperationTypes.kLoadBehavior, behaviorName);
            if (operation == null)
            {
                operation = new OperationData(OperationTypes.kLoadBehavior, behaviorName);
                _allOperations.Add(operation);
            }
            else
            {
                operation.Count++;
            }
        }

        public static void ReportExportBehavior()
        {
            OperationData operation = FindOperation(OperationTypes.kExportBehavior);
            if (operation == null)
            {
                operation = new OperationData(OperationTypes.kExportBehavior);
                _allOperations.Add(operation);
            }
            else
            {
                operation.Count++;
            }
        }

        public static void ReportConnectGame()
        {
            OperationData operation = FindOperation(OperationTypes.kConnectGame);
            if (operation == null)
            {
                operation = new OperationData(OperationTypes.kConnectGame);
                _allOperations.Add(operation);
            }
            else
            {
                operation.Count++;
            }
        }

        public static void ReportOpenDoc()
        {
            OperationData operation = FindOperation(OperationTypes.kOpenDoc);
            if (operation == null)
            {
                operation = new OperationData(OperationTypes.kOpenDoc);
                _allOperations.Add(operation);
            }
            else
            {
                operation.Count++;
            }
        }
    }
}
