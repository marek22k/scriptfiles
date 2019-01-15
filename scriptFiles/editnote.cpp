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
#include <cstdlib>
#include <fstream>

// The author of this file is Marek K.

using namespace std;

int main(int argc, char *argv[])
{
    string name, fc, ans;
    if(argc > 1) name = argv[1];
    if(name == "")
    {
        cout << "Note name: ";
        cin >> name;
    }
    ifstream f(name);
    getline(f, fc);
    cout << "Note content: " << fc << endl;
    if(argc == 3)
    {
        fc = argv[2];
        cout << "edit/quit: e" << endl;
        cout << "New note content: " << fc;
    }
    else
    {
        cout << "edit(e)/quit(q): ";
        cin >> ans;
        if(! (ans == "quit" || ans == "q")) {
            if(ans != "edit" && ans != "e") { cerr << "Invalid Input; For more information, contact the developer of this program; Errorcode: 0x0001\n"; abort(); }
            cout << "New note content: ";
            cin >> fc;
        }
    }
    ofstream fw(name);
    fw << fc;
    cout << "The developer of this program is Marek K." << endl;

    cout << "quit(q): ";
    cin >> ans;

    return 0;
}
