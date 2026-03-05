#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> arr(101, vector<int>(101, 20000));

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
    int tmp, n;cin>>n;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin>>tmp;
            if(tmp==1) arr[i][j]=tmp;
        }
    }
    fw(n);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) cout<<((arr[i][j]>0 && arr[i][j]<20000) ? 1:0)<<' ';
        cout<<'\n';
    }
    return 0;
}