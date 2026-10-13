#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student{
    char name[10];
    int h;
    double w;
}student;

void swap(student *a, student *b){
    student c=*a;
    *a = *b;
    *b = c;
}

void selection_sort(student *s, int n){
    for(int i=0;i<n-1;i++){
        int idx = i;
        // [참고] j=i+1부터 시작해도 결과는 같음 (j=i는 자기 자신과 비교하는 한 번이 낭비)
        for(int j=i;j<n;j++){
            // [헷갈린 점 - 본인 지적] strcmp 부호를 반대로 봐서 한 번 틀림.
            // strcmp(a, b): a가 사전식으로 앞이면 음수, 같으면 0, 뒤면 양수.
            // 정확한 값(-1 등)은 보장이 없으니 == -1이 아니라 < 0, > 0으로 비교할 것.
            // 여기선 "idx 쪽이 더 뒤면(> 0) j로 교체"해서 오름차순이 됨.
            if(strcmp(s[idx].name, s[j].name) > 0) idx = j;
        }
        swap(s+idx, s+i);
    }
}

int main(){
    int n;
    scanf("%d", &n);

    student *s = malloc(n*sizeof(student));
    // [지적받은 점] 처음엔 malloc 실패 확인을 빼먹음. 문제 구현 조건에 "할당 실패 확인"이 있음.
    if (s == NULL) return 1;

    for(int i=0;i<n;i++) scanf("%s %d %lf", (s+i)->name, &((s+i)->h), &((s+i)->w));
    selection_sort(s, n);
    // [헷갈린 점 - 본인 지적] 처음엔 %lf로만 출력해서 72.500000처럼 나옴.
    // 문제 조건 "몸무게는 소수 첫째 자리까지"를 못 보고 놓침 -> %.1lf로 수정.
    for(int i=0;i<n;i++) printf("%s %d %.1lf\n", (s+i)->name, (s+i)->h, (s+i)->w);

    // [지적받은 점] 처음엔 free(s)가 없었음 (출력은 맞아도 96바이트 누수, "사용 후 해제" 조건 위반).
    free(s); //중요!! 까먹지말기
    return 0;
}