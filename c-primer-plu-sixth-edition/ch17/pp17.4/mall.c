// 2020-11-15 created by Akson
// Code17.9 mall.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"

#define MIN_PER_HR 60.0

bool newcustomer(double x);
Item customertime(long when);

int main(void)
{
	Queue line1;
	Queue line2;
	Item temp;
	int hours;
	int perhour;
	long cycle, cyclelimit;
	long turnaways = 0;
	long customers = 0;
	long served = 0;
	long sum_line1 = 0;
	long sum_line2 = 0;
	int wait_time1 = 0;
	int wait_time2 = 0;
	double min_per_cust;
	long line_wait1 = 0;
	long line_wait2 = 0;

	InitializeQueue(&line1);
	InitializeQueue(&line2);
	srand((unsigned int)time(0));
	printf("Case Study: Sigmund Lander's Advice Booth\n");
	printf("Enter the number of customers per hours: ");
	scanf("%d", &hours);
	cyclelimit = MIN_PER_HR * hours;
	printf("Enter the average number of customers per hour: ");
	scanf("%d", &perhour);
	min_per_cust = MIN_PER_HR / perhour;

	for(cycle = 0; cycle < cyclelimit; cycle++)
	{
		if(newcustomer(min_per_cust))
		{
			if(QueueIsFull(&line1))
			{
				if(QueueIsFull(&line2))
				{
					turnaways++;
				}
				else
				{
					customers++;
					temp = customertime(cycle);
					EnQueue(temp, &line2);
				}
				
			}
			else
			{
				customers++;
				temp = customertime(cycle);
				EnQueue(temp, &line1);
			}
		}

		if(wait_time1 <= 0 && !QueueIsEmpty(&line1))
		{
			DeQueue(&temp, &line1);
			wait_time1 = temp.processtime;
			line_wait1 += cycle - temp.arrive;
			served++;
		}

		if(wait_time1 > 0)
		{
			wait_time1--;
		}

		sum_line1 += QueueItemCount(&line1);

		if(wait_time2 <= 0 && !QueueIsEmpty(&line2))
		{
			DeQueue(&temp, &line2);
			wait_time2 = temp.processtime;
			line_wait2 += cycle - temp.arrive;
			served++;
		}

		if(wait_time2 > 0)
		{
			wait_time2--;
		}

		sum_line2 += QueueItemCount(&line2);
	}

	if(customers > 0)
	{
		printf("customers accepted: %ld\n", customers);
		printf("customers served  : %ld\n", served);
		printf("turnaways         : %ld\n", turnaways);
		printf("Average queue size: %.2lf\n", (double)(sum_line1 + sum_line2) / cyclelimit);
		printf("Average wait time : %.2lf\n", (double)(line_wait1 + line_wait2) / served);
	}
	else
	{
		printf("No customers!\n");
	}

	EmptyTheQueue(&line1);
	EmptyTheQueue(&line2);
	printf("Bye!\n");

	return 0;
}

bool newcustomer(double x)
{
	if(rand() * x / RAND_MAX < 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Item customertime(long when)
{
	Item cust;
	cust.processtime = rand() % 3 + 1;
	cust.arrive = when;

	return cust;
}