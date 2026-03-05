#include<bits/stdc++.h>
using namespace std;

int a[51][51], l, r, n, flag=1, d[]={1,0,-1,0,1}, ans;
vector<vector<int>> vst;

bool chk(int x){ return (l<=x&&x<=r); }

int bfs(int i, int j){
    int s=a[i][j], cnt=1;
    vector<pair<int, int>> que = {{i, j}};
    queue<pair<int, int>> q;
    q.push({i, j});
    vst[i][j]=1;
    while(!q.empty()){
        int r=q.front().first, c=q.front().second;
        q.pop();
        for(int D=0;D<4;D++){
            int nr=r+d[D], nc=c+d[D+1];
            if(nr>=0&&nr<n&&nc>=0&&nc<n){
                if(!vst[nr][nc] && chk(abs(a[nr][nc]-a[r][c]))){
                    s+=a[nr][nc];
                    cnt++;
                    vst[nr][nc]=1;
                    que.push_back({nr, nc});
                    q.push({nr, nc});
                }
            }
        }
    }

    if(cnt==1) return 0;

    s/=cnt;
    for(auto x:que) a[x.first][x.second]=s;
    return 1;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>l>>r;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>a[i][j];
    while(flag){
        flag=0;
        vst=vector<vector<int>>(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!vst[i][j]) flag = max(flag, bfs(i, j));
            }
        }
        if(flag) ans++;
    }
    cout<<ans;
    return 0;
}