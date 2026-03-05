#include<bits/stdc++.h>
#define MX 32000
using namespace std;

int in[MX], n, m, a, b;
vector<vector<int>> v;
queue<int> q, ans;

void tsort(){
    for(int i=1;i<=n;i++) if(!in[i]) q.push(i);
    for(int i=0;i<n;i++){
        int x=q.front();
        q.pop();
        ans.push(x);
        for(int j=0;j<v[x].size();j++){
            int cur = v[x][j];
            if(--in[cur]==0) q.push(cur);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    v.resize(n+1);
    for(int i=0;i<m;i++){
        cin>>a>>b;
        v[a].push_back(b);
        in[b]++;
    }
    tsort();
    while(!ans.empty()){
        cout<<ans.front()<<' ';
        ans.pop();
    }
    return 0;
}