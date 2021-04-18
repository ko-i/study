// 2020-12-28 created by Akson
// pc9.1

#include <stdio.h>

char ga[] = "abcdefghijklmnopqrstuvwxyz";

void my_array_func(char ca[10]);
void my_pointer_func(char *pa);

int main(void)
{
    printf(" addr of global array = %p\n", &ga);
    printf(" addr (ga[0]) = %p\n", &(ga[0]));
    printf(" addr (ga[1]) = %p\n", &(ga[1]));

    my_array_func(ga);
    my_pointer_func(ga);

    return 0;
}

void my_array_func(char ca[10])
{
    printf(" addr of array param = %p\n", &ca);
    printf(" addr (ca[0]) = %p\n", &(ca[0]));
    printf(" addr (ca[1]) = %p\n", &(ca[1]));
    printf(" ++ca = %p\n", ++ca);
}

void my_pointer_func(char *pa)
{
    printf(" addr of array param = %p\n", &pa);
    printf(" addr (pa[0]) = %p\n", &(pa[0]));
    printf(" addr (pa[1]) = %p\n", &(pa[1]));
    printf(" ++pa = %p\n", ++pa);
}
