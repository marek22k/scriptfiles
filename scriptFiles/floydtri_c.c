#include <stdio.h>  /* printf, scanf */

int main()
{
    int n;

    printf("Please enter a number: ");
    scanf("%d", &n);
    printf("\nFloyd's triangle:\n");

    register int i, j, num;

    for(i = 1, num = 1; i <= n; i++)
    {
        for(j = 0; j < i; j++, num++)
            printf("%d ", num);

        printf("\n");
    }

    return 0;
}
