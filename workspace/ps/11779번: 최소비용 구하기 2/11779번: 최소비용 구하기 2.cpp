#include <bits/stdc++.h>
using namespace std;

vector<int> d(1001, INT_MAX), ans(1001);

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
    int tmp = start->num;
    priority_queue<pair<node*, int>, vector<pair<node*, int>>, cmp> q;
    q.push(make_pair(start, 0));
    while(q.size()){
        node* cur = q.top().first;
        int curdist = q.top().second;q.pop();
        if(d[cur->num] < curdist) continue;
        for(auto i:cur->edges){
            int nextdist = curdist + i.second;
            node* nextnode = i.first;
            if(nextdist < d[nextnode->num]){
                d[nextnode->num] = nextdist;
                ans[nextnode->num] = cur->num;
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
    if(frm==to){
        cout<<0<<'\n'<<1<<'\n'<<frm;
        return 0;
    }

    d[frm]=0;
    dij(v[frm]);

    int cur = to;
    vector<int> last;

    while(cur) {
        last.push_back(cur);
        cur = ans[cur];
    }
    reverse(last.begin(), last.end());
    cout<<d[to]<<'\n'<<last.size()<<'\n';
    for(auto i:last) cout<<i<<' ';
    
    return 0;
}