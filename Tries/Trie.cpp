#include<bits/stdc++.h>
#define maxC 26
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

int getVal(char c){
    return (c - 'a');
}

void insert(string word){
    Node *temp_root = root;
    for(int i = 0;i < word.size();i++){
        int char_val = getVal(word[i]);
        if(temp_root -> childes[char_val] == NULL)
        {
            temp_root -> childes[char_val] = new Node(false);
        }
        temp_root = temp_root -> childes[char_val];
    }
    temp_root -> flag = true;
}

bool search(string word){
    Node *temp_root = root;
    int i;
    for(i = 0;i < word.size();i++){
        int char_val = getVal(word[i]);
        if(temp_root -> childes[char_val] == NULL){
            break;
        }
        temp_root = temp_root -> childes[char_val];
    }
    return temp_root -> flag and i == word.size(); // why and condition here ? insert hello and search hello,helloa both true because of this added and condition
}

bool start_with(string word){
    Node *temp_root = root;
    for(int i = 0;i < word.size();i++){
        int char_val = getVal(word[i]);
        if(temp_root -> childes[char_val] == NULL){
            return false;
        }
        temp_root = temp_root -> childes[char_val];
    }
    return true;
}


int main(){
    insert("apple");
    cout << search("apple") << " ";
    cout << search("app") << " ";
    cout << start_with("app") << " ";
    insert("app");
    cout << search("app") << " ";
    
}