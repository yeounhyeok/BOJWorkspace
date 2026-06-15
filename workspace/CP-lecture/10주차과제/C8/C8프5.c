#include<stdio.h>

int sieve[101];

void set_sieve(){
    for(int i=2;i<101;i++){
        for(int j=i+i;j<101;j+=i){
            sieve[j]=1;
        }
    }
}

int check_prime(int x){ return sieve[x]; }

int main(){
    set_sieve();
    for(int i=2;i<101;i++) {
        if(!check_prime(i)) printf("%d ", i);
    }
    return 0;
}