#include<stdio.h>

int main(){
    int arr[10];
    for(int i=1;i<11;i++){
        arr[i-1]=i*10;
        printf("%d ", arr[i-1]);
    }

    printf("\n");

    int target, flag=-1;
    scanf("%d", &target);

    for(int i=0;i<10;i++){
        if(arr[i]==target) {
            flag=i;
            break;
        }
    }

    if(flag!=-1) printf("인덱스 %d번에 있다\n", flag);
    else printf("실패 데이터 = %d\n", target);
}