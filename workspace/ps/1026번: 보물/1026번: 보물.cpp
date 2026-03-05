#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    vector<vector<int>> v(2, vector<int>(n));
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++) cin>>v[i][j];
    }
    int s=0;
    sort(v[0].begin(), v[0].end());
    sort(v[1].begin(), v[1].end(), greater<>());
    for(int i=0;i<n;i++){
        s+=v[0][i]*v[1][i];
    }
    cout<<s;
}