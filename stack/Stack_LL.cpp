#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;
};

class Stack{
private:
    Node *top;
public:
    void push(int x);
    int pop();
    void display();
    int stackTop();
    Stack(){
        top = NULL;
    }
};


void Stack::push(int x){
    Node *t = new Node;
    if(t==NULL){
        cout<<"Stack Overflow";
    }
    else{
        t->data = x;
        t->next =top;
        top = t;
    }

}

int Stack::pop(){
    int x=-1;
    if(top==NULL){
        cout<<"Stack Underflow";
        return x;
    }
    else{
        Node *t=top;
        x = top->data;
        top=top->next;
        delete t;
        return x;
    }
}

int Stack::stackTop(){
    if(top==NULL)
        return -1;
    return top->data;
}

void Stack::display(){
    Node *t = top;
    while(t){
        cout<<t->data<<" ";
        t = t->next;
    }
}
int main(){
    Stack st;
    int check=1;
    while(check)
    {
        int choice;
        cout<<"\nEnter 1 for push\n";
        cout<<"Enter 2 for pop the element\n";
        cout<<"Enter 3 for display\n";
        cout<<"Enter 4 for display the top element of stack \n";
        cout<<"Enter 5 for exit\n";
        cin>>choice;
        switch (choice)
        {
        case 1:
            int x;
            cout<<"Enter the value you want push";
            cin>>x;
            st.push(x);
            break;
        case 2:
            st.pop();
            break;
        case 3:
            st.display();
            break;
        case 4:
            cout<<st.stackTop();
            break;
        case 5:
            check =0;
            break;
        default:
            break;
        }
    }
    
    return 0;
}
