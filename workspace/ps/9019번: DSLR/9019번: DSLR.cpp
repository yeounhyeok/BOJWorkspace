#include<bits/stdc++.h>
#define MX 10001
using namespace std;

unordered_map<int, pair<int, char>> trace;
vector<int> v;
vector<char> ans;
int t, a, b;

void bfs(){
    queue<int> q;
    q.push(a);
    v[a]=0;
    while(!q.empty()){
        int x = q.front(),
            d = (x*2>MX-2 ? (x*2)%(MX-1) : x*2),
            s = (x-1<0 ? MX-2 : x-1),
            l = (10*x)%(MX-1) + x/(1000),
            r = (x/10) + (x%10)*1000;
        q.pop();
        if(x==b) break;
        if(v[d] > v[x]+1){
            q.push(d);
            v[d] = v[x]+1;
            trace[d] = make_pair(x, 'D');
        }
        if(v[s] > v[x]+1){
            q.push(s);
            v[s] = v[x]+1;
            trace[s] = make_pair(x, 'S');
        }
        if(v[l] > v[x]+1){
            q.push(l);
            v[l] = v[x]+1;
            trace[l] = make_pair(x, 'L');
        }
        if(v[r] > v[x]+1){
            q.push(r);
            v[r] = v[x]+1;
            trace[r] = make_pair(x, 'R');
        }
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--){
        cin>>a>>b;
        trace.clear();
        ans.clear();
        v = vector<int>(MX, 1e8);
        bfs();
        while(a!=b){
            ans.push_back(trace[b].second);
            b=trace[b].first;
        }
        reverse(ans.begin(), ans.end());
        for(auto i:ans) cout<<i;
        cout<<'\n';
    }
    return 0;
}