#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;
};

Node *front = NULL;
Node *rear = NULL;

void Enqueue(int x){
    Node *t = new Node;
    if(t==NULL)
        cout<<"Queue Is Full"<<endl;
    t->data = x;
    t->next = NULL;
    if(front==NULL)
    {
        front = rear = t;
    }
    else{
        rear->next = t;
        rear = t;
    }
}

int Delqueue(){
    int x=-1;
    if(front == NULL){
        cout<<"Queue is empty";
    }
    else{
        Node *t;
        t = front;
        front = front->next;
        x = t->data;
        delete t;
    }
    return x;
}

void display(){
    Node *x = front;

    while (x)
    {
        cout<<x->data<<" ";
        x = x->next;
    }
    
}

int main(){
    int ch,i=1;
    while (i)
    {
        cout<<"press 1 for insert in que\n";
        cout<<"press 2 for delete in que\n";
        cout<<"press 3 for display the que\n";
        cout<<"press 4 for exit\n";
        cout<<"\nEnter the choice: ";
        cin>>ch;
        switch(ch){
            case 1:
                int x;
                cout<<"Enter the value you want insert: ";
                cin>>x;
                Enqueue(x);
                break;
            case 2:
                cout<<endl<<Delqueue();
                break;
            case 3:
                display();
                break;
            case 4:
                i=0;
                break;
            default:
                break;
        }
    }
    
}