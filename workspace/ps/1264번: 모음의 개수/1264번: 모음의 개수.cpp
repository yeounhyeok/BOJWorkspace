#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string str="";
    int n=0;
    while(1){
        getline(cin, str);
        if(str=="#") break;
        for(int i=0;str[i]!='\0';i++){
            if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' || str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U') n++;
        }
        cout<<n<<endl;
        n=0;
    }
}