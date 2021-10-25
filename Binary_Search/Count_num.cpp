/* 
    Given a sorted array and a key
    you have to count the number of times that number occured
    
    if(not present) then print 0

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

int BinSearchF(vi arr,int n,int key){
    int l = 0,h  = n-1;
    int res = -1;
    while(l <= h){
        int m = mid(l,h);
        if(arr[m] == key){
            res = m;
            h = m - 1;
        }
        else if(arr[m] > key)
            h = m - 1;
        else
            l = m + 1;
    }
    return res;
}

int BinSearchL(vi arr,int n,int key){
    int l = 0,h  = n-1;
    int res = -1;
    while(l <= h){
        int m = mid(l,h);
        if(arr[m] == key){
            res = m;
            l = m + 1;
        }
        else if(arr[m] > key)
            h = m - 1;
        else
            l = m + 1;
    }
    return res;
}

int main(){
    INPUT
    OUTPUT
    int n;
    cin>>n;
    vi arr(n);
    loop(i,0,n)
        cin>>arr[i];
    int key;
    cin>>key;
    int first = BinSearchF(arr,n,key);
    int last = BinSearchL(arr,n,key);
    if(first != -1){
    cout<<(last - first + 1);
    return 0;
    }
    cout<<0;
    return 0;
}