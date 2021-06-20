#include<bits/stdc++.h>
#include "Queue.h"
#include "Stack.h"
using namespace std;

Node *root = NULL;


void Treecreate(){
    Node *p,*t;
    DEqueue q(100);
    int x;
    cout<<"Enter the root Node: ";
    cin>>x;
    root = new Node;
    root->data = x;
    root->lchild = root->rchild=NULL;
    q.Enqueue(root);
    while (!q.isEmpty())
    {
        p = q.Delqueue();
        cout<<"Enter the left child of "<<p->data<<" : ";
        cin>>x;
        if(x!= -1){

        t = new Node;
        t->data =x;
        t->lchild = t->rchild = NULL;
        p->lchild = t;
        q.Enqueue(t);
        }
        cout<<"Enter the right child of "<<p->data<<" : ";
        cin>>x;
        if(x!= -1){

        t = new Node;
        t->data =x;
        t->lchild = t->rchild = NULL;
        p->rchild = t;
        q.Enqueue(t);
        }

    }
    
}


void preorder(Node *p){
    if(p){

    cout<<p->data<<" ";
    preorder(p->lchild);
    preorder(p->rchild);
    }
}
void postorder(Node *p){
    if(p){

    postorder(p->lchild);
    postorder(p->rchild);
    cout<<p->data<<" ";
    }
}
void inorder(Node *p){
    if(p){

    inorder(p->lchild);
    cout<<p->data<<" ";
    inorder(p->rchild);
    }
}


//iterative method for preorder traversal
Stack st;
Stack1 st1;
void Ipreorder(Node *t){
    while(t!=NULL || !st.StackEmpty()){
        if(t!=NULL){
            cout<<t->data<<" ";
            st.push(t);
            t=(t->lchild);
        }
        else{
            t = st.pop();
            
            t=(t->rchild);
        }
    }
}

void IInorder(Node *t){
    while(t!=NULL || !st.StackEmpty()){
        if(t!=NULL){
            st.push(t);
            t=(t->lchild);
        }
        else{
            t = st.pop();
            cout<<t->data<<" ";
            t=(t->rchild);
        }
    }
}

void IPostorder(Node *t){
    if(t==NULL)
        return;
    st.push(t);
    while(!st.StackEmpty()){
        t=st.pop();
        if(t->lchild)
            st.push(t->lchild);
        if(t->rchild)
            st.push(t->rchild);
        st1.push(t->data);
    }

    while (st1.top!=-1)
    {
        cout<<st1.pop()<<" ";
    }
    
}


int main(){
    Treecreate();
    preorder(root);
    cout<<endl;
    IPostorder(root);
    // postorder(root);
    // cout<<endl;
    // inorder(root);
    // cout<<endl;
}