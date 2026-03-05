#include <cstdio>
#include <iostream>

using namespace std;

int main(){
    int arr[1000];
    int n, a, sum=0;

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }    
    cin>>a;

    for(int i=1;i<=n;i++){
        if(arr[i]==a) sum++;
    }

    cout<<sum;
}