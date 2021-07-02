#include<bits/stdc++.h>

using namespace std;


void swap(int arr[],int i,int j){
    int temp;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

//bubble sort is not adaptive to we have to make it adaptive by introducing the flag variable

void bubble_sort(int arr[],int n){
    int flag;
    for(int i=0;i<n-1;i++){
        flag = 1;
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){

                swap(arr,j,j+1);
                flag=0;
            }
        }
        if(flag){
            break;
        }
    }
}

int main(){
    int arr[]={1,2,3,4,6};
    for(int i=0;i<5;i++)
        cout<<arr[i]<<" ";
    bubble_sort(arr,5);
    cout<<endl;
    for(int i=0;i<5;i++)
        cout<<arr[i]<<" ";
}