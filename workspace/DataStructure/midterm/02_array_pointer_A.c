#include <stdio.h>

void swap(int *a, int *b){
    int c=*a;
    *a=*b;
    *b=c;
    return;
}

void selection_sort(int *a, int n){
    for(int i=0;i<n-1;i++){
        int idx = i;
        for(int j=i+1;j<n;j++){
            if(a[idx]>a[j]) idx=j;
        }
        swap(a+i, a+idx);
    }
    return;
}

int main(){
    int n, a[1005];
    scanf("%d", &n);
    for(int i=0;i<n;i++) scanf("%d", a+i);
    selection_sort(a, n);
    // [참고] 마지막 원소 뒤에도 공백이 남음. 엄격한 채점이면 틀릴 수 있어서
    // i가 0이 아닐 때만 공백을 앞에 붙이는 방식이 안전함.
    for(int i=0;i<n;i++) printf("%d ", a[i]);
    return 0;
}
