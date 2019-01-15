// mgarlandword written by Marek K.

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

#include <stdio.h>  /* printf, fflush, scanf, stdout, stderr */
#include <stdlib.h>  /* atexit, exit, EXIT_SUCCESS, malloc, free, abort */

static char * input, * temp1, * temp2;
static _Bool argInput = 1;

_Bool strvs(char * x, char * y, int len);
void CloseHandler();
void ErrorHandler(int err);

int main(int argc, char *argv[])
{
    atexit(CloseHandler);

    if(argv[1] == NULL || argc < 1)
        ErrorHandler(0x0002);

    if(strvs(argv[1], "-v", 2))
    {
        printf(
                "mgarlandword\n"
                "============\n"
                "\n"
                "The program mgarlandword was written on 14/04/2018 by Marek K. in the C programming language.\n"
                "The program checks if it is a Garland word.\n"
                "\n"
                "Error 0x0001: Could not allocate memory.\n"
                "Error 0x0002: No start argument was specified.\n"
                "\n"
                "Argument -v: Version\n"
                "Argument -i: Word input at runtime (maximum 255 characters)\n"
                "Argument * (Other arguments): The word that should be checked\n"
                "\n"
                "Version: %s %s"
                "\n"
        , __DATE__, __TIME__);
        exit(EXIT_SUCCESS);
    }

    register int i, j, len, degree = 0;
    int ltmp;
    argInput = !(strvs(argv[1], "-i", 2));

    if(argInput)
        input = argv[1];
    else if((input = (char *) malloc(255 * sizeof(char))) == NULL)
            ErrorHandler(0x0001);

    printf("Word: ");
    if(argInput) printf("%s\n", input);

    fflush(stdout);
    if(!argInput) scanf("%s", input);

    for(len = 0; input[len] != 0; len++);
    ltmp = (len/2+1);

    for(i = 1; i < ltmp; i++)
    {
        temp1 = (char *) malloc((unsigned) i * sizeof(char)),
        temp2 = (char *) malloc((unsigned) i * sizeof(char));

        if(temp1 == NULL || temp2 == NULL)
            ErrorHandler(0x0001);

        for(j = 0; j < i; j++)
            temp1[j] = input[j],
            temp2[j] = input[len-i+j];

        temp1[j] = 0,
        temp2[j] = 0;

        printf("%s vs. %s\n", temp1, temp2);

        if(strvs(temp1, temp2, i))
            degree = i;

        free(temp1);
        free(temp2);

        temp1 = NULL,
        temp2 = NULL;
    }

    if(degree)
        printf("\"%s\" ist a garland Word with degree %d.", input, degree);
    else
        printf("\"%s\" ist not a garland Word.", input);

    return EXIT_SUCCESS;
}

_Bool strvs(char * x, char * y, int len)
{
    register int i;
    for(i = 0; i < len; i++)
    {
        if((char) x[i] != (char) y[i]) return 0;
    }
    return 1;
}

void CloseHandler()
{
    free(temp1);
    free(temp2);
    if(!argInput) free(input);

    temp1 = NULL,
    temp2 = NULL;
    if(!argInput) input = NULL;
}

void ErrorHandler(int err)
{
    fflush(stdout);

    fprintf(stderr, "Error: ");

    switch(err)
    {
        case 0x0001:
            {
                fprintf(stderr, "Could not allocate memory.");
                break;
            }
        case 0x0002:
            {
                fprintf(stderr, "No start argument was specified. (Please use the arguments -v, -i or enter the word to be checked.)");
                break;
            }
        default:
            {
                fprintf(stderr, "An unknown error has occurred.");
                break;
            }
    }

    fprintf(stderr, "; Errorcode %d;\n", err);

    abort();
}
