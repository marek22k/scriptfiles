#include <stdio.h>
#include <stdbool.h>
#include "mptrdef.h"
#include "mmemory.h"

int main()
{
    register int i;
    vptr x;
    bptr p;
    memnew(&x, MMEMORY_ARR(2, bool));
    memedi(&x, MMEMORY_ARR(4, bool));
    p = MPTRDEF_CONVERT(bool) x;
    p[0] = 1;
    p[1] = 0;
    p[2] = 0;
    p[3] = 1;
    
    for(i = 0; i < 4; i++)
        printf("%d", p[i]);
    
    memdel(&x);
    return 0;
}
