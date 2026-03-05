#include <cstdio>
#include <iostream>

using namespace std;

int main(){
    char arr[1000]={'\0'};
    int arr2[1000]={0};
    cin>>arr;
    for(int i=97;i<=122;i++){
        for(int j=0;arr[j]!='\0';j++){
            if(arr[j]==i){
                arr2[i-97]=j;
                break;
            }
            else arr2[i-97]=-1;
        }
    }

    for(int i=0;i<=122-97;i++) cout<<arr2[i]<<' ';
}