#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int arr[102][102]={0}, n, a, b,cnt=0;
    cin>>n; 
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        for(int j=a;j<a+10;j++){
            for(int k=b;k<b+10;k++){
                arr[k][j]=1;
            }
        }
    }

    for(int i=1;i<=101;i++){
        for(int j=1;j<=101;j++){
            if(arr[i][j]) cnt++;
        }
    } 

    cout<<cnt;
    return 0;

}