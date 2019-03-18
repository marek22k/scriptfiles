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

#ifndef MMATRIX_HPP
#define MMATRIX_HPP

#include <iostream>
#include <ostream>
#include <vector>
#include <exception>
#include <stdexcept>
#include <functional>

#include <cstddef>

template <typename T>
class mmatrix
{
    public:
        typedef T Mtype;
        
        mmatrix(size_t, size_t);
        void fill(Mtype);
        void fill(std::function<Mtype (size_t, size_t)>);
        void each(std::function<void (size_t, size_t, Mtype *)>);
        void output(std::ostream & = std::cout);
        Mtype * get(size_t, size_t);
        
        std::vector<std::vector<Mtype>> mat;
        const size_t sx, sy;
};

#include "mmatrix.inl"

#endif
