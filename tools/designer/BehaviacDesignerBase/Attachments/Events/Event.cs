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
using System.Text;
using System.IO;
using System.Windows.Forms;
using System.Reflection;
using Behaviac.Design.Attributes;
using Behaviac.Design.Properties;
using Behaviac.Design.Nodes;

namespace Behaviac.Design.Attachments
{
    [Behaviac.Design.EnumDesc("Behaviac.Design.Attachments.TriggerMode", true, "TriggerMode", "TriggerModeDesc")]
    public enum TriggerMode
    {
        [Behaviac.Design.EnumMemberDesc("Transfer", true, "TriggerMode_Transfer", "TriggerMode_TransferDesc")]
        Transfer,

        [Behaviac.Design.EnumMemberDesc("Return", true, "TriggerMode_Return", "TriggerMode_ReturnDesc")]
        Return
    }

	/// <summary>
	/// This class represents an event which is attached to a node.
	/// </summary>
    public class Event : Attach
	{
        public Event(Behaviac.Design.Nodes.Node node)
            : base(node, Resources.Event, Resources.EventDesc)
        {
        }

        public override string ExportClass
        {
            get { return "Event"; }
        }

        protected bool _bTriggeredOnce = false;
        [DesignerBoolean("TriggeredOnce", "TriggeredOnceDesc", "Event", DesignerProperty.DisplayMode.NoDisplay, 0, DesignerProperty.DesignerFlags.NoFlags)]
        public bool TriggeredOnce
        {
            get { return _bTriggeredOnce; }
            set { _bTriggeredOnce = value; }
        }

        private TriggerMode _triggerMode = TriggerMode.Transfer;
        [DesignerEnum("TriggerMode", "TriggerModeDesc", "Event", DesignerProperty.DisplayMode.Parameter, 1, DesignerProperty.DesignerFlags.NoFlags, "")]
        public TriggerMode TriggerMode
        {
            get { return _triggerMode; }
            set { _triggerMode = value; }
        }


        private MethodDef _event;
        [DesignerMethodEnum("EventName", "EventNameDesc", "Event", DesignerProperty.DisplayMode.Parameter, 2, DesignerProperty.DesignerFlags.NoFlags, MethodType.Event)]
        public MethodDef EventName
        {
            get { return _event; }
            set { this._event = value; }
        }

        protected BehaviorNode _referencedBehavior;
        public BehaviorNode ReferencedBehavior
        {
            get { return _referencedBehavior; }
            set { _referencedBehavior = value; }
        }

        [DesignerString("ReferencedBehaviorFilename", "ReferencedBehaviorFilenameDesc", "Event", DesignerProperty.DisplayMode.NoDisplay, 3, DesignerProperty.DesignerFlags.ReadOnly)]
        public string ReferenceFilename
        {
            get
            {
                if (_referencedBehavior == null)
                    return string.Empty;

                // make the path of the reference relative
                string relativeFilename = _referencedBehavior.MakeRelative(_referencedBehavior.FileManager.Filename);

                // make sure the behaviour filename is still correct
                Debug.Check(_referencedBehavior.MakeAbsolute(relativeFilename) == _referencedBehavior.FileManager.Filename);
                Debug.Check(!Path.IsPathRooted(relativeFilename));
                relativeFilename = relativeFilename.Replace('\\', '/');
                int pos = relativeFilename.IndexOf(".xml");
                if (pos != -1)
                {
                    relativeFilename = relativeFilename.Remove(pos);
                }

                return relativeFilename;
            }
            set
            {
                string absoluteFilename = this.Behavior.MakeAbsolute(value);

                // make sure the behaviour filename is still correct
                Debug.Check(Path.IsPathRooted(absoluteFilename));

                int pos = absoluteFilename.IndexOf(".xml");
                if (pos == -1)
                {
                    absoluteFilename += ".xml";
                }

                if (!File.Exists(absoluteFilename))
                {
                    string info = string.Format(Resources.ReferencedBehaviorError, Label);
                    MessageBox.Show(info, Resources.LoadWarning, MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    return;
                }

                // load the referenced behaviour
                _referencedBehavior = BehaviorManager.Instance.LoadBehavior(absoluteFilename);
                Debug.Check(_referencedBehavior != null);

                //((Node)_referencedBehavior).WasModified += new WasModifiedEventDelegate(referencedBehavior_WasModified);
                //_referencedBehavior.WasRenamed += new Behavior.WasRenamedEventDelegate(referencedBehavior_WasRenamed);
                Behaviac.Design.Nodes.Behavior refB = ((Behaviac.Design.Nodes.Behavior)_referencedBehavior);
                List<ParInfo> allPars = new List<ParInfo>();
                ((Nodes.Node)refB).GetAllPars(ref allPars);
                foreach (ParInfo p in allPars)
                {
                    _pars.Add(p.Clone());
                }
            }
        }

        protected List<ParInfo> _pars = new List<ParInfo>();
        public List<ParInfo> Pars
        {
            get { return _pars; }
            set { _pars = value; }
        }

        public override void GetAllPars(ref List<ParInfo> pars)
        {
            pars = Pars;
        }

        protected override void CloneProperties(Behaviac.Design.Attachments.Attachment newattach)
        {
            base.CloneProperties(newattach);

            Event prec = (Event)newattach;

            if (this._event != null)
            {
                prec._event = (MethodDef)this._event.Clone();
            }

            if (this._referencedBehavior != null)
            {
                prec._referencedBehavior = this._referencedBehavior;
            }

            prec._bTriggeredOnce = this._bTriggeredOnce;

            // Clone the Pars.
            prec.Pars.Clear();
            foreach (ParInfo par in this.Pars)
            {
                prec.Pars.Add(par.Clone());
            }
        }

        public override void CheckForErrors(Behaviac.Design.Nodes.BehaviorNode rootBehavior, List<Behaviac.Design.Nodes.Node.ErrorCheck> result)
        {
            if (this._event == null)
            {
                result.Add(new Behaviac.Design.Nodes.Node.ErrorCheck(this.Node, this.Label, Behaviac.Design.Nodes.ErrorCheckLevel.Error, "Event is not specified!"));
            }
            if (this._referencedBehavior == null)
            {
                result.Add(new Behaviac.Design.Nodes.Node.ErrorCheck(this.Node, this.Label, Behaviac.Design.Nodes.ErrorCheckLevel.Error, "Behavior is not specified!"));
            }

            base.CheckForErrors(rootBehavior, result);
        }

        public override void GetReferencedFiles(ref List<string> referencedFiles)
        {
            string file = this.ReferenceFilename;
            if (!string.IsNullOrEmpty(file) && !referencedFiles.Contains(file))
            {
                referencedFiles.Add(file);
            }
        }
	}
}
