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

#include <iostream>  /* cout, cin, flush */
#include <iomanip>  /* setw */
#include <functional>  /* function */

#include <cstdlib>  /* abort, EXIT_SUCCESS */

using namespace std;

void drawTrue(string, string, function<bool(bool, bool)>);

int main()
{
    short sel = 0;
    cout << "1: Draw truth table; 2: Solve a custom task: " << flush;
    cin >> sel;

    if(cin.fail() || sel == 0)
        abort();

    cout << endl;

    if(sel == 1)
    {
        drawTrue("|", "OR", [] (bool a, bool b) {return (a || b);});
        drawTrue("&", "AND", [] (bool a, bool b) {return (a && b);});
        drawTrue("^", "XOR", [] (bool a, bool b) {return (a ^ b);});
        drawTrue("!|", "NOR", [] (bool a, bool b) {return !(a || b);});
        drawTrue("!&", "NAND", [] (bool a, bool b) {return !(a && b);});
        drawTrue("!^", "NXOR", [] (bool a, bool b) {return !(a ^ b);});
        drawTrue("<=>", "EQU", [] (bool a, bool b) {return (a == b);});
        drawTrue("->", "IMP", [] (bool a, bool b) {return (!a || b);});
    }
    else if(sel == 2)
    {
        bool b1, b2;

        cout << "First boolean(0; 1): " << flush;
        cin >> b1;
        cout << "Second boolean(0; 1): " << flush;
        cin >> b2;

        cout << "NOT  :\t~ " << b1 << "     = " << !b1 << endl;
        cout << "NOT  :\t~ " << b2 << "     = " << !b2 << endl;

        cout << "AND  :\t" << b1 << " & " << b2 << "   = " << (b1 && b2) << endl;
        cout << "OR   :\t" << b1 << " | " << b2 << "   = " << (b1 || b2) << endl;
        cout << "XOR  :\t" << b1 << " ^ " << b2 << "   = " << (b1 ^ b2) << endl;

        cout << "NAND :\t" << b1 << " !& " << b2 << "  = " << !(b1 && b2) << endl;
        cout << "NOR  :\t" << b1 << " !| " << b2 << "  = " << !(b1 || b2) << endl;
        cout << "NXOR :\t" << b1 << " !^ " << b2 << "  = " << !(b1 ^ b2) << endl;

        cout << "EQU  :\t" << b1 << " <=> " << b2 << " = " << (b1 == b2) << endl;
        cout << "IMP  :\t" << b1 << " -> " << b2 << "  = " << (!b1 | b2) << endl;
    }

    return EXIT_SUCCESS;
}

void drawTrue(string oper, string lonoper, function<bool(bool, bool)> calc)
{
    cout << " " << setw(5) << lonoper << setw(0) << " | a | b | a " << oper << " b" << endl;
    cout << "       | 0 | 0 |   " << calc(0, 0) << endl;
    cout << "       | 0 | 1 |   " << calc(0, 1) << endl;
    cout << "       | 1 | 0 |   " << calc(1, 0) << endl;
    cout << "       | 1 | 1 |   " << calc(1, 1) << endl << endl;
}
