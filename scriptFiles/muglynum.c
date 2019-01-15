// muglynum written by Marek K.

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

#include <stdio.h>  /* printf, scanf, fprintf, stderr */
#include <stdlib.h>  /* exit, EXIT_FAILURE, EXIT_SUCCESS */
#include <math.h>  /* pow */

_Bool isUgly(int, _Bool);

int main()
{
    int c = -1;
    _Bool res;

    printf("Please enter a number: ");
    scanf("%d", &c);
    if(c == -1)
    {
        fprintf(stderr, "Invalid input!");
        exit(EXIT_FAILURE);
    }
    res = isUgly(c, 1);
    if(res)
        printf("%d is a ugly Number!", c);
    else
        printf("%d is not a ugly Number!", c);

    return EXIT_SUCCESS;
}

_Bool isUgly(int num, _Bool op)
{
    register int i, j, k, sum;

    for(i = 0; i < num; i++)
        for(j = 0; j < num; j++)
            for(k = 0; k < num; k++)
            {
                sum = pow(2, i) * pow(3, j) * pow(5, k);
                if(sum == num)
                {
                    if(op) printf("2^%d * 3^%d * 5^%d = %d\n", i, j, k, sum);
                    return 1;
                }
            }

    return 0;
}
