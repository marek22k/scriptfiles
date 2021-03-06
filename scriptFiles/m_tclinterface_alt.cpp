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

#include "m_tclinterface_alt.hpp"

#include <fstream>
#include <stdexcept>
#include <cstdlib>
#include <cstddef>

std::string m_tclinterface(std::string filename, std::string com)
{
    std::string tmpfile = filename + "_temp",
    buf;

    std::ifstream f(filename, std::ios::in);
    if(f.bad()) throw std::runtime_error("Can't open file! f1");

    std::ofstream tmp(tmpfile, std::ios::out | std::ios::trunc);
    if(f.bad()) throw std::runtime_error("Can't open file! f2");

    tmp << "rename puts m_tclinterface_puts" << "\n";
    tmp << "proc puts args {}" << "\n";
    while(std::getline(f, buf)) tmp << buf << "\n";
    f.close();
    tmp << "\n" << com;
    tmp.close();

    std::string res = "";
    system(std::string("tclsh " + tmpfile + " > " + filename + "_buffer.tmp").c_str());

    std::ifstream fbuf(filename + "_buffer.tmp", std::ios::in);
    if(f.bad()) throw std::runtime_error("Can't open file! f1");
    while(std::getline(fbuf, buf)) res += buf + "\n";

    fbuf.close();

    return res;
}
