// msysco(m system console) written by Marek K.

#include <stdio.h>  /* printf, scanf */
#include <stdlib.h>  /* malloc, system, EXIT_SUCCESS */
#include <string.h>  /* strcmp */

int main()
{
    char * x;
    x = (char *) malloc(0);

    do
    {
        printf(": ");
        scanf("%s", x);
        if(system(x)) printf("##error");
        printf("\n");
    } while(strcmp(x, "##exit") != 0);

    printf("##end");

    return EXIT_SUCCESS;
}
