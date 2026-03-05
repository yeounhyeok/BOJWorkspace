#include <bits/stdc++.h>
#define MOD 1000000000

using namespace std;
typedef unsigned long long ull;

int main(){
    int n;cin>>n;
    vector<ull> v(abs(n)+1);v[1]=1;

    if(n<0 && abs(n)%2==0) cout<<-1<<'\n';
    else if(n>0 || (abs(n)%2!=0 && n<0)) {
        cout<<1<<'\n';
    }
    else cout<<0<<'\n';

    for(int i=2;i<=abs(n);i++) v[i] = (v[i-1]%MOD + v[i-2]%MOD)%MOD;
    
    cout<<v[abs(n)]<<'\n';
    

    return 0;
}
