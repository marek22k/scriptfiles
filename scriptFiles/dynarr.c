/*
    DynArr written by Marek K.

    You can find a description / example / short instructions in the header file.
*/

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

#include "dynarr.h"  /* DynArr */
#include <stdlib.h>  /* malloc, realloc, free, NULL */

#define LEN (da->size)
#define ARR (da->arr)
#define NCHECK(var) if((var) == NULL) return 0;

int DynArr_init(DynArr * da)
{
    return ((ARR=(int *) malloc((LEN=0) * sizeof(*(ARR))))==NULL?0:1);
}

int DynArr_push(DynArr * da, int element)
{
    NCHECK(ARR)
    int * ptr = ARR;

    ARR = (int *) realloc(ARR, (unsigned) ++LEN * sizeof(*(ARR)));

    if(ptr != ARR)
        free(ptr);
    NCHECK(ARR)

    ARR[LEN-1] = element;

    return 1;
}

int DynArr_del(DynArr * da, int index)
{
    NCHECK(ARR)

    int arr[LEN], i, j = 0, * ptr;

    for(i = 0; i < LEN; i++)
        arr[i] = ARR[i];

    ptr = (int *) malloc((unsigned) LEN-- * sizeof(*(ARR)));
    if(ptr == NULL) return 0;
    free(ARR);
    ARR = ptr;

    for(i = -1; i++ < LEN; j++)
        ARR[i] = (j==index?arr[++j]:arr[j]);

    return 1;
}

int DynArr_at(DynArr * da, int index)
{
    return (ARR==NULL?0:ARR[index]);
}

int DynArr_close(DynArr * da)
{
    if(ARR == NULL)
        return 0;

    free(ARR);
    ARR = NULL;
    LEN = -1;

    return 1;
}

int DynArr_isopen(DynArr * da)
{
    return (ARR == NULL || LEN == -1?0:1);
}

int DynArr_pop(DynArr * da)
{
    return DynArr_del(da, LEN);
}

int DynArr_edit(DynArr * da, int index, int newval)
{
    NCHECK(ARR)
    ARR[index] = newval;
    return 1;
}

int DynArr_insert(DynArr * da, int index, int element)
{
    int i, j = 0, * ptr, arr[LEN];

    for(i = 0; i < LEN; i++)
        arr[i] = ARR[i];

    ptr = (int *) realloc(ARR, (unsigned) ++LEN * sizeof(*(ARR)));
    if(ptr == NULL) return 0;
    ARR = ptr;

    for(i = 0; i < LEN; i++)
        ARR[i] = (i==index?element:arr[j++]);

    return 1;
}

#undef LEN
#undef ARR
#undef NCHECK
