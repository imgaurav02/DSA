#include<bits/stdc++.h>

using namespace std;

void odd_occuring(vector <int> arr){

    // defining hash array of size arr and intilizing with 0
    int n=*max_element(arr.begin(),arr.end());
    vector <int> h(n+1,0);

    for (int i = 0; i < arr.size(); i++)
    {
        h[arr[i]]++;
    }
    
    for(int i=0;i<h.size();i++){
        // cout<<h[i]<<" ";
        if((h[i] & 1))
        {
            cout<<i<<" ";
        }
    }
}

int main(){
    vector <int> a;
    // a={1, 2, 3, 2, 3, 1, 3};
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(2);
    a.push_back(3);
    a.push_back(1);
    a.push_back(3);
    a.push_back(5);
    a.push_back(2);
    odd_occuring(a);
}