#include <cstdio>
#include <iostream>

using namespace std;

int main(){
    int n, j=1, num=0;
    char arr[100000]={};
    char arr2[1000]={};
    cin>>n;

    
    for(int i=1;i<=n;i++){
        for(int k=0;k<j;k++) arr[k]='\0';
        cin>>arr;
        for(j=1;arr[j]!='\0';j++){}
        arr2[2*i-1]=arr[0];
        arr2[2*i]=arr[j-1];
    }
    
    for(int i=1;i<=n;i++){
        cout<<arr2[2*i-1]<<arr2[2*i]<<endl;
    }

}