// 2020-11-07 created by Akson

#include <stdio.h>

#define POUND1 5.0
#define POUND2 20.0
#define EXTRAFEE 0.5
#define TRANSFORMFEE1 6.5
#define TRANSFORMFEE2 14.0

#define DISCOUNTLIMIT 100.0
#define DISCOUNT 0.05

int main(void)
{
	const float PAY[3] = {2.05, 1.15, 1.09};
	float goods_weight[3] = {0.0, 0.0, 0.0};
	float all_weight = 0.0;
	float goods_fee = 0.0;
	float discount_fee = 0.0;
	float transform_fee = 0.0;
	float all_fee = 0.0;
	char goods[3][10] = {"Artichoke", "Beet", "Parrort"};

	printf("***************************************************\n");
	printf("*             Welcome to ABC grocer!              *\n");
	printf("***************************************************\n");
	printf("*     This the goods and it value today           *\n");
	printf("*     1) Artichoke $2.05     2) Beet $1.15        *\n");
	printf("*     3) Parrort   $1.09     4) QUIT              *\n");
	printf("***************************************************\n");
	printf("\n");
	printf("You can enter number to add it in your purches car!\n");

	int input_number = -1;
	float input_pounds = 0.0;
	while(scanf("%d", &input_number) && input_number <=3 && input_number >= 1)
	{
		printf("How many %s do you want to buy?\n", goods[input_number - 1]);
		scanf("%f", &input_pounds);
		goods_weight[input_number - 1] += input_pounds;
		printf("Now, you will buy %.2f pounds %s. ", goods_weight[input_number - 1], goods[input_number - 1]);

		printf("Anything else?\n");
	}

	printf("So, you want to buy:\n");
	for(int i = 0; i < 3; i++)
	{
		if(goods_weight[i] > 0.0)
		{
			printf("%.2f pounds %s: $%.2f.\n", goods_weight[i], goods[i], goods_weight[i] * PAY[i]);
			all_weight += goods_weight[i];
			goods_fee += goods_weight[i] * PAY[i];
		}
	}
	printf("All you buy: $%.2f\n", goods_fee);

	if(goods_fee > DISCOUNTLIMIT)
	{
		printf("If you buy more than $%.2f goods, you can have %.2f discount!\n", DISCOUNTLIMIT, 1.0 - DISCOUNT);
		discount_fee = goods_fee * DISCOUNT;
		printf("So you can have %.2f for free!\n", discount_fee);
	}

	if(all_weight > POUND2)
	{
		transform_fee = TRANSFORMFEE2 + (all_weight - POUND2) * EXTRAFEE;
	}
	else if(all_weight > POUND1)
	{
		transform_fee = TRANSFORMFEE2;
	}
	else
	{
		transform_fee = TRANSFORMFEE1;
	}

	printf("Transform fee: $%.2f.\n", transform_fee);
	all_fee = goods_fee - discount_fee + transform_fee;

	printf("All: $%.2f\n", all_fee);
	printf("Thanks for buy! Bye!\n");

	return 0;
}