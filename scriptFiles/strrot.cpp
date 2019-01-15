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

#include <iostream>  /* cout, cin */
#include <string>  /* string */

#include <cstdlib>  /* abort, EXIT_SUCCESS */

using namespace std;

inline string strrotationrec(string str, unsigned n) noexcept
{
    return n?strrotationrec(str[str.length()-1] + str.substr(0, str.length()-1), n - 1):str;
}

inline string strrotation(string str, unsigned n) noexcept
{
    string res = str;

    for(unsigned i = 0; i < n; i++)
        res = res[res.length()-1] + res.substr(0, res.length()-1);

    return res;
}

int main()
{
    string str;

    cout << "String: ";
    cin >> str;
    if(cin.fail() || str == "") abort();

    unsigned n = static_cast<unsigned>(-1);
    cout << "Rotation: ";
    cin >> n;
    if(cin.fail() || n == static_cast<unsigned>(-1)) abort();

    cout << "Result: " << (str.length()<64?strrotationrec(str, n):strrotation(str, n));

    return EXIT_SUCCESS;
}
