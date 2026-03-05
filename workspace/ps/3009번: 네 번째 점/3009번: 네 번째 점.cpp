#include <bits/stdc++.h>
#include <algorithm>


using namespace std;
int arr1[1001];
int arr2[1001];

int main(){
    int a;
    for(int i=1;i<=3;i++){
        cin>>a;
        arr1[a]++;
        cin>>a;
        arr2[a]++;
    }

    int x, y;
    for(int i=0;i<=1000;i++){
        if(arr1[i]%2!=0) x=i;
        if(arr2[i]%2!=0) y=i;
    }
    cout<<x<<' '<<y;
    return 0;
}