#include<bits/stdc++.h>
using namespace std;

int n, r, q, a, b;

struct node{
    int num, cnt=0;
    vector<node*> edges;
    node(int _n) : num(_n) {}
};
vector<node*> v;

void dfs(node* x, node* from){
    for(auto e:x->edges) {
        if(e!=from) dfs(e, x);
    }
    from->cnt += x->cnt+1;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>r>>q;
    for(int i=0;i<=n;i++) v.push_back(new node(i));
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        v[a]->edges.push_back(v[b]);
        v[b]->edges.push_back(v[a]);
    }
    dfs(v[r], v[0]);
    for(int i=0;i<q;i++){
        cin>>a;
        cout<<v[a]->cnt+1<<'\n';
    }

    return 0;
}