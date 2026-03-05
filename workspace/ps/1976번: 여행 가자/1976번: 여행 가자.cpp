#include <bits/stdc++.h>
using namespace std;

int n, m, tmp, cnt;
vector<vector<int>> v(201, vector<int>(201));
vector<int> plan, id;

void dfs(int x, int _id){
    id[x] = _id;
    for(int i=1;i<=n;i++){
        if(v[x][i]&&!id[i]) dfs(i, _id);
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    id = vector<int>(n+1);
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cin>>v[i][j];
    for(int i=1;i<=m;i++){
        cin>>tmp;
        plan.push_back(tmp);
    }
    for(int i=1;i<=n;i++) {
        if(!id[i]) dfs(i, ++cnt);
    }
    cnt = id[plan[0]];
    for(int i=0;i<m;i++){
        if(id[plan[i]]!=cnt) {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}