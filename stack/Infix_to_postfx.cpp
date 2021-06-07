#include<bits/stdc++.h>
#include "STack_array2.cpp"
int main(){
    char *s = "2+4*5-6/3";
    char *postfix = IntoPo(s);
    cout<<postfix<<endl;


    //evaluating the postfix expression

    cout<<EvalPostfix(postfix);

}



