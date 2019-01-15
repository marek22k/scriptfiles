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

int lifes(_Bool circle[], int len);
int wholife(int sperson, _Bool circle[], int len);

int main()
{
    int n = 10;
    register int i = 0, sword = 1, d;

    printf("n: ");
    scanf("%d", &n);

    _Bool circle[n];

    for(i = 0; i < n; i++)
        circle[i] = 1;

    while(lifes(circle, n) != 1)
    {
        d = wholife(sword+1, circle, n);
        circle[d-1] = 0;
        printf("Person %d kills person %d;\n", sword, d);

        printf("Person %d has the sword;\n\n", (sword=wholife(sword+1, circle, n)));
    }

    printf("Person %d survives.", wholife(1, circle, n));


    return 0;
}

int lifes(_Bool circle[], int len)
{
    register int i, res = 0;

    for(i = 0; i < len; i++)
        if(circle[i]) res++;

    return res;
}

int wholife(int sperson, _Bool circle[], int len)
{
    register int i;

    for(i = sperson-1; i < len; i++)
        if(circle[i]) return i+1;

    return wholife(1, circle, len);
}
