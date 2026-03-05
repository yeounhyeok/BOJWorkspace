#include <bits/stdc++.h>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    int arr0[100005], arr1[100005];
    int n;cin>>n;
    for(int i=0;i<n;i++) cin>>arr0[i];
    
    sort(arr0, arr0+n);
    
    int m;cin>>m;
    for(int i=0;i<m;i++) cin>>arr1[i];
    
    int L=0, R=n-1, M;
    for(int i=0;i<m;i++){
        L=0; R=n-1;
        while(L<=R){
            M=(L+R)/2;
            if(arr0[M]>arr1[i]) R=M-1;
            else if(arr0[M]<arr1[i])L=M+1;
            else {
                cout<<1<<'\n';
                goto there;
            }
        }
        //if(arr0[L]==arr1[i]||arr0[R]==arr1[i]) cout<<1<<'\n';
        cout<<0<<'\n';
        there:;
    }
    
    return 0;
}
