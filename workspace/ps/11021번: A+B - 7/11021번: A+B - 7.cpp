#include <stdio.h>
int n, a, b;
int main(){
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        scanf("%d %d", &a, &b);
        printf("Case #%d: %d\n",i+1 , a+b);
    }

    return 0;
}
