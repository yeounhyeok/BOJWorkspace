#include <bits/stdc++.h>
using namespace std;

int main(){
    double n;cin>>n;
    int c = n/1.1;
    if(c%100!=0) c++;
    cout<<c<<'\n';
    return 0;
}