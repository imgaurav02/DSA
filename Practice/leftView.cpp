#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node *left;
    int data;
    Node *right;
    Node(int data){
        left = NULL;
        this->data = data;
        right = NULL;
    }
};


// iterative code

// class q{
//     public:
//         int lev;
//         Node *addr;
// };

// void leftView(Node *root){
//     if(!root)
//         return;
//     queue<q> Q;
//     q obj;
//     int maxLevel  = 0;
//     obj.lev = 0;
//     obj.addr = root;
//     Q.push(obj);
//     while(!Q.empty()){
//         q t = Q.front();
//         Q.pop();
//         if(maxLevel == t.lev){
//             cout<<t.addr->data<<" ";
//             maxLevel++;
//         }
//         if(t.addr->left){
//             obj.lev = t.lev+1;
//             obj.addr = t.addr->left;
//             Q.push(obj);
//         }
//         if(t.addr->right){
//             obj.lev = t.lev+1;
//             obj.addr = t.addr->right;
//             Q.push(obj);
//         }
//     }
// }



//recursive code
int maxLevel = 0;

void leftView(Node *root,int level){
    if(!root)
        return;
    if(maxLevel < level){
        cout<<root->data<<" ";
        maxLevel = level;
    }
    leftView(root->left,level+1);
    leftView(root->right,level+1);
}

Node* create(){
    queue<Node*> Q;
    int data;
    cin>>data;
    Node *root = new Node(data);
    Q.push(root);
    while(!(Q.empty())){
        Node *t = Q.front();
        Q.pop();
        cin>>data;
        if(data != -1)
        {
            t->left = new Node(data);
            Q.push(t->left);
        }
        
        cin>>data;
        if(data != -1)
        {
            t->right = new Node(data);
            Q.push(t->right);
        }
    }
    return root;
}

void Inorder(Node *root){
    if(root){
        Inorder(root->left);
        cout<<root->data<<" ";
        Inorder(root->right);
    }
}

int main() {
    Node *root = create();
    Inorder(root);
    cout<<endl;
    leftView(root,1);
}
