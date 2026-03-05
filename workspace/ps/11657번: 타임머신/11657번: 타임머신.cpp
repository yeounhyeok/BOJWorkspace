#include <bits/stdc++.h>
#define MX LONG_LONG_MAX/2
using namespace std;
typedef long long int ll;
typedef vector<unordered_map<ll, ll>> vumii;

ll n, m, a, b, c;
vumii v;
vector<ll> d;

bool bf(ll s){
    d[s]=0;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            for(auto e:v[j]){
                ll next = e.first, nextdist = e.second + d[j];
                if(d[next]>nextdist){
                    d[next] = nextdist;
                    if(i==n&&d[next]<=MX/2) return 1;
                }
            }
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    d = vector<ll>(n+1, MX);
    v = vumii(n+1);
    for(ll i=0;i<m;i++){
        cin>>a>>b>>c;
        v[a][b]=min(c, v[a].find(b)!=v[a].end() ? v[a][b]:c);
    }
    bool cycle = bf(1);
    if(cycle) cout<<-1;
    else{
        for(ll i=2;i<=n;i++) cout<<(d[i]>MX/2?-1:d[i])<<'\n';
    }
}