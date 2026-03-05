#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    vector<int> ans;
    int n, m, a[102], b[102], ai=1, bi=1, mx;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    cin>>m;
    for(int i=1;i<=m;i++) cin>>b[i];
    
    mx = *max_element(a+1, a+1+n);
    while(1){
        int x=-1, xi, yi=bi;
        for(int i=ai;i<=n;i++){
            if(x<a[i] && mx>=a[i]) {
                x = a[i];
                xi = i;
            }
        }
        for(;yi<=m+1;yi++){
            if(x==b[yi]) {
                break;
            }
        }
        if(x==-1) break;
        if(yi<=m){
            ans.push_back(x);
            mx = x;
            bi = yi+1;
            ai = xi+1;
        }
        else{
            mx--;
        }
    }
    cout<<ans.size()<<'\n';
    if(!ans.empty()) for(auto i:ans) cout<<i<<' ';
    return 0;
}