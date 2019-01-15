// MIOXO written by Marek K.

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

#ifndef MIOXO_H
#define MIOXO_H

// M INPUT OUTPUT EXTENSION
// _ _     _       _     _

#define CPTRtoCHARPTR(ptr) ((char *) ptr)
#define CHARPTRtoCPTR(ptr) ((cptr) ptr)

#ifndef MMEMORY_H  // memnew, memedi, memdel
#error The file mmemory.h is not included.
#endif

#ifndef MPTRDEF_H
#define MIOXO_MPTRDEF_NO_IMPORT 1
typedef char * cptr;
#define MPTRDEF_CONVERT(type) (type *)
#endif

const int
NO_LIMIT,
LIMIT_1,
LIMIT_3,
LIMIT_7,
LIMIT_15,

LIMIT_31,
LIMIT_63,
LIMIT_127,
LIMIT_255,

LIMIT_511,
LIMIT_1023,
LIMIT_2047,
LIMIT_4095,

LIMIT_8191,
LIMIT_16383,
LIMIT_32767,
LIMIT_65535;

cptr GetInput(void (*) (), char, int);
void mixo_close(void (*) (), cptr);
void moxo(cptr, int, char);
void moxo_limit(cptr, int);
void moxo_end(cptr, char);

#endif
