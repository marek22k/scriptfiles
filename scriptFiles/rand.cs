using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace rand
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int randomNumber = 0;  // Set var randomNumber
            Random MyRandom = new Random();  // Set a new Random object
            randomNumber = MyRandom.Next(9);  // Get a random number
            textBox1.Text = (string) Convert.ToString(randomNumber);  // Show the random number
        }

        private void button2_Click(object sender, EventArgs e)
        {
            string symbols = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";  // Symbols for random password
            string passwd = "";  // Set var passwd for the random password

            Random MyRandomObject = new Random();  // A new Random object

            for(int i = 0; i < 7; i++)  // Get symbols for the password
            {
                passwd += symbols[MyRandomObject.Next(symbols.Length)];  // Get random symbol
            }

            textBox2.Text = passwd;  // Show random symbol
        }
    }
}
