#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int check_prime(int);

int main(void) {
    int n, flag = 0;
    printf("양의 정수를 입력하시오: ");
    scanf_s("%d", &n);

    for (int i = 2; i < n; i++) {
        if (check_prime(i) == 1) {
            if (check_prime(n - i) == 1) {
                printf("%d = %d + %d\n", n, i, n - i);
                flag = 1;
            }
        }
    }
    if (flag == 0)
        printf("%d은 소수들의 합으로 표시될 수 없습니다.\n", n);
    return 0;
}
int check_prime(int n) {
        int is_prime = 1;       // 일단 소수라고 가정한다.
        for (int i = 2; i < n; ++i) {
                if (n % i == 0) {
                        is_prime = 0;
                        break;
                }
        }
        return is_prime;
}
