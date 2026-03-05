#include <iostream>
using namespace std;

#define M 1000
int g[M+1];

int min(int s) {
    for (int i=s;i<=M;i++)
        if (g[i])
            return i;
    return 0;
}

int main() {
    int n,x;
    cin>>n;
    for (int i=0; i<n; i++)
        cin>>x,g[x]++;
    int m,t,h=-2;
    while(n--) {
        m = min(0);
        if (m==h+1)
            m = min(m+1);
        else {
            t = min(m+1);
            if (t&&!min(m+2)) m = t;
        }
        h = m;
        cout<<m<<" ",g[m]--;
    }
}