#include<stdio.h>

int account, input, tmp;

void check(){
    printf("잔고는 %d입니다.\n", account);
}

void deposit(int a){
    account+=a;
    printf("새로운 ");
    check();
}

void withdraw(int a){
    if(account-a>=0) account-=a;
    else printf("잔액의 부족합니다\n");

    printf("새로운 ");
    check();
}

int main(){
    do{
        printf("==하나를 선택하세요==\n1. 잔고 확인\n2. 입금\n3. 인출\n4. 종료\n");
        scanf("%d", &input);

        switch(input){
            case 1:
                check();
                break;
            case 2:
                printf("입금금액 : ");
                scanf("%d", &tmp);
                deposit(tmp);
                break;
            case 3:
                printf("출금금액 : ");
                scanf("%d", &tmp);
                withdraw(tmp);
                break;
            case 4:
                break;
            default:
                printf("다시 입력하세요\n");
        }

    }while(input!=4);

    return 0;
}