using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace L06DataBase
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'continentsDataSet.Countries' table. You can move, or remove it, as needed.
            this.countriesTableAdapter.Fill(this.continentsDataSet.Countries);

        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.countriesTableAdapter.Z2(this.continentsDataSet.Countries, "Северная Америка");
        }
    }
}
