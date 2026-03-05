#include<bits/stdc++.h>
using namespace std;

struct node{
    int num;
    unordered_map<int, node*> edges;
    node(int _n):num(_n){};
};
int n, tmp, cnt;
vector<node*> v;
node* rt;

void dfsEraser(node* cur, int x){
    if(cur->edges.find(x)!=cur->edges.end()) {
        cur->edges.erase(x);
        return;
    }
    for(auto i:cur->edges){
        dfsEraser(i.second, x);
    }
}

void dfsCounter(node* cur){
    if(cur->edges.size()==0) {
        cnt++;
        return;
    }
    for(auto i:cur->edges){
        dfsCounter(i.second);
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    v = vector<node*>(n);
    for(int i=0;i<n;i++) v[i] = new node(i);
    for(int i=0;i<n;i++){
        cin>>tmp;
        if(tmp==-1) rt = v[i];
        else v[tmp]->edges[i]=v[i];
    }
    cin>>tmp;
    if(rt->num==tmp) {
        cout<<0;
        return 0;
    }
    dfsEraser(rt, tmp);
    dfsCounter(rt);
    cout<<cnt;
    return 0;
}