#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, h, arr[100002], ac[1000002];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=0;i<m;i++){
        cin>>a>>b>>h;
        ac[a] += h;
        ac[b+1] -= h;
    }
    for(int i=1;i<=n;i++) ac[i]+=ac[i-1];
    for(int i=1;i<=n;i++) cout<<arr[i]+ac[i]<<' ';
    return 0;
}
