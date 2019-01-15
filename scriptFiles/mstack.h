// mstack written by Marek K.

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

#ifndef MSTACK_H
#define MSTACK_H

#ifndef MSTACK_BR
    #ifdef __bool_true_false_are_defined
        #define MSTACK_BR bool
    #elif __STDC_VERSION__ >= 199901L
        #define MSTACK_BR _Bool
    #else
        #define MSTACK_BR int
    #endif // __bool_true_false_are_defined
#endif // MSTACK_BR
// MSTACK BR = MSTACK BOOL RETURN

#ifndef MSTACK_TYPE
    #define MSTACK_TYPE long
#endif // MSTACK_TYPE

#ifndef NULL
    #define NULL ((void *) 0)
#endif // NULL

typedef struct {
    MSTACK_TYPE * ptr;
    unsigned long siz;
    MSTACK_BR v;
} mstack;

MSTACK_BR mstack_init(mstack * msk);
MSTACK_BR mstack_push(mstack * msk, MSTACK_TYPE x);
MSTACK_BR mstack_pop(mstack * msk, MSTACK_TYPE * x);
MSTACK_BR mstack_top(mstack * msk, MSTACK_TYPE * x);
MSTACK_BR mstack_close(mstack * msk);

#endif // MSTACK_H
