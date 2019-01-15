/*
    DynArr written by Marek K.

    Error handling:
        DynArr_init, DynArr_push, DynArr_del, DynArr_close, DynArr_at, DynArr_isopen, DynArr_pop, DynArr_edit, DynArr_insert: Returns 0 if an error occurred.

    New type: DynArr
    New functions: DynArr_init, DynArr_push, DynArr_del, DynArr_close, DynArr_at, DynArr_isopen, DynArr_pop, DynArr_edit, DynArr_insert

    DynArr_init(DynArr *da): Prepare a DynArr for your use.
    DynArr_push(DynArr *da, int element): Added an element at the end of DynArr.
    DynArr_del(DynArr *da, int index): Deletes an item.
    DynArr_close(DynArr *da): Closes a DynArr and releases the memory space of the DynArr.
    DynArr_at(DynArr *da, int index): Returns the value of an item.
    DynArr_isopen(DynArr *da): Returns 1 if the DynArr is closed, otherwise 0.
    DynArr_pop(DynArr * da): Deletes the last element
    DynArr_edit(DynArr * da, int index, int newval): Sets a new value for an element
    DynArr_insert(DynArr * da, int index, int element): Adds to element to DynArr

    New attribute: DynArr.size


    Exmple:
    #include "DynArr.h"
    // ...
    DynArr da;
    DynArr * ptr = &da;
    DynArr_init(&da);
    DynArr_push(ptr, 5);
    DynArr_push(&da, 7);
    DynArr_push(ptr, 9);
    DynArr_del(&da, 1);
    DynArr_pop(ptr);
    DynArr_edit(ptr, 0, 2);
    DynArr_insert(&da, 0, 3);
    DynArr_del(ptr, 0);
    printf("Index 0: %d; Size: %d\n", DynArr_at(ptr, 0), da.size);
    if(DynArr_isopen(ptr))
    {
        DynArr_close(&da);
    }

    Output: Index 0: 2; Size: 1
*/

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

#ifndef DYNARR_H
#define DYNARR_H

typedef struct
{
    int *arr;
    int size;
} DynArr;

int DynArr_init(DynArr * da);
int DynArr_push(DynArr * da, int element);
int DynArr_del(DynArr * da, int index);
int DynArr_at(DynArr * da, int index);
int DynArr_close(DynArr * da);
int DynArr_isopen(DynArr * da);
int DynArr_pop(DynArr * da);
int DynArr_edit(DynArr * da, int index, int newval);
int DynArr_insert(DynArr * da, int index, int element);

#endif  // DYNARR_H
