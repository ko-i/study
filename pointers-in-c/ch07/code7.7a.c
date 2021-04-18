// 2020-12-08 created by Akson
// Code7.7a fact_rec.c 递归计算阶乘

// 用递归方法计算n的阶乘

long factorial(int n)
{
	if(n <= 0)
	{
		return 1;
	}

	return n * factorial(n - 1);
}