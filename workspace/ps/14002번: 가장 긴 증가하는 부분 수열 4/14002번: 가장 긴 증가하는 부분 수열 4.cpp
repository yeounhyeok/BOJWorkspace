#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    vector<int> v(n+1), dp(n+1, 1);dp[0]=0;
    vector<vector<int>> trace(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];

    for(int i=1;i<=n;i++) {
        for(int j=1;j<i;j++) {
            if(v[i]>v[j] && dp[i]<dp[j]+1) {
                dp[i] =dp[j]+1;
                trace[i] = trace[j];
                trace[i].push_back(v[j]);
            }
        }
    }
    int idx = max_element(dp.begin(), dp.end())-dp.begin();
    cout<<*(dp.begin()+idx)<<'\n';
    for(auto x:trace[idx]) cout<<x<<' ';
    cout<<v[idx];
    return 0;
}