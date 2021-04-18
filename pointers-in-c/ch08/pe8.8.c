// 2020-12-14 created by Akson
// pe8.8

#include <stdio.h>

#define MAT_SIZE 8

void put_princess();
int can_put(int mat[][MAT_SIZE], int row, int col);
void print_chess_mat(int mat[][MAT_SIZE]);

int main(int argc, char const *argv[])
{
	put_princess();

	printf("Done!\n");

	return 0;
}

void put_princess()
{
	int chess_mat[MAT_SIZE][MAT_SIZE] = {{0}};

	// the 1 line
	for(int i = 0; i < MAT_SIZE; i++)
	{
		chess_mat[0][i] = 1;

		// the 2 line
		for(int j = 0; j < MAT_SIZE; j++)
		{
			//print_chess_mat(chess_mat);
			if(can_put(chess_mat, 1, j))
			{
				chess_mat[1][j] = 1;
				// the 3 line
				for(int k = 0; k < MAT_SIZE; k++)
				{

					if(can_put(chess_mat, 2, k))
					{
						chess_mat[2][k] = 1;

						// the 4 line
						for(int l = 0; l < MAT_SIZE; l++)
						{
							if(can_put(chess_mat, 3, l))
							{
								chess_mat[3][l] = 1;

								// the 5 line
								for(int m = 0; m < MAT_SIZE; m++)
								{
									if(can_put(chess_mat, 4, m))
									{
										chess_mat[4][m] = 1;

										// the 6 line
										for(int n = 0; n < MAT_SIZE; n++)
										{
											if(can_put(chess_mat, 5, n))
											{
												chess_mat[5][n] = 1;

												// the 7 line
												for(int o = 0; o < MAT_SIZE; o++)
												{
													if(can_put(chess_mat, 6, o))
													{
														chess_mat[6][o] = 1;

														// the 8 line
														for(int p = 0; p < MAT_SIZE; p++)
														{
															if(can_put(chess_mat, 7, p))
															{
																chess_mat[7][p] = 1;
																print_chess_mat(chess_mat);
																chess_mat[7][p] = 0;
															}
														}

														chess_mat[6][o] = 0;
				
													}
												}

												chess_mat[5][n] = 0;
											}
										}

										chess_mat[4][m] = 0;
				
									}
								}

								chess_mat[4][l] = 0;
				
							}
						}

						chess_mat[2][k] = 0;
					}
				}

				chess_mat[1][j] = 0;
			}
		}

		chess_mat[0][i] = 0;
	}
}

int can_put(int mat[][MAT_SIZE], int row, int col)
{
	int i, j;

	// check left
	i = row;
	j = col - 1;
	while(j >= 0)
	{
		if(mat[i][j] == 1)
		{
			return 0;
		}
		j--;
	}

	// check left_up
	i = row - 1;
	j = col - 1;
	while(j >= 0 && i >= 0)
	{
		if(mat[i][j] == 1)
		{
			return 0;
		}
		i--;
		j--;
	}

	// check up
	i = row - 1;
	j = col;
	while(i >= 0)
	{
		if(mat[i][j] == 1)
		{
			return 0;
		}
		i--;
	}

	// check up_right
	i = row - 1;
	j = col + 1;
	while(j < MAT_SIZE && i >= 0)
	{
		if(mat[i][j] == 1)
		{
			return 0;
		}
		i--;
		j++;
	}

	// check right
	i = row;
	j = col + 1;
	while(j < MAT_SIZE)
	{
		if(mat[i][j] == 1)
		{
			return 0;
		}
		j++;
	}

	// check right_down
	i = row + 1;
	j = col + 1;
	while(j < MAT_SIZE && i < MAT_SIZE)
	{
		if(mat[i][j] == 1)
		{
			return 0;
		}
		i++;
		j++;
	}

	// check down
	i = row + 1;
	j = col;
	while(i < MAT_SIZE)
	{
		if(mat[i][j] == 1)
		{
			return 0;
		}
		i++;
	}

	// check left_down
	i = row + 1;
	j = col - 1;
	while(j >= 0 && i < MAT_SIZE)
	{
		if(mat[i][j] == 1)
		{
			return 0;
		}
		i++;
		j--;
	}

	return 1;
}

void print_chess_mat(int mat[][MAT_SIZE])
{
	for(int i = 0; i < MAT_SIZE; i++)
	{
		for(int j = 0; j < MAT_SIZE; j++)
		{
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
