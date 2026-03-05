#include<bits/stdc++.h>
#define MX 1001
using namespace std;
typedef vector<int> vi;


int t, n, k, w, a, b;

void tsort(vector<vi>& v, vi& dp, vi& in, vi& delay){
    queue<int> q;
    for(int i=1;i<=n;i++) if(!in[i]) {
        q.push(i);
        dp[i]=delay[i];
    }
    for(int i=1;i<=n;i++){
        int cur=q.front();
        q.pop();
        for(int j=0;j<v[cur].size();j++){
            int next = v[cur][j];
            dp[next] = max(dp[next], dp[cur]+delay[next]);
            if(--in[next]==0){
                q.push(next);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<vi> v(n+1);
        vi dp(n+1), in(n+1), delay(n+1);
        for(int i=1;i<=n;i++) cin>>delay[i];
        for(int i=0;i<k;i++){
            cin>>a>>b;
            v[a].push_back(b);
            in[b]++;
        }
        tsort(v,dp,in,delay);
        cin>>w;
        cout<<dp[w]<<'\n';
    }
    return 0;
}