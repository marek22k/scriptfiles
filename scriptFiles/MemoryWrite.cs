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
using System.IO;

namespace MemoryWrite
{
    class Program
    {
        public static void Main(string[] args)
        {
            try
            {
                Console.Title = "MemoryWrite";
                Console.InputEncoding = Encoding.UTF8;
                Console.OutputEncoding = Encoding.UTF8;

                for (int r = 0; r <= (args.Length - 1); r++)
                {
                    string file = args[r];
                    if (File.Exists(file) == true)
                    {
                        MemoryStream ms = new MemoryStream();

                        string wri = File.ReadAllText(file, Encoding.UTF8);
                        ms.Write(Encoding.UTF8.GetBytes(wri), 0, wri.Length);

                        string str = "";
                        for (int i = 0; i <= (wri.Length - 1); i++)
                        {
                            Console.Clear();
                            Console.WriteLine(i.ToString() + "/" + wri.Length);
                            ms.Write(Encoding.UTF8.GetBytes(i.ToString()), 0, i.ToString().Length);
                            char wir = Convert.ToBase64String(ms.ToArray())[i];
                            str += wir.ToString();
                        }

                        int op = wri.Length;
                        Console.Clear();
                        Console.WriteLine("{0}/{0}", op);
                        File.WriteAllText(file, str);
                        ms.Flush();
                        ms.Close();
                    }
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e.ToString());
            }
        }
    }
}