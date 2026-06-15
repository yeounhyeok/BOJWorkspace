#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000

int main(void)
{

    int *p = NULL;
    int i = 0;

    p = (int *)malloc(SIZE * sizeof(int));
    if (p == NULL) {
        printf("메모리 할당 오류\n");
        exit(1);
    }

    for (i = 0; i < SIZE; i++)
        p[i] = rand();

    int max = p[0];
    for (i = 1; i < SIZE; i++) {
        if (p[i] > max)
            max = p[i];
    }

    printf("최대값=%d \n", max);
    free(p);

    return 0;
}
