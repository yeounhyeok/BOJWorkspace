#include <stdio.h>
#define SQUARE(x)  ((x) * (x))

int main(void)
{
    int x = 2;

    printf("SQUARE(3) = %d\n", SQUARE(3));      // 상수에도 적용 가능
    printf("SQUARE(1.2) = %f\n", SQUARE(1.2));      // 실수에도 적용 가능
    printf("SQUARE(2+3) = %d\n", SQUARE(2 + 3));    // 수식에도 적용 가능

    printf("x = %d\n", x);      // 변수에도 적용 가능
    printf("SQUARE(x) = %d\n", SQUARE(x));      // 변수에도 적용 가능
    printf("SQUARE(++x) = %d\n", SQUARE(++x));      // 논리 오류

    return 0;
}
