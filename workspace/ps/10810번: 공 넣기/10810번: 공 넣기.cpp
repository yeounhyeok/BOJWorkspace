#include <cstdio>
#include <iostream>

using namespace std;

int main(){
    int m, n, i, j, k, arr[1000]={0};
    cin>>n>>m;

    for(int a=1;a<=m;a++){
        cin>>i>>j>>k;
        for(int b=i;b<=j;b++){
            arr[b]=k;
        }
    }

    for(int a=1;a<=n;a++){
        cout<<arr[a]<<' ';
    }
}