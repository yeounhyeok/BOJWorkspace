#include<bits/stdc++.h>
using namespace std;
int n, m, s, e, v[2001];
bool dp[2001][2001];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)dp[i][i]=1;
    for(int i=1;i<=n;i++)cin>>v[i];

    int rep = n;
    for(int len=2;len<=n;len++){
        rep--;
        for(int i=1;i<=rep;i++){
            s = i;
            e = i+len-1;
            dp[s][e] = (v[s]==v[e] && (s+1<=e-1 ? dp[s+1][e-1]:1));
        }
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>s>>e;
        cout<<dp[s][e]<<'\n';
    }
    return 0;
}