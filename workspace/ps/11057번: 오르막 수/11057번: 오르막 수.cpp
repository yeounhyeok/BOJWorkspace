#include <bits/stdc++.h>
#define MOD 10007
using namespace std;

int main(){
    int n;cin>>n;
    vector<vector<int>> dp(n+1, vector<int>(11));
    for(int i=0;i<10;i++)dp[1][i]=1;
    dp[1][10]=10;
    
    for(int i=2;i<=n;i++){
        int tmp = dp[i-1][10], s=tmp;
        dp[i][0] = tmp;
        for(int j=1;j<10;j++){
            tmp = (tmp+MOD - dp[i-1][j-1])%MOD;
            dp[i][j] = tmp;
            s = (s+tmp)%MOD;
        }
        dp[i][10] = s;
    }
    cout<<dp[n][10];
    return 0;
}