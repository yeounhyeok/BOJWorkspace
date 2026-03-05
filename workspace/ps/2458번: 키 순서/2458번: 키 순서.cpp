#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v(501, vector<int>(501, 1e7));
int n, m, a, b, ans;

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
    cin>>n>>m;
    for(int i=1;i<=n;i++) v[i][i]=0;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        v[a][b] = 1;
    }

    fw();

    for(int i=1;i<=n;i++){
        vector<bool> chk(n+1, 0);
        for(int j=1;j<=n;j++) {
            chk[j] = (v[i][j]!=1e7 || v[j][i]!=1e7);
        }
        for(int j=1;j<=n;j++){
            if(!chk[j]) break;
            if(j==n && chk[j]) ans++;
        }
    }

    cout<<ans;
    return 0;
}