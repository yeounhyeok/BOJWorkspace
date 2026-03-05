#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> arr(1000005, 0);
vector<pair<ll ,ll>> tree(4000005, {1e10, 0});

void init(vector<ll> &a, vector<pair<ll ,ll>> &tree, int node, int start, int end) {
    if (start == end) {
        tree[node] = {a[start], a[start]};
    } else {
        init(a, tree, node*2, start, (start+end)/2);
        init(a, tree, node*2+1, (start+end)/2+1, end);
        tree[node].first = min(tree[node*2].first, tree[node*2+1].first);
        tree[node].second = max(tree[node*2].second, tree[node*2+1].second);
    }
}

pair<ll ,ll> query(vector<pair<ll ,ll>> &tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return make_pair(1e10, 0);
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    pair<ll ,ll> lsum = query(tree, node*2, start, (start+end)/2, left, right);
    pair<ll ,ll> rsum = query(tree, node*2+1, (start+end)/2+1, end, left, right);
    return make_pair(min(lsum.first, rsum.first), max(lsum.second, rsum.second));
}

int main(){
    ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
    ll n, m;cin>>n>>m;
    for(int i=0;i<n;i++) cin>>arr[i];
    init(arr, tree, 1, 0, n-1);
    for(int i=0;i<m;i++){
        ll b, c;cin>>b>>c;
        pair<ll, ll> p = query(tree, 1, 0, n-1, b-1, c-1);
        cout<<p.first<<' '<<p.second<<'\n';
    }
    return 0;
}