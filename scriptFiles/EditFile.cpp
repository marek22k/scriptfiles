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

/*

The author of this file is Marek K.

*/

int main()
{
    string *tmp = new string;
    cout << "Please enter the name of the information file: ";
    cin >> *tmp;
    fstream file;
    file.open(*tmp, ios::in);
    delete tmp;
    if(file.is_open() == true)
    {
        cout << "Part: 1/7 | ";
    }
    else
    {
        cout << "Error: File one does not exist\n";
        abort();
    }
    string fileContext = "";
    int n = 0;
    while(! file.eof())
    {
        if(n != 0)
        {
            fileContext += "\n";
        }
        n++;
        string *tmp = new string;
        getline(file, *tmp);
        fileContext += *tmp;
        delete tmp;
    }
    cout << "2/7 | ";
    //cout << fileContext << endl;

    regex reg("(.*):\n(.*)", regex_constants::extended | regex_constants::icase);
    smatch m;
    bool res = regex_search(fileContext, m, reg);
    if(res == true && m.size() > 1)
    {
        cout << "3/7 | ";
        fstream f;
        f.open(m.str(1), ios::out);
        if(f.is_open() == true)
        {
            cout << "4/7 | ";
        }
        f << m.str(2);
        f.close();
        cout << "5/7 | ";
    }
    else
    {
        cout << "Error: Match failed\n";
        abort();
    }

    file.close();
    cout << "7/7\nEnd of the program\n";
    return 0;
}
