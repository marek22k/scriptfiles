// mwordpoints written by Marek K.

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
#include <ostream>
#include <array>
#include <vector>
#include <string>
#include <algorithm>

#include <cstddef>

using namespace std;


static array<vector<char>, 7> chars = { {
    {'e', 'a', 'i', 'o', 'n', 'r', 't', 'l', 's', 'u'},
    {'d', 'g'},
    {'b', 'c', 'm', 'p'},
    {'f', 'h', 'v', 'w', 'y'},
    {'k'},
    {'j', 'x'},
    {'q', 'z'}
} };

static array<short unsigned, 7> nums = {1, 2, 3, 4, 5, 8, 10};


int main()
{
    vector<string> str;
    string in;
    size_t buf;
	
    getline(cin, in);
    do
    {
        cout << "Word: ";
        str.push_back(in);
        getline(cin, in);
    } while(in != "");

    cout << endl;

    vector<unsigned> ps;
    for(size_t i = 0; i < str.size(); i++)
    {
        ps.push_back(0);
        for(size_t j = 0; j < str[i].length(); j++)
            for(size_t k = 0; k < 7; k++)
            {
                buf = static_cast<size_t>(find(chars[k].begin(), chars[k].end(), str[i][j])-chars[k].begin());
                if(buf != chars[k].size()) ps[i] += static_cast<unsigned>(nums[k]);
            }
			
        cout << "Word " << str[i] << ": " << ps[i] << (ps[i]<=1?" point":" points") << endl;
    }

    cout << endl << endl << "Winner: " << str[static_cast<size_t>(max_element(ps.begin(), ps.end()) - ps.begin())] << endl;

    return 0;
}
