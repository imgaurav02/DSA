#include<bits/stdc++.h>

using namespace std;

class Stack{
public:
    int size;
    Node **ptr;
    int top;

    Stack(){
        size = 10;
        top=-1;
        ptr = new Node*[size];
    }

    void push(Node *key){
        if(top==size-1){
            cout<<"overflow";
        }
        else{
            top++;
            ptr[top] = key;
        }
    }

    Node* pop(){
        Node *temp=NULL;
        if(top==-1)
            return temp;
        temp = ptr[top];
        top--;
        return temp;

    }

    int StackEmpty(){
        return top==-1;
    }
};
class Stack1{
public:
    int size;
    int *ptr;
    int top;

    Stack1(){
        size = 10;
        top=-1;
        ptr = new int[size];
    }

    void push(int key){
        if(top==size-1){
            cout<<"overflow";
        }
        else{
            top++;
            ptr[top] = key;
        }
    }

    int pop(){
        int temp=0;
        if(top==-1)
            return temp;
        temp = ptr[top];
        top--;
        return temp;

    }

    int StackEmpty(){
        return top==-1;
    }
};