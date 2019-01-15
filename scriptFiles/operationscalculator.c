// Operations Calculator written by Marek K.

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

#include <stdio.h>  /* printf, scanf, fflush, stdout, fprintf, stderr */
#include <stdlib.h>  /* EXIT_SUCCESS, abort */

void ErrorHandler(int err);

int main()
{
    int a = -1, b = -1, m = -1;
    char o = (char) -1;
    printf(
        "Operations Calculator\n"
        "\n"
        "[from] [to] [operator] [operand]\n"
        "Example: 10 20 & 3\n"
        "Input: "
    );
    scanf("%d %d %c %d", &a, &b, &o, &m);

    if(a == -1 || b == -1 || m == -1 || o == (char) -1)
    {
        ErrorHandler(0x0001);
    }

    register int i, sum = 0;
    for(i = a; i <= b; i++)
    {
        switch(o)
        {
            case '+':
                {
                    sum += i + m;
                    break;
                }
            case '-':
                {
                    sum += i - m;
                    break;
                }
            case '*':
                {
                    sum += i * m;
                    break;
                }
            case '/':
                {
                    sum += i / m;
                    break;
                }
            case '%':
                {
                    sum += i % m;
                    break;
                }
            case '|':
                {
                    sum += i | m;
                    break;
                }
            case '&':
                {
                    sum += i & m;
                    break;
                }
            case '^':
                {
                    sum += i ^ m;
                    break;
                }
        }
    }

    printf("\nsum: %d", sum);

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
                fprintf(stderr, "Invalid input!");
            }
    }
    abort();
}
