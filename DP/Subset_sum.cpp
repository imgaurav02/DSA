/* 
    You have been iven an array & a sum is given you have to return true/false
    
    Test Case 1:
    Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 9
    Output: True  
    There is a subset (4, 5) with sum 9.

    Test Case 2:
    Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 30
    Output: False
    There is no subset that add up to 30.
*/

//first i am writing the recursive code
bool SubsetSum(int arr[],int n,int sum){
    if(n >= 0 && sum == 0)
        return true;
    if(n==0 && sum>0)
        return false;
    
    if(sum >= arr[n-1])
        return SubsetSum(arr,n-1,sum-arr[n-1]) || SubsetSum(arr,n-1,sum);
    else
        return SubsetSum(arr,n-1,sum);
}

//memonize  version 
static int table[105][100005];
    
bool M_SubsetSum(int arr[],int n,int sum){
    if(table[n][sum] != -1)
        return table[n][sum];
    if(n >= 0 && sum == 0)
        return table[n][sum] = true;
    if(n==0 && sum>0)
        return table[n][sum] = false;
    
    if(sum >= arr[n-1])
        return table[n][sum] = SubsetSum(arr,n-1,sum-arr[n-1]) || SubsetSum(arr,n-1,sum);
    else
        return table[n][sum] = SubsetSum(arr,n-1,sum);
}


//Top Down 
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

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,sum;
    memset(table,-1,sizeof(table));
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cin>>sum;
    cout<<TD_SubsetSum(arr,n,sum);
}