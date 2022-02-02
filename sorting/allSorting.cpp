#include<bits/stdc++.h>
using namespace std;
#define INPUT freopen("input.txt","r",stdin);
#define OUTPUT freopen("output.txt","w",stdout);
#define loop(i,a,b) for(int i = a;i<b;i++)
#define looprev(i,a,b) for(int i = a;i>=b;i--)
#define mid(l,r) (l+(r-l)/2)
#define ll long long int
#define vi vector<int>

bool isSmaller(vi arr,int i,int j){
    cout << "comparing " << arr[i] << " with " << arr[j] << endl;
    if(arr[i] < arr[j])
        return true;
    return false;
}

void swap(vi &arr,int i,int j){
    cout << "swapping " << arr[i] << " with " << arr[j] << endl;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void print(vi arr){
    loop(i,0,arr.size())
        cout << arr[i] << " ";
    cout << endl;
}

void bubbleSort(vi &arr,int n){
    loop(i,0,n - 1){
        loop(j,0,n - i - 1){
            if(isSmaller(arr,j + 1,j)){
                swap(arr,j +1,j);
            }
        }
    }
}

int main(){
    INPUT
    OUTPUT

    int n;
    cin >> n;
    
    vi arr(n);
    loop(i,0,n)
        cin >> arr[i];

    bubbleSort(arr,n);
    print(arr);
    return 0;
}