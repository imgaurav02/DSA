/* 
    what is knapsack?
    in this probelem you have a bag which can hold weight W and you have given 2 array of n sized
    1st array is weight array : this contains the weight of items
    2nd array is value array : this contains the value(price) of each item.

    your task?
        choose that item which gives you max profit

    why it is called 01 knapsack problem?
    because you have only 2 choice take it or leave it that's why you can't take items in part

    how to identify it's Dp problem?
    1. because have choice for each element to take it or leave it
    2. it says to maximize the profit

    why it's important?
    because it's an standard problem of Dp understanding this you will be getting the solution
    of various probelm by doing small variation on this code
*/

#include<bits/stdc++.h>
using namespace std;

int knapsack(int wt[],int val[],int W,int n)
{
    if(n == 0 || W == 0)
        return 0;
    if(W>=wt[n-1]){
        return max(val[n-1] + knapsack(wt,val,W-wt[n-1],n-1),knapsack(wt,val,W,n-1));
    }
    else{
        return knapsack(wt,val,W,n-1);
    }
}

// upper knapsack problem calling itself 2^n times to reduce we are going to create memozize version

int t[100][100];


int M_knapsack(int wt[],int val[],int W,int n)
{
    if(t[n][W] != -1)
        return t[n][W];
    if(n == 0 || W == 0)
        return 0;
    
    if(W>=wt[n-1]){
        return t[n][W] = max(val[n-1] + knapsack(wt,val,W-wt[n-1],n-1),knapsack(wt,val,W,n-1));
    }
    else{
        return t[n][W] = knapsack(wt,val,W,n-1);
    }
}

int main(){
    memset(t,-1,sizeof(t));
    int n;
    cin>>n;
    int wt[n],val[n]; //weight and value array for n items
    for(int i=0;i<n;i++)
        cin>>wt[i];
    for(int i=0;i<n;i++)
        cin>>val[i];
    int W; // capacity of bag
    cin>>W;

    cout<<M_knapsack(wt,val,W,n);

}