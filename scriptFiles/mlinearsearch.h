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

#ifndef MLINEARSEARCH_H
#define MLINEARDEARCH_H

#define MLSEARCH(arr, elem, type, func) (type *) mlinearsearch((void *) arr, sizeof(arr)/sizeof(*arr), sizeof(*arr), (void *) &elem, func)


void * mlinearsearch   (register void *, const unsigned long, const unsigned, const void const *, int (*)(const void const *, const void const *));

int    mintfound       (const void * const a, const void * const b);  // int
int    muintfound      (const void * const a, const void * const b);  // unsigned int
int    mshrtfound      (const void * const a, const void * const b);  // short
int    mushrtfound     (const void * const a, const void * const b);  // unsigned short
int    mlongfound      (const void * const a, const void * const b);  // long
int    mulongfound     (const void * const a, const void * const b);  // unsigned long
int    mcharfound      (const void * const a, const void * const b);  // char
int    mucharfound     (const void * const a, const void * const b);  // unsigned char

#endif  // LINEARSEARCH_H
