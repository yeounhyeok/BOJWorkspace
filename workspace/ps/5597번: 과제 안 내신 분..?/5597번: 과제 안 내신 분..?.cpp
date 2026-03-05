#include <cstdio>
#include <iostream>

using namespace std;

int main(){
    int n, m=0, arr[1000]={0};
    
    for(int i=1;i<=28;i++){
        cin>>n;
        arr[n] = n;
    }
    
    for(int i=1;i<=30&&m<2;i++){
        if(arr[i]==i) continue;
        else{
            cout<<i<<endl;
            m++;
        }
    }
    

}