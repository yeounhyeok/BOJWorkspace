#include <bits/stdc++.h>
using namespace std;

unordered_map<string, string> m;
string a, b;
int N, M;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>a>>b;
        m[a] = b;
    }

    for(int i=0;i<M;i++){
        cin>>a;
        cout<<m.find(a)->second<<'\n';
    }

    return 0;
}

