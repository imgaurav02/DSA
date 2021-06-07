#include<bits/stdc++.h>

using namespace std;

class que{
public:
    int front;
    int rear;
    int size;
    int *q;


// if user passes the size while creating the object then it will defined with that size else it will\
set to default size ie 10
que(int size){
    front = rear = -1;
    this->size = size;
}


que(){
    front = rear = -1;
    this->size = 10;
}
};


int Delque(que *p){
    int x=-1;
    if(p->front == p->rear){
        cout<<"que is Empty"<<endl;
        return -1;
    }
    p->front++;
    x = p->q[p->front];
    return x;
}

void enque(que *p,int x){
    if(p->rear == p->size-1)
        cout<<"que if full";
    p->rear++;
    p->q[p->rear] = x;
}

void display(que p){
    int x = p.front;
    while (x!=p.rear)
    {
        x++;
        cout<<p.q[x]<<endl;
    }
    
}

int main(){
    que Q(5);
    Q.q = new int [Q.size];
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
                enque(&Q,x);
                break;
            case 2:
                cout<<endl<<Delque(&Q);
                break;
            case 3:
                display(Q);
                break;
            case 4:
                i=0;
                break;
            default:
                break;
        }
    }
    

    
}