#include<stdio.h>

int main(){
    int n=100;
    for(int i=0;i<n;i+=2){
        for(int j=n-3;j>=i;j-=2){
            printf(" ");
        }
        for(int j=0;j<=i;j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}