#include <stdio.h>

int get_array_sum(int *A, int size){
    int sum=0;
    for(int i=0;i<size;i++) sum+=A[i];
    return sum;
}

void print_array(int *A, int size){
    for(int i=0;i<size;i++) printf("%d ", A[i]);
    printf("\n");
    return;
}

int main(){
    int data[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    print_array(data, 10);
    printf("배열 요소의 합=%d\n", get_array_sum(data, 10));
    return 0;
}