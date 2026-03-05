#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;

int main(){
    int n, tmp[2], result=0;cin>>n;
    for(int i=0;i<n;i++){
        cin>>tmp[0]>>tmp[1];
        v.push_back(make_pair(tmp[0], tmp[1]));
    }
    sort(v.begin(), v.end());
    for(int i=0;i<n;i++){
        if(v[i].first>result) result = v[i].first + v[i].second;
        else result+=v[i].second;
    }
    cout<<result<<endl;
    return 0;
}