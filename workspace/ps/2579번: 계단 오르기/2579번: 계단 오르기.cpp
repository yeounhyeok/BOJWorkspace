#include <bits/stdc++.h>
using namespace std;

int N, arr[305], dp[305];

int stairs(int n){
    dp[1] = arr[1];
    dp[2] = arr[1]+arr[2];
    for(int i=3;i<=n;i++) dp[i] = max(dp[i-2], dp[i-3]+arr[i-1]) + arr[i];
    return dp[n];
}

int main(){
    cin>>N;
    for(int i=1;i<=N;i++) cin>>arr[i];
    cout<<stairs(N)<<'\n';
    return 0;
}