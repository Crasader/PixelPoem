using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PixelPoemGenerator
{
    public partial class Form1 : Form
    {
        /// <summary>
        /// 
        /// </summary>
        private string _bmpFileFullPath;

        /// <summary>
        /// 
        /// </summary>
        private bool _hasInitialized;

        private Button[,] button;

        private int imageWidth = 0;
        private int imageHeight = 0;
            
        public Form1()
        {
            InitializeComponent();

            _hasInitialized = false;
        }

        private void initializeUI()
        {
            fileInfoTxt.Clear();
            this.mainPanel.Controls.Clear();
            
            // Read BMP File

            BinaryReader br;
            int tempInt;
            char tempChar;
            short tempShort;

            int dataOffset = 0;

            int colorTableSize = 0;
            int[] colorTable;


            //reading from the file
            try
            {
                br = new BinaryReader(new FileStream(_bmpFileFullPath, FileMode.Open));
                // br = new BinaryReader(new FileStream(@"D:\Toney\SharedFolder\Temp\test.bmp", FileMode.Open));
            }
            catch (IOException e)
            {
                Console.WriteLine(e.Message + "\n Cannot open file.");
                return;
            }

            byte red, blue, green;
            int lineCount = 0;
            int pixelCount = 0;

            try
            {
                tempShort = br.ReadInt16();
                tempInt = br.ReadInt32();
                tempShort = br.ReadInt16();
                tempShort = br.ReadInt16();
                tempInt = br.ReadInt32();
                dataOffset = tempInt;
                fileInfoTxt.AppendText(string.Format("Offset: {0}\r\n", tempInt));

                tempInt = br.ReadInt32();

                tempInt = br.ReadInt32();
                imageWidth = tempInt;
                fileInfoTxt.AppendText(string.Format("Width: {0}\r\n", tempInt));

                tempInt = br.ReadInt32();
                imageHeight = tempInt;
                fileInfoTxt.AppendText(string.Format("Height: {0}\r\n", tempInt));

                tempShort = br.ReadInt16();

                tempShort = br.ReadInt16();
                fileInfoTxt.AppendText(string.Format("Bits Per Pixel: {0}\r\n", tempShort));

                tempInt = br.ReadInt32();
                fileInfoTxt.AppendText(string.Format("Compression Type: {0}\r\n", tempInt));

                tempInt = br.ReadInt32();
                fileInfoTxt.AppendText(string.Format("Data Size: {0}\r\n", tempInt));

                tempInt = br.ReadInt32();
                fileInfoTxt.AppendText(string.Format("X Pixels Per Meter: {0}\r\n", tempInt));

                tempInt = br.ReadInt32();
                fileInfoTxt.AppendText(string.Format("Y Pixels Per Meter: {0}\r\n", tempInt));

                tempInt = br.ReadInt32();
                colorTableSize = tempInt;
                fileInfoTxt.AppendText(string.Format("Colors in Table: {0}\r\n", tempInt));

                tempInt = br.ReadInt32();
                fileInfoTxt.AppendText(string.Format("Important Color Count: {0}\r\n", tempInt));

                /*
                tempInt = br.ReadInt32();
                fileInfoTxt.AppendText(string.Format("Red Bit Mask: {0}\r\n", tempInt));
                tempInt = br.ReadInt32();
                fileInfoTxt.AppendText(string.Format("Blue Bit Mask: {0}\r\n", tempInt));
                tempInt = br.ReadInt32();
                fileInfoTxt.AppendText(string.Format("Green Bit Mask: {0}\r\n", tempInt));
                tempInt = br.ReadInt32();
                fileInfoTxt.AppendText(string.Format("Alpha Bit Mask: {0}\r\n", tempInt));

                tempInt = br.ReadInt32();
                fileInfoTxt.AppendText(string.Format("Color Space Type: {0}\r\n", tempInt));

                tempInt = br.ReadInt32();
                fileInfoTxt.AppendText(string.Format("Color Space Endpoints: {0}\r\n", tempInt));

                tempInt = br.ReadInt32();
                fileInfoTxt.AppendText(string.Format("Gamma for Red Channel: {0}\r\n", tempInt));
                tempInt = br.ReadInt32();
                fileInfoTxt.AppendText(string.Format("Gamma for Blue Channel: {0}\r\n", tempInt));
                tempInt = br.ReadInt32();
                fileInfoTxt.AppendText(string.Format("Gamma for Green Channel: {0}\r\n", tempInt));

                tempInt = br.ReadInt32();
                fileInfoTxt.AppendText(string.Format("Intent: {0}\r\n", tempInt));
                tempInt = br.ReadInt32();
                fileInfoTxt.AppendText(string.Format("ICC Data: {0}\r\n", tempInt));
                tempInt = br.ReadInt32();
                fileInfoTxt.AppendText(string.Format("ICC Size: {0}\r\n", tempInt));
                tempInt = br.ReadInt32();
                fileInfoTxt.AppendText(string.Format("Reserved: {0}\r\n", tempInt));
                */


                // Start Reading Data:
                // br.BaseStream.Seek(dataOffset, SeekOrigin.Begin);

                button = new Button[imageWidth,imageHeight];

                int bytesPerRow = (imageWidth * 3 - 1) / 4 * 4 + 4;
                int fill = bytesPerRow - (imageWidth * 3);

                for (int j = imageHeight - 1; j >= 0; j--)
                {
                    for (int i = 0; i < imageWidth; i++)
                    {
                        blue = br.ReadByte();
                        green = br.ReadByte();
                        red = br.ReadByte();

                        bool isBlack = (red < 128) || (green < 128) || (blue < 128);

                        Button btn = new Button();
                        btn.Height = 20;
                        btn.Width = 20;
                        btn.Left = i * 20;
                        btn.Top = j * 20;
                        btn.BackColor = (isBlack) ? Color.Black : Color.White;
                        this.mainPanel.Controls.Add(btn);
                        button[i, j] = btn;
                    }

                    for (int i = 0;  i < fill; i++)
                    {
                        br.ReadByte();
                    }
                }
            }
            catch (IOException e)
            {
                Console.WriteLine(e.Message + "\n Cannot read from file.");
                return;
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
                return;
            }
            finally
            {
                br.Close();
            }

            _hasInitialized = true;
        }

        private void filesToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void openBMPFileToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (openFileDialog1.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                _bmpFileFullPath = openFileDialog1.FileName;
                initializeUI();
            }

        }

        private void fileInfoView_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void saveToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (saveFileDialog1.ShowDialog() != System.Windows.Forms.DialogResult.OK || !_hasInitialized)
            {
                return;
            }

            BinaryWriter writer = new BinaryWriter(new FileStream(saveFileDialog1.FileName, FileMode.Create));
            writer.Write(imageWidth);
            writer.Write(imageHeight);


            for (int j = 0; j < imageHeight; j++ )
            {
                for (int i = 0; i < imageWidth; i++)
                {
                    if (button[i,j].BackColor == Color.Black)
                    {
                        writer.Write((byte)0);
                        writer.Write((byte)0);
                        writer.Write((byte)0);
                    }
                    else
                    {
                        writer.Write((byte)255);
                        writer.Write((byte)255);
                        writer.Write((byte)255);
                    }

                }
            }
            writer.Close();

            MessageBox.Show("File has been saved.");
        }
    }
}
