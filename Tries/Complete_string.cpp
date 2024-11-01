#include <bits/stdc++.h> 

using namespace std;

class Node{
    public:
    vector<Node*> childes{vector<Node*>(26,NULL)};
    bool flag;

    Node(bool flag){
        this -> flag = flag;
    }
};

Node *root = new Node(false);

int getVal(char c)
{
    return (c - 'a');
}


bool search(string word){

    Node *temp_root = root;
    for(int i = 0;i < word.size();i++){
        int val = getVal(word[i]);
        if(!temp_root -> childes[val] -> flag){
            return false;
        }
        temp_root = temp_root -> childes[val];
    }
    return temp_root -> flag;
    
}

void insert(string word){
    Node *temp_root = root;
    for(int i = 0;i < word.size();i++){
        int val = getVal(word[i]);
        if(temp_root -> childes[val] == NULL){
            temp_root -> childes[val] = new Node(false);
        }
        temp_root = temp_root -> childes[val];
    }
    temp_root -> flag = true;
}

string completeString(int n, vector<string> &a){
    // Write your code here.
    for(int i = 0;i < n;i++){
        insert(a[i]);
    }

    string ans = "";
    int len = INT_MIN;

    for(int i = 0;i < n;i++){
        if(search(a[i])){
            //or int temp = a[i].size();
            if(len < (int)a[i].size()){
                len = a[i].size();
                ans = a[i];
            }
            else if(len == (int)a[i].size()){
                if(ans > a[i]){
                    ans = a[i];
                }
            }
        }
    }
    return ans;

}

int main(){
    int n = 6;
    vector<string> arr = {"n", "ni", "nin", "ninj", "ninja", "ninga"};
    
    cout << completeString(n,arr);
    
} 