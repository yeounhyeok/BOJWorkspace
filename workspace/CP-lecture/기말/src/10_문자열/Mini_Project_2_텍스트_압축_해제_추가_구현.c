#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char processing[100];

void printRLE(char str[])
{
    char temp[10];
    int n = strlen(str);
    for (int i = 0; i < n; i++) {
        int count = 1;
        while (i < n - 1 && str[i] == str[i + 1]) {
            count++;
            i++;
        }
        printf("%d%c", count, str[i]);
        sprintf(temp, "%d%c", count, str[i]);
        strcat(processing, temp);
    }
    printf("\n\n");
}

void recover(char str[])
{
    int i, j, k, num;
    char collect[10];

    int n = strlen(str);
    for (i = 0; i < n; i++) {
        j = 0;
        while(str[i+j] >= '0' && str[i+j] <= '9') {
            collect[j]=str[i+j++];
        }
        collect[j] = 0;
        num = atoi(collect);
        for (k = 0; k < num; k++) {
            putchar(str[i + j]);
        }
        i += j;
    }
}

int main(void)
{
    char s[100];
    printf("문자열 입력: ");
    gets_s(s, 100);
    printRLE(s);
    printf("복구 문자열: ");
    recover(processing);
    return 0;
}
