#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
    FILE *fp;
    int number;
    char name[30];
    float score;
    char ch;

    // 성적 파일을 쓰기 모드로 연다.
    fp = fopen("scores.txt", "w");
    if (fp == NULL) {
        printf("성적 파일 scores.txt를 열 수 없습니다.\n");
        exit(0);
    }

    do {
        printf("\n학번 : ");
        scanf("%d", &number);

        printf("이름 : ");
        scanf("%s", name);

        printf("성적 : ");
        scanf("%f", &score);

        fprintf(fp, "%d %s %f\n", number, name, score); // 파일에 기록한다.
        printf("데이터 추가를 계속? (y/n) : ");
        ch = getche();  // 에코우를 하면서 하나의 문자를 입력받는 함수
    } while (ch != 'n');

    fclose(fp);
    return 0;
}
