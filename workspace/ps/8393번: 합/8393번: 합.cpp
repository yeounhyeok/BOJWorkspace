#include <stdio.h>
int a, s;
int main(){
    scanf("%d", &a);
    for(int i=1;i<=a;i++){
        s+=i;
    }
    printf("%d", s);
    return 0;
}



