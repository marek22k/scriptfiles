#ifndef MQUICKSORT_H
#define MQUICKSORT_H

#ifdef __cplusplus
    #include <cstddef>
extern "C"
#else
    #include <stddef.h>
#endif

void mquicksort(long * arr, size_t beg, size_t end);
#define MQSORT(arr) (mquicksort(arr, 0, sizeof(arr)/sizeof(*arr)-1))

#endif