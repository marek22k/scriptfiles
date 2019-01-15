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
    along long with this program.  If not, see <http://www.gnu.org/licenses/>.

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

#include <iostream>  /* cout, endl, flush, cin */
#include <vector>  /* vector */
#include <string>  /* string, to_string */
#include <stdexcept>  /* runtime_error */
#include <exception>  /* exception, terminate */

#include <cstdlib>  /* EXIT_SUCCESS */

using namespace std;

unsigned long long find10(unsigned long long) noexcept;
unsigned long long calcLuhn(unsigned long long, unsigned long long (*)(unsigned long long) = find10);
bool checkLuhn(unsigned long long, unsigned long long (*)(unsigned long long) = find10);

vector<string> menu = {"Luhn algorithm",
                       "==============",
                       "",
                       "Option 1:\n\r\tHave a number checked to see if the check digit corresponds to the Luhn algorithm.",
                       "Option 2:\n\r\tCalculate the check digit according to the Luhn algorithm",
                       "",
                       "Author:\n\r\tMarek K. (mk16.de)",
                       "",
                       "Lisense:"};

vector<string> license = {"This program is free software: you can redistribute it and/or modify",
                          "it under the terms of the GNU General Public License as published by",
                          "the Free Software Foundation, either version 3 of the License, or",
                          "(at your option) any later version.",
                          "",
                          "This program is distributed in the hope that it will be useful,",
                          "but WITHOUT ANY WARRANTY; without even the implied warranty of",
                          "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the",
                          "GNU General Public License for more details.",
                          "You should have received a copy of the GNU General Public License",
                          "along long with this program.  If not, see <http://www.gnu.org/licenses/>.",
                          ""};

int main()
{
    for(string line : menu) cout << line << endl;
    for(string line : license) cout << "\t" << line << endl;

    try
    {
        short option = 0;
        unsigned long long num;

        cout << "Option(1/2): " << flush;
        cin >> option;
        if(cin.fail() || (option != 1 && option != 2)) throw runtime_error("Invalid input!");

        cout << "Number: " << flush;
        cin >> num;
        if(cin.fail()) throw runtime_error("Invalid input!");

        switch(option)
        {
            case 1:
                cout << "Result: " << (checkLuhn(num)?"Valid!":"Invalid!") << endl;
                break;

            case 2:
                cout << "Result: " << calcLuhn(num) << endl;
                break;
        }
    }
    catch(const exception & e)
    {
        cerr << "Error: " << e.what() << endl;
        terminate();
    }

    return EXIT_SUCCESS;
}

inline unsigned long long find10(unsigned long long n) noexcept
{
        while(n%10 != 0) n++;
        return n;
}

unsigned long long calcLuhn(unsigned long long num, unsigned long long (* f10)(unsigned long long))
{
    string str(to_string(num));
    if(str.length() < 1) throw runtime_error("String too short!");

    unsigned long long n = 0, tmp;

    for(long long i = str.length()-1; i >= 0; i--)
        tmp = (((i+str.length())%2 == 0)?2:1) * (static_cast<unsigned long long>(str[i]) - static_cast<unsigned long long>('0')),
        n += tmp - (tmp>10?9:0);

    return stoull(str + to_string(f10(n) - n));
}

bool checkLuhn(unsigned long long num, unsigned long long (* f10)(unsigned long long))
{
    string str(to_string(num));
    if(str.length() < 1) throw runtime_error("String too short!");

    unsigned long long n = 0, tmp;
    char ctmp = str[str.length()-1];
    str.erase(str.length()-1, 1);

    for(long long i = str.length()-1; i >= 0; i--)
        tmp = (((i+str.length())%2 == 0)?2:1) * (static_cast<unsigned long long>(str[i]) - static_cast<unsigned long long>('0')),
        n += tmp - (tmp>10?9:0);

    return f10(n) - n == static_cast<unsigned long long>(ctmp) - static_cast<unsigned long long>('0');
}
