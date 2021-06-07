#include<bits/stdc++.h> //this will import all the necessrory header files
using namespace std;
// using recursion
int fab(int n)
{
    if(n<=1)
        return n;
    return fab(n-1)+fab(n-2);
}

// recursion using memonization method 
int fabm(int n){
vector<int> F(n,-1);
if(n<=1){
    F[n]=n;
    return n;
}
else
{
    if(F[n-2]==-1)
        F[n-2] = fabm(n-2);
    else if(F[n-1]==-1)
        F[n-1] = fabm(n-1);
    F[n] = F[n-2]+F[n-1];
    return (F[n-2]+F[n-1]);
}
}



// using iteratuve method
int fabitr(int n)
{
    int t1=0,t2=1,res;
    if(n<=1)
        return n;
    for(int i=2;i<=n;i++){
        res = t1+t2;
        t1=t2;
        t2=res;
    }
    return res;
}


int main(){
int n;
cout<<"enter the digit upto that you want print series: ";
cin>>n;
for (int i = 0; i < n; i++)
{
    printf("%d ",fabm(i));
}


}