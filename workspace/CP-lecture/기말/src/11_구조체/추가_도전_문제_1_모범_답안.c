#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define NUM_MOVIES 3

// 영화 정보를 담는 구조체
struct Movie {
    char title[100];
    char director[50];
    int release_year;
    float rating;
};

// 영화 정보를 입력받는 함수
void inputMovie(struct Movie* m) {
    printf("영화 제목: ");
    gets(m->title);
    printf("감독: ");
    gets(m->director);
    printf("개봉 연도: ");
    scanf("%d", &m->release_year);
    printf("평점: ");
    scanf("%f", &m->rating);
    getchar(); // 남아있는 개행 문자를 제거
}

// 영화 정보를 출력하는 함수
void printMovie(const struct Movie* m) {
    printf("제목: %s\n", m->title);
    printf("감독: %s\n", m->director);
    printf("개봉 연도: %d\n", m->release_year);
    printf("평점: %.1f\n", m->rating);
}

int main(void) {
    struct Movie movies[NUM_MOVIES];

    // 영화 정보 입력
    for (int i = 0; i < NUM_MOVIES; i++) {
        printf("영화 %d 정보 입력\n", i + 1);
        inputMovie(&movies[i]);
    }

    // 영화 정보 출력
    printf("-----------------------------------\n");
    for (int i = 0; i < NUM_MOVIES; i++) {
        printf("\n영화 %d 정보\n", i + 1);
        printMovie(&movies[i]);
    }
    printf("-----------------------------------\n");

    return 0;
}
