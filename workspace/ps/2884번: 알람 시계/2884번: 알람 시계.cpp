#include <stdio.h>

int a, b, B;
int main(){
    scanf("%d %d", &a, &b);
    B=b-45;
    if(B<0){
        a--;
        if(a<0) a=24+a;
        b = 60+B;
        printf("%d %d", a, b);
    }
    else{
        printf("%d %d", a, b-45);
    }
    return 0;
}


