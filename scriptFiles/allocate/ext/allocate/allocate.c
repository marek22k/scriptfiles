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

#include <ruby.h>
#include <stdlib.h>
#include <stddef.h>

struct allocate_s
{
    size_t size;
    void * ptr;
};

static VALUE allocate_allocallocate(VALUE);  /* Allocates the object */
static void allocate_allocatefree(void *);  /* Releases the previously allocated memory of the object. */

static VALUE allocate_init(VALUE);  /* Initializes the object */
static VALUE allocate_free(VALUE);  /* Free memory */
static VALUE allocate_alloc(VALUE, VALUE);  /* Allocated memory */
static VALUE allocate_good(VALUE);  /* Check if the memory is ready */
static VALUE allocate_set(VALUE, VALUE, VALUE);  /* Sets a value */
static VALUE allocate_get(VALUE, VALUE);  /* Get a value */
static VALUE allocate_max(VALUE self);

void Init_allocate();

static void allocate_allocatefree(void * p)
{
    struct allocate_s * ptr = (struct allocate_s *) p;
    
    if(ptr->ptr != NULL)
        free(ptr->ptr);
}

static VALUE allocate_allocallocate(VALUE klass)
{
    VALUE obj;
    struct allocate_s * ptr;
    
    obj = Data_Make_Struct(klass, struct allocate_s, NULL, allocate_allocatefree, ptr);
    
    ptr->size = 0;
    ptr->ptr = NULL;
    
    return obj;
}

static VALUE allocate_init(VALUE self)
{
    //struct allocate_s * ptr;

    //Data_Get_Struct(self, struct allocate_s, ptr);

    return self;
}

static VALUE allocate_free(VALUE self)
{
    struct allocate_s * ptr;

    Data_Get_Struct(self, struct allocate_s, ptr);

    if (0 == ptr->size)
        return self;

    free(ptr->ptr);
    
    ptr->size = 0;
    ptr->ptr = NULL;

    return self;
}

static VALUE allocate_alloc(VALUE self, VALUE size)
{
    struct allocate_s * ptr;
    
    Data_Get_Struct(self, struct allocate_s, ptr);
    
    if(NUM2UINT(size) == 0)
        rb_raise(rb_eArgError, "At least 1 byte must be allocated.");
        
    ptr->size = NUM2SIZET(size);
    ptr->ptr = malloc(NUM2SIZET(size) * sizeof(unsigned char));
    
    if(ptr->ptr == NULL)
        rb_raise(rb_eArgError, "There was an error while allocating.");
    
    return self;
}

static VALUE allocate_good(VALUE self)
{
    struct allocate_s * ptr;
    
    Data_Get_Struct(self, struct allocate_s, ptr);
    
    return (ptr->size>0&&ptr->ptr!=NULL?Qtrue:Qfalse);
}

static VALUE allocate_set(VALUE self, VALUE index, VALUE size)
{
    struct allocate_s * ptr;
    
    Data_Get_Struct(self, struct allocate_s, ptr);
    
    if(ptr->size > 0 && ptr->ptr != NULL)
    {
        ((unsigned char *) ptr->ptr)[NUM2SIZET(index)] = (unsigned char) NUM2CHR(size);
    }
    else
    {
        rb_raise(rb_eArgError, "An area that has not been allocated can not contain a value.");
    }
    
    return self;
}

static VALUE allocate_get(VALUE self, VALUE index)
{
    struct allocate_s * ptr;
    
    Data_Get_Struct(self, struct allocate_s, ptr);
    
    if(ptr->size > 0 && ptr->ptr != NULL)
    {
        return UINT2NUM((unsigned int) ((unsigned char *) ptr->ptr)[NUM2SIZET(index)]);
    }
    else
    {
        rb_raise(rb_eArgError, "Can not read from an area that has not been allocated.");
    }
    
    return self;
}

static VALUE allocate_max(VALUE self)
{
    struct allocate_s * ptr;
    
    Data_Get_Struct(self, struct allocate_s, ptr);
    
    return UINT2NUM(ptr->size);
}

void Init_allocate()
{
    VALUE cAllocate;

    cAllocate = rb_const_get(rb_cObject, rb_intern("Allocate"));

    rb_define_alloc_func(cAllocate, allocate_allocallocate);
    rb_define_method(cAllocate, "initialize", allocate_init, 0);
    rb_define_method(cAllocate, "alloc", allocate_alloc, 1);
    rb_define_method(cAllocate, "good?", allocate_good, 0);
    rb_define_method(cAllocate, "set", allocate_set, 2);
    rb_define_method(cAllocate, "get", allocate_get, 1);
    rb_define_method(cAllocate, "max?", allocate_max, 0);
    rb_define_method(cAllocate, "free", allocate_free, 0);
}