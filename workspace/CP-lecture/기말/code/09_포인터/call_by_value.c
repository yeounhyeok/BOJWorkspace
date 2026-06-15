#include <stdio.h>

void modify(int value)
{
    value = 99;     // 매개 변수를 변경한다.
}

int main(void)
{
    int number = 1;

    modify(number);
    printf("number = %d\n", number);

    return 0;
}
