
// Thanks to test.mk16.de
// This file is from Marek K.
// test.mk16.de

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

// Define to output
#define GLOBAL_sqrt true
#define GLOBAL_prime false
#define GLOBAL_to 100000




#include <iostream>
#include <vector>
using namespace std;

// This function(isPrime) is from test.mk16.de
bool isPrime(int num)
{
    bool res = true;
    for(int n = 2; n < num; n++)
    {
        int i = num%n;
        if(i == 0)
            res = false;
    }
    return res;
}

// This function(GetHeron) is from test.mk16.de
double GetHeron(int num)
{
    if(num == 0)
        return 0;
    double calc = 2, last = 0;
    while(last != calc)
    {
        last = calc;
        calc = (calc+(num/calc))/(double)2;
    }
    return calc;
}

vector<int> GetNumbers(int to)
{
    vector<int> v;
    for(unsigned int i = 0; i < to; i++)
    {
        bool o = false;
        double h = GetHeron(i);

        if(h == (int)h && GLOBAL_sqrt) o=true;
        if(isPrime(i) && GLOBAL_prime) o=true;

        if(o) v.push_back(i);
    }
    return v;
}

void OutputNumbers(vector<int> v)
{
    int to = v.size();
    for(unsigned int i = 0; i < to; i++)
    {
        cout << v[i];
        if(i != to-1) cout << ", ";
        if(i%9 == 0 && i != 0) cout << endl;
    }
}

int main()
{
    OutputNumbers(GetNumbers(GLOBAL_to));
    return 0;
}
