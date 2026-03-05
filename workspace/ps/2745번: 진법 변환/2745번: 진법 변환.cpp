#include <bits/stdc++.h>

using namespace std;

string str;
int b, sum=0;

int main(){
    cin>>str>>b;
    for(int i=0;i<str.length()-1;i++){
        if(str[i]>=65&&str[i]<=90) sum+=(pow(b, (str.length()-1-i))*(str[i]-55));
        else sum+=(pow(b, (str.length()-1-i))*(str[i]-48));
    }
    
    if(str[str.length()-1]>=65&&str[str.length()-1]<=90) sum+=(str[str.length()-1]-55);
    else sum+=(str[str.length()-1]-48);

    cout<<sum;
    return 0;
}