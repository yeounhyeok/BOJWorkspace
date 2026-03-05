#include <bits/stdc++.h>
using namespace std;

vector<string> v;
vector<vector<vector<int>>> vst;
int d[] = {1, 0, -1, 0, 1}, n, m, k;

typedef struct status{
    
    int i, j, breaked=0;
    status(int _b, int _i, int _j) : breaked(_b), i(_i), j(_j) {};
}status;

bool cmp(vector<vector<int>> &a, vector<vector<int>> &b){ return (a[n-1][m-1]<b[n-1][m-1]); }

int bfs(){
    queue<status> q;
    q.push(status(0, 0, 0));
    
    while(!q.empty()){
        status cur = q.front(); q.pop();
        for(int i=0;i<4;i++){
            int nextr = cur.i+d[i], nextc = cur.j+d[i+1];
            if(nextr>=0 && nextr<n && nextc>=0 && nextc<m){
                int b = ((v[nextr][nextc]=='1' && cur.breaked+1<=k) ? 1:0);
                if(!b&&v[nextr][nextc]=='1') continue;
                if(vst[cur.breaked][cur.i][cur.j]+1<vst[cur.breaked + b][nextr][nextc]){
                    q.push(status(cur.breaked + b, nextr, nextc));
                    vst[cur.breaked + b][nextr][nextc] = vst[cur.breaked][cur.i][cur.j]+1;
                }
            }
        }
    }
    sort(vst.begin(), vst.end(), cmp);
    return vst[0][n-1][m-1];
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m>>k;
    v = vector<string>(n);
    vst = vector<vector<vector<int>>>(k+1, vector<vector<int>>(n, vector<int>(m, 1e7)));
    for(int i=0;i<=k;i++) vst[i][0][0]=1;
    for(int i=0;i<n;i++) cin>>v[i];
    int ans = bfs();
    cout<<(ans!=1e7?ans:-1);
    return 0;
}