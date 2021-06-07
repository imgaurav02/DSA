// { Driver Code Starts
//Initial Template for C

#include <stdio.h>


 // } Driver Code Ends
//User function Template for C

void swap(int *p,int *q){
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}
void sort012(int a[], int n)
{
    int low=0,mid=0,high=n-1;
    for(;mid<=high;){
        if(a[mid]==0){
            swap(&a[mid],&a[low]);
            low++; mid++;
        }
        else if(a[mid]==2){
            swap(&a[mid],&a[high]);
            high--;
        }
        else
            mid++;
    }
}

// { Driver Code Starts.

int main() {

    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);
        int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d", &arr[i]);
        }

        sort012(arr, n);

        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    return 0;
}
  // } Driver Code Ends