#include<bits/stdc++.h>

using namespace std;

int findmax(int arr[],int n){
    int max = arr[0];
    for(int i=1;i<n;i++){
        if(max<arr[i])
            max = arr[i];
    }
    return max;
}

void bin_sort(int arr[],int n){
    int max,i,j;
    max = findmax(arr,n);
    list<int> *bins[max+1];
    for(i=0;i<max+1;i++)
        bins[i] = NULL;
    for(i=0;i<n;i++){
        bins[arr[i]]->push_front(arr[i]);    
    }
    i=0,j=0;
    while (i<max+1)
    {
        while(bins[i]!=NULL){
            arr[j++] = bins[i]->front();
            bins[i]->pop_back();

        }
        i++;
    }
    
}

int main(){
    int arr[] = {5,4,1,2,7,6,3};
    bin_sort(arr,7);
    for(int i=0;i<7;i++)
        cout<<arr[i]<<" ";
    return 0;
}