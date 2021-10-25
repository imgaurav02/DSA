/* 
    here it is not given array is sorted in assending order or in
    decending order
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

int AscSearch(vector<int>arr,int n,int key){
    int l = 0, h = n-1;
    while(l<=h){
        int m = mid(l,h);
        if(arr[m] == key)
            return m;
        else if(arr[m] > key)
            h = m - 1;
        else
            l = m + 1;
    }
    return -1;
}
int descSearch(vector<int>arr,int n,int key){
    int l = 0, h = n-1;
    while(l<=h){
        int m = mid(l,h);
        if(arr[m] == key)
            return m;
        else if(arr[m] > key)
            l = m + 1;
        else
            h = m - 1;
    }
    return -1;
}

int main(){
    INPUT
    OUTPUT
    int n;
    cin>>n;
    vector<int> arr(n);
    loop(i,0,n)
        cin>>arr[i];
    int key;
    cin>>key;
    if(arr[0] > arr[n-1])
    {
        if(descSearch(arr,n,key) != -1){
            cout<<"Found at index : "<<descSearch(arr,n,key);
            return 0;
        }
    }
    else if(arr[0] < arr[n-1]){
        if(AscSearch(arr,n,key) != -1){
            cout<<"Found at index : "<<AscSearch(arr,n,key);
            return 0;
        }
    }
    cout<<"Not Found";
    return 0;
}