#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp(505, vector<int>(505, INT_MAX));
pair<int, int> dpmat[505][505];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int a, b, c, n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        dpmat[1][i]={a, b};
        dp[1][i]=0;
    }
    int r = n;
    for(int i=2;i<=n;i++){
        r--;
        for(int j=1;j<=r;j++){
            pair<int, int> lt={i-1, j}, rt={1, j+i-1};
            while(lt.first>0){
                a = dpmat[lt.first][lt.second].first;
                b = dpmat[lt.first][lt.second].second;
                c = dpmat[rt.first][rt.second].second;
                if(dp[i][j] > a*b*c + dp[lt.first][lt.second] + dp[rt.first][rt.second]){
                    dp[i][j] = a*b*c + dp[lt.first][lt.second] + dp[rt.first][rt.second];
                    dpmat[i][j] = {a, c};
                }
                lt.first--;
                rt.first++;
                rt.second--;
            }
        }
    }
    cout<<dp[n][1];
    return 0;
}