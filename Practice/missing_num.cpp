#include<bits/stdc++.h>
using namespace std;

void missing_num(vector<int> arr){
    int max=*max_element(arr.begin(),arr.end());
    vector<int> h(max+1,0);

    for(int i=0;i<arr.size();i++){
        h[arr[i]]++;
    }
    for (int i = arr[0]; i < max; i++)
    {
        if(h[i]==0){
            cout<<i<<" ";
        }
    }
    
}

int main(){
    vector <int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(4);
    a.push_back(6);
    a.push_back(8);
    // a.push_back(7);
    a.push_back(3);
    missing_num(a);
    return 0;

}