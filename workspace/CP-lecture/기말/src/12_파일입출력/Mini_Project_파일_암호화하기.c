#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char name1[20]; // 배열을 사용한 정적 메모리 할당
    char* name2;    // malloc() 함수를 사용한 동적 메모리 할당

    name2 = (char*)malloc(sizeof(char) * 20); // name1[20] 배열과 동일한 크기로 동적 메모리 할당
    if (name2 == (char*)NULL) {               // 메모리 할당 여부 반드시 확인 후 사용해야함
        printf("name2 malloc() fail!!!\n");
        exit(1);
    }

    strcpy(name1, "홍길동"); // 정적 메모리 할당 배열 사용
    strcpy(name2, "이순신"); // 동적 메모리 할당 배열 사용

    printf("%s\n", name1);
    printf("%s\n", name2);

    free(name2);  // 할당 메모리 해제
}
