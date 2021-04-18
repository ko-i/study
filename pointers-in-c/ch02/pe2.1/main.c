// 2020-12-03 created by Akson
// pe2.1 main.c compile with increment.c and negate.c

#include <stdio.h>
#include "increment.h"
#include "negate.h"

#define TESTSIZE 3

int main(int argc, char const *argv[])
{
    int test_numbers[TESTSIZE] = {10, 0, -10};

    for(int i = 0; i < TESTSIZE; i++)
    {
        printf("Test %d:\n", i + 1);
        printf("Source number: %d\n", test_numbers[i]);
        printf("increment(%d) is %d\n", test_numbers[i], increment(test_numbers[i]));
        printf("negate(%d) is %d\n", test_numbers[i], negate(test_numbers[i]));
    }

    printf("Bye!\n");
    
    return 0;
}
