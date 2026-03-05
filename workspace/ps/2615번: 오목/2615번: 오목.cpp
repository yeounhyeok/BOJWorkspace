#include <iostream>
#include <cstdio>

using namespace std;

int a[19][19];
int arr[20][20];
int cnt, flag, m, n, i, j, toward, state;
//toward :: 1==R, 2==D, 3==RU, 4==RD

void scan(int x, int y){
    if(x==0||y==0||x==20||y==20) return;
    cnt++;
    if(cnt==1){
        if(a[x][y]==1) state=1;
        else if(a[x][y]==2) state=2;
        if(a[x][y+1]==state){
            toward=1;
            scan(x, y+1);
            cnt=1;
        }
        if(a[x+1][y]==state){
            toward=2;
            scan(x+1, y);
            cnt=1;
        }
        if(a[x+1][y+1]==state){
            toward=3;
            scan(x+1, y+1);
            cnt=1;
        }
        if(a[x-1][y+1]==state){
            toward=4;
            scan(x-1, y+1);
            cnt=1;
        }
    }
    if(cnt>=2&&cnt<=4){
        if(toward==1){
            if(a[x][y+1]==state){
                scan(x, y+1);
            }
        }
        if(toward==2){
            if(a[x+1][y]==state){
                scan(x+1, y);
            }
        }
        if(toward==3){
            if(a[x+1][y+1]==state){
                scan(x+1, y+1);
            }
        }
        if(toward==4){
            if(a[x-1][y+1]==state){
                scan(x-1, y+1);
            }
        }
    }
    if(cnt==5){
        if(toward==1){
            if(a[x][y+1]!=state&&a[i][j-1]!=state) flag = state;
        }
        if(toward==2){
            if(a[i-1][j]!=state&&a[x+1][y]!=state) flag = state;
        }
        if(toward==3){
            if(a[x+1][y+1]!=state&&a[i-1][j-1]!=state) flag = state;
        }
        if(toward==4){
            if(a[i+1][j-1]!=state&&a[x-1][y+1]!=state) flag = state;
        }
    }
    return;
}

int main(){
    for(i=1;i<=19;i++){
        for(j=1;j<=19;j++){
            scanf("%d", &a[i][j]);
        }
    }

    for(i=1;i<=19;i++){
        for(j=1;j<=19;j++){
            cnt=0;
            if(a[i][j]!=0) scan(i, j);
            if(flag!=0) break;
        }
        if(flag!=0) break;
    }


    if(flag!=0) printf("%d\n%d %d", flag, i, j);
    else if(flag==0) printf("0");

    return 0;
}

