#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *next;
    node(int x){
        this->data = x;
        this->next = NULL;
    }
};

node* createLL(vector<int> arr,int n){
    node *head = new node(-1);
    node *last = head,*t;
    for(int i=0;i<n;i++){
        t = new node(arr[i]);
        last->next = t;
        last = t;
    }
    return head->next;
}
void display(node *head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
}
node* reverseK(node *head,int k){
    if(!head)
        return NULL;
    int count = 0;
    node *p = head;
    node *q = NULL;
    node *r = NULL;
    while(p && count<k){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
        count++;
    }
    head->next = reverseK(p,k);
    return q;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    node *head = createLL(arr,n);
    head = reverseK(head,k);
    display(head);
}