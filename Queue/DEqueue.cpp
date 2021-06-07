#include<bits/stdc++.h>
using namespace std;



//NOTE
// This is not DEQueue(Double Ended Queue) i mistakly named it as DEQueue it's a circuler queue program



class DEqueue{
public:
    int size;
    int front;
    int rear;
    int *Q;

// default contructor
DEqueue(){
    front = rear = 0;
    size = 10;
}

// parameterized contructor
DEqueue(int size){
    front = rear = 0;
    this->size = size;
}

void Enqueue(int x);
int Delqueue();
void display();
};

void DEqueue::Enqueue(int x){
    if((rear+1)%size == front)
        cout<<"Queue Is Full"<<endl;
    else{
        rear = (rear+1)%size;
        Q[rear] = x;
    }
}

int DEqueue::Delqueue(){
    int x=-1;
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

void DEqueue::display(){
    int x = front;
    while (x!=rear)
    {
        cout<<Q[++x];
    }
    
}

int main(){
    DEqueue Que(5);
    Que.Q = new int [Que.size];
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
                Que.Enqueue(x);
                break;
            case 2:
                cout<<endl<<Que.Delqueue();
                break;
            case 3:
                Que.display();
                break;
            case 4:
                i=0;
                break;
            default:
                break;
        }
    }
    
}

