#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n, cnt=0;cin>>n;
    vector<int> v(n+1), dp(n+1), xdp(n+2, 1e7);xdp[0]=0;
    for(int i=1;i<=n;i++) {
        cin>>v[i];
        int idx = lower_bound(xdp.begin(), xdp.begin()+i+1, v[i])-xdp.begin();
        xdp[idx] = min(xdp[idx], v[i]);
    }
    for(;xdp[cnt]!=1e7;cnt++);
    cout<<cnt-1;
    return 0;
}