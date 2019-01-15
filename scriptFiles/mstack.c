// mstack written by Marek K.

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

#include "mstack.h"
#include <stdlib.h>

#ifndef MSTACK_MSK_VALID
    #define MSTACK_MSK_VALID if(msk->ptr == NULL || msk->siz == (unsigned long) -1 || msk->v != 1) return 0;
#else
    #error MSTACK_MSK_VALID is defined
#endif // MSTACK_MSK_VALID

#ifndef MSTACK_NCHECK
    #define MSTACK_NCHECK(var) if(var == NULL) return 0;
#else
    #error MSTACK_NCHECK is defined
#endif // MSTACK_NCHECK


MSTACK_BR mstack_init(mstack * msk)
{
    msk->siz = 0;
    msk->ptr = malloc(0);
    MSTACK_NCHECK(msk->ptr)
    msk->v = 1;
    return 1;
}

MSTACK_BR mstack_push(mstack * msk, MSTACK_TYPE x)
{
    MSTACK_TYPE * ptr;
    MSTACK_MSK_VALID
    ptr = (MSTACK_TYPE *) realloc(msk->ptr, ++msk->siz * sizeof(MSTACK_TYPE));
    MSTACK_NCHECK(ptr)
    if(ptr != msk->ptr) free(msk->ptr);
    msk->ptr = ptr;
    msk->ptr[msk->siz-1] = x;
    return 1;
}

MSTACK_BR mstack_pop(mstack * msk, MSTACK_TYPE * x)
{
    MSTACK_TYPE * ptr;
    MSTACK_MSK_VALID
    if(x != NULL) *x = msk->ptr[msk->siz-1];
    ptr = (MSTACK_TYPE *) realloc(msk->ptr, --msk->siz * sizeof(MSTACK_TYPE));
    if(ptr != msk->ptr) free(msk->ptr);
    msk->ptr = ptr;
    return 1;
}

MSTACK_BR mstack_top(mstack * msk, MSTACK_TYPE * x)
{
    MSTACK_MSK_VALID
    if(x != NULL) *x = msk->ptr[msk->siz-1];
    return 1;
}

MSTACK_BR mstack_close(mstack * msk)
{
    free(msk->ptr);
    msk->ptr = NULL;
    msk->siz = (unsigned long) -1;
    msk->v = 0;
    return 1;
}

#undef MSTACK_MSK_VALID
#undef MSTACK_NCHECK
