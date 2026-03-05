#include <cstdio>
#include <iostream>

using namespace std;

int main(){
    char a[1000];
    int n,sum=0;
    cin>>n;
    cin>>a;
    for(int i=0;i<n;i++){
        sum+=(a[i]-'0');
    }
    cout<<sum;
}