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
using Behaviac.Design.Properties;

namespace Behaviac.Design
{
    public class Utilities
    {
        public static void ClearDirectory(string folderName) {
            DirectoryInfo dir = new DirectoryInfo(folderName);

            foreach(FileInfo fi in dir.GetFiles()) {
                fi.Delete();
            }

            foreach(DirectoryInfo di in dir.GetDirectories()) {
                ClearDirectory(di.FullName);
                di.Delete();
            }
        }

        public static string GetDebugFileDirectory() {
            string dbgFileDir = Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments);
            return Path.Combine(dbgFileDir, "BehaviacDesigner");
        }

        public static string GetLogFileDirectory() {
            return Path.Combine(Path.GetTempPath(), "BehaviacDesigner");
        }
    }
}
