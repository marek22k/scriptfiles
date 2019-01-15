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

#include "buffer.hpp"
#include <new>  /* operator new, operator delete */

template <class T>
inline T GetValue(buffer<T> & buf)
{
    return *buf.obj;
}

template <class T>
inline T * GetPointer(buffer<T> & buf)
{
    return buf.obj;
}

template <class T>
inline buffer<T>::buffer()
{
    this->obj = new T{};
}

template <class T>
inline buffer<T>::buffer(T init)
{
    this->obj = new T{init};
}

template <class T>
inline buffer<T>::~buffer()
{
    delete this->obj;
}

template <class T>
inline void buffer<T>::close()
{
    delete this->obj;
    this->obj = nullptr;
}

template <class T>
inline bool buffer<T>::is_open()
{
    return this->obj==nullptr;
}

template <class T>
inline T buffer<T>::operator<<(T obj)
{
    *this->obj += obj;
    return obj;
}

template <class T>
inline T buffer<T>::operator>>(T & obj)
{
    obj = *this->obj;
    return obj;
}

template <class T>
inline void buffer<T>::swap(buffer<T> buf)
{
    T * ptr = buf.obj;
    buf.obj = this->obj;
    this->obj = ptr;
}
