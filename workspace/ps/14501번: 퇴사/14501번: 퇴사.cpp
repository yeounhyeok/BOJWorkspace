#include <bits/stdc++.h>
using namespace std;

int n, dp[16], t[16], p[16], l[16], tmp;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>t[i]>>p[i];
    for(int i=1;i<=n;i++){
        if(t[i]>1){
            tmp=0;
            l[i]=1;
        }
        else tmp=p[i];

        for(int x=1;x<=n;x++){
            if(l[x] && x + (t[x]-1) <= i){
                dp[i] = max(dp[x-1]+p[x], max(dp[i-1]+tmp, dp[i]));
            }
        }
        dp[i] = max(dp[i], dp[i-1]+tmp);
    }
    cout<<dp[n];
    return 0;
}