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
#include <cstdlib>
#include <ctime>
#include <fstream>
/**< Imports */

/**< Namespaces */
using namespace std;

namespace settings /**< Begin namespace settings */
{
    const int NumberOfOverrides = 1; /**< Number of Overrides */
} /**< End namespace settings */

/**< Main-Function */
int main(int argc, char *argv[])
{
    cout << "The developer of this program is Marek K." << endl;
    try
    {
        srand( time(0) );
        for(int n = 1; n < argc; n++)
        {
            fstream file;
            file.open(argv[n], ios::in);

            cout << "Delete file: " << argv[n];

            if(!file.is_open())
                throw 0x0001;

            string context;
            bool *tmp = new bool;
            *tmp = false;
            while(! file.eof())
            {
                if(*tmp != false)
                    context += "\n";
                getline(file, context);
                *tmp = true;
            }
            if(*tmp == false)
                throw 0x0002;
            int len = context.length();
            delete tmp;
            file.close();

            for(int z = 0; z < settings::NumberOfOverrides; z++)
            {
                fstream f;
                f.open(argv[n], ios::out);

                if(!f.is_open())
                    throw 0x0001;

                for(int i = 0; i < len; i++)
                {
                    int *tmp = new int;
                    *tmp = rand()%10;
                    f << *tmp;
                }

                f.close();
            }

            remove(argv[n]);

            cout << "; Complete" << endl;

        }
        cout << "The file(s) has removed!" << endl;
        if(argv[1] == "")
            throw 0x0003;
    }
    catch (int e)
    {
        cerr << "An error has occurred; Please contact the developer for more information; Errorcode: " << e << "\n";
    }
    return 0;
}
/**< End Main-Function */
