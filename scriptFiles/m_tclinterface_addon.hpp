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

#ifndef M_TCLINTERFACE_ADDON
#define M_TCLINTERFACE_ADDON

#include <string>
#include <vector>

#ifdef M_TCLINTERFACE_ALT_HPP
    #define MTI_DELBUF(filename) (m_tclinterface_delbuf_alt ( (std::string) filename ))
#elif defined(M_TCLINTERFACE_HPP)
    #define MTI_DELBUF(filename) (m_tclinterface_delbuf ( (std::string) filename ))
#else
    #error m_tclinterface function is not included.
#endif

bool m_tclinterface_delbuf(std::string filename);
bool m_tclinterface_delbuf_alt(std::string filename);
std::vector<std::string> m_tclinterface_GetDataFromList(std::string, std::string,
                                                        std::string (*)(std::string, std::string));

#endif  // M_TCLINTERFACE_ADDON
