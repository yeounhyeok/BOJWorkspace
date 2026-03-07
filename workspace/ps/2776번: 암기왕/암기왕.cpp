#include<bits/stdc++.h>
#define MX 1000005
using namespace std;

int T, N, M, arr1[MX], arr2[MX];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>T;
    while(T--){
        cin>>N;
        for(int i=0;i<N;i++) cin>>arr1[i];
        cin>>M;
        for(int i=0;i<M;i++) cin>>arr2[i];
        sort(arr1, arr1+N);
        for(int i=0;i<M;i++){
            int s=-1, e=N, m;
            while(s+1<e){
                m=(s+e)/2;
                if(arr1[m]<=arr2[i]) s=m;
                else e=m;
            }
            cout<<(arr2[i]==arr1[s] ? 1:0)<<'\n';
        }
        
    }
    
    return 0;
}