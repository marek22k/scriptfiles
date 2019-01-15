// mptrdef.h written by Marek K.

#ifndef MPTRDEF_H
#define MPTRDEF_H

#define MPTRDEF_CONVERT(type) (type *) 

typedef char * cptr;
typedef int * iptr;
typedef long * lptr;
typedef short * sptr;

typedef unsigned char * ucptr;
typedef unsigned int * uiptr;
typedef unsigned long * ulptr;
typedef unsigned short * usptr;

typedef double * dptr;
typedef float * fptr;
typedef void * vptr;

#if defined(__bool_true_false_are_defined) || defined(__cplusplus)
    #define MPTRDEF_BOOL 1
    typedef bool * bptr;
#endif

#if __STDC_VERSION__ >= 199901L
    #define MPTRDEF__BOOL 1
    typedef _Bool * _bptr;
#endif

#endif