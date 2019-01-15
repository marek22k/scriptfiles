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

#include <stdio.h>  /* fprintf, printf, stderr, scanf */
#include <stdlib.h>  /* abort, malloc, realloc, free, NULL, abort, exit */
#include <string.h>  /* strcpy, strat, strlen */
#include <ctype.h>  /* toupper, isalpha, isdigit */
#include <math.h>  /* pow */

void errhandling(int errcode);
void CloseFromBase10(char * ptr);
void reverse(const char * str, char* cpy);
char * FromBase10(const int num, const int base, const void (* errhandling) (int));
int ToBase10(const char * num, const int base, const void (* errhandling) (int));
int ccti(char x);  // ccti = Convert Char To Integer

int main()
{
    int select = -1, numi, base;
    char * numc, nums[255];
    printf(
            "Base Converter\n"
            "==============\n"
            "\n"
            "1 - From base 10\n"
            "2 - To base 10\n"
            "3 - Exit\n"
            "\n"
            "Option: "
           );
    scanf("%d", &select);
    switch(select)
    {
        case -1:
            errhandling(0x0003);
            break;
        case 1:
            {
                printf(
                        "\n\nFrom base 10\n"
                        "============\n"
                        "\n"
                        "Number: "
                        );
                scanf("%d", &numi);
                printf("Base: ");
                scanf("%d", &base);
                numc = FromBase10(numi, base, &errhandling);
                printf("\nAnswer: %s", numc);
                CloseFromBase10(numc);
                break;
            }
        case 2:
            {
                printf(
                        "\n\To base 10\n"
                        "==========\n"
                        "\n"
                        "Number: "
                        );

                scanf("%s", &nums);
                printf("Base: ");
                scanf("%d", &base);
                numi = ToBase10(nums, base, &errhandling);
                printf("\nAnswer: %d", numi);
                break;
            }
        case 3:
            exit(0);
    }
    return 0;
}

void errhandling(int errcode)
{
    fprintf(stderr, "Errorcode: %d;\n", errcode);
    abort();
}

void CloseFromBase10(char * ptr)
{
    free(ptr);
    ptr = NULL;
}

void reverse(const char * str, char* cpy)
{
    int len = strlen(str);
    register int i;
    char res[len];

    for(i = 0; i < len; i++)
        res[i] = str[len-i-1];

    strcpy(cpy, res);
}

char * FromBase10(const int num, const int base, const void (* errhandling) (int))
{
    static char * res;
    char temp, * ptr;
    register int len = 0, calc = num, tmp, tmp1, tmp2;
    res = malloc(++len * sizeof(char));
    res[0] = 0;

    while(calc != 0)
    {
        tmp = tmp2 = calc % base;
        ptr = realloc(res, ++len * sizeof(char));
        if(ptr != NULL)
        {
            if(res != ptr) free(res);
            res = ptr;
        }
        else
            errhandling(0x0001);

        for(tmp1 = 1; tmp2 > 9; tmp1++) tmp2 /= 10;

        ptr = malloc(tmp1 * sizeof(char));
        if(tmp < 9)
            sprintf(ptr, "%d", tmp);
        else
            sprintf(ptr, "%c", 'A' - 10 + tmp);
        strcat(res, ptr);
        calc = calc / base;
    }

    reverse(res, res);

    return res;
}

int ToBase10(const char * num, const int base, const void (* errhandling) (int))
{
    int len = strlen(num);
    register int i, res = 0, tmp;

    for(i = 0; i < len; i++)
    {
        tmp = ccti(num[len-1-i]);
        if(tmp == -1) errhandling(0x0002);
        res += tmp * pow(base, i);
    }

    return res;
}

int ccti(char x)
{
    if(isdigit(x))
        return (int) (x - '0');
    else if(isalpha(x))
        return (int) (toupper(x) - 55);
    else
        return -1;
}
