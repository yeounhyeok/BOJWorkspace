#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll p[1001], n, m, a, b, c, ans;
vector<tuple<ll, ll ,ll>> v;

ll f(ll x){
    if(x==p[x]) return x;
    return p[x] = f(p[x]);
}
void u(ll x, ll y){
    x=f(x);y=f(y);
    p[x<y?x:y] = x<y?y:x;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++) p[i]=i;
    for(ll i=0;i<m;i++){
        cin>>a>>b>>c;
        v.push_back({c, a, b});
    }
    sort(v.begin(), v.end());
    
    for(ll i=0;i<m;i++){
        if(f(get<1>(v[i])) != f(get<2>(v[i]))){
            u(get<1>(v[i]), get<2>(v[i]));
            ans+=get<0>(v[i]);
        }
    }
    cout<<ans;
    return 0;
}