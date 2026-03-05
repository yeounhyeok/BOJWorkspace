#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int arr[10000];
int main(){  
    int n, m, cnt=1;
    cin>>n>>m;
    for(int i=1;n/i!=0;i++){
        if(n%i==0){
            arr[cnt]=i;
            cnt++;
        }
    }
    if(arr[m]!='\0') cout<<arr[m];
    else cout<<'0';
    
    return 0;
}

