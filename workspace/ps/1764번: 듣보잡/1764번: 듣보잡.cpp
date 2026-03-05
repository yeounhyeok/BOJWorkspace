#include <bits/stdc++.h>
using namespace std;

map<string, string> mp;
vector<string> v;
int cnt, n, m;string tmp;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>tmp;
        mp[tmp] = tmp;
    }
    for(int i=0;i<m;i++){
        cin>>tmp;
        if(mp.find(tmp) != mp.end()){
            cnt++;
            v.push_back(tmp);
        }
    }

    sort(v.begin(), v.end());
    cout<<v.size()<<'\n';
    for(int i=0;i<v.size();i++) cout<<v[i]<<'\n';
    return 0;
}

