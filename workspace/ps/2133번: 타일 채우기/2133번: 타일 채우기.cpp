#import<iostream>
int n,d[31]={1},i,j;main(){std::cin>>n;for(i=2;i<=n;i+=2){d[i]=d[i-2]*3;for(j=i-4;j>=0;j-=2)d[i]+=d[j]*2;}std::cout<<d[n];}