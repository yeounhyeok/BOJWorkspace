#include <bits/stdc++.h>
using namespace std;

int v[101][101], n, m, mid, ans;

void fw(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                v[i][j]=min(v[i][j], v[i][k]+v[k][j]);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    mid = (n+1)/2;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)v[i][j]=1e8;
    for(int i=1;i<=n;i++)v[i][i]=0;
    for(int i=0;i<m;i++){
        int a, b;cin>>a>>b;
        v[a][b]=0;
    }
    fw();
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(!v[i][j])cnt++;
        }
        if(cnt>mid)ans++;
    }
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(!v[j][i])cnt++;
        }
        if(cnt>mid)ans++;
    }
    cout<<ans;
    return 0;
}