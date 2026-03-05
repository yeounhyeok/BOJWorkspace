#include <bits/stdc++.h>
using namespace std;

int ans;

void dfs(vector<vector<bool>> &v, vector<bool> &vst, int nation){
    vst[nation]=1;
    for(int i=1;i<v.size();i++){
        int x=v[nation][i];
        if(x==1&&!vst[i]){
            ans++;
            dfs(v, vst, i);
        }
    }
}

int main(){
    int t,n,m,a,b;
    cin>>t;
    while(t--){
        ans=0;
        cin>>n>>m;
        vector<vector<bool>> v(n+1, vector<bool>(n+1, 0));
        while(m--){
            cin>>a>>b;
            v[a][b]=1;
            v[b][a]=1;
        }
        vector<bool> vst(n+1, 0);
        dfs(v, vst, 1);
        cout<<ans<<'\n';
    }
    return 0;
}



