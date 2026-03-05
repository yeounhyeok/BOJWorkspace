#include <bits/stdc++.h>

using namespace std;
int arr[10005], K, N;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>K>>N;
    for(int i=0;i<K;i++) cin>>arr[i];

    unsigned long long start=1, end=1<<31, mid, tot;
    while(start+1<end){
        tot=0;
        mid=(start+end)/2;
        for(int i=0;i<K;i++) tot+=arr[i]/mid;
        if(tot<N) end = mid;
        else if(tot>=N) start = mid;
    }
    cout<<start;
    
    return 0;
}