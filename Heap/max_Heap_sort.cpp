#include<bits/stdc++.h>

using namespace std;

void deleteheap(int [],int);


// creating max heap
void sort(int arr[],int n){
    int temp=arr[n],i=n;
    while(i>1 && temp>arr[i/2]){
        arr[i] = arr[i/2];
        i=i/2;
    }
    arr[i]=temp;
}

void heap(int arr[],int n){
    int i;
    for(i=2;i<n;i++){
        sort(arr,i);
    }
    
    for(i=1;i<n-1;i++){
        deleteheap(arr,n-i);
    }
}

void deleteheap(int arr[],int n){
    int i=1,x=arr[1];
    int j=2*i,temp;
    arr[1] = arr[n];
    
    while(j<=n-1){

    temp = arr[i];
    if(arr[j]<arr[j+1])
        j++;
    if(arr[i]<arr[j])
    {
        arr[i] = arr[j];
        arr[j]=temp;
        i=j;
        j=2*i;
    }
    }
    arr[n]=x;
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