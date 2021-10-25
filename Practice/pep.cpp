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
    Node *left;
    Node *right;

    Node(int data,Node *left,Node *right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

class Pair {
    public:
    Node *node;
    int state;

    Pair(Node *n, int state) {
      node = n;
      this->state = state;
    }
};


Node* construct(vi arr){
    Node *root = new Node(arr[0],NULL,NULL);
    Pair rtp(root,1);

    stack<Pair> st;
    st.push(rtp);
    int idx = 0;
    while(!st.empty()){
        Pair &top = st.top();
        if(top.state == 1){
            idx++;
            if(arr[idx] != -1){
                top.node->left = new Node(arr[idx],NULL,NULL);
                Pair lp(top.node->left,1);
                st.push(lp);
            }
            else{
                top.node->left = NULL;
            }
            top.state++;
        }
        else if(top.state == 2){
            idx++;
            if(arr[idx] != -1){
                top.node->right = new Node(arr[idx],NULL,NULL);
                Pair rp(top.node->right,1);
                st.push(rp);
            }
            else{
                top.node->right = NULL;
            }
            top.state++;
        }else{
            st.pop();
        }
    }


    return root;
}

// void display(Node *node) {
//     if (node == NULL) {
//       return;
//     }

//     string str = "";
//     str += node->left == NULL ? "." : node->left->data + "";
//     str += " <- " + to_string(node->data) + " -> ";
//     str += node->right == NULL ? "." : node->right->data + "";
//     cout<<str;

//     display(node->left);
//     display(node->right);
// }


  vector<Node*> nodeToRootPath(Node *node, int data) {
    vector<Node*> temp;
    if (node == NULL){
      return temp;
    }

    vector<Node*> ans;
    if (node->data == data) {
      ans.push_back(node);
      return ans;
    }
    vector<Node*> left = nodeToRootPath(node->left, data);
    if (left.size() > 0) {
      left.push_back(node);
      return left;
    }
    vector<Node*> right = nodeToRootPath(node->right, data);
    if (right.size() > 0) {
      right.push_back(node);
      return right;
    }
    return temp;
  }

void printKLevelsDown(Node *node, int k, Node *block) {
    if (node == NULL)
      return;
    if (node == block)
      return;
    if (k == 0) {
      cout<<node->data<<endl;
      return;
    }
      printKLevelsDown(node->left, k - 1, block);
      printKLevelsDown(node->right, k - 1, block);
    
  } 

void printKNodesFar(Node *node, int data, int k) {
    if (node == NULL)
      return;
    Node *block = NULL;
    vector<Node*> ans;
    ans = nodeToRootPath(node, data);
    for (int i = 0; i < ans.size(); i++) {
      printKLevelsDown(ans[i], k - i, block);
      block = ans[i];
    }

  }

int main(){
    INPUT
    OUTPUT
    int n;
    cin>>n;
    vi arr(n);
    loop(i,0,n)
    {
        cin>>arr[i];
    }
    int data,k;
    cin>>data>>k;

    Node *root = construct(arr);
    printKNodesFar(root,data,k);
    return 0;
}