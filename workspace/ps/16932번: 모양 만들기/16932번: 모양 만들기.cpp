#include<bits/stdc++.h>
using namespace std;

int v[1001][1001];
vector<vector<int>> idsize(2, vector<int>(1));
int d[]={1,0,-1,0,1};
int mx = -1, n, m, idmap[2][1001][1001], ans[1001][1001];
bool vst[1001][1001];

void dfs(int i, int j, int id, int type){
    vst[i][j]=1;
    idmap[type][i][j] = id;
    idsize[type][id]++;
    for(int ii=0;ii<4;ii++){
        int ni = i+d[ii], nj = j+d[ii+1];
        if(ni>=0&&ni<n&&nj>=0&&nj<m){
            if(v[ni][nj]==type&&!vst[ni][nj]) dfs(ni, nj, id, type);
        }
    }
}

int breakwall(int i, int j, int type){
    int res = 1;
    unordered_map<int, int> um;
    for(int ii=0;ii<4;ii++){
        int ni = i+d[ii], nj = j+d[ii+1];
        if(ni>=0&&ni<n&&nj>=0&&nj<m){
            if(idmap[type][ni][nj]!=0 && um.find(idmap[type][ni][nj])==um.end()){
                um[idmap[type][ni][nj]]=0;
                res+=idsize[type][idmap[type][ni][nj]];
            }
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++)cin>>v[i][j];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]==0&&!vst[i][j]){
                idsize[0].push_back(0);
                dfs(i, j, idsize[0].size()-1, 0);
            }
            if(v[i][j]==1&&!vst[i][j]){
                idsize[1].push_back(0);
                dfs(i, j, idsize[1].size()-1, 1);
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans[i][j] = breakwall(i, j, 1);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) mx = max(ans[i][j], mx);
    }
    cout<<mx;
    return 0;   
}