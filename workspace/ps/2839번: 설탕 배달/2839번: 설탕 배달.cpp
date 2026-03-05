#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n, cnt=0, arr[5005];
    cin>>n;
    
    arr[3]=1;
    arr[5]=1;
    for(int i=6;i<=n;i++){
        if(arr[i-5]!=0) arr[i]=arr[i-5]+1;
        else if(arr[i-3]!=0) arr[i]=arr[i-3]+1;
    }
    if(arr[n]!=0) cout<<arr[n];
    else cout<<-1;
    return 0;
}