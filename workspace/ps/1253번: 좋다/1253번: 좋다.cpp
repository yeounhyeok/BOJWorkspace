#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    ll n, cnt=0;cin>>n;
    vector<ll> v(n);
    for(ll i=0;i<n;i++) cin>>v[i];
    sort(v.begin(), v.end());
    for(ll i=0;i<n;i++){
        ll s=0, e=n-1;
        if(s==i)s++;
        if(e==i)e--;
        while(s<e){
            if(v[s]+v[e]==v[i]) {
                cnt++;
                break;
            }
            else if(v[s]+v[e]>v[i]) {
                e--;
                if(e==i)e--;
            }
            else {
                s++;
                if(s==i)s++;
            }
        }
    }
    cout<<cnt;
    return 0;
}