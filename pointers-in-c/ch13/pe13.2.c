// 2020-12-18 created by Akson
// pe13.2

typedef int ElemType;

typedef struct NODE
{
	ElemType val;
	struct NODE* link;
} Node;

void translate(Node* pNode, void (*func)(const void*))
{
	while(pNode != NULL)
	{
		func(&pNode -> val);

		pNode = pNode -> link;
	}
}