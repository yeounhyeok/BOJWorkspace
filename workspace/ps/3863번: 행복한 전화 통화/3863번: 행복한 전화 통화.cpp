#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m, s, d, cnt=0;
    while(true){
        cin>>n>>m;
        vector<vector<int>> v(n, vector<int>(4));
        if(n==0 && m==0) return 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<4;j++) cin>>v[i][j];
        }
        for(int i=0;i<m;i++){
            cin>>s>>d;
            for(int j=0;j<n;j++){
                if(!(s+d<=v[j][2] || s>=v[j][2]+v[j][3])) cnt++;
            }
            cout<<cnt<<'\n';
            cnt=0;
        }
    }
}