/* 
    Given an array arr[] of size N and an integer K.
    Find the maximum for each and every contiguous subarray of size K.

    Input:
    N = 9, K = 3
    arr[] = 1 2 3 1 4 5 2 3 6
    Output: 
    3 3 4 5 5 5 6 
    Explanation: 
    1st contiguous subarray = {1 2 3} Max = 3
    2nd contiguous subarray = {2 3 1} Max = 3
    3rd contiguous subarray = {3 1 4} Max = 4
    4th contiguous subarray = {1 4 5} Max = 5
    5th contiguous subarray = {4 5 2} Max = 5
    6th contiguous subarray = {5 2 3} Max = 5
    7th contiguous subarray = {2 3 6} Max = 6
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> max_of_subarrays(vector<int> arr,int n,int k){
    vector<int> res;
    deque<int> Q;
    int i =0,j = 0;
    while(j<n){
        while(!Q.empty() && Q.back() < arr[j])
            Q.pop_back();
        Q.push_back(arr[j]);
        if(j - i +1 <k)
            j++;
        else if(j - i + 1 == k){
            res.push_back(Q.front());
            if(arr[i] == Q.front())
                Q.pop_front();
            i++;j++;
        }
    }
    return res;
}

int main(){
    int n,k;
    cin>>n;
    vector<int> arr(n);
    for(int i =0;i<n;i++)
        cin>>arr[i];
    cin>>k;
    vector<int> res;
    res = max_of_subarrays(arr,n,k);
    for(int i  =0;i<res.size();i++)
        cout<<res[i]<<" ";
}