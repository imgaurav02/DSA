/*

    Problem Statement: you have been given an n size array and and you have to find is there
    is any subsets present whoes sum is equal.

    Test case 1:
    arr[] = {1, 5, 11, 5}
    Output: true 
    The array can be partitioned as {1, 5, 5} and {11}

    Test case 2:
    arr[] = {1, 5, 3}
    Output: false 
    The array cannot be partitioned into equal sum sets.

    approch
    the very basic thing is that you can only devide array in 2 eqaul subset sum if
    the sum of array is even.
    now if(even)
        let s1 -> subset 1 & s2 -> subset 2
        so s1 - s2 = 0 ---1
        &  s1 + s2 = sum of aaray ---2
        so 2s1 = sum
        so s1 = sum/2
        now this problem is break into subset sum where you have to find is sum/2
        subset is possible in array or not.

 */


#include<bits/stdc++.h>
using namespace std;

bool TD_SubsetSum(int arr[],int n,int sum){
    bool table[n+1][sum+1];
    for(int i=0;i<=sum;i++)
        table[0][i] = false;
    for(int i=0;i<=n;i++)
        table[i][0] = true;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(j >= arr[i-1])
                table[i][j] = table[i-1][j-arr[i-1]] || table[i-1][j];
            else
                table[i][j] = table[i-1][j];
        }
    }
    return table[n][sum];
}

bool EqualSum(int arr[],int n){
    int sum = arr[0];
    for(int i=1;i<n;i++)
        sum +=arr[i];
    if(!(sum&1))
        return TD_SubsetSum(arr,n,sum/2);
    else
        return false;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<EqualSum(arr,n);
}