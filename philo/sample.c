#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t mutex;

void *thread_function(void *arg)
{
	//locking resource
    pthread_mutex_lock(&mutex);
	// do whatever u want here to the resource
    // printf("Thread %ld is running\n", pthread_self());
	// unlock resource
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

	// init the mutex
    pthread_mutex_init(&mutex, NULL);

	// create thread
    pthread_create(&thread1, NULL, thread_function, NULL);
	// create thread
    pthread_create(&thread2, NULL, thread_function, NULL);

    // join back to main program
	pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

	// destroy mutex after not using
    pthread_mutex_destroy(&mutex);
    return 0;
}
