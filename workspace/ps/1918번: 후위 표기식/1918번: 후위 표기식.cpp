#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;cin>>s;
    stack<char> st;
    unordered_map<char, int> m;
    m['+']=1;m['-']=1;m['*']=2;m['/']=2;m['(']=3;m[')']=3;

    for(auto i:s){
        if(i>='A' && i<='Z') cout<<i;
        else if(!st.empty()){
            while(!st.empty() && i==')'){
                if(st.top()!='(' && st.top()!=')') cout<<st.top();
                st.pop();
                if(!st.empty() && st.top()=='('){
                    st.pop();
                    break;
                }
            }
            while(!st.empty() && m[i]<=m[st.top()] && st.top()!='('){
                if(st.top()!='(' && st.top()!=')')cout<<st.top();
                st.pop();
            }
            if(i!=')') st.push(i);
        }
        else{
            st.push(i);
        }
        
    }
    while(!st.empty()) {
        if(st.top()!='(' && st.top()!=')') cout<<st.top();
        st.pop();
    }
    return 0;   
}