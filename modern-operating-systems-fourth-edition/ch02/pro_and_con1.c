// 2020-11-18 created by Akson
// Code2.2 Producer and Consumer

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


#define N 100
#define EPOCH 10000

static int count = 0;

void * producer(void * arg);
void * consumer(void * arg);

int produce_item(int item);
void insert_item(int item);
int remove_item(int item);

int main(int argc, char const *argv[])
{
	pthread_t my_producer;
	pthread_t my_consumer;

	int pro_status, con_status;
	pro_status = pthread_create(&my_producer, NULL, producer, NULL);
	con_status = pthread_create(&my_consumer, NULL, consumer, NULL);

	return 0;
}

void * producer(void * arg)
{
	printf("Producer at you service.\n");
	int item;
	int epoch = 0;
	while(epoch < EPOCH)
	{
		epoch++;
		item = produce_item(epoch);
		if(count == N)
		{
			// sleep();
			insert_item(item);
		}
		count++;
		if(count == 1)
		{
			printf("Wake up consumer.\n");
			// wakeup(consumer);
		}
	}

	printf("Producer Done!\n");
	pthread_exit(NULL);
}

void * consumer(void * arg)
{
	printf("Consumer at you service.\n");

	int item;
	int epoch = 0;
	while(epoch < EPOCH)
	{
		epoch++;
		if(count == 0)
		{
			// sleep();
		}
		item = remove_item(epoch);
		count--;
		if(count == N - 1)
		{
			printf("Wake up producer.\n");
			// wakeup(producer);
		}
	}

	printf("Consumer Done!\n");
	pthread_exit(NULL);
}

int produce_item(int item)
{
	printf("Produce item %d\n", item);
	return item;
}

void insert_item(int item)
{
	printf("Insert item %d\n", item);
}

int remove_item(int item)
{
	printf("Remove item %d\n", item);

	return item;
}
