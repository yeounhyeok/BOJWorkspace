#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct stack{
    int* arr;
    int top_idx;
}stack;

void top(stack *st){
    printf("%d\n", st->top_idx==-1 ? -1 : st->arr[st->top_idx]);
}

void size(stack *st){
    // [놓친 점] 처음엔 top()처럼 `top_idx==-1 ? -1 : ...`로 씀 -> 빈 스택에서 -1 출력(오답).
    // 빈 스택이면 top_idx+1 = 0이라 예외 처리가 필요 없음. top의 -1 처리를 그대로 복붙한 실수.
    printf("%d\n", st->top_idx+1);
}

void empty(stack *st){
    printf("%d\n", st->top_idx==-1 ? 1:0);
}

void pop(stack *st){
    // [놓친 점] 처음엔 빈 스택 확인이 없어서 arr[-1]을 읽고 top_idx가 -2로 내려감
    // (heap-buffer-overflow, 이후 size/empty/push도 전부 어긋남). 문제 조건: 비었으면 -1 출력.
    printf("%d\n", st->top_idx==-1 ? -1 : st->arr[st->top_idx--]);  //endcase 확인!!! null 참조 안하도록
}

void push(stack *st, int x){
    st->arr[++st->top_idx] = x;
}

int main(){
    int n;
    scanf("%d", &n);
    stack st = {malloc(n * sizeof(int)), -1};
    while(n--){
        char in[6];
        scanf("%s", in);
        if(in[0]=='t') top(&st);
        else if(in[0]=='s') size(&st);
        else if(in[0]=='e') empty(&st);
        else if(in[1]=='o') pop(&st);
        else{
            int x;
            scanf("%d", &x);
            push(&st, x);
        }
    }
    free(st.arr);
    return 0;
}