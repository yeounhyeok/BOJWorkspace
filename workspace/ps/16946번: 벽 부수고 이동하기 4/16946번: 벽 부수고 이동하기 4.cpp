#include<bits/stdc++.h>
using namespace std;

vector<string> v;
vector<int> idsize(1);
int d[]={1,0,-1,0,1};
int n, m, idmap[1001][1001], ans[1001][1001];
bool vst[1001][1001];

void dfs(int i, int j, int id){
    vst[i][j]=1;
    idmap[i][j] = id;
    idsize[id]++;
    for(int ii=0;ii<4;ii++){
        int ni = i+d[ii], nj = j+d[ii+1];
        if(ni>=0&&ni<n&&nj>=0&&nj<m){
            if(v[ni][nj]=='0'&&!vst[ni][nj]) dfs(ni, nj, id);
        }
    }
}

int breakwall(int i, int j){
    int res = 1;
    unordered_map<int, int> um;
    for(int ii=0;ii<4;ii++){
        int ni = i+d[ii], nj = j+d[ii+1];
        if(ni>=0&&ni<n&&nj>=0&&nj<m){
            if(idmap[ni][nj]!=0 && um.find(idmap[ni][nj])==um.end()){
                um[idmap[ni][nj]]=0;
                res+=idsize[idmap[ni][nj]];
            }
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    v = vector<string>(n);
    for(int i=0;i<n;i++) cin>>v[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]=='0'&&!vst[i][j]){
                idsize.push_back(0);
                dfs(i, j, idsize.size()-1);
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]=='1'){
                ans[i][j] = breakwall(i, j);
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cout<<ans[i][j]%10;
        cout<<endl;
    }
    return 0;   
}