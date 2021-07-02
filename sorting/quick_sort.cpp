#include<bits/stdc++.h>

using namespace std;

void swap(int *a,int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


int partition(int arr[],int l,int h){
    int i=l,j=h,pivot=arr[l];
    do{
        do{i++;}while(arr[i]<=pivot);
        do{j--;}while(arr[j]>pivot);
        if(i<j){
            swap(&arr[i],&arr[j]);
        }
    }while(i<j);
    swap(&arr[j],&arr[l]);
    return j;
}

void quick_sort(int arr[],int l,int h){
    int mid;
    if(l<h){
        mid = partition(arr,l,h);
        quick_sort(arr,l,mid);
        quick_sort(arr,mid+1,h); 
    }
}

int main(){
    int n;
    cout<<"How Many elements in array: ";
    cin>>n;
    int arr[n+1];
    arr[n] = __INT32_MAX__;
    cout<<"Enter the elements of array: ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    quick_sort(arr,0,n);
    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    

}