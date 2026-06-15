#include<stdio.h>

int main(){
    int x;
    printf("요일을 0(일요일)에서 6까지의정수로 입력하시오: ");
    scanf("%d", &x);
    if(x<6&&x>0) printf("주중");
    else printf("주말");
    printf("입니다.\n");
    return 0;
}