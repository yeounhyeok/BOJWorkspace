#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

unordered_map<ull, ull> a;
ull p, q;

ull an(ull n){
    if(a.find(n)!=a.end()) return a[n];
    ull x=floor(n/p), y=floor(n/q);
    return a[n] = an(x) + an(y);
}

int main(){
    ull n;
    cin>>n>>p>>q;
    a[0]=1;a[1]=2;
    cout<<an(n);
    return 0;
}