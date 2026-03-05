#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str;
bool arr[200]={false};
int cnt;

int main(){
    cin>>cnt;

    for(int j=1;j<=cnt;j++){
        cin>>str;
        for(int i=0;i<str.length();i++){
            arr[str[0]]=true;
            if(str[i+1]!=str[i]&&!arr[str[i+1]]){
                arr[str[i+1]]=true;
                continue;
            }
            if(str[i+1]!=str[i]&&arr[str[i+1]]){
                cnt--;
                j--;
                goto there;
            }
        }
        there:
        for(int k=0;k<200;k++) arr[k]=false;
    }
    
    cout<<cnt;
    return 0;
}