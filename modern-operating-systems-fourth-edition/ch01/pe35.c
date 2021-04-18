// 2020-11-17 created by Akson

#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int count = 0;
    while(1)
    {
        fork();
    }
    return 0;
}
