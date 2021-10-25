#include<bits/stdc++.h>
using namespace std;
#define INPUT freopen("input.txt","r",stdin);
#define OUTPUT freopen("output.txt","w",stdout);
#define loop(i,a,b) for(int i = a;i<b;i++)
#define looprev(i,a,b) for(int i = a;i>=b;i--)
#define mid(l,r) (l+(r-l)/2)
#define ll long long int
#define vi vector<int>

int rotateTime(vi arr,int n){
    int l = 0, h = n - 1;
    while(l  <= h){
        int m = mid(l,h);
        int next = (m + 1) % n;
        int prev = (m + n - 1) % n;
        if(arr[m] < arr[prev] and arr[m] < arr[next])
            return m;
        if(arr[prev] < arr[next])
            h = m-1;
        else
            l = m+1; 
    }
}

int main(){
    INPUT
    OUTPUT
    int n;
    cin>>n;
    vi arr(n);
    loop(i,0,n)
        cin>>arr[i];
    cout<<rotateTime(arr,n);
    return 0;
}