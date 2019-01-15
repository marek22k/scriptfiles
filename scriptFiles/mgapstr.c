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

#include "mgapstr.h"
#include <stdlib.h>

int mgapstr_init(mgapstr * gs, size_t size)
{
    gs->ptr = (char *) malloc(sizeof(char) * (size));
    if(gs->ptr == NULL) return (gs->good = 0);
    gs->begin = 0;
    gs->end = size - 1;
    gs->size = size;
    gs->good = 1;
    return 1;
}

int mgapstr_good(mgapstr * gs)
{
    return gs->good;
}

int mgapstr_push(mgapstr * gs, char c)
{
    if(gs->good == 0 || gs->begin + 1 >= gs->end) return 0;
    gs->ptr[gs->begin] = c;
    gs->begin++;
    return 1;
}

int mgapstr_pushstr(mgapstr * gs, char * str, size_t siz)
{
    size_t i;

    if(gs->good == 0 || gs->begin + siz >= gs->end) return 0;

    for(i = 0; i < siz; i++)
        gs->ptr[gs->begin + i] = str[i];

    gs->begin += siz;
    return 1;
}

int mgapstr_left(mgapstr * gs)
{
    if(gs->good == 0 || (long) gs->begin - 1 < 0) return 0;
    gs->ptr[gs->end - 1] = gs->ptr[gs->begin - 1];
    gs->begin--;
    gs->end--;
    return 1;
}

int mgapstr_right(mgapstr * gs)
{
    if(gs->good == 0 || gs->begin + 1 > gs->size - 1) return 0;
    gs->ptr[gs->begin] = gs->ptr[gs->end];
    gs->begin++;
    gs->end++;
    return 1;
}

int mgapstr_move(mgapstr * gs, long mov)
{
    size_t i;

    if(gs->good == 0) return 0;

    if(mov > 0)
    {
        if(gs->begin + (size_t) mov > gs->size - 1) return 0;
        for(i = 0; i < (size_t) mov; i++)
            gs->ptr[gs->begin + i] = gs->ptr[gs->end + i];

        gs->begin += (size_t) mov;
        gs->end += (size_t) mov;
    }
    else if(mov < 0)
    {
        if((long) gs->begin - (-mov) < 0) return 0;
        for(i = 0; i < (size_t) (-mov); i++)
            gs->ptr[gs->end - 1 - i] = gs->ptr[gs->begin - 1 - i];

        gs->begin -= (size_t) (-mov);
        gs->end -= (size_t) (-mov);
    }
    return 1;
}

int mgapstr_output(mgapstr * gs, int (* pc)(int))
{
    size_t i;

    if(gs->good == 0) return 0;

    for(i = 0; i < gs->begin; i++)
        if(! pc((int) gs->ptr[i])) return 0;

    pc('-');

    for(i = gs->end; i < gs->size - 1; i++)
        if(! pc((int) gs->ptr[i])) return 0;

    return 1;
}

int mgapstr_delete(mgapstr * gs)
{
    if(gs->good == 0 || gs->begin - 1 > gs->end) return 0;
    gs->begin--;
    return 1;
}

int mgapstr_delchars(mgapstr * gs, size_t chars)
{
    if(gs->good == 0 || gs->begin - chars > gs->end) return 0;
    gs->begin -= chars;
    return 1;
}

char * mgapstr_get(mgapstr * gs)
{
    size_t i, siz;
    char * ptr;

    siz = gs->size - gs->end + gs->begin;
    ptr = (char *) malloc(sizeof(char) * siz);
    if(ptr == NULL) return NULL;

    for(i = 0; i < gs->begin; i++)
        ptr[i] = gs->ptr[i];

    for(i = gs->end; i < gs->size - 1; i++)
        ptr[i + gs->begin] = gs->ptr[i];

    ptr[siz - 1] = '\0';

    return ptr;
}

int mgapstr_close(mgapstr * gs)
{
    if(gs->good == 0) return 0;
    free(gs->ptr);
    gs->good = 0;
    return 1;
}
