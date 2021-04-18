// 2020-12-13 created by Akson
// pe8.1

#include <stdio.h>

int main(int argc, char const *argv[])
{
	// 四维的大括号初始化方法太反人类，我就不实现那个了。
	char char_value[3][6][4][5] = {{{{0}}}};
	char_value[1][2][2][3] = 'A';
	char_value[1][1][1][1] = ' ';
	char_value[1][3][2][2] = 0xf3;
	char_value[2][4][3][2] = '3';
	char_value[1][4][2][3] = '\n';
	char_value[2][2][3][1] = '\121';
	char_value[2][4][3][3] = 3;
	char_value[2][5][3][4] = 125;
	char_value[1][2][3][4] = 'x';
	char_value[2][1][1][2] = 0320;
	char_value[2][2][2][2] = '\'';
	char_value[2][2][1][1] = '0';

	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 6; j++)
		{
			for(int k = 0; k < 4; k++)
			{
				for(int l = 0; l < 5; l++)
				{
					printf("%d ", char_value[i][j][k][l]);
				}
				printf("\n");
			}
			printf("\n");
		}
		printf("\n");
	}

	printf("Bye!\n");

	return 0;
}