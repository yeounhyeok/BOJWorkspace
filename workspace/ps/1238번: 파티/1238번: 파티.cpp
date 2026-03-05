#include <bits/stdc++.h>
using namespace std;

struct cmp{
    bool operator()(pair<int, int> a, pair<int, int> b){ return a.second>b.second; }
};

vector<int> dij(vector<vector<pair<int, int>>>& v, int frm){
    vector<int> d(1001, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
    d[frm] = 0;
    q.push(make_pair(frm, 0));
    while(!q.empty()){
        int cur = q.top().first, dist = q.top().second;
        q.pop();
        if(d[cur]<dist) continue;
        for(auto edge:v[cur]){
            int next = edge.first, nextdist = edge.second + d[cur];
            if(nextdist < d[next]){
                d[next] = nextdist;
                q.push(edge);
            }
        }
    }
    return d;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n, m, x, a, b, c;cin>>n>>m>>x;
    vector<vector<pair<int, int>>> v1(1001), v2(1001);
    vector<int> ans(1), d1, d2;
    for(int i=0;i<m;i++) {
        cin>>a>>b>>c;
        v1[a].push_back(make_pair(b, c));
        v2[b].push_back(make_pair(a, c));
    }
    d1 = dij(v1, x); d2 = dij(v2, x);
    for(int i=1;i<=n;i++) ans.push_back(d1[i] + d2[i]);
    cout<<*max_element(ans.begin(), ans.end());

    return 0;
}