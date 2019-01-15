#include <stdio.h>  /* printf */
#include <stdlib.h>  /* NULL, sleep */
#include <pthread.h>  /* pthread_t, pthread_create, pthread_join, pthread_exit */
 
void * MyFirstThread(void * tid);
void * MySecondThread(void * tid);
void CallThreads();

static pthread_t fth, sth;

int main()
{
    pthread_create(&fth, NULL, &MyFirstThread, NULL);  // Create first thread
    pthread_create(&sth, NULL, &MySecondThread, NULL);  // Create second thread
    
    CallThreads();
    return 0;
}

void * MyFirstThread(void * tid)
{
    sleep(1);
    printf("My First Thread\n");
    return NULL;  // Exit thread
}

void * MySecondThread(void * tid)
{
    printf("My Second Thread\n");
    pthread_exit(NULL);  // Exit thread
}

void CallThreads()
{
    pthread_join(fth, NULL);  // Call the first thread
    pthread_join(sth, NULL);  // Call the second thread
}