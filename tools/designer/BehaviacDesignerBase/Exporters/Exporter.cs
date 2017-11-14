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
using System.Globalization;

namespace Behaviac.Design.Exporters
{
    /// <summary>
    /// This is the base class for an exporter. It allows you to export behaviours into your workflow to be added to your game.
    /// </summary>
    public abstract class Exporter
    {
        protected Nodes.BehaviorNode _node;

        /// <summary>
        /// The behaviour which will be exported.
        /// </summary>
        public Nodes.BehaviorNode Node {
            get { return _node; }
        }

        protected string _outputFolder;

        /// <summary>
        /// The folder we want to export the behaviour to.
        /// </summary>
        public string OutputFolder {
            get { return _outputFolder; }
        }

        protected string _filename;

        /// <summary>
        /// The relative filename the behaviour will be exported to.
        /// </summary>
        public string Filename {
            get { return _filename; }
        }

        protected List<string> _includedFilenames;
        public List<string> IncludedFilenames {
            get { return _includedFilenames; }
        }

        /// <summary>
        /// Creates a new exporter.
        /// </summary>
        /// <param name="node">The behaviour hich will be exported.</param>
        /// <param name="outputFolder">The folder we want to export the behaviour to.</param>
        /// <param name="filename">The relative filename we want to export to. You have to add your file extension.</param>
        public Exporter(Nodes.BehaviorNode node, string outputFolder, string filename, List<string> includedFilenames = null) {
            _node = node;
            _outputFolder = outputFolder;
            _filename = filename;
            _includedFilenames = includedFilenames;
        }

        /// <summary>
        /// Exportes the node to the given filename.
        /// </summary>
        /// <returns>Returns the result when the behaviour is exported.</returns>
        public virtual FileManagers.SaveResult Export() {
            return FileManagers.SaveResult.Succeeded;
        }

        public virtual FileManagers.SaveResult Export(List<Nodes.BehaviorNode> behaviors, bool exportBehaviors, int exportFileCount)
        {
            return FileManagers.SaveResult.Succeeded;
        }
    }
}
