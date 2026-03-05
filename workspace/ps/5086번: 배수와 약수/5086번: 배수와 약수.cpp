#include <bits/stdc++.h>

using namespace std;

int main()
{  
    int n, m;
    while(1){
        cin>>n>>m;
        if(n==0&&m==0) break;
        if(n%m==0) cout<<"multiple"<<endl;
        else if(m%n==0) cout<<"factor"<<endl;
        else cout<<"neither"<<endl;
    }
    
    
    return 0;
}

