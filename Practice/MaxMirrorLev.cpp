//will work in online ide remeber to comment input and output

//what my thought process in this program
/* 
    1. i will decleare the irative ismirror fuction and if it's returning true
    then i case will like it will fully mirrored so i m returning height of tree
    2. if it return false then i am storing the address of that faulty node
    and will do BFS on tree untill i haven't found the stored address

    input 
    1 2 2 3 -1 -1 3 -1 4 -1 4 -1 -1 -1 -1
*/

#include<bits/stdc++.h>
using namespace std;
#define INPUT freopen("input.txt","r",stdin);
#define OUTPUT freopen("output.txt","w",stdout);
#define loop(i,a,b) for(int i = a;i<b;i++)
#define looprev(i,a,b) for(int i = a;i>=b;i--)
#define mid(l,r) (l+(r-l)/2)
#define ll long long int
#define vi vector<int>

class Node{
    public:
    int data;
    Node *left,*right;
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

Node* create(){
    int key;
    cin>>key;
    if(key == -1)
        return NULL;
    Node *root = new Node(key);
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        cin>>key;
        if(key != -1){
            temp->left = new Node(key);
            q.push(temp->left);
        }
        else{
            temp->left = NULL;
        }
        cin>>key;
        if(key != -1){
            temp->right = new Node(key);
            q.push(temp->right);
        }
        else{
            temp->right = NULL;
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

int ans = -1e8;
Node *target = NULL;

int height(Node *root){
    if(!root)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh,rh) + 1;
}

int BFS(Node *root){
    if(target == NULL or !root)
        return 0;
    queue<pair<Node*,int> > q;
    q.push({root,1});
    while(!q.empty()){
        pair<Node*,int> temp = q.front();
        q.pop();
        if(temp.first == target)
            return temp.second;
        if(temp.first->left){
            q.push({temp.first->left,temp.second+1});
        }
        if(temp.first->right)
            q.push({temp.first->right,temp.second+1});
    }
    return height(root);
}


bool isSymmetric(struct Node* root)
{
    if(root == NULL){
        ans = 0;
        return true;
    }
     
    // If it is a single tree node, then
    // it is a symmetric tree.
    if(!root->left && !root->right){
        ans = 1;
        return true;
    }
     
    queue <Node*> q;
     
    // Add root to queue two times so that
    // it can be checked if either one child
    // alone is NULL or not.
    q.push(root);
    q.push(root);
     
    // To store two nodes for checking their
    // symmetry.
    Node* leftNode, *rightNode;
     
    while(!q.empty()){
         
        // Remove first two nodes to check
        // their symmetry.
        leftNode = q.front();
        q.pop();
         
        rightNode = q.front();
        q.pop();
         
        // if both left and right nodes
        // exist, but have different
        // values--> inequality, return false
        if(leftNode->data != rightNode->data){
            target = leftNode;
            return false;
        }
         
        // Push left child of left subtree node
        // and right child of right subtree
        // node in queue.
        if(leftNode->left && rightNode->right){
            q.push(leftNode->left);
            q.push(rightNode->right);
        }
         
        // If only one child is present alone
        // and other is NULL, then tree
        // is not symmetric.
        else if (leftNode->left || rightNode->right){
            target = leftNode;
            return false;
        }
         
        // Push right child of left subtree node
        // and left child of right subtree node
        // in queue.
        if(leftNode->right && rightNode->left){
            q.push(leftNode->right);
            q.push(rightNode->left);
        }
         
        // If only one child is present alone
        // and other is NULL, then tree
        // is not symmetric.
        else if(leftNode->right || rightNode->left)
        {
            target = leftNode;
            return false;

        }
    }
    ans = height(root);
    return true;
}

int main(){
    INPUT
    OUTPUT
    Node *root = create();
    Inorder(root);
    cout<<endl;
    if(isSymmetric(root)){
        if(ans == -1e8){
            cout<<BFS(root);
        }
        else{
            cout<<ans;
        }
    }
    else{
        cout<<BFS(root);
    }

    // cout<<height(root);
    return 0;
}