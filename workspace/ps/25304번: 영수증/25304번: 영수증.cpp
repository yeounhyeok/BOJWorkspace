#include <cstdio>
#include <iostream>

using namespace std;

int main(){
    unsigned long long int sum=0, tot=0;
    int count, a, b;
    cin>>tot;
    cin>>count;

    for(int i=1;i<=count;i++){
        scanf("%d %d", &a, &b);
        sum+=a*b;
    }
    if(tot==sum) printf("Yes");
    else printf("No");
    
}