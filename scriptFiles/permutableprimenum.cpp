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

#include <iostream>  /* cout, cin, endl */
#include <string>  /* string, to_string, stoul */

#include <cstdlib>  /* abort, EXIT_SUCCESS */

using namespace std;

bool isPermutableprime(unsigned x, bool op);

int main()
{
    unsigned x = static_cast<unsigned>(-1);

    cout << "Please enter a number: ";
    cin >> x;

    if(cin.fail() || x == static_cast<unsigned>(-1)) abort();

    cout << endl;
    if(isPermutableprime(x, 1))
        cout << endl << x << " is a permutable prime :-)";
    else
        cout << endl <<  x << " is not a permutable prime :-(";

    return EXIT_SUCCESS;
}

bool isPermutableprime(unsigned x, bool op)
{
    string num = to_string(x);
    unsigned c;

    for(unsigned i = 0; i < num.length(); i++)
    {
        c = static_cast<unsigned>(stoul(num));

        for(unsigned j = 2; j < c; j++)
            if(c % j == 0)
            {
                if(op) cout << c << " is not a Prime" << endl;
                return false;
            }
        if(op) cout << c << " is a Prime" << endl;

        num = num[num.length()-1] + num.substr(0, num.length()-1);
    }

    return true;
}
