#include <bits/stdc++.h>
using namespace std;

int dp[1002][1002];

int main(){
    string a, b;
    cin>>a>>b;
    a.insert(0, " ");b.insert(0, " ");
    int n = a.size()-1, m=b.size()-1, mx=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i]==b[j]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(dp[i][j]>mx) mx= dp[i][j];
        }
    }
    cout<<mx;
    return 0;
}