#include <cstdio>
#include <iostream>

using namespace std;

int main(){
    int a, i=0;
    char arr[1000]={};

    cin>>arr;
    for(i=1;arr[i-1]!='\0';i++){}
    cout<<i-1;
    return 0;

}