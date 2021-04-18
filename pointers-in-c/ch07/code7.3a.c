// 2020-12-08 created by Akson
// Code7.3a swap1.c 整数交换：无效的版本

// 交换调用程序中的两个整数

void swap(int x, int y)
{
	int temp;

	temp = x;
	x = y;
	y = temp;
}