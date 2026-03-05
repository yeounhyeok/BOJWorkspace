#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> arr(101, vector<int>(101, 1<<24));
vector<vector<int>> bt(101, vector<int>(101));

void fw(int n){
    for(int cur=1;cur<=n;cur++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(arr[i][j]>arr[i][cur]+arr[cur][j]){
                    arr[i][j] = arr[i][cur]+arr[cur][j];
                    bt[i][j] = bt[i][cur];
                }
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
        bt[a][b] = b;
    }
    for(int i=1;i<=n;i++) arr[i][i]=0;

    fw(n);

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) cout<<((arr[i][j]>0 && arr[i][j]<1<<24) ? arr[i][j]:0)<<' ';
        cout<<'\n';
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(arr[i][j]==1<<24 || i==j) {
                cout<<0<<'\n';
                continue;
            }

            vector<int> ans;
            int x = bt[i][j];
            while(x!=j){
                ans.push_back(x);
                x = bt[x][j];
            }
            cout<<ans.size()+2<<' '<<i<<' ';
            for(auto a:ans) cout<<a<<' ';
            cout<<j<<'\n';
        }
    }
    return 0;
}