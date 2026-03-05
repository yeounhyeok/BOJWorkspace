#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str;
string str2;
char* arr[10]={"A+", "A0", "B+", "B0", "C+", "C0", "D+", "D0", "P", "F"};

double a=0, sum=0, alla=0;

int main(){
    
    for(int i=1;i<=20;i++){
        cin>>str>>a>>str2;
        for(int j=0;j<10;j++){
            if((str2==arr[j]&&str2!="P")){
                if(str2!="F"){
                    sum+=(9-j)*0.5*a;
                }
                alla+=a;
            }
        }
    }

    printf("%f", sum/alla);
    return 0;
}