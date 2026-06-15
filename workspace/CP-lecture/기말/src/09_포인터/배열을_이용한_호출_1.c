#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define NUM_SUBJECTS    4

double avg_score(int jumsu[], int num)
{
    int i, sum = 0;

    for (i = 0; i < num; i++) {
        sum += jumsu[i];
    }
    return (double)sum / num;
}

int main(void)
{
    int i, scores[NUM_SUBJECTS] ={98, 50, 33, 60};
    double average;

    average = avg_score(scores, NUM_SUBJECTS);
    printf("학생의 4과목의 평균은 %lf 입니다.\n", average);
}
