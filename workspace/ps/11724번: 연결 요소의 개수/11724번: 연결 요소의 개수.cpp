#include <bits/stdc++.h>
using namespace std;

int cnt;

struct node{
    int num;
    bool vst = false;
    vector<node*> edges;
    node(int n) : num(n) {};
};

void dfs(node* x){
    if(x->vst) return;
    x->vst = true;
    for(auto i:x->edges){
        if(!i->vst) dfs(i);
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n, m;cin>>n>>m;
    vector<node*> v(1);
    for(int i=1;i<=n;i++){
        node* tmp = new node(i);
        v.push_back(tmp);
    }
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        v[a]->edges.push_back(v[b]);
        v[b]->edges.push_back(v[a]);
    }

    for(int i=1;i<=n;i++) {
        if(!v[i]->vst){
            dfs(v[i]);
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}