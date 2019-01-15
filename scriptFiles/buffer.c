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

#include "buffer.h"
#include <stdlib.h>  /* malloc, realloc, free */ /* dynamic memory */
#include <stddef.h>  /* NULL, size_t */

/** \brief Create a Buffer
 *
 * \param buf buffer*
 * \param size size_t The size of the buffer(in byte)
 * \param elem size_t The size of a Element(in byte)
 * \return int
 *
 */
int CreateBuffer(buffer * buf, size_t size, size_t elem)
{
    buf->ptr = malloc(size);
    if(buf->ptr == NULL) return 0;
    buf->begin = buf->ptr;
    buf->end = (void *) ((size_t) buf->ptr + size);
    buf->size = size;
    buf->elem = elem;
    return 1;
}

/** \brief Return a pointer to current buffer value
 *
 * \param buf buffer*
 * \return void*
 *
 */
void * GetBuffer(buffer * buf)
{
    return buf->ptr;
}

/** \brief Return a pointer to a buffer value
 *
 * \param buf buffer*
 * \param index size_t
 * \return void*
 *
 */
void * GetBufferByIndex(buffer * buf, size_t index)
{
    return (void *) ((size_t) buf->begin + index * buf->elem);
}

/** \ Edit the size of a buffer
 *
 * \param buf buffer*
 * \param size size_t The size of the buffer(in byte)
 * \param elem size_t The size of a Element(in byte)
 * \return int
 *
 */
int EditBuffer(buffer * buf, size_t size, size_t elem)
{
    buf->ptr = realloc(buf->ptr, size);
    if(buf->ptr == NULL) return 0;
    buf->begin = buf->ptr;
    buf->end = (void *) ((size_t) buf->ptr + size);
    buf->size = size;
    buf->elem = elem;
    return 1;
}

/** \brief Delete a buffer
 *
 * \param buf buffer*
 * \return void
 *
 */
void DeleteBuffer(buffer * buf)
{
    free(buf->ptr);
    buf->ptr = NULL;
}

/** \brief  Set the cursor(buffer.ptr) up
 *
 * \param buf buffer*
 * \return int
 *
 */
int NextBuffer(buffer * buf)
{
    if((void *) ((size_t)buf->ptr + buf->size) > buf->end) return 0;
    buf->ptr = (void *) ((size_t)buf->ptr + buf->elem);
    return 1;
}

/** \brief Set the cursor(buffer.ptr) down
 *
 * \param buf buffer*
 * \return int
 *
 */
int LastBuffer(buffer * buf)
{
    if(buf->ptr < buf->begin) return 0;
    buf->ptr = (void *) ((size_t)buf->ptr - buf->elem);
    return 1;
}

/** \brief Set the cursor(buffer.ptr) quick up
 *
 * \param buf buffer*
 * \param index size_t
 * \return int
 *
 */
int GoNextBuffer(buffer * buf, size_t index)
{
    size_t i;
    for(i = 0; i < index; i++) if(!NextBuffer(buf)) return 0;
    return 1;
}

/** \brief Set the cursor(buffer.ptr) quick down
 *
 * \param buf buffer*
 * \param index size_t
 * \return int
 *
 */
int GoLastBuffer(buffer * buf, size_t index)
{
    size_t i;
    for(i = 0; i < index; i++) if(!LastBuffer(buf)) return 0;
    return 1;
}
