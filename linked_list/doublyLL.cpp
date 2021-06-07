#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node *prev;
    int data;
    Node *next;
};
Node *first;

void create(int a[],int n){
    Node *t,*last;
    first = new Node;
    first->prev = NULL;
    first->data = a[0];
    first->next = NULL;
    last = first;
    for(int i=1;i<n;i++)
    {
        t = new Node;
        t->data = a[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }


}

int countNode(Node *p){
    int count =0;
    while (p)
    {
        p=p->next;
        count++;
    }
    return count;
    
}

void insert(Node *p,int pos,int x){
    if(pos<0 || pos>countNode(first))
        return;
    Node *t=new Node;
    t->data = x;
    if(pos==0){
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }
    else {
        for(int i=0;i<pos-1;i++)
            p = p->next;
        t->prev = p;
        t->next = p->next;
        if(p->next)
            p->next->prev = t;
        p->next = t;
    }

}

void display(Node *p){
    while (p)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    
}

int delNode(Node *p,int pos){
    if(pos<1 || pos>countNode(first))
        return -1;
    int x;
    if(pos==1){
        first = first->next;
        first->prev = NULL;
        x = p->data;
        delete p;
        return x;
    }
    else{
        Node *q;
        for (int i = 0; i < pos-1; i++)
        {
            q=p;
            p=p->next;
        }
        q->next = p->next;
        if(p->next)
            p->next->prev = q;
        x = p->data;
        delete p;
        return x;
        
    }
    
}

void reverse(Node *p){
    Node *t;
    while(p){
        t= p->next;
        p->next = p->prev;
        p->prev = t;
        p = p->prev;
        if(p!=NULL && p->next==NULL)
            first = p;
    }

}

int main(){
    int a[5] = {10,20,30,40,50};
    create(a,5);
    reverse(first);
    display(first);
    insert(first,2,60);
    cout<<endl;
    display(first);
    cout<<endl;
  
    display(first);
}