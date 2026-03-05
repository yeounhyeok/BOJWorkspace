#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    ll n, b;
    cin>>n>>b;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    ll s=0, e=1e9, m;
    while(s+1<e){
        bool flag=true;
        ll idx = 0;
        vector<ll> blueray(b);
        m = (s+e)/2;
        for(auto i:v) {
            there:
            if(blueray[idx]+i>m) {
                idx++;
                if(idx==b) {
                    s = m;
                    flag = false;
                    break;
                }
                goto there;
            }

            blueray[idx]+=i;
        }
        if(flag) e = m;
    }
    cout<<e;
    return 0;
}