#include<stdio.h>

int main(){
    int x;
    printf("정수를 입력하시오: ");
    scanf("%d", &x);
    printf("%d은(는) ", x);
    printf("%s", (x%2)?"홀":"짝");
    printf("수입니다.\n");
    return 0;
}