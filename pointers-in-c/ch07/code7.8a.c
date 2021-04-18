// 2020-12-09 created by Akson
// Code7.8a fib_rec.c 用递归计算斐波那契数

long fibonacci(int n)
{
	if(n <= 2)
	{
		return 1;
	}

	return fibonacci(n - 1) + fibonacci(n - 2);
}