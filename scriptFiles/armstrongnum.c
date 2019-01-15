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
#include <math.h>

int DigitsNumber(int num);
_Bool isArmstrong(int num);

int main()
{
    int x;

    printf("Please enter a number: ");
    scanf("%d", &x);

    if(isArmstrong(x))
        printf("%d is a armstrong Number.", x);
    else
        printf("%d is not a armstrong Number.", x);

    return 0;
}

int DigitsNumber(int num)
{
    unsigned int res = 1;
    for(; num > 9; res++)
        num /= 10;

    return res;
}

_Bool isArmstrong(int num)
{
    int len = DigitsNumber(num), res = 0;
    char strn[len];

    sprintf(strn, "%d", num);

    for(int i = 0; i < len; i++)
        res += pow((strn[i] - '0'), len);

    return (num==res);
}
