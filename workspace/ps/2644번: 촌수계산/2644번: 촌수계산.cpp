#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<bool>> &v, vector<int> &vst, int h, int cur){
    vst[h]=cur;
    for(int i=1;i<v.size();i++){
        int x=v[h][i];
        if(x==1&&!vst[i]){
            dfs(v, vst, i, cur+1);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m,a,b,x,y;
    cin>>n>>x>>y>>m;
    vector<vector<bool>> v(n+1, vector<bool>(n+1, 0));
    while(m--){
        cin>>a>>b;
        v[a][b]=1;
        v[b][a]=1;
    }
    vector<int> vst(n+1, 0);
    dfs(v, vst, x, 0);
    cout<<(vst[y]?vst[y]:-1);
    return 0;
}