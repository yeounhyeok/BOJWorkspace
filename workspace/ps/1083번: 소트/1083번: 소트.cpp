#include<bits/stdc++.h>
using namespace std;

int n, s, tmp, cnt, maxnum, maxidx;
int arr[51];

int main (){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)cin>>arr[i];
    cin>>s;

    for(int i=0;i<n-1 && s!=0;i++){
        cnt=0;
        maxnum=arr[i];
        maxidx=i;
        for(int j=i+1;j<n && cnt<s;j++,cnt++){
            if(maxnum<arr[j]){
                maxnum=arr[j];
                maxidx=j;
            }
        }
        int j=maxidx;
        if(maxidx > i){
            while(j!=i){
                tmp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=tmp;
                j--;
            }
        }
        s-=(maxidx-i);
    }   
    for(int i=0;i<n;i++)cout << arr[i] << " ";
    return 0;
}
