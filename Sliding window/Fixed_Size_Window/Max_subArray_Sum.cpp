/* 
    problem Statement: 
    we have been given an array and a window size ie k and we have to return the max sum
    of k subarrays in that array

    arr[] :: [2 5 1 8 2 9 1]
    n : len of array
    k : window size

    return max sum of k size sub array
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

int maxSubarraySum(int arr[],int n,int k)
{
    int i = 0,j = 0,sum = 0,max = INT_MIN;
    while(j<n){
        sum = sum + arr[j];  //doing calculation
        // arr[] :: [2 5 1 8 2 9 1]
        if(j-i+1 < k){
            j++;
        }
        else if(j-i+1 >= k) {
            if(max < sum) max = sum;  // storing required answers
            sum -=arr[i];   //removing calculations for leaving element
            i++;j++;
        }
    }
    return max;
}

int main(){
    INPUT
    OUTPUT

    int n;
    cin>>n;
    int arr[n];
    
    for(int i =0;i<n;i++){
        cin>> arr[i];
    }
    int k;
    cin>>k;
    cout<<maxSubarraySum(arr,n,k);
    return 0;
}
