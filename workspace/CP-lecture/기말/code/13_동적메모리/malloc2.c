#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *pi;

    pi = (int *)malloc(5 * sizeof(int));
    if (pi == NULL) {
            printf("메모리 할당 오류\n");
            exit(1);
    }
    *pi = 1;            // pi[0] = 1;
    *(pi + 1) = 2;      // pi[1] = 2;
    *(pi + 2) = 3;      // pi[2] = 3;
    *(pi + 3) = 4;      // pi[3] = 4;
    *(pi + 4) = 5;      // pi[4] = 5;

    free(pi);
    return 0;
}
