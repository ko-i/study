// 2020-11-16 created by Akson

#include <stdio.h>
#include <string.h>
#include "stack.h"

char * s_gets(char * str, int n);

int main(void)
{
    Stack my_stack;
    InitializeStack(&my_stack);

    char str[MAXSTACK];
    printf("Enter a string (empty line to quit): ");
    while((s_gets(str, MAXSTACK)) != NULL && str[0] != '\0')
    {
        char * ps = str;
        while(*ps != '\0')
        {
            if(Push(*ps, &my_stack) == false)
            {
                printf("Stack FULL");
                break;
            }
            ps++;
        }
        
        while(Pop(ps, &my_stack))
        {
            printf("%c", *ps);
        }

        printf("\nEnter next string(empty line to quit): ");
    }

    printf("Done!\n");

    return 0;
}

char * s_gets(char * str, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(str, n, stdin);

    if(ret_val)
    {
        find = strchr(str, '\n');
        if(find)
        {
            *find = '\0';
        }
        else
        {
            while(getchar() != '\n')
            {
                continue;
            }
        }  
    }

    return ret_val;
}