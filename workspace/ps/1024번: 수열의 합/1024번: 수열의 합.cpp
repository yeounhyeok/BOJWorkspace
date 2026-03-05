#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

ull N, L;

void print(ull a1, ull an){
    for(ull i=a1;i<=an;i++) cout<<i<<' ';
    cout<<'\n';
}

int main(){
    cin>>N>>L;
    for(ull i=0;;i++){
        if(i+L>100){
            cout<<-1<<'\n';
            return 0;
        }

        ull j = (N /(i+L)) - ((i+L-1) / 2); 
        
        if(j>1000000000){
            cout<<-1<<'\n';
            return 0;
        }
        if (N == (i+L)*(((i+L)+j-1) + j)/2){
            print(j, (i+L)+j-1);
            return 0;
        }
        
    }
}