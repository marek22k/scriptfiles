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

_Bool isFisher(unsigned, _Bool);

int main()
{
    unsigned n = (unsigned) -1;

    printf("Please input a number: ");
    scanf("%u", &n);

    if(n == (unsigned) -1) abort();

    if(isFisher(n, 1))
        printf("\n%u is a Fisher number :-)", n);
    else
        printf("\n%u is not a Fisher number :-(", n);

    return EXIT_SUCCESS;
}

_Bool isFisher(unsigned n, _Bool op)
{
    unsigned res = 0;

    for(unsigned i = 1; i <= n; i++)
    {
        if(n%i == 0)
        {
            if(res == 0)
            {
                res = i;
                if(op) printf("%u", i);
            }
            else
            {
                res *= i;
                if(op) printf(" * %u", i);
            }
        }
    }
    if(op) printf(" = %u vs. %u * %u * %u = %u", res, n, n, n, n*n*n);
    return n*n*n == res;
}
