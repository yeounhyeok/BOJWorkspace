#include <bits/stdc++.h>
using namespace std;
int main(){
    unsigned long long int a, b, v, k;
    cin>>a>>b>>v;
    k=(v-a)/(a-b);
    while(1){
        if((a-b)*k+a>=v) break;
        else k++;
    }
    cout<<k+1;
    return 0;
}