#include<iostream>
using namespace std;
double taylor(int x,int n){
    static int num=1,den=1;
    double r=0;
    if (n==0)
    {
        return 1;
    }
    else{
        r = taylor(x,n-1);
        num = num*x;
        den = den*n;
        return r+(double)num/den;
    }
}

double taylorSecond(int x,int n){
    static double result;
    if(n==0)
        return result;
    result = 1+ x*result/n;
    return taylorSecond(x,n-1);
}
int main(){
    int x,n;
    printf("Enter the value of x: ");
    scanf("%d",&x);
    printf("Enter how many terms you want to add: ");
    scanf("%d",&n);
    printf("Value of e^%d: %lf\n",x,taylor(x,n));
    printf("Value of e^%d: %lf",x,taylorSecond(x,n));
    return 0;
}