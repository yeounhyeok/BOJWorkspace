#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, t, tmp;cin>>t;
    for(int j=1;j<=t;j++){
        int mx=-1;
        cin>>n;
        vector<int> v;
        for(int i=0;i<n;i++){
            cin>>tmp;
            v.push_back(tmp);
        }
        sort(v.begin(), v.end());
        cout<<"Class "<<j<<'\n';
        cout<<"Max "<<v[v.size()-1];
        cout<<", Min "<<v[0];
        for(int ii=1;ii<v.size();ii++){
            mx = max(mx, v[ii]-v[ii-1]);
        }
        cout<<", Largest gap "<<mx<<'\n';
    }
    return 0;   
}