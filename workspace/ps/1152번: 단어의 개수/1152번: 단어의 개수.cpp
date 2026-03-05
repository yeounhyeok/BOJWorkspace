#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(){
    //char arr[1000]="";
    string arr;
    int n=0, sum=0;
    bool isFirst=true;

    getline(cin, arr);

    for(int i=0;arr[i]!='\0';i++){
        if(isFirst && arr[i]==' '){
            continue;
        }
        if(!n && (arr[i]!=' ' || i!=arr.length()-1)){
            n++;
            isFirst=false;
        }
        if(n && (arr[i]==' ' || i==arr.length()-1)){
            n--;
            sum++;
        }

    }

    cout<<sum;

}