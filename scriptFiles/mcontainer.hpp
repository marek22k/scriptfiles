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

#ifndef MCONTAINER_H
#define MCONTAINER_H

#include <memory>
#include <iterator>
#include <cstddef>

template <typename T, typename Alloc = std::allocator<T>>
class mcontainer
{
    protected:
        T * ptr;
        Alloc all;
        size_t siz;

    public:
        explicit mcontainer();
        explicit mcontainer(size_t);
        virtual ~mcontainer();

        class iterator : public std::iterator<std::input_iterator_tag, T>
        {
            protected:
                T * ptr;

            public:
                iterator(T *);
                iterator(const iterator &);
                T & operator*() const;
                iterator operator++(int);
                iterator & operator++() noexcept;
                iterator operator--(int);
                iterator & operator--() noexcept;
                iterator operator=(const iterator &);
                bool operator==(const iterator &) const noexcept;
                bool operator!=(const iterator &) const noexcept;
                bool operator<(const iterator &) const noexcept;
                bool operator>(const iterator &) const noexcept;
        };

        iterator begin();
        iterator end();

        T operator[](size_t) const;
        T & operator[](size_t);

        T at(size_t) const;
        T & at(size_t);

        T front() const;
        T & front();

        T back() const;
        T & back();

        size_t size() const noexcept;
        void clear(T = 0);

        Alloc get_allocator() const noexcept;
};



#endif  // MCONTAINER_H
