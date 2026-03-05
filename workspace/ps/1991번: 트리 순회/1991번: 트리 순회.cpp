#include <bits/stdc++.h>
using namespace std;

vector<char> ans[3];

void f1(vector<vector<int>> v, int cur){
    ans[0].push_back(cur+65); //md
    if(v[cur][0]>=0) f1(v, v[cur][0]); //lt
    if(v[cur][1]>=0) f1(v, v[cur][1]); //rt
}

void f2(vector<vector<int>> v, int cur){
    if(v[cur][0]>=0) f2(v, v[cur][0]); //lt
    ans[1].push_back(cur+65); //md
    if(v[cur][1]>=0) f2(v, v[cur][1]); //rt
}

void f3(vector<vector<int>> v, int cur){
    if(v[cur][0]>=0) f3(v, v[cur][0]); //lt
    if(v[cur][1]>=0) f3(v, v[cur][1]); //rt
    ans[2].push_back(cur+65); //md
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    vector<vector<int>> v(n);
    for(int i=0;i<n;i++){
        char a, b, c; cin>>a>>b>>c; 
        a-=65; b-=65; c-=65;
        v[a].push_back(b);
        v[a].push_back(c);
    }
    f1(v, 0); f2(v, 0); f3(v, 0);
    for(auto i:ans){
        for(auto j:i) cout<<j;
        cout<<'\n';
    }
    return 0;
}