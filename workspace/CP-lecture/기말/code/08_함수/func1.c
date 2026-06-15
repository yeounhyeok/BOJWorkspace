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

int main(void)
{
    int x = get_integer();  // 함수를 호출한다.
    int y = get_integer();  // 함수를 호출한다.
    int result = x + y;
    printf("두수의 합 = %d \n", result);

    return 0;
}
