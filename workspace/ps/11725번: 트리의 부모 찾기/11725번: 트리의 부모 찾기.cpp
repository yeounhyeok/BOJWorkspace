#include <bits/stdc++.h>
using namespace std;

struct node{
    int num;
    vector<node*> edges;
    node* prt=nullptr;
    bool visited=false;
    node(int _n) : num(_n) {} ;
};

void dfs(node* cur, node* from){
    cur->prt=from;
    cur->visited=true;
    for(int i=0;i<cur->edges.size();i++){
        if(!cur->edges[i]->visited) dfs(cur->edges[i], cur);
    }
}

vector<node*> v(1);

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        node* tmp = new node(i);
        v.push_back(tmp);
    }
    for(int i=0;i<n-1;i++){
        int a, b;cin>>a>>b;
        v[a]->edges.push_back(v[b]);
        v[b]->edges.push_back(v[a]);
    }
    dfs(v[1], nullptr);
    for(int i=2;i<=n;i++) cout<<v[i]->prt->num<<'\n';
    
    return 0;
}