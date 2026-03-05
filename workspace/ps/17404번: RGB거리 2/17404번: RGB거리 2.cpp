#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, arr[3][1001], dp[3][1001], ans=1e7;
    cin>>n;
    for(int i=1;i<=n;i++)for(int j=0;j<3;j++) cin>>arr[j][i];

    for(int st=0;st<3;st++){
        for(int i=0;i<3;i++)dp[i][1] = 1e7;
        dp[st][1]=arr[st][1];
        for(int i=2;i<=n;i++){
            dp[0][i] = arr[0][i] + min(dp[1][i-1], dp[2][i-1]);
            dp[1][i] = arr[1][i] + min(dp[0][i-1], dp[2][i-1]);
            dp[2][i] = arr[2][i] + min(dp[0][i-1], dp[1][i-1]);
        }
        for(int x=0;x<3;x++){
            if(x!=st) ans = min(ans, dp[x][n]);
        }
    }
    cout<<ans;
    return 0;
}