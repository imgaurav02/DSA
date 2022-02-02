#include<iostream>
#include "node.h"
#include "single.h"

using namespace std;

SingleLinkedList ::SingleLinkedList()
{
    start=NULL;
}

inline bool SingleLinkedList::isEmpty() const
{
    return start == NULL;
}

void SingleLinkedList::displayList() const
{
 if(isEmpty())
 {
     cout<< "List is empty\n";
     return;
 }   

 cout<<"List is : \n";
 Node *p =start;
  while(p!=NULL)
 {
     cout<< p->info<<" ";
     p=p->link;
 }
 cout<<"\n\n";
}

int SingleLinkedList :: countNodes() const 
{
    Node  *p = start;
    int n=0;
    while(p!=NULL)
    {
        n++;
        p=p->link;
    }
    return n;
}

int SingleLinkedList ::find(int x) const
{
    Node *p = start;
    int position;

    while (p!=NULL)
    {
        if(p->info==x)
        return position;
        position++;
        p=p->link;
    }
    
    return 0;
}

void SingleLinkedList::insertAtbeginning(int data )
{
    Node *temp = new Node(data);
    if(!start){
        start = temp;
        return;
    }
    Node *p =start;
    temp->link =p;
    p = temp;
}

void SingleLinkedList::insertAtend(int data) 
{
    if(isEmpty())
    {
        insertAtbeginning(data);
        return;
    }
    Node *temp= new Node(data);
    Node *p =start;
    while (p->link !=NULL)
    {
        p=p->link;
    }
    p->link= temp;
}

void SingleLinkedList::createList()
{
    int i ,n ,data;
    cout<<"enter the number of nodes :";
    cin>>n;

    if(n<=0)
    return;

    cout<< " enter the first element to be insert";
    cin>>data;
    insertAtbeginning(data);

    Node *p =start;
    for(i=2;i<=n;i++)
    {
        cout<< "enter next Element to be inserted";
        cin>>data;
        Node *temp= new Node(data);
        p->link = temp;
        p=temp;  
    }

    
}