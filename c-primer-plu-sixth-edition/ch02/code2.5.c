// 2020-11-04 created by Akson
// Code2.5

// 修改前
// #include <stdio.h>
// int main(void)
// {
//     int n, n2, n3;
// 
// 	   /* 该程序有一个语义错误 */
// 	   n = 5;
// 	   n2 = n * n;
// 	   n3 = n2 * n2;
// 	   printf("n = %d, n squared = %d, n cubed = %d\n", n, n2, n3);
// 
// 	   return 0;
// }

// 修改后
#include <stdio.h>
int main(void)
{
    int n, n2, n3;

	/* 该程序没有语义错误 */
	n = 5;
	n2 = n * n;
	n3 = n2 * n;
	printf("n = %d, n squared = %d, n cubed = %d\n", n, n2, n3);

	return 0;
}