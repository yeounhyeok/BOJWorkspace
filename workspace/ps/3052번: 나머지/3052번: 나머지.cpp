#include <cstdio>
#include <iostream>

using namespace std;

int main(){
    int arr[100]={0};
    int a, j, tot=0;
    bool wasZero = false;

    for(int i=1;i<=10;i++){
        cin>>a;
        if(a%42==0 && wasZero==false){
            tot++;
            wasZero = true;
        }
        else{
            for(j=1;j<=10 && a%42 && arr[j]!=a%42;j++)
            if(j==10){
                tot++;
                arr[i]=a%42;
            }
        }    
    }    
    
    cout<<tot;

    return 0;
}