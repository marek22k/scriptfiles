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

#include <iostream>  // Import iostream
#include <cstdlib>  // Import cstdlib(stdlib.h)
#include <ctime>  // Import ctime(time.h)

/*
    The author of this file is Marek K.
    Thanks for Marek K., test.mk16.de
*/
#define GLOBAL_N 100  // Define GLOBAL_N

using namespace std;  // Using namespace std

// This function is from test.mk16.de
// test.mk16.de/scriptFiles/prime.h
bool isPrime(int num)  // Start function isPrime
{
    if(num == 1) return false;
    bool res = true;
    for(int n = 2; n < num; n++)
    {
        int i = num%n;
        if(i == 0)
            res = false;
    }
    return res;
}  // End function isPrime

// This function is from test.mk16.de
// test.mk16.de/scriptFiles/GetHeron.cpp
double GetHeron(int num)  // Start function GetHeron
{
    if(num == 0) return 0;
    double calc = 2, last = 0;
    while(last != calc)
    {
        last = calc;
        calc = (calc+(num/calc))/(double)2;
    }
    return calc;
}  // End function GetHeron

int main()  // Start function main
{
    srand( time(0) );
    int z1 = 1;
    int z2 = 0;
    int i = 0;
    int t = GLOBAL_N;
    int x = 0;
    int y = 0;
    bool p = true;
    bool r = true;
    while(true)
    {
        if(p)
        {
            int num = 0;
            if(r)
            {
                num = rand()%(t+1);
                r = false;
            }
            else
            {
                num = z1;
                z1++;
                r = true;
            }
            bool user = false;
            bool comp = isPrime(num);
            cout << "Ist " << num << " eine Primzahl? ";
            cin >> user;
            if(user == comp)
            {
                cout << "Richtig!" << endl;
                x++;
            }
            else
            {
                cout << "FALSCH" << endl;
                y++;
            }
            p = false;
            i++;

            // Output "You are great!"
            if(i%40 == 0) cout << "----------> Du bist schon weit gekommen!! <----------" << endl;
            else if(i%30 == 0) cout << "----------> Gut gemacht! <----------" << endl;
            else if(i%20 == 0) cout << "----------> Weiter so! <----------" << endl;
            else if(i%10 == 0) cout << "----------> Super! <----------" << endl;
            if(i%5 == 0) cout << "----------> Du hast schon " << i << " Fragen beantwortet davon " << x << " Richtig und " << y << " Falsch! <----------" << endl;

            if(z1 > t) t *= 2;
        }
        else
        {
            double heron = GetHeron(z2);
            cout << "Die Wurzel aus " << z2 << " ist " << heron << endl;
            z2++;
            p = true;
        }
    }
    return 0;
}  // End function main
