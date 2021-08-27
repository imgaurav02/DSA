/* 
    You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each
 integer in nums and then concatenate all the integers.

For example, 
if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build
 the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.


Example 1:

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
*/

#include<bits/stdc++.h>
using namespace std;

bool isZero(int x){
    return x == 0;
}

int subsetSum(vector<int> &arr,int n,int sum){
    vector<vector<int> > t(n+1, vector<int>(sum+1));
    for(int i =0;i<=sum;i++)
        t[0][i] = 0;
    for(int i =0;i<=n;i++)
        t[i][0] = 1;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=sum;j++){
            if(j>= arr[i-1] && arr[i-1] != 0){
                t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][sum];
}

int TargetSum(vector<int> &arr,int n,int target){
    int sum = accumulate(arr.begin(),arr.end(),0);
    if(target > sum or (sum+target)%2 != 0)
        return 0;
    // it's for if you get -ve numbers as input
    if(target < 0 and target < -sum)
        return 0;
    int zeros = count_if(arr.begin(),arr.end(),isZero);
    return pow(2,zeros) * subsetSum(arr,n,(sum+target)/2);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i =0;i<n;i++)
        cin>>arr[i];
    int target;
    cin>>target;
    cout<<TargetSum(arr,n,target);
    return 0;
}