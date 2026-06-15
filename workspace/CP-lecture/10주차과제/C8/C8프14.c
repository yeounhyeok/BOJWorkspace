#include<stdio.h>
#include<stdlib.h>

int a[100], cur;

void show_digit(int x){
    if(x==0) return;
    a[cur++] = x%10;
    show_digit(x/10);
    return;
}
int main(){
    int n;
    printf("정수를 입력하시오: ");
    scanf("%d", &n);
    
    show_digit(n);

    for(int i=cur-1;i>=0;i--) printf("%d ", a[i]);
    return 0;
}