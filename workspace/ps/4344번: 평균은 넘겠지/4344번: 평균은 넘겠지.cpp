#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int a[1001];
int main(){
    int c, n;
    
    double count=0, sum=0;
    cin>>c;
    for(int i=1;i<=c;i++){
        sum=0;
        count=0;
        cin>>n;
        for(int j=1;j<=n;j++){
            cin>>a[j];
            sum+=a[j];
        }
        for(int j=1;j<=n;j++){
            if(a[j]>sum/n) count++;
        }

        printf("%.3f%\n", (count/n)*100);
    }

    return 0;
}