#include<bits/stdc++.h>
using namespace std;

vector<string> v;

int n, m, d[]={1,0,-1,0,1}, mx=1;
bool vst[27];

typedef struct stat{
    int i, j, cnt;
    stat(int _i, int _j, int _c) : i(_i), j(_j), cnt(_c) {};
}stat;

void dfs(stat &cur){
    vst[v[cur.i][cur.j]-'A']=1;
    mx = max(mx, (cur.cnt));
    for(int D=0;D<4;D++){
        int ni = cur.i+d[D], nj = cur.j+d[D+1];
        if(ni>=0&&ni<n&&nj>=0&&nj<m){
            if(!vst[v[ni][nj]-'A']){
                stat next(ni, nj, cur.cnt+1);
                dfs(next);
                vst[v[ni][nj]-'A']=0;
            }
        }
    }
    
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    v = vector<string>(n);
    for(int i=0;i<n;i++) cin>>v[i];
    stat t(0, 0, 1);
    dfs(t);
    cout<<mx;
    return 0;
}