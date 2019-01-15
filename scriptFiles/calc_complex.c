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

#include <stdio.h>  /* printf, scanf */
#include <stdlib.h>  /* abort, EXIT_SUCCESS */
#include <float.h>  /* FLT_MAX */

int main()
{
    double x1 = FLT_MAX,
    x2 = FLT_MAX,
    y1 = FLT_MAX,
    y2 = FLT_MAX;

    printf("Please enter the first complex number: ");
    scanf("%lf %lf", &x1, &y1);

    if(x1 == FLT_MAX || y1 == FLT_MAX) abort();

    printf("Please enter the second complex number: ");
    scanf("%lf %lf", &x2, &y2);

    if(x2 == FLT_MAX || y2 == FLT_MAX) abort();

    printf("+: (%.3lf + %.3lfi) + (%.3lf + %.3lfi) = (%.3lf + %.3lfi)\n", x1, x2, y1, y2, (x1 + x2), (y1 + y2));
    printf("-: (%.3lf + %.3lfi) - (%.3lf + %.3lfi) = (%.3lf + %.3lfi)\n", x1, x2, y1, y2, (x1 - x2), (y1 - y2));
    printf("*: (%.3lf + %.3lfi) * (%.3lf + %.3lfi) = (%.3lf + %.3lfi)\n", x1, x2, y1, y2, (x1*x2 - y1*y2), (x1*y2 + x2*y1));
    printf("/: (%.3lf + %.3lfi) / (%.3lf + %.3lfi) = (%.3lf + %.3lfi)", x1, x2, y1, y2, (x1*x2 + y1*y2)/(x1*x1 + y2*y2), (y1*x2 - x1*y2)/(x1*x1+y2*y2));

    return EXIT_SUCCESS;
}
