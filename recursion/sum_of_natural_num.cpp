#include<iostream>
using namespace std;
int sum(int n){
    if(n==1)
        return 1;
    return sum(n-1)+n;
}

// using formula
int formulaSum(int n){
    return n*(n+1)/2;
}
int main(){
    int n;
    cout<<"Enter natural number: ";
    cin>>n;
    cout<<formulaSum(n);
    return 0;
}