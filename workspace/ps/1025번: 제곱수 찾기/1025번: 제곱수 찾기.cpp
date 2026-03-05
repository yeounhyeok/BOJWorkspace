#include <bits/stdc++.h>

using namespace std;

int arr[15][15], maxVal=-1;
int n, m, d1, d2, k1, k2, M, cnt;
string str;
size_t a;

bool isinArr(int x, int y){
    if(x<=n&&y<=m&&x>=1&&y>=1) return true;
    else return false;
}


int main(){
    bool exist=false;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>str;
        for(int j=1;j<=m;j++){
            arr[i][j]=str[j-1]-'0';
        }
    }

    M=max(n,m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){ //위치


            for(d1=(-1)*M+1;d1<=M-1;d1++){ //행방향
                    for(d2=(-1)*M+1;d2<=M-1;d2++){ //열방향
                        str="";
                        if(d1==0&&d2==0){
                            if(isinArr(i+d1*k1, j+d2*k1)==true){
                                str+=to_string(arr[i+d1*k1][j+d2*k1]);
                                int is=sqrt(stoi(str));
                                if(is*is==stoi(str)&&stoi(str)>maxVal) maxVal=stoi(str);
                            }
                            continue;
                        }
                        for(k1=0;k1<M;k1++){
                            if(isinArr(i+d1*k1, j+d2*k1)==true){
                                str+=to_string(arr[i+d1*k1][j+d2*k1]);
                                int is=sqrt(stoi(str));
                                if(is*is==stoi(str)&&stoi(str)>maxVal) maxVal=stoi(str);
                            }
                            else{
                                if(str=="") break;
                                int is=sqrt(stoi(str));
                                if(is*is==stoi(str)&&stoi(str)>maxVal) maxVal=stoi(str);
                                break;  
                            }
                        }
                    }
                


                }


            }
        }
    
    cout<<maxVal;
    return 0;
}