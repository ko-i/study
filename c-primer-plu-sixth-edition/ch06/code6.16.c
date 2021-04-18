// 2020-11-06 created by Akson
// Code6.16 entry.c

#include <stdio.h>

int main(void)
{
	const int secret_code = 13;
	int code_entered;

	printf("To enter the triskaidekaphobbia therapy club,\n");
	printf("please enter th secret code number: ");
	scanf("%d", &code_entered);

	while(code_entered != secret_code)
	{
		printf("To enter the triskaidekaphobbia therapy club,\n");
		printf("please enter th secret code number: ");
		scanf("%d", &code_entered);
	} 

	printf("Congratulations! You are cured!\n");

	return 0;
}