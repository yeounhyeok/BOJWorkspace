#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int arr[10000];
int main(){  
    int n, m, cnt=1, sum=0, k;
    bool first=true;
    cin>>n>>m;
    while(n<=m){
        cnt=1;
        for(int i=1;n/i!=0;i++){
            if(n%i==0){
                arr[cnt]=i;
                cnt++;
            }
        }
        if(cnt==3&&n!=1){
            sum+=n;
            if(first){
                first=false;
                k=n;
            }
        }
        n++;
    }
    if(sum==0) cout<<-1;
    else cout<<sum<<endl<<k;
    
    return 0;
}

