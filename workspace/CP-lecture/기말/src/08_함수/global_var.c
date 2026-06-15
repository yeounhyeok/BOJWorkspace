#include <stdio.h>

int global = 123;

void sub1()
{
    printf("%d\n", global);
}

void sub2()
{
    printf("%d\n", global);
}

int main(void)
{
    sub1();
    sub2();
    return 0;
}
