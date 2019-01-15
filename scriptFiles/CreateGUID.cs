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

namespace CreateGUID
{
    public class Program
    {
        public static void Main(string[] args)
        {
            Console.Title =  // Edit title
                "CreateGUID";

            Console.InputEncoding = Encoding.UTF8;  // Edit encoding
            Console.OutputEncoding = Encoding.UTF8;

            Guid g = Guid.NewGuid();  //  New GUID
            Console.WriteLine("D: {0}", g.ToString("D"));  // Output GUID
            Console.WriteLine("N: {0}", g.ToString("N"));
            Console.WriteLine("P: {0}", g.ToString("P"));
            Console.WriteLine("B: {0}", g.ToString("B"));
            Console.WriteLine("X: {0}", g.ToString("X"));

            Console.Read();

            Environment.Exit(Environment.ExitCode);  // Exit Program
        }
    }
}