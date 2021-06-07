#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node *next;
};
static Node *head = NULL;
static Node *last = NULL;



int nodes(Node *p){
    int count =0;
    if(head == NULL)
        return 0;
    do
    {
        count++;
        p = p->next;
    }while (p!=head);
    return count;
}

void insertLast(Node *p,int x){
    Node *t = new Node;
    t->data =x;
    t->next = NULL;
    if(nodes(p)==0){
        head =t;
        last =t;     
    }
    else{
    last->next=t;
    last = t;
    }
    last->next = head;
}


void del(Node *p,int index){
    Node *q=NULL;
    if(index<1 || index>nodes(head))
        return;
    if(index==1)
    {
        head = p->next;
        delete p;
        last->next = head;

    }
    else if(nodes(head)==index){
        for (int i = 1; i < index-1; i++)
        {
            p=p->next;
        }
        p->next = last->next;
        delete last;
        last = p;
    }
    else {
        for (int i = 0; i < index-1; i++)
        {
            q=p;
            p=p->next;
        }
        q->next = p->next;
        delete p;
    }

}

void display(Node *p){
    do
    {
        cout<<p->data<<" ";
        p=p->next;
    }while (p!=head);
    
}

int main(int argc, char const *argv[])
{
    int n;
    cout<<"How Many Elements you want to insert";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        insertLast(head,x);
    }

    display(head);
    cout<<endl;
    int index;
    cout<<"From which index you want to delete: ";
    cin>>index;
    del(head,index);
    display(head);
    return 0;
}
