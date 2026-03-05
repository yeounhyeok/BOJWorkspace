#include <bits/stdc++.h>
using namespace std;

int arr[100050];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m, tmp;cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>tmp;
        arr[i] = tmp + arr[i-1] ;
    }
    int x1,x2;
    for(int i=0;i<m;i++){
        cin>>x1>>x2;
        cout<<arr[x2]-arr[x1-1]<<'\n';
    }
    return 0;
}