#include <bits/stdc++.h>
using namespace std;

void insertEle(vector<int> &arr,int ele){
    if(arr.size() == 0 or arr[arr.size()-1] < ele){
        arr.push_back(ele);
        return;
    }
    int temp = arr[arr.size()-1];
    arr.pop_back();
    insertEle(arr,ele);
    arr.push_back(temp);
}

void Sortarr(vector<int> &arr){
    if(arr.size()==1)
        return;
    int ele = arr[arr.size()-1];
    arr.pop_back();
    Sortarr(arr);
    insertEle(arr,ele);
}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0;i<n;i++)
        cin>>arr[i];
    Sortarr(arr);
    for(int i = 0;i<n;i++)
        cout<<arr[i]<<" ";
}
