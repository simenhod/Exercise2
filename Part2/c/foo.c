#include <pthread.h>
#include <stdio.h>

int i = 0;
pthread_mutex_t increment_decrement_mutex;



void* incrementingThreadFunction()
{
    for(int j = 0; j < 1000000; j++)
    {
        pthread_mutex_lock(&increment_decrement_mutex);
	    i++;
        pthread_mutex_unlock(&increment_decrement_mutex);
    }
    return NULL;
}

void* decrementingThreadFunction()
{
    for (int j = 0; j < 1000000; j++)
    {
        pthread_mutex_lock(&increment_decrement_mutex);
	    i--;
        pthread_mutex_unlock(&increment_decrement_mutex);
    }
    return NULL;
}


int main()
{
    pthread_t incrementingThread, decrementingThread;
    pthread_mutex_init(&increment_decrement_mutex, NULL);
    
    pthread_create(&incrementingThread, NULL, incrementingThreadFunction, NULL);
    pthread_create(&decrementingThread, NULL, decrementingThreadFunction, NULL);
    
    pthread_join(incrementingThread, NULL);
    pthread_join(decrementingThread, NULL);
    
    printf("The magic number is: %d\n", i);
    return 0;
}
