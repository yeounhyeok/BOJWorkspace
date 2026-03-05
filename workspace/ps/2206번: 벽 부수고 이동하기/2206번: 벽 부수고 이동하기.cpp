#include <bits/stdc++.h>
using namespace std;

vector<string> v;
vector<vector<int>> vst[2];
int d[] = {1, 0, -1, 0, 1}, n, m;

typedef struct status{
    bool breaked=false;
    int i, j;
    status(bool _b, int _i, int _j) : breaked(_b), i(_i), j(_j) {};
}status;

int bfs(){
    int mn=1e7;
    vst[1][0][0]=1;
    vst[0][0][0]=1;
    queue<status> q;
    q.push(status(false, 0, 0));
    
    while(!q.empty()){
        status cur = q.front(); q.pop();
        if(cur.i==n-1&&cur.j==m-1) {
            mn = min(mn, min(vst[1][n-1][m-1], vst[0][n-1][m-1]));
        }

        for(int i=0;i<4;i++){
            int nextr = cur.i+d[i], nextc = cur.j+d[i+1];
            if(nextr>=0 && nextr<=n-1 && nextc>=0 && nextc<=m-1){
                if(!cur.breaked){
                    int type = (v[nextr][nextc]=='1' ? 1:0);
                    if(vst[0][cur.i][cur.j]+1<vst[type][nextr][nextc]){
                        q.push(status(type, nextr, nextc));
                        vst[type][nextr][nextc] = vst[0][cur.i][cur.j]+1;
                    }
                }
                else{
                    if(v[nextr][nextc]=='0'){
                        if(vst[1][cur.i][cur.j]+1<vst[1][nextr][nextc]){
                            q.push(status(true, nextr, nextc));
                            vst[1][nextr][nextc] = vst[1][cur.i][cur.j]+1;
                        }
                    }
                }
            }
        }
    }
    return mn;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    v = vector<string>(n);
    vst[0] = vector<vector<int>>(n, vector<int>(m, 1e7));
    vst[1] = vst[0];
    for(int i=0;i<n;i++) cin>>v[i];
    int ans = bfs();
    cout<<(ans!=1e7?ans:-1);
    return 0;
}