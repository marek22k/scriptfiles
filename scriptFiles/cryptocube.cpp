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
#include <array>
#include <vector>
#include <string>

#include <cmath>
#include <cstdlib>

using namespace std;

class cryptocube
{
    public:
        cryptocube(string);
        void Up();
        void Down();
        void Right();
        void Left();
        string GetValue();

    protected:
        array<array<array<char, 2>, 2>, 2> arr;
};

string cube_crypt(string str, string key);
string cptr_to_string(char *);

cryptocube::cryptocube(string str)
{
    arr[0][0][0] = str[0];
    arr[0][1][0] = str[1];
    arr[1][1][0] = str[2];
    arr[1][0][0] = str[3];
    arr[0][0][1] = str[4];
    arr[0][1][1] = str[5];
    arr[1][1][1] = str[6];
    arr[1][0][1] = str[7];
}

string cryptocube::GetValue()
{
    string res;
    res += arr[0][0][0];
    res += arr[0][1][0];
    res += arr[1][1][0];
    res += arr[1][0][0];
    res += arr[0][0][1];
    res += arr[0][1][1];
    res += arr[1][1][1];
    res += arr[1][0][1];
    return res;
}

void cryptocube::Up()
{
    array<array<array<char, 2>, 2>, 2> old = arr;
    arr[0][0][0] = old[0][0][1];
    arr[0][0][1] = old[0][1][1];
    arr[0][1][1] = old[0][1][0];
    arr[0][1][0] = old[0][0][0];

    arr[1][0][0] = old[1][0][1];
    arr[1][0][1] = old[1][1][1];
    arr[1][1][1] = old[1][1][0];
    arr[1][1][0] = old[1][0][0];
}

void cryptocube::Down()
{
    array<array<array<char, 2>, 2>, 2> old = arr;
    arr[0][0][1] = old[0][0][0];
    arr[0][1][1] = old[0][0][1];
    arr[0][1][0] = old[0][1][1];
    arr[0][0][0] = old[0][1][0];

    arr[1][0][1] = old[1][0][0];
    arr[1][1][1] = old[1][0][1];
    arr[1][1][0] = old[1][1][1];
    arr[1][0][0] = old[1][1][0];
}

void cryptocube::Right()
{
    array<array<array<char, 2>, 2>, 2> old = arr;
    arr[0][0][0] = old[0][0][1];
    arr[0][0][1] = old[1][0][1];
    arr[1][0][1] = old[1][0][0];
    arr[1][0][0] = old[0][0][0];

    arr[0][1][1] = old[1][1][1];
    arr[1][1][1] = old[1][1][0];
    arr[1][1][0] = old[0][1][0];
    arr[0][1][0] = old[0][1][1];
}

void cryptocube::Left()
{
    array<array<array<char, 2>, 2>, 2> old = arr;
    arr[0][0][1] = old[0][0][0];
    arr[1][0][1] = old[0][0][1];
    arr[1][0][0] = old[1][0][1];
    arr[0][0][0] = old[1][0][0];

    arr[1][1][1] = old[0][1][1];
    arr[1][1][0] = old[1][1][1];
    arr[0][1][0] = old[1][1][0];
    arr[0][1][1] = old[0][1][0];
}

string cube_crypt(string str, string key)
{
    unsigned c = ceil(static_cast<double>(str.length()) / 8.0);

    vector<cryptocube> cc;

    for(unsigned i = 0; i < c; i++)
    {
        if(i*8+8 < str.length())
            cc.push_back(cryptocube(str.substr(i*8, 8)));
        else
        {
            string tmp = str.substr(i*8, str.length()-i*8);
            while(tmp.length() < 8) tmp += "x";
            cc.push_back(cryptocube(tmp));
        }
    }

    for(unsigned i = 0; i < c; i++)
        for(unsigned j = 0; j < key.length(); j += 2)
            switch(key[j])
            {
                case 'U': cc[i].Up(); break;
                case 'D': cc[i].Down(); break;
                case 'R': cc[i].Right(); break;
                case 'L': cc[i].Left(); break;
            }

    string res;

    for(unsigned i = 0; i < c; i++)
        res += cc[i].GetValue();

    return res;
}

string cptr_to_string(char * c)
{
    string res;
    unsigned len;

    if(c == NULL) abort();
    for(len = 0; c[len] != '\0'; len++);

    for(unsigned i = 0; i < len; i++)
        res += c[i];

    return res;
}

int main(int argc, char * argv[])
{
    if(argc < 2) abort();
    cout << cube_crypt(cptr_to_string(argv[1]), cptr_to_string(argv[2]));
    return EXIT_SUCCESS;
}
