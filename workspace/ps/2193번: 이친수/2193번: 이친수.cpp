#include <stdio.h>
 
unsigned long long dp[100000] = {0,};    
 
unsigned long long fibo(int n) {
    dp[0] = 0;
    dp[1] = 1;
    int i;
    for (i=2; i<=n; i++) {    
            dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
 
int main(){
    int k;
    scanf("%d", &k);
    printf("%llu", fibo(k));
    return 0;
}
