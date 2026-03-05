#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int arr[10000];
int main(){  
    int n, m, cnt, sum=0;
    cin>>m;
    for(int j=1;j<=m;j++){
        cnt=1;
        cin>>n;
        for(int i=1;n/i!=0;i++){
            if(n%i==0){
                arr[cnt]=i;
                cnt++;
            }
        }
        if(cnt==3&&n!=1) sum++;
    }
    cout<<sum;
    return 0;
}

