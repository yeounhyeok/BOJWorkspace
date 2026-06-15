#include<stdio.h>

int main(){
    char x;
    printf("문자를 입력하시오:");
    scanf("%c", &x);
    if(x<91&&x>64) printf("대문자");
    else printf("소문자");
    printf("입니다.\n");
    return 0;
}