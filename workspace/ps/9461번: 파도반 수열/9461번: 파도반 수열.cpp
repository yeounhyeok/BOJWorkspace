#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

unsigned long long dp[10000];
int init[9] = {1, 1, 1, 2, 2, 3, 4, 5, 7};

int main(){
    cin.tie(NULL);ios_base::sync_with_stdio(false);
    for(int i=0;i<9;i++) dp[i+1]=init[i];
    unsigned long long n, k;

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>k;
        if(k<=9) cout<<dp[k]<<'\n';
        else{
            for(int j=10;j<=k;j++){
                dp[j]=dp[j-2]+dp[j-3];
            }
            cout<<dp[k]<<'\n';
        }
        
    }
    return 0;
}