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

#include "mmatrix.hpp"

template <typename T>
inline mmatrix<T>::mmatrix(size_t x, size_t y) : sx(x), sy(y)
{
    this->mat.resize(y);
    for(size_t i = 0; i < y; i++)
        this->mat.at(i).resize(x);
}

template <typename T>
inline void mmatrix<T>::fill(mmatrix<T>::Mtype f)
{
    for(size_t y = 0; y < this->sy; y++)
        for(size_t x = 0; x < this->sx; x++)
            this->mat.at(y).at(x) = f;
}

template <typename T>
inline typename mmatrix<T>::Mtype * mmatrix<T>::get(size_t x, size_t y)
{
    if(x > this->sx || y > this->sy)
        throw std::invalid_argument("Invalid arguments!");
    return & this->mat.at(y).at(x);
}

template <typename T>
inline void mmatrix<T>::output(std::ostream & os)
{
    os << "  ";
    for(size_t x = 0; x < this->sx; x++)
        os << x << " ";
    os << std::endl;
    
    for(size_t y = 0; y < this->sy; y++)
    {
        os << y << " ";
        for(size_t x = 0; x < this->sx; x++)
            os << this->mat.at(y).at(x) << " ";
        os << std::endl;
    }
}

template <typename T>
inline void mmatrix<T>::fill(std::function<mmatrix<T>::Mtype (size_t, size_t)> func)
{
    for(size_t y = 0; y < this->sy; y++)
        for(size_t x = 0; x < this->sx; x++)
            this->mat.at(y).at(x) = func(x, y);
}

template <typename T>
inline void mmatrix<T>::each(std::function<void (size_t, size_t, mmatrix<T>::Mtype *)> func)
{
    for(size_t y = 0; y < this->sy; y++)
        for(size_t x = 0; x < this->sx; x++)
            func(x, y, & this->mat.at(y).at(x));
}
