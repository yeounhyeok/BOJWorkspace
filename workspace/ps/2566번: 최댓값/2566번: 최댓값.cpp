#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int arr1[101][101]={0}, arr2[101][101]={0};
    int n, m, max=0, a=1, b=1;
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            cin>>arr1[i][j];
            if(max<arr1[i][j]){
                max=arr1[i][j];
                a=i;
                b=j;
            }
        }
    }

    cout<<max<<endl<<a<<' '<<b;
    
    return 0;
}