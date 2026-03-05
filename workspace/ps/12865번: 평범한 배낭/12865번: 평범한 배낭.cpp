#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n, k; cin>>n>>k;
    vector<vector<int>> arr(n+1, vector<int>(2)), dp(k+1, vector<int>(n+1)); //(W, V)
    for(int i=1;i<=n;i++) cin>>arr[i][0]>>arr[i][1];
    for(int i=1;i<=k;i++) {
        for(int j=1;j<=n;j++){
            dp[i][j]= max(dp[i][j-1], ((i>=arr[j][0]) ? (dp[(i-arr[j][0])][j-1]) + arr[j][1] : (dp[i][j-1])) );  
        }
    }
    cout<<dp[k][n]<<'\n';
    return 0;
}