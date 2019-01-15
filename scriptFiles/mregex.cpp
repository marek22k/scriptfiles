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

#include <iostream>  /* cout, cin, cerr */
#include <regex>  /* regex, smatch, regex_search, regex_constants */
#include <string>  /* getline */
#include <cstring>  /* strcmp */
#include <cstdlib>  /* exit, EXIT_SUCCESS */

using namespace std;

int main(int argc, char * argv[])
{
    if(argc >= 2)
        if(strcmp(argv[1], "-v") == 0)
        {
            cout << "mregex" << endl <<
                    "======" << endl <<
                    endl <<
                    "The program mregex was written by Marek K. on 22/04/2018 in the programming language C++." << endl;
            exit(EXIT_SUCCESS);
        }

    try
    {
        string str, reg;
        cout << "mregex" << endl <<
                "======" << endl <<
                endl <<
                "Regular expression: ";
        getline(cin, reg);
        cout << "String: ";
        getline(cin, str);
        cout << endl;
        regex re(reg, regex_constants::extended);
        smatch mat;
        bool res = regex_search(str, mat, re);
        if(res && mat.str(0) != "")
        {
            cout << "Matchs: " << endl;
            cout << "Match: " << mat.str(0) << endl;
            for(register unsigned i = 1; i < mat.size(); i++)
                cout << "Match " << i << ": " << mat.str(i) << endl;
        }
        else
            cout << "No Matchs" << endl;
    }
    catch(const exception &e)
    {
        cerr << "Error: " << e.what() << endl;
    }

    return EXIT_SUCCESS;
}
