#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int a[10000], b[10000];
    int i=0;

    a[0]=-1;
    b[0]=-1;

    for(i=0;a[i]!=0||b[i]!=0;){
        i++;
        cin>>a[i]>>b[i];
    }

    for(i=1;a[i]!=0||b[i]!=0;i++){
        if(i!=1) cout<<"\n";
        if(a[i]>b[i]) cout<<"Yes";
        else cout<<"No";
    }

    return 0;
}
