#include <bits/stdc++.h>
using namespace std;

int dp[3001][3001];
string a, b;

int main(){
    cin>>a;
    cin>>b;
    int c=a.length()/3, r=b.length()/3;
    a.insert(0, " ");b.insert(0, " ");
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            dp[i][j] = ((a.substr(j*3-2, 3)==b.substr(i*3-2, 3)) ? dp[i-1][j-1]+1 : max(dp[i-1][j], dp[i][j-1]));
        }
    }

    cout<<dp[r][c];
    
    return 0;
}