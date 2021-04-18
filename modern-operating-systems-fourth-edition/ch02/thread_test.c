// 2020-11-17 created by Akson
// pthread test

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_THREADS 10

void *print_hello_world(void *tid);

int main(int argc, char const *argv[])
{
	pthread_t threads[NUMBER_OF_THREADS];
	int status;

	for(int i = 0; i < NUMBER_OF_THREADS; i++)
	{
		printf("Main here. Creating thread %d\n", i);
		status = pthread_create(&threads[i], NULL, print_hello_world, &i);

		if(status != 0)
		{
			printf("Oops. pthread_created error code %d\n", status);
			exit(-1);
		}
	}

	exit(0);
}

void *print_hello_world(void *tid)
{
	printf("Hello world. Greetings from thread %d\n", *(int*)tid);

	pthread_exit(NULL);
}