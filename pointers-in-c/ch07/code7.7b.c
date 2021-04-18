// 2020-12-08 created by Akson
// Code7.7b fact_itr.c 迭代计算阶乘

// 用迭代方法计算n的阶乘

long factorial(int n)
{
	int result = 1;
	while(n > 1)
	{
		result *= n;
		n--;
	}

	return result;
}