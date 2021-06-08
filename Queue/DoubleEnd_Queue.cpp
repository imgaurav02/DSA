#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;
}
;
Node *front = NULL;
Node *rear = NULL;


void frontEn(int x){
    Node *t = new Node;
    if(t==NULL){
        cout<<"Queue Is Full";
    }
    else{
        t->data = x;
        if(front==NULL){
            t->next = NULL;
            front=rear = t;
        }
        else{
            t->next = front;
            front = t;
        }
    }
}

void rearEn(int x){
    Node *t = new Node;
    if(t==NULL){
        cout<<"Queue Is Full";
    }
    else{
        t->data = x;
        t->next = NULL;
        if(front==NULL){
            front=rear = t;
        }
        else{
            rear->next = t;
            rear = t;
        }
    }
}

int frontDel(){
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
int rearDel(){
    int x=-1;
    if(front == NULL){
        cout<<"Queue is empty";
    }
    else{
        Node *t;
        t = front;
        if(t->next == NULL)
        {
            front = rear = NULL;
            x = t->data;
            delete t;
        }
        else{
            while (t->next!=rear)
            {
                t=t->next;
            }
            t->next = NULL;
            x = rear->data;
            delete rear;
            rear = t;
            
        }
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
    int x;
    while (i)
    {
        cout<<"press 1 for insert in queue from front\n";
        cout<<"press 2 for insert in queue from rear\n";
        cout<<"press 3 for delete in queue from front\n";
        cout<<"press 4 for delete in queue from rear\n";
        cout<<"press 5 for display the que\n";
        cout<<"press 6 for exit\n";
        cout<<"\nEnter the choice: ";
        cin>>ch;
        switch(ch){
            case 1:
                
                cout<<"Enter the value you want insert: ";
                cin>>x;
                frontEn(x);
                break;
            case 2:
                cout<<"Enter the value you want insert: ";
                cin>>x;
                rearEn(x);
                break;
            case 3:
                cout<<endl<<frontDel();
                break;
            case 4:
                cout<<endl<<rearDel();
                break;
            case 5:
                display();
                break;
            case 6:
                i=0;
                break;
            default:
                break;
        }
    }
    
}