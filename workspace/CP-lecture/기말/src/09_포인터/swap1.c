#include <stdio.h>
void swap(int x, int y)
{
    int tmp;

    tmp = x;
    x = y;
    y = tmp;
}

int main(void)
{
    int a = 10, b = 20;

    swap(a, b);
    printf("swap() 호출후 a=%d b=%d\n", a, b);
    return 0;
}
