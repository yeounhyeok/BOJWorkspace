#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull n, tmp, a[3];
pair<ull, ull> arr[6];
unordered_map<ull, ull> m = {
    {2, 3}, {3, 2},
    {0, 5}, {5, 0},
    {1, 4}, {4, 1}
};

int main(){
    cin>>n;
    for(ull i=0;i<6;i++){
        cin>>tmp;
        arr[i] = {tmp, i};
    }
    sort(arr, arr+6);
    if(n==1){
        ull sum=0;
        for(int i=0;i<5;i++)sum+=arr[i].first;
        cout<<sum;
        return 0;
    }
    ull side = (n*2+(n-2)*2);
    ull a1 = (n*n-side)*5 + (n-2)*4 , a2 = (n-2)*8 + 4, a3 = 4;
    a[0] = arr[0].first;

    ull idx=1;
    while(a[1]==0){
        ull x = arr[idx].second;
        if(m[arr[0].second]==x) idx++;
        else a[1] = arr[idx].first;
    }
    ull idx0=idx+1;
    while(a[2]==0){
        ull x = arr[idx0].second;
        if(m[arr[idx].second]==x||m[arr[0].second]==x) idx0++;
        else a[2] = arr[idx0].first;
    }
    
    
    ull ans1 = a1 * a[0], ans2 = a2 * (a[0]+a[1]), ans3 = a3 * (a[0]+a[1]+a[2]);
    cout<<ans1+ans2+ans3;
    
    return 0;
}