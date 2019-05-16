namespace RGR05
{
    partial class Form3
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
            Microsoft.Reporting.WinForms.ReportDataSource reportDataSource1 = new Microsoft.Reporting.WinForms.ReportDataSource();
            this.ПользователиBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.Base1DataSet = new RGR05.Base1DataSet();
            this.reportViewer1 = new Microsoft.Reporting.WinForms.ReportViewer();
            this.ПользователиTableAdapter = new RGR05.Base1DataSetTableAdapters.ПользователиTableAdapter();
            this.MoviesUsersBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.MoviesUsersTableAdapter = new RGR05.Base1DataSetTableAdapters.MoviesUsersTableAdapter();
            ((System.ComponentModel.ISupportInitialize)(this.ПользователиBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.Base1DataSet)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.MoviesUsersBindingSource)).BeginInit();
            this.SuspendLayout();
            // 
            // ПользователиBindingSource
            // 
            this.ПользователиBindingSource.DataMember = "Пользователи";
            this.ПользователиBindingSource.DataSource = this.Base1DataSet;
            // 
            // Base1DataSet
            // 
            this.Base1DataSet.DataSetName = "Base1DataSet";
            this.Base1DataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // reportViewer1
            // 
            reportDataSource1.Name = "DataSet1";
            reportDataSource1.Value = this.MoviesUsersBindingSource;
            this.reportViewer1.LocalReport.DataSources.Add(reportDataSource1);
            this.reportViewer1.LocalReport.ReportEmbeddedResource = "RGR05.Report1.rdlc";
            this.reportViewer1.Location = new System.Drawing.Point(13, 13);
            this.reportViewer1.Name = "reportViewer1";
            this.reportViewer1.Size = new System.Drawing.Size(396, 246);
            this.reportViewer1.TabIndex = 0;
            // 
            // ПользователиTableAdapter
            // 
            this.ПользователиTableAdapter.ClearBeforeFill = true;
            // 
            // MoviesUsersBindingSource
            // 
            this.MoviesUsersBindingSource.DataMember = "MoviesUsers";
            this.MoviesUsersBindingSource.DataSource = this.Base1DataSet;
            // 
            // MoviesUsersTableAdapter
            // 
            this.MoviesUsersTableAdapter.ClearBeforeFill = true;
            // 
            // Form3
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(633, 261);
            this.Controls.Add(this.reportViewer1);
            this.Name = "Form3";
            this.Text = "Form3";
            this.Load += new System.EventHandler(this.Form3_Load);
            ((System.ComponentModel.ISupportInitialize)(this.ПользователиBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.Base1DataSet)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.MoviesUsersBindingSource)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private Microsoft.Reporting.WinForms.ReportViewer reportViewer1;
        private System.Windows.Forms.BindingSource ПользователиBindingSource;
        private Base1DataSet Base1DataSet;
        private Base1DataSetTableAdapters.ПользователиTableAdapter ПользователиTableAdapter;
        private System.Windows.Forms.BindingSource MoviesUsersBindingSource;
        private Base1DataSetTableAdapters.MoviesUsersTableAdapter MoviesUsersTableAdapter;
    }
}