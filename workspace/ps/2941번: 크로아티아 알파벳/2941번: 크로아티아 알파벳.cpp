#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str="";
int cnt=0;

void countingStar(string s){
    if(str.find(s)<=21000000){
            str.replace(str.find(s), s.length(), "AA");
            cnt++;
        }
}

int main(){
    cin>>str;
    int n=str.length();
    for(int i=0;i<=n;i++){
        if(str.find("dz=")<=210000000){
            str.replace(str.find("dz="), 3, "AAA");
            cnt++;
            continue;
        }
        countingStar("c=");
        countingStar("c-");
        countingStar("d-");
        countingStar("lj");
        countingStar("nj");
        countingStar("s=");
        countingStar("z=");
    }

    
    
    for(int i=0;i<str.length();i++){
        if(str[i]>=97&&str[i]<=122) cnt++;
    }

    cout<<cnt;

    return 0;

}