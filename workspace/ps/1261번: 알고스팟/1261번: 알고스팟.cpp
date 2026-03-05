#include <bits/stdc++.h>
using namespace std;

int n, m, d[]={1, 0, -1, 0, 1};
vector<string> v;

vector<vector<int>> bfs(){
    deque<pair<int, int>> q;
    vector<vector<int>> ans(n, vector<int>(m, 1e8));
    ans[0][0] = 0;
    q.push_back(make_pair(0, 0));

    while(!q.empty()){
        int r = q.front().first, c = q.front().second;
        q.pop_front();
        if(r==n-1&&c==m-1) return ans;
        for(int i=0;i<4;i++){
            int nr = r+d[i], nc = c+d[i+1];
            if(nr>=0&&nr<n&&nc>=0&&nc<m){
                if(v[nr][nc]=='0'&&ans[nr][nc]==1e8){
                    ans[nr][nc] = ans[r][c];
                    q.push_front(make_pair(nr, nc));
                }
                else if(ans[nr][nc] > ans[r][c]+1){
                    ans[nr][nc] = ans[r][c]+1;
                    q.push_back(make_pair(nr, nc));
                }
            }
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>m>>n;
    v=vector<string>(n);
    for(int i=0;i<n;i++)cin>>v[i];
    vector<vector<int>> ans = bfs();
    cout<<ans[n-1][m-1];
    return 0; 
}