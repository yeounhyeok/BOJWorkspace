#include <bits/stdc++.h>
#include <algorithm>


using namespace std;

int main(){
    int x, y ,w , h;
    cin>>x>>y>>w>>h;
    int inner[4] = {w-x, h-y, x, y};
    sort(inner, inner+4);
    if(x<=w&&y>=h) cout<<y-h;
    if(x>=w&&y<=h) cout<<x-w;
    if(x>=w&&y>=h) cout<<sqrt(pow((x-w), 2)+pow((y-h), 2));
    if(x<=w&&y<=h) cout<<inner[0];

    return 0;
}