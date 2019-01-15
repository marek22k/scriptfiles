#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

#define FILL(n, s) {size_t fill_i; for(fill_i = 0; fill_i < (n); fill_i++){ printf(s); } }

int main()
{
    
    size_t n = (size_t) - 1;
    size_t i;
    
    printf("Please enter the size of the Christmas tree: ");
    fflush(stdout);
    if( scanf("%u", &n) != 1 )
    {
        fprintf(stderr, "Invalid input!\n");
        abort();
    }
    
    printf("\nChristmas tree:\n\n");
    FILL(n + 1 , " ");
    printf("_\n");
    FILL(n, " ");
    printf("/ \\\n");
    for(i = 0; i < n; i++)
    {
        FILL(n - i - 1, " ");
        printf("/ ");
        FILL(i + 1, "* ");
        printf("\\");
        printf("\n");
    }
    
    return EXIT_SUCCESS;
}