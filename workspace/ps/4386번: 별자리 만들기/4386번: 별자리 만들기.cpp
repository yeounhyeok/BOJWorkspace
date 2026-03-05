#include <bits/stdc++.h>
using namespace std;
typedef pair<double, double> pdd;
typedef struct edge{
    int frm, to;
    double dst;
    edge(int f, int t, double dd) : frm(f), to(t), dst(dd) {};
}edge;

vector<pdd> node;
vector<edge> v;
vector<int> p;
int n;
double a, b, ans=0;

int f(int x){
    if(x==p[x]) return x;
    return p[x] = f(p[x]);
}

void u(int x, int y){
    x = f(x); y = f(y);
    p[x<y?x:y] = x<y?y:x;
}

double dist(int aa, int bb, int cc, int dd){ return sqrt((aa-cc)*(aa-cc) + (bb-dd)*(bb-dd)); }

bool cmp(edge x, edge y){ return x.dst<y.dst; }

int main(){
    cin>>n;
    p.resize(n);
    for(int i=0;i<n;i++)p[i]=i;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        node.push_back({a, b});
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            v.push_back(edge(i, j, dist(node[i].first, node[i].second, node[j].first, node[j].second)));
        }
    }
    sort(v.begin(), v.end(), cmp);

    for(auto e:v){
        if(f(e.frm)!=f(e.to)) {
            u(e.frm, e.to);
            ans+=e.dst;
        }
    }
    printf("%.2lf", ans);
    return 0;
}