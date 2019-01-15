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

#ifndef CROSS_H
#define CROSS_H

#include <sstream>
#include <string>
#include <cstdlib>

namespace cross
{
    using namespace std;

    int temp = 0;
    string log = "";

    template <class T>
    int GetCrossSum(T num)
    {
        stringstream ss;
        ss << num;
        log += "\nGetCrossSum(" + ss.str() + ")\n";
        string s = ss.str();
        int len = s.length();
        int d = 0;
        for(int n = 0; n < len; n++)
        {
            d += atoi(s.substr(n, 1).c_str());
            stringstream s;
            s << d;
            stringstream ss;
            ss << n+1;
            log += "Round " + ss.str() + "(GetCrossSum): " + s.str() + "\n";
        }
        return d;
    }

    template <class T>
    int GetCrossProduct(T num)
    {
        stringstream ss;
        ss << num;
        log += "\nGetCrossProduct(" + ss.str() + ")\n";
        string s = ss.str();
        int len = s.length();
        int d = 1;
        for(int n = 0; n < len; n++)
        {
            d *= atoi(s.substr(n, 1).c_str());
            stringstream s;
            s << d;
            stringstream ss;
            ss << n+1;
            log += "Round " + ss.str() + "(GetCrossProduct): " + s.str() + "\n";
        }
        return d;
    }

    template <class T>
    int GetIteratedCrossProduct(T num)
    {
        int d = num, n = 0;
        stringstream s;
        s << num;
        log += "\nGetIteratedCrossProduct(" + s.str() + ")\n";
        while(true)
        {
            d = GetCrossProduct(d);
            stringstream s;
            s << d;
            stringstream ss;
            ss << n+1;
            n++;
            log += "\nRound " + ss.str() + "(GetIteratedCrossProduct): " + s.str() + "\n";
            if(s.str().length() == 1) break;
            else continue;
        }
        temp = n;
        return d;
    }

    int GetLastPersistence()
    {
        return temp;
    }

    string GetLog()
    {
        return log;
    }

    void ClearLog()
    {
        log = "";
    }

    template <class T>
    int GetAlternatingCrossSum(T num)
    {
        stringstream ss;
        ss << num;
        log += "\nGetAlternatingCrossSum(" + ss.str() + ")\n";
        string s = ss.str();
        int len = s.length();
        signed int d = atoi(s.substr(0, 1).c_str());
        bool p = false;
        for(int n = 1; n < len; n++)
        {
            if(p == true)
                d += atoi(s.substr(n, 1).c_str());
            else
                d -= atoi(s.substr(n, 1).c_str());
            stringstream s;
            s << d;
            stringstream ss;
            ss << n+1;
            log += "Round " + ss.str() + "(GetAlternatingCrossSum): " + s.str() + "\n";
            if(p == false)p=true;else p=false;
        }
        return d;
    }
}

#endif
