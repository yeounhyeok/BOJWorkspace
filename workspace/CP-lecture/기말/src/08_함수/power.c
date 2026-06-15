#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 함수를 정의한다.
int get_integer()
{
    int value;
    printf("정수를 입력하시오 : ");
    scanf("%d", &value);
    return value;
}

// 함수를 정의한다.
int power(int x, int y)
{
    int i;
    long result = 1;

    for (i = 0; i < y; i++)
        result *= x;        // result = result * x

    return result;
}

int main(void)
{
    int x = get_integer();  // 함수를 호출한다.
    int y = get_integer();  // 함수를 호출한다.
    int result = power(x, y);
    printf("%d의 %d승 = %d \n", x, y, result);

    return 0;
}
