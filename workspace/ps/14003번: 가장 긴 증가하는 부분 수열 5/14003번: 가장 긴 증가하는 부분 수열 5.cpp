#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    ll n, cnt=0, mx=-1;cin>>n;
    vector<ll> v(n+1), xdp(n+2, 1e9+1), idxv(n+1), ans; xdp[0]=-(1e9+1);
    
    for(ll i=1;i<=n;i++) {
        cin>>v[i];
        ll idx = lower_bound(xdp.begin(), xdp.begin()+i+1, v[i])-xdp.begin();
        if(xdp[idx] > v[i]){
            xdp[idx] = v[i];
            idxv[i]=idx;
            mx = max(mx, idx);
        }
    }
    cout<<mx<<'\n';
    for(ll i=n;mx>0;i--){
        if(idxv[i]==mx){
            ans.push_back(v[i]);
            mx--;
        }
    }
    reverse(ans.begin(), ans.end());
    for(auto x:ans)cout<<x<<' ';
    return 0;
}