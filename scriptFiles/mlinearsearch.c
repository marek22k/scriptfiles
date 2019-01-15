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

#include "mlinearsearch.h"

#if __STDC_VERSION__ >= 199901L
    #define MLINEARSEARCH_INLINE inline
#else
    #define MLINEARSEARCH_INLINE
#endif  // __STDC_VERSION__

void * mlinearsearch(register void * arr, const unsigned long ind, const unsigned siz, const void * const elem, int (* found)(const void * a, const void * b))
{
    void * b = (void *) ((unsigned long) arr + ind * siz);

    for(; arr < b; arr = (void *) ((unsigned long) arr + siz))
        if(found(arr, elem))
            return arr;

    return (void *) 0;
}

MLINEARSEARCH_INLINE int mintfound(const void * const a, const void * const b)  // int
{
    return *(int *)a == *(int *)b;
}

MLINEARSEARCH_INLINE int muintfound(const void * const a, const void * const b)  // unsigned int
{
    return *(unsigned int *)a == *(unsigned int *)b;
}

MLINEARSEARCH_INLINE int mshrtfound(const void * const a, const void * const b)  // short
{
    return *(short *)a == *(short *)b;
}

MLINEARSEARCH_INLINE int mushrtfound(const void * const a, const void * const b)  // unsigned short
{
    return *(unsigned short *)a == *(unsigned short *)b;
}

MLINEARSEARCH_INLINE int mlongfound(const void * const a, const void * const b)  // long
{
    return *(long *)a == *(long *)b;
}

MLINEARSEARCH_INLINE int mulongfound(const void * const a, const void * const b)  // unsigned long
{
    return *(unsigned long *)a == *(unsigned long *)b;
}

MLINEARSEARCH_INLINE int mcharfound(const void * const a, const void * const b)  // char
{
    return *(char *)a == *(char *)b;
}

int mucharfound(const void * const a, const void * const b)  // unsigned char
{
    return *(unsigned char *)a == *(unsigned char *)b;
}
