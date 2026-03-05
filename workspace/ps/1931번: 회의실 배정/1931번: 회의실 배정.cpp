#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int a, b, n, tmp=0, cnt=0;cin>>n;
    vector<pair<int, int>> v;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        v.push_back(make_pair(b, a));
    }
    sort(v.begin(), v.end());
    for(int i=0;i<n;i++){
        if(v[i].second>=tmp) {
            cnt++;
            tmp = v[i].first;
        }
    }

    cout<<cnt<<'\n';
    return 0;
}