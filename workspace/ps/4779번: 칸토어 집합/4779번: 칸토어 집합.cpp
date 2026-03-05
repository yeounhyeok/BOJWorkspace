#include <bits/stdc++.h>
using namespace std;

void rec(vector<bool> &v, int n, int st){
    if(n==1)return;
    for(int i=st+n/3;i<=st+(n/3)*2-1;i++) v[i] = false;
    rec(v, n/3, st);
    rec(v, n/3, st+(n/3)*2);
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    while(cin>>n){
        int _3n = pow(3, n);
        vector<bool> v(_3n, true);
        rec(v, _3n, 0);
        for(int i=0;i<v.size();i++) cout<<((v[i]) ? '-':' ');
        cout<<'\n';
    }
    
    return 0;
}