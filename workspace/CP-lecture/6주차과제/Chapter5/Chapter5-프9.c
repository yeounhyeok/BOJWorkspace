#include<stdio.h>

int main(){
    int a, b;
    char c;
    printf("수식을 입력하시오:");
    scanf("%d %c %d", &a, &c, &b);

    switch(c){
        case '+':
            printf("%d\n", a+b);
            break;
        case '-':
            printf("%d\n", a-b);
            break;
        case '*':
            printf("%d\n", a*b);
            break;
        case '/':
            printf("%d\n", a/b);
            break;
    }
    
    return 0;
}