// 2020-12-14 created by Akson
// pe7.5

#include <stdio.h>

#define M_ROW 10
#define M_COL 10
#define N_ROW 10
#define N_COL 10

void matrix_multiply(int* m1, int* m2, int* r, int x, int y, int z);

int main(int argc, char const *argv[])
{
	int m1[M_ROW][M_COL];
	int m2[N_ROW][N_COL];
	int r[M_ROW][N_COL];

	for(int i = 0; i < M_ROW; i++)
	{
		for(int j = 0; j < M_COL; j++)
		{
			m1[i][j] = i * j;
		}
	}

	for(int i = 0; i < N_ROW; i++)
	{
		for(int j = 0; j < N_COL; j++)
		{
			m2[i][j] = i * j;
		}
	}

	matrix_multiply(&m1[0][0], &m2[0][0], &r[0][0], M_ROW, M_COL, N_COL);

	printf("The result:\n");
	for(int i = 0; i < M_ROW; i++)
	{
		for(int j = 0; j < N_COL; j++)
		{
			printf("%5d ", r[i][j]);
		}
		printf("\n");
	}

	printf("\nBye!\n");

	return 0;
}

void matrix_multiply(int* m1, int* m2, int* r, int x, int y, int z)
{
	for(int m1_row = 0; m1_row < x; m1_row++)
	{
		for(int m2_col = 0; m2_col < z; m2_col++)
		{
			int temp = 0;
			for(int i = 0; i < y; i++)
			{
				temp += *(m1 + m1_row * y + i) * *(m2 + i * y + m2_col);
			}
			*(r + m1_row * x + m2_col) = temp;
		}
	}
}