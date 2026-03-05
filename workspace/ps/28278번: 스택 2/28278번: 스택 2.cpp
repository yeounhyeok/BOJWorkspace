#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    stack<int> s;
    int n, a;cin>>n;
    while(n--){
        cin>>a;
        if(a==1){
            cin>>a;
            s.push(a);
        }
        else if(a==2||a==5){
            if(!s.empty()){
                cout<<s.top()<<'\n';
                if(a==2)s.pop();
            }
            else cout<<-1<<'\n';
        }
        else if(a==3) cout<<s.size()<<'\n';
        else cout<<s.empty()<<'\n';
    }
    return 0;
}