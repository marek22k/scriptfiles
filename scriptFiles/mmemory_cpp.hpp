// mmemory.hpp and mmemory.cpp written by Marek K.

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
