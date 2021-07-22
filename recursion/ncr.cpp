#include<iostream>
using namespace std;

int ncr(int n,int r){
    if(n==r || r==0)
        return 1;
    return ncr(n-1,r-1)+ncr(n-1,r);
}

void pascal(int row){
    int n,r,check;
    for(n=0;n<row;n++){
        for(r=0;r<=n;r++)
            cout<<ncr(n,r)<<" ";
        cout<<endl;
    }
}

int main(){
    int n,r;
    cout<<"Enter the value of n and r: ";
    cin>>n>>r;
    cout<<ncr(n,r);
    // pascal(5);
    return 0;
}