// 2020-11-08 created by Akson

// 2020-11-07 created by Akson
// Code8.4 guess.c

#include <stdio.h>

int main(void)
{
	int guess = 50;
	int up = 100;
	int low = 1;
	char response;

	printf("Pick an integer from 1 to 100. I will try to guess it.\n");
	printf("Respond with a y if my guess is right and with an b(l) if it is more(less) than answer.\n");

	printf("Uh...is your number %d?\n", guess);

	while((response = getchar()) != 'y')
	{
		if(response == 'b')
		{
			up = guess;
			guess = (guess + low) / 2;
			printf("Well, then, is it %d?\n", guess);
		}
		else if(response == 'l')
		{
			low = guess;
			guess = (guess + up) / 2;
			printf("Well, then, is it %d?\n", guess);
		}
		else
		{
			printf("Sorry, I understand only y or n.\n");
		}

		while(getchar() != '\n')
		{
			continue;
		}
	}

	printf("I knew I could do it!\n");

	return 0;
}