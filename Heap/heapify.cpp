
#include<bits/stdc++.h>

using namespace std;



// this is method to create heap using heapify method this takes O(n) time by normal method it takes O(nlogn) time 

void heapify(int arr[],int n,int i){
    if(2*i<n){
        int x=arr[i];
        int largest=i,j=2*i;
        if(arr[j]<arr[j+1])
            j++;
        if(arr[largest]<arr[j]){
            arr[largest]=arr[j];
            arr[j]=x;
            largest=j;
        }
        heapify(arr,n,largest);

    }
    return;
}

void heap(int arr[],int n){
    int start_heapify = (n/2)-1;
    for(int i=start_heapify;i>=1;i--){
        heapify(arr,n,i);
    }
}

int main(){
    int arr[] ={0,5,1,50,85,36,12,96};
    for(int i=1;i<8;i++)
        cout<<arr[i]<<" ";
    heap(arr,8);
    cout<<endl;
    for(int i=1;i<8;i++)
        cout<<arr[i]<<" ";
}