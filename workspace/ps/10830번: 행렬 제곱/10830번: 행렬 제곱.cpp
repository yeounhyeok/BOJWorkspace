#include<bits/stdc++.h>
#define MOD 1000
using namespace std;
typedef unsigned long long ull;
typedef vector<vector<ull>> vvull;

vvull v;
ull n, m;

vvull mat_multi(vvull A, vvull B){
    vvull res(n, vector<ull>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int x=0;x<n;x++){
                res[i][j] = (res[i][j] + (A[i][x] * B[x][j])%MOD)%MOD;
            }
        }
    }
    return res;
}

vvull mat_fpow(vvull C, ull n){
    if(n==1) return C;
    vvull x = mat_fpow(C, n/2);
    if(n%2==0) return mat_multi(x, x);
    else return mat_multi(mat_multi(x, x), C);
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    v = vvull(n, vector<ull>(n));
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>v[i][j];
    vvull ans = mat_fpow(v, m);
    for(auto y:ans){
        for(auto x:y) cout<<x%MOD<<' ';
        cout<<'\n';
    }
    return 0;
}