#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
char* key = "0123456789";

int main(void)
{
    char name[256];
    char name1[256];
    printf("입력 파일 이름: ");
    scanf("%s", name);
    printf("출력 파일 이름: ");
    scanf("%s", name1);
    FILE* f1 = fopen(name, "r+b");
    FILE* f2 = fopen(name1, "w+b");

    if (!f1 || !f2) {
        printf("파일 열기에 실패했습니다.\n");
        if (f1) fclose(f1);
        if (f2) fclose(f2);
        return 1;
    }

    fseek(f1, 0, SEEK_END);
    long length = ftell(f1);
    char* p = (char*)malloc(length * sizeof(char));

    fseek(f1, 0, SEEK_SET);
    fread(p, sizeof(char), length, f1);

    for (unsigned long i = 0; i < length; i++) {
        p[i] ^= key[i % strlen(key)];
    }
    fwrite(p, sizeof(char), length, f2);
    free(p);
    fclose(f1);
    fclose(f2);
    return 0;
}
