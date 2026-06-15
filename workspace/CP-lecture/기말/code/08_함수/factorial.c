#define _CRT_SECURE_NO_WARNINGS
// 순환적인 팩토리얼 함수 계산
#include <stdio.h>
int factorial(int n);

int main(void)
{
    int x = 0, result;

    printf("정수를 입력하시오:");
    scanf("%d", &x);

    result = factorial(x);
    printf("%d!은 %d입니다.\n", x, result);

    return 0;
}

int factorial(int n)
{
    printf("factorial(%d)\n", n);

    if (n <= 1) return 1;
    else return n * factorial(n - 1);
}
