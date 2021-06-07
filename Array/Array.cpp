// #include<iostream>
#include<bits/stdc++.h> //this will include all the c++ standard libary including iostream
using namespace std;

// defing the dynamic array 
class Array
{
public:
    int *a;
    int size,length;
    void display();
};
// display fxn using scope resulation operator
void Array::display(){
    for (int i = 0; i < length; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

//appending the element at the end of array
void append(Array *arr,int x){
    arr->a[arr->length] = x;
    arr->length++;
}

//inserting the element at the given index of array
void insert(Array *arr,int index,int x){
    if(index<arr->size && index<=arr->length && index>=0){
        for (int i = arr->length; i > index; i--)
        {
            arr->a[i] = arr->a[i-1];
        }
        arr->a[index]=x;
        arr->length++;
        
    }
}

//deleting the element from the given index of an array
int del(Array *arr,int index){
    int x;
    x = arr->a[index];
    if(index<arr->size && index<arr->length && index>=0){
        for (int i = index; i < arr->length-1; i++)
        {
            arr->a[i] = arr->a[i+1];           
        }    
            arr->length--;
    }
    return x;
}

//linear searching on array
int linearSearch(Array array,int element){
    for (int i = 0; i < array.length; i++)
    {
        if(array.a[i]==element)
            return i;
    }
    return -1;    
}
// get method
int get(Array array,int index){
    return array.a[index];
}

// set method
void set(Array array,int index,int x){
    array.a[index]=x;
}

// find max element of array
int max(Array array){
    int max = array.a[0];
    for (int i = 1; i < array.length; i++)
    {
        if (max<array.a[i])
        {
            max= array.a[i];
        }
        
    }
    return max;
    
}

// find min element of array
int min(Array array){
    int min = array.a[0];
    for (int i = 1; i < array.length; i++)
    {
        if (min>array.a[i])
        {
            min= array.a[i];
        }
        
    }
    return min;
    
}

// sum of array
int sum(Array array){
    int sum=0;
    for (int i = 0; i < array.length; i++)
    {
        sum += array.a[i];
    }
    return sum;    
}
// avg of array
int avg(Array array){
    int sum=0;
    for (int i = 0; i < array.length; i++)
    {
        sum += array.a[i];
    }
    return sum/array.length;    
}
// binary search using iterative method
int binsearch(Array array,int element){
    int l =0,h=(array.length)-1,mid;
    while (l<=h)        
    {
        mid = (l+h)/2;
        if(array.a[mid]==element)
            return mid;
        else if(array.a[mid]>element)
            h = mid-1;
        else    
            l = mid+1;
    }
    return -1;
}

// swaping 2 values of array
void swap(int *a,int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

//reverse the array
void reverse(Array *arr){
    int i=0,j=arr->length-1;
    while (i<j)
    {
        swap(&arr->a[i],&arr->a[j]);
        i++;j--;
    }
    
}

// for checking array is sorted or not
int isSorted(Array array){
    for (int i = 0; i < array.length-1; i++)
    {
        if(array.a[i]>array.a[i+1])
            return 0;
    }
    
    return 1;
}

//for inserting at sorted position of an array
void SortInsert(Array *arr,int x){
    int j = arr->length-1;
    if(isSorted(*arr)){
    while (j>=0 && x<arr->a[j])
    {
        arr->a[j+1] = arr->a[j--];
    }
    arr->a[j+1]=x;
    arr->length++;
}
}

// seprate the -ve on last and +ve on right remember it's not sorting just arranging the -ve +ve
void seprate(Array *arr){
    int i=0,j=arr->length-1;
    while (i<j)
    {
        while (arr->a[i]<0) i++;
        while (arr->a[j]>=0) j--;
        swap(&arr->a[i],&arr->a[j]);
    } 
}

//merging the 2 arrays at sorted position but condition is given array should also be sorted  
Array* mergeArray(Array *arr1,Array *arr2){
    int i=0,j=0,k=0;
    Array *arr3;
    arr3 = new Array[sizeof(Array)];
    while (i<arr1->length && j<arr2->length)        
    {
        if(arr1->a[i]<arr2->a[j])
            arr3->a[k++] = arr1->a[i++];
        else
            arr3->a[k++] = arr2->a[j++];
    }
    for (;i < arr1->length; i++)
        arr3->a[k++] = arr1->a[i];
    for (;j < arr2->length; j++)
        arr3->a[k++] = arr2->a[j];

    arr3->length = arr1->length + arr2->length;
    arr3->size = arr3->length;
    return arr3;
}



//union of sorted array all elements in array must be unique

Array* unionsort(Array *arr1,Array *arr2){
    int i=0,j=0,k=0;
    Array *arr3;
    arr3 = new Array[sizeof(Array)];
    while (i<arr1->length && j<arr2->length)        
    {
        if(arr1->a[i]<arr2->a[j])
            arr3->a[k++] = arr1->a[i++];
        else if(arr2->a[j]<arr1->a[i])
            arr3->a[k++] = arr2->a[j++];
        else{
            arr3->a[k++] = arr1->a[i++];
            j++;
        }
    }
    for (;i < arr1->length; i++)
        arr3->a[k++] = arr1->a[i];
    for (;j < arr2->length; j++)
        arr3->a[k++] = arr2->a[j];

    arr3->length =k;
    arr3->size = arr3->length;
    return arr3;
}


//union of unsorted array all elements in array must be unique
Array* unionunsort(Array *arr1, Array *arr2){
    Array *arr3;
    arr3 = new Array[sizeof(Array)];
    int i,j,k=0;
    for ( i = 0; i < arr1->length; i++)
    {
        arr3->a[k++] =arr1->a[i];
    }
    for ( i = 0; i < arr2->length; i++)
    {
        int count =1;
        for ( j = 0; j < arr1->length; j++)
        {
            if(arr2->a[i]==arr1->a[j]){
                count = 0;
                break;
            }
            
        }
            if (count)
            {
                arr3->a[k++] = arr2->a[i];
            }
        
    }
    arr3->length =k;
    arr3->size = arr3->length;
    return arr3;
    
}


// intersection only for the sorted arrays
Array* intersection(Array *arr1,Array *arr2){
    int i=0,j=0,k=0;
    Array *arr3;
    arr3 = new Array[sizeof(Array)];
    while (i<arr1->length && j<arr2->length)        
    {
        if(arr1->a[i]<arr2->a[j])
           i++;
        else if(arr2->a[j]<arr1->a[i])
            j++;
        else{
            arr3->a[k++] = arr1->a[i++];
            j++;
        }
    }
    arr3->length =k;
    arr3->size = arr3->length;
    return arr3;
}

// set difference operation for the sorted array

Array* difference(Array *arr1,Array *arr2){
    int i=0,j=0,k=0;
    Array *arr3;
    arr3 = new Array[sizeof(Array)];
    while (i<arr1->length && j<arr2->length)        
    {
        if(arr1->a[i]<arr2->a[j])
           arr3->a[k++] = arr1->a[i++];
        else if(arr2->a[j]<arr1->a[i])
            j++;
        else{
            i++;
            j++;
        }
    }
    for (; i < arr1->length; i++)
    {
        arr3->a[k++] = arr1->a[i++];
    }
    
    arr3->length =k;
    arr3->size = arr3->length;
    return arr3;
}


//finding missing single and multiple element for sorted array using brute force approch
void missingSort(Array arr,int low){
    int diff = low-0;
    cout<<"Missing Elements :";
    for (int i = 1; i < arr.length; i++)
    {
        if(diff!=(arr.a[i]-i)){
            //this loop for if there are more than 1 element is missing
            while(diff<(arr.a[i]-i)){
                cout<<diff+i<<" ";
                diff++;
            }
        }
    }
    
}

//another method for missing element this will work for sorted and unsorted both

void missing(Array arr,int low,int high){
    int hash[high]={0};
    for (int i = 0; i < arr.length; i++)
    {
        hash[arr.a[i]]++;
    }
    for (int i = low; i < high; i++)
    {
        if(hash[i]==0)
            cout<<i<<" ";
    }
    

}

//finds the duplicate elements in array using hash table
void duplicate(Array arr,int max){
    int hash[max+1]={0};
    for (int i = 0; i < arr.length; i++)
    {
        hash[arr.a[i]]++;
    }
    for (int i = 0; i <=max; i++)
    {
        if(hash[i]>1)
            cout<<i<<" is repeated "<<hash[i]<<" Times."<<endl;
    }
    
    
}

int main(){
    Array array;
    // Array array1,*array2; //use it when perform any 2 array operation
    cout<<"Enter the size of array: ";
    cin>>array.size;
    array.a = new int[array.size];
    int n;
    cout<<"Enter how many elements you want to enter: ";
    cin>>n;
    cout<<"Enter the elemets of array: ";
    for (int i = 0; i < n; i++)
    {
        cin>>array.a[i];
    }
    array.length=n;

    // cout<<"\nEnter the size of array: ";
    // cin>>array1.size;
    // array1.a = new int[array1.size];
    // n;
    // cout<<"Enter how many elements you want to enter: ";
    // cin>>n;
    // cout<<"Enter the elemets of array: ";
    // for (int i = 0; i < n; i++)
    // {
    //     cin>>array1.a[i];
    // }
    // array1.length=n;
    // array2 = difference(&array,&array1);  
    // array2->display(); 
    duplicate(array,max(array));
    delete[] array.a;
    return 0;
}