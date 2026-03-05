#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> arr(100005, 1), tree(400005, 0);
ll n, k;

void init(vector<ll> &a, vector<ll> &tree, int node, int s, int e) {
    if (s == e) {
        tree[node] = a[s];
    } else {
        init(a, tree, node*2, s, (s+e)/2);
        init(a, tree, node*2+1, (s+e)/2+1, e);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}

ll updateQuery(vector<ll> &a, vector<ll> &tree, int node, int s, int e, int idx, ll val) {
    int res;
    if(s == e) {
        tree[node] = val;
        return s;
    }
    if(tree[node*2]>=idx) {
        res = updateQuery(a, tree, node*2, s, (s+e)/2, idx, val);
    }
    else {
        res = updateQuery(a, tree, node*2+1, (s+e)/2+1, e, idx-tree[node*2], val);
    }
    tree[node] = tree[node*2] + tree[node*2+1];
    return res;
}

int main(){
    ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
    cin>>n>>k;
    init(arr, tree, 1, 0, n-1);
    vector<ll> ans;
    int cur = 0;
    while(tree[1]) {
        cur+=k-1;
        cur%=tree[1];
        ans.push_back(updateQuery(arr, tree, 1, 0, n-1, cur+1, 0)+1);
    }
    cout<<"<";
    for(int i=0;i<n-1;i++) cout<<ans[i]<<", ";
    cout<<ans[n-1]<<">";
    return 0;
}