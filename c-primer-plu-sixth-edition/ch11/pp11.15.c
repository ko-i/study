// 2020-11-10 created by Akson

#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int count = 0;
	char str[20];
	char * pstr;
	int sum = 0;

	printf("Please enter a string, I will try to change it in number.\n");
	printf("Enter the string: ");
	while(fgets(str, 20, stdin))
	{
		if(str[0] == '\n')
		{
			break;
		}
		sum = 0;
		char * pts = str;
		count = 0;
		int notanum = 0;
		while(*pts != '\n')
		{
			if(!isdigit(*pts))
			{
				notanum = 1;
				break;
			}
			count++;
			pts++;
		}

		if(notanum)
		{
			printf("Not a number, please enter the string only contians number.\n");
			printf("Enter the string: ");
			continue;
		}

		int multi = 1;
		for(int i = count - 1; i >= 0; i--)
		{
			sum += (str[i] - 48) * multi;
			multi *= 10;
		}

		printf("The number is %d.\n", sum);

		printf("Enter the string: ");
	}

	printf("Done!\n");

	return 0;

}