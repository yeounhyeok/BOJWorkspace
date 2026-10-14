#include<stdio.h>
#include<stdlib.h>
#include <string.h>


// [놓친 점 1] 처음엔 arr를 char *로 둠 -> 계산 결과가 char 범위(-128~127)를 넘으면 잘림
// (9*9*9 = 729 같은 값에서 오답). 변환(연산자 문자)과 계산(숫자)을 한 스택으로 쓰려면 int.
typedef struct stack{
    int *arr;
    int size, idx;
}stack;

void push(stack * st, int x){
    st->arr[++st->idx] = x;
    st->size++;
}

int pop(stack* st){
    st->size--;
    return st->arr[st->idx--];
}

int top(stack *st){
    return st->arr[st->idx];
}

int prior(char c){
    if(c=='(' || c==')') return 0;
    else if(c=='+' || c=='-') return 1;
    else return 2;
}

int main(){
    // [놓친 점 2] 처음엔 p_idx를 char로 둠. 인덱스는 int로 (127 넘으면 오버플로, 01-C와 같은 습관).
    char in[101], post[101];
    int p_idx=0;
    scanf("%s", in);
    stack st = {malloc(100*sizeof(int)), 0, -1};
    for(int i=0;in[i]!='\0';i++){ // 변환
        if(in[i]=='(') push(&st, '(');
        else if(in[i]==')'){
            // [놓친 점 3] 처음엔 여기 맨 앞에 pop(&st)가 하나 더 있었음 -> 스택 top의 연산자를
            // 출력하지 않고 버려서 (2+3)*4+9가 234*9+로 나옴(+ 소실).
            // ')'는 '('가 나올 때까지 pop해서 "출력"하고, 마지막에 '('만 버린다. 이유는 )를 push한적이 없는데 푸시햇다고 착각하여 pop 했었음
            while(st.size>0&&top(&st)!='(') post[p_idx++] = pop(&st);
            pop(&st);
        }
        else if(in[i]>='0' && in[i]<='9') post[p_idx++] = in[i];
        else {
            // 연산자: 스택 top의 우선순위가 같거나 높으면(>=) 먼저 pop해서 출력 (8-3-2 -> 83-2-).
            // st.size>0 확인이 앞에 있어야 빈 스택에서 top이 arr[-1]을 읽지 않음.
            while(st.size>0 && prior(top(&st))>=prior(in[i])) post[p_idx++] = pop(&st);
            push(&st, in[i]);
        }
    }
    while(st.size>0) post[p_idx++] = pop(&st);
    post[p_idx] = '\0';

    for(int i=0;post[i]!='\0';i++) printf("%c", post[i]); //변환결과 출력

    int a, b;
    for(int i=0;post[i]!='\0';i++){
        // [놓친 점 4] 처음엔 `>='0' || <='9'`로 씀 -> 모든 문자가 참이라 연산자도 숫자로 push됨.
        // 범위 검사는 && (변환 쪽에선 맞게 썼는데 옮기며 틀림).
        if(post[i]>='0' && post[i]<='9') push(&st, post[i]-'0');
        else if(post[i]=='+'){
            b = pop(&st);
            a = pop(&st);
            push(&st, a+b);
        }
        else if(post[i]=='-'){
            // 후위 계산: 먼저 pop한 것이 오른쪽 피연산자(b), 나중에 pop한 것이 왼쪽(a) -> a-b, a/b
            b = pop(&st);
            a = pop(&st);
            push(&st, a-b);
        }
        else if(post[i]=='*'){
            b = pop(&st);
            a = pop(&st);
            push(&st, a*b);
        }
        else if(post[i]=='/'){
            b = pop(&st);
            a = pop(&st);
            push(&st, a/b);
        }
    }
    printf("\n%d\n", pop(&st));

    free(st.arr);
    
    return 0;
}