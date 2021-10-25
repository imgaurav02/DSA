/*
    Unbounded Knapsack (Repetition of items allowed)
    Given a knapsack weight W and a set of n items with certain value vali and weight wt,
    we need to calculate the maximum amount that could make up this quantity exactly.
    This is different from classical Knapsack problem, 
    here we are allowed to use unlimited number of instances of an item.
    Input : W = 100
       val[]  = {1, 30}
       wt[] = {1, 50}
    Output : 100
    There are many ways to fill knapsack.
    1) 2 instances of 50 unit weight item.
    2) 100 instances of 1 unit weight item.
    3) 1 instance of 50 unit weight item and 50
    instances of 1 unit weight items.
    We get maximum value with option 2.

    Input : W = 8
        val[] = {10, 40, 50, 70}
        wt[]  = {1, 3, 4, 5}       
    Output : 110 
    We get maximum value with one unit of
    weight 5 and one unit of weight 3.
 */


#include<bits/stdc++.h>
using namespace std;
#define INPUT freopen("input.txt","r",stdin);
#define OUTPUT freopen("output.txt","w",stdout);
#define loop(i,a,b) for(int i = a;i<b;i++)
#define looprev(i,a,b) for(int i = a;i>=b;i--)
#define mid(l,r) (l+(r-l)/2)
#define ll long long int
#define vi vector<int>

//memomization

//you can make the dp array by checking the constraints
int dp[1000+1][1000+1];

int unbounded_knapsack(int wt[],int val[],int W,int n){
    if(W <= 0 or n <=0)
        return 0;
    if(dp[n][W] != -1)
        return dp[n][W];
    if(W>=wt[n-1])
        return dp[n][W] =  max(val[n-1] + unbounded_knapsack(wt,val,W-wt[n-1],n),unbounded_knapsack(wt,val,W,n-1));
    else
        return dp[n][W] = unbounded_knapsack(wt,val,W,n-1);
}

int top_down(int wt[],int val[],int W,int n){
    int t[n+1][W+1];
    loop(i,0,n+1){
        loop(j,0,W+1){
            if(i == 0 or j  == 0)
                t[i][j] = 0;
            else if(j>=wt[i-1]){
                t[i][j] = max(val[i-1] + t[i][j-wt[i-1]],t[i-1][j]);
            }
            else
                t[i][j] = t[i-1][j];
        }
    }
    return t[n][W];
}

int main(){
    memset(dp,-1,sizeof(dp));
    INPUT
    OUTPUT
    int n;
    cin>>n;
    int wt[n],val[n];
    loop(i,0,n)
        cin>>wt[i];
    loop(i,0,n)
        cin>>val[i];
    int bag;
    cin>>bag;
    cout<<unbounded_knapsack(wt,val,bag,n)<<endl;
    cout<<top_down(wt,val,bag,n);
    return 0;
}