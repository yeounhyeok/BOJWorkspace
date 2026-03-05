#include <bits/stdc++.h>
using namespace std;
int n, t, a, b;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>t;
    for(int j=0;j<t;j++){
        cin>>n;
        vector<vector<int>> v(n+2, vector<int>(2));
        vector<pair<int, int>> dp(n+2);
        for(int i=0;i<n;i++) cin>>v[i][0];
        for(int i=0;i<n;i++) cin>>v[i][1];

        a = v[0][0]; b = v[0][1];
        dp[0] = make_pair(a, b);
        a = v[0][0]+v[1][1]; b = v[0][1]+v[1][0];
        dp[1] = make_pair(b, a);

        for(int i=2;i<n;i++){
            dp[i].first = max(dp[i-1].second, dp[i-2].second) + v[i][0];
            dp[i].second = max(dp[i-1].first, dp[i-2].first) + v[i][1];
            
        }
        cout<<max(dp[n-1].first, dp[n-1].second)<<'\n';
    }
    
    return 0;
}