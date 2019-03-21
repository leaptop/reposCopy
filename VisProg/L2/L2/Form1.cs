using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Drawing.Imaging;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace L2
{
    public partial class Form1 : Form
    {

        int historyCounter;
        bool drawing;
        GraphicsPath currentPath;
        GraphicsPath currentPath2;
        Point oldLocation;
        public Pen currentPen;
        Color historyColor = Color.Cyan;//Сохранение текущего цвета перед исапользованием ластика
        List<Image> History; // Список для истории

        private void myPictureBox_MouseDown(object sender, MouseEventArgs e)
        {

            if (pictureBox1.Image == null)
            {
                MessageBox.Show("Сначала создайте новый файл!");
                return;
            } currentPath = new GraphicsPath();
            if (e.Button == MouseButtons.Left)
            {
                //currentPen.Color = historyColor;
                drawing = true;
                currentPen.Color = historyColor;
                oldLocation = e.Location;
                
                
            } else if(e.Button == MouseButtons.Right)
            {
                historyColor = currentPen.Color;
                drawing = true;
                oldLocation = e.Location;
               // currentPath = new GraphicsPath();
                
                currentPen.Color = Color.White;
            }
            
        }
        private void myPictureBox_MouseUp(object sender, MouseEventArgs e)
        {
            drawing = false;
           
            try
            {
                currentPath.Dispose();

            }
            catch { };
            currentPen.Color = historyColor;
        }
        private void myPictureBox_MouseMove(object sender, MouseEventArgs e)
        {
            if (drawing)
            {
                Graphics g = Graphics.FromImage(pictureBox1.Image);
                currentPath.AddLine(oldLocation, e.Location);
                g.DrawPath(currentPen, currentPath);
                oldLocation = e.Location;
                g.Dispose();
                pictureBox1.Invalidate();
                label1.Text = e.X.ToString() + ", " + e.Y.ToString();
            }
        }
        public Form1()
        {
            InitializeComponent();
            drawing = false;

            // pictureBox1.MouseDown += new MouseEventHandler(pictureBox1_MouseDown);// не нашёл MouseDown в событиях, поэтому пришлось это прописывать
            pictureBox1.MouseDown += new MouseEventHandler(myPictureBox_MouseDown);
            pictureBox1.MouseUp += new MouseEventHandler(myPictureBox_MouseUp);
            pictureBox1.MouseMove += new MouseEventHandler(myPictureBox_MouseMove);
            currentPen = new Pen(Color.Black);
            currentPen.Width = trackBar1.Value;// pen's width initialization
            History = new List<Image>();// инициализация списка для истории

        }

        private void toolStrip1_ItemClicked(object sender, ToolStripItemClickedEventArgs e)
        {

        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void toolStripContainer1_ContentPanel_Load(object sender, EventArgs e)
        {

        }

        private void newToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Bitmap pic = new Bitmap(693, 371);
            pictureBox1.Image = pic;// не смог переименовать в picDrawingSurface в свойствах(Name)

            if (pictureBox1.Image != null)
            {
                var result = MessageBox.Show("Сохранить текущее изображение перед созданием нового рисунка?",
                    "Предупреждение", MessageBoxButtons.YesNoCancel);
                switch (result)
                {
                    case DialogResult.No: break;
                    case DialogResult.Yes: saveToolStripMenuItem_Click(sender, e); break;
                    case DialogResult.Cancel: return;
                }
            }
        }

        private void styleToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void toolStripComboBox1_Click(object sender, EventArgs e)
        {

        }

        private void toolStrip1_ItemClicked_1(object sender, ToolStripItemClickedEventArgs e)
        {

        }

        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {
            OpenFileDialog OP = new OpenFileDialog();
            OP.Filter = "JPEG Image|*.jpg|Bitmap Image|*.bmp|GIF Image|*.gif|PNG Image|*.png";
            OP.Title = "Open an Image File";
            OP.FilterIndex = 1;//По умолчанию будет выбрано перове расширение *.jpg

            if (OP.ShowDialog() != DialogResult.Cancel)
                pictureBox1.Load(OP.FileName);
            pictureBox1.AutoSize = true;
        }

        private void saveToolStripMenuItem_Click(object sender, EventArgs e)
        {
            SaveFileDialog SaveDlg = new SaveFileDialog();
            SaveDlg.Filter = "JPEG Image|*.jpg|Bitmap Image|*.bmp|GIF Image|*.gif|PNG Image|*.png";
            SaveDlg.Title = "Save an Image File";
            SaveDlg.FilterIndex = 4;// по умолчанию будет выбрано последнее расширение *.png
            SaveDlg.ShowDialog();
            if (SaveDlg.FileName != "")
            {
                System.IO.FileStream fs = (System.IO.FileStream)SaveDlg.OpenFile();

                switch (SaveDlg.FilterIndex)
                {
                    case 1:
                        this.pictureBox1.Image.Save(fs, ImageFormat.Jpeg);
                        break;
                    case 2:
                        this.pictureBox1.Image.Save(fs, ImageFormat.Bmp);
                        break;
                    case 3:
                        this.pictureBox1.Image.Save(fs, ImageFormat.Gif);
                        break;
                    case 4:
                        this.pictureBox1.Image.Save(fs, ImageFormat.Png);
                        break;
                }
                fs.Close();
            }

        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void menuStrip1_ItemClicked(object sender, ToolStripItemClickedEventArgs e)
        {

        }

        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Сделано Степаном Алексеевым\nНу что, порисуем?");
        }

        private void pictureBox1_Click_1(object sender, EventArgs e)
        {

        }

        private void trackBar1_Scroll(object sender, EventArgs e)
        {
            currentPen.Width = trackBar1.Value;
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }


    }
}
