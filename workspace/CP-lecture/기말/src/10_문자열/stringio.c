#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    char name[100];
    char address[100];


    printf("이름이 어떻게 되시나요? ");
    scanf("%s", name);

    printf("어디 사시나요? ");
    scanf("%s", address);

    printf("안녕하세요, %s에 사는 %s씨.\n", address, name);
    return 0;
}
