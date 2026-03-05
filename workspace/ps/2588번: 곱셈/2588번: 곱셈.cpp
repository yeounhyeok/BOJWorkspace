#include <stdio.h>
int a, b, x;
int main(){
    scanf("%d", &a);
    scanf("%d", &b);
    x = a*b;
    for(int i=0;i<3;i++){
        printf("%d\n", a*(b%10));
        b/=10;
    }
    printf("%d", x);
    return 0;
}


