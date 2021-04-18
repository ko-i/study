// 2020-12-18 created by Akson
// pe13.3

typedef int ElemType;

typedef struct NODE
{
	ElemType val;
	NODE* next;
	Node* prev;
} Node;

typedef struct TRANSACTION
{
	int type;
} Transaction;

typedef enum {NEW, DELETE, FORWARD, BACKWARD, SEARCH, EDIT} Trans_type;

Node* add_new_trans(void*, void*);
Node* delete_trans(void*, void*);
Node* forward_trans(void*, void*);
Node* backward_trans(void*, void*);
Node* search(void*, void*);
Node* edit(void*, void*);

Node* (*func[])(void*, void*) = 
{
	add_new_trans, delete_trans, forward_trans, backward_trans ,search, edit
};





int main(int argc, char const *argv[])
{
	Node* list;
	Node* current;
	Transaction* transaction;

	if(transaction -> type >= 0 && transaction -> type < 6)
	{
		current = func[transaction -> type](current, transaction);
	}
	else
	{
		printf("Illegal transaction type!\n");
	}

	return 0;
}