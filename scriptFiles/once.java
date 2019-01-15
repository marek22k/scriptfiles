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

package once;

import javax.swing.JOptionPane;

public class once {
	public static void main(String[] args){
		String op = "";
		int f = Integer.parseInt(JOptionPane.showInputDialog(null,"From:", "Input dialog",JOptionPane.PLAIN_MESSAGE));  // From ( example 1 )
		int to = Integer.parseInt(JOptionPane.showInputDialog(null,"To:", "Input dialog",JOptionPane.PLAIN_MESSAGE));  // To   ( example 10)
		for(int i=f/* Set i = f ( example 1 ) */; i<(to+1)/* Calculator plus 1 */; i++/* Next i += +1 */){
			for(int b=f; b<(to+1); b++){
				int o = i*b;
				String s = i + "*" + b + "=" + o + "   ";
				op += s;
			}
			op += "\n";
		}
		JOptionPane.showMessageDialog(null, op, "Once", JOptionPane.PLAIN_MESSAGE);  // Output once
		System.exit(0);  // Quit from the application
	}
}
