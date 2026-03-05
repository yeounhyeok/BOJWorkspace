#include <bits/stdc++.h>

using namespace std;
int sum,arr[10];
int main(){
    for(int i=0;i<5;i++)cin>>arr[i];
    for(int i=0;i<5;i++)sum+=arr[i]*arr[i];
    cout<<sum%10;
}