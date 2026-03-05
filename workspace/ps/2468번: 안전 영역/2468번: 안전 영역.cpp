#include <bits/stdc++.h>
using namespace std;

int dir[] = {1, 0, -1, 0, 1};

void dfs(vector<vector<int>> &v, vector<vector<bool>> &vst, int h, int i, int j){
    int n = v.size();
    vst[i][j]=1;

    

    for(int d=0;d<4;d++){
        if(i+dir[d]>=0 && i+dir[d]<n && j+dir[d+1]>=0 && j+dir[d+1]<n && v[i+dir[d]][j+dir[d+1]]-h>0 && !vst[i+dir[d]][j+dir[d+1]]){
            dfs(v, vst, h, i+dir[d], j+dir[d+1]);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n, mx=1;cin>>n;
    vector<vector<int>> v(n, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin>>v[i][j];
    }

    for(int h=0;h<101;h++){
        int cnt=0;
        vector<vector<bool>> vst(n, vector<bool>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]-h<=0 || vst[i][j]) continue;
                dfs(v, vst, h, i, j);
                cnt+=1;
            }
        }
        mx = max(cnt, mx);
        if(cnt==0) break;
    }
    cout<<mx;
    return 0;
}