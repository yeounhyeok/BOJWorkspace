#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

string a, b;
char c[100001];

int n1, n2, k, cnt;

int main(){
    cin>>a>>b;
    if(a.length()>b.length()){
        n1=b.length();
        n2=a.length();
    }
    else{
        n1=a.length();
        n2=b.length();
    }

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    for(int i=0;i<n1;i++){
        if((a[i]-'0')+(b[i]-'0')+k<10){
            c[i]=a[i]+b[i]-'0'+k;
            k=0;
        }
        else{
            c[i]=a[i]+b[i]-'0'-10+k;
            k=1;
        }
    }

    for(int i=n1;i<n2;i++){
        if(a.length()>b.length()){
            if(a[i]+k-'0'<10){
                c[i]=a[i]+k;
                k=0;
            }
            else{
                c[i]=a[i]+k-10;
                k=1;
            }
        }
        else{
            if(b[i]+k-'0'<10){
                c[i]=b[i]+k;
                k=0;
            }
            else{
                c[i]=b[i]+k-10;
                k=1;
            }
        }
    }
     
    for(cnt=0;c[cnt]!='\0';cnt++);
    if(k){
        c[cnt]=k+'0';
        cnt++;
    }
    for(cnt--;cnt>=0;cnt--) cout<<c[cnt];

    return 0;
}