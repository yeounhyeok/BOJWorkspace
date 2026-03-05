#include <cstdio>
#include <iostream>

using namespace std;

int main(){
    int i, j, n;
    cin>>n;
    n=2*n-1;

    for(i=1;i<=n;i+=2){  //별몇개
        for(j=1;j<=(n-i)/2;j++){  //왼쪽 공백
            cout<<' ';
        }
        for(j=1;j<=i;j++){  //별 개수
            cout<<"*";
        }
    cout<<endl;
    }
    
    for(i=n-2;i>=1;i-=2){  //별몇개
        for(j=(n-i)/2;j>=1;j--){  //왼쪽 공백
            cout<<' ';
        }
        for(j=i;j>=1;j--){  //별 개수
            cout<<"*";
        }
    cout<<endl;
    }

    return 0;

}