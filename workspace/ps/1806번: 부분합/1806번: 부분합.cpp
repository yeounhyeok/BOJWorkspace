#include <bits/stdc++.h>
using namespace std;
int arr[100002];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int tmp, s=1, e=1, N, S, mn=INT_MAX;
    cin>>N>>S;
    for(int i=1;i<=N;i++) {
        cin>>tmp;
        arr[i]=tmp+arr[i-1];
    }
    for(;s<=N;s++){
        for(;e<=N;e++){
            int sum = arr[e]-arr[s-1];
            if(sum<S) continue;
            else {
                mn = min(mn, e-s+1);
                break;
            }
        }
    }
    cout<<(mn==INT_MAX ? 0 : mn);
    return 0;
}