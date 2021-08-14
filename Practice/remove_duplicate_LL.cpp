#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    
    Node(int x){
        this->data = x;
        this->next = NULL;
    }
};
Node *head = NULL;
Node *last = NULL;

void insert(int x){
    Node *t = new Node(x);
    if(!head){
        head = last = t;
    }
    else{
        last->next = t;
        last = t;
    }
}

void display(){
    Node *p = head;
    while(p){
        cout<<p->data<<" ";
        p = p->next;
    }
}

void removeDuplicates(vector<int> arr){
    int n = arr.size();
    int max = *max_element(arr.begin(),arr.end());
    vector<int> hash(max+1,0);

    for(int i=0;i<n;i++){
        if(hash[arr[i]]==0){
            insert(arr[i]);
            hash[arr[i]]++;
        }
    }
}

int main(){
    int x;
    vector <int> arr;
    while(true){
        cin>>x;
        if(x != -1)
            arr.push_back(x);
        else
            break;
    }
    removeDuplicates(arr);
    display();

}