#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int a, sum=0;
    for(int i=1;i<=5;i++){
        cin>>a;
        if(a<40) sum+=40;
        else sum+=a;
    }
    cout<<sum/5;
    
}