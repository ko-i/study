// 2020-12-08 created by Akson
// Code7.3b swap2.c 整数交换：有效版本

// 交换调用程序中的两个整数

void swap(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}