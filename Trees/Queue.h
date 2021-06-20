#include<bits/stdc++.h>
using namespace std;



//NOTE
// This is not DEQueue(Double Ended Queue) i mistakly named it as DEQueue it's a circuler queue program

class Node{
public:
    Node *lchild;
    int data;
    Node *rchild;
};



class DEqueue{
public:
    int size;
    int front;
    int rear;
    Node **Q;

// default contructor
DEqueue(){
    front = rear = 0;
    size = 10;
    Q = new Node*[size];
}

// parameterized contructor
DEqueue(int size){
    front = rear = 0;
    this->size = size;
    Q = new Node*[size];
}

void Enqueue(Node *x);
Node* Delqueue();
int isEmpty();
};

int DEqueue::isEmpty(){
    return front==rear;
}

void DEqueue::Enqueue(Node *x){
    if((rear+1)%size == front)
        cout<<"Queue Is Full"<<endl;
    else{
        rear = (rear+1)%size;
        Q[rear] = x;
    }
}

Node* DEqueue::Delqueue(){
    Node *x=NULL;
    if(front==rear){
        cout<<"Queue is Empty";
        return x;
    }
    else{
        front++;
        x = Q[front];
        return x;
    }
}

