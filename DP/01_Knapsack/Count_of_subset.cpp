/* Given an array arr[] of length N and an integer X, 
the task is to find the number of subsets with a sum equal to X. 
        Input: arr[] = {1, 2, 3, 3}, X = 6 
        Output: 3 
        All the possible subsets are {1, 2, 3}, 
        {1, 2, 3} and {3, 3}

        Input: arr[] = {1, 1, 1, 1}, X = 1 
        Output: 4 
*/

#include<bits/stdc++.h>
using namespace std;

int countSubset(int wt[],int n,int sum){
    int t[n+1][sum+1];
    for(int i=0;i<=sum;i++)
        t[0][i] = 0;
    for(int i=0;i<=n;i++)
        t[i][0] = 1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(j>=wt[i-1])
                t[i][j] = t[i-1][j-wt[i-1]] + t[i-1][j];
            else
                t[i][j] = t[i-1][j];
        }
    }
    return t[n][sum];
    
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int sum;
    cin>>sum;
    cout<<countSubset(arr,n,sum);
    return 0;
}