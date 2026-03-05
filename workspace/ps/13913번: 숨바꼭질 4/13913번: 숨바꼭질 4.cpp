#include <bits/stdc++.h>
#define MX 100002
using namespace std;

vector<int> cnt(MX, INT_MAX);

int main(){
    deque<int> q;
    unordered_map<int, int> m;
    int n, k, currentDist;cin>>n>>k;
    if(n==k){
        cout<<0<<'\n'<<n<<'\n';
        return 0;
    }
    if(n>k){
        cout<<n-k<<'\n';
        for(int i=n;i>=k;i--) cout<<i<<' ';
        return 0;
    }
    q.push_front(n);cnt[n] = 0;
    while(!q.empty()){
        int x = q.front();
        q.pop_front();
        if(x==k) break;
        else {
            if(2*x<=MX && m.find(2*x)==m.end()){
                currentDist = cnt[x]+1;
                if(currentDist < cnt[2*x]){
                    cnt[2*x] = currentDist;
                    m[2*x] = x;
                    q.push_front(2*x);
                }
            }
            if(x-1>=0 && m.find(x-1)==m.end()){
                currentDist = cnt[x]+1;
                if(currentDist < cnt[x-1]){
                    cnt[x-1] = currentDist;
                    m[x-1] = x;
                    q.push_back(x-1);
                }
            }
            if(x+1<=MX && m.find(x+1)==m.end()){
                currentDist = cnt[x]+1;
                if(currentDist < cnt[x+1]){
                    cnt[x+1] = currentDist;
                    m[x+1] = x;
                    q.push_back(x+1);
                }
            }
        }
    }
    cout<<cnt[k]<<'\n';
    deque<int> result;
    int cur = k;
    for(int i=0;i<cnt[k];i++){
        result.push_front(cur);
        cur=m[cur];
    }
    result.push_front(n);
    for(int i=0;i<=cnt[k];i++) cout<<result[i]<<' ';
    return 0;
}