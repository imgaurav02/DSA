#include<stdio.h>
#include<stdlib.h>
int *fun(int n){
    int *p;
    p = (int *) malloc(sizeof(int)*n);
    printf("Enter Elements of Array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&p[i]);
    }
    return(p);
}
int main(){
    int n,*A;
    printf("how Many elements in array: ");
    scanf("%d",&n);
    A = fun(n);
    for(int i=0;i<n;i++){
        printf("%d\n",A[i]);
    }
    return 0;
}