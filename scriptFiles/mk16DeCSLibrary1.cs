// Author: Marek K.

/*

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    Dieses Programm ist Freie Software: Sie koennen es unter den Bedingungen
    der GNU General Public License, wie von der Free Software Foundation,
    Version 3 der Lizenz oder (nach Ihrer Wahl) jeder neueren
    veroeffentlichten Version, weiter verteilen und/oder modifizieren.

    Dieses Programm wird in der Hoffnung bereitgestellt, dass es nuetzlich sein wird, jedoch
    OHNE JEDE GEWAEHR,; sogar ohne die implizite
    Gewaehr der MARKTFAEHIGKEIT oder EIGNUNG FUER EINEN BESTIMMTEN ZWECK.
    Siehe die GNU General Public License fuer weitere Einzelheiten.

    Sie sollten eine Kopie der GNU General Public License zusammen mit diesem
    Programm erhalten haben. Wenn nicht, siehe <http://www.gnu.org/licenses/>.
	
*/

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace mk16DeCSLibrary1
{
    public struct Addition
    {
        public double Result { get; set; }
        public Addition(byte add, byte add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(byte add, char add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(byte add, decimal add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(byte add, double add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(byte add, float add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(byte add, int add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(byte add, long add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(byte add, short add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(byte add, string add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }


        public Addition(char add, byte add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(char add, char add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(char add, decimal add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(char add, double add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(char add, float add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(char add, int add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(char add, long add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(char add, short add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(char add, string add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }

        public Addition(decimal add, byte add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(decimal add, char add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(decimal add, decimal add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(decimal add, double add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(decimal add, float add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(decimal add, int add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(decimal add, long add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(decimal add, short add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(decimal add, string add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }

        public Addition(double add, byte add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(double add, char add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(double add, decimal add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(double add, double add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(double add, float add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(double add, int add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(double add, long add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(double add, short add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(double add, string add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }

        public Addition(float add, byte add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(float add, char add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(float add, decimal add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(float add, double add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(float add, float add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(float add, int add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(float add, long add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(float add, short add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(float add, string add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }

        public Addition(int add, byte add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(int add, char add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(int add, decimal add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(int add, double add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(int add, float add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(int add, int add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(int add, long add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(int add, short add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(int add, string add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }

        public Addition(long add, byte add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(long add, char add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(long add, decimal add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(long add, double add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(long add, float add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(long add, int add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(long add, long add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(long add, short add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(long add, string add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }

        public Addition(short add, byte add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(short add, char add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(short add, decimal add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(short add, double add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(short add, float add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(short add, int add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(short add, long add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(short add, short add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(short add, string add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }

        public Addition(string add, byte add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(string add, char add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(string add, decimal add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(string add, double add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(string add, float add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(string add, int add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(string add, long add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(string add, short add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
        public Addition(string add, string add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) + double.Parse(add2.ToString()));
        }
    }
    public struct Subtraction
    {
        public double Result { get; set; }
        public Subtraction(byte add, byte add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(byte add, char add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(byte add, decimal add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(byte add, double add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(byte add, float add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(byte add, int add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(byte add, long add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(byte add, short add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(byte add, string add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }


        public Subtraction(char add, byte add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(char add, char add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(char add, decimal add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(char add, double add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(char add, float add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(char add, int add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(char add, long add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(char add, short add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(char add, string add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }

        public Subtraction(decimal add, byte add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(decimal add, char add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(decimal add, decimal add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(decimal add, double add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(decimal add, float add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(decimal add, int add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(decimal add, long add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(decimal add, short add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(decimal add, string add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }

        public Subtraction(double add, byte add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(double add, char add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(double add, decimal add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(double add, double add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(double add, float add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(double add, int add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(double add, long add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(double add, short add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(double add, string add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }

        public Subtraction(float add, byte add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(float add, char add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(float add, decimal add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(float add, double add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(float add, float add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(float add, int add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(float add, long add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(float add, short add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(float add, string add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }

        public Subtraction(int add, byte add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(int add, char add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(int add, decimal add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(int add, double add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(int add, float add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(int add, int add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(int add, long add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(int add, short add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(int add, string add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }

        public Subtraction(long add, byte add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(long add, char add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(long add, decimal add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(long add, double add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(long add, float add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(long add, int add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(long add, long add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(long add, short add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(long add, string add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }

        public Subtraction(short add, byte add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(short add, char add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(short add, decimal add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(short add, double add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(short add, float add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(short add, int add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(short add, long add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(short add, short add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(short add, string add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }

        public Subtraction(string add, byte add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(string add, char add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(string add, decimal add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(string add, double add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(string add, float add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(string add, int add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(string add, long add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(string add, short add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
        public Subtraction(string add, string add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) - double.Parse(add2.ToString()));
        }
    }
    public struct Multiplication
    {
        public double Result { get; set; }
        public Multiplication(byte add, byte add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(byte add, char add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(byte add, decimal add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(byte add, double add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(byte add, float add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(byte add, int add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(byte add, long add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(byte add, short add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(byte add, string add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }


        public Multiplication(char add, byte add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(char add, char add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(char add, decimal add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(char add, double add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(char add, float add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(char add, int add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(char add, long add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(char add, short add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(char add, string add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }

        public Multiplication(decimal add, byte add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(decimal add, char add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(decimal add, decimal add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(decimal add, double add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(decimal add, float add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(decimal add, int add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(decimal add, long add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(decimal add, short add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(decimal add, string add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }

        public Multiplication(double add, byte add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(double add, char add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(double add, decimal add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(double add, double add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(double add, float add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(double add, int add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(double add, long add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(double add, short add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(double add, string add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }

        public Multiplication(float add, byte add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(float add, char add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(float add, decimal add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(float add, double add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(float add, float add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(float add, int add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(float add, long add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(float add, short add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(float add, string add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }

        public Multiplication(int add, byte add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(int add, char add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(int add, decimal add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(int add, double add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(int add, float add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(int add, int add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(int add, long add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(int add, short add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(int add, string add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }

        public Multiplication(long add, byte add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(long add, char add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(long add, decimal add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(long add, double add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(long add, float add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(long add, int add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(long add, long add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(long add, short add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(long add, string add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }

        public Multiplication(short add, byte add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(short add, char add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(short add, decimal add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(short add, double add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(short add, float add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(short add, int add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(short add, long add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(short add, short add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(short add, string add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }

        public Multiplication(string add, byte add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(string add, char add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(string add, decimal add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(string add, double add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(string add, float add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(string add, int add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(string add, long add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(string add, short add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Multiplication(string add, string add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
    }
    public struct Division
    {
        public double Result { get; set; }
        public Division(byte add, byte add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(byte add, char add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(byte add, decimal add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(byte add, double add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(byte add, float add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(byte add, int add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(byte add, long add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(byte add, short add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(byte add, string add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }


        public Division(char add, byte add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(char add, char add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(char add, decimal add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(char add, double add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(char add, float add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(char add, int add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(char add, long add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(char add, short add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(char add, string add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }

        public Division(decimal add, byte add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(decimal add, char add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(decimal add, decimal add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(decimal add, double add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(decimal add, float add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(decimal add, int add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(decimal add, long add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(decimal add, short add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(decimal add, string add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }

        public Division(double add, byte add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(double add, char add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(double add, decimal add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(double add, double add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(double add, float add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(double add, int add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(double add, long add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(double add, short add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(double add, string add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }

        public Division(float add, byte add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(float add, char add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(float add, decimal add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(float add, double add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(float add, float add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(float add, int add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(float add, long add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(float add, short add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(float add, string add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }

        public Division(int add, byte add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(int add, char add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(int add, decimal add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(int add, double add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(int add, float add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(int add, int add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(int add, long add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(int add, short add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(int add, string add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }

        public Division(long add, byte add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(long add, char add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(long add, decimal add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(long add, double add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(long add, float add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(long add, int add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(long add, long add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(long add, short add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(long add, string add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }

        public Division(short add, byte add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(short add, char add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(short add, decimal add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(short add, double add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(short add, float add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(short add, int add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(short add, long add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(short add, short add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(short add, string add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }

        public Division(string add, byte add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(string add, char add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(string add, decimal add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(string add, double add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(string add, float add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(string add, int add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(string add, long add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(string add, short add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
        public Division(string add, string add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) * double.Parse(add2.ToString()));
        }
    }
    public struct Modulo
    {
        public double Result { get; set; }
        public Modulo(byte add, byte add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(byte add, char add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(byte add, decimal add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(byte add, double add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(byte add, float add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(byte add, int add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(byte add, long add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(byte add, short add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(byte add, string add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }


        public Modulo(char add, byte add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(char add, char add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(char add, decimal add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(char add, double add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(char add, float add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(char add, int add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(char add, long add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(char add, short add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(char add, string add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }

        public Modulo(decimal add, byte add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(decimal add, char add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(decimal add, decimal add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(decimal add, double add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(decimal add, float add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(decimal add, int add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(decimal add, long add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(decimal add, short add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(decimal add, string add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }

        public Modulo(double add, byte add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(double add, char add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(double add, decimal add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(double add, double add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(double add, float add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(double add, int add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(double add, long add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(double add, short add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(double add, string add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }

        public Modulo(float add, byte add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(float add, char add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(float add, decimal add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(float add, double add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(float add, float add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(float add, int add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(float add, long add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(float add, short add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(float add, string add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }

        public Modulo(int add, byte add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(int add, char add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(int add, decimal add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(int add, double add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(int add, float add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(int add, int add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(int add, long add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(int add, short add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(int add, string add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }

        public Modulo(long add, byte add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(long add, char add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(long add, decimal add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(long add, double add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(long add, float add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(long add, int add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(long add, long add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(long add, short add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(long add, string add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }

        public Modulo(short add, byte add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(short add, char add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(short add, decimal add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(short add, double add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(short add, float add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(short add, int add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(short add, long add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(short add, short add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(short add, string add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }

        public Modulo(string add, byte add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(string add, char add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(string add, decimal add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(string add, double add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(string add, float add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(string add, int add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(string add, long add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(string add, short add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
        public Modulo(string add, string add2)
        {
            this.Result = (double)(double.Parse(add.ToString()) % double.Parse(add2.ToString()));
        }
    }
}
