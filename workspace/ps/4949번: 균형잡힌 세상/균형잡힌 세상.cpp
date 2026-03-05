#include<bits/stdc++.h>
using namespace std;

string s;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    while(1){
        getline(cin, s);
        if(s==".") break;

        bool flag=1;
        stack<char> st;

        for(auto i:s){
            if(i=='(' || i=='[') st.push(i);
            else if(i==')' || i==']'){
                if(!st.size() || abs(i-st.top()) > 2){
                    flag=0;
                    break;
                }
                st.pop();
            }
        }
        
        cout<<(flag&&!st.size() ? "yes" : "no")<<'\n';

    }

    return 0;
}