#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000000
typedef unsigned long long ull;

ull dt[105][15];

void dp(int n){
    for(int i=1;i<=9;i++) dt[1][i]=1;
    for(int i=2;i<=n;i++) {
        dt[i][0] = dt[i-1][1];
        dt[i][9] = dt[i-1][8];
        for(int j=1;j<9;j++) dt[i][j] = (dt[i-1][j-1]%MOD + dt[i-1][j+1]%MOD)%MOD;
    }
}

int main(){
    int N;cin>>N;
    dp(N);
    cout<<(accumulate(dt[N], dt[N]+10, 0LL))%MOD<<'\n';
    return 0;
}
