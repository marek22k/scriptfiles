// This program is written by Marek K.

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

#include <stdio.h>  /* scanf, fflush, stdout, fprintf, stderr, printf */
#include <stdlib.h>  /* abort */

void bonacci(int sq[], int n, int m);

int main()
{
    int n = -1, m = -1;
    register int i;
    scanf("%d %d", &n, &m);

    if(m < n || n < 2 || m == -1)
    {
        fflush(stdout);
        fprintf(stderr, "Invalid input!");
        abort();
    }

    int sq[m];

    bonacci(sq, n, m);

    for(i = 0; i < m; i++)
        printf("%d%s", sq[i], (i!=m-1?" ":""));

    return 0;
}

void bonacci(int sq[], int n, int m)
{
    register int i, j;

    for(i = 0; i < n-1; i++)
        sq[i] = 0;
    sq[i] = 1;

    for(i = n; i < m; i++)
    {
        sq[i] = 0;
        for(j = i-n; j < i; j++)
            sq[i] += sq[j];
    }
}
