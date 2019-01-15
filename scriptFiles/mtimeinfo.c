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
#include <stdlib.h>  /* exit, EXIT_SUCCESS */
#include <locale.h>  /* lconv, localeconv, setlocale */
#include <time.h>  /* time_t, time, ctime */
#include <string.h>  /* strlen, strcmp */

int main(int argc, char * argv[])
{
    time_t curtime, firt;
    char buf1[255], buf2[255];
    struct lconv * lc;

    if(argc < 2) setlocale(LC_ALL, "");
    else if(!strcmp(argv[1], "-v") && argc == 2) printf(
                                            "Name: mtimeinfo\n"
                                            "Compile time: " __TIME__ " " __DATE__ "\n"
                                            "Author: Marek K."
                                           ), exit(EXIT_SUCCESS);
    else setlocale(LC_ALL, argv[1]);

    time( &curtime );
    firt = 0;
    lc = localeconv();

    strcpy(buf1, ctime(&curtime));
    strcpy(buf2, ctime(&firt));

    buf1[strlen(buf1)-1] = (char) 0;
    buf2[strlen(buf2)-1] = (char) 0;

    printf("Locale: %s\n", setlocale(LC_ALL, NULL));
    printf("Time: %s (%ld seconds after %s)\n", buf1, curtime, buf2);
    printf("Decimal point: %s\n", lc->decimal_point);
    printf("Thousands split: %s\n", lc->thousands_sep);
    printf("International current symbol: %s\n", lc->int_curr_symbol);
    printf("Currency symbol: %s\n", lc->currency_symbol);
    printf("Positive sign: %s\n", lc->positive_sign);
    printf("Negative sign: %s", lc->negative_sign);

    return EXIT_SUCCESS;
}
