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
#include <time.h>

#define TEST_TIME 3
#define TEST_TIME_D 3.0

int main()
{
    time_t tim;
    FILE * f;
    char * c;
    unsigned m = 0, tmp;

    printf("Start program...\n");
    printf("Create variables: OK\n");

    f = fopen("bytes.tmp", "w");
    if(f == NULL) abort();
    printf("Create and open file: OK\n");
    m = 0;

    printf("Set time and start test...\n");
    tim = time( NULL );

    while(tim+TEST_TIME >= time( NULL ))
    {
        fputc(0, f);
        m++;
    }

    printf("\nWrite: %lf MegaBytes/s\n", m/TEST_TIME_D/1024.0/1024.0);
    tmp = m;

    printf("Set time and start test...\n");
    tim = time( NULL );
    while(tim+TEST_TIME >= time( NULL ))
    {
        fgetc(f);
        m++;
    }

    printf("\nRead: %lf MegaBytes/s\n", m/TEST_TIME_D/1024.0/1024.0);

    if(m >= tmp) printf("Write vs. Read: OK\n");
    else printf("Write vs. Read: NOT OK\n");

    fclose(f);

    m = 1;
    printf("Set time and start test...\n");
    tim = time( NULL );
    c = malloc(m++);
    while(tim+TEST_TIME >= time( NULL ))
    {
        if(!(c = realloc(c, m))) goto ALT2;
        m++;
    }

    free(c);

    goto ALT1;
    ALT2: printf("\nAllocate(Aborted): %lf MegaBytes/s\n", (time( NULL ) - tim)/TEST_TIME_D/1024.0/1024.0);
    ALT1: printf("\nAllocate: %lf MegaBytes/s\n", m/TEST_TIME_D/1024.0/1024.0);

    m = 0;
    printf("Set time and start test...\n");
    tim = time( NULL );
    while(tim+TEST_TIME >= time( NULL ))
    {
        m++;
    }

    printf("\nNumbers: %lf Mega/s\n", m/TEST_TIME_D/1024.0/1024.0);

    printf("Test complete!");

    return EXIT_SUCCESS;
}
