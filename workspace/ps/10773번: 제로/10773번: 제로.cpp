#include <iostream>
#include<stack>
#pragma warning(disable:4996)
using namespace std;

int main()
{
    stack<int> s;
    int n, tmp;
    cin>>n;
    
    for(int i=0;i<n;i++){
        cin>>tmp;
        if(tmp!=0) s.push(tmp);
        else s.pop();
    }
    
    int sum=0;
    
    while(s.size()!=0){
        sum+=s.top();
        s.pop();
    }
    
    cout<<sum;
    
    return 0;
}
