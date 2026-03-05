#include <bits/stdc++.h>

using namespace std;
bool arr[1000001];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,m;cin>>m>>n;
    arr[1]=true;
    for(int i=2;i<=n;i++){
        for(int j=2;i*j<=n;j++) arr[i*j]=true;
    }

    for(int i=m;i<=n;i++){
        if(!arr[i]) cout<<i<<'\n';
    }
    
    return 0;
}