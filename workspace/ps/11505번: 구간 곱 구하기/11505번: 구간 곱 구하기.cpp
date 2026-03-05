#include <bits/stdc++.h>
#define M 1000000007ULL
using namespace std;
typedef unsigned long long ll;

vector<ll> arr(1000005, 1), tree(4000005, 1);

void init(vector<ll> &a, vector<ll> &tree, int node, int start, int end) {
    if (start == end) {
        tree[node] = a[start];
    } else {
        init(a, tree, node*2, start, (start+end)/2);
        init(a, tree, node*2+1, (start+end)/2+1, end);
        tree[node] = (tree[node*2] * tree[node*2+1])%M;
    }
}

void update(vector<ll> &a, vector<ll> &tree, int node, int start, int end, int index, long long val) {
    if (index < start || index > end) {
        return;
    }
    if (start == end) {
        a[index] = val;
        tree[node] = val;
        return;
    }
    update(a, tree,node*2, start, (start+end)/2, index, val);
    update(a, tree,node*2+1, (start+end)/2+1, end, index, val);
    tree[node] = (tree[node*2] * tree[node*2+1])%M;
}

ll query(vector<ll> &tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return 1;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    ll lsum = query(tree, node*2, start, (start+end)/2, left, right);
    ll rsum = query(tree, node*2+1, (start+end)/2+1, end, left, right);
    return (lsum * rsum)%M;
}

int main(){
    ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
    ll n, m, k;cin>>n>>m>>k;
    for(int i=0;i<n;i++) cin>>arr[i];
    init(arr, tree, 1, 0, n-1);
    for(int i=0;i<m+k;i++){
        ll a, b, c;cin>>a>>b>>c;
        if(a==1) update(arr, tree, 1, 0, n-1, b-1, c);
        else if(a==2) cout<<query(tree, 1, 0, n-1, b-1, c-1)<<'\n';
    }
    return 0;
}