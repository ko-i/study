// 2020-12-21 created by Akson
// Code16.1 shuffle.c 用随机数洗牌

// 使用随机数在牌桌上洗牌。第2个参数指定牌的数字。当这个函数第1次调用时，调用srand函数初始化随机数发生器。

#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

void shuffle(int* deck, int ncards)
{
	static int first_time = TRUE;

	// 如果尚未进行初始化，用当天的当前时间作为随机数发生器
	if(first_time)
	{
		first_time = FALSE;
		srand((unsigned int)time(NULL));
	}

	// 通过交换随机对的牌进行洗牌
	for(int i = n_cards - 1; i > 0; i--)
	{
		int where = rand() % i;

		int temp = deck[where];
		deck[where] = deck[i];
		deck[i] = temp;
	}
}