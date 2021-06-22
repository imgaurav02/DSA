#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    Node *lchild;
    int data;
    Node *rchild;
};
Node *root=NULL;
class Tree{
public:
    void create(Node*,int);
    void Inorder(Node*);
    Node* search(Node *,int);
    Node* Rinsert(Node*,int);
    Node* Delete(Node*,int);
};

int Height(Node*p){
    int x,y;
    if(!p)
        return 0;
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x>y?x+1:y+1;
}

Node* Inpre(Node *p){
    while(p && p->lchild){
        p = p->lchild;
    }
    return p;
}

Node* InSucc(Node *p){
    while(p && p->lchild){
        p = p->lchild;
    }
    return p;
}

Node* Tree::Delete(Node *p,int key){
    Node *q;

    if(p==NULL)
        return NULL;
    
    if(!p->lchild && !p->rchild){
        if(p==root)
            root=NULL;
        delete p;
        return NULL;
    }

    if(key>p->data)
        p->rchild = Delete(p->rchild,key);
    else if(key<p->data)
        p->lchild = Delete(p->lchild,key);
    else
    {
        if(Height(p->lchild)>Height(p->rchild))
        {
            q=Inpre(p->lchild);
            p->data = q->data;
            p->lchild=Delete(p->lchild,q->data);
        }
        else
        {
            q=InSucc(p->lchild);
            p->data = q->data;
            p->rchild=Delete(p->rchild,q->data);
        }
    }
    return p;
}

Node* Tree::search(Node *p,int key){
    while(p){
        if(p->data==key)
            return p;
        else if(p->data>key)
            p = p->lchild;
        else
            p = p->rchild;
    }
    return p;
}

void Tree::create(Node *p,int key){
    Node *r=NULL,*temp;
    if(root==NULL){
        temp = new Node;
        temp->data = key;
        temp->rchild = temp->lchild = NULL;
        root = temp;
        return;
    }
    while(p!=NULL){
        r=p;
        if(key==p->data)
            return;
        else if(key<p->data)
        {
            p = p->lchild;
        }
        else{
            p = p->rchild;
        }
    }
    temp = new Node;
    temp->data = key;
    temp->rchild = temp->lchild = NULL;
    if(r->data>key){
        r->lchild = temp;
    }
    else{
        r->rchild = temp;
    }
    
}

void Tree::Inorder(Node *t){
    if(t){
        Inorder(t->lchild);
        cout<<t->data<<" ";
        Inorder(t->rchild);
    }
}

Node* Tree::Rinsert(Node *p,int key){
    Node *t;
    if(p==NULL){
        t=new Node;
        t->data = key;
        t->rchild = t->lchild = NULL;
        if(p==root)
            p = root =t;
        else
            p=t;
    }    
    if(p->data>key)
        p->lchild = Rinsert(p->lchild,key);
    else if(p->data<key)
        p->rchild = Rinsert(p->rchild,key);
    
    return p;
}

int main(){
    Tree t;
    int choice,i=1,key;
    Node *s;
    while(i){
        cout<<"press 1 For insert\n";
        cout<<"press 2 For Inorder Traversal\n";
        cout<<"press 3 For search \n";
        cout<<"press 4 For Delete Any Key \n";
        cout<<"press 5 For exit \n";
        cout<<"Enter Choice: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"Enter the element you want to insert in BST: ";
            cin>>key;
            t.Rinsert(root,key);
            // t.create(root,key);
            break;
        case 2:
            t.Inorder(root);
            cout<<endl;
            break;
        case 3:
            cout<<"Enter the data you want to search: ";
            cin>>key;
            s = t.search(root,key);
            if(s)
                cout<<"Key is Found\n";
            else
                cout<<"Key is Not Found\n";
            break;
        case 4:
            cout<<"Enter the Key you want to delete: ";
            cin>>key;
            s=t.Delete(root,key);
            break;
        case 5:
            i=0;
            break;
        default:
            break;
        }
    }
}