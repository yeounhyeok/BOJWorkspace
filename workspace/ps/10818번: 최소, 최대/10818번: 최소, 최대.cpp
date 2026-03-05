#include <cstdio>
#include <iostream>

using namespace std;

int main(){
    int arr[1000001];
    int n, max=-1000001, min=1000001;

    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>arr[i];
        if(arr[i]>max) max=arr[i];
        if(arr[i]<min) min=arr[i];
    }    
    
    cout<<min<<' '<<max;
}