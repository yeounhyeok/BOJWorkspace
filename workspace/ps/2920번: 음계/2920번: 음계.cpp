#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main(){
    int arr[9];
    for(int i=0;i<8;i++)cin>>arr[i];
    int d=arr[1]-arr[0];
    for(int i=2;i<8;i++){
        if(arr[i]-arr[i-1]==d)continue;
        else{
            cout<<"mixed";
            return 0;
        }
    }
    cout<<((d>0)?"ascending":"descending");
    return 0;
}