
#include<bits/stdc++.h>
#include"STack_array2.cpp"
using namespace std;
int main(){
    
    string str;
    str ="{([a+b]*[c+d])}";
    
    if(isBalanced2(str))
        cout<<"Correct";
    else
        cout<<"Incorrect";
}