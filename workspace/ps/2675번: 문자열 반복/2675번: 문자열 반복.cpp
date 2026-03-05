#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){
    int n, a;
    char arr[10000]="";

    cin>>n;
    for(int k=1;k<=n;k++){
        cin>>a>>arr;
        for(int i=0;arr[i]!='\0';i++){
            for(int j=1;j<=a;j++) cout<<arr[i];
        }
        cout<<endl;
    }

}