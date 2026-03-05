#include<bits/stdc++.h>
using namespace std;
int n, m, mn=1e9;
vector<vector<int>> arr[3];

void fw(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                for(int x=0;x<2;x++)arr[x][i][j] = min(arr[x][i][j], arr[x][i][k]+arr[x][k][j]);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<3;i++)arr[i] = vector<vector<int>>(n+1, vector<int>(n+1, 1e9));
    for(int i=0;i<m;i++){
        int a, b, c;
        cin>>a>>b>>c;
        arr[0][a][b]=c;
        arr[1][b][a]=c;
    }
    fw();
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++) arr[2][i][j] = arr[0][i][j] + arr[1][i][j];
    for(auto y:arr[2])for(auto x:y) mn=min(x, mn);
    cout<<(mn==1e9?-1:mn);
    return 0;
}