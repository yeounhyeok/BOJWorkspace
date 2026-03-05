#include<bits/stdc++.h>
#define rep(i, a, b) for(int i=a;i<b;i++)
using namespace std;

int n, v[125][125], d[]={1,0,-1,0,1};

struct stat{
    int i,j,w;
    stat(int ii, int jj):i(ii),j(jj){ w = v[i][j]; }
};

struct cmp{ bool operator()(stat &a, stat &b) { return a.w>b.w; } };

int dij(){
    vector<vector<int>> dist(n, vector<int>(n, 1e7));
    priority_queue<stat, vector<stat>, cmp> q;
    dist[0][0]=v[0][0];
    q.push(stat(0, 0));
    while(!q.empty()){
        stat cur = q.top(); q.pop();
        if(dist[cur.i][cur.j] < cur.w) continue;
        rep(i, 0, 4){
            int ni = cur.i+d[i], nj = cur.j+d[i+1];
            if(ni>=0&&ni<n&&nj>=0&&nj<n){
                stat next(ni, nj);
                if(next.w + dist[cur.i][cur.j] < dist[ni][nj]){
                    dist[ni][nj] = next.w + dist[cur.i][cur.j];
                    q.push(next);
                }
            }
        }
    }
    return dist[n-1][n-1];
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int t=1;;t++){
        cin>>n;
        if(!n)break;
        rep(i, 0, n)rep(j, 0, n)cin>>v[i][j];
        cout<<"Problem "<<t<<": "<<dij()<<'\n';
    }
}