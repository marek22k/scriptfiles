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

#include <stdio.h>  /* printf */
#include <stdlib.h>  /* abort */
#include <limits.h>  /* ULONG_MAX */
#define MMEMORY_H
#include "mioxo.h"  /* cptr, mixo, mixo_close, LIMIT_255 */
#undef MMEMORY_H

int main()
{
    cptr cp;
    register int i;
    register unsigned long int sum = 0;

    cp = mixo(abort, '\n', ULONG_MAX/LIMIT_255);

    for(i = 0; cp[i] != (char) 0; i++)
    {
        printf("%s%d(%c)", (cp[i]!=cp[0]?" + ":""), (int) cp[i], cp[i]);
        sum += (int) cp[i];
    }

    printf(" = %lu", sum);

    mixo_close(abort, cp);

    return 0;
}
