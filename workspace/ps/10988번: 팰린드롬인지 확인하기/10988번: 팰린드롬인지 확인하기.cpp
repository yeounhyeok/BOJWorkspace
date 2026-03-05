#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    char arr[1000]="";
    int num, ans=1;
    cin>>arr;
    for(num=0;arr[num]!='\0';num++){}

    for(int i=0;i<num/2;i++){
        if(arr[i]!=arr[num-1-i]){
            ans--;
            break;
        }
    }
    
    cout<<ans;

}