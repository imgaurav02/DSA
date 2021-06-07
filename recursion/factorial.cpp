#include<iostream>
using namespace std;
int fact(int n){
    if(n==0)
        return 1;
    return fact(n-1)*n;
}
int main(){
    int n;
    cout<<"Enter A Number: ";
    cin>>n;
    if(n>=0)
        cout<<"Factorial: "<<fact(n);
    else
        cout<<"Factorial: 0";
    return 0;
}