#include <stdio.h>  /* printf */

#include <sys/types.h>  /* pid_t */
#include <unistd.h>  /* getpid */

int main()
{
    pid_t /* aka int */ pid = getpid();
    
    printf("%d", pid);
    
    return 0;
}