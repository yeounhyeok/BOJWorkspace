#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    char arr1[101][101]={'\0'};
    string str="";
    for(int i=0;i<5;i++){
        for(int j=0;str[j]!='\0';j++) str[j]='\0';
        cin>>str;
        for(int j=0;str[j]!='\0';j++) arr1[i][j]=str[j];
    }
    
    for(int i=0;i<16;i++){
        for(int j=0;j<5;j++){
            if(arr1[j][i]!='\0') cout<<arr1[j][i];
        }
    }

    return 0;
}