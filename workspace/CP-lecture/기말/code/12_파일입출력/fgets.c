#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
    FILE *fp;
    char str[100];

    fp = fopen("file.txt", "w");

    if (fp == NULL) {
        fprintf(stderr, "파일 file.txt를 열 수 없습니다.\n");
        exit(0);
    }

    do {
        gets_s(str, 100);           // 사용자로부터 한 줄을 받는다.
        fputs(str, fp);     // 한 줄을 파일에 쓴다.
    } while (strlen(str) != 0); // 사용자가 아무것도 적지 않으면 반복 루프 탈출

    fclose(fp);
    return 0;
}
