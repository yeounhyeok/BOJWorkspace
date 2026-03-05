#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int min=1000000;
    int a[10]={0};
    for(int i=1;i<=5;i++){
        cin>>a[i];
    }
    for(int i=1;i<=3;i++){
        for(int j=4;j<=5;j++){
            if(a[i]+a[j]<min) min=a[i]+a[j];
        }
    }

    cout<<min-50;
    
}