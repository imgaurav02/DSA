/* 
    Given a set of integers, the task is to divide it into two sets S1 and S2 
    such that the absolute difference between their sums is minimum. 
    If there is a set S with n elements, 
    then if we assume Subset1 has m elements, 
    Subset2 must have n-m elements and the value of abs(sum(Subset1) – sum(Subset2)) should be minimum.


    Input:  arr[] = {1, 6, 11, 5} 
    Output: 1
    Explanation:
    Subset1 = {1, 5, 6}, sum of Subset1 = 12 
    Subset2 = {11}, sum of Subset2 = 11    
    
        
    what's the idea i am implimenting..

    here i m first do the sum of whole array
    by doing it i will find it the subset difference will surely ly b/w  0 to sum
    let sum of subset1 = s1 and sum of subset2 = s2
    so
        s2 + s1 = sum
        s2 - s1 = min
    ---------------------
        (minus) 2s1 = sum - min
        min = sum - 2s1 

        here we will find apply the subset sum to get the s1 because the subset sum last row half sub array will 
        give us the s1 the we can easily calculate it
*/

#include<bits/stdc++.h>

using namespace std;


int minSubsetDiff(int arr[],int n,int sum){

    //Subset Sum code
    bool t[n+1][sum+1];
    for(int i = 0;i<=sum;i++)
        t[0][i] = false;
    for(int i = 0;i<=n;i++)
        t[i][0] = true;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=sum;j++){
            if(j>=arr[i-1])
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            else
                t[i][j] = t[i-1][j];
        }
    }

    // calculating the min diff
    int min_diff = INT_MAX;
    for(int i = sum/2 ; i>=0 ; i--)
    {
        if(t[n][i]){
            min_diff = sum - 2*i;
            break;
        }
    }    
    return min_diff;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int sum = arr[0];
    for(int i=1;i<n;i++)
        sum +=arr[i];
    cout<<minSubsetDiff(arr,n,sum);
    return 0;
}