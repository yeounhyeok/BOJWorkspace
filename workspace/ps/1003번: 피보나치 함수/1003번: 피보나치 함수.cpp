#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

typedef struct dynamicProgramming{
    int a0=0;
    int a1=0;
}dp;

dp dt[100];

void fibo(int x){
    if(x==0||x==1) cout<<dt[x].a0<<' '<<dt[x].a1<<"\n";
    else{
        for(int i=2;i<=x;i++){
            dt[i].a0=dt[i-1].a0+dt[i-2].a0;
            dt[i].a1=dt[i-1].a1+dt[i-2].a1;    
        }
        cout<<dt[x].a0<<' '<<dt[x].a1<<"\n";
    }
}
 

int main(){
    dt[0].a0=1;
    dt[1].a1=1;
    int n, k;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>k;
        fibo(k);
    }
    return 0;
}


