#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int n=12, x;
    srand(time(NULL));

    printf("현재 스틱의 개수: %d\n", n);

    while(1){
        printf("몇 개의 스틱을 가져가시렵니까?: ");
        scanf("%d", &x);
        n-=x;
        
        if(n<=0){
            printf("\n=====컴퓨터 승=====\n\n");
            break;
        }

        x=rand()%3+1;
        n-=x;
        printf("**컴퓨터는 %d개의 스틱을 가져갔습니다.\n",x);
        
        if(n<=0){
            printf("\n=====사용자 승=====\n\n");
            break;
        }
        printf("현재 스틱의 개수: %d\n", n);
    }
    return 0;
}