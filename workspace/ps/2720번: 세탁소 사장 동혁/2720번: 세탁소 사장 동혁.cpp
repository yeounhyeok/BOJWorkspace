#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int n, a, b, c, d, x;

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        a=x/25;
        x%=25;
        b=x/10;
        x%=10;
        c=x/5;
        x%=5;
        d=x;
        cout<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
    }
    
    return 0;
}
