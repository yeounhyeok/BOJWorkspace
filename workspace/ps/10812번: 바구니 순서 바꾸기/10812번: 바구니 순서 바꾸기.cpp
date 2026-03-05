#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){

    int arr[1000]={0}, n, m, a, b, c;
    int arr2[1000]={0}, arr3[1000]={0};

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        arr[i]=i;
    } 
    
    for(int i=1;i<=m;i++){
        cin>>a>>b>>c;
        if(a==c) continue;

        for(int j=c;j<=b;j++) arr2[j]=arr[j];
        for(int j=c-1;j>=a;j--) arr3[j]=arr[j];
        for(int j=c;j<=b;j++) arr[j-(c-a)]=arr2[j];
        for(int j=c-1;j>=a;j--) arr[j+(b-c+1)]=arr3[j];
        

        for(int j=1;arr2[j]!=0;j++) arr2[j]=0;
        for(int j=1;arr3[j]!=0;j++) arr3[j]=0;
    }

    for(int i=1;i<=n;i++){
        cout<<arr[i]<<' ';
    } 
}