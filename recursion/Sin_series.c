#include<stdio.h>
double sinseries(float x,int n){
    static double num=1,den=1;
    double res = 0;
    if(n==1){
        return x;
    }
    else{
        res = sinseries(x,n-1);
        if(n==2)
            num = x*x*x;
        else
            num = num*x*x;
        den = den*(2*n-2)*(2*n-1);
        if(n%2==0)
            return (res - (num/den));
        else
            return (res + (num/den));
    }

}

int main(){
    int n;
    float x;
    printf("Enter the value of x in deg");
    scanf("%f",&x);
    printf("Enter How elements sum you wants to perform: ");
    scanf("%d",&n);
    x = ((x*22)/7)/180;
    printf("%lf",sinseries(x,n));
    return 0;
}