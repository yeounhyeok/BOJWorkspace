#include <stdio.h>
int n, a, x;
int main(){
    scanf("%d %d", &n, &x);
    for(int i=0;i<n;i++){
        scanf("%d", &a);
        if(a<x) printf("%d ", a);
    }
    return 0;
}
