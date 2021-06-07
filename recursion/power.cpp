#include<iostream>
using namespace std;
int pow(int n,int q){
    if(q==0)
        return 1;
    return pow(n,q-1)*n;
}
int Secondpow(int n,int q){
    if(q==0)
        return 1;
    else if(q%2==0)
        return Secondpow(n*n,q/2);
    else
        return n*Secondpow(n*n,q/2);
}
int main(){
    int n,q;
    cout<<"Enter The number and its power";
    cin>>n>>q;
    if(q>=0)
        cout<<Secondpow(n,q);
    else
        cout<<"Error";
}