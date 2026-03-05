#include <bits/stdc++.h>
using namespace std;

deque<int> q;
unordered_map<int, int> dst;
unordered_map<int, set<int>> m;
unordered_map<int, bool> m0;

void bfs(){
    while(!q.empty()){
        int x = q.front();q.pop_front();
        if(m0.find(x)!=m0.end()){
            q.push_front(*m[x].begin());
            dst[*m[x].begin()] = dst[x];
            continue;
        }
        for(auto i:m[x]){
            if(dst.find(i)==dst.end()){
                dst[i]=dst[x]+1;
                q.push_back(i);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int N, M;cin>>N>>M;
    for(int i=1;i<=100;i++) m[i]=set<int>();
    for(int i=0;i<N+M;i++){
        int a, b;cin>>a>>b;
        m[a].insert(b);
        m0[a]=1;
    }
    for(int i=1;i<100;i++){
        if(m[i].empty()){
            for(int j=1;j<=6 && i+j<=100;j++){
                m[i].insert(i+j);
            }
        }
    }

    dst[1]=0;
    q.push_back(1);
    bfs();

    cout<<dst[100];
    
    return 0;
}