/*
 * Program to see how multiple threads work at the same time
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h> // POSIX thread library


int beers = 2000000;
pthread_mutex_t beers_lock = PTHREAD_MUTEX_INITIALIZER;

void error (const char *msg)
{
        fprintf(stderr, "%s: %s\n", msg, strerror(errno));
        exit(1);
}

void * drinks_lots (void *a)
{
	pthread_mutex_lock(&beers_lock);
	for (int i = 0; i < 100000; i++) {
		beers -= 1;
	}
	pthread_mutex_unlock(&beers_lock);
	printf("beers = %i\n", beers);
	return NULL;
}


int main (void)
{
	pthread_t threads[20]; // create 20 pthread_t data structures
	int t;
	printf("%i bottles of beer on the wall\n%i bottles of beer\n",
	       beers, beers);
	
	// creates 20 threads:
	for (t = 0; t < 20; t++) {
		if (pthread_create(&threads[t], NULL, drinks_lots, NULL) == -1) {
			error("Can't create thread");
		}
	}

	// run the threads and wait until they finish:
	void *result;
	for (t = 0; t < 20; t++) {
		if (pthread_join(threads[t], &result) == -1) {
			error("Can't join thread t");
		}
	}
	printf("The are now %i bottles of beer on the wall\n", beers);
		
        return 0;
}
