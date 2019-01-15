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
#include <string.h>

int GetKaprekars(const int num, const _Bool op);
void sort(const char* str, char* cpy);
void reverse(const char* str, char* cpy);
int DigitsNumber(register int num);

int main()
{
    int x;

    printf("Please enter a number: ");
    scanf("%d", &x);

    printf("Kaprekars: %d", GetKaprekars(x, 1));

    return 0;
}

int GetKaprekars(const int num, const _Bool op)
{
    int len = DigitsNumber(num);
    register int res = num, lres = 0, i1, i2;
    char s1[len], s2[len];

    while(res != lres)
    {
        sprintf(s1, "%d", res);

        sort(s1, s1);
        reverse(s1, s2);

        lres = res, i1 = atoi(s1), i2 = atoi(s2);
        if(i1 > i2)
        {
            res = i1-i2;
            if(op) printf("%d - %d", i1, i2);
        }
        else
        {
            res = i2-i1;
            if(op) printf("%d - %d", i2, i1);
        }
        if(op) printf(" = %d\n", res);
    }

    return res;
}

void sort(const char* str, char* cpy)
{
    int len = strlen(str);
    register int i;
    char res[len], temp;
    register _Bool t = 0;

    strcpy(res, str);

    do
    {
        t = 0;
        for(i = 0; i < len-1; i++)
        {
            if(res[i] > res[i+1])
            {
                t = 1;
                temp = res[i];
                res[i] = res[i+1];
                res[i+1] = temp;
            }
        }
    } while(t);

    strcpy(cpy, res);
}

void reverse(const char* str, char* cpy)
{
    int len = strlen(str);
    register int i;
    char res[len];

    for(i = 0; i < len; i++)
        res[i] = str[len-i-1];

    strcpy(cpy, res);
}

int DigitsNumber(register int num)
{
    register int res;

    for(res = 1; num > 9; res++)
        num /= 10;

    return res;
}
