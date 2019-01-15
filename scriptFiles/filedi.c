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

#include <stdio.h>  /* printf, scanf, fprintf, putchar, fgetc, fopen, fflush, fclose, FILE, stdout, stderr, EOF */
#include <string.h>  /* strerror */
#include <errno.h>  /* errno */
#include <stdlib.h>  /* exit, EXIT_SUCCESS, EXIT_FAILURE, atexit, malloc, free */
#include <signal.h>  /* signal, SIGABRT, SIGFPE, SIGILL, SIGINT, SIGSEGV, SIGTERM */

#define STLO 65535
// STLO = Stop loading
#define PROGNAME "filedi"
// PROGNAME = Program name

static FILE * f;  // f = File
static char * fn;  // fn = filename

void AppCloseHandler();
void SignalHandler(int sig);

int main ()
{
    atexit(AppCloseHandler);

    signal(SIGABRT, SignalHandler);
    signal(SIGFPE, SignalHandler);
    signal(SIGILL, SignalHandler);
    signal(SIGINT, SignalHandler);
    signal(SIGSEGV, SignalHandler);
    signal(SIGTERM, SignalHandler);

    register int tmp, i;
    int tmp2;

    fn = (char *) malloc(0);

    printf("Filename: ");
    fflush(stdout);
    scanf("%s", fn);
    printf("\n");

    f = fopen(fn, "r");

    if(f == 0)
    {
        fprintf(stderr, "Error in the file %s.c line %d: %s;", PROGNAME, __LINE__, strerror(errno));
        exit(EXIT_FAILURE);
    }

    for(i = 0; (tmp=fgetc(f)) != EOF; i++)
    {
        putchar(tmp);
        if(i >= STLO)
        {
            printf("\nDo you want to continue loading the file? (0/1): ");
            scanf("%d", &tmp2);
            if(tmp2 == 0) break;
            i = 0;
        }
    }

    return EXIT_SUCCESS;
}

void AppCloseHandler()
{
    fflush(stdout);
    fflush(stderr);
    fclose(f);
    free(fn);
}

void SignalHandler(int sig)
{
    fflush(stdout);
    fprintf(stderr, "\n\nThe following signal was sent: ");
    switch(sig)
    {
        case SIGABRT:
            fprintf(stderr, "Signal Abort(SIGABRT)");
            break;
        case SIGFPE:
            fprintf(stderr, "Signal Floating-Point Exception(SIGFPE)");
            break;
        case SIGILL:
            fprintf(stderr, "Signal Illegal Instruction(SIGILL)");
            break;
        case SIGINT:
            fprintf(stderr, "Signal Interrupt(SIGINT)");
            break;
        case SIGSEGV:
            fprintf(stderr, "Signal Segmentation Violation(SIGSEGV)");
            break;
        case SIGTERM:
            fprintf(stderr, "Signal Terminate(SIGTERM)");
            break;
    }
    fprintf(stderr, "\nThe process is finished!");
    exit(EXIT_FAILURE);
}
