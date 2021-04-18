// 2020-11-18 created by Akson
// Producer and Consumer with mutex and cond

#include <stdio.h>
#include <pthread.h>

#define MAX 100

pthread_mutex_t the_mutex;
pthread_cond_t condc, condp;

int buffer = 0;

void * producer(void * ptr);
void * consumer(void * ptr);

int main(int argc, char const *argv[])
{
	pthread_t pro;
	pthread_t con;

	pthread_mutex_init(&the_mutex, 0);
	pthread_cond_init(&condp, 0);
	pthread_cond_init(&condc, 0);

	pthread_create(&pro, 0, producer, 0);
	pthread_create(&con, 0, consumer, 0);

	pthread_join(pro, 0);
	pthread_join(con, 0);

	pthread_cond_destroy(&condp);
	pthread_cond_destroy(&condc);

	pthread_mutex_destroy(&the_mutex);

	return 0;
}

void * producer(void * ptr)
{
	for(int i = 1; i <= MAX; i++)
	{
		pthread_mutex_lock(&the_mutex);
		while(buffer != 0)
		{
			pthread_cond_wait(&condp, &the_mutex);
		}

		buffer = i;
		printf("Put %d in buffer.\n", i);

		pthread_cond_signal(&condc);
		pthread_mutex_unlock(&the_mutex);
	}

	pthread_exit(0);
}

void * consumer(void * ptr)
{
	for(int i = 1; i <= MAX; i++)
	{
		pthread_mutex_lock(&the_mutex);
		while(buffer == 0)
		{
			pthread_cond_wait(&condc, &the_mutex);
		}

		buffer = 0;
		printf("Put %d out buffer.\n", i);
		pthread_cond_signal(&condp);
		pthread_mutex_unlock(&the_mutex);
	}

	pthread_exit(0);
}