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
	partial class FindFileDialog
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
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FindFileDialog));
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle7 = new System.Windows.Forms.DataGridViewCellStyle();
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle10 = new System.Windows.Forms.DataGridViewCellStyle();
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle11 = new System.Windows.Forms.DataGridViewCellStyle();
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle12 = new System.Windows.Forms.DataGridViewCellStyle();
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle8 = new System.Windows.Forms.DataGridViewCellStyle();
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle9 = new System.Windows.Forms.DataGridViewCellStyle();
            this.folderBrowserDialog = new System.Windows.Forms.FolderBrowserDialog();
            this.imageList = new System.Windows.Forms.ImageList(this.components);
            this.filesGridView = new System.Windows.Forms.DataGridView();
            this.filepathColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.sizeColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.modifiedTimeColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.filenameTextBox = new System.Windows.Forms.TextBox();
            this.exportFolderLabel = new System.Windows.Forms.Label();
            this.searchIncludeDirCheckBox = new System.Windows.Forms.CheckBox();
            this.fileCountLabel = new System.Windows.Forms.Label();
            this.closeButton = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.filesGridView)).BeginInit();
            this.SuspendLayout();
            // 
            // folderBrowserDialog
            // 
            resources.ApplyResources(this.folderBrowserDialog, "folderBrowserDialog");
            this.folderBrowserDialog.RootFolder = System.Environment.SpecialFolder.MyComputer;
            // 
            // imageList
            // 
            this.imageList.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("imageList.ImageStream")));
            this.imageList.TransparentColor = System.Drawing.Color.Magenta;
            this.imageList.Images.SetKeyName(0, "VSFolder_closed.bmp");
            this.imageList.Images.SetKeyName(1, "DocumentHS.png");
            // 
            // filesGridView
            // 
            resources.ApplyResources(this.filesGridView, "filesGridView");
            this.filesGridView.AllowUserToAddRows = false;
            this.filesGridView.AllowUserToDeleteRows = false;
            this.filesGridView.AllowUserToResizeRows = false;
            this.filesGridView.BackgroundColor = System.Drawing.Color.FromArgb(((int)(((byte)(65)))), ((int)(((byte)(65)))), ((int)(((byte)(65)))));
            this.filesGridView.ColumnHeadersBorderStyle = System.Windows.Forms.DataGridViewHeaderBorderStyle.Single;
            dataGridViewCellStyle7.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleLeft;
            dataGridViewCellStyle7.BackColor = System.Drawing.Color.DarkGray;
            dataGridViewCellStyle7.Font = new System.Drawing.Font("SimSun", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            dataGridViewCellStyle7.ForeColor = System.Drawing.Color.LightGray;
            dataGridViewCellStyle7.SelectionBackColor = System.Drawing.SystemColors.Highlight;
            dataGridViewCellStyle7.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle7.WrapMode = System.Windows.Forms.DataGridViewTriState.True;
            this.filesGridView.ColumnHeadersDefaultCellStyle = dataGridViewCellStyle7;
            this.filesGridView.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.filesGridView.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.filepathColumn,
            this.sizeColumn,
            this.modifiedTimeColumn});
            dataGridViewCellStyle10.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleLeft;
            dataGridViewCellStyle10.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(56)))), ((int)(((byte)(56)))), ((int)(((byte)(56)))));
            dataGridViewCellStyle10.Font = new System.Drawing.Font("SimSun", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            dataGridViewCellStyle10.ForeColor = System.Drawing.Color.LightGray;
            dataGridViewCellStyle10.SelectionBackColor = System.Drawing.SystemColors.Highlight;
            dataGridViewCellStyle10.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle10.WrapMode = System.Windows.Forms.DataGridViewTriState.False;
            this.filesGridView.DefaultCellStyle = dataGridViewCellStyle10;
            this.filesGridView.MultiSelect = false;
            this.filesGridView.Name = "filesGridView";
            this.filesGridView.RowHeadersBorderStyle = System.Windows.Forms.DataGridViewHeaderBorderStyle.Single;
            dataGridViewCellStyle11.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleLeft;
            dataGridViewCellStyle11.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(56)))), ((int)(((byte)(56)))), ((int)(((byte)(56)))));
            dataGridViewCellStyle11.Font = new System.Drawing.Font("SimSun", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            dataGridViewCellStyle11.ForeColor = System.Drawing.Color.LightGray;
            dataGridViewCellStyle11.SelectionBackColor = System.Drawing.SystemColors.Highlight;
            dataGridViewCellStyle11.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle11.WrapMode = System.Windows.Forms.DataGridViewTriState.True;
            this.filesGridView.RowHeadersDefaultCellStyle = dataGridViewCellStyle11;
            this.filesGridView.RowHeadersVisible = false;
            dataGridViewCellStyle12.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(56)))), ((int)(((byte)(56)))), ((int)(((byte)(56)))));
            dataGridViewCellStyle12.ForeColor = System.Drawing.Color.LightGray;
            this.filesGridView.RowsDefaultCellStyle = dataGridViewCellStyle12;
            this.filesGridView.RowTemplate.Height = 23;
            this.filesGridView.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.filesGridView.VirtualMode = true;
            this.filesGridView.CellMouseDoubleClick += new System.Windows.Forms.DataGridViewCellMouseEventHandler(this.filesGridView_CellMouseDoubleClick);
            this.filesGridView.CellValueNeeded += new System.Windows.Forms.DataGridViewCellValueEventHandler(this.filesGridView_CellValueNeeded);
            this.filesGridView.ColumnHeaderMouseClick += new System.Windows.Forms.DataGridViewCellMouseEventHandler(this.filesGridView_ColumnHeaderMouseClick);
            this.filesGridView.KeyDown += new System.Windows.Forms.KeyEventHandler(this.filesGridView_KeyDown);
            // 
            // filepathColumn
            // 
            this.filepathColumn.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
            this.filepathColumn.FillWeight = 80F;
            resources.ApplyResources(this.filepathColumn, "filepathColumn");
            this.filepathColumn.Name = "filepathColumn";
            this.filepathColumn.ReadOnly = true;
            // 
            // sizeColumn
            // 
            this.sizeColumn.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
            dataGridViewCellStyle8.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleRight;
            this.sizeColumn.DefaultCellStyle = dataGridViewCellStyle8;
            this.sizeColumn.FillWeight = 10F;
            resources.ApplyResources(this.sizeColumn, "sizeColumn");
            this.sizeColumn.Name = "sizeColumn";
            this.sizeColumn.ReadOnly = true;
            // 
            // modifiedTimeColumn
            // 
            this.modifiedTimeColumn.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
            dataGridViewCellStyle9.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleRight;
            this.modifiedTimeColumn.DefaultCellStyle = dataGridViewCellStyle9;
            this.modifiedTimeColumn.FillWeight = 20F;
            resources.ApplyResources(this.modifiedTimeColumn, "modifiedTimeColumn");
            this.modifiedTimeColumn.Name = "modifiedTimeColumn";
            this.modifiedTimeColumn.ReadOnly = true;
            this.modifiedTimeColumn.Resizable = System.Windows.Forms.DataGridViewTriState.True;
            // 
            // filenameTextBox
            // 
            resources.ApplyResources(this.filenameTextBox, "filenameTextBox");
            this.filenameTextBox.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(65)))), ((int)(((byte)(65)))), ((int)(((byte)(65)))));
            this.filenameTextBox.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.filenameTextBox.ForeColor = System.Drawing.Color.LightGray;
            this.filenameTextBox.Name = "filenameTextBox";
            this.filenameTextBox.TextChanged += new System.EventHandler(this.filenameTextBox_TextChanged);
            this.filenameTextBox.KeyDown += new System.Windows.Forms.KeyEventHandler(this.filenameTextBox_KeyDown);
            // 
            // exportFolderLabel
            // 
            resources.ApplyResources(this.exportFolderLabel, "exportFolderLabel");
            this.exportFolderLabel.Name = "exportFolderLabel";
            // 
            // searchIncludeDirCheckBox
            // 
            resources.ApplyResources(this.searchIncludeDirCheckBox, "searchIncludeDirCheckBox");
            this.searchIncludeDirCheckBox.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(65)))), ((int)(((byte)(65)))), ((int)(((byte)(65)))));
            this.searchIncludeDirCheckBox.Checked = true;
            this.searchIncludeDirCheckBox.CheckState = System.Windows.Forms.CheckState.Checked;
            this.searchIncludeDirCheckBox.Name = "searchIncludeDirCheckBox";
            this.searchIncludeDirCheckBox.UseVisualStyleBackColor = false;
            this.searchIncludeDirCheckBox.CheckedChanged += new System.EventHandler(this.searchIncludeDirCheckBox_CheckedChanged);
            // 
            // fileCountLabel
            // 
            resources.ApplyResources(this.fileCountLabel, "fileCountLabel");
            this.fileCountLabel.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(65)))), ((int)(((byte)(65)))), ((int)(((byte)(65)))));
            this.fileCountLabel.Name = "fileCountLabel";
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
            // 
            // FindFileDialog
            // 
            resources.ApplyResources(this, "$this");
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(56)))), ((int)(((byte)(56)))), ((int)(((byte)(56)))));
            this.CancelButton = this.closeButton;
            this.Controls.Add(this.closeButton);
            this.Controls.Add(this.fileCountLabel);
            this.Controls.Add(this.searchIncludeDirCheckBox);
            this.Controls.Add(this.exportFolderLabel);
            this.Controls.Add(this.filenameTextBox);
            this.Controls.Add(this.filesGridView);
            this.ForeColor = System.Drawing.Color.LightGray;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "FindFileDialog";
            this.ShowInTaskbar = false;
            ((System.ComponentModel.ISupportInitialize)(this.filesGridView)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

		}

		#endregion

        private System.Windows.Forms.FolderBrowserDialog folderBrowserDialog;
        private System.Windows.Forms.ImageList imageList;
        private System.Windows.Forms.DataGridView filesGridView;
        private System.Windows.Forms.TextBox filenameTextBox;
        private System.Windows.Forms.Label exportFolderLabel;
        private System.Windows.Forms.CheckBox searchIncludeDirCheckBox;
        private System.Windows.Forms.Label fileCountLabel;
        private System.Windows.Forms.Button closeButton;
        private System.Windows.Forms.DataGridViewTextBoxColumn filepathColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn sizeColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn modifiedTimeColumn;
	}
}