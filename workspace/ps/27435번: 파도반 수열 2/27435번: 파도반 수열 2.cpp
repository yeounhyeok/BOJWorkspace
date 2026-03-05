#include<bits/stdc++.h>
#define MOD 998244353ULL
using namespace std;
typedef unsigned long long ull;
typedef vector<vector<ull>> vvull;

ull t, N;
vvull q = {{0, 1, 0},
           {0, 0, 1},
           {1, 1, 0}};

vvull mat_multi(vvull A, vvull B){
    vvull res(3, vector<ull>(3));
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int x=0;x<3;x++){
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
    cin>>t;
    while(t--){
        cin>>N;
        cout<<((mat_fpow(q, N+3))[0][2])%MOD<<'\n';
    }
    return 0;
}