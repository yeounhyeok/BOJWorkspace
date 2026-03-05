#import <bits/stdc++.h>
using namespace std;int i,j,t=1;string s,r;main(){for(;;t++){cin>>s;if(s=="0")break;while(!(s.size()&1)){r="";for(i=0;i<s.size()-1;i++){char n=s[i++],w=s[i];for(j=48;j<n;j++)r+=w;}if(s==r)break;s=r;}cout<<"Test "<<t<<": "<<s<<'\n';}}
