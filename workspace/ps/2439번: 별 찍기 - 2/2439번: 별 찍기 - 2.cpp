#include <stdio.h>
int n, a, b;
int main(){
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        for(int k=1;k<=n-i;k++){
            printf(" ");
        }
        for(int j=1;j<=i;j++){
            printf("*");
        }
        if(i!=n) printf("\n");
    }
    return 0;
}
