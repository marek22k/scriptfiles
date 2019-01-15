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
using System.IO.Compression;

namespace ZipExtract
{
    class Program
    {
        static void Main(string[] args)
        {
            // Set settings for console
            Console.Title = "ZipExtract";
            Console.InputEncoding = Encoding.UTF8;
            Console.OutputEncoding = Encoding.UTF8;

            try
            {
                // Extract folders
                string extractFolder = @"extract\\";
                if (Directory.Exists(extractFolder) == true)
                {
                    Directory.Delete(extractFolder, true);
                }

                for (int i = 0; i <= (args.Length-1); i++)
                {
                    string endExtractFolder = extractFolder + (string)i.ToString();
                    Console.WriteLine("Extract zip...");
                    ZipFile.ExtractToDirectory(args[i], endExtractFolder);
                }

            } catch(Exception e)
            {
                // Except
                Console.WriteLine((string)"Error: " + e.ToString());
            }

            // End application
            Console.WriteLine("\nEnd");
        }
    }
}
