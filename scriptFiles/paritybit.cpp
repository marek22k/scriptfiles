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
#include <string>
#include <algorithm>

#include <boost/dynamic_bitset.hpp>

#include <cstdlib>
#include <cstddef>
#include <cmath>

using namespace std;
using namespace boost;

dynamic_bitset<> EncodeParitybit(dynamic_bitset<>, bool = true);
bool DecodeParitybit(dynamic_bitset<>, bool = true);

dynamic_bitset<> InputDynBS(istream & = cin, ostream & = cout);
void OutputDynBS(string, dynamic_bitset<>, ostream & = cout);

dynamic_bitset<> toBinary(unsigned);

int main()
{
    short option, even;

    cout << "Option(1 = Encode; 2 = Check; 3 = Encode ASCII(Text); 4 = Decode ASCII(Text); else: Exit): " << flush;
    cin >> option;

    if(cin.fail()) abort();

    cout << "Even(0 = Odd; 1 = Even): " << flush;
    cin >> even;

    if(cin.fail() || (even != 0 && even != 1)) abort();

    cout << endl;

    switch(option)
    {
        case 1:
            {
                OutputDynBS("Result(input bits + check bit): ", EncodeParitybit(InputDynBS(), even));
                break;
            }

        case 2:
            {
                if(DecodeParitybit(InputDynBS(), even))
                    cout << "Valid!" << endl;
                else
                    cout << "Invalid!" << endl;

                break;
            }

        case 3:
            {
                string in, res, buf;
                short nb;

                cout << "Text: " << flush;
                cin >> in;

                if(cin.fail() || in == "") abort();

                cout << "Null-Byte(1 = Yes; 2 = No): " << flush;
                cin >> nb;

                if(cin.fail() || (nb != 1 && nb != 2)) abort();

                for(size_t i = 0; i < in.length(); i++)
                {
                    to_string(EncodeParitybit(toBinary(static_cast<unsigned>(in[i])), even), buf);
                    reverse(buf.begin(), buf.end());
                    for(size_t j = 0; j < 9-buf.size(); j++) res += "0";
                    res += buf;
                    res += " ";
                }

                if(nb) res += "000000000";

                cout << "Result: " << res;
                break;
            }

        case 4:
            {
                string in, res, tmp, incor;
                unsigned buf;

                cout << "Binary(without spaces): " << flush;
                cin >> in;

                if(cin.fail() || in == "") abort();

                for(size_t i = 0; i < in.length(); i += 9)
                {
                    buf = 0;
                    for(size_t j = i; j < i + 8; j++)
                    {
                        buf += (in[j] - 48) * pow(2, i+7-j);
                    }

                    tmp = in.substr(i,9);
                    reverse(tmp.begin(), tmp.end());

                    if(DecodeParitybit(dynamic_bitset<>(tmp), even))
                        res += static_cast<char>(buf);
                    else
                        incor += static_cast<char>(buf);
                }

                cout << "Result: " << res << endl;
                cout << "Incorrect information: " << incor;
                break;
            }
    }

    cout << endl;

    return EXIT_SUCCESS;
}

inline dynamic_bitset<> EncodeParitybit(dynamic_bitset<> bs, bool even)
{
    bs.push_back(static_cast<int>(bs.count()%2==static_cast<int>(even)));
    return bs;
}


inline bool DecodeParitybit(dynamic_bitset<> bs, bool even)
{
    return bs.count()%2!=static_cast<int>(even);
}

inline dynamic_bitset<> InputDynBS(istream & is, ostream & os)
{
    string buf;

    os << "Bits: " << flush;
    is >> buf;
    reverse(buf.begin(), buf.end());

    return dynamic_bitset<>(buf);
}

inline void OutputDynBS(string before, dynamic_bitset<> bs, ostream & os)
{
    string buf;

    to_string(bs, buf);
    reverse(buf.begin(), buf.end());

    os << before;
    os << buf;
}

dynamic_bitset<> toBinary(unsigned num)
{
    string res;

    while(num != 0)
    {
        res += to_string(num%2);
        num /= 2;
    }

    return dynamic_bitset<>(res);
}
