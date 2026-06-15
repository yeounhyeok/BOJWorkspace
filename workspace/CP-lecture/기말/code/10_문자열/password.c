#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char password[10];
    int i;

    system("cls");
    printf("패스워드를 입력하시오: ");
    for (i = 0; i < 8; i++) {
        password[i] = _getch();
        printf("*");
    }
    password[i] = '\0';
    printf("\n");

    printf("입력된 패스워드는 다음과 같습니다: ");
    printf("%s\n", password);
    _getch();
    return 0;
}
