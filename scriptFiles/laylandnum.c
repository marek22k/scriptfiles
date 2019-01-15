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
#include <math.h>

_Bool isLeyland(int num, _Bool op);

int main()
{
    int x;
    printf("Please enter a number: ");
    scanf("%d", &x);
    _Bool il = isLeyland(x, 1);
    if(il)
        printf("\n%d is a Leyland number.", x);
    else
        printf("%d is not a Leyland number.", x);
    return 0;
}

_Bool isLeyland(int num, _Bool op)
{
    for(int i = 2; i < num; i++)
        for(int j = 2; j < num; j++)
        {
            if(pow(i, j) + pow(j, i) == num)
            {
                if(op) printf("%d = %d^%d + %d^%d", num, i, j, j, i);
                return 1;
            }
        }
    return 0;
}
