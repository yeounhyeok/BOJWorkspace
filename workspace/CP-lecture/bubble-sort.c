#include<stdio.h>

int main(){
    int tmp, arr[]={16, 7, 9, 1, 3};

    for(int j=0;j<5;j++){
        for(int i=0;i<4-j;i++){
            if(arr[i]>arr[i+1]) {
                tmp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=tmp;
            }
        }
    }
    for(int i=0;i<5;i++) printf("%d ", arr[i]);
    return 0;
}