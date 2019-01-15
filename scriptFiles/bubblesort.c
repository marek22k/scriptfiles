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

#include "bubblesort.h"

#define STRINGLENGTH(str, var) for(var = 0; str[var] != '\0'; var++);
#define STRINGCOPY(from, to, len) for(i = 0; i < len; i++) to[i] = from[i];

_Bool standardcomparison(char a, char b)
{
    return (a > b);
}

void bubblesort(const char* str, char* cpy, _Bool (*bigger) (char, char))
{
    int len;

    STRINGLENGTH(str, len)

    register int i;
    char res[len], temp;
    register _Bool t = 0;


    STRINGCOPY(str, res, len)

    do
    {
        t = 0;
        for(i = 0; i < len-1; i++)
        {
            if(bigger(res[i], res[i+1]))
            {
                t = 1;
                temp = res[i];
                res[i] = res[i+1];
                res[i+1] = temp;
            }
        }
    } while(t);

    STRINGLENGTH(res, len)
    STRINGCOPY(res, cpy, len)
}

#undef STRINGLENGTH
#undef STRINGCOPY
