#include <bits/stdc++.h>

using namespace std;

int main()
{  
    int n, k=2;
    cin>>n;
    for(int i=1;;i++){
        if(n-i>0){
            n-=i;
            k++;
        }
        else if(k%2!=0){
            cout<<n<<'/'<<k-n;
            break;
        }
        else{
            cout<<k-n<<'/'<<n;
            break;
        }
    }
    return 0;
}

