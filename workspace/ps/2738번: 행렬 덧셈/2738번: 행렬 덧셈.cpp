#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int arr1[101][101]={0}, arr2[101][101]={0};
    int n, m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr1[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr2[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            arr2[i][j]+=arr1[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<arr2[i][j]<<' ';
        }
        cout<<endl;
    }

    return 0;
}