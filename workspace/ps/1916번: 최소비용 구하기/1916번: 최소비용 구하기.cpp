#include <bits/stdc++.h>
using namespace std;

vector<int> d(1001, INT_MAX);

struct node{
    int num;
    vector<pair<node*, int>> edges;
    node(int _n) : num(_n) {};
};

struct cmp {
    bool operator()(pair<node*, int> a, pair<node*, int> b) {
        return a.second>b.second;
    }
};

vector<node*> v(1);

void dij(node* start){
    priority_queue<pair<node*, int>, vector<pair<node*, int>>, cmp> q;
    q.push(make_pair(start, 0));
    while(!q.empty()){
        node* cur = q.top().first;
        int curdist = q.top().second;q.pop();
        if(d[cur->num] < curdist) continue;
        for(auto i:cur->edges){
            int nextdist = curdist + i.second;
            node* nextnode = i.first;
            if(nextdist < d[nextnode->num]){
                d[nextnode->num] = nextdist;
                q.push(make_pair(v[nextnode->num], nextdist));
            }
        }
    }
}



int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, e, frm, to;cin>>n>>e;
    for(int i=1;i<=n;i++){
        node* tmp = new node(i);
        v.push_back(tmp);
    }

    int a, b, c;
    for(int i=0;i<e;i++){
        cin>>a>>b>>c;
        v[a]->edges.push_back(make_pair(v[b], c));
    }

    cin>>frm>>to;

    d[frm]=0;
    dij(v[frm]);
    cout<<d[to];
    return 0;
}