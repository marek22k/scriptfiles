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

/*
    Example:
        mministream<> s(mmslimits::LARGE);
        char x[] = "test";
        s << x;
        s.clear();
        
        for(int i = 0; i < 4; i++)
        {
                std::cout << s.get();
                s.up();
        }
        std::cout << std::endl;
        mselfmstream<mministream<>::SType> selfs = s.getself();
        selfs.cur = 0;
        
        for(int i = 0; i < 4; i++)
        {
                std::cout << selfs.ptr[selfs.cur++];
        }
        std::cout << std::endl;
*/

#ifndef MMINISTREAM
#define MMINISTREAM

#define MMINISTREAM_DEFAULT_TYPE char
// default template type

#define MMINISTREAM_USE_USING 1
// use using or typedef

// This file include cstddef(stddef.h) and stdexcept

#if __cplusplus >= 201703L
    #if ! __has_include(<cstddef>)
        #include <cstddef>
    #endif
#else
    #include <cstddef>
#endif

#if __cplusplus >= 201703L
    #if ! __has_include(<stdexcept>)
        #include <stdexcept>
    #endif
#else
    #include <stdexcept>
#endif


namespace mmslimits
{
    constexpr size_t TINY = sizeof(MMINISTREAM_DEFAULT_TYPE) * 3,
    VISIBLY               = sizeof(MMINISTREAM_DEFAULT_TYPE) * 7,
    SMALL                 = sizeof(MMINISTREAM_DEFAULT_TYPE) * 15,
    GREATER               = sizeof(MMINISTREAM_DEFAULT_TYPE) * 127,
    NORMAL                = sizeof(MMINISTREAM_DEFAULT_TYPE) * 255,
    LARGE                 = sizeof(MMINISTREAM_DEFAULT_TYPE) * 1023,
    BIG                   = sizeof(MMINISTREAM_DEFAULT_TYPE) * 65535;
}

template <typename T = MMINISTREAM_DEFAULT_TYPE>
struct mselfmstream
/* mselfmstream = m self mini stream */
{
#if MMINISTREAM_USE_USING == 0
    typedef T SType;
#else
    using SType = T;
#endif
    size_t cur;
    SType * ptr;
    size_t bytes;
};

template <typename T = MMINISTREAM_DEFAULT_TYPE>
class mministream
/* mministream = m mini stream */
{
    public:
#if MMINISTREAM_USE_USING == 0
        typedef T SType;
#else
        using SType = T;
#endif
    
    protected:
        mselfmstream<T> self;
        
    public:
        mministream(const size_t bytes)
        {
            self.bytes = bytes,
            self.ptr = new SType(bytes),
            self.cur = 0;
        }

        ~mministream()
        {
            delete [] this->self.ptr;
        }

        // Push SType on stream
        void operator<<(SType t)
        {
            if(this->self.cur + 1 >= this->self.bytes)
                throw std::runtime_error("cur + 1 >= bytes");
            
            this->self.ptr[this->self.cur] = t;
            this->self.cur++;
        }

        // Push SType's on stream
        void operator<<(SType * t)
        {
            for(size_t i = 0; t[i] != static_cast<SType>(0); i++)
            {
                if(this->self.cur + 1 >= this->self.bytes)
                    throw std::runtime_error("cur + 1 >= bytes");
                
                this->self.ptr[this->self.cur] = t[i];
                this->self.cur++;
            }
        }

        // Pull SType from stream
        void operator>>(SType & t)
        {
            if(this->self.cur - 1 < 0)
                throw std::runtime_error("cur + 1 >= bytes");
                
            t = this->self.ptr[--this->self.cur];
        }

        // Set cur on zero
        void clear()
        {
            this->self.cur = 0;
        }

        // Free the memory
        void free()
        {
            this->self.cur = this->self.bytes + 1;
            delete [] this->self.ptr;
        }

        // Add 1 to cur
        void up()
        {
            this->self.cur++;
        }

        // Sub 1 to cur
        void down()
        {
            this->self.cur--;
        }

        // Get pointer on the current pos
        SType * getptr()
        {
            return this->self.ptr + this->self.cur;
        }

        // Return the value of the current pos
        SType get()
        {
            return this->self.ptr[this->self.cur];
        }

        // Return true, if cur is out of range, otherwise false
        bool outofrange()
        {
            return (this->self.cur >= this->self.bytes?true:false);
        }

        // Return true, if cur is zero, otherwise false
        bool iszero()
        {
            return (this->self.cur == 0?true:false);
        }

        // Return the value of cur
        size_t getcur()
        {
            return this->self.cur;
        }

        // Return the maximum of elements
        size_t getbytes()
        {
            return this->self.bytes;
        }

        // Return the self struct
        mselfmstream<T> getself()
        {
            return self;
        }
};

#endif
