/* 
    Given a rod of length n inches and an array of prices that includes prices of all 
    pieces of size smaller than n.
    Determine the maximum value obtainable by cutting up the rod and selling the pieces.
    For example,
    if the length of the rod is 8 and the values of different pieces are given
    as the following, 
    length   | 1   2   3   4   5   6   7   8  
    --------------------------------------------
    price    | 1   5   8   9  10  17  17  20
    then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6) 

    And if the prices are as following,
    length   | 1   2   3   4   5   6   7   8  
    --------------------------------------------
    price    | 3   5   8   9  10  17  17  20
    then the maximum obtainable value is 24 (by cutting in eight pieces of length 1) 
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

int rod_cutting(int n,int rod_size,int length[],int value[]){
    int t[n+1][rod_size+1];
    loop(i,0,n+1){
        loop(j,0,rod_size+1){
            if(i == 0 or j == 0)
                t[i][j] = 0;
            else if(j >= length[i-1])
                t[i][j] = max(value[i-1] + t[i][j-length[i-1]],t[i-1][j]);
            else
                t[i][j] = t[i-1][j];
        }
    }
    return t[n][rod_size];
}

int main(){
    INPUT
    OUTPUT
    int rod_size;
    cin>>rod_size;
    int n;
    cin>>n;
    int length[n],value[n];
    loop(i,0,n)
        cin>>length[i];
    loop(i,0,n)
        cin>>value[i];
    cout<<rod_cutting(n,rod_size,length,value);
    return 0;
}