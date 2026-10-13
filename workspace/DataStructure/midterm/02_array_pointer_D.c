#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap_ptr(char **a, char **b){
    char *c = *a;
    *a = *b;
    *b = c;
}

// [헷갈린 점 1] 처음엔 `p=&a;` / `p=&b;`로 씀. 이건 매개변수 p(복사본)에 대입하고,
// &a는 함수 지역변수의 주소라 함수가 끝나면 무효. main의 p는 그대로 0이었음.
// 바꾸려는 건 main의 p이므로 "p가 가리키는 곳"인 *p에 값(a 또는 b)을 대입해야 함.
void set_pointer(char **p, char *a, char *b, int idx){
    if(!idx) *p=a;
    else *p=b;
}

// [헷갈린 점 2] 처음엔 malloc을 main에서 미리 하고, 이 함수는 strcpy만 했음.
// 문제 의도는 함수 안에서 malloc해서 그 주소를 호출한 쪽 포인터(*p)에 저장하는 것.
// [헷갈린 점 3 - 아직 안 고침] 크기가 입력 길이와 무관하게 105 고정. strlen(s)+1이 정확함.
void make_string(char **p, char *s) {
    *p = malloc(105*sizeof(char));
    strcpy(*p, s);
}

int main(){
    char s1[105], s2[105];
    char *a, *b, *p;
    int idx;

    scanf("%s %s", s1, s2);
    scanf("%d", &idx);

    make_string(&a, s1);
    make_string(&b, s2);

    // [헷갈린 점 4] 처음엔 set_pointer를 swap_ptr보다 먼저 호출해서 예제 출력이 달랐음.
    // 문제의 호출 순서: make_string -> swap_ptr -> set_pointer
    swap_ptr(&a, &b);

    set_pointer(&p, a, b, idx);

    printf("%s\n", p);
    printf("%s %s\n", a, b);

    free(a);
    free(b);

    return 0;
}
