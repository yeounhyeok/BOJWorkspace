#include <bits/stdc++.h>
using namespace std;

typedef struct edge{
    int a, b, c;
    edge(int aa, int bb, int cc):a(aa), b(bb), c(cc){};
}edge;

bool cmp(edge &x, edge &y){ return x.c<y.c; }

vector<int> prt(1);
vector<edge> v;
int V, E, a, b, c, ans, mx;

int f(int x){
    if(x==prt[x]) return x;
    return prt[x] = f(prt[x]);
}

void u(int x, int y){
    x = f(x);  y = f(y);
    prt[x<y?x:y] = x<y?y:x;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>V>>E;
    for(int i=1;i<=V;i++) prt.push_back(i);
    for(int i=0;i<E;i++){
        cin>>a>>b>>c;
        v.push_back(edge(a, b, c));
    }
    sort(v.begin(), v.end(), cmp);
    for(auto e:v){
        if(f(e.a)!=f(e.b)) {
            u(e.a, e.b);
            ans+=e.c;
            mx = max(mx, e.c);
        }
    }
    cout<<ans-mx;
    return 0;
}