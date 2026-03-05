#include <bits/stdc++.h>

using namespace std;

typedef struct myStruct{
    int age;
    string name;
}myStruct;

bool compare(myStruct p1, myStruct p2){
    return p1.age < p2.age;
}

int main(){
    int n;cin>>n;
    myStruct myList[100005];
    for(int i=0;i<n;i++) cin>>myList[i].age>>myList[i].name;
    stable_sort(myList, myList+n, compare);
    for(int i=0;i<n;i++) cout<<myList[i].age<<' '<<myList[i].name<<"\n";
    
    
    return 0;
}



