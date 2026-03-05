#include<bits/stdc++.h>
using namespace std;

vector<int> d;
vector<vector<pair<int, int>>> v;
int n, m;

void dij(){
    priority_queue<pair<int, int>> q;
    q.push({0, 1});
    d[1]=0;
    while(!q.empty()){
        int cur = q.top().second, curdist = -q.top().first;
        q.pop();
        if(curdist>d[cur]) continue;
        for(auto e:v[cur]){
            int next = e.second, nextdist = e.first+d[cur];
            if(d[next]>nextdist){
                d[next] = nextdist;
                q.push({-e.first, e.second});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    v.resize(n+1); d.resize(n+1, 1e8);
    for(int i=0;i<m;i++){
        int a, b, c;
        cin>>a>>b>>c;
        v[a].push_back({c, b});
        v[b].push_back({c, a});
    }
    dij();
    cout<<d[n];
    return 0;
}