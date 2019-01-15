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

/*
 Example:
    size_t i;
    int * arr = toIntArray(4, 1, 2, 5, 120);
    for(i = 0; i < 4; i++)
    {
        printf("%d\n", arr[i]);
    }
    free(arr);

*/

#ifndef TOARRAYFUNCTION_H
#define TOARRAYFUNCTION_H

#ifdef __cplusplus
extern "C" {
#endif
    
#include <stddef.h>

#define writeToArrayFunctionDec(type, name) type * name(size_t, ...);
#define writeToArrayFunctionDef(type, name) type * name(size_t siz, ...)\
{\
    va_list vl;\
    type * arr = (type *) malloc(siz * sizeof(type));\
    size_t i;\
    \
    if(arr == NULL || errno == ENOMEM)\
        return NULL;\
    \
    va_start(vl, siz);\
    \
    if(siz == 0)\
    {\
        errno = EINVAL;\
        return NULL;\
    }\
    \
    for(i = 0; i < siz; i++)\
    {\
        arr[i] = va_arg(vl, type);\
    }\
    \
    va_end(vl);\
    return arr;\
}\

#define writeToArrayFunction(type, name) writeToArrayFunctionDec(type, name) writeToArrayFunctionDef(type, name)

writeToArrayFunctionDec(int, toIntArray)
writeToArrayFunctionDec(long, toLongArray)
writeToArrayFunctionDec(unsigned, toUnsignedIntArray)
writeToArrayFunctionDec(unsigned long, toUnsignedLongArray)
writeToArrayFunctionDec(int *, toIntPtrArray)
writeToArrayFunctionDec(short *, toShortPtrArray)
writeToArrayFunctionDec(long *, toLongPtrArray)
writeToArrayFunctionDec(char *, toCharPtrArray)
writeToArrayFunctionDec(unsigned int *, toUnsignedIntPtrArray)
writeToArrayFunctionDec(unsigned short *, toUnsignedShortPtrArray)
writeToArrayFunctionDec(unsigned long *, toUnsignedLongPtrArray)
writeToArrayFunctionDec(unsigned char *, toUnsignedCharPtrArray)
        
#ifdef __cplusplus
}
#endif

#endif