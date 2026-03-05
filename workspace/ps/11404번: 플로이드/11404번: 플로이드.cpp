#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> arr(101, vector<int>(101, 1<<24));

void fw(int n){
    for(int cur=1;cur<=n;cur++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                arr[i][j] = min(arr[i][j], arr[i][cur]+arr[cur][j]);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int m, n, a, b, c;cin>>n>>m;
    for(int i=1;i<=m;i++) {
        cin>>a>>b>>c;
        arr[a][b] = min(c, arr[a][b]);
    }
    for(int i=1;i<=n;i++) arr[i][i]=0;

    fw(n);

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) cout<<((arr[i][j]>0 && arr[i][j]<1<<24) ? arr[i][j]:0)<<' ';
        cout<<'\n';
    }
    return 0;
}