#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

string str;

int main(){
    unsigned long long int n, temp;
    int b;
    cin>>n>>b;
    while(n!=0){
        temp=n;
        there:
        if(temp<b){
            if(temp<10) str+=(temp+'0');
            else str+=(temp+55);
        }
        else{
            temp%=b;
            goto there;
        }
        n/=b;
    }
    reverse(str.begin(), str.end());
    cout<<str;
    return 0;
}

