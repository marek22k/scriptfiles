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

#define T_TCLINTERFACE_HPP
#define M_TCLINTERFACE_ALT_HPP

#include "m_tclinterface_addon.hpp"
#include <vector>
#include <string>
#include <algorithm>

std::vector<std::string> m_tclinterface_GetDataFromList(std::string filename, std::string varname,
                                        std::string (* m_tclinterface)(std::string, std::string))
{
    std::string data;
    std::vector<std::string> lang;

    data = m_tclinterface(filename, "for {set i 0} { $i < [llength " + varname +
                          "] } {incr i} { m_tclinterface_puts [lindex " + varname + " $i] }");

    size_t items_n = static_cast<size_t>(std::count(data.begin(), data.end(), '\n')),
    last = 0,
    buf = 0;
    for(size_t i = 0; i < items_n; i++)
    {
        buf = data.find("\n", last + 1);
        lang.push_back(data.substr(last, buf - last));
        #ifdef DEBUG
            cout << ":" << data.substr(last, buf - last) << ";" << endl;
        #endif
        last = buf + 1;
    }

    return lang;
}

bool m_tclinterface_delbuf(std::string filename)
{
    return remove(std::string(filename + "_temp").c_str());
}

bool m_tclinterface_delbuf_alt(std::string filename)
{
    return ! remove(std::string(filename + "_buffer.tmp").c_str()) &&
           ! m_tclinterface_delbuf(filename);
}
