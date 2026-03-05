#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
bool cmp(P a, P b){
    return (a.second<b.second);
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n, mx=-1;cin>>n;
    vector<ll> idxv(n+1), anss;
    map<ll, ll> ans;
    vector<P> v(n+1), x(n+2, {1e9+1, 1e9+1}); x[0]={-(1e9+1), -(1e9+1)};
    for(ll i=1;i<=n;i++){
        cin>>v[i].first>>v[i].second;
        ans[v[i].first]=0;
    }
    sort(v.begin(), v.end());
    for(ll i=1;i<=n;i++){
        ll idx = lower_bound(x.begin(), x.begin()+i+1, v[i], cmp)-x.begin();
        if(x[idx].second > v[i].second){
            x[idx] = v[i];
            idxv[i]=idx;
            mx = max(mx, idx);
        }
    }
    cout<<n-mx<<'\n';
    for(ll i=n;mx>0;i--){
        if(idxv[i]==mx){
            ans.erase(v[i].first);
            mx--;
        }
    }
    for(auto x:ans)cout<<x.first<<'\n';
    return 0;
}