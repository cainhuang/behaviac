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

        public static void ReportToTQOS(int intNum, string intList, int strNum, string strList)
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
                    //client.OpenReadAsync(uri);
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
        }

        enum OperationTypes
        {
            kOpenEditor = 1,
            kOpenWorkspace,
            kLoadBehavior,
            kExportBehavior,
            kConnectGame,
            kOpenDoc,
        }

        private static string getHeaderString()
        {
            return string.Format("\"{0}\",\"{1}\"", GetLocalIP(), System.Reflection.Assembly.GetEntryAssembly().GetName().Version);
        }

        public static void ReportOpenEditor()
        {
            int intNum = 8;
            string intList = string.Format("0,0,0,0,0,0,{0},{1}", (int)OperationTypes.kOpenEditor, 1);
            int strNum = 2;
            string strList = getHeaderString();

            ReportToTQOS(intNum, intList, strNum, strList);
        }

        public static void ReportOpenWorkspace(string workspaceName)
        {
            int intNum = 8;
            string intList = string.Format("0,0,0,0,0,0,{0},{1}", (int)OperationTypes.kOpenWorkspace, 1);
            int strNum = 3;
            string header = getHeaderString();
            string strList = string.Format("{0},\"{1}\"", header, workspaceName);

            ReportToTQOS(intNum, intList, strNum, strList);
        }

        public static void ReportLoadBehavior(string behaviorName)
        {
            int intNum = 8;
            string intList = string.Format("0,0,0,0,0,0,{0},{1}", (int)OperationTypes.kLoadBehavior, 1);
            int strNum = 3;
            string header = getHeaderString();
            string strList = string.Format("{0},\"{1}\"", header, behaviorName);

            ReportToTQOS(intNum, intList, strNum, strList);
        }

        public static void ReportExportBehavior()
        {
            int intNum = 8;
            string intList = string.Format("0,0,0,0,0,0,{0},{1}", (int)OperationTypes.kExportBehavior, 1);
            int strNum = 2;
            string strList = getHeaderString();

            ReportToTQOS(intNum, intList, strNum, strList);
        }

        public static void ReportConnectGame()
        {
            int intNum = 8;
            string intList = string.Format("0,0,0,0,0,0,{0},{1}", (int)OperationTypes.kConnectGame, 1);
            int strNum = 2;
            string strList = getHeaderString();

            ReportToTQOS(intNum, intList, strNum, strList);
        }

        public static void ReportOpenDoc()
        {
            int intNum = 8;
            string intList = string.Format("0,0,0,0,0,0,{0},{1}", (int)OperationTypes.kOpenDoc, 1);
            int strNum = 2;
            string strList = getHeaderString();

            ReportToTQOS(intNum, intList, strNum, strList);
        }
    }
}
