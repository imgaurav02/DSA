#include<bits/stdc++.h>

using namespace std;

int merge(int arr[],int l,int mid,int h){
    int i=l,j=mid+1,k=l;
    int b[h+1];
    while(i<=mid && j<=h){
        if(arr[i]<arr[j])
            b[k++] = arr[i++];
        else
            b[k++] = arr[j++];
    }
    for(;i<=mid;i++){
        b[k++] = arr[i];
    }
    for(;j<=h;j++){
        b[k++] = arr[j];
    }
    for(i=l;i<=h;i++){
        arr[i] = b[i];
    }
}

void merge_sort(int arr[],int l,int h){
    int mid;
    if(l<h){
        mid = (l+h)/2;
        merge_sort(arr,l,mid);
        merge_sort(arr,mid+1,h);
        merge(arr,l,mid,h);
    }
}

int main(){

    int arr[] = {38,27,43,3,9,82,10};
    merge_sort(arr,0,6);
    for(int i=0;i<7;i++)
        cout<<arr[i]<<" ";
    return 0;
}