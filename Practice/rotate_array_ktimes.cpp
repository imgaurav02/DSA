#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,b) for(int i=a;i<b;i++)
void Krotation(int arr[],int n,int k)
{
    int temp;
    while(k--){
        temp = arr[0];
        for(int i=1;i<n;i++){
            arr[i-1] = arr[i];
        }
        arr[n-1] = temp;
    }
}

int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    Krotation(arr,n,k);

    loop(i,0,n)
        cout<<arr[i]<<" ";
    
    return 0;
}