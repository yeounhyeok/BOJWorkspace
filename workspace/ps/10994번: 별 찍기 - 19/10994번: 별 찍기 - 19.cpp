#include <bits/stdc++.h>

using namespace std;
int N, cnt=-1;
bool rev=false;

void revStar(int n){
    if(n==N+1) return;
    cnt--;
    
    for(int i=1;i<=cnt;i++) cout<<"* ";
    if(cnt!=-1) cout<<"* ";
    for(int i=1;i<=4*n-7;i++) cout<<" ";
    for(int i=1;i<=cnt;i++) cout<<" *";
    if(cnt!=-1) cout<<" *";
    
    cout<<"\n";

    for(int i=1;i<=cnt;i++) cout<<"* ";
    for(int i=1;i<=4*n-3;i++) cout<<"*";
    for(int i=1;i<=cnt;i++) cout<<" *";

    cout<<"\n";

    revStar(n+1);

    return;
}

void star(int n){
    if(n==0) return;
    cnt++;

    for(int i=1;i<=cnt;i++) cout<<"* ";
    for(int i=1;i<=4*n-3;i++) cout<<"*";
    for(int i=1;i<=cnt;i++) cout<<" *";

    cout<<"\n";

    if(n==1||rev==true){
        rev=true;
        revStar(n+1);
        return;
    }

    for(int i=1;i<=cnt;i++) cout<<"* ";
    if(cnt!=-1) cout<<"* ";
    for(int i=1;i<=4*n-7;i++) cout<<" ";
    for(int i=1;i<=cnt;i++) cout<<" *";
    if(cnt!=-1) cout<<" *";
    
    cout<<"\n";

    star(n-1);

    return;
}

int main(){
    cin>>N;
    star(N);
    return 0;
}