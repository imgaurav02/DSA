/* 
    First negative integer in every window of size k 
    Given an array A[] of size N and a positive integer K, 
    find the first negative integer for each and every window(contiguous subarray) of size K.
    Input : 
    N = 5
    A[] = {-8, 2, 3, -6, 10}
    K = 2
    Output : 
    -8 0 -6 -6
    Explanation :
    First negative integer for each window of size k
    {-8, 2} = -8
    {2, 3} = 0 (does not contain a negative integer)
    {3, -6} = -6
    {-6, 10} = -6

*/

#include<bits/stdc++.h>
using namespace std;

vector<int> firstNegative(vector<int> arr,int n,int k){
    vector<int> res;
    queue <int> Q;
    int i = 0,j  = 0;
    while(j<n){
        if(arr[j] < 0) Q.push(arr[j]);
        if(j - i + 1 < k) 
            j++;
        else if(j - i + 1 >= k){
            if(Q.empty())
                res.push_back(0);
            else
                res.push_back(Q.front());
            if(arr[i] == Q.front())
                Q.pop();
            i++; j++;
        }

    }
    return res;
}

int main(){
    int n,k;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0;i<n;i++)
        cin>>arr[i];
    cin>>k;
    vector<int> res;
    res = firstNegative(arr,n,k);
    for(int i = 0;i< res.size();i++)
        cout<<res[i]<<" ";
}