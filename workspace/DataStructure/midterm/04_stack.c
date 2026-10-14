#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int val;
    struct node* next;
}node;

typedef struct stack{
    node* top;
    int size;
}stack;

void push(stack *st, int x){
    node *tmp = malloc(sizeof(node));
    tmp->val = x;
    tmp->next = st->top;

    st->top = tmp;
    st->size++;
}

int top(stack *st){ return st->size ? st->top->val : -1; }

int size(stack *st) { return st->size; }

void empty(stack *st){
    printf("%d\n", st->size ? 0 : 1);
}

int pop(stack *st){
    if(st->size==0) return -1;
    int ans = st->top->val;
    node *tmp = st->top;
    st->top = st->top->next;
    st->size--;
    free(tmp);
    return ans;
}

int main(){
    int n;
    stack st = {NULL, 0};
    scanf("%d", &n);
    getchar();

    for(int i=0;i<n;i++){
        char input[100];
        fgets(input, 100, stdin);

        if(input[0]=='t') printf("%d\n", top(&st));
        else if(input[0]=='s') printf("%d\n", size(&st));
        else if(input[0]=='e') empty(&st);
        else if(input[1]=='o') printf("%d\n", pop(&st));
        else {
            char x[12] = "\0\0\0\0\0\0\0\0\0\0\0\0";
            for(int j=5;input[j]!='\0';j++){
                x[j-5] = input[j];
            }
            push(&st, atoi(x));
        }
    }
    return 0;
}