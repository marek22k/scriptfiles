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
using System.Security.Cryptography;

namespace AESsaveConsole
{
    class Program
    {
        // Protected sub for Encrypt with AES
        protected static string Encrypt(string content, string salt, string passwd, int bits)
        {
            AesManaged AES = new AesManaged();
            Rfc2898DeriveBytes rfc = new Rfc2898DeriveBytes(passwd, Encoding.UTF8.GetBytes(salt));
            Byte[] Data = Encoding.UTF8.GetBytes(content);

            AES.BlockSize = 128;
            AES.KeySize = bits;
            AES.Key = rfc.GetBytes(AES.KeySize / 8);
            AES.IV = rfc.GetBytes(AES.BlockSize / 8);

            MemoryStream ms = new MemoryStream();
            CryptoStream cs = new CryptoStream(ms, AES.CreateEncryptor(), CryptoStreamMode.Write);
            cs.Write(Data, 0, Data.Length);
            cs.FlushFinalBlock();
            cs.Close();

            return Convert.ToBase64String(ms.ToArray());

            ms.Close();
            AES.Clear();
        }


        // Protected sub for Decrypt with AES
        protected static string Decrypt(string card, string salt, string passwd, int bits)
        {
            AesManaged AES = new AesManaged();
            Rfc2898DeriveBytes rfc = new Rfc2898DeriveBytes(passwd, Encoding.UTF8.GetBytes(salt));
            Byte[] Data = Convert.FromBase64String(card);

            AES.BlockSize = 128;
            AES.KeySize = bits;
            AES.Key = rfc.GetBytes(AES.KeySize / 8);
            AES.IV = rfc.GetBytes(AES.BlockSize / 8);

            MemoryStream ms = new MemoryStream();
            CryptoStream cs = new CryptoStream(ms, AES.CreateDecryptor(), CryptoStreamMode.Write);
            cs.Write(Data, 0, Data.Length);
            cs.FlushFinalBlock();
            cs.Close();

            return (string)Encoding.UTF8.GetString(ms.ToArray());

            ms.Close();
            AES.Clear();
        }

        static void Main(string[] args)
        {
            try
            {
                string a1 = "";
                for(int i = 4; i <= (args.Length-1); i++)
                {
                    a1 += args[i] + " ";
                }
                if (args[0] == "encrypt")
                {
                    Console.WriteLine("Result: " + Encrypt(a1, args[1], args[2], (int)Int32.Parse(args[3])));
                }else if(args[0] == "decrypt")
                {
                    Console.WriteLine("Result: " + Decrypt(a1, args[1], args[2], (int)Int32.Parse(args[3])));
                }
            } catch(Exception e)
            {
                Console.WriteLine("Error: " + e.ToString());
            }
        }
    }
}
