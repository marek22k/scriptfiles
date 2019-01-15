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

#include "mcontainer.hpp"

template <typename T, typename Alloc>
mcontainer<T, Alloc>::mcontainer()
{
    this->ptr = this->all.allocate(255);
    this->siz = 255;
}

template <typename T, typename Alloc>
mcontainer<T, Alloc>::mcontainer(size_t n)
{
    this->ptr = this->all.allocate(n);
    this->siz = n;
}

template <typename T, typename Alloc>
mcontainer<T, Alloc>::~mcontainer()
{
    this->all.deallocate(this->ptr, this->siz);
}

template <typename T, typename Alloc>
mcontainer<T, Alloc>::iterator::iterator(T * o) : ptr(o) { }

template <typename T, typename Alloc>
mcontainer<T, Alloc>::iterator::iterator(const iterator & iter) : ptr(iter.ptr) { }

template <typename T, typename Alloc>
T & mcontainer<T, Alloc>::iterator::operator*() const
{
    return *this->ptr;
}

template <typename T, typename Alloc>
typename mcontainer<T, Alloc>::iterator
mcontainer<T, Alloc>::iterator::operator=(const iterator & iter)
{
    this->ptr = iter.ptr;
    return *this;
}

template <typename T, typename Alloc>
typename mcontainer<T, Alloc>::iterator mcontainer<T, Alloc>::iterator::operator++(int)
{
    mcontainer<T, Alloc>::iterator tmp(*this);
    this->ptr++;
    return tmp;
}

template <typename T, typename Alloc>
typename mcontainer<T, Alloc>::iterator & mcontainer<T, Alloc>::iterator::operator++() noexcept
{
    this->ptr++;
    return *this;
}

template <typename T, typename Alloc>
typename mcontainer<T, Alloc>::iterator mcontainer<T, Alloc>::iterator::operator--(int)
{
    mcontainer<T, Alloc>::iterator tmp(this->ptr);
    this->ptr--;
    return tmp;
}

template <typename T, typename Alloc>
typename mcontainer<T, Alloc>::iterator & mcontainer<T, Alloc>::iterator::operator--() noexcept
{
    this->ptr--;
    return *this;
}

template <typename T, typename Alloc>
bool mcontainer<T, Alloc>::iterator::operator==(const iterator & iter) const noexcept
{
    return this->ptr == iter.ptr;
}

template <typename T, typename Alloc>
bool mcontainer<T, Alloc>::iterator::operator!=(const iterator & iter) const noexcept
{
    return this->ptr != iter.ptr;
}

template <typename T, typename Alloc>
bool mcontainer<T, Alloc>::iterator::operator<(const iterator & iter) const noexcept
{
    return this->ptr < iter.ptr;
}

template <typename T, typename Alloc>
bool mcontainer<T, Alloc>::iterator::operator>(const iterator & iter) const noexcept
{
    return this->ptr > iter.ptr;
}

template <typename T, typename Alloc>
typename mcontainer<T, Alloc>::iterator mcontainer<T, Alloc>::begin()
{
    return mcontainer<T, Alloc>::iterator(this->ptr);
}

template <typename T, typename Alloc>
typename mcontainer<T, Alloc>::iterator mcontainer<T, Alloc>::end()
{
    return mcontainer<T, Alloc>::iterator(this->ptr + this->siz);
}

template <typename T, typename Alloc>
T mcontainer<T, Alloc>::operator[](size_t index) const
{
    return this->ptr[index];
}

template <typename T, typename Alloc>
T & mcontainer<T, Alloc>::operator[](size_t index)
{
    return this->ptr[index];
}

template <typename T, typename Alloc>
T mcontainer<T, Alloc>::at(size_t index) const
{
    return this->ptr[index];
}

template <typename T, typename Alloc>
T & mcontainer<T, Alloc>::at(size_t index)
{
    return this->ptr[index];
}

template <typename T, typename Alloc>
size_t mcontainer<T, Alloc>::size() const noexcept
{
    return this->siz;
}

template <typename T, typename Alloc>
void mcontainer<T, Alloc>::clear(T val)
{
    for (size_t i = 0; i < this->siz; i++)
        this->ptr[i] = val;
}

template <typename T, typename Alloc>
Alloc mcontainer<T, Alloc>::get_allocator() const noexcept
{
    return this->all;
}

template <typename T, typename Alloc>
T mcontainer<T, Alloc>::front() const
{
    return this->ptr[0];
}

template <typename T, typename Alloc>
T & mcontainer<T, Alloc>::front()
{
    return this->ptr[0];
}

template <typename T, typename Alloc>
T mcontainer<T, Alloc>::back() const
{
    return this->ptr[this->siz - 1];
}

template <typename T, typename Alloc>
T & mcontainer<T, Alloc>::back()
{
    return this->ptr[this->siz - 1];
}
