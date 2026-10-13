#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sum(int *a){
    int s=0;
    for(int i=0;i<10;i++) s+=a[i];
    return s;
}

int main(){
    int *x = malloc(10*sizeof(int));
    for(int i=0;i<10;i++) scanf("%d", x+i);
    printf("%d\n", sum(x));
    free(x);

    // [헷갈린 점] 20, 39 같은 임의 크기로 malloc하고, 입력이 길면 scanf 단계에서 넘칠 수 있음.
    // (문제에 길이 제한이 없으면 조건을 확인하거나 넉넉히 잡아야 함)
    char *a = malloc(20*sizeof(char));
    char *b = malloc(20*sizeof(char));

    scanf("%s", a);
    scanf("%s", b);

    // [헷갈린 점] 처음엔 c의 크기에 '\0' 자리(+1)를 빼먹었음. 문자열은 길이+1 필요.
    char *c = malloc((strlen(a) + strlen(b)+1)*sizeof(char));

    // [헷갈린 점 - 아직 안 고침] strcat(a, b)는 이어 붙이는 일을 a에서 함.
    // a는 20바이트라 a+b가 19자를 넘으면 넘침. strcpy(c, strcat(a,b))는 결과만 c로 복사.
    // 교수님 원문(concat(p, str1, str2))의 의도는 새 메모리 c에 직접 이어 붙이는 것:
    //   strcpy(c, a); strcat(c, b);
    strcpy(c, strcat(a, b));
    printf("%s", c);
    free(a);
    free(b);
    free(c);



    return 0;
}
