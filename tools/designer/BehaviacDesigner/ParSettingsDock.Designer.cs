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

namespace Behaviac.Design
{
	partial class ParSettingsDock
	{
        /// <summary> 
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary> 
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

		#region Windows Form Designer generated code

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(ParSettingsDock));
            this.panel = new System.Windows.Forms.Panel();
            this.tableLayoutPanel = new Behaviac.Design.BehaviacTableLayoutPanel();
            this.parameterLabel = new System.Windows.Forms.Label();
            this.nameLabel = new System.Windows.Forms.Label();
            this.typeLabel = new System.Windows.Forms.Label();
            this.defaultValueLabel = new System.Windows.Forms.Label();
            this.descLabel = new System.Windows.Forms.Label();
            this.toolStrip = new System.Windows.Forms.ToolStrip();
            this.addButton = new System.Windows.Forms.ToolStripButton();
            this.deleteButton = new System.Windows.Forms.ToolStripButton();
            this.editButton = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.sortButton = new System.Windows.Forms.ToolStripButton();
            this.panel.SuspendLayout();
            this.tableLayoutPanel.SuspendLayout();
            this.toolStrip.SuspendLayout();
            this.SuspendLayout();
            // 
            // panel
            // 
            resources.ApplyResources(this.panel, "panel");
            this.panel.Controls.Add(this.tableLayoutPanel);
            this.panel.Name = "panel";
            // 
            // tableLayoutPanel
            // 
            resources.ApplyResources(this.tableLayoutPanel, "tableLayoutPanel");
            this.tableLayoutPanel.Controls.Add(this.parameterLabel, 0, 0);
            this.tableLayoutPanel.Controls.Add(this.nameLabel, 1, 0);
            this.tableLayoutPanel.Controls.Add(this.typeLabel, 2, 0);
            this.tableLayoutPanel.Controls.Add(this.defaultValueLabel, 3, 0);
            this.tableLayoutPanel.Controls.Add(this.descLabel, 4, 0);
            this.tableLayoutPanel.ForeColor = System.Drawing.Color.LightGray;
            this.tableLayoutPanel.Name = "tableLayoutPanel";
            // 
            // parameterLabel
            // 
            resources.ApplyResources(this.parameterLabel, "parameterLabel");
            this.parameterLabel.ForeColor = System.Drawing.Color.LightGray;
            this.parameterLabel.Name = "parameterLabel";
            // 
            // nameLabel
            // 
            resources.ApplyResources(this.nameLabel, "nameLabel");
            this.nameLabel.ForeColor = System.Drawing.Color.LightGray;
            this.nameLabel.Name = "nameLabel";
            this.nameLabel.Click += new System.EventHandler(this.nameLabel_Click);
            // 
            // typeLabel
            // 
            resources.ApplyResources(this.typeLabel, "typeLabel");
            this.typeLabel.ForeColor = System.Drawing.Color.LightGray;
            this.typeLabel.Name = "typeLabel";
            this.typeLabel.Click += new System.EventHandler(this.typeLabel_Click);
            // 
            // defaultValueLabel
            // 
            resources.ApplyResources(this.defaultValueLabel, "defaultValueLabel");
            this.defaultValueLabel.ForeColor = System.Drawing.Color.LightGray;
            this.defaultValueLabel.Name = "defaultValueLabel";
            this.defaultValueLabel.Click += new System.EventHandler(this.defaultValueLabel_Click);
            // 
            // descLabel
            // 
            resources.ApplyResources(this.descLabel, "descLabel");
            this.descLabel.ForeColor = System.Drawing.Color.LightGray;
            this.descLabel.Name = "descLabel";
            this.descLabel.Click += new System.EventHandler(this.descLabel_Click);
            // 
            // toolStrip
            // 
            this.toolStrip.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(56)))), ((int)(((byte)(56)))), ((int)(((byte)(56)))));
            this.toolStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.addButton,
            this.deleteButton,
            this.editButton,
            this.toolStripSeparator1,
            this.sortButton});
            resources.ApplyResources(this.toolStrip, "toolStrip");
            this.toolStrip.Name = "toolStrip";
            // 
            // addButton
            // 
            this.addButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            resources.ApplyResources(this.addButton, "addButton");
            this.addButton.Name = "addButton";
            this.addButton.Click += new System.EventHandler(this.addButton_Click);
            // 
            // deleteButton
            // 
            this.deleteButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            resources.ApplyResources(this.deleteButton, "deleteButton");
            this.deleteButton.Name = "deleteButton";
            this.deleteButton.Click += new System.EventHandler(this.deleteButton_Click);
            // 
            // editButton
            // 
            this.editButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            resources.ApplyResources(this.editButton, "editButton");
            this.editButton.Name = "editButton";
            this.editButton.Click += new System.EventHandler(this.editButton_Click);
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            resources.ApplyResources(this.toolStripSeparator1, "toolStripSeparator1");
            // 
            // sortButton
            // 
            this.sortButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            resources.ApplyResources(this.sortButton, "sortButton");
            this.sortButton.Name = "sortButton";
            this.sortButton.Click += new System.EventHandler(this.sortButton_Click);
            // 
            // ParSettingsDock
            // 
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(56)))), ((int)(((byte)(56)))), ((int)(((byte)(56)))));
            resources.ApplyResources(this, "$this");
            this.Controls.Add(this.toolStrip);
            this.Controls.Add(this.panel);
            this.ForeColor = System.Drawing.Color.LightGray;
            this.Name = "ParSettingsDock";
            this.ShowIcon = false;
            this.TabText = "Pars";
            this.panel.ResumeLayout(false);
            this.panel.PerformLayout();
            this.tableLayoutPanel.ResumeLayout(false);
            this.tableLayoutPanel.PerformLayout();
            this.toolStrip.ResumeLayout(false);
            this.toolStrip.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

		}

		#endregion

        private System.Windows.Forms.Panel panel;
        private BehaviacTableLayoutPanel tableLayoutPanel;
        private System.Windows.Forms.Label parameterLabel;
        private System.Windows.Forms.Label nameLabel;
        private System.Windows.Forms.Label typeLabel;
        private System.Windows.Forms.Label defaultValueLabel;
        private System.Windows.Forms.Label descLabel;
        private System.Windows.Forms.ToolStrip toolStrip;
        private System.Windows.Forms.ToolStripButton addButton;
        private System.Windows.Forms.ToolStripButton deleteButton;
        private System.Windows.Forms.ToolStripButton editButton;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        private System.Windows.Forms.ToolStripButton sortButton;
    }
}
