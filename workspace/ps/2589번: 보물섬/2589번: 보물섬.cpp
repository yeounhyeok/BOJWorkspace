#include <bits/stdc++.h>
using namespace std;

int n, m, mx=0, d[] = {1,0,-1,0,1};
vector<string> v;

void bfs(int i, int j){
    vector<vector<int>> vst(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    q.push({i, j});
    while(!q.empty()){
        int r = q.front().first, c = q.front().second;
        q.pop();
        for(int D=0;D<4;D++){
            int nr = r+d[D], nc = c+d[D+1];
            if(nr>=0&&nr<n&&nc>=0&&nc<m){
                if(v[nr][nc]=='L'&&!vst[nr][nc]&&!(nr==i&&nc==j)) {
                    vst[nr][nc] = vst[r][c] + 1;
                    mx = max(vst[nr][nc], mx);
                    q.push({nr, nc});
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    v = vector<string>(n);
    for(int i=0;i<n;i++)cin>>v[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]=='L') bfs(i, j);
        }
    }
    cout<<mx;
    return 0;
}