/* 
    Count no of subsets with given difference 


    you have been given an array and a difference you have to find the 
    maximum number of 2 subset whoes Subset sum diffrence 
    (S1-S2) = diff(given)

    Let sum of subset 1 be s1 and subset 2 with s2
    s1 - s2 = diff (given)
    s1 + s2=sum of array (logical)
    Therefore adding both eq we get :
    2s1= diff + sum of array
    s1= (diff + sum of array)/2;
    Problem reduces to find no of subsets with given sum**
*/

#include<bits/stdc++.h>

using namespace std;

int subsetSumCount(int arr[],int n,int sum){
    
    int t[n+1][sum+1];
    for(int i =0;i<=sum;i++)
        t[0][i] = 0;
    for(int i=0;i<=n;i++)
        t[i][0] = 1;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=sum;j++){
            if(j>=arr[i-1])
                t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
            else
                t[i][j] = t[i-1][j];
        }
    }
    return t[n][sum];
}

int findTargetSumWays(int arr[],int n,int target){
    int sum = arr[0];
        for(int i = 1;i<n;i++)
            sum +=arr[i];
    if(target>sum or (sum+target)%2 !=0 )
        return 0;
    if(target<0 && target < -sum)
        return 0;    
    return subsetSumCount(arr,n,(sum+target)/2);
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++)
        cin>>arr[i];
    int diff;
    cin>>diff;
    cout<<findTargetSumWays(arr,n,diff);
    return 0;
}