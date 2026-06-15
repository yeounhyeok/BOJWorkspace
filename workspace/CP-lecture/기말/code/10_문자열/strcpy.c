#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
    char src[] = "Hello";
    char dst[6];

    strcpy(dst, src);
    printf("복사된 문자열 = %s \n", dst);
    return 0;
}
