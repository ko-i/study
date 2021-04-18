// 2020-11-15 created by Akson
// Code17.3 list.h

#ifndef LIST_H_
#define LIST_H_

#include <stdbool.h>

#define TSIZE 45
#define MAXSIZE 100

struct film
{
	char title[TSIZE];
	int rating;
};

typedef struct film Item;

typedef struct list
{
	Item entries[MAXSIZE];
	int items;
} List;


void InitializeList(List * plist);

bool ListIsEmpty(const List * plist);

bool ListIsFull(const List * plist);

unsigned int ListItemCount(const List * plist);

bool AddItem(Item item, List * plist);

void Traverse(const List * plist, void(*pfun)(Item item));

void EmptyTheList(List * plist);

#endif