#include<iostream>
#include<string.h>
using namespace std;

// using state tree
void permutation(char s[],int k){
    static int f[20]={0};
    static char res[20];
    int i;
    if(s[k]=='\0'){
        res[k]='\0';
        cout<<res<<endl;
    }
    else{
        for (i=0; s[i]!='\0'; i++)
        {
            if(f[i]==0){

            res[k] = s[i];
            f[i]=1;
            permutation(s,k+1);
            f[i]=0;
            }
        }
        
    }
}


void swap(int *p,int *q){
    int temp = *p;
    *p = *q;
    *q = temp;
}

//using swaping
void permSwap(char s[],int l,int h){
    if(l==h)
        cout<<s<<" ";
    else{
        for(int i=l;i<=h;i++){
            swap(s[l],s[i]);
            permSwap(s,l+1,h);
            swap(s[i],s[l]);
        }
    }
}


int main(){
    char a[20] = {"GAURAV"};
    puts(a);
    permSwap(a,0,5);
    return 0;
}