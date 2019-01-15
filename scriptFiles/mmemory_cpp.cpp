// mmemory.h and mmemory.c written by Marek K.

#include "mmemory_cpp.hpp"
#ifdef __cplusplus
    #include <cstdlib>
    #include <cstddef>
#else
    #include <stdlib.h>
    #include <stddef.h>
#endif

/*
    stdlib.h(cstdlib): malloc, realloc, free
    stddef.h(cstddef): size_t
*/

#ifdef NCHECK
    #error The Macro NCHECK is defined
#else
    #define NCHECK(var) if(var == NULL) return 0;
#endif

MMEMORY_BR memnew(void ** ptr, MMEMORY_GET byte)
{
    void * ml = malloc((size_t) byte);
    NCHECK(ml)
    *ptr = ml;
    return 1;
}

MMEMORY_BR memdel(void ** ptr)
{
    NCHECK(*ptr)
    free(*ptr);
    *ptr = NULL;
    return 1;
}

MMEMORY_BR memedi(void ** ptr, MMEMORY_GET byte)
{
    NCHECK(*ptr)
    void * rl = realloc(*ptr, (size_t) byte);
    NCHECK(rl)
    if(*ptr != rl) free(*ptr);
    *ptr = rl;
    return 1;
}

#undef NCHECK
