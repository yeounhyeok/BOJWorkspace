#include<bits/stdc++.h>
#define rep(i, a, b) for(int i=a;i<b;i++)
using namespace std;

int n, v[20][20], d[]={1,0,-1,0,1}, ans, ex;

typedef struct stat{
    int size, i, j;
    stat(int _i, int _j, int _s):i(_i),j(_j),size(_s){}
}stat;
queue<stat> q;

bool cmp(pair<stat, int> &a, pair<stat, int> &b){
    if(a.second==b.second){
        if(a.first.i==b.first.i) return a.first.j<b.first.j;
        return a.first.i<b.first.i;
    }
    return a.second<b.second;
}

pair<stat, int> bfs(){
    vector<pair<stat, int>> where;
    vector<vector<int>> vst(n, vector<int>(n, 1e7));
    vst[q.front().i][q.front().j]=0;
    while(!q.empty()){
        stat cur = q.front();q.pop();
        rep(D, 0, 4){
            int ni = cur.i+d[D], nj = cur.j+d[D+1];
            if(ni>=0&&ni<n&&nj>=0&&nj<n){
                if(v[ni][nj]<=cur.size && vst[ni][nj]==1e7){
                    if(v[ni][nj]<cur.size && v[ni][nj]>0){
                        vst[ni][nj] = vst[cur.i][cur.j] + 1;
                        where.push_back({stat(ni, nj, cur.size), vst[ni][nj]});
                    }
                    else {
                        vst[ni][nj] = vst[cur.i][cur.j] + 1;
                        q.push(stat(ni, nj, cur.size));
                    }
                }
            }
        }
    }
    sort(where.begin(), where.end(), cmp);
    return ((where.empty())?make_pair(stat(-1,-1,-1), -1):where[0]);
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    rep(i,0,n)rep(j,0,n){
        cin>>v[i][j];
        if(v[i][j]==9) q.push(stat(i, j, 2));
    }
    v[q.front().i][q.front().j]=0;

    while(1){
        pair<stat, int> x = bfs();
        if(x.first.i==-1) break;
        ex++;
        while(ex-x.first.size>=0){
            ex-=x.first.size;
            x.first.size++;
        }
        v[x.first.i][x.first.j]=0;
        q.push(x.first);
        ans+=x.second;
    }

    cout<<ans;

    return 0;
}