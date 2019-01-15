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

#include "pntype.h"

using namespace std;

pntype::pntype()
{
	this->number = 0;
	this->outlog = false;
}

pntype::pntype(int number, bool outlog)
{
	this->number = number;
	this->outlog = outlog;
}

string pntype::ConvertToString(int n)
{
    ostringstream s;
    s << n;
    return s.str();
}

void pntype::_set(int number)
{
    this->number = number;
}

int pntype::_get()
{
    return number;
}

void pntype::_calculate()
{
    try
    {
        int num = number;
        int z = 0;
        while (true)
        {
            string sn = ConvertToString(num);
            reverse(sn.begin(), sn.end());
            int i = atoi(sn.c_str());
            int n = num;
            int r = i + n;
            string res = ConvertToString(r);
            if(res.length() > 2)
            {
                int len = res.length()/2;
                if(len%2 == 0) len-1;
                string one = "";
                string two = "";
                for(int n = len+1; n > 1; n--)
                {
                    one += res.at(n);
                }
                for(int n = 0; n < len; n++)
                {
                    two += res.at(n);
                }
                num = r;
                if(one == two) break;
            }
            else
            {
                num = r;
                if(res.at(0) == res.at(1)) break;
            }
            if(z >= 24 || num > 10000) {throw 0x0001; break;}
            z += 1;
            if(outlog == true) clog << z << ": " << num << "\n";
        }
        number = num;
        if(outlog == true) clog << (z+1) << ": " << num << "\n";
    }
    catch(int e)
    {
        if(e == 0x0001) errorlog += ConvertToString(number) + " is a Lychrel number; Errorcode: 0x0001\n";
    }
}

string pntype::_ErrorLog()
{
    return errorlog;
}

void pntype::_TurnLog()
{
    if(outlog == true) outlog = false; else outlog = true;
}
