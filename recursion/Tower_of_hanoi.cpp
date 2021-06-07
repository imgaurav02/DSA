#include<iostream>
using namespace std;

void TOH(int n,char A,char B,char C){
    if(n>0){
        TOH(n-1,A,C,B);
        cout<<"Move "<<A<<" To "<<C<<endl;
        TOH(n-1,B,A,C);
    }
}
int main(){
    int n;
    cout<<"Enter the number of disk: ";
    cin>>n;
    TOH(n,'A','B','C');
    return 0;
}