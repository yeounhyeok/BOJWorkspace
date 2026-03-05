#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

typedef struct myNode{
    myNode *front=nullptr;
    int data;
    myNode *rear=nullptr;
}myNode;

myNode* currentNode;
int n=1; 

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

void deleteNode(){
    myNode *previous = currentNode->front;
    previous->rear=currentNode->rear;
    nextNode();
    currentNode->front=previous;
    previousNode();
}

int main(){

    int N, K;
    cin>>N>>K;

    myNode *headNode=new myNode;
    headNode->data=n;
    n++;
    currentNode=headNode;
    
    for(int i=2;i<=N;i++) addNode(); //리스트 노드 생성
    
    currentNode->rear=headNode;  
    headNode->front=currentNode; // 원형 리스트로 !

    cout<<'<';
    for(int i=1;i<=N-1;i++){
        for(int j=1;j<=K;j++) nextNode();
        cout<<currentNode->data<<", ";
        deleteNode();
    }
    for(int j=1;j<=K;j++) nextNode();
    cout<<currentNode->data<<'>';
 /*   
    cout<<headNode->data<<endl;  //출력
    currentNode=headNode->rear;
    for(int i=2;i<=7;i++){
        cout<<currentNode->data<<endl;
        nextNode();
    }
*/
    return 0;
}