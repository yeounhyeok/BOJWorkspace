#include<stdio.h>
#include<stdlib.h>

int tmp, sum[2];

int rollDice(){ return rand()%6 + 1; }

int main(){
    printf("사용자 주사위=(");
    for(int i=0;i<3;i++){
        sum[0] += tmp = rollDice();
        printf("%d%s", tmp, (i==2) ? "" : ", ");
    }
    printf(")=%d\n", sum[0]);
    
    printf("사용자 주사위=(");
    for(int i=0;i<3;i++){
        sum[1] += tmp = rollDice();
        printf("%d%s", tmp, (i==2) ? "" : ", ");
    }
    printf(")=%d\n", sum[1]);
    
    printf("%s", (sum[0]==sum[1]) ? "무승부" : (sum[0]>sum[1]) ? "사용자 승리" : "컴퓨터 승리");
    printf("\n");
    
    return 0;
}