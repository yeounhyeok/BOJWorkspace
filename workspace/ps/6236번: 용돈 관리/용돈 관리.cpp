#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    int N, M, arr[100005];
    cin>>N>>M;
    for(int i=0;i<N;i++) cin>>arr[i];
    ll s=*max_element(arr, arr+N)-1, e=1e9+1, m, k, cnt;
    while(s+1<e){
        m=(s+e)/2;
        k=m;
        cnt=1;
        for(int i=0;i<N;i++){
            if(k<arr[i]){
                k=m;
                cnt++;    
            }            
            k-=arr[i];
            if(k<0) break;
        }
        if(k<0||cnt>M) s=m;
        else e=m;
    }
    cout<<e;
    return 0;
}