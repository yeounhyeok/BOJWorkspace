#include <bits/stdc++.h>
using namespace std;

int cnt[2];

bool chk(vector<vector<int>> &v, int n){
    int col = v[0][0];
    for(auto i:v){
        for(auto j:i){
            if(j!=col) return false;
        }
    }
    return true;
}

vector<vector<int>> vecSlice(vector<vector<int>> inp, int c, int d, int a, int b) {
    vector<vector<int>> v;
    for(int i=c;i<d;i++) v.push_back(vector<int>(inp[i].begin() + a, inp[i].begin() + b));
    return v;
}


void rec(vector<vector<int>> v, int n){
    if(n==1 || chk(v, n)) {
        cnt[v[0][0]]++;
        return;
    }
    rec(vecSlice(v, 0, n/2, 0, n/2), n/2);
    rec(vecSlice(v, 0, n/2, n/2, n), n/2);
    rec(vecSlice(v, n/2, n, 0, n/2), n/2);
    rec(vecSlice(v, n/2, n, n/2, n), n/2);
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    vector<vector<int>> v(n, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin>>v[i][j];
    }
    rec(v, n);
    cout<<cnt[0]<<'\n'<<cnt[1];
    return 0;
}