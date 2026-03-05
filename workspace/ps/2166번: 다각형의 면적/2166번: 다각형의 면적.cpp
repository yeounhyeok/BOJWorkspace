#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll N;
vector<pair<ll,ll>> v;
ll ccw(pair<ll,ll> a, pair<ll,ll> b, pair<ll,ll> c){
    return (ll)(a.first*b.second)+(b.first*c.second)+(a.second*c.first)-(b.first*a.second)-(c.first*b.second)-(a.first*c.second);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N;
    v.resize(N);
    for(int i=0;i<N;i++)cin>>v[i].first>>v[i].second;
    double ans = 0;
    for(int i=1; i<N-1; i++){
        ans += ccw(v[0], v[i], v[i+1]) /(double)2;
    }
    cout<<fixed;
    cout.precision(1);
    cout<<abs(ans);
    return 0;
}