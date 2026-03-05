#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int n, a, dp[10002];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;
    for(int j=1;j<=n;j++){
        cin>>a;
        for(int i=4;i<=a;i++){
                dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        }
        cout<<dp[a]<<'\n';
    }
    return 0;
}


