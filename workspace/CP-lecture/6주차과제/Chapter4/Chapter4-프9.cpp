#include <stdio.h>

int main(){
    int num;
    scanf("%d", &num);
    printf("LSB는 %d\n", num&1);
    return 0;
}