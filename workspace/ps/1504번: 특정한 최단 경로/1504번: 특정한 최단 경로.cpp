#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef vector<vector<pii>> vvpii;

vvpii v;
int n, e, x, y;

vector<int> dij(int start){
    vector<int> d(n+1, 1e8);
    priority_queue<pii, vector<pii>, less<>> q;
    q.push(make_pair(0, start)); d[start]=0;
    while(!q.empty()){
        int cur=q.top().second, curdist=q.top().first; q.pop();
        if(curdist>d[cur]) continue;
        for(auto e:v[cur]){
            int next = e.second, nextdist=e.first + curdist;
            if(nextdist<d[next]){
                d[next]=nextdist;
                q.push(make_pair(nextdist, next));
            }
        }
    }
    return d;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>e;
    v=vvpii(n+1);
    while(e--){
        int a, b, c;cin>>a>>b>>c;
        v[a].push_back(make_pair(c, b));
        v[b].push_back(make_pair(c, a));
    }
    cin>>x>>y;
    vector<int> v1=dij(1), vx=dij(x), vy=dij(y);
    int ans1 = v1[x] + vx[y] + vy[n];
    int ans2 = v1[y] + vy[x] + vx[n];
    int ans = min(ans1, ans2);
    cout<<(ans>1e7*8 ? -1:ans);
    return 0;
}