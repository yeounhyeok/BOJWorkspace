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
        if((b-a)%2==0) for(int j=0;j<(b-a)/2;j++) swap(arr[a+j], arr[b-j]);
        else for(int j=0;j<=(b-a)/2;j++) swap(arr[a+j], arr[b-j]);
            
    }

    for(int i=1;i<=n;i++){
        cout<<arr[i]<<' ';
    }
}