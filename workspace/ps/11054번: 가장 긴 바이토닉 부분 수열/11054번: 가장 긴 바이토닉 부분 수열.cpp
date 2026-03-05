#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    vector<int> v(n+2), dp(n+2, 1), rdp, ans(n+1);
    rdp = dp;reverse(rdp.begin(), rdp.end());
    
    for(int i=1;i<=n;i++) cin>>v[i];

    for(int i=1;i<=n;i++) {
        for(int j=1;j<i;j++) {
            if(v[i]>v[j]) dp[i] = max(dp[i], dp[j]+1);
        }
    }
    reverse(v.begin(), v.end());
    for(int i=1;i<=n;i++) {
        for(int j=1;j<i;j++) {
            if(v[i]>v[j]) rdp[i] = max(rdp[i], rdp[j]+1);
        }
    }
    for(int i=1;i<=n;i++) {
        ans[i] = dp[i] + rdp[n-i+1] - 1;
    }
    cout<<*max_element(ans.begin(), ans.end());
    return 0;
}