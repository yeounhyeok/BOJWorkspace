#include <cstdio>
#include <iostream>

using namespace std;

int main(){
    long double sum=0, arr[1001]={0};
    long double n, a, max=0;
    cin>>n;

    for (int i = 1; i < n+1; i++){
        cin>>a;
        if(max<a) max=a;
        arr[i]=a;
    }

    for(int i=1;i<n+1;i++){
        sum+=arr[i]/max*100;
    }
    cout<<sum/n;
    

}