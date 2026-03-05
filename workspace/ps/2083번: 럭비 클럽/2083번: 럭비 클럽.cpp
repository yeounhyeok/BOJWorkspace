#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string str="";
    int age, weight;
    while(1){
        cin>>str>>age>>weight;
        if(str=="#"&&!age&&!weight) break;
        if(age>17||weight>=80) cout<<str<<" Senior"<<endl;
        else cout<<str<<" Junior"<<endl;
    }
}