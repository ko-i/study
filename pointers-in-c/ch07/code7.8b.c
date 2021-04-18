// 2020-12-09 created by Akson
// Code7.8b fib_iter.c   用迭代计算斐波那契数

// 用迭代方法计算第n个斐波那契数的值

long fibonacci(int n)
{
	long result;
	long previous_result;
	long next_older_result;

	result = previous_result = 1;

	while(n > 2)
	{
		n--;

		next_older_result = previous_result;
		previous_result = result;
		result = previous_result + next_older_result;
	}

	return result;
}