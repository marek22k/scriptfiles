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
#include "dynarr.h"

int findByValue(DynArr *da, int val);

int main()
{
    int n = 20, p = 2;
    register int calc, i, index, pos;
    DynArr v;

    DynArr_init(&v);
    scanf("%d", &n);

    for(i = 2; i <= n; i++)
        DynArr_push(&v, i);

    for(pos = 0; p*p <= n && pos < v.size; p = DynArr_at(&v, pos++))
        for(calc = p*p; calc <= n; calc += p)
        {
            index = findByValue(&v, calc);
            if(index != -1)
                DynArr_del(&v, index);

        }

    for(i = 0; i < v.size; i++)
        printf("%s%d;", (i==0?"":" "), DynArr_at(&v, i));

    return 0;
}

int findByValue(DynArr *da, int val)
{
    register int i;

    for(i = 0; i < da->size; i++)
        if(DynArr_at(da, i) == val)
            return i;

    return -1;
}
