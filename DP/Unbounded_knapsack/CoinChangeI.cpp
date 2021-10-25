/* 
    Coin change I
    Given a value N, find the number of ways to make change for N cents,  
    if we have infinite supply of each of S = { S1, S2, .. , SM } valued coins.

    Example 1:

    Input:
    n = 4 , m = 3
    S[] = {1,2,3}
    Output: 4
    Explanation: Four Possible ways are:
    {1,1,1,1},{1,1,2},{2,2},{1,3}.

    basically what's the logic
    if we select any coin then we can again select it again so for selection we not decrease the i value
    if not select then we will decrease the i
*/
#include<bits/stdc++.h>
using namespace std;

int coinChange(int coin[],int n, int sum){
    int dp[n+1][sum+1];
    for(int i =0;i<=sum;i++)
        dp[0][i] = 0;

    for(int i =0;i<=n;i++)
        dp[i][0] = 1;
    for(int i =1;i<=n;i++){
        for(int j = 1;j<=sum;j++){
            if(j>=coin[i-1])
                dp[i][j] = dp[i][j-coin[i-1]] + dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}

int main(){
    int n,sum;
    cin>>n>>sum;
    int coin[n];
    for(int i =0;i<n;i++)
        cin>>coin[i];
    cout<<coinChange(coin,n,sum);
}