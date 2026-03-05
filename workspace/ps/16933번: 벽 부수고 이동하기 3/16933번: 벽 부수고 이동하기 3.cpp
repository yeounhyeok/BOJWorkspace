#include <bits/stdc++.h>
using namespace std;

vector<string> v;
int vst[11][1001][1001];
int d[] = {1, 0, -1, 0, 1}, n, m, k;

typedef struct status{
    short i, j, breaked, day, waited;
    status(short _d, short _w, short _b, short _i, short _j) : day(_d), waited(_w), breaked(_b), i(_i), j(_j) {};
}status;

queue<status> q;

void breakwall(status cur, int nextr, int nextc, int type){
    if(vst[cur.breaked + type][nextr][nextc]!=(int)1e7) return;
    if(vst[cur.breaked][cur.i][cur.j]+1 < vst[cur.breaked + type][nextr][nextc]){
        q.push(status(!cur.day, 0, cur.breaked + type, nextr, nextc));
        vst[cur.breaked + type][nextr][nextc] = vst[cur.breaked][cur.i][cur.j] + 1 + cur.waited;
    }
}

void waiting(status cur){ q.push(status(true, 1, cur.breaked, cur.i, cur.j)); }

int bfs(){
    q.push(status(1, 0, 0, 0, 0));
    while(!q.empty()){
        status cur = q.front(); q.pop();
        if(cur.i==n-1&&cur.j==m-1) return vst[cur.breaked][cur.i][cur.j];
        for(int i=0;i<4;i++){
            int nextr = cur.i+d[i], nextc = cur.j+d[i+1];
            if(nextr>=0 && nextr<n && nextc>=0 && nextc<m){
                if(v[nextr][nextc]=='1' && cur.breaked+1<=k){
                    if(cur.day) breakwall(cur, nextr, nextc, 1);
                    else waiting(cur);
                }
                else if(v[nextr][nextc]=='0'){
                    breakwall(cur, nextr, nextc, 0);
                }
            }
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    v = vector<string>(n);
    for(int l=0;l<=k;l++)for(int i=0;i<n;i++)for(int j=0;j<m;j++)vst[l][i][j]=1e7;
    vst[0][0][0]=1;
    
    for(int i=0;i<n;i++) cin>>v[i];
    int ans = bfs();
    cout<<(ans!=1e7?ans:-1);
    return 0;
}