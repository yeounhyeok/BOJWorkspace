#include<stdio.h>

int main(){
    int a, b, c;
    for(int i=1;i<100;i++){
        a=i*i;
        for(int j=1;j<100;j++){
            b=j*j;
            for(int k=1;k<100;k++){
                c=k*k;
                if(a+b==c || a+c==b || b+c==a){
                    printf("%d %d %d\n", i, j, k);
                }
            }
        }
    }
    return 0;   
}