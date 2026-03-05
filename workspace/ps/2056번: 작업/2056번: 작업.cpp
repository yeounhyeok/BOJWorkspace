#include<bits/stdc++.h>
#define MX 10001
using namespace std;

int in[MX], n, m, w[MX], dp[MX];
vector<vector<int>> v;
queue<int> q;

void tsort(){
    for(int i=1;i<=n;i++) {
        if(!in[i]){
            q.push(i);
            dp[i]=w[i];
        }
    }

    for(int i=0;i<n;i++){
        if(q.empty())return;
        int x=q.front();
        q.pop();
        for(int j=0;j<v[x].size();j++){
            int cur = v[x][j];
            dp[cur] = max(dp[cur], dp[x] + w[cur]);
            if(--in[cur]==0) {
                q.push(cur);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    v.resize(n+1);
    for(int i=1;i<=n;i++){
        int a, m, ww;cin>>ww>>m;
        w[i]=ww;
        for(int j=0;j<m;j++){
            cin>>a;
            v[a].push_back(i);
            in[i]++;
        }
    }
    tsort();
    cout<<*max_element(dp+1, dp+1+n);
    return 0;
}