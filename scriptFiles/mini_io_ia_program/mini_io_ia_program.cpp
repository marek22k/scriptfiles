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
#include <stdexcept>
#include <vector>
#include <algorithm>

#include <cstdlib>

#include "m_tclinterface.hpp"

using namespace std;

int main()
{
    string name, zustand, data;
    vector<string> lang;

    try
    {
        // Lese Sprach Daten
        data = m_tclinterface("language.tcl", "for {set i 0} { $i < [llength $language] } {incr i} { m_tclinterface_puts [lindex $language $i] }");
    }
    catch (const runtime_error & e)  // Ausnahmebehandlung
    {
        cerr << "Error: " << e.what() << endl;
        abort();  // Beendet Programm, weil eine ordnungsgemaesze durchfuehrung nicht mehr moeglisch ist
    }

    size_t anzahl_eintrage = static_cast<size_t>(count(data.begin(), data.end(), '\n')),
    last = 0,
    buf = 0;
    for(size_t i = 0; i < anzahl_eintrage; i++)
    {
        buf = data.find("\n", last + 1);
        lang.push_back(data.substr(last, buf - last));
        #ifdef DEBUG
            cout << "Sprach Datan: " << endl;
            cout << ":" << data.substr(last, buf - last) << ";" << endl;
        #endif
        last = buf + 1;
    }

    cout << lang[1] << " " << flush;
    cin >> name;
    cout << lang[0] << ", " << name << endl;

    abfrage_zustand:
    cout << lang[2] << " " << flush;
    cin >> zustand;

    if (zustand == lang[3])  // gut
        cout << lang[6] << endl;
    else if (zustand == lang[4])  // schlecht
        cout << lang[5] << endl;
    else
    {
        cout << lang[7] << endl;
        goto abfrage_zustand;
    }

    cout << lang[8] << endl;

    return EXIT_SUCCESS;
}
