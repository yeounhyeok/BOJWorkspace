#include <bits/stdc++.h>
#define rep(i, a, b) for(int i=a;i<b;i++)
using namespace std;

vector<vector<int>> v;
vector<bool> vst;
int n, m, x, y, ans;

void dfs(int cur, int depth){
    if(depth==4) {
        ans=1;
        return;
    }
    vst[cur]=1;
    for(auto e:v[cur]){
        if(!vst[e]) dfs(e, depth+1);
        if(ans)return;
    }
    vst[cur]=0;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    v = vector<vector<int>>(n);
    vst = vector<bool>(n);
    rep(i, 0, m){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    rep(i, 0, n) {
        dfs(i, 0);
        if(ans)break;
    }
    cout<<ans;
}