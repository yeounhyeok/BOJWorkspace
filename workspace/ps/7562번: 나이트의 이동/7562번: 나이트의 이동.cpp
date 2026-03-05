#include<bits/stdc++.h>
using namespace std;

int dc[]={1, 2, 2, 1, -1, -2, -2, -1};
int dr[]={2, 1, -1, -2, -2, -1, 1, 2};

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<vector<int>> v(n, vector<int>(n));
        queue<pair<int, int>> q;
        int r0, c0, r1, c1;cin>>r0>>c0>>r1>>c1;
        if(r0==r1&&c0==c1) goto there;
        q.push(make_pair(r0, c0));
        while(!q.empty()){
            int r=q.front().first, c=q.front().second;
            q.pop();
            for(int i=0;i<8;i++){
                int nextr=r+dr[i], nextc=c+dc[i];
                if(nextr>=0&&nextr<n&&nextc>=0&&nextc<n && !v[nextr][nextc]){
                    v[nextr][nextc]=v[r][c]+1;
                    if(nextr==r1&&nextc==c1) goto there;
                    q.push(make_pair(nextr, nextc));
                }
            }
        }
        there:
        cout<<v[r1][c1]<<'\n';
    }
    return 0;
}