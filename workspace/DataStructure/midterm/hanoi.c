#include<stdio.h>
void hanoi(int n,int f,int t,int v){
    if(!n)return;
    hanoi(n-1,f,v,t);
    printf("%c %c\n",f+'A',t+'A');
    hanoi(n-1,v,t,f);
}
int main(){
    int n;scanf("%d",&n);
    printf("%d\n",(1<<n)-1);
    hanoi(n,0,2,1);
}