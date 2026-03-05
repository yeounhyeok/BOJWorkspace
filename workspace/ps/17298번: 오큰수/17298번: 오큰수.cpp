#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    vector<vector<int>> v(n+1, vector<int>(2));
    stack<int> s;
    for(int i=0;i<n;i++) cin>>v[i][0];
    for(int i=0;i<n;i++){
        if(v[i+1][0]>v[i][0]) {
            v[i][1]=v[i+1][0];
            while(!s.empty()&&v[s.top()][0]<v[i+1][0]){
                v[s.top()][1]=v[i+1][0];
                s.pop();
            }
        }
        else s.push(i);
    }
    v.pop_back();
    for(auto i:v) cout<<(i[1] ? i[1]:-1)<<' '; 
    return 0;
}