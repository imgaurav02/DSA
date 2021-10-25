/* 
    Given and sorted array and a key
    you have to first and last occurence of that key
    if not repeated the first and last occurence will be same
    if key not find both occurence wil be -1
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
    cout<<"First Occurence of "<<key<< " at index : "<<first<<"\n";
    cout<<"Last Occurence of "<<key<< " at index : "<<last;
    return 0;
    }
    cout<<"Not Found";
    return 0;
}