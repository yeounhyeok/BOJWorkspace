#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
char arr[85];
int main(){
    int n,s,sum;;cin>>n;
    for(int i=0;i<n;i++){
        s=0;sum=0;memset(arr,'\0',sizeof(arr));
        cin>>arr;
        for(int j=0;arr[j]!='\0';j++){
            if(arr[j]=='O'){
                s++;
                sum+=s;
            }
            else s=0;
        }
        cout<<sum<<'\n';
    }
}