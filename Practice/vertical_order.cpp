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

// running code try on coding blocks ide not here understand from yt
map<int,map<int,set<int>>> m;
void solve(Node *root,int col,int row){
    if(!root)
        return;
    m[col][row].insert(root->data);
    solve(root->left,col-1,row+1);
    solve(root->right,col+1,row+1);
}
void verticle_order(Node *root){
    solve(root,0,0);
    for(auto m1: m){
        for(auto m2 : m1.second){
            for(auto m3 : m2.second){
                cout<<m3<<" ";
            }
        }
    }
}


int main() {
    Node *root = create();
    Inorder(root);
    cout<<endl;
    verticle_order(root);
}
