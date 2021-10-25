#include<bits/stdc++.h>
#define INPUT freopen("input.txt","r",stdin);
#define OUTPUT freopen("output.txt","w",stdout);
#define loop(i,a,b) for(int i = a;i<b;i++)
using namespace std;


//enter the preorder of BST to construct B tree
/* 
    19
    50 25 12 -1 -1 37 30 -1 -1 -1 75 62 -1 10 -1 -1 87 -1 -1
*/
class Node{
    public:
    Node *left;
    int data;
    Node *right;
    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class Pair{
    public:
    Node *addr;
    int state;
    Pair(Node *addr,int state){
        this->addr = addr;
        this->state = state;
    }
};

Node *constructBTree(vector<int> arr,int n){
    stack<Pair> st;
    Node *root = new Node(arr[0]);
    st.push(Pair(root,1));
    int i = 0;
    while(!st.empty()){
        Pair &top = st.top();
        if(top.state == 1){
            i++;
            if(arr[i] != -1){
                top.addr->left = new Node(arr[i]);
                st.push(Pair(top.addr->left,1));
            }
            else{
                top.addr->left = NULL;
            }
            top.state++;
        }
        else if(top.state == 2){
            i++;
            if(arr[i] != -1){
                top.addr->right = new Node(arr[i]);
                st.push(Pair(top.addr->right,1));
            }
            else{
                top.addr->right = NULL;
            }
            top.state++;
        }
        else{
            st.pop();
        }
    }
    return root;

}

void Preorder(Node *root){
    if(root){
        Preorder(root->left);
        cout<<root->data<<" ";
        Preorder(root->right);
    }
}

int main(){
    INPUT
    OUTPUT
    int n;
    cin>>n;
    vector<int> arr(n);
    loop(i,0,n)
        cin>>arr[i];
    Node *root = constructBTree(arr,n);
    vector<int> res;
    Preorder(root);
    return 0;
}