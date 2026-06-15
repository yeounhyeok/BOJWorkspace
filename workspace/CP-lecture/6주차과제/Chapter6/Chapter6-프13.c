#include<stdio.h>

int main(){
    int n, a=0, b=1, c;
    printf("몇 번째 항까지 구할까요? ");
    scanf("%d", &n);

    printf("%d, ", a);
    if(n>0) printf("%d, ", b);

    for(int i=2;i<=n;i++) {
        printf("%d, ", a+b);
        c=b;
        b+=a;
        a=c;
    }
    return 0;   
}