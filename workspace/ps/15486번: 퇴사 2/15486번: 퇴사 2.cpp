#include <bits/stdc++.h>
#define MX 1500052
using namespace std;

int n, dp[MX], t[MX], p[MX], tmp;
vector<int> l[MX];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>t[i]>>p[i];
    for(int i=1;i<=n;i++){
        if(t[i]>1){
            tmp=0;
            l[i+t[i]-1].push_back(i);
        }
        else tmp=p[i];

        for(auto x:l[i]){
            if(x) dp[i] = max(dp[x-1]+p[x], max(dp[i-1]+tmp, dp[i]));
        }
        dp[i] = max(dp[i], dp[i-1]+tmp);
    }
    cout<<dp[n];
    return 0;
}