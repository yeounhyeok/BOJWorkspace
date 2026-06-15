#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    char s[] = "HelloWorld";
    char *p = "HelloWorld";

    s[0] = 'h'; // 변경 가능하다.
                // p[0] = 'h';  // 이 문장을 실행하면 프로그램의 작동이 중지된다.

    printf("포인터가 가리키는 문자열 = %s \n", p);
    p = "Goodbye";  // 이것은 가능하다. 큰 장점이다.
    printf("포인터가 가리키는 문자열 = %s \n", p);
    return 0;
}
