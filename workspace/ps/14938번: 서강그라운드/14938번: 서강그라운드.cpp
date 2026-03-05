#include<bits/stdc++.h>
using namespace std;

vector<int> itm(101);
vector<vector<int>> v(101, vector<int>(101, 1e7));
int n, m, r, a, b, c, mx;

void fw(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                v[i][j] = min(v[i][j], v[i][k]+v[k][j]);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m>>r;
    for(int i=1;i<=n;i++){
        cin>>itm[i];
        v[i][i]=0;
    }
    for(int i=0;i<r;i++){
        cin>>a>>b>>c;
        v[a][b] = c;
        v[b][a] = c;
    }
    fw();
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(v[i][j]<=m) cnt+=itm[j];
        }
        mx = max(mx, cnt);
    }
    cout<<mx;
    return 0;
}