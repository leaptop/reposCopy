using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace RGR05
{
    public partial class Form3 : Form
    {
        public Form3()
        {
            InitializeComponent();
        }

        private void Form3_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'Base1DataSet.MoviesUsers' table. You can move, or remove it, as needed.
            this.MoviesUsersTableAdapter.Fill(this.Base1DataSet.MoviesUsers);
            // TODO: This line of code loads data into the 'Base1DataSet.Пользователи' table. You can move, or remove it, as needed.
            this.ПользователиTableAdapter.Fill(this.Base1DataSet.Пользователи);

            this.reportViewer1.RefreshReport();
        }
    }
}
