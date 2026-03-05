#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tmp, n, mini = LONG_LONG_MAX;cin>>n;
    vector<ll> v, ans(2);
    for(int i=0;i<n;i++){
        cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    ll s=0, e=n-1;
    while(s<e){
        ll sum = v[s]+v[e], asum = abs(sum);

        if(asum<mini){
            mini = asum;
            ans[0] = v[s];
            ans[1] = v[e];
        }   

        if(sum==0) break;
        else if(sum<0) s++;
        else e--;
    }
    for(auto i:ans) cout<<i<<' ';
    return 0;
}