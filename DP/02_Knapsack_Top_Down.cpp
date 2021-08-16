/* 
    Top Down code for 01 knapsack
*/


#include<bits/stdc++.h>
using namespace std;

int Knapsack(int wt[],int val[],int W,int n){
    int t[n+1][W+1];
    // intializing the table
    for(int i=0;i<=W;i++)
        t[0][i] = 0;
    for(int i=0;i<=n;i++)
        t[i][0] = 0;
    
    // filling whole table

    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=W;j++){
            if(j>=wt[i-1]){
                t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]],t[i-1][j]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[n][W];
}

int main(){
    int n,W;
    //enter the size of weight and value array
    cin>>n;
    int wt[n],val[n];
    //taking input for weight and value array
    for(int i=0;i<n;i++)
        cin>>wt[i];
    for(int i=0;i<n;i++)
        cin>>val[i];
    //taking input capacity of bag
    cin>>W;
    cout<<Knapsack(wt,val,W,n);
}