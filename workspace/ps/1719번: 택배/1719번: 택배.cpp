#include<bits/stdc++.h>
using namespace std;

int n, m, v[201][201], ans[201][201];

void fw(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(v[i][j]>v[i][k]+v[k][j]){
                    v[i][j]=v[i][k]+v[k][j];
                    ans[i][j] = ans[i][k];
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)v[i][j]=1e8;
    for(int i=1;i<=n;i++)v[i][i] = 0;
    for(int i=1;i<=m;i++){
        int a, b, c;
        cin>>a>>b>>c;
        v[a][b] = c;
        v[b][a] = c;
        ans[a][b] = b;
        ans[b][a] = a;
    }
    fw();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) cout<<"- ";
            else cout<<ans[i][j]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}