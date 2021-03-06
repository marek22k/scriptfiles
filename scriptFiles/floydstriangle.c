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

#include <stdio.h>  /* fflush, stdout, fprintf, stderr, printf */
#include <stdlib.h>  /* abort, atoi, EXIT_SUCCESS */

void ErrorHandler(int err);

int main(int argc, char *argv[])
{
    int n = -1;

    if(argc < 2) ErrorHandler(0x0001);

    n = atoi(argv[1]);

    if(n == 0) ErrorHandler(0x0001);

    register int i, j, num;

    for(i = 1, num = 1; i <= n; i++)
    {
        for(j = 0; j < i; j++, num++)
        {
            printf("%d ", num);
        }
        printf("\n");
    }

    return EXIT_SUCCESS;
}

void ErrorHandler(int err)
{
    fflush(stdout);
    fprintf(stderr, "Errorcode: %d; Errormessage: ", err);
    switch(err)
    {
        case 0x0001:
            {
                fprintf(stderr, "Please enter the first argument a number! (Not 0)");
                break;
            }
    }
    abort();
}
