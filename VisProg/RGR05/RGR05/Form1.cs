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
                command.Dispose();

                //как обновить инфу сразу после добавления? Вот это:                
                this.moviesUsersTableAdapter.Fill(this.base1DataSet.MoviesUsers);
                //не работает
                //Как выводить названия вместо айдишников в MoviesUsers?
                // как сохранять БД в аксесе, чтобы это стало видно в Вижуал Студио?(при изменении структуры БД)

                // OleDbDataReader reader = command.ExecuteReader();//for reading(for SELECT)}
                connection.Close();
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error " + ex);
                connection.Close();
            }
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            int row = dataGridView3.SelectedCells[0].RowIndex;

            string film = dataGridView1.Rows[row].Cells[0].Value.ToString();

            //DateTime date = (DateTime)dataGridView1.Rows[row].Cells[1].Value;

            string first_name = dataGridView3.Rows[row].Cells[0].Value.ToString();
            string second_name = dataGridView3.Rows[row].Cells[1].Value.ToString();
            // string third_name = dataGridView1.Rows[row].Cells[4].Value.ToString();

            //int adr = (int)dataGridView1.Rows[row].Cells[5].Value;
            // string adr1 = this.usersTableAdapter1.ScalarQuery(adr);
            //int m = date.Month - 1;

            //DateTime dt2 = dateTimePicker1.Value.Date;

            textBox1.Text = new string(' ', 100) + "Кому: " + second_name + " " + first_name ;
            textBox1.Text += "\n" + new string(' ', 120);
            textBox1.Text += "\n" + new string(' ', 60) + "Уважаемый " + first_name + " " + second_name + "!";
            textBox1.Text += "\r\n\r\n" + "Убедительно прошу Вас вернуть фильм " + film + ", который Вы взяли ";          
            textBox1.Text += "\r\n\r\n\r\n" + new string(' ', 50) + "Заранее спасибо";
            textBox1.Text += "\r\n\r\n" + new string(' ', 100) + "Подпись" + "\r\n\r\n" + new string(' ', 100) + DateTime.Now.ToString("dd.MM.yyyy") + " г.";
        }
    }
}
