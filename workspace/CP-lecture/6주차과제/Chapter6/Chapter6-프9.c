#include<stdio.h>

int main(){
    char x;
    int cnt=0;
    printf("문자를 입력하시오: (종료 .)");
    while((x=getchar())!='.'){
        printf("문자를 입력하시오: (종료 .)");
        scanf(" ");
        if(x=='a') cnt++;
    }
    printf("a의 개수 = %d\n", cnt);
    return 0;   
}