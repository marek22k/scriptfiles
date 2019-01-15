// mmemory.h and mmemory.c written by Marek K.

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
#ifdef __cplusplus
    #include <cstdlib>
    #include <cstddef>
#else
    #include <stdlib.h>
    #include <stddef.h>
#endif

/*
    stdlib.h(cstdlib): malloc, realloc, free
    stddef.h(cstddef): size_t
*/

#ifdef NCHECK
    #error The Macro NCHECK is defined
#else
    #define NCHECK(var) if(var == NULL) return 0;
#endif

MMEMORY_BR memnew(void ** ptr, MMEMORY_GET byte)
{
    void * ml = malloc((size_t) byte);
    NCHECK(ml)
    *ptr = ml;
    return 1;
}

MMEMORY_BR memdel(void ** ptr)
{
    NCHECK(*ptr)
    free(*ptr);
    *ptr = NULL;
    return 1;
}

MMEMORY_BR memedi(void ** ptr, MMEMORY_GET byte)
{
    NCHECK(*ptr)
    void * rl = realloc(*ptr, (size_t) byte);
    NCHECK(rl)
    if(*ptr != rl) free(*ptr);
    *ptr = rl;
    return 1;
}

#undef NCHECK
