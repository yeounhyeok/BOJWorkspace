#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    char arr[1000000]="";
    int ascii[200]={0}, count[200]={0}, max=0, maxPoint, maxCount=1;
    bool maxAlreadyExist = false;
    for(int i=65;i<=122;i++) ascii[i]=i;

    cin>>arr;

    for(int i=0;arr[i]!='\0';i++){
        for(int j=65;j<=122;j++){
            if(arr[i]==ascii[j]) count[j]++;
        }
    }

    for(int i=97;i<=122;i++){
        count[i-32]+=count[i];
    }

    for(int i=65;i<=90;i++){
        if(max==count[i]&&maxAlreadyExist==true){
            maxCount++;
        }
        if(max<count[i]){
            maxCount=1;
            max=count[i];
            maxPoint=i;
            maxAlreadyExist=true;
        }
    }

    char ans=maxPoint;

    if(maxCount==1) cout<<ans;
    else cout<<'?';

    return 0;
}