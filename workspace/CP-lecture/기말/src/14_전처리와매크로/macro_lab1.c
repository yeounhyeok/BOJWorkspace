#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define and  &&
#define or  ||

int main(void)
{
    int credits;
    double gpa;

    printf("지금까지 획득한 학점수를 입력하시오: ");
    scanf("%d", &credits);
    printf("지금까지 획득한 학점평균을 입력하시오: ");
    scanf("%lf", &gpa);

    if (credits >= 120 and gpa >= 2.0)
        printf("졸업 가능합니다. \n");
    else
        printf("좀 더 다녀야 합니다. \n");

    return 0;
}
