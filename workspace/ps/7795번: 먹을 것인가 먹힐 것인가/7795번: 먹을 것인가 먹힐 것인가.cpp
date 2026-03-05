#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, t, tmp;cin>>t;
    for(int i=0;i<t;i++){
        vector<int> a, b;
        int cnt=0;
        cin>>n>>m;
        for(int ii=0;ii<n;ii++){
            cin>>tmp;
            a.push_back(tmp);
        }
        for(int ii=0;ii<m;ii++){
            cin>>tmp;
            b.push_back(tmp);
        }
        sort(b.begin(), b.end());
        for(auto ii:a){
            tmp=lower_bound(b.begin(), b.end(), ii)-b.begin();
            cnt+=tmp;
        }
        cout<<cnt<<'\n';
    }
    return 0;
}