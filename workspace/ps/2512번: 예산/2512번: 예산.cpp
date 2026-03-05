#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    ll n, h;cin>>n;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cin>>h;

    if(accumulate(v.begin(), v.end(), 0LL) <= h){
        cout<<*max_element(v.begin(), v.end());
        return 0;
    }

    ll s=0, e=1e9, sum ,m, ans=1e9;
    while(s<=e){
        sum=0;
        m = (s+e)/2;
        for(auto i:v) sum+=min(i, m);
        if(sum<=h) {
            s = m+1;
            ans=m;
        }
        else e = m-1; 
    }
    cout<<ans;
    return 0;
}