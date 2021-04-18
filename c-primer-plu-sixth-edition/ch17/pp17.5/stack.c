// 2020-11-16 created by Akson

#include <stdio.h>
#include "stack.h"

void InitializeStack(Stack * ps)
{
    ps -> top = 0;
}

bool FullStack(const Stack * ps)
{
    if(ps -> top == MAXSTACK)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool EmptyStack(const Stack * ps)
{
    if(ps -> top == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Push(Item item, Stack * ps)
{
    if(FullStack(ps))
    {
        return false;
    }

    ps -> items[ps -> top] = item;
    (ps -> top)++;

    return true;
}

bool Pop(Item *pitem, Stack * ps)
{
    if(EmptyStack(ps))
    {
        return false;
    }

    *pitem = ps -> items[(ps -> top) - 1];
    (ps -> top)--;

    return true;
}