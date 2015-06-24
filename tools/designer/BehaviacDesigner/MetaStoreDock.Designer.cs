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

namespace Behaviac.Design
{
	partial class MetaStoreDock
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MetaStoreDock));
            this.instanceLabel = new System.Windows.Forms.Label();
            this.closeButton = new System.Windows.Forms.Button();
            this.memberListBox = new System.Windows.Forms.ListBox();
            this.instanceComboBox = new System.Windows.Forms.ComboBox();
            this.memberTypeComboBox = new System.Windows.Forms.ComboBox();
            this.memberTypeLabel = new System.Windows.Forms.Label();
            this.memberDescriptionLabel = new System.Windows.Forms.Label();
            this.memberDescLabel = new System.Windows.Forms.Label();
            this.memberFilterLabel = new System.Windows.Forms.Label();
            this.memberFilterTextBox = new System.Windows.Forms.TextBox();
            this.memberFilterCheckBox = new System.Windows.Forms.CheckBox();
            this.memberListLabel = new System.Windows.Forms.Label();
            this.memberCountLabel = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // instanceLabel
            // 
            resources.ApplyResources(this.instanceLabel, "instanceLabel");
            this.instanceLabel.Name = "instanceLabel";
            // 
            // closeButton
            // 
            resources.ApplyResources(this.closeButton, "closeButton");
            this.closeButton.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(65)))), ((int)(((byte)(65)))), ((int)(((byte)(65)))));
            this.closeButton.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.closeButton.FlatAppearance.MouseDownBackColor = System.Drawing.Color.DarkGray;
            this.closeButton.FlatAppearance.MouseOverBackColor = System.Drawing.Color.DarkGray;
            this.closeButton.Name = "closeButton";
            this.closeButton.UseVisualStyleBackColor = false;
            this.closeButton.Click += new System.EventHandler(this.closeButton_Click);
            // 
            // memberListBox
            // 
            resources.ApplyResources(this.memberListBox, "memberListBox");
            this.memberListBox.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(56)))), ((int)(((byte)(56)))), ((int)(((byte)(56)))));
            this.memberListBox.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.memberListBox.ForeColor = System.Drawing.Color.LightGray;
            this.memberListBox.FormattingEnabled = true;
            this.memberListBox.Name = "memberListBox";
            this.memberListBox.KeyDown += new System.Windows.Forms.KeyEventHandler(this.memberListBox_KeyDown);
            this.memberListBox.MouseDown += new System.Windows.Forms.MouseEventHandler(this.memberListBox_MouseDown);
            // 
            // instanceComboBox
            // 
            resources.ApplyResources(this.instanceComboBox, "instanceComboBox");
            this.instanceComboBox.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(65)))), ((int)(((byte)(65)))), ((int)(((byte)(65)))));
            this.instanceComboBox.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.instanceComboBox.ForeColor = System.Drawing.Color.LightGray;
            this.instanceComboBox.FormattingEnabled = true;
            this.instanceComboBox.Name = "instanceComboBox";
            this.instanceComboBox.SelectedIndexChanged += new System.EventHandler(this.instanceComboBox_SelectedIndexChanged);
            // 
            // memberTypeComboBox
            // 
            resources.ApplyResources(this.memberTypeComboBox, "memberTypeComboBox");
            this.memberTypeComboBox.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(65)))), ((int)(((byte)(65)))), ((int)(((byte)(65)))));
            this.memberTypeComboBox.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.memberTypeComboBox.ForeColor = System.Drawing.Color.LightGray;
            this.memberTypeComboBox.FormattingEnabled = true;
            this.memberTypeComboBox.Name = "memberTypeComboBox";
            this.memberTypeComboBox.SelectedIndexChanged += new System.EventHandler(this.memberTypeComboBox_SelectedIndexChanged);
            // 
            // memberTypeLabel
            // 
            resources.ApplyResources(this.memberTypeLabel, "memberTypeLabel");
            this.memberTypeLabel.Name = "memberTypeLabel";
            // 
            // memberDescriptionLabel
            // 
            resources.ApplyResources(this.memberDescriptionLabel, "memberDescriptionLabel");
            this.memberDescriptionLabel.Name = "memberDescriptionLabel";
            // 
            // memberDescLabel
            // 
            resources.ApplyResources(this.memberDescLabel, "memberDescLabel");
            this.memberDescLabel.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.memberDescLabel.Name = "memberDescLabel";
            // 
            // memberFilterLabel
            // 
            resources.ApplyResources(this.memberFilterLabel, "memberFilterLabel");
            this.memberFilterLabel.Name = "memberFilterLabel";
            // 
            // memberFilterTextBox
            // 
            resources.ApplyResources(this.memberFilterTextBox, "memberFilterTextBox");
            this.memberFilterTextBox.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(65)))), ((int)(((byte)(65)))), ((int)(((byte)(65)))));
            this.memberFilterTextBox.ForeColor = System.Drawing.Color.LightGray;
            this.memberFilterTextBox.Name = "memberFilterTextBox";
            this.memberFilterTextBox.TextChanged += new System.EventHandler(this.memberFilterTextBox_TextChanged);
            // 
            // memberFilterCheckBox
            // 
            resources.ApplyResources(this.memberFilterCheckBox, "memberFilterCheckBox");
            this.memberFilterCheckBox.Name = "memberFilterCheckBox";
            this.memberFilterCheckBox.UseVisualStyleBackColor = true;
            this.memberFilterCheckBox.CheckedChanged += new System.EventHandler(this.memberFilterCheckBox_CheckedChanged);
            // 
            // memberListLabel
            // 
            resources.ApplyResources(this.memberListLabel, "memberListLabel");
            this.memberListLabel.Name = "memberListLabel";
            // 
            // memberCountLabel
            // 
            resources.ApplyResources(this.memberCountLabel, "memberCountLabel");
            this.memberCountLabel.Name = "memberCountLabel";
            // 
            // MetaStoreDock
            // 
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(56)))), ((int)(((byte)(56)))), ((int)(((byte)(56)))));
            this.CancelButton = this.closeButton;
            resources.ApplyResources(this, "$this");
            this.Controls.Add(this.memberCountLabel);
            this.Controls.Add(this.memberListLabel);
            this.Controls.Add(this.memberFilterCheckBox);
            this.Controls.Add(this.memberFilterTextBox);
            this.Controls.Add(this.memberFilterLabel);
            this.Controls.Add(this.memberDescLabel);
            this.Controls.Add(this.memberDescriptionLabel);
            this.Controls.Add(this.memberTypeComboBox);
            this.Controls.Add(this.memberTypeLabel);
            this.Controls.Add(this.instanceComboBox);
            this.Controls.Add(this.memberListBox);
            this.Controls.Add(this.closeButton);
            this.Controls.Add(this.instanceLabel);
            this.ForeColor = System.Drawing.Color.LightGray;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "MetaStoreDock";
            this.TopMost = true;
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.MetaStoreDock_FormClosing);
            this.ResumeLayout(false);
            this.PerformLayout();

		}

		#endregion

        private System.Windows.Forms.Label instanceLabel;
        private System.Windows.Forms.Button closeButton;
        private System.Windows.Forms.ListBox memberListBox;
        private System.Windows.Forms.ComboBox instanceComboBox;
        private System.Windows.Forms.ComboBox memberTypeComboBox;
        private System.Windows.Forms.Label memberTypeLabel;
        private System.Windows.Forms.Label memberDescriptionLabel;
        private System.Windows.Forms.Label memberDescLabel;
        private System.Windows.Forms.Label memberFilterLabel;
        private System.Windows.Forms.TextBox memberFilterTextBox;
        private System.Windows.Forms.CheckBox memberFilterCheckBox;
        private System.Windows.Forms.Label memberListLabel;
        private System.Windows.Forms.Label memberCountLabel;

    }
}
