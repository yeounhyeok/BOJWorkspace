#include <bits/stdc++.h>
using namespace std;
typedef long long ull;

unordered_map<ull, ull> a;
ull p, q, X, Y;

ull an(ull n){
    if(n<=0) return 1;
    if(a.find(n)!=a.end()) return a[n];
    ull x=floor(n/p)-X, y=floor(n/q)-Y;
    return a[n] = an(x) + an(y);
}

int main(){
    ull n;
    cin>>n>>p>>q>>X>>Y;
    a[0]=1;
    cout<<an(n);
    return 0;
}