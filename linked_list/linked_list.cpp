#include<bits/stdc++.h>
using namespace std;
// defining the linked list here
class Node{
    public:
    int data;
    Node *next;
};


// creating the first node which points always start of linked list
static Node *first=NULL;
static Node *last=NULL;
// for 2nd linked list
static Node *second = NULL;
static Node *third = NULL;

//creating the linked list for the first time
void create(int a[],int n){
    int i;
    Node *t,*last;
    first = new Node[sizeof(Node)];
    first->data = a[0];
    first->next = NULL;
    last = first;
    for ( i = 1; i < n; i++)
    {
        t = new Node[sizeof(Node)];
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    
}
//creating the linked list for the second LL
void create2(int a[],int n){
    int i;
    Node *t,*last;
    second = new Node[sizeof(Node)];
    second->data = a[0];
    second->next = NULL;
    last = second;
    for ( i = 1; i < n; i++)
    {
        t = new Node[sizeof(Node)];
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    
}


//iterative display function
void display(Node *p){
    while (p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    
}


//recursive display function
void display2(Node *p){
    if(p!=0){
        cout<<p->data<<endl;
        display2(p->next);
    }
}

//countng the nodes of linked list using iterative method
int nodes(Node *p){
    int count =0;
    while (p!=NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}


// recursive for count
int nodes2(Node *p){
    if(p)
    {
        return nodes2(p->next)+1;
    }
    return 0;
}


//sum of all nodes data of linked list
int sum(Node *p){
    int sum=0;
    while (p)
    {
        sum+= p->data;
        p = p->next;
    }
    return sum;
}


//sum of all nodes data recusive
int sum2(Node *p){
    if(p){
        return sum2(p->next)+p->data;
    }
    return 0;
}


//finding max element of linked list
int max(Node *p){
    int max = first->data;
    while (p)
    {
        if(max<p->data)
            max = p->data;
        p = p->next;
    }
    return max;
}


/* searching in linked list we can't perform on ll coz we can't move to mid beacuse the data is located at different
locations so we are performing linear search */ 

Node *searchLL(Node *p,int key){
    while(p){
        if(key==p->data)
            return p;
        p=p->next;
    }
    return NULL;
}

// improved linear search using move to head in linked list we avoid movement of data so transposition is not suit
// suitable although we can apply it also
Node *searchMTH(Node *p,int key){
    Node *q= new Node;
    q->next=NULL;
    while(p)
    {
        if(key==p->data){
            q->next = p->next;
            p->next=first;
            first = p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
    
}


// this will insert the any where you want but it won't insert once you pass the wrong index
void insert(Node *p,int index,int x){
    if(index<0 || index > nodes(p))
        return;
    Node *t = new Node;
    t->data = x;
    t->next = NULL;

    if(index==0){
        t->next = first;
        first =t;
    }

    else{
        for (int i = 0; i < index-1; i++)
        {
            p=p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}


// insert last will append the data to the last of linked list we have maintain a last ptr also 
// for this
void insertLast(Node *p,int x){
    Node *t = new Node;
    t->data =x;
    t->next = NULL;
    if(nodes2(p)==0){
        first =t;
        last =t;     
    }
    else{
    last->next=t;
    last = t;
    }
}


//insert at the sorted position of linked list
void insertSort(Node *p,int x){
    Node *t = new Node;
    Node *q=first;
    t->data = x;
    t->next = NULL;
    if(x<first->data){
        t->next = first;
        first =t;
    }
    else{
        for (;q->next&& x> q->next->data ;)
        {
            q = q->next;
        }
        t->next = q->next;
        q->next = t;
        
    }

}


//deleting node from a linked list index starts from 0 onwards
int del(Node *p,int index){
    if(index <0 || index> nodes2(p)){
        return -1;
    }
    int x;
    Node *q;
    if(index==0){
        x=first->data;
        first = first->next;
        delete p;
        return x;
    }
    
    else{
        for (int i=0;i<index;i++)
        {
            q=p;
            p=p->next;
        }
        x = p->data;
        q->next = p->next;
        delete p;
        return x;
    }
}


//checking linkedlist is sorted or not 
int isSort(Node *p){
    while (p->next->next) //or we can write also p->next->next !=NULL
    {
        if(p->data>p->next->data)
            return 0;
        p=p->next;
    }
    return 1;
}

// removing the duplicates from a sorted list 
// imp. if LL is unsorted so u have to use brute force for every element
void DelDuplicate(Node *p){
    Node *q=p->next;
    while (q)
    {
        if(q->data == p->data){
            p->next = q->next;
            delete q;
            q = p->next;
        }
        else{
        p = p->next;
        q= q->next;
        }
    }
    
}

// reversing the linked list in this method we move data but this technique is not good don't use it if
// you are good dev we avoid the movement of data in LL
void Rev(Node *p){
    int a[nodes2(p)],i=0;
    while (p)
    {
        a[i++]=p->data;
        p = p->next;
    }
    p=first;
    while (p)
    {
        p->data = a[--i];
        p=p->next;
    }
}

// there is 1 more method of reversing the linked list by reversing the links nodes not the data movement
void Rev2(Node *p){
    Node *q=NULL,*r=NULL;
    while (p)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first =q;
}


//comcatenation of 2 linked list
void concate(Node *p,Node *q){
    third = p;
    while (p->next)
    {
        p=p->next;
    }
    p->next = q;
}


//merging two linked list in a sorted formate
void merge(Node *p,Node *q){
    Node *r=third;

    // firstly intialising the third LL first ptr
    if(p->data<q->data){
        third =r=p;
        p = p->next;
    }
    else{
        third = r =q;
        q = q->next;
    }

    // now linking the node sorted formate
    while (p && q)
    {
        if(p->data<q->data){
            r->next = p;
            p = p->next;
            r = r->next;
        }
        else{
            r->next = q;
            q = q->next;
            r = r->next;
        }
    }

    // if any node in any LL left then linking that node to third LL
    while (p)
    {
        r->next = p;
        p=p->next;
        r=r->next;
    }
    while (q)
    {
        r->next = q;
        q = q->next;
        r = r->next;
    }
    
}

//checking the linked list is looped or not
int isLoop(Node *p){
    Node *q=first;

    /* why we are not using while loop here??
        because the condition of p!=q is fails because intially it both points to 1st so  it will always thought linked lis is looped
     */
    do
    {
        p = p->next;
        q = q->next;
        q=q?q=q->next:q;
    }while (q && p && p!=q);
    if(p==q)
        return 1;
    return 0;
}



// while final implimentation always maintain the last ptr 
int main(int argc, char const *argv[])
{
    // int a[5]={10,20,50,60,300};
    // create(a,5);
    // int b[5]={5,15,25,35,45};
    // create2(b,5);

    //insertion using insertLast
    // int n,x;
    // cout<<"How Many elements you want intially in linked list: ";
    // cin>>n;
    // while (n--)
    // {
    //     cin>>x;
    //     insertLast(first,x);

    // }
  
    // Node *t = first->next->next->next->next;
    // t->next = first->next->next;
    // cout<<endl;
    // if(isLoop(first)){
    //     cout<<"Loop Linked List";
    // }
    // else{
    //     cout<<"Not Looped";
    // }
    int n,choice,index,i=1;
    while(i){
        cout<<endl<<"Enter 1 for insert: "<<endl;
        cout<<"Enter 2 for Delete: "<<endl;
        cout<<"Enter 3 for display: "<<endl;
        cout<<"Enter 4 for exit: "<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"Enter the data you want insert: ";
            cin>>n;
            cout<<"Enter the index in which you want to insert: ";
            cin>>index;
            insert(first,index,n);
            break;
        case 2:
            cout<<"Enter the index from which you want to delete: ";
            cin>>index;
            del(first,index);
            break;
        case 3:
            display(first);
            break;
        case 4:
            i=0;
            break;
        default:
            break;
        }
    }
    return 0;
}
