#include <bits/stdc++.h>
using namespace std;

bool arr[21];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, tmp;cin>>n;

    for(int i=0;i<n;i++){
        string s="";cin>>s;
        if(s=="add"){
            cin>>tmp;
            arr[tmp]=true;
        }
        if(s=="remove"){
            cin>>tmp;
            arr[tmp]=false;
        }
        if(s=="check"){
            cin>>tmp;
            if(arr[tmp]) cout<<1<<'\n';
            else cout<<0<<'\n';
        }
        if(s=="toggle"){
            cin>>tmp;
            arr[tmp]=!arr[tmp];
        }
        if(s=="all"){
            for(int j=0;j<=20;j++) arr[j]=true;
        }
        if(s=="empty"){
            for(int j=0;j<=20;j++) arr[j]=false;
        }
    }
}