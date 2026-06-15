#include <stdio.h>

int main(){
    int w, h;
    printf("첫 번째 정수를 입력하시오: ");
    scanf("%d", &w);
    printf("두 번째 정수를 입력하시오: ");
    scanf("%d", &h);
    printf("몫은 %d이고 나머지는 %d입니다.\n", w/h, w%h);
    return 0;
}