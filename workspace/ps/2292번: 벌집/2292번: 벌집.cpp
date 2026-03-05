#include <bits/stdc++.h>

using namespace std;

int main()
{  
    unsigned long long int n, k=0;
    cin>>n;
    if(n==1){
        cout<<'1';
        return 0;
    }
    for(int i=1;;i++){
        k+=6*i;
        if(n<=k+1&&n>=k+1-6*i){
            cout<<i+1;
            break;
        }
    }
    return 0;
}

