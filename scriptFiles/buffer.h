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

#ifndef BUFFER_H
#define BUFFER_H

#define BUF(buf, type) (* ((type *) GetBuffer(&buf)))  // Quick access

#ifndef NULL
    #define NULL ((void *) 0)
    typedef unsigned size_t;
#endif  // NULL


typedef struct {
    void * ptr;  // Cursor
    void * begin;  // Begin of array
    void * end;  // End of array
    size_t size;  // Size of array
    size_t elem;  // Element size of array
} buffer;

int CreateBuffer(buffer * buf, size_t size, size_t elem);
void * GetBuffer(buffer * buf);
void * GetBufferByIndex(buffer * buf, size_t index);
int EditBuffer(buffer * buf, size_t size, size_t elem);
void DeleteBuffer(buffer * buf);
int NextBuffer(buffer * buf);
int LastBuffer(buffer * buf);
int GoNextBuffer(buffer * buf, size_t index);
int GoLastBuffer(buffer * buf, size_t index);

#endif  // BUFFER_H
