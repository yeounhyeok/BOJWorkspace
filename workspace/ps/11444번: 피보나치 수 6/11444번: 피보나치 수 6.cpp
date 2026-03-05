#include<bits/stdc++.h>
#define MOD (int)(1e9+7)
using namespace std;
typedef unsigned long long ull;
typedef vector<vector<ull>> vvull;
vvull v={{1, 1}, {1, 0}};

vvull mat_multi(vvull A, vvull B){
    vvull res=v;
    res[0][0] = ((A[0][0]*B[0][0])%MOD+(A[0][1]*B[1][0])%MOD)%MOD;
    res[0][1] = ((A[0][0]*B[0][1])%MOD+(A[0][1]*B[1][1])%MOD)%MOD;
    res[1][1] = ((A[1][0]*B[0][1])%MOD+(A[1][1]*B[1][1])%MOD)%MOD;
    res[1][0] = ((A[1][0]*B[0][0])%MOD+(A[1][1]*B[1][0])%MOD)%MOD;
    return res;
}

vvull mat_fpow(vvull C, ull n){
    if(n==1) return C;
    vvull x = mat_fpow(C, n/2);
    if(n%2==0) return mat_multi(x, x);
    else return mat_multi(mat_multi(x, x), C);
}

int main(){
    ull n;cin>>n;
    cout<<mat_fpow(v, n)[0][1];
    return 0;
}

