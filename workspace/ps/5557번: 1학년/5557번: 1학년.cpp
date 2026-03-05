#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll arr[101], n, tmp, cur, dp[101][21];

bool chk(ll x) { return (x>=0&&x<=20); }

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>arr[i];
    dp[1][arr[1]]++;
    for(ll i=2;i<n;i++){
        for(ll j=0;j<=20;j++){
            cur = dp[i-1][j];
            if(cur){
                tmp=j+arr[i];
                if(chk(tmp)) dp[i][tmp]+=cur;
                tmp=j-arr[i];
                if(chk(tmp)) dp[i][tmp]+=cur;
            }
        }
    }    
    cout<<dp[n-1][arr[n]];
    return 0;
}