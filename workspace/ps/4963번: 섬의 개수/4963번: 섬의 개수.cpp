#include <bits/stdc++.h>
using namespace std;

int d[] = {1, 0, -1, 0, 1, 1, -1, -1, 1};

void dfs(vector<vector<int>> &v, int i, int j){
    v[i][j]--;
    for(int k=0;k<8;k++){
        int next_i = i+d[k], next_j = j+d[k+1];
        if(next_i>=0 && next_i<v.size() && next_j>=0 && next_j<v[0].size() && v[next_i][next_j]){
            dfs(v, next_i, next_j);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(1){
        int a, b, cnt=0;cin>>b>>a;
        if(!a && !b) break;
        vector<vector<int>> v(a, vector<int>(b));
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++) cin>>v[i][j];
        }
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++) {
                if(!v[i][j])continue;
                cnt++;
                dfs(v, i, j);
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
}