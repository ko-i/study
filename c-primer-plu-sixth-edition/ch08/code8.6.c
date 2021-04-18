// 2020-11-07 created by Akson
// Code8.6 showchar2.c

#include <stdio.h>

void display(char ch, int lines, int width);

int main(void)
{
	int ch;
	int rows, cols;

	printf("Enter a character and two integers:\n");
	while((ch = getchar()) != '\n')
	{
		if(scanf("%d %d", &rows, &cols) != 2)
		{
			break;
		}
		display(ch, rows, cols);
		while(getchar() != '\n');
		
		printf("Enter another character and two integers;\n");
		printf("Enter a newline to quit.\n");
	}

	printf("Bye.\n");

	return 0;
}

void display(char ch, int lines, int width)
{
	int row, col;

	for(row = 0; row < lines; row++)
	{
		for(col = 0; col < width; col++)
		{
			putchar(ch);
		}
		printf("\n");
	}
}