#include <cstdio>
#include <iostream>

using namespace std;

int main(){
    int n, m, arr[1000]={0};
    int a, b, c;
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        arr[i]=i;
    }

    for(int i=1;i<=m;i++){
        cin>>a>>b;
        c=arr[a];
        arr[a]=arr[b];
        arr[b]=c;
    }

    for(int i=1;i<=n;i++){
        cout<<arr[i]<<' ';
    }
}