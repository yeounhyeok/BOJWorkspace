#import<cstdio>
int i,a,b,c,n;main(){a=1;b=2;scanf("%d",&n);for(i=3;i<=n;i++){c=(a+b)%15746;a=b;b=c;};printf("%d",(n==1)?1:b%15746);}