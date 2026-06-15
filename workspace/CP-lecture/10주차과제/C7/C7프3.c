#include <stdio.h>

int main(){
    int n, a[1000], sum=0;
    printf("입력할 정수의 개수:");
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        printf("%d번째 요소를 입력하시오:", i);
        scanf("%d", a+i);
        sum+=a[i];
    }
    printf("합=%d\n", sum);
    return 0;
}