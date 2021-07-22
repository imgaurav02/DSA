#include<bits/stdc++.h>

using namespace std;

void count_sort(int arr[],int n){
    int max=arr[0];
    for(int i=1;i<n;i++){
        if(max<arr[i])
            max = arr[i];
    }
    int temp[max+1] = {0};
    for(int i=0;i<n;i++){
        temp[arr[i]]++;
    }
    for(int i=0,j=0;i<max+1;i++){
        while (temp[i]>0)
        {
            arr[j++] = i;
            temp[i]--;
        }
        
    }


}

int main(){
    int arr[] = {38,27,43,3,9,82,10};
    count_sort(arr,7);
    for(int i=0;i<7;i++)
        cout<<arr[i]<<" ";
    return 0;
}