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

// Compile command(example): gcc gmptest.c -IE:\gmp-6.1.2 E:\gmp-6.1.2\.libs\libgmp.a

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

void mmpz_fact(mpz_t, mpz_t);

int main()
{
    mpz_t r, a, b;

    char * str1 = (char *) malloc(1),
    * str2 = (char *) malloc(1);

    printf("Please enter two number( [NUM1] [NUM2] ): ");
    fflush(stdout);
    scanf("%s %s", str1, str2);

    mpz_init(r);
    mpz_init(a);
    mpz_init(b);

    mpz_set_str(a, str1, 10);
    mpz_set_str(b, str2, 10);


    mpz_add(r, a, b);
    printf("%s + %s = %s\n", str1, str2, mpz_get_str(NULL, 10, r));
    
    mpz_sub(r, a, b);
    printf("%s - %s = %s\n", str1, str2, mpz_get_str(NULL, 10, r));
    
    mpz_mul(r, a, b);
    printf("%s * %s = %s\n", str1, str2, mpz_get_str(NULL, 10, r));

    mmpz_fact(a, r);
    printf("%s! = %s\n", str1, mpz_get_str(NULL, 10, r));

    mpz_clear(r);
    mpz_clear(a);
    mpz_clear(b);
    
    return 0;
}

void mmpz_fact(mpz_t x, mpz_t r)
{
    mpz_t i;

    if(mpz_cmp_ui(x, 0) == 0)
        mpz_set_ui(r, 1);
    
    mpz_set_ui(r, 1);
    for(mpz_init_set_ui(i, 1); mpz_cmp(i, x) < 0; mpz_add_ui(i, i, 1))
        mpz_mul(r, r, i);
    
    mpz_clear(i);
}
