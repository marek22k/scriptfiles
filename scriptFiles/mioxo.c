// MIOXO written by Marek K.

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

#include "mmemory.h"
#include "mioxo.h"
#include <stdio.h>

const int
NO_LIMIT = -1,
LIMIT_1 = 1,
LIMIT_3 = 3,
LIMIT_7 = 7,
LIMIT_15 = 15,

LIMIT_31 = 31,
LIMIT_63 = 63,
LIMIT_127 = 127,
LIMIT_255 = 255,

LIMIT_511 = 511,
LIMIT_1023 = 1023,
LIMIT_2047 = 2047,
LIMIT_4095 = 4095,

LIMIT_8191 = 8191,
LIMIT_16383 = 16383,
LIMIT_32767 = 32767,
LIMIT_65535 = 65535;

cptr mixo(void (* err) (), char end, int limit)
{
    cptr ptr;
    char c;
    register int siz;

    if(!memnew(MPTRDEF_CONVERT(void *) &ptr, MMEMORY_ARR(siz=0, char))) err();

    do
    {
        if(!memedi(MPTRDEF_CONVERT(void *) &ptr, MMEMORY_ARR(++siz, char))) err();
        ptr[siz-1] = c = (char) getchar();
    } while(c != end && limit-- != 0);

    ptr[siz-1] = (char) 0;

    return ptr;
}

void mixo_close(void (* err) (), cptr cp)
{
    if(!memdel(MPTRDEF_CONVERT(void *) &cp)) err();
}

void moxo(cptr str, int limit, char end)
{
    register int i;
    for(i = 0; limit-- != 0 && str[i] != end; i++)
        putchar(str[i]);
}

void moxo_limit(cptr str, int limit)
{
    register int i;
    for(i = 0; limit-- != 0; i++)
        putchar(str[i]);
}

void moxo_end(cptr str, char end)
{
    register int i;
    for(i = 0; str[i] != end; i++)
        putchar(str[i]);
}
