// 2020-12-22 created by Akson
// pe16.5

#include <stdio.h>
#include <math.h>

double wind_chill(double temp, double velocity);

int main(int argc, char const *argv[])
{
	printf("Enter a temprature and a wind velocity.\n");

	double temp;
	double velocity;

	printf("Temp and velocity(q to quit): ");
	while(scanf("%lf %lf", &temp, &velocity) == 2)
	{
		while(getchar() != '\n');

		printf("The wind chill is: %.2lf\n", wind_chill(temp, velocity));

		printf("Next temp and velocity(q to quit): ");
	}

	printf("Bye!\n");

	return 0;
}

double wind_chill(double temp, double velocity)
{
	return (10.45 + 10 * sqrt(velocity) + (-1) * velocity) * (33 - temp) / (10.45 + 10 * sqrt(1.78816) + (-1) * 1.78816);
}