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

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int GetKaprekars(const int num, const bool op);

int main()
{
    int x, res;

    cout << "Please enter a number: ";
    cin >> x;

    res = GetKaprekars(x, true);
    cout << "Kaprekars: " << res << endl;

    return 0;
}

int GetKaprekars(const int num, const bool op)
{
    register int res = num, lres = 0, i1, i2;
    register string s1, s2;

    while(res != lres)
    {
        s1 = to_string(res);
        sort(s1.begin(), s1.end());
        s2 = s1;
        reverse(s2.begin(), s2.end());

        lres = res, i1 = stoi(s1), i2 = stoi(s2);
        if(i1 > i2)
        {
            res = i1-i2;
            if(op) cout << i1 << " - " << i2 << " = " << res << endl;
        }
        else
        {
            res = i2-i1;
            if(op) cout << i2 << " - " << i1 << " = " << res << endl;
        }
    }

    return res;
}
