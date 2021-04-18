// 2020-11-12 created by Akson

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 256

int main(void)
{
	FILE * infp;
	FILE * outfp;
	FILE * outfp_hq;
	int ch;
	int rows = 0;
	int cols = 0;

	char str[SIZE];

	infp = fopen("img_src", "r");
	while(fgets(str, SIZE, infp) != NULL)
	{
		rows++;
		cols = (strlen(str) + 1) / 2;
	}
	printf("%d %d\n", rows, cols);

	rewind(infp);

	int img_mat_int[rows][cols];

	int i = 0;
	int j = 0;
	while((ch = getc(infp)) != EOF)
	{
		if(ch == ' '){
			continue;
		}
		else if(ch == '\n')
		{
			i++;
			j = 0;
			continue;
		}
		else
		{
			switch(ch)
			{
				case '0': img_mat_int[i][j] = 0; j++; break;
				case '1': img_mat_int[i][j] = 1; j++; break;
				case '2': img_mat_int[i][j] = 2; j++; break;
				case '3': img_mat_int[i][j] = 3; j++; break;
				case '4': img_mat_int[i][j] = 4; j++; break;
				case '5': img_mat_int[i][j] = 5; j++; break;
				case '6': img_mat_int[i][j] = 6; j++; break;
				case '7': img_mat_int[i][j] = 7; j++; break;
				case '8': img_mat_int[i][j] = 8; j++; break;
				case '9': img_mat_int[i][j] = 9; j++; break;
			}
		}
	}

	fclose(infp);

	outfp = fopen("img_copy", "w");

	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			switch(img_mat_int[i][j])
			{
				case 0: printf("%c", ' '); putc(' ', outfp);break;
				case 1: printf("%c", '.'); putc('.', outfp);break;
				case 2: printf("%c", '\''); putc('\'', outfp);break;
				case 3: printf("%c", ':'); putc(':', outfp);break;
				case 4: printf("%c", '~'); putc('~', outfp);break;
				case 5: printf("%c", '*'); putc('*', outfp);break;
				case 6: printf("%c", '='); putc('=', outfp);break;
				case 7: printf("%c", '&'); putc('&', outfp);break;
				case 8: printf("%c", '%'); putc('%', outfp);break;
				case 9: printf("%c", '#'); putc('#', outfp);break;
			}
		}
		printf("\n");
		putc('\n', outfp);

	}

	fclose(outfp);

	int img_mat_int_hq[rows][cols];

	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			img_mat_int_hq[i][j] = img_mat_int[i][j];
			if(i >= 1 && i <= rows - 2 && j >= 1 && j <= cols - 2)
			{
				int left = img_mat_int[i][j] - img_mat_int[i][j - 1];
				int right = img_mat_int[i][j] - img_mat_int[i][j + 1];
				int up = img_mat_int[i][j] - img_mat_int[i - 1][j];
				int down = img_mat_int[i][j] - img_mat_int[i + 1][j];

				if(left > 1 || left < -1)
				{
					if(right > 1 || right < -1)
					{
						if(up > 1 || up < -1)
						{
							if(down > 1 || down < -1)
							{
								img_mat_int_hq[i][j] = img_mat_int[i][j] - (up + down + left + right) / 4;
							}
						}
					}
				}
			}
		}
	}

	outfp_hq = fopen("img_copy_hq", "w");

	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			switch(img_mat_int_hq[i][j])
			{
				case 0: printf("%c", ' '); putc(' ', outfp_hq);break;
				case 1: printf("%c", '.'); putc('.', outfp_hq);break;
				case 2: printf("%c", '\''); putc('\'', outfp_hq);break;
				case 3: printf("%c", ':'); putc(':', outfp_hq);break;
				case 4: printf("%c", '~'); putc('~', outfp_hq);break;
				case 5: printf("%c", '*'); putc('*', outfp_hq);break;
				case 6: printf("%c", '='); putc('=', outfp_hq);break;
				case 7: printf("%c", '&'); putc('&', outfp_hq);break;
				case 8: printf("%c", '%'); putc('%', outfp_hq);break;
				case 9: printf("%c", '#'); putc('#', outfp_hq);break;
			}
		}
		printf("\n");
		putc('\n', outfp_hq);

	}

	fclose(outfp_hq);

	return 0;
}