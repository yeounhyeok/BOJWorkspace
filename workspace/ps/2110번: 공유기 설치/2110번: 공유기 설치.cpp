#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    ll n, c;cin>>n>>c;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    sort(v.begin(), v.end());
    
    ll s=0, e=*(v.end()-1)-(*v.begin())+1, m;
    while(s+1<e){
        ll cnt=1, cur=0;
        m = (s+e)/2;
        for(int i=1;i<n;i++){
            if(v[i]-v[cur]>=m){
                cnt++;
                cur=i;
            }
        }
        if(cnt<c) e=m;
        else s=m;
    }
    
    cout<<(s?s:1);
    return 0;
}