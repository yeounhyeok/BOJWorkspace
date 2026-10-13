#include <stdio.h>
#include <stdlib.h>

typedef struct circular_queue{
    int *arr;
    int front_idx, rear_idx, size, mx;
}circular_queue;

int enq(circular_queue *q, int x){
    if(q->size+1 == q->mx) return 0;
    q->size++;
    // [놓친 점] 처음엔 `arr[(++rear_idx) % mx]`처럼 증가만 하고 읽을 때만 % 했음.
    // 교재 방식은 인덱스를 옮길 때 바로 (idx+1) % M으로 감싸서 항상 0~M-1 유지.
    // (이동 후 저장: rear는 마지막으로 넣은 칸을 직접 가리킴)
    q->rear_idx = (q->rear_idx+1) % q->mx;
    q->arr[q->rear_idx]=x;
    return 1;
}

int deq(circular_queue *q){
    if(!q->size) return -1;
    q->size--;
    q->front_idx = (1+q->front_idx) % q->mx;
    return q->arr[q->front_idx];
}

int main(){
    int m, Q;
    scanf("%d %d", &m, &Q);
    circular_queue q = {malloc(m * sizeof(int)), 0, 0, 0, m};
    while(Q--){
        char in[10];
        scanf("%s", in);
        if(in[0]=='d') printf("%d\n", deq(&q));
        // [놓친 점 1] front: front_idx는 맨 앞 원소의 "바로 앞 칸"을 가리킴 -> 읽을 땐 +1.
        // [놓친 점 2] 빈 큐 처리가 없어서 쓰레기값이 나왔음. 문제 조건: 비었으면 -1 출력.
        else if(in[0]=='f') printf("%d\n", !q.size ? -1 : q.arr[(q.front_idx+1) % m]);
        // [놓친 점 3] back: 처음엔 front처럼 rear_idx+1로 읽어서 오답(예제에서 40 대신 10).
        // rear_idx는 마지막으로 넣은 칸을 직접 가리키므로 +1 없이 arr[rear_idx].
        // front의 공식을 rear에 그대로 복사한 실수.
        else if(in[0]=='b') printf("%d\n", !q.size ? -1 : q.arr[q.rear_idx]);
        else if(in[0]=='s') printf("%d\n", q.size);
        else if(in[1]=='m') printf("%d\n", !q.size ? 1:0);
        else {
            int x;
            scanf("%d", &x);
            printf("%d\n", enq(&q, x));
        }
    }
    // [아직 안 고침] free(q.arr)가 없음 (malloc한 m*sizeof(int) 바이트 누수). 끝나기 전에 해제할 것.
    return 0;
}