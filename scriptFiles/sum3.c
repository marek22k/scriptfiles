// sum3 written by Marek K.

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

#include <stdio.h>  /* scanf, printf, fflush, stdout, fprintf, stderr */
#include <stdlib.h>  /* NULL, exit, EXIT_SUCCESS, malloc, free */
#include <string.h>  /* strcmp */

static int * input = NULL;

void ErrorHandler(int err);
void CloseHandler();

int main(int argc, char *argv[])
{
    atexit(CloseHandler);

    if(strcmp((argv[1]==NULL?"":argv[1]), "-v") == 0)
    {
        if(strcmp((argv[2]==NULL?"":argv[2]), "-de") == 0)
        {
            printf(
                   "sum3\n"
                   "====\n"
                   "\n"
                   "Das Programm sum3 wurde am 15/04/2018 von Marek K. in der Progarmmiersprache C geschrieben.\n"
                   "\n"
                   "Eingabe\n"
                   "=======\n"
                   "\n"
                   "Eingabe zur Laufzeit:\n"
                   "  1. Als erstes gibt man die Anzahl der Zahlen ein, die man eingeben moechte.\n"
                   "  2. Danach gibt man die Zahlen ein aus denen die Dreiergruppe berchnet werden soll.\n"
                   "\n"
                   "Kein Argument: siehe ->Eingabe zur Laufzeit<-\n"
                   "Argument -v: Version in Englisch\n"
                   "Argument -v -de: Version in Deutsch\n"
                   "\n"
                   "Fehler\n"
                   "======\n"
                   "\n"
                   "Error 0x0001(1): Invalid input! (Ungueltige Eingabe!)\n"
                   "Behandlung: UEberpruefen Sie ihre Eingabe.\n"
                   "            Die Anzahl der Zahlen, die Sie Eingeben wollen, sollte groeszer als 2 sein.\n"
                   "\n"
                   "Error 0x0002(2): Could not allocate memory! (Speicher konnte nicht zugewiesen werden!)\n"
                   "Behandlung: Eventuell ist nicht genuegend Arbeitsspeicher verfuegbar oder das Programm kann nicht auf den Arbeitsspeicher zugreifen.\n"
                   "\n"
                   "\n"
                   "Version: %s %s\n"
                   , __DATE__, __TIME__);
        }
        else
        {
            printf(
                   "sum3\n"
                   "====\n"
                   "\n"
                   "The program sum3 was written on 15/04/2018 by Marek K. in the programming language C.\n"
                   "\n"
                   "Input\n"
                   "=====\n"
                   "\n"
                   "Input at runtime:\n"
                   "  1. First, enter the number of digits you want to enter.\n"
                   "  2. Then you enter the numbers from which the triple is to be calculated.\n"
                   "\n"
                   "No argument: see ->Input at runtime<-\n"
                   "Argument -v: Version in English\n"
                   "Argument -v -de: Version in German\n"
                   "\n"
                   "Errors\n"
                   "======\n"
                   "\n"
                   "Error 0x0001(1): Invalid input!\n"
                   "Handling: Check your input.\n"
                   "          The number of numbers you want to enter should be greater than 2.\n"
                   "\n"
                   "Error 0x0002(2): Could not allocate memory!\n"
                   "Handling: There may not be enough memory or the program can not access memory.\n"
                   "\n"
                   "\n"
                   "Version: %s %s\n"
                   , __DATE__, __TIME__);
        }
        exit(EXIT_SUCCESS);
    }

    int len = -1;
    register int i, j, k;
    register _Bool f;

    scanf("%d", &len);
    if(len < 3)
        ErrorHandler(0x0001);

    input = (int *) malloc((unsigned) len * sizeof(int));
    if(input == NULL) ErrorHandler(0x0002);
    for(i = 0; i < len; i++)
        scanf("%d", &input[i]);


    for(i = 0; i < len; i++)
        for(j = i+1; j < len; j++)
            for(k = j+1; k < len; k++)
                if((input[i] + input[j] + input[k]) == 0)
                {
                    printf("%d + %d + %d = 0\n", input[i], input[j], input[k]);
                    f = 1;
                }

    if(!f)
        printf("No triplets found!");

    return EXIT_SUCCESS;
}

void ErrorHandler(int err)
{
    fflush(stdout);
    fprintf(stderr, "\nAn error has occurred :-(\nErrorcode: %d;\nErrormessage: ", err);
    switch(err)
    {
        case 0x0001:
            {
                fprintf(stderr, "Invalid input!");
                break;
            }
        case 0x0002:
            {
                fprintf(stderr, "Could not allocate memory!");
                break;
            }
    }
    fprintf(stderr, "\n");
    fflush(stderr);
    abort();
}

void CloseHandler()
{
    free(input);
    input = NULL;
}
