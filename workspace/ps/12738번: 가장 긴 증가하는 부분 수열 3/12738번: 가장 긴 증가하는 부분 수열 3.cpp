#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    ll n, cnt=0;cin>>n;
    vector<ll> v(n+1), xdp(n+2, 1e9+1);xdp[0]=-(1e9+1);
    for(ll i=1;i<=n;i++) {
        cin>>v[i];
        ll idx = lower_bound(xdp.begin(), xdp.begin()+i+1, v[i])-xdp.begin();
        xdp[idx] = min(xdp[idx], v[i]);
    }
    for(;xdp[cnt]!=1e9+1;cnt++);
    cout<<cnt-1;
    return 0;
}