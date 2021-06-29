#include<bits/stdc++.h>

using namespace std;

void delheap(int arr[],int n){
    int i=1,x=arr[1];
    int j=2*i,temp;
    arr[i] = arr[n];
    while(j<=n-1){
    temp = arr[i];
    if(arr[j]>arr[j+1])
        j++;
    if(arr[i]>arr[j]){
        arr[i] = arr[j];
        arr[j] = temp;
    }
    i=j;
    j=2*i;
    }
    arr[n]=x;
}


void makeheap(int arr[],int n){
    int i=n,temp = arr[n];
    while(i>1 && temp<arr[i/2]){
        arr[i] = arr[i/2];
        i = i/2;
    }
    arr[i]=temp;
}

void heap(int arr[],int n){
    int i;
    for(i=2;i<n;i++){
        makeheap(arr,i);
    }
    for(i=1;i<n;i++){
        delheap(arr,n-i);
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