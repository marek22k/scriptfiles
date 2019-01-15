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
#include <fstream>
#include <regex>

using namespace std;

int main()
{
    try
    {
        string addressC, addressE;
        cout << "Content address: ";
        cin >> addressC;
        cout << "RegExp address: ";
        cin >> addressE;
        ifstream fc(addressC);  // Content
        ifstream fe(addressE);  // RegExp
        string regexp;
        string content;
        string tmp;
        if(! fc.is_open()) throw 0x0001;
        if(! fe.is_open()) throw 0x0002;
        while(! fe.eof() )
        {
            getline(fe, tmp);
            regexp += tmp;
        }
        while(! fc.eof() )
        {
            getline(fc, tmp);
            content += tmp;
        }
        regex reg(regexp);
        smatch m;
        bool res = regex_search(content, m, reg);
        if(res && m.size() > 0)
            for(int i = 0; i < m.size(); i++)
                cout << "Match " << i+1 << ": " << m.str(i) << endl;
        else
            cerr << "Match failed\n";
        cin >> tmp;
    }
    catch(int e)
    {
        cerr << "Error " << e;
    }
    return 0;
}
