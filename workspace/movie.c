#include<stdio.h>

typedef struct Movie{
    char title[100];
    char director[50];
    int release_year;
    float rating;
} Movie;

void input(Movie *m){
    scanf("%s%s%d%f", m->title, m->director, &m->release_year, &m->rating);
}

void print(Movie *m){
    printf("%s\n%s\n%d\n%f\n", m->title, m->director, m->release_year, m->rating);
}

int main(){
    Movie tmp;
    input(&tmp);
    print(&tmp);
    return 0;
}

/*
띄어쓰기 할때 gets(변수 포인터)
다 받고 getchar() 해야지 개행문자가 안남아있고 이상한데 들어가는 거 방지함
포인터 초기화 및 넘겨줄때의 자료형(포인터인지 변수자체인지 확인)
*/

