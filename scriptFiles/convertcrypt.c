// convertcrypt written by Marek K.

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

#include <stdio.h>  /* printf, scanf */
#include <string.h>  /* strcpy, strncpy */

typedef union {
    long val;
    char str[sizeof(long)];
} cc; // cc = convert crypt

long encrypt(char * str, char * key)
{
    cc ccrypt;
    cc ckey;
    strncpy(ckey.str, key, sizeof(long));
    strncpy(ccrypt.str, str, sizeof(long));
    return ccrypt.val - ckey.val;
}

void decrypt(long cstr, char * str, char * key)
{
    cc ccrypt;
    cc ckey;
    ccrypt.val = cstr;
    strncpy(ckey.str, key, sizeof(long));
    ccrypt.val += ckey.val;
    strcpy(str, ccrypt.str);
}

int main()
{
    char key[8];
    char str[8];
    short unsigned x;
    
    printf("convertcrypt\n"
           "============\n"
           "\n"
           "1 - Encrypt\n"
           "2 - Decrypt\n"
           "3 - Exit\n"
           "\n"
           "Input: ");
    scanf("%hu", &x);
    
    switch(x)
    {
        case 1:
        {
            printf("String (maximum 7 character): ");
            scanf("%s", str);
            printf("Key (maximum 7 character): ");
            scanf("%s", key);
            printf("Number: %ld", encrypt(str, key));
            break;
        }
        
        case 2:
        {
            long num;
			
            printf("Number: ");
            scanf("%ld", &num);
            printf("Key (maximum 7 character): ");
            scanf("%s", key);
            decrypt(num, str, key);
            printf("Result: %s", str);
            break;
        }
    }
    return 0;
}
