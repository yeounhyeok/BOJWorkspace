#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[11] = "Hello";
    strcat(s, "World"); // s에 문자열 “World"를 붙인다.
    printf("%s \n", s);

    return 0;
}
