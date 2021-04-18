// 2020-11-16 created by Akson

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define NAMELEN 20
#define SEATNUM 12
#define FLIGHTNUM 4

struct seat
{
	int id;
	bool ordered;
	char fname[NAMELEN];
	char lname[NAMELEN];
};

struct flight
{
	int id;
	struct seat seats[SEATNUM];
	bool confirmed;
	
};

struct flight * choiceFlight(struct flight * my_flights, int flight_num);
char getChoice();

int numberOfEmptySeat(struct flight * my_flight, int seat_num);
void listOfEmptySeat(struct flight * my_flight, int seat_num);
void alphabeticalOfSeat(struct flight * my_flight, int seat_num);
void assignSeat(struct flight * my_flight, int seat_num);
void deleteAssign(struct flight * my_flight, int seat_num);
void confirm(struct flight * my_flight, int seat_num);

int main(void)
{
	// initialize
	struct flight * my_flights = (struct flight *)malloc(FLIGHTNUM * sizeof(struct flight));
	for(int i = 0; i < FLIGHTNUM; i++)
	{
		my_flights[i].id = i + 101;
		my_flights[i].confirmed = false;
		for(int j = 0; j < SEATNUM; j++)
		{
			my_flights[i].seats[j].id = i * 10 + j;
			my_flights[i].seats[j].ordered = false;
			strcpy(my_flights[i].seats[j].fname, " ");
			strcpy(my_flights[i].seats[j].lname, " ");
		}
	}
	
	struct flight * flightChoice;

	printf("******************************\n");
	printf("* Welcome to Hugeman Flight! *\n");
	printf("******************************\n");

	while((flightChoice = choiceFlight(my_flights, FLIGHTNUM)) != NULL)
	{
		char choice;
		while((choice = getChoice(flightChoice)) != 'f')
		{
			switch(choice)
			{
				case 'a' : numberOfEmptySeat(flightChoice, SEATNUM); break;
				case 'b' : listOfEmptySeat(flightChoice, SEATNUM); break;
				case 'c' : alphabeticalOfSeat(flightChoice, SEATNUM); break;
				case 'd' : assignSeat(flightChoice, SEATNUM); break;
				case 'e' : deleteAssign(flightChoice, SEATNUM); break;
				case 'g' : confirm(flightChoice, SEATNUM); break;
			}
		}
	}
	
	printf("Bye.\n");

	return 0;
}

struct flight * choiceFlight(struct flight * my_flights, int flight_num)
{
	printf("This is the flight we have:\n");
	for(int i = 0; i < flight_num; i++)
	{
		printf("%d: Flight%d\n", i, my_flights[i].id);
	}
	printf("Please enter the number(left of ':')(-1 to quit): ");
	int flightChoice;
	scanf("%d", &flightChoice);
	while(getchar() != '\n')
	{
		continue;
	}

	if(flightChoice == -1)
	{
		return NULL;
	}


	return &my_flights[flightChoice];
}

char getChoice(struct flight * flightChoice)
{
	struct flight * pf = flightChoice;
	int ch;

	if(pf -> confirmed)
	{
		printf("\nFlight%d is confirmed.\n", pf -> id);
		printf("This is the choice menu for flight%d:\n", pf -> id);
		printf("a) Show number of empty seats.\n");
		printf("b) Show list of empty seats.\n");
		printf("c) Show alphabetical list of seats.\n");
		printf("f) Quit.\n");

		printf("Please enter a letter: ");

		while((ch = getchar()) != EOF)
		{
			while(getchar() != '\n')
			{
				continue;
			}

			ch = tolower(ch);

			if(strchr("abcf", ch) == NULL)
			{
				printf("Please enter a, b, c or f: ");
			}
			else
			{
				break;
			}
		}
	}
	else
	{
		printf("\nThis is the choice menu for flight%d:\n", pf -> id);
		printf("a) Show number of empty seats.\n");
		printf("b) Show list of empty seats.\n");
		printf("c) Show alphabetical list of seats.\n");
		printf("d) Assign a customer to a seat assignment.\n");
		printf("e) Delete a seat assignment.\n");
		printf("f) Quit.\n");
		printf("g) CONFIRM THIS FLIGHT\n");

		printf("Please enter a letter: ");

		while((ch = getchar()) != EOF)
		{
			while(getchar() != '\n')
			{
				continue;
			}

			ch = tolower(ch);

			if(strchr("abcdefg", ch) == NULL)
			{
				printf("Please enter a, b, c, d, e, f or g: ");
			}
			else
			{
				break;
			}
		}
	}
	return ch;
}

int numberOfEmptySeat(struct flight * my_flight, int n)
{
	struct flight * pf = my_flight;

	int count = 0;

	for(int i = 0; i < n; i++)
	{
		if(!(pf -> seats[i].ordered))
		{
			count++;
		}
	}

	printf("Empty Seat Number: %d\n", count);
	return count;
}

void listOfEmptySeat(struct flight * my_flight, int n)
{
	struct flight * pf = my_flight;

	printf("\nEmpty Seat List:\n");
	for(int i = 0; i < n; i++)
	{
		if(!(pf -> seats[i].ordered))
		{
			printf("Seat: %d\n", pf -> seats[i].id);
		}
	}
}

void alphabeticalOfSeat(struct flight * my_flight, int n)
{
	struct flight * pf = my_flight;

	printf("\nSeat Ordered Customer:\n");
	for(int i = 0; i < n; i++)
	{
		printf("%4d", my_flight -> seats[i].id);
		printf("%8s", (my_flight -> seats[i].ordered) ? "true" : "false");
		printf("%s %s\n", my_flight -> seats[i].fname, my_flight -> seats[i].lname);
	}
}

void assignSeat(struct flight * my_flight, int n)
{
	struct flight * pf = my_flight;
	if(numberOfEmptySeat(pf, n) == 0)
	{
		printf("This flight is FULL!\n");
		return;
	}

	int seatnumber;
	printf("\nPlease enter the seat number: ");
	scanf("%d", &seatnumber);
	while(pf -> seats[seatnumber].ordered)
	{
		printf("This seat has been ordered, please choice another one!\n");
		printf("enter the other seat number: ");
		scanf("%d", &seatnumber);
	}

	printf("\nPlease enter the customer first name: ");
	scanf("%s", pf -> seats[seatnumber].fname);
	printf("\nPlease enter the customer last name: ");
	scanf("%s", pf -> seats[seatnumber].lname);
	pf -> seats[seatnumber].ordered = true;

	printf("Assigned success.\n");
}

void deleteAssign(struct flight * my_flight, int n)
{
	struct flight * pf = my_flight;
	if(numberOfEmptySeat(pf, n) == n)
	{
		printf("No seat ordered!\n");
		return;
	}

	int seatnumber;
	printf("\nPlease enter the seat number to delete: ");
	scanf("%d", &seatnumber);
	while(!(pf -> seats[seatnumber].ordered))
	{
		printf("This seat hasn't been ordered, please choice another one!\n");
		printf("enter the other seat number: ");
		scanf("%d", &seatnumber);
	}

	strcpy(pf -> seats[seatnumber].fname, " ");
	strcpy(pf -> seats[seatnumber].lname, " ");

	pf -> seats[seatnumber].ordered = false;

	printf("Delete success.\n");
}

void confirm(struct flight * my_flight, int seat_num)
{
	struct flight * pf = my_flight;

	pf -> confirmed = true;
	printf("Confirm Success.\n");
}
