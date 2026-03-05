#include <bits/stdc++.h>

using namespace std;

char arr[55];

int main(){
    int n, x=0;cin>>n;
    for(int j=0;j<n;j++){
        x=0;
        scanf("%s", &arr);
        
        for(int i=0;arr[i]!='\0';i++){
            if(arr[i]=='(') x++;
            else if(arr[i]==')') x--;

            if(x<0) break;
        }

        if(x==0) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}