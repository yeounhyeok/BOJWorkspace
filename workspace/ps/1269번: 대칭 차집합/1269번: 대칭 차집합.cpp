#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    unordered_map<int, bool> m1, m2;

    int tmp, n, m, cnt=0;cin>>n>>m;
    for(int i=0;i<n;i++) {
        cin>>tmp;
        m1[tmp] = tmp;
    }
    for(int i=0;i<m;i++) {
        cin>>tmp;
        m2[tmp] = tmp;
    }
    for(auto iter : m1){
        if(m2.find(iter.first)==m2.end()) {
            cnt++;
        }
    }
    for(auto iter : m2){
        if(m1.find(iter.first)==m1.end()) {
            cnt++;
        }
    }
    cout<<cnt;
    
    return 0;
}