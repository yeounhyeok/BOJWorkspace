#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v;

int f(int x){
    if(x==v[x]) return x;
    return v[x] = f(v[x]);
}

void u(int x, int y){
    x = f(x); y = f(y);
    if(x==y) return;
    v[x<y?y:x] = x<y?x:y;
}

bool isu(int x, int y){
    x = f(x); y = f(y);
    return (x==y);
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    v=vector<int>(n+1);
    for(int i=0;i<=n;i++)v[i]=i;
    for(int i=0;i<m;i++){
        int a, b, c;cin>>a>>b>>c;
        if(!a) u(b, c);
        else cout<<(isu(b, c)?"YES":"NO")<<"\n";
        
    }
    return 0;
}