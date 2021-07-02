#include<bits/stdc++.h>

using namespace std;


void insertnsort(int arr[],int n){
    int x,j,i;
    for(i=1;i<n;i++){
        x=arr[i];
        j=i-1;
        while(j>-1 && x<arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1]=x;
    }
}

int main(){
    int arr[]={1,2,3,4,6};
    for(int i=0;i<5;i++)
        cout<<arr[i]<<" ";
    insertnsort(arr,5);
    cout<<endl;
    for(int i=0;i<5;i++)
        cout<<arr[i]<<" ";
}
