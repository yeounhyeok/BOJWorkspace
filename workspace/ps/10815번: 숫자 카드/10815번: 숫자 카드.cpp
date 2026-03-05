#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> um;

int main(){
    ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, tmp;cin>>n;
    for(int i=0;i<n;i++){
        cin>>tmp;
        um.insert(pair<int ,int>(tmp, tmp));
    }

    int m;cin>>m;
    for(int i=0;i<m;i++){
        cin>>tmp;
        if(um.find(tmp)!=um.end()) cout<<1<<' ';
        else cout<<0<<' ';
    }

    return 0;
}