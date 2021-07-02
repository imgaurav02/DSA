#include<iostream>
using namespace std;

void swap(int *a,int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int arr[],int n){
    int i,j,k;
    for(i=0;i<n-1;i++){
        j=i;
        for(k=i+1;k<n;k++){
            if(arr[k]<arr[k-1]){
                j=k;
            }
        }
        swap(&arr[i],&arr[j]);
    }
}

int main(){
    int n;
    cout<<"How Many elements in array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of array: ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    selection_sort(arr,n);
    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    

}