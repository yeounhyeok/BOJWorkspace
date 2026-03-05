#include<bits/stdc++.h>
using namespace std;

vector<int> p;
int n, m, a, b, ans;

int f(int x){
    if(x==p[x]) return x;
    return p[x]=f(p[x]);
}
void u(int x, int y){
    x=f(x);y=f(y);
    p[x<y?x:y]=x<y?y:x;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++) p.push_back(i);
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        if(f(a)==f(b)) ans = (!ans?i:ans);
        else u(a, b);
    }
    cout<<ans;
    return 0;
}