#include <cstdio>
#include <iostream>

using namespace std;

int main(){
    int arr[101];
    int max=0, a=0;

    for(int i=1;i<=9;i++){
        cin>>arr[i];
        if(max<arr[i]){
            max=arr[i];
            a=i;
        }
    }    
    
    cout<<max<<'\n'<<a;
}