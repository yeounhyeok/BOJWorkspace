#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

typedef struct myNode{
    myNode *front=nullptr;
    int data;
    myNode *rear=nullptr;
}myNode;

myNode* currentNode;
myNode *headNode=new myNode;
int n=1, arr[55], cnt=0; 

void addNode(){
    myNode *newNode = new myNode;
    newNode->data = n;
    newNode->front = currentNode;
    currentNode->rear = newNode;
    currentNode = newNode; //자동으로 넘어간다네.
    n++;
}

void nextNode(){
    currentNode=currentNode->rear;
}

void previousNode(){
    currentNode=currentNode->front;
}

void front_pop(){
    myNode *Nnode=headNode->rear, *Pnode=headNode->front;
    Pnode->rear=Nnode;
    Nnode->front=Pnode;
    headNode=Nnode;
}

void to_left(){
    headNode=headNode->rear;
    cnt++;
}

void to_right(){
    headNode=headNode->front;
    cnt++;
}

int main(){

    int N, M;
    cin>>N>>M;

    headNode->data=n;
    n++;
    currentNode=headNode;
    
    for(int i=2;i<=N;i++) addNode(); //리스트 노드 생성

    currentNode->rear=headNode;  
    headNode->front=currentNode; // 원형 리스트로 !

    for(int i=0;i<M;i++) cin>>arr[i];
    
    for(int i=0;arr[i]!=0;i++){
        if(arr[i]==headNode->data){
            front_pop();
        }
        else{
            int l=0, r=0;
            myNode *lNode = headNode;
            myNode *rNode = headNode;
            while(arr[i]!=lNode->data){
                l++;
                lNode=lNode->rear;
            }
            while(arr[i]!=rNode->data){
                r++;
                rNode=rNode->front;
            }
            if(l<r) for(int j=1;j<=l;j++) to_left();
            else for(int j=1;j<=r;j++) to_right();
            front_pop();
            }
        }
    cout<<cnt;
    
    return 0;
}