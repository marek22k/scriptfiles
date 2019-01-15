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

#include "mbignum.hpp"

#include <new>  /* new [], delete [] */
#include <stdexcept>  /* runtime_error */
#include <string>  /* string */

#include <cstring>  /* strcpy, strcat */
#include <cstddef>  /* size_ t */
#include <iostream>
mbignum::mbignum(MBN_LEN n) : nlen(n)
{
    str = new char[nlen];
    str[0] = static_cast<char>(0);
}

void mbignum::destroy() noexcept
{
    delete [] str;
    str = nullptr;
}

inline bool mbignum::good() const noexcept
{
    return str != nullptr;
}

inline bool mbignum::bad() const noexcept
{
    return ! good();
}

bool mbignum::zero() const noexcept
{
    MBN_LEN len = strlen(str);

    for(MBN_LEN i = 0; i < len; i++)
    {
        if(str[i] != '0') return false;
    }

    return true;
}

MBN_LEN mbignum::maxlength() const noexcept
{
    return nlen;
}

MBN_LEN mbignum::length() const noexcept
{
    return static_cast<MBN_LEN>(strlen(str));
}

char * mbignum::ptr() const noexcept
{
    return str;
}

inline void mbignum::operator=(char cs[])
{
    strcpy(str, cs);
}

mbignum mbignum::operator+(mbignum & other) const
{
    if(other.bad() || bad()) throw std::runtime_error("Not good!");
    mbignum ret(nlen);
    MBN_LEN u = 0;
    MBN_LEN len1 = strlen(str);
    MBN_LEN len2 = strlen(other.str);

    if(len1 > len2)
    {
        char * tmp = new char[len1];
        strcpy(tmp, other.str);
        strcpy(other.str, "0");
        len2++;

        while(len1 > len2)
            strcat(other.str, "0"), len2++;

        strcat(other.str, tmp);
        delete [] tmp;
    }

    if(len2 > len1)
    {
        char * tmp = new char[len2];
        strcpy(tmp, str);
        strcpy(str, "0");
        len1++;

        while(len2 > len1)
            strcat(str, "0"), len1++;

        strcat(str, tmp);
        delete [] tmp;
    }

    char * buf = new char[static_cast<size_t>(len1 + 2)];

    for(int i = len1-1; i >= 0; i--)
    {
        MBN_LEN c1 = str[i] - '0';
        MBN_LEN c2 = other.str[i] - '0';
        MBN_LEN c3 = static_cast<MBN_LEN>(u);
        MBN_LEN res = c1 + c2 + c3;

        u = 0;
        while(res >= 10)
            res -= 10,
            u += 1;

        buf[i + 1] = static_cast<char>(res) + '0';
    }

    buf[len1 + 1] = static_cast<char>(0);
    buf[0] = static_cast<char>(u) + '0';
    ret = buf;
    delete [] buf;

    return ret;
}

mbignum mbignum::operator-(mbignum & other) const
{
    if(other.bad() || bad()) throw std::runtime_error("Not good!");
    mbignum ret(nlen);
    bool u = false;
    MBN_LEN len1 = strlen(str);
    MBN_LEN len2 = strlen(other.str);

    if(len1 > len2)
    {
        char * tmp = new char[len1];
        strcpy(tmp, other.str);
        strcpy(other.str, "0");
        len2++;

        while(len1 > len2)
            strcat(other.str, "0"), len2++;

        strcat(other.str, tmp);
        delete [] tmp;
    }

    if(len2 > len1)
    {
        char * tmp = new char[len2];
        strcpy(tmp, str);
        strcpy(str, "0");
        len1++;

        while(len2 > len1)
            strcat(str, "0"), len1++;

        strcat(str, tmp);
        delete [] tmp;
    }

    char * buf = new char[static_cast<size_t>(len1 + 2)];

    for(int i = len1-1; i >= 0; i--)
    {
        MBN_LEN c1 = str[i] - '0';
        MBN_LEN c2 = other.str[i] - '0';
        MBN_LEN c3 = static_cast<MBN_LEN>(u);
        int res = c1 - c2 - c3;

        u = 0;
        while(res < 0)
            res += 10,
            u += 1;

        buf[i + 1] = static_cast<char>(res) + '0';
    }

    buf[len1 + 1] = static_cast<char>(0);
    buf[0] = static_cast<char>(u) + '0';
    ret = buf;
    delete [] buf;

    return ret;
}

mbignum mbignum::operator+=(mbignum & other)
{
    *this = *this + other;
    return *this;
}

mbignum mbignum::operator-=(mbignum & other)
{
    *this = *this - other;
    return *this;
}

bool mbignum::operator==(mbignum & other) const noexcept
{
    return ! strcmp(str, other.str);
}

bool mbignum::operator!=(mbignum & other) const noexcept
{
    return strcmp(str, other.str);
}

std::string to_string(mbignum mbn)
{
    return std::string(mbn.str);
}
