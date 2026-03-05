#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    priority_queue<long long, vector<long long>, greater<>> gq;
    long long tmp, n;cin>>n;
    for(int i=0;i<n*n;i++){
        cin>>tmp;
        if(gq.size()<n || gq.top()<tmp) {
            if(gq.size()==n) gq.pop();
            gq.push(tmp);
        }
    }
    cout<<gq.top();
    return 0;
}