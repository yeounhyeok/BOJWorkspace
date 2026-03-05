#include <bits/stdc++.h>

using namespace std;
int n, m, arr[10];
//bool visited[10];
vector<int> v;
void dfs(int depth){
    if(depth==m){
        for(int i=0;i<m;i++) cout<<v[i]<<' ';
        cout<<'\n';
        return;
    }
    for(int i=1;i<=n;i++){
        //if(visited[i]) continue;
        //visited[i]=true;
        v.push_back(arr[i]);
        dfs(depth+1);
        v.pop_back();
        //visited[i]=false;
    }
    return;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=n;i++) arr[i]=i;
    dfs(0);
}