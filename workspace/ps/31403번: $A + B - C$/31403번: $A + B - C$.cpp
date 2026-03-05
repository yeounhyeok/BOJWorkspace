#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a[3];
    for(int i=0;i<3;i++){
        cin>>a[i];
    }
    string b="";
    b.append(to_string(a[0]));
    b.append(to_string(a[1]));
    int c = stoi(b)-a[2];
    cout<<a[0]+a[1]-a[2]<<endl;
    cout<<c;
    return 0;
}