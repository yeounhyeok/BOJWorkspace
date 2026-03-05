#include <bits/stdc++.h>
using namespace std;
int N, r, c, cnt;

void Z(int size, int row, int col, int num){
    if(row==r&&col==c){
        cout<<cnt<<endl;
        return;
    }
    else if(row<=r&&row+size>r&&col<=c&&col+size>c){
        Z(size/2, row, col, 0);
        return;
    }
    else {
        cnt+=size*size;
        if(num==0) Z(size, row, col+size, 1);
        else if(num==1) Z(size, row+size, col-size, 2);
        else if(num==2) Z(size, row, col+size, 0);
        return;
    }
    

    
}

int main(){
    cin>>N>>r>>c;
    Z(pow(2, N), 0, 0, 0);
    return 0;
}