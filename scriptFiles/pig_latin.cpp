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

#include <iostream>  /* cout, flush, cin, cerr, endl */
#include <string>  /* string, getline */

#include <cstdlib>  /* abort, EXIT_SUCCESS */
#include <cstddef>  /* size_t */

using namespace std;

string::iterator countConsonants(string::iterator, string::iterator, int = 1);
string encrypt(string);
string decrypt(string, size_t = 1);

int main()
{
    string in;
    int sel;


    input1:
    cout << "String: " << flush;
    getline(cin, in);
    if(in == "")
    {
        cerr << "Invalid input!" << endl;
        goto input1;
    }

    input2:
    cout << "Mode (Encrypt: 1; Decrypt: 2): " << flush;
    cin >> sel;
    if(cin.fail() || (sel != 1 && sel != 2))
    {
        cerr << "Invalid input!" << endl;
        goto input2;
    }

    switch(sel)
    {
        case 1:
        {
            in += " ";
            string buf;
            for(string::iterator i = in.begin(); i < in.end(); i++)
            {
                if(*i == ' ')
                {
                    cout << encrypt(buf) << " ";
                    buf = "";
                    continue;
                }
                buf += *i;
            }
            break;
        }
        case 2:
        {
            in += " ";
            string buf;
            for(string::iterator i = in.begin(); i < in.end(); i++)
            {
                if(*i == ' ')
                {
                    cout << decrypt(buf) << " ";
                    buf = "";
                    continue;
                }
                buf += *i;
            }
            break;
        }
    }

    cout << endl;

    return EXIT_SUCCESS;
}

inline string::iterator countConsonants(string::iterator ibeg, string::iterator iend, int add)
{

    string::iterator iter;
    for(iter = ibeg;
    *iter != 'a' && *iter != 'A' &&
    *iter != 'e' && *iter != 'E' &&
    *iter != 'i' && *iter != 'I' &&
    *iter != 'o' && *iter != 'O' &&
    *iter != 'u' && *iter != 'U' &&
    iter != iend; iter += add);

    return iter;
}

inline string encrypt(string str)
{
    size_t cons = static_cast<size_t>(countConsonants(str.begin(), str.end()) - str.begin());
    return (cons>0?str.substr(cons, str.length() - cons) + str.substr(0, cons) + "ay":str + "yay");
}

inline string decrypt(string str, size_t ayde)
{
    return (str.substr(str.length() - 2, 2) == "ay"?(str[str.length() - 3] == 'y'?str.substr(0,
    str.length() - 3):str.substr(str.length()-3, ayde) + str.substr(0, str.length()-2-ayde)):
    "Error");
}
