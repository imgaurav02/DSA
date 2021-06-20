#include<bits/stdc++.h>
using namespace std;

/*  root -> i
    lchlid -> 2i
    rchlid -> 2i+1

    any node it's root on -> i/2

    storing starts from index 1 onwards

                                                    A
                                                B           C
                                            D       E   F       G
                            

 */
// this is only a demo to show how create tree using array generally we create tree with LL

void preorder(char a[],int i){
    if(i<8){
        cout<<a[i];
        preorder(a,2*i);
        preorder(a,2*i+i);
    }
}
int main(){
    char a[8];
    cout<<"Enter the root: ";
    cin>>a[1];
    for(int i=1;i<4;i++){
    cout<<"Enter the left chlid of "<<a[i]<<" : ";
    cin>>a[2*i];
    cout<<"Enter the right chlid of "<<a[i]<<" : ";
    cin>>a[2*i+1];
        
    }

    //preorder traversal

    // for(int i=1;i<4;i++){
    //     cout<<a[i]<<" ";
    //     cout<<a[2*i]<<" ";
    //     cout<<a[2*i+1]<<" ";
    // }
    preorder(a,1);
    return 0;
}