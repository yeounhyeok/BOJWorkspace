#include <bits/stdc++.h>
using namespace std;
typedef vector<unordered_map<int, int>> vumii;

bool cycle;
int t, n, m, w, a, b, c;
vumii v;
unordered_map<int, int> um;

bool bf(int s){
    vector<int> d(n+1, 1e8);
    d[s]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(auto e:v[j]){
                int next = e.first, nextdist = e.second + d[j];
                if(d[next]>nextdist){
                    d[next] = nextdist;
                    if(i==n) return 1;
                }
            }
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>m>>w;
        v = vumii(n+1);
        for(int i=0;i<m;i++){
            cin>>a>>b>>c; um[a]=a, um[b]=b;
            v[a][b]=min(c, v[a].find(b)!=v[a].end() ? v[a][b]:c);
            v[b][a]=min(c, v[b].find(a)!=v[b].end() ? v[b][a]:c);
        }
        for(int i=0;i<w;i++){
            cin>>a>>b>>c;
            v[a][b]=min(-c, v[a].find(b)!=v[a].end() ? v[a][b]:-c);
        }
        
        cycle = bf(1);
        cout<<(cycle?"YES":"NO")<<'\n';
    }
    

    return 0;
}