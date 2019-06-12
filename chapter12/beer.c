/*
 * Program to see how multiple threads work at the same time
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h> // POSIX thread library


int BEERS = 2000000;

void error (const char *msg)
{
        fprintf(stderr, "%s: %s\n", msg, strerror(errno));
        exit(1);
}

void * drinks_lots (void *a)
{
	for (int i = 0; i < 100000; i++) {
		BEERS -= 1;
	}
	return NULL;
}


int main (void)
{
	pthread_t threads[20]; // create 20 pthread_t data structures
	int t;
	printf("%i bottles of beer on the wall\n%i bottles of beer\n",
	       BEERS, BEERS);
	
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
	printf("The are now %i bottles of beer on the wall\n", BEERS);
		
        return 0;
}
