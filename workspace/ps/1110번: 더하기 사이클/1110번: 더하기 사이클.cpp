#include <stdio.h>
int n, x0, x1, x2, i=1;
int main(){
    scanf("%d", &n);
    x0 = n;
    x1 = x0/10 + x0%10;
    x2 = x1%10 + x0%10*10;
    while(1){
        i++;
        x1 = x2/10 + x2%10;
        x2 = x1%10 + x2%10*10;
        if(x2==n) break;

    }
    if(n==0) printf("1");
    else printf("%d", i);
    return 0;
}
