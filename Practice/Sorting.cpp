#include<bits/stdc++.h>

using namespace std;

#define INPUT freopen("input.txt","r",stdin);
#define OUTPUT freopen("output.txt","w",stdout);
#define loop(i,a,b) for(int i = a;i<b;i++)
#define looprev(i,a,b) for(int i = a;i>=b;i--)
#define mid(l,r) (l+(r-l)/2)
#define ll long long int
#define vi vector<int>

void mySwap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
  // Heap sort start
void maxHeap(vi &arr,int n){
    int temp = arr[n],i = n;
    while(i>0 and temp > arr[i/2])
    {
        arr[i] = arr[i/2];
        i /=2;
    }
    arr[i] = temp;
}

void delHeap(vi &arr,int n){
    int last  = arr[0],i = 0;
    int j = 2*i+1;
    arr[0] = arr[n];
    while(j<=n-1){
        int temp = arr[i];
        if(arr[j] < arr[j+1])
            j++;
        if(arr[j] > arr[i]){
            arr[i] = arr[j];
            arr[j] = temp;
            i = j;
            j = 2*i+1;
        }
        else
            break;
    }
    arr[n] = last;
}

void createHeap(vi arr,int n){
    loop(i,1,n){
        maxHeap(arr,i);
    }
    loop(i,1,n)
        delHeap(arr,n-i);
    loop(i,0,n)
        cout<<arr[i]<<" ";
}
/// ---------- Heap Sort Ends -------------------

/// ---------- Bubble Sort Start -------------------
void BubbleSort(vi arr,int n){
    loop(i,0,n-1){
        loop(j,0,n-1-i){
            if(arr[j]>arr[j+1])
                mySwap(&arr[j],&arr[j+1]);
        }
    }
    loop(i,0,n)
        cout<<arr[i]<<" ";
}

/// ---------- Bubble Sort Ends -------------------


/// ---------- Insertion Sort Start -------------------
void sorted_insert(vi &arr,int ele,int n){
    if(n == 0 or arr[n-1] < ele)
    {
        arr.push_back(ele);
        return;
    }
    int temp = arr[n-1];
    arr.pop_back();
    sorted_insert(arr,ele,n-1);
    arr.push_back(temp);
}

void insertion_sort(vi &arr,int n){
    if(n == 1)
        return;
    int temp = arr[n-1];
    arr.pop_back();
    insertion_sort(arr,n-1);
    sorted_insert(arr,temp,n-1);
}

/// ---------- Insertion Sort Ends -------------------

// --------------- Quick Sort Start -------------------------

int partition(vi &arr,int l,int h){
    int i = l,j  = h,pivote = arr[l];
    do{
        do{ i++;}while(arr[i]<=pivote);
        do{ j--;}while(arr[j]>=pivote);
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }while(i<j);
    swap(arr[l],arr[j]);
    return j;
}
void Quick_sort(vi &arr,int l,int h){
    int j;
    while(l<h){
        j = partition(arr,l,h);
        Quick_sort(arr,l,j);
        Quick_sort(arr,j+1,h);
    }
}

// ---------------- Quick Sort Ends ------------------------

int main() {
    INPUT
    OUTPUT
    int n;
    cin>>n;
    vi arr(n+1);
    loop(i,0,n)
        cin>>arr[i];
    arr[n] = INT_MAX;
    // BubbleSort(arr,n);
    // createHeap(arr,n);
    // insertion_sort(arr,n);
    loop(i,0,n)
        cout<<arr[i]<<" ";
    Quick_sort(arr,0,n);
    return 0;
}