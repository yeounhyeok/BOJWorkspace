#include <bits/stdc++.h>

using namespace std;

double v[100005][2];

double linear_f(double a[], double b[]){
    return (a[1]-b[1])/(a[0]-b[0]);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;cin>>n;
    for(int i=0;i<n;i++) cin>>v[i][0]>>v[i][1];
    
    int idx, m;cin>>m;
    double k;
    for(int i=0;i<m;i++){
        cin>>k;

        int high=n-1, low=0, mid;
        while(high>=low){
            mid = (low+high)/2;
            if(k<v[mid][0]) high = mid-1;
            else low = mid + 1;
        }
        if(v[mid][0]<k) mid++;

        double d = linear_f(v[mid-1], v[mid]);
        
        if(d>0) cout<<1<<'\n';
        else if(d<0) cout<<-1<<'\n';
        else cout<<0<<'\n';
    }
    return 0;
}