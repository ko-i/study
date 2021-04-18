// 2020-12-09 created by Akson
// Code7.9a average1.c  计算标量参数的平均值：差的版本

// 计算指定数目的值的平均值（差的方案）

float average(int n_values, int v1, int v2, int v3, int v4, int v5)
{
	float sum = v1;

	if(n_values >= 2)
	{
		sum += v2;
	}

	if(n_values >= 3)
	{
		sum += v3;
	}

	if(n_values >= 4)
	{
		sum += v4;
	}

	if(n_values >= 5)
	{
		sum += v5;
	}

	return sum / n_values;
}