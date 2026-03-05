#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    ll n, tmp, cnt=1;cin>>n;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> q;
    priority_queue<int, vector<int>, greater<>> q2;
    for(ll i;i<n;i++){
        ll a,b;cin>>a>>b;
        q.push(make_pair(a, b));
    }

    q2.push(q.top().second);
    q.pop();
    while(!q.empty()){
        ll x = q.top().first, y = q.top().second;
        q.pop();
        if(x<q2.top()){
            cnt++;
            q2.push(y);
        }
        else{
            q2.pop();
            q2.push(y);
        }
    }
    cout<<cnt;
    return 0;
}