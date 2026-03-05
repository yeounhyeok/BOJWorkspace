#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int arr[10000];
int main(){  
    int n, m, cnt, sum;
    while(1){
        sum=0;
        cnt=1;
        cin>>n;
        if(n==-1) break;
        for(int i=1;n/i!=0;i++){
            if(n%i==0){
                arr[cnt]=i;
                cnt++;
            }
        }
        for(int i=1;i<=cnt-2;i++) sum+=arr[i];
        
        if(sum==n){
            cout<<n<<" = ";
            for(int i=1;i<=cnt-3;i++) cout<<arr[i]<<" + ";
            cout<<arr[cnt-2]<<endl;
        }
        else cout<<n<<" is NOT perfect."<<endl;
    }
    return 0;
}

