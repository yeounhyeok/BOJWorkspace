#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string a, b, lcs="";
    cin>>a>>b;
    a.insert(0, " ");b.insert(0, " ");
    int n = a.size()-1, m=b.size()-1, mx=0, mxi=1, mxj=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i]==b[j]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(dp[i][j]>mx) {
                mx= dp[i][j];
                mxi = i; mxj = j;
            }
        }
    }

    while(mxi>0 && mxj>0){
        if(dp[mxi][mxj]==dp[mxi][mxj-1]){
            mxj--;
        }
        else if(dp[mxi][mxj]==dp[mxi-1][mxj]){
            mxi--;
        }
        else{
            lcs+=a[mxi];
            mxi--;
            mxj--;
        }
    }
    reverse(lcs.begin(), lcs.end());
    cout<<mx;
    if(lcs.size()!=0) cout<<"\n"<<lcs;
    return 0;

}