#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;cin>>n>>m;
    vector<int> dp(m+1), arr(n+1);
    dp[0]=1;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(j>=arr[i]) dp[j]+=dp[j-arr[i]];
        }
    } 

    cout<<dp[m];

    return 0;
}