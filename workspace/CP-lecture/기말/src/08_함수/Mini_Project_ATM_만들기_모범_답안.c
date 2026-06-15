#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void mainMenu();
void checkBalance(int balance);
int moneyDeposit(int balance);
int moneyWithdraw(int balance);
void menuExit();
void errorMessage();

int main() {
    int option = 0;
    int balance = 10000;
    int choose = 0;

    bool again = true;

    while (again) {
        mainMenu();

        scanf("%d", &option);

        switch (option) {
        case 1:
            checkBalance(balance);
            break;
        case 2:
            balance = moneyDeposit(balance);
            break;
        case 3:
            balance = moneyWithdraw(balance);
            break;

        case 4:
            menuExit();
            return 0;

        default:
            errorMessage();
        }

        system("CLS");
    }
    return 0;
}

void mainMenu() {
    printf("**********Welcome to 콘서트 ATM***********\n");
    printf("****하나를 선택하시오****\n");
    printf("<1>  잔고 확인\n");
    printf("<2>  입금\n");
    printf("<3>  인출\n");
    printf("<4>  종료\n");

}

void checkBalance(int balance) {
    printf("****잔고는 %d입니다.\n\n", balance);
    printf("아무키나 누르세요\n");
    getch();

}

int moneyDeposit(int balance) {
    int deposit;
    printf("****입금 금액을 입력하시오: ");
    scanf("%d", &deposit);

    balance += deposit;
    printf("\n새로운 잔고는 %d입니다.\n\n", balance);
    printf("아무키나 누르세요\n");
    getch();
    return balance;

}

int moneyWithdraw(int balance) {
    int withdraw;
    bool back = true;

    while (back) {
        printf("출금 금액을 입력하시오: ");
        scanf("%d", &withdraw);


        if (withdraw < balance) {
            back = false;
            balance -= withdraw;
            printf("\n새로운 잔고는 %d입니다.\n\n", balance);
        }

        else {
        }
    }
    getch();
    printf("아무키나 누르세요\n");
    return balance;
}

void menuExit() {
    printf("다음에 또 만나요~~~\n");
}

void errorMessage() {
    printf("1~4번 중 하나를 선택하세요!!!\n");
    getch();
}
