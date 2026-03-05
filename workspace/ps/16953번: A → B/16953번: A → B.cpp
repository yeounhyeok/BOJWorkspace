#include <bits/stdc++.h>
using namespace std;
#define MX 1000000000
#define ull unsigned long long

bool flag;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    ull dist=0, A, B, x;cin>>A>>B;
    queue<ull> q;
    
    q.push(A);
    while(!q.empty()){
        ull size = q.size();
        while(size--){
            x = q.front();
            q.pop();
            if(x>B) continue;
            if(x==B) {
                flag=true;
                break;
            }
            if(2*x<=MX){
                q.push(2*x);
            }
            if(10*x+1<=MX){
                q.push(10*x+1);
            }
        }
        if(x==B) break;
        dist++;
    }
    if(flag) cout<<dist+1;
    else cout<<-1;
    return 0;
}