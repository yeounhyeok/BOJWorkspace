#include <bits/stdc++.h>
using namespace std;

int dp[102][102][102];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    string a, b, c;
    cin>>a>>b>>c;
    a.insert(0, " ");b.insert(0, " ");c.insert(0, " ");
    int n = a.size()-1, m=b.size()-1, l=c.size()-1, mx=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=l;k++){
                if(a[i]==b[j]&&b[j]==c[k]) dp[i][j][k] = dp[i-1][j-1][k-1]+1;
                else dp[i][j][k] = max(dp[i-1][j][k], max(dp[i][j-1][k], dp[i][j][k-1]));
                if(dp[i][j][k]>mx) mx= dp[i][j][k];
            }
            
        }
    }
    cout<<mx;
    return 0;
}