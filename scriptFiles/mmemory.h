// mmemory.h and mmemory.c written by Marek K.

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

#ifndef MMEMORY_H
#define MMEMORY_H

#define MMEMORY_ARR(num, type) (num * sizeof(type))

#ifdef NULL
    #define MMEMORY_GET size_t
#else
    #define MMEMORY_GET unsigned int
#endif

#if defined(__bool_true_false_are_defined) || defined(__cplusplus)
    #define MMEMORY_BR bool
    // MEMORY_BR = MEMORY BOOL RETURN
#elif __STDC_VERSION__ >= 199901L
    #define MMEMORY_BR _Bool
#else
    #define MMEMORY_BR int
#endif

MMEMORY_BR memnew(void **, MMEMORY_GET);
MMEMORY_BR memdel(void **);
MMEMORY_BR memedi(void **, MMEMORY_GET);

#endif