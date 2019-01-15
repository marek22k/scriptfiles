// remspechars = removespecialcharacters
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

#include <stdio.h>
#include <stdlib.h>

#ifdef __bool_true_false_are_defined
#ddefine BOOLR bool
#elif __STDC_VERSION__ >= 201112L
#define BOOLR _Bool
#else
#define BOOLR int
#endif

typedef char * cptr;

static cptr str, res, tmpptr;

void errhandling(int, int);
void allfree();
BOOLR isNuOrAl(char);

int main()
{
    register unsigned i, cur, siz;
    unsigned len;

    atexit(&allfree);
    str = (char *) malloc(1 * sizeof(char));
    if(str == NULL) errhandling(0x0002, __LINE__);
    str[0] = (char) 0;
    scanf("%s", str);
    if(str[0] == (char) 0) errhandling(0x0001, __LINE__);
    for(len = 0; str[len] != (char) 0; len++);

    siz = len;
    cur = 0;
    res = (char *) malloc(siz * sizeof(char));
    if(res == NULL) errhandling(0x0002, __LINE__);

    for(i = 0; i < len; i++)
    {
        if(cur+1 >= siz)
        {
            siz += len/2;
            tmpptr = (char *) realloc(res, siz * sizeof(char));
            if(tmpptr == NULL) errhandling(0x0002, __LINE__);
            if(res != tmpptr) free(res);
            res = tmpptr;
        }
        if(isNuOrAl(str[i]))
            res[cur++] = str[i];
    }

    res[cur] = (char) 0;
    printf("%s", res);

    return EXIT_SUCCESS;
}

void errhandling(int err, int line)
{
    fprintf(stderr, "Error %d in line %d; Errormessage: ", err, line);
    switch(err)
    {
        case 0x0001:
        {
            fprintf(stderr, "Invalid input!");
            break;
        }
        case 0x0002:
        {
            fprintf(stderr, "Could not allocate memory.");
            break;
        }
        default:
        {
            fprintf(stderr, "Unknown error.");
        }
    }
    abort();
}

void allfree()
{
    free(str);
    str = NULL;
    free(res);
    res = NULL;
}

BOOLR isNuOrAl(char x)
{
    if(
    (x >= '0' &&
    x <= '9') ||

    (x >= 'A' &&
    x <= 'Z') ||

    (x >= 'a' &&
    x <= 'z')
    ) return 1;
    return 0;
}
