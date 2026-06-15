#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define    NUM_STUDENTS    3
#define NUM_SUBJECTS    4

void avg_score(int jumsu[][NUM_SUBJECTS], double avg[], int st_no, int num)
{
    int i, j, sum = 0;
    for (j = 0; j < st_no; j++) {
        sum = 0;
        for (i = 0; i < num; i++) {
            sum += jumsu[j][i];
        }
        avg[j] = (double)sum / num;
    }
}

int main(void)
{
    int i, scores[NUM_STUDENTS][NUM_SUBJECTS] = { {98, 50, 33, 60}, {86, 80, 99, 40}, {45, 67, 30, 90} };
    double avg_scores[NUM_STUDENTS];

    avg_score(scores, avg_scores, NUM_STUDENTS, NUM_SUBJECTS);

    for (i = 0; i < NUM_STUDENTS; i++) {
        printf("%d 학생의 4과목의 평균은 %lf 입니다.\n", i + 1, avg_scores[i]);
    }
}
