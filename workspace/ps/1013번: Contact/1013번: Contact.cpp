#include <bits/stdc++.h>
using namespace std;

int main(){  
    int n;cin>>n;

    for(int i=0;i<n;i++){
        string s="";int tmp;
        cin>>s; s.append("22");

        for(int j=0;;){
            if(s[j]=='0' && s[j+1]=='1'){
                j+=2;
                continue;
            }
            else if(s[j]=='1' && s[j+1]=='0' && s[j+2]=='0'){
                j+=3;
                while(s[j]=='0') j++;
                while(s[j]=='1') j++;
                if(j>2 && s[j-2]=='1' && s[j-1]=='1' && s[j]=='0' && s[j+1]=='0') j--;
            }
            else{
                if(j>1 && s[j-1]=='1' && s[j]=='2') cout<<"YES"<<'\n';
                else cout<<"NO"<<'\n';
                break;
            }
        }
    }
    return 0;
}

