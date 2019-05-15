namespace RGR05
{
    partial class Form1
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
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.названиеФильмаDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.годВыходаDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.длительностьDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.movieIDDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.moviesBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.base1DataSet = new RGR05.Base1DataSet();
            this.moviesTableAdapter = new RGR05.Base1DataSetTableAdapters.MoviesTableAdapter();
            this.dataGridView2 = new System.Windows.Forms.DataGridView();
            this.кодDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.userDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.movieDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.moviesUsersBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.moviesMoviesUsersBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.moviesUsersTableAdapter = new RGR05.Base1DataSetTableAdapters.MoviesUsersTableAdapter();
            this.dataGridView3 = new System.Windows.Forms.DataGridView();
            this.фамилияDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.имяDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.телефонDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.userIDDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.пользователиBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.пользователиTableAdapter = new RGR05.Base1DataSetTableAdapters.ПользователиTableAdapter();
            this.button1 = new System.Windows.Forms.Button();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.textBox3 = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.button2 = new System.Windows.Forms.Button();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.moviesUsersBindingSource1 = new System.Windows.Forms.BindingSource(this.components);
            this.moviesUsersBindingSource2 = new System.Windows.Forms.BindingSource(this.components);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.moviesBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.base1DataSet)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.moviesUsersBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.moviesMoviesUsersBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView3)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.пользователиBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.moviesUsersBindingSource1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.moviesUsersBindingSource2)).BeginInit();
            this.SuspendLayout();
            // 
            // dataGridView1
            // 
            this.dataGridView1.AutoGenerateColumns = false;
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.названиеФильмаDataGridViewTextBoxColumn,
            this.годВыходаDataGridViewTextBoxColumn,
            this.длительностьDataGridViewTextBoxColumn,
            this.movieIDDataGridViewTextBoxColumn});
            this.dataGridView1.DataSource = this.moviesBindingSource;
            this.dataGridView1.Location = new System.Drawing.Point(13, 13);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.Size = new System.Drawing.Size(449, 150);
            this.dataGridView1.TabIndex = 0;
            // 
            // названиеФильмаDataGridViewTextBoxColumn
            // 
            this.названиеФильмаDataGridViewTextBoxColumn.DataPropertyName = "Название фильма";
            this.названиеФильмаDataGridViewTextBoxColumn.HeaderText = "Название фильма";
            this.названиеФильмаDataGridViewTextBoxColumn.Name = "названиеФильмаDataGridViewTextBoxColumn";
            // 
            // годВыходаDataGridViewTextBoxColumn
            // 
            this.годВыходаDataGridViewTextBoxColumn.DataPropertyName = "Год выхода";
            this.годВыходаDataGridViewTextBoxColumn.HeaderText = "Год выхода";
            this.годВыходаDataGridViewTextBoxColumn.Name = "годВыходаDataGridViewTextBoxColumn";
            // 
            // длительностьDataGridViewTextBoxColumn
            // 
            this.длительностьDataGridViewTextBoxColumn.DataPropertyName = "Длительность";
            this.длительностьDataGridViewTextBoxColumn.HeaderText = "Длительность";
            this.длительностьDataGridViewTextBoxColumn.Name = "длительностьDataGridViewTextBoxColumn";
            // 
            // movieIDDataGridViewTextBoxColumn
            // 
            this.movieIDDataGridViewTextBoxColumn.DataPropertyName = "Movie_ID";
            this.movieIDDataGridViewTextBoxColumn.HeaderText = "Movie_ID";
            this.movieIDDataGridViewTextBoxColumn.Name = "movieIDDataGridViewTextBoxColumn";
            // 
            // moviesBindingSource
            // 
            this.moviesBindingSource.DataMember = "Movies";
            this.moviesBindingSource.DataSource = this.base1DataSet;
            // 
            // base1DataSet
            // 
            this.base1DataSet.DataSetName = "Base1DataSet";
            this.base1DataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // moviesTableAdapter
            // 
            this.moviesTableAdapter.ClearBeforeFill = true;
            // 
            // dataGridView2
            // 
            this.dataGridView2.AutoGenerateColumns = false;
            this.dataGridView2.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView2.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.кодDataGridViewTextBoxColumn,
            this.userDataGridViewTextBoxColumn,
            this.movieDataGridViewTextBoxColumn});
            this.dataGridView2.DataSource = this.moviesUsersBindingSource2;
            this.dataGridView2.Location = new System.Drawing.Point(469, 13);
            this.dataGridView2.Name = "dataGridView2";
            this.dataGridView2.Size = new System.Drawing.Size(453, 150);
            this.dataGridView2.TabIndex = 1;
            // 
            // кодDataGridViewTextBoxColumn
            // 
            this.кодDataGridViewTextBoxColumn.DataPropertyName = "Код";
            this.кодDataGridViewTextBoxColumn.HeaderText = "Код";
            this.кодDataGridViewTextBoxColumn.Name = "кодDataGridViewTextBoxColumn";
            // 
            // userDataGridViewTextBoxColumn
            // 
            this.userDataGridViewTextBoxColumn.DataPropertyName = "User";
            this.userDataGridViewTextBoxColumn.HeaderText = "User";
            this.userDataGridViewTextBoxColumn.Name = "userDataGridViewTextBoxColumn";
            // 
            // movieDataGridViewTextBoxColumn
            // 
            this.movieDataGridViewTextBoxColumn.DataPropertyName = "Movie";
            this.movieDataGridViewTextBoxColumn.HeaderText = "Movie";
            this.movieDataGridViewTextBoxColumn.Name = "movieDataGridViewTextBoxColumn";
            // 
            // moviesUsersBindingSource
            // 
            this.moviesUsersBindingSource.DataMember = "MoviesUsers";
            this.moviesUsersBindingSource.DataSource = this.base1DataSet;
            // 
            // moviesMoviesUsersBindingSource
            // 
            this.moviesMoviesUsersBindingSource.DataMember = "MoviesMoviesUsers";
            this.moviesMoviesUsersBindingSource.DataSource = this.moviesBindingSource;
            // 
            // moviesUsersTableAdapter
            // 
            this.moviesUsersTableAdapter.ClearBeforeFill = true;
            // 
            // dataGridView3
            // 
            this.dataGridView3.AutoGenerateColumns = false;
            this.dataGridView3.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView3.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.фамилияDataGridViewTextBoxColumn,
            this.имяDataGridViewTextBoxColumn,
            this.телефонDataGridViewTextBoxColumn,
            this.userIDDataGridViewTextBoxColumn});
            this.dataGridView3.DataSource = this.пользователиBindingSource;
            this.dataGridView3.Location = new System.Drawing.Point(13, 170);
            this.dataGridView3.Name = "dataGridView3";
            this.dataGridView3.Size = new System.Drawing.Size(449, 150);
            this.dataGridView3.TabIndex = 2;
            // 
            // фамилияDataGridViewTextBoxColumn
            // 
            this.фамилияDataGridViewTextBoxColumn.DataPropertyName = "Фамилия";
            this.фамилияDataGridViewTextBoxColumn.HeaderText = "Фамилия";
            this.фамилияDataGridViewTextBoxColumn.Name = "фамилияDataGridViewTextBoxColumn";
            // 
            // имяDataGridViewTextBoxColumn
            // 
            this.имяDataGridViewTextBoxColumn.DataPropertyName = "Имя";
            this.имяDataGridViewTextBoxColumn.HeaderText = "Имя";
            this.имяDataGridViewTextBoxColumn.Name = "имяDataGridViewTextBoxColumn";
            // 
            // телефонDataGridViewTextBoxColumn
            // 
            this.телефонDataGridViewTextBoxColumn.DataPropertyName = "Телефон";
            this.телефонDataGridViewTextBoxColumn.HeaderText = "Телефон";
            this.телефонDataGridViewTextBoxColumn.Name = "телефонDataGridViewTextBoxColumn";
            // 
            // userIDDataGridViewTextBoxColumn
            // 
            this.userIDDataGridViewTextBoxColumn.DataPropertyName = "User_ID";
            this.userIDDataGridViewTextBoxColumn.HeaderText = "User_ID";
            this.userIDDataGridViewTextBoxColumn.Name = "userIDDataGridViewTextBoxColumn";
            // 
            // пользователиBindingSource
            // 
            this.пользователиBindingSource.DataMember = "Пользователи";
            this.пользователиBindingSource.DataSource = this.base1DataSet;
            // 
            // пользователиTableAdapter
            // 
            this.пользователиTableAdapter.ClearBeforeFill = true;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(505, 297);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 3;
            this.button1.Text = "Add";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // textBox2
            // 
            this.textBox2.Location = new System.Drawing.Point(606, 191);
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(100, 20);
            this.textBox2.TabIndex = 5;
            // 
            // textBox3
            // 
            this.textBox3.Location = new System.Drawing.Point(606, 217);
            this.textBox3.Name = "textBox3";
            this.textBox3.Size = new System.Drawing.Size(100, 20);
            this.textBox3.TabIndex = 6;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(519, 194);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(40, 13);
            this.label2.TabIndex = 8;
            this.label2.Text = "UserID";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(519, 220);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(47, 13);
            this.label3.TabIndex = 9;
            this.label3.Text = "MovieID";
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(505, 327);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(75, 23);
            this.button2.TabIndex = 10;
            this.button2.Text = "Составить письмо";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(13, 329);
            this.textBox1.Multiline = true;
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(449, 208);
            this.textBox1.TabIndex = 11;
            // 
            // moviesUsersBindingSource1
            // 
            this.moviesUsersBindingSource1.DataMember = "MoviesUsers";
            this.moviesUsersBindingSource1.DataSource = this.base1DataSet;
            // 
            // moviesUsersBindingSource2
            // 
            this.moviesUsersBindingSource2.DataMember = "MoviesUsers";
            this.moviesUsersBindingSource2.DataSource = this.base1DataSet;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(934, 565);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.textBox3);
            this.Controls.Add(this.textBox2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.dataGridView3);
            this.Controls.Add(this.dataGridView2);
            this.Controls.Add(this.dataGridView1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.moviesBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.base1DataSet)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.moviesUsersBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.moviesMoviesUsersBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView3)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.пользователиBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.moviesUsersBindingSource1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.moviesUsersBindingSource2)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView dataGridView1;
        private Base1DataSet base1DataSet;
        private System.Windows.Forms.BindingSource moviesBindingSource;
        private Base1DataSetTableAdapters.MoviesTableAdapter moviesTableAdapter;
        private System.Windows.Forms.DataGridViewTextBoxColumn названиеФильмаDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn годВыходаDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn длительностьDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn movieIDDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridView dataGridView2;
        private System.Windows.Forms.BindingSource moviesMoviesUsersBindingSource;
        private Base1DataSetTableAdapters.MoviesUsersTableAdapter moviesUsersTableAdapter;
        private System.Windows.Forms.DataGridViewTextBoxColumn кодDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn userDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn movieDataGridViewTextBoxColumn;
        private System.Windows.Forms.BindingSource moviesUsersBindingSource;
        private System.Windows.Forms.DataGridView dataGridView3;
        private System.Windows.Forms.BindingSource пользователиBindingSource;
        private Base1DataSetTableAdapters.ПользователиTableAdapter пользователиTableAdapter;
        private System.Windows.Forms.DataGridViewTextBoxColumn фамилияDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn имяDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn телефонDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn userIDDataGridViewTextBoxColumn;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.TextBox textBox3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.BindingSource moviesUsersBindingSource2;
        private System.Windows.Forms.BindingSource moviesUsersBindingSource1;
    }
}

