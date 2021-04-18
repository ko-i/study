// 2020-11-04 created by Akson
// Code2.4

// 修改前
// #include <stdio.h>
// int main(void)
// (
//     int n, int n2, int n3;

//	   /* 该程序有多处错误
//	   n = 5;
//	   n2 = n * n;
//	   n3 = n2 * n2;
//	   printf("n = %d, n squared = %d, n cubed = %d\n", n, n2, n3)

//	   return 0;
// )


// 修改后
#include <stdio.h>
int main(void)
{
    int n, n2, n3;

	/* 该程序没有语法错误 */
	n = 5;
	n2 = n * n;
	n3 = n2 * n2;
	printf("n = %d, n squared = %d, n cubed = %d\n", n, n2, n3);

	return 0;
}