using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.OleDb;

namespace RGR05
{
    public partial class Form1 : Form
    {
        private OleDbConnection connection = new OleDbConnection();
        public Form1()
        {
            InitializeComponent();
            connection.ConnectionString = @"Provider=Microsoft.ACE.OLEDB.12.0;Data Source=C:\Users\Stepan\source\repos\VisProg\RGR05\RGR05\Base1.accdb; Persist Security Info=False;";
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'base1DataSet.Пользователи' table. You can move, or remove it, as needed.
            this.пользователиTableAdapter.Fill(this.base1DataSet.Пользователи);
            // TODO: This line of code loads data into the 'base1DataSet.MoviesUsers' table. You can move, or remove it, as needed.
            this.moviesUsersTableAdapter.Fill(this.base1DataSet.MoviesUsers);
            // TODO: This line of code loads data into the 'base1DataSet.Movies' table. You can move, or remove it, as needed.
            this.moviesTableAdapter.Fill(this.base1DataSet.Movies);

        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                connection.Open();
                OleDbCommand command = new OleDbCommand();
                command.Connection = connection;
                //command.CommandText = "insert into MoviesUsers (Код, User, Movie) values('" + 10 + "','" + textBox2.Text + "','" + textBox3.Text + "')";
                //command.CommandText = "insert into MoviesUsers (User, Movie) values('" + textBox2.Text + "','" + textBox3.Text + "')";
                command.CommandText = "INSERT INTO [MoviesUsers] ([User], [Movie]) VALUES('" + Convert.ToDecimal(textBox2.Text) + "','" + Convert.ToDecimal(textBox3.Text) + "')";
                command.ExecuteNonQuery();
                MessageBox.Show("Data Saved");
                // OleDbDataReader reader = command.ExecuteReader();//for reading(for SELECT)}

            }
            catch (Exception ex)
            {
                MessageBox.Show("Error " + ex);
            }
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }
    }
}
