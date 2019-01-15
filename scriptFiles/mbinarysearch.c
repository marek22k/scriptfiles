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

#include "mbinarysearch.h"

#if __STDC_VERSION__ >= 199901L
    #define MBINARYSEARCH_INLINE inline
#else
    #define MBINARYSEARCH_INLINE
#endif  // __STDC_VERSION__

long * mbinarysearchrec(long * arr, long num, int s, int e, long (* bigger)(long *, long *))
{
    int middle = e/2-s/2-1;

    if(!bigger(&num, arr+middle))
        return arr+middle;
    else if(e-s-2 <= 1)
        return (long *) 0;
    else if(bigger(&num, arr+middle) >= 1)
        return mbinarysearchrec(arr, num, middle, e+2, bigger);
    else if(bigger(&num, arr+middle) <= -1)
        return mbinarysearchrec(arr, num, s, middle+2, bigger);

    return (long *) 0;
}

long * mbinarysearch(long * arr, long num, int s, int e, long (* bigger)(long *, long *))
{
    int middle = e/2-s/2-1;

    while(1)
        if(!bigger(&num, arr + (middle=e/2-s/2-1)))
            return arr+middle;
        else if(e-s-2 <= 1)
            return (long *) 0;
        else if(bigger(&num, arr+middle) >= 1)
            s = middle,
            e += 2;
        else if(bigger(&num, arr+middle) <= -1)
            e = middle + 2;

    return (long *) 0;
}

MBINARYSEARCH_INLINE long mbinarysearch_compare(long * a, long * b)
{
    return *a-*b;
}
