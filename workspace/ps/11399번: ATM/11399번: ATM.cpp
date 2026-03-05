#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    vector<int> arr(1000);

    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr.begin(), arr.begin()+n);
    for(int i=1;i<n;i++) arr[i]+=arr[i-1];
    cout<<accumulate(arr.begin(), arr.end(), 0)<<'\n';
    
    
    return 0;
}