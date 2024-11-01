#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    Node* c[2] = {NULL};
    int val;
};

Node *root = new Node;

void add(int a){
    Node *temp_root = root;
    for(int i = 31;i >= 0;i--){
        int bit = ((a >> i) & 1);
        if(!temp_root -> c[bit]){
            temp_root -> c[bit] = new Node;
        }
        temp_root = temp_root -> c[bit];
    }
    temp_root -> val = a;
}

int get_maxXOR(int a){
    Node *temp_root = root;
    int ans = 0;
    int t = 1;
    for(int i = 31;i >= 0;i--)
    {
        int bit = ((a >> i) & 1);
        //search for opposite sign toget max XOR because 0 ^ 1 = 1
        bit = !bit;
        if(temp_root -> c[bit]){
            // if found opposite sign setting that bit to 1
            ans = (ans | (t << i));
        }
        else{
            //else getting original bit to move in correct direction
            bit = !bit;
        }
        temp_root = temp_root -> c[bit];
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0;i < n;i++)
        cin >> arr[i];
    int maxxor = INT_MIN;
    for(int i : arr){
        add(i);
    }
    for(int i : arr){
        maxxor = max(maxxor,get_maxXOR(i));
    }
    cout << maxxor;
    return 0;
}