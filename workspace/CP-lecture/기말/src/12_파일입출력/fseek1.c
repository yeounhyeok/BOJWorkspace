#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    long length;

    FILE * fp = fopen("d:\\lena(256x256).raw", "rb");
    if (fp == NULL) {
        printf("lena.raw 파일을 열 수 없습니다.");
        exit(1);
    }
    fseek(fp, 0, SEEK_END);

    length = ftell(fp);
    printf("파일 크기=%d 바이트\n", length);
    fclose(fp);
    return 0;
}
