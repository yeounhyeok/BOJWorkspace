#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

float get_average(int scores[], int n)
{
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += scores[i];
    }
    return (sum / n);
}

int main(void)
{
    float avg_score;

    int scores[10] = { 67, 55, 43, 80, 93, 84, 75, 90, 88, 40 };

    avg_score = get_average(scores, 10);
    printf("평균 점수는 %f 입니다.", avg_score);
}
