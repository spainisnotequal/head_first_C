/*
 * Program to see how to pass a variable of type "long" to thread functions
 */

#include <stdio.h>
#include <pthread.h>


void * do_stuff (void *param) // a thread function only can accept a single
                              // void pointer parameter
{
        long thread_no = (long) param; // convert the parameter to type "long"
        printf("Thread number %ld\n", thread_no);
        return (void*) (thread_no + 1); // cast it back to a void pointer
                                        // before returning it
}

int main (void)
{
	pthread_t threads[20];
	long t;
	for (t = 0; t < 3; t++) {
		pthread_create(&threads[t],
                               NULL,
                               do_stuff,
                               (void *) t); // convert the "long" t value to
                                            // a void pointer
	}

	void *result;
	for (t = 0; t < 3; t++) {
		pthread_join(threads[t], &result);
                printf("Thread %ld returned %ld\n", t
                       , (long) result); // convert the return value to a "long"
                                         // before using it
	}
			
        return 0;
}
