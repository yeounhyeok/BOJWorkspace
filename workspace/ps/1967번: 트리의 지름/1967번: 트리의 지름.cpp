#include<bits/stdc++.h>
using namespace std;
typedef struct node{
    int num, vst[2]={0, 0}, dst[2]={0, 0};
    vector<pair<node*, int>> edges;
    node(int n):num(n){};
}node;

void dfs(node* x, int type){
    x->vst[type]=1;
    for(auto e:x->edges){
        if(!e.first->vst[type]){
            e.first->dst[type]=x->dst[type]+e.second;
            dfs(e.first, type);
        }
    }
}

bool cmp(node *a, node *b){ return (a->dst[0]>b->dst[0]); }
bool cmp1(node *a, node *b){ return (a->dst[1]>b->dst[1]); }

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int a, b, c, n;cin>>n;
    vector<node*> v(n+1),tmpv;
    for(int i=1;i<=n;i++) v[i]=new node(i);
    for(int i=1;i<n;i++){
        cin>>a>>b>>c;
        v[a]->edges.push_back(make_pair(v[b], c));
        v[b]->edges.push_back(make_pair(v[a], c));
    }
    dfs(v[1], 0);
    tmpv=v;
    sort(tmpv.begin()+1, tmpv.end(), cmp);
    dfs(tmpv[1], 1);
    sort(v.begin()+1, v.end(), cmp1);
    cout<<v[1]->dst[1];
    return 0;
}
