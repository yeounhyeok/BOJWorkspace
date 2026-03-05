#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n, k, tmp, ans=0, cnt=0;
    stack<int> s;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>tmp;
        s.push(tmp);
    }
    while(!s.empty() && ans!=k){
        tmp = s.top();
        s.pop();
        while(ans+tmp<=k) {
            ans+=tmp;
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}